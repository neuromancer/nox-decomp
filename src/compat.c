#include <ctype.h>
#include <fcntl.h>
#include <fenv.h>
#include <glob.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>
#include <wctype.h>
#include "proto.h"

#include <stdlib.h>
#include <string.h>

#include <dirent.h>
#include <errno.h>

#include <SDL2/SDL_stdinc.h>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

enum
{
    HANDLE_FILE,
    HANDLE_PROCESS,
    HANDLE_THREAD,
    HANDLE_MUTEX,
};

struct _REGKEY
{
    char *path;
};

extern const char *progname;
DWORD last_error;
DWORD last_socket_error;
void *handles[1024];

static inline HANDLE new_handle(unsigned int type, void *data)
{
    unsigned int i;
    for (i = 0; i < 1024; i++)
    {
        if (!handles[i])
        {
            handles[i] = data;
            return (HANDLE)((type << 16) | i);
        }
    }
    return (HANDLE)-1;
}

static inline void *lookup_handle(unsigned int type, HANDLE h)
{
    if (type != ((DWORD)h >> 16))
        return NULL;
    if ((WORD)h >= 1024)
        return NULL;
    return handles[(WORD)h];
}

// Debug functions
VOID WINAPI DebugBreak()
{
#ifdef __EMSCRIPTEN__
#else
    asm volatile ("int3");
#endif
}

VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString)
{
    fprintf(stderr, "%s", lpOutputString);
}

// Memory functions
BOOL WINAPI HeapDestroy(HANDLE hHeap)
{
    DebugBreak();
}

// CRT functions
unsigned int _control87(unsigned int new_, unsigned int mask)
{
    if (new_ == 0x300 && mask == 0x300)
        fesetround(FE_TOWARDZERO);
    else
        DebugBreak();
}

unsigned int _controlfp(unsigned int new_, unsigned int mask)
{
    if (new_ == 0x300 && mask == 0x300)
        fesetround(FE_TOWARDZERO);
    else
        DebugBreak();
}

uintptr_t _beginthread(void( __cdecl *start_address )( void * ), unsigned int stack_size, void *arglist)
{
    pthread_t handle;

#ifdef __EMSCRIPTEN__
    fprintf(stderr, "%s: unsupported\n");
    while (1) {}
#endif

    if (pthread_create(&handle, NULL, start_address, arglist))
        return (uintptr_t)-1;

    return new_handle(HANDLE_THREAD, handle);
}

char *_strrev(char *str)
{
    char *begin, *end;

    if (!str[0])
        return str;

    begin = str;
    end = str + strlen(str) - 1;

    while (begin < end)
    {
        char tmp = *end;
        *end = *begin;
        *begin = tmp;
    }

    return str;
}

char *_itoa(int val, char *s, int radix)
{
    return SDL_itoa(val, s, radix);
}

char *_utoa(unsigned int val, char *s, int radix)
{
    return SDL_uitoa(val, s, radix);
}

wchar_t *_itow(int val, wchar_t *s, int radix)
{
    char tmp[32];
    unsigned int i;

    _itoa(val, tmp, radix);
    for (i = 0; tmp[i]; i++)
        s[i] = tmp[i];
    s[i] = 0;

    return s;
}

void _makepath(char *path, const char *drive, const char *dir, const char *fname, const char *ext)
{
    sprintf(path, "%s%s%s%s%s%s%s",
            drive,
            drive && drive[0] && (!dir || dir[0] != '\\') ? "\\" : "",
            dir,
            dir && dir[0] && dir[strlen(dir) - 1] != '\\' ? "\\" : "",
            fname,
            ext && ext[0] && ext[0] != '.' ? "." : "",
            ext);
    dprintf("%s: (\"%s\", \"%s\", \"%s\", \"%s\") = \"%s\"", __FUNCTION__, drive, dir, fname, ext, path);
}

