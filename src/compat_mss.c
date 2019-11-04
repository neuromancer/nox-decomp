#ifdef __APPLE__
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif
#include <SDL2/SDL.h>

#define MINIMP3_ONLY_MP3
#define MINIMP3_NO_SIMD
#define MINIMP3_IMPLEMENTATION
#include "minimp3.h"

#include "defs.h"

struct _DIG_DRIVER
{
    ALCdevice *device;
    ALCcontext *context;
    SDL_mutex *mutex;
    HSAMPLE sample_head;
    HSTREAM stream_head;
};

struct _SAMPLE_BUFFER
{
    const void *buffer;
    unsigned int length;
    unsigned int position;
};

struct _SAMPLE
{
    HDIGDRIVER dig;

    HSAMPLE next;
    ALuint source;
    ALuint hwbuf[2];
    BYTE hwready;

    struct _SAMPLE_BUFFER buffers[2];
    BYTE current;
    BYTE ready;

    BYTE stereo;
    BYTE adpcm;

    unsigned int playback_rate;
    unsigned int block_size;

    unsigned int playing;

    AILSAMPLECB eob;
    AILSAMPLECB eos;
    S32 user[8];
};

struct _STREAM
{
    HDIGDRIVER dig;

    HSTREAM next;
    ALuint source;
    ALuint hwbuf[2];
    BYTE hwready;

    BYTE stereo;
    unsigned int playback_rate;
    unsigned int playing;
    
    FILE *file;
    unsigned int file_size;
    unsigned int chunk_size;
    unsigned int chunk_pos;
    unsigned int buffered;
    union
    {
        struct
        {
            WAVEFORMAT wf;
            unsigned int position;
        } pcm;
        struct
        {
            WAVEFORMAT wf;
            unsigned int position;
            unsigned int samples;
        } adpcm;
        struct 
        {
            MPEGLAYER3WAVEFORMAT wf;
            mp3dec_t dec;
        } mp3;
    };
    unsigned int (*decode)(HSTREAM, int16_t *, unsigned int);
    void (*seek)(HSTREAM, unsigned int);
    unsigned int (*tell)(HSTREAM);
    BYTE buffer[16 * 1024];
};

struct _TIMER
{
    unsigned int interval;
    AILTIMERCB cb;
    U32 user;
};

// https://wiki.multimedia.cx/index.php/IMA_ADPCM
int ima_index_table[16] = {
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8
}; 

int ima_step_table[89] = { 
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 
    19, 21, 23, 25, 28, 31, 34, 37, 41, 45, 
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 
    130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
    337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 
    2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
    5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899, 
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767 
}; 

static inline int16_t sat16(int x)
{
    if (x < INT16_MIN)
        return INT16_MIN;
    else if (x > INT16_MAX)
        return INT16_MAX;
    else
        return x;
}

static inline int satindex(int x)
{
    if (x < 0)
        return 0;
    else if (x > 88)
        return 88;
    else
        return x;
}

static int16_t decode_nibble(int16_t predictor, unsigned int nibble, int unsigned index)
{
    int diff, step = ima_step_table[index];

    diff = step >> 3;
    if (nibble & 4) diff += step;
    if (nibble & 2) diff += step >> 1;
    if (nibble & 1) diff += step >> 2;
    if (nibble & 8)
        predictor = sat16(predictor - diff);
    else
        predictor = sat16(predictor + diff);
    return predictor;
}

static unsigned int decode_adpcm(int16_t *out, const BYTE *data, unsigned int size)
{
    int index, diff;
    unsigned int i, samples = 0;
    int8_t nibble, sign;
    int16_t predictor;

    predictor = data[0] | (data[1] << 8);
    index = data[2];

    out[samples++] = predictor;

    for (i = 4; i < size; i++)
    {
        predictor = decode_nibble(predictor, data[i], index);
        index = satindex(index + ima_index_table[data[i] & 15]);
        out[samples++] = predictor;

        predictor = decode_nibble(predictor, data[i] >> 4, index);
        index = satindex(index + ima_index_table[data[i] >> 4]);
        out[samples++] = predictor;
    }

    return samples;
}

