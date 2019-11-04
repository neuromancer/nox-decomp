#include <stdint.h>

#define AILCALL
#define AILCALLBACK WINAPI
#define DXDEC
#define FAR

typedef int8_t S8;
typedef uint8_t U8;
typedef int16_t S16;
typedef uint16_t U16;
typedef int32_t S32;
typedef uint32_t U32;

typedef struct _DIG_DRIVER * HDIGDRIVER;
typedef struct _SAMPLE * HSAMPLE;
typedef struct _STREAM * HSTREAM;
typedef struct _TIMER *  HTIMER;

typedef void (AILCALLBACK FAR* AILTIMERCB)    (U32 user);
typedef void (AILCALLBACK FAR* AILSAMPLECB)   (HSAMPLE sample);

DXDEC HSAMPLE AILCALL AIL_allocate_sample_handle (HDIGDRIVER dig);
DXDEC void AILCALL AIL_close_stream(HSTREAM stream);
DXDEC void AILCALL AIL_digital_configuration (HDIGDRIVER dig, S32 FAR *rate, S32 FAR *format, char FAR *string);
DXDEC S32 AILCALL AIL_digital_handle_release(HDIGDRIVER drvr);
DXDEC S32 AILCALL AIL_digital_handle_reacquire (HDIGDRIVER drvr);
DXDEC void AILCALL AIL_end_sample (HSAMPLE S);
DXDEC S32 AILCALL AIL_get_preference (U32 number);
DXDEC void AILCALL AIL_init_sample (HSAMPLE S);
DXDEC char FAR *AILCALL AIL_last_error (void);
DXDEC void AILCALL AIL_load_sample_buffer (HSAMPLE S, U32 buff_num, void const FAR *buffer, U32 len);
DXDEC HSTREAM AILCALL AIL_open_stream(HDIGDRIVER dig, char const FAR * filename, S32 stream_mem);
DXDEC void AILCALL AIL_pause_stream(HSTREAM stream, S32 onoff);
DXDEC AILSAMPLECB AILCALL AIL_register_EOB_callback (HSAMPLE S, AILSAMPLECB EOB);
DXDEC AILSAMPLECB AILCALL AIL_register_EOS_callback (HSAMPLE S, AILSAMPLECB EOS);
DXDEC HTIMER AILCALL AIL_register_timer (AILTIMERCB fn);
DXDEC void AILCALL AIL_release_sample_handle (HSAMPLE S);
DXDEC void AILCALL AIL_release_timer_handle (HTIMER timer);
DXDEC void AILCALL AIL_resume_sample (HSAMPLE S);
DXDEC S32 AILCALL AIL_sample_buffer_ready (HSAMPLE S);
DXDEC S32 AILCALL AIL_sample_user_data (HSAMPLE S, U32 index);
DXDEC void AILCALL AIL_serve(void);
DXDEC S32 AILCALL AIL_set_preference (U32 number, S32 value);
DXDEC void AILCALL AIL_set_sample_adpcm_block_size (HSAMPLE S, U32 blocksize);
DXDEC void AILCALL AIL_set_sample_pan (HSAMPLE S, S32 pan);
DXDEC void AILCALL AIL_set_sample_playback_rate (HSAMPLE S, S32 playback_rate);
DXDEC void AILCALL AIL_set_sample_type (HSAMPLE S, S32 format, U32 flags);
DXDEC void AILCALL AIL_set_sample_user_data (HSAMPLE S, U32 index, S32 value);
DXDEC void AILCALL AIL_set_sample_volume (HSAMPLE S, S32 volume);
DXDEC void AILCALL AIL_set_stream_position(HSTREAM stream,S32 offset);
DXDEC void AILCALL AIL_set_stream_volume(HSTREAM stream,S32 volume);
DXDEC void AILCALL AIL_set_timer_frequency (HTIMER timer, U32 hertz);
DXDEC void AILCALL AIL_shutdown (void);
DXDEC void AILCALL AIL_start_stream(HSTREAM stream);
DXDEC void AILCALL AIL_start_timer (HTIMER timer);
DXDEC S32 AILCALL AIL_startup (void);
DXDEC void AILCALL AIL_stop_sample (HSAMPLE S);
DXDEC void AILCALL AIL_stop_timer (HTIMER timer);
DXDEC S32 AILCALL AIL_stream_position(HSTREAM stream);
DXDEC S32 AILCALL AIL_stream_status(HSTREAM stream);
DXDEC void AILCALL AIL_waveOutClose (HDIGDRIVER drvr);
DXDEC S32 AILCALL AIL_waveOutOpen (HDIGDRIVER FAR *drvr, LPHWAVEOUT FAR *lphWaveOut, S32 wDeviceID, LPWAVEFORMAT lpFormat);