void _splitpath(const char *path, char *drive, char *dir, char *fname, char *ext)
{
    const char *tmp;

    if (isalpha(path[0]) && path[1] == ':')
    {
        if (drive)
        {
            drive[0] = path[0];
            drive[1] = path[1];
            drive[2] = 0;
        }
        path += 2;
    }
    else if (drive)
    {
        drive[0] = 0;
    }

    tmp = strrchr(path, '\\');
    if (tmp)
    {
        if (dir)
        {
            memcpy(dir, path, tmp + 1 - path);
            dir[tmp + 1 - path] = 0;
        }
        path = tmp + 1;
    }
    else if (dir)
    {
        dir[0] = 0;
    }

    tmp = strrchr(path, '.');
    if (tmp)
    {
        if (fname)
        {
            memcpy(fname, path, tmp - path);
            fname[tmp - path] = 0;
        }
        path = tmp;
    }
    else if (fname)
    {
        fname[0] = 0;
    }

    if (ext)
    {
        strcpy(ext, path);
    }

    //dprintf("%s: \"%s\" = (\"%s\", \"%s\", \"%s\", \"%s\")", __FUNCTION__, path, drive, dir, fname, ext);
}

// Misc functions
BOOL WINAPI CloseHandle(HANDLE hObject)
{
    switch ((DWORD)hObject >> 16)
    {
    case 0:
        close((WORD)hObject);
        break;
    case HANDLE_THREAD:
        handles[(WORD)hObject] = NULL;
        break;
    case HANDLE_MUTEX:
        {
            pthread_mutex_t *m = lookup_handle(HANDLE_MUTEX, hObject);
            pthread_mutex_destroy(m);
            free(m);
        }
        handles[(WORD)hObject] = NULL;
        break;
    default:
        DebugBreak();
        return FALSE;
    }

    return TRUE;
}

DWORD WINAPI GetModuleFileNameA(HMODULE hModule, LPSTR lpFileName, DWORD nSize)
{
    unsigned int i, size = strlen(progname);
    DWORD ret;

    if (hModule != NULL)
        DebugBreak();

    if (size < nSize)
    {
        strcpy(lpFileName, progname);
        ret = size;
    }
    else if (nSize)
    {
        memcpy(lpFileName, progname, nSize);
        lpFileName[nSize-1] = 0;
        ret = nSize;
    }

    for (i = 0; lpFileName[i]; i++)
        if (lpFileName[i] == '/')
            lpFileName[i] = '\\';

    return ret;
}

DWORD WINAPI GetLastError()
{
    return last_error;
}

BOOL WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInformation)
{
    lpVersionInformation->dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);
    lpVersionInformation->dwMajorVersion = 5;
    lpVersionInformation->dwMinorVersion = 1;
    return TRUE;
}

LONG InterlockedExchange(volatile LONG *Target, LONG Value)
{
    return __sync_lock_test_and_set(Target, Value);
}

LONG InterlockedDecrement(volatile LONG *Addend)
{
    return __sync_fetch_and_sub(Addend, 1);
}

LONG InterlockedIncrement(volatile LONG *Addend)
{
    return __sync_fetch_and_add(Addend, 1);
}

int WINAPI MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    DebugBreak();
}

int WINAPI MulDiv(int nNumber, int nNumerator, int nDenominator)
{
    DebugBreak();
}

HINSTANCE WINAPI ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd)
{
    DebugBreak();
}

int WINAPI WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar)
{
    DebugBreak();
}

// Socket functions
int WINAPI WSAStartup(WORD wVersionRequested, struct WSAData *lpWSAData)
{
    return 0;
}

int WINAPI WSACleanup()
{
    return 0;
}

SOCKET WINAPI socket(int domain, int type, int protocol)
#undef socket
{
#ifdef __EMSCRIPTEN__
    static int fd = 1024;
    return fd++;
#else
    return socket(domain, type, protocol);
#endif
}

int WINAPI closesocket(SOCKET s)
{
    close(s);
    return 0;
}

char *WINAPI inet_ntoa(struct in_addr compat_addr)
#undef in_addr
#undef inet_ntoa
{
    struct in_addr addr;

    addr.s_addr = compat_addr.S_un.S_addr;
    return inet_ntoa(addr);
}