static unsigned int decode_adpcm_stereo(int16_t *out, const BYTE *data, unsigned int size)
{
    int lindex, rindex, diff;
    unsigned int i, samples = 0;
    int8_t nibble, sign;
    int16_t lpredictor, rpredictor;

    lpredictor = data[0] | (data[1] << 8);
    lindex = data[2];
    rpredictor = data[4] | (data[5] << 8);
    rindex = data[6];

    out[samples++] = lpredictor;
    out[samples++] = rpredictor;

    for (i = 8; i < size; i += 8)
    {
        unsigned int j;

        for (j = 0; j < 4; j++)
        {
            lpredictor = decode_nibble(lpredictor, data[i + j], lindex);
            lindex = satindex(lindex + ima_index_table[data[i + j] & 15]);
            out[samples++] = lpredictor;

            rpredictor = decode_nibble(rpredictor, data[i + j + 4], rindex);
            rindex = satindex(rindex + ima_index_table[data[i + j + 4] & 15]);
            out[samples++] = rpredictor;

            lpredictor = decode_nibble(lpredictor, data[i + j] >> 4, lindex);
            lindex = satindex(lindex + ima_index_table[data[i + j] >> 4]);
            out[samples++] = lpredictor;

            rpredictor = decode_nibble(rpredictor, data[i + j + 4] >> 4, rindex);
            rindex = satindex(rindex + ima_index_table[data[i + j + 4] >> 4]);
            out[samples++] = rpredictor;
        }
    }

    return samples;
}

static void checkError()
{
    ALCenum error;
    error = alGetError();
    if (error != AL_NO_ERROR)
    {
        dprintf("AL error: 0x%x\n", error);
        DebugBreak();
    }
}

static void sample_unqueue_buffers(HSAMPLE S)
{
    ALint processed;
    alGetSourcei(S->source, AL_BUFFERS_PROCESSED, &processed);
    checkError();
    if (processed)
    {
        alSourceUnqueueBuffers(S->source, processed, S->hwbuf + S->hwready);
        checkError();
    }
    S->hwready += processed;
}

static void stream_unqueue_buffers(HSTREAM S)
{
    ALint processed;
    alGetSourcei(S->source, AL_BUFFERS_PROCESSED, &processed);
    checkError();
    if (processed)
    {
        alSourceUnqueueBuffers(S->source, processed, S->hwbuf + S->hwready);
        checkError();
    }
    S->hwready += processed;
}

DXDEC HSAMPLE AILCALL AIL_allocate_sample_handle (HDIGDRIVER dig)
{
    HSAMPLE sample = calloc(1, sizeof(*sample));
    sample->dig = dig;
    // fprintf(stderr, "%s\n", __FUNCTION__);

    alGenSources(1, &sample->source);
    checkError();
    alGenBuffers(2, sample->hwbuf);
    checkError();
    sample->hwready = 2;

    SDL_LockMutex(dig->mutex);
    sample->next = dig->sample_head;
    dig->sample_head = sample;
    SDL_UnlockMutex(dig->mutex);
    return sample;
}

static void sample_eos(HSAMPLE S)
{
    S->playing = 0;
    if (S->eos)
        S->eos(S);
}

static void sample_eob(HSAMPLE S)
{
    S->ready++;
    S->current = !S->current;
    if (S->eob)
        S->eob(S);
}

DXDEC void AILCALL AIL_close_stream(HSTREAM stream)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    SDL_LockMutex(stream->dig->mutex);
    SDL_UnlockMutex(stream->dig->mutex);
}

DXDEC void AILCALL AIL_digital_configuration (HDIGDRIVER dig, S32 FAR *rate, S32 FAR *format, char FAR *string)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    if (string)
        strcpy(string, "");
}

DXDEC S32 AILCALL AIL_digital_handle_release(HDIGDRIVER drvr)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
    return 0;
}

DXDEC S32 AILCALL AIL_digital_handle_reacquire (HDIGDRIVER drvr)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
    return 0;
}

DXDEC void AILCALL AIL_end_sample (HSAMPLE S)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);

    SDL_LockMutex(S->dig->mutex);
    if (S->playing)
    {
        sample_eob(S);
        sample_eos(S);
    }
    SDL_UnlockMutex(S->dig->mutex);
}

DXDEC S32 AILCALL AIL_get_preference (U32 number)
{
    // fprintf(stderr, "%s: %d\n", __FUNCTION__, number);
    return 0;
}

DXDEC void AILCALL AIL_init_sample (HSAMPLE S)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    SDL_LockMutex(S->dig->mutex);

    S->current = 0;
    S->ready = 2;
    alSourcef(S->source, AL_PITCH, 1.0f);
    alSourcef(S->source, AL_GAIN, 1.0f);
    AIL_set_sample_pan(S, 63);

    S->playing = 0;
    alSourceStop(S->source);
    sample_unqueue_buffers(S);

    SDL_UnlockMutex(S->dig->mutex);
}

DXDEC char FAR *AILCALL AIL_last_error (void)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
    return 0;
}

DXDEC void AILCALL AIL_load_sample_buffer (HSAMPLE S, U32 buff_num, void const FAR *buffer, U32 len)
{
    struct _SAMPLE_BUFFER *sb = &S->buffers[buff_num];
    // fprintf(stderr, "%s: %08X, %d, %08X, %d\n", __FUNCTION__, (int)S, buff_num, (int)buffer, len);
    SDL_LockMutex(S->dig->mutex);
    sb->buffer = buffer;
    sb->length = len;
    sb->position = 0;
    S->playing = 1;
    SDL_UnlockMutex(S->dig->mutex);
}

static void stream_find_data(HSTREAM stream)
{
    char tmp[8];

    stream->chunk_size = 0;
    stream->chunk_pos = 0;

    while (ftell(stream->file) < stream->file_size)
    {
        unsigned int size;
        if (fread(tmp, 8, 1, stream->file) != 1)
            break;
        size = *(DWORD *)(tmp + 4);
        if (memcmp(tmp, "data", 4) == 0)
        {
            stream->chunk_size = size;
            break;
        }
        fseek(stream->file, size, SEEK_CUR);
    }
}

static unsigned int stream_pcm_decode(HSTREAM stream, int16_t *out, unsigned int max_samples)
{
    unsigned int channels = stream->stereo ? 2 : 1;
    unsigned int remaining = stream->chunk_size - stream->chunk_pos;

    if (!remaining)
    {
        stream_find_data(stream);
        remaining = stream->chunk_size - stream->chunk_pos;
        if (!remaining)
        {
            stream->playing = 0;
            return 0;
        }
    }

    if (remaining / 2 >= max_samples)
        remaining = max_samples * 2;

    fread(out, 2, remaining / 2, stream->file);
    stream->pcm.position += remaining / 2 / channels;
    return remaining / 2;
}

static void stream_pcm_seek(HSTREAM stream, unsigned int position)
{
    // TODO
    stream->pcm.position = 0;
}

static unsigned int stream_pcm_tell(HSTREAM stream)
{
    return stream->pcm.position;
}

static unsigned int stream_adpcm_decode(HSTREAM stream, int16_t *out, unsigned int max_samples)
{
    unsigned int block_size = stream->adpcm.wf.nBlockAlign;
    unsigned int samples;
    unsigned int channels = stream->stereo ? 2 : 1;

    if (stream->adpcm.position >= stream->adpcm.samples)
    {
        stream->playing = 0;
        return 0;
    }

    if (stream->buffered < block_size)
    {
        unsigned int remaining = stream->chunk_size - stream->chunk_pos;

        if (!remaining)
        {
            stream_find_data(stream);
            remaining = stream->chunk_size - stream->chunk_pos;
            if (!remaining)
            {
                stream->playing = 0;
                return 0;
            }
        }
        
        if (remaining > block_size - stream->buffered)
            remaining = block_size - stream->buffered;
        fread(stream->buffer + stream->buffered, 1, remaining, stream->file);
        stream->buffered += remaining;
    }

    if (stream->stereo)
        samples = decode_adpcm_stereo(out, stream->buffer, block_size);
    else
        samples = decode_adpcm(out, stream->buffer, block_size);

    stream->buffered -= block_size;
    if (stream->buffered)
        memmove(stream->buffer, stream->buffer + block_size, stream->buffered);
    if (samples / channels + stream->adpcm.position >= stream->adpcm.samples)
        samples = (stream->adpcm.samples - stream->adpcm.position) * channels;
    stream->adpcm.position += samples / channels;
    return samples;
}