int WINAPI setsockopt(SOCKET s, int level, int opt, const void *value, unsigned int len)
#undef setsockopt
{
#ifdef __EMSCRIPTEN__
    return 0;
#else
    return setsockopt(s, level, opt, value, len);
#endif
}

int WINAPI ioctlsocket(SOCKET s, long cmd, unsigned long *argp)
{
    int ret;

    switch (cmd)
    {
    case 0x4004667f: // FIONREAD
#ifdef __EMSCRIPTEN__
        *argp = EM_ASM_INT({
            return network.available($0);
        }, s);
        ret = 0;
#else
        ret = ioctl(s, FIONREAD, argp);
#endif
        break;
    default:
        DebugBreak();
        ret = -1;
        break;
    }

    return ret;
}

#ifdef __EMSCRIPTEN__
void build_server_info(void *arg)
{
    static char oldbuf[256];
    static int oldlen;
    char buf[256];
    int dummy[3] = { 0, 0, 0 };
    int length, ready;

    ready = EM_ASM_INT({
        return network.isready();
    });

    if (!ready) {
        oldlen = 0;
        return;
    }
    
    length = sub_554040(dummy, sizeof(buf), buf);
    if (oldlen != length || memcmp(buf, oldbuf, length) != 0)
    {
        memcpy(oldbuf, buf, length);
        oldlen = length;

        EM_ASM_({
            network.registerServer($1 > 0 ? Module.HEAPU8.slice($0, $0 + $1) : null);
        }, oldbuf, oldlen);
    }
}
#endif

int WINAPI bind(int sockfd, const struct sockaddr *addr, unsigned int addrlen)
#undef bind
{
    int ret;
#ifdef __EMSCRIPTEN__
    static long updater = -1;

    EM_ASM_({
        network.bind($0);
    }, sockfd);

    if (updater == -1)
        updater = emscripten_set_interval(build_server_info, 1000, NULL);

    ret = 0;
#else
    ret = bind(sockfd, addr, addrlen);
#endif
    if (ret >= 0)
        return ret;

    switch (errno)
    {
    case EADDRINUSE:
        last_socket_error = 10048u;
        break;
    default:
        DebugBreak();
        break;
    }

    return -1;
}

int WINAPI recvfrom(int sockfd, void *buffer, unsigned int length, int flags, struct sockaddr *addr, unsigned int *addrlen)
#undef recvfrom
{
#ifdef __EMSCRIPTEN__
    int ret;
    struct sockaddr_in *addr_in = addr;
    ret = EM_ASM_INT(({
        const [ remote, port, data ] = network.recvfrom($4);
        if (remote === null)
            return -1;
        const length = Math.min(data.length, $1);
        Module.HEAPU8.set(new Uint8Array(data, 0, length), $0);
        if ($2) {
            Module.HEAPU32[$2 >> 2] = remote;
        }
        if ($3) {
            Module.HEAPU8[$3] = port >> 8;
            Module.HEAPU8[$3 + 1] = port >> 0;
        }
        return length;
    }), buffer, length, addr_in ? &addr_in->sin_addr : NULL, addr_in ? &addr_in->sin_port : NULL, sockfd);
    if (addr_in)
        addr_in->sin_family = AF_INET;
    return ret;
#else
    return recvfrom(sockfd, buffer, length, flags, addr, addrlen);
#endif
}

int WINAPI sendto(int sockfd, void *buffer, unsigned int length, int flags, const struct sockaddr *addr, unsigned int addrlen)
#undef sendto
{
#ifdef __EMSCRIPTEN__
    struct sockaddr_in *addr_in = addr;
    unsigned int dest = addr_in->sin_addr.s_addr;
    unsigned char *p = buffer;

    // broadcast packet
    if (dest == 0xffffffff)
    {
        if (p[2] == 12)
        {
            EM_ASM_({
                network.isready() && network.listServers($0, $1)
            }, *(DWORD *)(p + 8), sockfd);
        }
        return length;
    }

    return EM_ASM_INT({
        network.sendto($3, $2, $4, Module.HEAPU8.slice($0, $0 + $1));
        return $1;
    }, buffer, length, dest, sockfd, ntohs(addr_in->sin_port));
#else
    return sendto(sockfd, buffer, length, flags, addr, addrlen);
#endif
}