static void stream_adpcm_seek(HSTREAM stream, unsigned int position)
{
    unsigned int block_size = stream->adpcm.wf.nBlockAlign;
    unsigned int channels = stream->stereo ? 2 : 1;
    unsigned int samples_per_block = (block_size / channels - 4) * 2;
    unsigned int blocks = position / samples_per_block;
    stream->adpcm.position = 0;

    while (stream->adpcm.position < position)
    {
        unsigned int chunk_blocks;
        stream_find_data(stream);
        if (stream->chunk_size == 0)
            break;
        chunk_blocks = stream->chunk_size / block_size;
        if (blocks < chunk_blocks)
        {
            fseek(stream->file, blocks * block_size, SEEK_CUR);
            stream->adpcm.position += blocks * samples_per_block;
            break;
        }
        else
        {
            fseek(stream->file, stream->chunk_size, SEEK_CUR);
            stream->adpcm.position += chunk_blocks * samples_per_block;
        }
    }

    // TODO seek within an ADPCM block
}

static unsigned int stream_adpcm_tell(HSTREAM stream)
{
    return stream->adpcm.position;
}

static unsigned int stream_mp3_decode(HSTREAM stream, int16_t *out, unsigned int max_samples)
{
    unsigned int remaining = stream->chunk_size - stream->chunk_pos;
    unsigned int samples;
    mp3dec_frame_info_t info;

    if (stream->buffered < sizeof(stream->buffer))
    {
        if (!remaining && !stream->buffered)
        {
find_data:
            stream_find_data(stream);
            remaining = stream->chunk_size - stream->chunk_pos;
            if (!remaining)
            {
                stream->playing = 0;
                return 0;
            }
        }
        
read_data:
        if (remaining)
        {
            if (remaining > sizeof(stream->buffer) - stream->buffered)
                remaining = sizeof(stream->buffer) - stream->buffered;
            fread(stream->buffer + stream->buffered, 1, remaining, stream->file);
            stream->buffered += remaining;
        }
    }

    samples = mp3dec_decode_frame(&stream->mp3.dec, stream->buffer, stream->buffered, out, &info);
    if (samples == 0)
    {
        if (remaining)
            goto read_data;
        else
            goto find_data;
    }

    stream->buffered -= info.frame_bytes;
    if (stream->buffered)
        memmove(stream->buffer, stream->buffer + info.frame_bytes, stream->buffered);

    return samples;
}

static void stream_mp3_seek(HSTREAM stream, unsigned int position)
{
    mp3dec_init(&stream->mp3.dec);
}

static unsigned int stream_mp3_tell(HSTREAM steam)
{
    return 0;
}

DXDEC HSTREAM AILCALL AIL_open_stream(HDIGDRIVER dig, char const FAR * filename, S32 stream_mem)
{
    unsigned int file_size, size;
    BYTE tmp[256];
    FILE *f;
    HSTREAM stream = NULL;
    WAVEFORMAT *wf = (WAVEFORMAT *)tmp;
    MPEGLAYER3WAVEFORMAT *mp3wf = (MPEGLAYER3WAVEFORMAT *)tmp;

    f = fopen(filename, "rb");
    if (f == NULL)
        return NULL;

    if (fread(tmp, 12, 1, f) != 1)
        goto error;

    if (memcmp(tmp, "RIFF", 4) != 0)
        goto error;

    // XXX ignore file size?
    file_size = *(DWORD *)(tmp + 4);

    if (memcmp(tmp + 8, "WAVE", 4) != 0)
        goto error;

    if (fread(tmp, 8, 1, f) != 1)
        goto error;
    size = *(DWORD *)(tmp + 4);

    if (memcmp(tmp, "fmt ", 4) != 0)
        goto error;

    if (size < sizeof(WAVEFORMAT) || size > sizeof(tmp))
        goto error;

    if (fread(tmp, size, 1, f) != 1)
        goto error;

    stream = calloc(1, sizeof(*stream));
    stream->dig = dig;
    stream->file = f;
    stream->file_size = file_size;

    if (wf->wFormatTag == 0x01) // PCM
    {
        stream->playback_rate = wf->nSamplesPerSec;
        stream->stereo = wf->nChannels > 1;
        stream->pcm.wf = *wf;
        stream->decode = stream_pcm_decode;
        stream->seek = stream_pcm_seek;
        stream->tell = stream_pcm_tell;
    }
    else if (wf->wFormatTag == 0x11) // ADPCM
    {
        stream->playback_rate = wf->nSamplesPerSec;
        stream->stereo = wf->nChannels > 1;
        stream->adpcm.wf = *wf;
        stream->decode = stream_adpcm_decode;
        stream->seek = stream_adpcm_seek;
        stream->tell = stream_adpcm_tell;

        if (fread(tmp, 8, 1, f) != 1)
            goto error;
        if (memcmp(tmp, "fact", 4) != 0)
            goto error;
        size = *(DWORD *)(tmp + 4);
        if (size != 4)
            goto error;
        if (fread(tmp, 4, 1, f) != 1)
            goto error;

        stream->adpcm.samples = *(DWORD *)tmp;
    }
    else if (wf->wFormatTag == 0x55) // MP3
    {
        if (size < sizeof(MPEGLAYER3WAVEFORMAT))
            goto error;
        if (mp3wf->wfx.cbSize != 12)
            goto error;
        stream->playback_rate = mp3wf->wfx.nSamplesPerSec;
        stream->stereo = mp3wf->wfx.nChannels > 1;
        stream->mp3.wf = *mp3wf;
        mp3dec_init(&stream->mp3.dec);
        stream->decode = stream_mp3_decode;
        stream->seek = stream_mp3_seek;
        stream->tell = stream_mp3_tell;
    }
    else
    {
        DebugBreak();
    }

    alGenSources(1, &stream->source);
    checkError();
    alGenBuffers(2, stream->hwbuf);
    checkError();
    stream->hwready = 2;

    SDL_LockMutex(dig->mutex);
    stream->next = dig->stream_head;
    dig->stream_head = stream;
    SDL_UnlockMutex(dig->mutex);

    return stream;

error:
    fclose(f);
    free(stream);
    return NULL;
}

DXDEC void AILCALL AIL_pause_stream(HSTREAM stream, S32 onoff)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
}

DXDEC AILSAMPLECB AILCALL AIL_register_EOB_callback (HSAMPLE S, AILSAMPLECB EOB)
{
    AILSAMPLECB prev = S->eob;
    // fprintf(stderr, "%s: %08X, %08X\n", __FUNCTION__, (int)S, (int)EOB);
    S->eob = EOB;
    return prev;
}

DXDEC AILSAMPLECB AILCALL AIL_register_EOS_callback (HSAMPLE S, AILSAMPLECB EOS)
{
    AILSAMPLECB prev = S->eos;
    // fprintf(stderr, "%s: %08X, %08X\n", __FUNCTION__, (int)S, (int)EOS);
    S->eos = EOS;
    return prev;
}

DXDEC HTIMER AILCALL AIL_register_timer (AILTIMERCB fn)
{
    HTIMER timer = calloc(1, sizeof(*timer));
    // fprintf(stderr, "%s %08x\n", __FUNCTION__, (int)fn);
    timer->cb = fn;
    return timer;
}

DXDEC void AILCALL AIL_release_sample_handle (HSAMPLE S)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
}

DXDEC void AILCALL AIL_release_timer_handle (HTIMER timer)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
}

DXDEC void AILCALL AIL_resume_sample (HSAMPLE S)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
}

DXDEC S32 AILCALL AIL_sample_buffer_ready (HSAMPLE S)
{
    // fprintf(stderr, "%s: %08X\n", __FUNCTION__, (int)S);
    if (S->ready == 0)
        return -1;
    else if (S->ready-- == 2)
        return 0;
    return !S->current;
}

DXDEC S32 AILCALL AIL_sample_user_data (HSAMPLE S, U32 index)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    return S->user[index];
}

DXDEC void AILCALL AIL_serve(void)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
}

DXDEC S32 AILCALL AIL_set_preference (U32 number, S32 value)
{
    // fprintf(stderr, "%s: %d = %d\n", __FUNCTION__, number, value);
    return 0;
}