int WINAPI WSAGetLastError()
{
    return last_socket_error;
}

// Time functions
// compatGetDateFormatA(Locale=2048, dwFlags=1, lpDate=0x1708c6a4, lpFormat=0x00000000, lpDateStr="nox.str:Warrior", cchDate=256) at compat.c:1001
int WINAPI GetDateFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCSTR lpFormat, LPSTR lpDateStr, int cchDate)
{
    if (Locale != 0x800 || dwFlags != 1 || lpFormat)
        DebugBreak();

    // default locale, short date (M/d/yy)
    return snprintf(lpDateStr, cchDate, "%d/%d/%02d", lpDate->wMonth, lpDate->wDay, lpDate->wYear % 100);
}

int WINAPI GetTimeFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, int cchTime)
{
    if (Locale != 0x800 || dwFlags != 14 || lpFormat)
        DebugBreak();

    // default locale, 24 hour, no time marker, no seconds
    return snprintf(lpTimeStr, cchTime, "%02d:%02d", lpTime->wHour, lpTime->wMinute);
}

BOOL WINAPI SystemTimeToFileTime(const SYSTEMTIME *lpSystemTime, LPFILETIME lpFileTime)
{
    QWORD t;
    struct tm tm;

    tm.tm_sec = lpSystemTime->wSecond;
    tm.tm_min = lpSystemTime->wMinute;
    tm.tm_hour = lpSystemTime->wHour;
    tm.tm_mday = lpSystemTime->wDay;
    tm.tm_mon = lpSystemTime->wMonth;
    tm.tm_year = lpSystemTime->wYear - 1900;
    tm.tm_isdst = -1;
    tm.tm_zone = NULL;
    tm.tm_gmtoff = 0;

    t = mktime(&tm);
    t = (t * 1000 + lpSystemTime->wMilliseconds) * 10000;
    lpFileTime->dwLowDateTime = t & 0xffffffff;
    lpFileTime->dwHighDateTime = t >> 32;
}

LONG WINAPI CompareFileTime(const FILETIME *lpFileTime1, const FILETIME *lpFileTime2)
{
    if (lpFileTime1->dwHighDateTime != lpFileTime2->dwHighDateTime)
        return (LONG)lpFileTime1->dwHighDateTime - (LONG)lpFileTime2->dwHighDateTime;
    if (lpFileTime1->dwLowDateTime != lpFileTime2->dwLowDateTime)
        return (LONG)lpFileTime1->dwLowDateTime - (LONG)lpFileTime2->dwLowDateTime;
}

VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime)
{
    time_t t;
    struct tm *tm;

    time(&t);
    tm = localtime(&t);

    lpSystemTime->wYear = tm->tm_year + 1900;
    lpSystemTime->wMonth = tm->tm_mon;
    lpSystemTime->wDayOfWeek = tm->tm_wday;
    lpSystemTime->wDay = tm->tm_mday;
    lpSystemTime->wHour = tm->tm_hour;
    lpSystemTime->wMinute = tm->tm_min;
    lpSystemTime->wSecond = tm->tm_sec;
    lpSystemTime->wMilliseconds = 0;
}

BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    lpPerformanceCount->QuadPart = (QWORD)tv.tv_sec * 1000000 + tv.tv_usec;
    return TRUE;
}

BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency)
{
    lpFrequency->QuadPart = 1000000;
    return TRUE;
}

VOID WINAPI Sleep(DWORD dwMilliseconds)
{
#ifndef __EMSCRIPTEN__
    SDL_Delay(dwMilliseconds);
#endif
}

DWORD WINAPI timeGetTime()
{
    return SDL_GetTicks();
}

DWORD WINAPI GetTickCount()
{
    return timeGetTime();
}

// File functions
static char *dos_to_unix(const char *path)
{
    int i, len = strlen(path);
    char *str = malloc(len + 1);

    if (path[0] == 'C' && path[1] == ':')
        path += 2;
    
    for (i = 0; path[i]; i++)
    {
        if (path[i] == '\\')
            str[i] = '/';
        else
            str[i] = path[i];
    }
    str[i] = 0;

    return str;
}

struct _FIND_FILE
{
    size_t idx;
    glob_t globbuf;
};

static void fill_find_data(const char *path, LPWIN32_FIND_DATAA lpFindFileData)
{
    struct stat st;
    const char *filename = strrchr(path, '/');
    filename = filename == NULL ? path : filename + 1;

    stat(path, &st);

    memset(lpFindFileData, 0, sizeof(*lpFindFileData));
    lpFindFileData->dwFileAttributes = S_ISDIR(st.st_mode) ? FILE_ATTRIBUTE_DIRECTORY : FILE_ATTRIBUTE_NORMAL;
    lpFindFileData->nFileSizeHigh = st.st_size >> 32;
    lpFindFileData->nFileSizeLow = st.st_size;
    strcpy(lpFindFileData->cFileName, filename);

    // dprintf("%s: attr=0x%X, filename=%s", __FUNCTION__, lpFindFileData->dwFileAttributes, lpFindFileData->cFileName);
}

HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
{
    char *converted = dos_to_unix(lpFileName);
    int len = strlen(converted);
    struct _FIND_FILE *ff = calloc(sizeof(*ff), 1);

    dprintf("%s: converted=%s", __FUNCTION__, converted);

    // glob is close enough to the semantics
    if (len >= 2 && converted[len - 2] == '.' && converted[len - 1] == '*')
        converted[len - 2] = 0;
    if (glob(converted, GLOB_NOESCAPE, NULL, &ff->globbuf))
    {
        free(ff);
        return (HANDLE)-1;
    }

    fill_find_data(ff->globbuf.gl_pathv[ff->idx++], lpFindFileData);
    return (HANDLE)ff;
}

BOOL WINAPI FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
{
    struct _FIND_FILE *ff = (struct _FIND_FILE *)hFindFile;

    if (ff->idx >= ff->globbuf.gl_pathc)
    {
        last_error = ERROR_NO_MORE_FILES;
        return FALSE;
    }

    fill_find_data(ff->globbuf.gl_pathv[ff->idx++], lpFindFileData);
    return TRUE;
}

BOOL WINAPI FindClose(HANDLE hFindFile)
{
    struct _FIND_FILE *ff = (struct _FIND_FILE *)hFindFile;

    globfree(&ff->globbuf);
    free(ff);
    return TRUE;
}

HANDLE WINAPI CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
    char *converted = dos_to_unix(lpFileName);
    int fd, flags;

    switch (dwDesiredAccess)
    {
    case GENERIC_READ:
        flags = O_RDONLY;
        break;
    case GENERIC_WRITE:
        flags = O_WRONLY;
        break;
    case GENERIC_READ|GENERIC_WRITE:
        flags = O_RDWR;
        break;
    default:
        DebugBreak();
    }

    switch (dwCreationDisposition)
    {
    case CREATE_NEW:
        flags |= O_CREAT | O_EXCL;
        break;
    case CREATE_ALWAYS:
        flags |= O_CREAT | O_TRUNC;
        break;
    default:
    case OPEN_EXISTING:
        break;
    case OPEN_ALWAYS:
        flags |= O_CREAT;
        break;
    case TRUNCATE_EXISTING:
        flags |= O_TRUNC;
        break;
    }
    
    fd = open(converted, flags, 0666);
    dprintf("%s: CreateFileA(%s) = %08x\n", __FUNCTION__, converted, fd);
    free(converted);
    return (HANDLE)fd;
}

BOOL WINAPI ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
    int fd = (int)hFile;
    int ret;

    if (lpOverlapped)
        DebugBreak();

    ret = read(fd, lpBuffer, nNumberOfBytesToRead);
    if (ret >= 0)
    {
        *lpNumberOfBytesRead = ret;
        last_error = 0;
        return TRUE;
    }
    else
    {
        *lpNumberOfBytesRead = 0;
        last_error = 2; // FIXME
        return FALSE;
    }
}