DXDEC void AILCALL AIL_set_sample_adpcm_block_size (HSAMPLE S, U32 blocksize)
{
    // fprintf(stderr, "%s: %08X, %d\n", __FUNCTION__, (int)S, blocksize);
    S->block_size = blocksize;
}

DXDEC void AILCALL AIL_set_sample_pan (HSAMPLE S, S32 pan)
{
    float pos[3] = { (pan - 63) / 64.0f, 0, 0 };
    pos[2] = sqrtf(1 - pos[0] * pos[0]);
    alSourcefv(S->source, AL_POSITION, pos);
    // fprintf(stderr, "%d -> %f, %f, %f\n", pan, pos[0], pos[1], pos[2]);
    // fprintf(stderr, "%s: %08X, %d\n", __FUNCTION__, (int)S, pan);
}

DXDEC void AILCALL AIL_set_sample_playback_rate (HSAMPLE S, S32 playback_rate)
{
    // fprintf(stderr, "%s: %08X, %d\n", __FUNCTION__, (int)S, playback_rate);
    S->playback_rate = playback_rate;
}

DXDEC void AILCALL AIL_set_sample_type (HSAMPLE S, S32 format, U32 flags)
{
    // fprintf(stderr, "%s: %08X %d %d\n", __FUNCTION__, (int)S, format, flags);
    if (flags)
        DebugBreak();
    S->stereo = format & 2;
    S->adpcm = format & 4;
}

DXDEC void AILCALL AIL_set_sample_user_data (HSAMPLE S, U32 index, S32 value)
{
    // fprintf(stderr, "%s, %d, %08X\n", __FUNCTION__, index, value);
    S->user[index] = value;
}

DXDEC void AILCALL AIL_set_sample_volume (HSAMPLE S, S32 volume)
{
    // fprintf(stderr, "%s: %08X, %d\n", __FUNCTION__, (int)S, volume);
    alSourcef(S->source, AL_GAIN, volume / 127.0f);
}

DXDEC void AILCALL AIL_set_stream_position(HSTREAM stream,S32 offset)
{
    SDL_LockMutex(stream->dig->mutex);
    stream->chunk_size = 0;
    stream->chunk_pos = 0;
    stream->buffered = 0;
    fseek(stream->file, 12, SEEK_SET);
    stream->seek(stream, offset);
    SDL_UnlockMutex(stream->dig->mutex);
}

DXDEC void AILCALL AIL_set_stream_volume(HSTREAM stream,S32 volume)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    alSourcef(stream->source, AL_GAIN, volume / 127.0f);
}

DXDEC void AILCALL AIL_set_timer_frequency (HTIMER timer, U32 hertz)
{
    // fprintf(stderr, "%s %d\n", __FUNCTION__, hertz);
    timer->interval = 1000.0 / hertz;
}

DXDEC void AILCALL AIL_shutdown (void)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
}

DXDEC void AILCALL AIL_start_stream(HSTREAM stream)
{
    stream->playing = 1;
}

static Uint32 timer_callback(Uint32 interval, void *param)
{
    HTIMER timer = param;
    
    timer->cb(timer->user);
    return timer->interval;
}

DXDEC void AILCALL AIL_start_timer (HTIMER timer)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    SDL_AddTimer(timer->interval, timer_callback, timer);
}

DXDEC S32 AILCALL AIL_startup (void)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    return 0;
}

DXDEC void AILCALL AIL_stop_sample (HSAMPLE S)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
}

DXDEC void AILCALL AIL_stop_timer (HTIMER timer)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    DebugBreak();
}

DXDEC S32 AILCALL AIL_stream_position(HSTREAM stream)
{
    unsigned int result;
    result = stream->tell(stream);
    return result;
}

DXDEC S32 AILCALL AIL_stream_status(HSTREAM stream)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
    return stream->playing ? 4 : 2;
}

DXDEC void AILCALL AIL_waveOutClose (HDIGDRIVER drvr)
{
    // fprintf(stderr, "%s\n", __FUNCTION__);
}