DWORD WINAPI SetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod)
{
    int fd = (int)hFile;
    int whence;
    off_t offset;

    if (lpDistanceToMoveHigh && *lpDistanceToMoveHigh)
        DebugBreak();

    switch (dwMoveMethod)
    {
    case FILE_BEGIN:
        whence = SEEK_SET;
        break;
    case FILE_CURRENT:
        whence = SEEK_CUR;
        break;
    case FILE_END:
        whence = SEEK_END;
        break;
    default:
        DebugBreak();
    }

    if (lpDistanceToMoveHigh)
        *lpDistanceToMoveHigh = 0;

    offset = lseek(fd, lDistanceToMove, whence);
    if (offset != (off_t)-1)
        last_error = 0;
    else
        last_error = 2; // FIXME
    return offset;
}

BOOL WINAPI CopyFileA(LPCSTR lpExistingFileName, LPCSTR lpNewFileName, BOOL bFailIfExists)
{
    char buf[1024];
    int rfd = _open(lpExistingFileName, O_RDONLY);
    int wfd;

    if (rfd < 0)
        return FALSE;
    
    wfd = _open(lpNewFileName, bFailIfExists ? O_WRONLY | O_CREAT | O_EXCL : O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (wfd < 0)
    {
error:
        close(rfd);
        return FALSE;
    }

    while (1)
    {
        int ret = read(rfd, buf, sizeof(buf));
        if (ret <= 0)
            break;
        if (write(wfd, buf, ret) != ret)
            goto error;
    }

    close(rfd);
    close(wfd);
    return TRUE;
}

BOOL WINAPI DeleteFileA(LPCSTR lpFileName)
{
    return _unlink(lpFileName) == 0;
}

BOOL WINAPI MoveFileA(LPCSTR lpExistingFileName, LPCSTR lpNewFileName)
{
    char *converted = dos_to_unix(lpExistingFileName);
    free(converted);
    dprintf("%s\n", __FUNCTION__);
    DebugBreak();
}

BOOL WINAPI CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
    return _mkdir(lpPathName) == 0;
}

BOOL WINAPI RemoveDirectoryA(LPCSTR lpPathName)
{
    int result;
    char *converted = dos_to_unix(lpPathName);
    result = rmdir(converted);
    free(converted);
    return result == 0;
}

DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer)
{
    dprintf("%s: GetCurrentDirectoryA(%s)\n", __FUNCTION__, lpBuffer);
 
    if (_getcwd(lpBuffer, nBufferLength))
        return strlen(lpBuffer);
    else
        return 0;
}

BOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName)
{
    int result;
    char *converted = dos_to_unix(lpPathName);
    dprintf("%s: chdir(%s)\n", __FUNCTION__, converted);
    result = chdir(converted);
    free(converted);
    return result == 0;
}

int _open(const char *filename, int oflag, ...)
{
    va_list ap;
    int fd;
    char *converted = dos_to_unix(filename);

    va_start(ap, oflag);
    dprintf("%s: _open(%s,%x)\n", __FUNCTION__, converted, oflag);
 
    fd = open(converted, oflag, va_arg(ap, int));
    va_end(ap);

    free(converted);
    return fd;
}

int _chmod(const char *filename, int mode)
{
    int result;
    char *converted = dos_to_unix(filename);
    result = chmod(converted, mode);
    free(converted);
    return result;
}

int _access(const char *filename, int mode)
{
    int result;
    char *converted = dos_to_unix(filename);
    result = access(converted, mode);
    free(converted);
    return result;
}

int _stat(const char *path, struct _stat *buffer)
{
    int result;
    char *converted = dos_to_unix(path);
    struct stat st;

    result = stat(converted, &st);
    free(converted);

    if (result)
        return result;

    buffer->st_dev = st.st_dev;
    buffer->st_ino = st.st_ino;
    buffer->st_mode = st.st_mode;
    buffer->st_nlink = st.st_nlink;
    buffer->st_uid = st.st_uid;
    buffer->st_gid = st.st_gid;
    buffer->st_rdev = st.st_rdev;
    buffer->st_size = st.st_size;
#ifdef __APPLE__
    buffer->st_mtime = st.st_mtimespec.tv_sec;
    buffer->st_atime = st.st_atimespec.tv_sec;
    buffer->st_ctime = st.st_ctimespec.tv_sec;
#else
    buffer->st_mtime = st.st_mtim.tv_sec;
    buffer->st_atime = st.st_atim.tv_sec;
    buffer->st_ctime = st.st_ctim.tv_sec;
#endif
    return result;
}

int _mkdir(const char *path)
{
    int result;
    char *converted = dos_to_unix(path);
    result = mkdir(converted, 0777);
    free(converted);
    return result;
}

int _unlink(const char *filename)
{
    int result;
    char *converted = dos_to_unix(filename);
    result = unlink(converted);
    free(converted);
    return result;
}

char *_getcwd(char *buffer, int maxlen)
{
    int i;

    if (maxlen < 2)
        return NULL;

    strcpy(buffer, "C:");
    if (!getcwd(buffer + 2, maxlen - 2))
        return NULL;
    
    for (i = 0; buffer[i]; i++)
        if (buffer[i] == '/')
            buffer[i] = '\\';

    printf("%s: _getcwd(%s, %d)\n", __FUNCTION__, buffer, maxlen); 
    return buffer;
}

// r must have strlen(path) + 2 bytes
static int casepath(char const *path, char *r)
{
    size_t l = strlen(path);
    char *p = alloca(l + 1);
    strcpy(p, path);
    size_t rl = 0;
    
    DIR *d;
    if (p[0] == '/')
    {
        d = opendir("/");
        p = p + 1;
    }
    else
    {
        d = opendir(".");
        r[0] = '.';
        r[1] = 0;
        rl = 1;
    }
    
    int last = 0;
    char *c = strsep(&p, "/");
    while (c)
    {
        if (!d)
        {
            return 0;
        }
        
        if (last)
        {
            closedir(d);
            return 0;
        }
        
        r[rl] = '/';
        rl += 1;
        r[rl] = 0;
        
        struct dirent *e = readdir(d);
        while (e)
        {
            if (strcasecmp(c, e->d_name) == 0)
            {
                strcpy(r + rl, e->d_name);
                rl += strlen(e->d_name);

                closedir(d);
                d = opendir(r);
                
                break;
            }
            
            e = readdir(d);
        }
        
        if (!e)
        {
            strcpy(r + rl, c);
            rl += strlen(c);
            last = 1;
        }
        
        c = strsep(&p, "/");
    }
    
    if (d) closedir(d);
    return 1;
}

void casechdir(char const *path)
{
    char *r = alloca(strlen(path) + 2);
    if (casepath(path, r))
    {
        chdir(r);
    }
    else
    {
        errno = ENOENT;
    }
}

FILE *fopen(const char *path, const char *mode)
#undef fopen
{
    FILE *result;
    char *converted = dos_to_unix(path);
    char *converted_ptr = converted;
    printf("%s: fcaseopen(%s)\n", __FUNCTION__, converted);

    char *r = alloca(strlen(converted) + 2);
    char *cdir = get_current_dir_name();

    // Some paths are absolute for some reason 
    if (strstr(converted, cdir) == converted_ptr) {
	converted = converted + strlen(cdir) + 1;
    }
	
    free(cdir);
    int found = casepath(converted, r);

    if (found == 0)
	 r = converted; 
         //dprintf("%s not found!\n", converted);
      
    result = fopen(r, mode);
    dprintf("%s: fopen(%s, %s, %s) = %08x\n", __FUNCTION__, r, mode, (int)result);
  
    free(converted_ptr);
    return result;
}

char *fgets(char *str, int size, FILE *stream)
#undef fgets
{
    char *result;
    //printf("stream: %x, size: %d, str: %x\n", stream, size, str);

    result = fgets(str, size, stream);
    //printf("%s: fgets(%s) = %s\n", __FUNCTION__, str, result);
 
    if (result)
    {
        // XXX hack for text-mode line conversion
        size = strlen(result);
        if (size >= 2 && result[size - 1] == '\n' && result[size - 2] == '\r')
        {
            result[size - 2] = '\n';
            result[size - 1] = '\0';
        }
    }
    //printf("%s: fgets(%s) = %s\n", __FUNCTION__, str, result);

    return result;
}