#if 0
// https://wiki.multimedia.cx/index.php/Microsoft_ADPCM
int AdaptationTable [] = { 
    230, 230, 230, 230, 307, 409, 512, 614, 
    768, 614, 512, 409, 307, 230, 230, 230 
};
int AdaptCoeff1 [] = { 256, 512, 0, 192, 240, 460, 392 };
int AdaptCoeff2 [] = { 0, -256, 0, 64, 0, -208, -232 };

static unsigned int decode_adpcm(signed short *out, const BYTE *data, unsigned int size)
{
    int8_t nibble;
    unsigned int i, samples = 0;
    int predictor;
    int16_t coeff1, coeff2, delta, sample1, sample2;

    coeff1 = AdaptCoeff1[data[0]];
    coeff2 = AdaptCoeff2[data[0]];
    delta = data[1] | (data[2] << 8);
    sample1 = data[3] | (data[4] << 8);
    sample2 = data[5] | (data[6] << 8);

    out[samples++] = sample2;
    out[samples++] = sample1;

    for (i = 7; i < size; i++)
    {
        nibble = (int8_t)data[i] >> 4;
        predictor = ((sample1 * coeff1) + (sample2 * coeff2)) / 256;
        predictor += nibble * delta;
        sample2 = sample1;
        sample1 = sat16(predictor);
        delta = sat16((AdaptationTable[nibble & 15] * delta) / 256);
        out[samples++] = sample1;

        nibble = (int8_t)(data[i] << 4) >> 4;
        predictor = ((sample1 * coeff1) + (sample2 * coeff2)) / 256;
        predictor += nibble * delta;
        sample2 = sample1;
        sample1 = sat16(predictor);
        delta = sat16((AdaptationTable[nibble & 15] * delta) / 256);
        out[samples++] = sample1;
    }

    return samples;
}

static unsigned int decode_adpcm_stereo(signed short *out, const BYTE *data, unsigned int size)
{
    int8_t nibble;
    unsigned int i, samples = 0;
    int lpredictor, rpredictor;
    int16_t lcoeff1, lcoeff2, ldelta, lsample1, lsample2;
    int16_t rcoeff1, rcoeff2, rdelta, rsample1, rsample2;

    lcoeff1 = AdaptCoeff1[data[0]];
    lcoeff2 = AdaptCoeff2[data[0]];
    rcoeff1 = AdaptCoeff1[data[1]];
    rcoeff2 = AdaptCoeff2[data[1]];
    ldelta = data[2] | (data[3] << 8);
    rdelta = data[4] | (data[5] << 8);
    lsample1 = data[6] | (data[7] << 8);
    rsample1 = data[8] | (data[9] << 8);
    lsample2 = data[10] | (data[11] << 8);
    rsample2 = data[12] | (data[13] << 8);

    out[samples++] = lsample2;
    out[samples++] = rsample2;
    out[samples++] = lsample1;
    out[samples++] = rsample1;

    for (i = 14; i < size; i++)
    {
        nibble = (int8_t)data[i] >> 4;
        lpredictor = ((lsample1 * lcoeff1) + (lsample2 * lcoeff2)) / 256;
        lpredictor += nibble * ldelta;
        lsample2 = lsample1;
        lsample1 = sat16(lpredictor);
        ldelta = sat16((AdaptationTable[nibble & 15] * ldelta) / 256);
        out[samples++] = lsample1;

        nibble = (int8_t)(data[i] << 4) >> 4;
        rpredictor = ((rsample1 * rcoeff1) + (rsample2 * rcoeff2)) / 256;
        rpredictor += nibble * rdelta;
        rsample2 = rsample1;
        rsample1 = sat16(rpredictor);
        rdelta = sat16((AdaptationTable[nibble & 15] * rdelta) / 256);
        out[samples++] = rsample1;
    }

    return samples;
}
#endif