// Registry functions
LSTATUS WINAPI RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition)
{
    DebugBreak();
}

LSTATUS WINAPI RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
    HKEY hkResult;
    const char *root;

    if (hKey == HKEY_LOCAL_MACHINE)
        root = "HKEY_LOCAL_MACHINE";
    else
        root = hKey->path;

    hkResult = calloc(sizeof(*hkResult), 1);
    hkResult->path = malloc(strlen(root) + strlen(lpSubKey) + 2);
    sprintf(hkResult->path, "%s\\%s", root, lpSubKey);
    *phkResult = hkResult;
    return 0;
}

LSTATUS WINAPI RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
    dprintf("%s: key=\"%s\", value=\"%s\"", __FUNCTION__, hKey->path, lpValueName);

    if (strcmp(hKey->path, "HKEY_LOCAL_MACHINE\\SOFTWARE\\Westwood\\Nox") == 0 && strcmp(lpValueName, "Serial") == 0)
    {
        int i;
        for (i = 0; i < *lpcbData - 1; i++)
            lpData[i] = (rand() % 10) + '0';
        lpData[i] = 0;
        *lpType = 1; // REG_SZ
        return 0;
    }

    return 3;
}

LSTATUS WINAPI RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData)
{
    DebugBreak();
}

LSTATUS WINAPI RegCloseKey(HKEY hKey)
{
    free(hKey->path);
    free(hKey);
}

// Synchronization functions
VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    lpCriticalSection->opaque = SDL_CreateMutex();
}

VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    SDL_DestroyMutex(lpCriticalSection->opaque);
}

VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    SDL_LockMutex(lpCriticalSection->opaque);
}

VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    SDL_UnlockMutex(lpCriticalSection->opaque);
}

HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpSecurityAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
    pthread_mutex_t *m = malloc(sizeof(pthread_mutex_t));
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(m, &attr);
    pthread_mutexattr_destroy(&attr);

    if (bInitialOwner)
        pthread_mutex_lock(m);

    return new_handle(HANDLE_MUTEX, m);
}

BOOL WINAPI ReleaseMutex(HANDLE hMutex)
{
    pthread_mutex_t *m = lookup_handle(HANDLE_MUTEX, hMutex);
    if (m == NULL)
        return FALSE;
    pthread_mutex_unlock(m);
    return TRUE;
}

BOOL WINAPI SetEvent(HANDLE hEvent)
{
    DebugBreak();
}

DWORD WINAPI WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
{
    DWORD result = (DWORD)-1;
    struct timespec tv;

    clock_gettime(CLOCK_REALTIME, &tv);
    tv.tv_sec += dwMilliseconds / 1000;
    tv.tv_nsec += (dwMilliseconds % 1000) * 1000000;
    while (tv.tv_nsec >= 1000000000)
    {
        tv.tv_sec++;
        tv.tv_nsec -= 1000000000;
    }

    switch ((DWORD)hHandle >> 16)
    {
    case HANDLE_THREAD:
        {
            pthread_t thr = lookup_handle(HANDLE_THREAD, hHandle);
            result = 0;
            if (dwMilliseconds == INFINITE)
                pthread_join(thr, NULL);
#if defined(__APPLE__) || defined(__EMSCRIPTEN__)
            else
                pthread_join(thr, NULL);
#else
            else if (pthread_timedjoin_np(thr, NULL, &tv) == ETIMEDOUT)
                result = 0x102;
#endif
        }
        break;
    case HANDLE_MUTEX:
        {
            pthread_mutex_t *m = lookup_handle(HANDLE_MUTEX, hHandle);
            result = 0;
            if (dwMilliseconds == INFINITE)
                pthread_mutex_lock(m);
#if defined(__APPLE__) || defined(__EMSCRIPTEN__)
            else
                pthread_mutex_lock(m);
#else
            else if (pthread_mutex_timedlock(m, &tv) == ETIMEDOUT)
                result = 0x102;
#endif
        }
        break;
    default:
        DebugBreak();
        break;
    }

    return result;
}