static void sample_play_adpcm(HSAMPLE S, const BYTE *data, unsigned int size)
{
    signed short decoded[4096];
    unsigned int decoded_samples = 0;

    if (!S->adpcm)
        DebugBreak();

    if (S->stereo)
        decoded_samples = decode_adpcm_stereo(decoded, data, size);
    else
        decoded_samples = decode_adpcm(decoded, data, size);

    S->hwready--;
#ifdef __EMSCRIPTEN__
    // XXX Emscripten's OpenAL does not do correct things to mono sources. Fake a stereo sample.
    if (!S->stereo)
    {
        unsigned int i;
        for (i = decoded_samples; i > 0; i--)
            decoded[2 * i - 2] = decoded[2 * i - 1] = decoded[i - 1];
        decoded_samples *= 2;
    }
    alBufferData(S->hwbuf[S->hwready], AL_FORMAT_STEREO16, decoded, decoded_samples * 2, S->playback_rate);
#else
    alBufferData(S->hwbuf[S->hwready], S->stereo ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, decoded, decoded_samples * 2, S->playback_rate);
#endif
    checkError();
    alSourceQueueBuffers(S->source, 1, &S->hwbuf[S->hwready]);
    checkError();
}

static void sample_work(HSAMPLE S)
{
    struct _SAMPLE_BUFFER *buf = &S->buffers[S->current];

    if (S->ready == 2)
    {
        sample_eos(S);
        return;
    }

    if (buf->length == 0)
    {
        sample_eob(S);
        sample_eos(S);
        return;
    }

    sample_unqueue_buffers(S);
    
    while (S->hwready)
    {
        ALint state;

        sample_play_adpcm(S, (BYTE *)buf->buffer + buf->position, S->block_size);
        buf->position += S->block_size;

        alGetSourcei(S->source, AL_SOURCE_STATE, &state);
        if (S->playing && state != AL_PLAYING)
            alSourcePlay(S->source);

        if (buf->length == buf->position)
        {
            sample_eob(S);
            buf = &S->buffers[S->current];
            if (buf->length == 0)
                break;
        }
    }
}

static void stream_work(HSTREAM stream)
{
    static WORD buffer[16 * 1024];
    unsigned int channels = stream->stereo ? 2 : 1;
    // We need to queue 33ms of audio data.
    unsigned int min_samples = stream->playback_rate * channels / 30;

    stream_unqueue_buffers(stream);

    while (stream->hwready)
    {
        unsigned int offset = 0;
        ALint state;

        while (offset < min_samples)
        {
            unsigned int samples = stream->decode(stream, buffer + offset, min_samples * 2 - offset);
            if (samples == 0)
                break;
            offset += samples;
        }

        if (offset == 0)
            break;

        stream->hwready--;
        alBufferData(stream->hwbuf[stream->hwready], stream->stereo ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, buffer, offset * 2, stream->playback_rate);
        checkError();
        alSourceQueueBuffers(stream->source, 1, &stream->hwbuf[stream->hwready]);
        checkError();

        alGetSourcei(stream->source, AL_SOURCE_STATE, &state);
        if (stream->playing && state != AL_PLAYING)
            alSourcePlay(stream->source);
    }
}

static Uint32 work_callback(Uint32 interval, void *param)
{
    HDIGDRIVER dig = param;
    HSAMPLE sample;
    HSTREAM stream;

    SDL_LockMutex(dig->mutex);

    for (sample = dig->sample_head; sample; sample = sample->next)
    {
        if (!sample->playing)
            continue;
        sample_work(sample);
    }

    for (stream = dig->stream_head; stream; stream = stream->next)
    {
        if (!stream->playing)
            continue;
        stream_work(stream);
    }

    SDL_UnlockMutex(dig->mutex);

    return interval;
}

DXDEC S32 AILCALL AIL_waveOutOpen (HDIGDRIVER FAR *pdrvr, LPHWAVEOUT FAR *lphWaveOut, S32 wDeviceID, LPWAVEFORMAT lpFormat)
{
    HDIGDRIVER dig = calloc(1, sizeof(*dig));
    // fprintf(stderr, "%s\n", __FUNCTION__);
    dig->device = alcOpenDevice(NULL);
    dprintf("AL device: %08x", (int)dig->device);
    if (!dig->device)
        checkError();
    dig->context = alcCreateContext(dig->device, NULL);
    dprintf("AL context: %08x", (int)dig->context);
    if (!dig->context)
        checkError();
    alcMakeContextCurrent(dig->context);
    checkError();
    dig->mutex = SDL_CreateMutex();
    SDL_AddTimer(1000.0 / 60, work_callback, dig);
    alListenerf(AL_GAIN, 1.0f);
    alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
    *pdrvr = dig;
    return 0;
}
