#ifndef COMPAT_WINDOWS_H
#define COMPAT_WINDOWS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define __cdecl
#define __fastcall
#define __stdcall
#define WINAPI
#define WINAPIV

#define FALSE (0)
#define TRUE (1)
#define MAX_PATH 260
#define INFINITE ((DWORD)-1)

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

typedef void VOID;
typedef unsigned char BYTE;
typedef char CHAR;
typedef wchar_t WCHAR;
typedef unsigned short WORD;
typedef int INT;
typedef unsigned int DWORD;
typedef unsigned int UINT;
typedef int LONG;
typedef unsigned int ULONG;
typedef long long LONGLONG;
typedef unsigned long long ULONGLONG;
typedef uint64_t QWORD;
typedef void *LPVOID;
typedef DWORD DWORD_PTR;
typedef intptr_t INT_PTR;
typedef uintptr_t UINT_PTR;

typedef int BOOL;
typedef BOOL *LPBOOL;
typedef BYTE *LPBYTE;
typedef DWORD *LPDWORD;
typedef LONG *PLONG;
typedef const char *LPCCH;
typedef const char *LPCSTR;
typedef char *LPSTR;
typedef const wchar_t *LPCWSTR;
typedef wchar_t *LPWSTR;

typedef int HANDLE;
typedef int HDC;
typedef int HIMC;
typedef void *HINSTANCE;
typedef struct _REGKEY *HKEY;
typedef HKEY *PHKEY;
#define HKEY_LOCAL_MACHINE ((HKEY)1)
typedef int HKL;
typedef void *HMODULE;
typedef int HPALETTE;
typedef int HRESULT;
typedef int HWND;
typedef int LCID;
typedef int REGSAM;
typedef int SOCKET;
typedef INT_PTR LRESULT;
typedef INT_PTR LSTATUS;
typedef INT_PTR LPARAM;
typedef UINT_PTR WPARAM;

typedef struct _WAVEOUT * HWAVEOUT;
typedef HWAVEOUT *LPHWAVEOUT;

typedef struct {
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
} WAVEFORMAT, *LPWAVEFORMAT;

typedef struct {
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wBitsPerSample;
    WORD cbSize;
} WAVEFORMATEX;

typedef struct {
    WAVEFORMATEX wfx;
    WORD wID;
    DWORD fdwFlags;
    WORD nBlockSize;
    WORD nFramesPerBlock;
    WORD nCodecDelay;
} MPEGLAYER3WAVEFORMAT;

typedef struct _GUID {
    DWORD Data1;
    WORD Data2;
    WORD Data3;
    BYTE Data4[8];
} GUID;
typedef GUID IID;

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *LPSYSTEMTIME;

typedef struct _MEMORYSTATUS {
    DWORD dwLength;
} MEMORYSTATUS, *LPMEMORYSTATUS;

typedef union _LARGE_INTEGER {
    QWORD QuadPart;
    DWORD LowPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *LPFILETIME;

typedef struct _SECURITY_ATTRIBUTES {
} SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _CRITICAL_SECTION {
    void *opaque;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;

typedef struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    BYTE szCSDVersion[128];
} OSVERSIONINFOA, *LPOSVERSIONINFOA;

typedef struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_PATH];
    CHAR cAlternateFileName[14];
} WIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

typedef struct _OVERLAPPED {
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _RECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *LPRECT;

typedef struct _POINT {
    LONG x;
    LONG y;
} POINT;

struct WSAData {
    WORD wVersion;
    WORD wHighVersion;
    CHAR szDescription[257];
    CHAR szSystemStatus[129];
    WORD iMaxSockets;
    WORD iMaxUdpDg;
    LPVOID lpVendorInfo;
} WSADATA, *LPWSADATA;

struct compatin_addr {
    union {
        DWORD S_addr;
    } S_un;
};

#include <sys/stat.h>
#undef st_mtime
#undef st_atime
#undef st_ctime
struct compat_stat {
    DWORD st_dev;
    WORD st_ino;
    WORD st_mode;
    WORD st_nlink;
    WORD st_uid;
    WORD st_gid;
    DWORD st_rdev;
    DWORD st_size;
    DWORD st_mtime;
    DWORD st_atime;
    DWORD st_ctime;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

enum
{
    CREATE_NEW = 1,
    CREATE_ALWAYS,
    OPEN_EXISTING,
    OPEN_ALWAYS,
    TRUNCATE_EXISTING,
};

enum
{
    GENERIC_READ = 0x80000000,
    GENERIC_WRITE = 0x40000000,
};

enum
{
    FILE_ATTRIBUTE_DIRECTORY = 0x10,
    FILE_ATTRIBUTE_NORMAL = 0x80,
};

enum
{
    FILE_BEGIN = 0,
    FILE_CURRENT,
    FILE_END
};

enum
{
    ERROR_NO_MORE_FILES = 18,
};

#define DebugBreak compatDebugBreak
#define CloseHandle compatCloseHandle
#define GetLastError compatGetLastError
#define GetLocalTime compatGetLocalTime
#define GetTickCount compatGetTickCount
#define Sleep compatSleep
#define timeGetTime compattimeGetTime
#define FindFirstFileA compatFindFirstFileA
#define FindNextFileA compatFindNextFileA
#define FindClose compatFindClose
#define CreateFileA compatCreateFileA
#define ReadFile compatReadFile
#define SetFilePointer compatSetFilePointer
#define CopyFileA compatCopyFileA
#define DeleteFileA compatDeleteFileA
#define MoveFileA compatMoveFileA
#define CreateDirectoryA compatCreateDirectoryA
#define RemoveDirectoryA compatRemoveDirectoryA
#define GetCurrentDirectoryA compatGetCurrentDirectoryA
#define SetCurrentDirectoryA compatSetCurrentDirectoryA
#define GetDateFormatA compatGetDateFormatA
#define RegOpenKeyExA compatRegOpenKeyExA
#define RegQueryValueExA compatRegQueryValueExA
#define RegSetValueExA compatRegSetValueExA
#define RegCloseKey compatRegCloseKey
#define MulDiv compatMulDiv
#define RegCreateKeyExA compatRegCreateKeyExA
#define GlobalMemoryStatus compatGlobalMemoryStatus
#define GetModuleFileNameA compatGetModuleFileNameA
#define QueryPerformanceCounter compatQueryPerformanceCounter
#define QueryPerformanceFrequency compatQueryPerformanceFrequency
#define InitializeCriticalSection compatInitializeCriticalSection
#define DeleteCriticalSection compatDeleteCriticalSection
#define EnterCriticalSection compatEnterCriticalSection
#define LeaveCriticalSection compatLeaveCriticalSection
#define HeapDestroy compatHeapDestroy
#define GetVersionExA compatGetVersionExA
#define OutputDebugStringA compatOutputDebugStringA
#define ShellExecuteA compatShellExecuteA
#define GetTimeFormatA compatGetTimeFormatA
#define SystemTimeToFileTime compatSystemTimeToFileTime
#define CompareFileTime compatCompareFileTime
#define CreateMutexA compatCreateMutexA
#define ReleaseMutex compatReleaseMutex
#define SetEvent compatSetEvent
#define WaitForSingleObject compatWaitForSingleObject
#define in_addr compatin_addr
#define inet_ntoa compatinet_ntoa
#define CopyRect compatCopyRect
#define SetRect compatSetRect
#define IsRectEmpty compatIsRectEmpty
#define _rotl compat_rotl
#define _strrev compat_strrev
#define _itoa compat_itoa
#define _itow compat_itow
#define _makepath compat_makepath
#define _splitpath compat_splitpath
#define WSAStartup compatWSAStartup
#define WSACleanup compatWSACleanup
#define socket compatsocket
#define setsockopt compatsetsockopt
#define bind compatbind
#define closesocket compatclosesocket
#define ioctlsocket compatioctlsocket
#define WSAGetLastError compatWSAGetLastError
#define recvfrom compatrecvfrom
#define sendto compatsendto
#define InterlockedExchange compatInterlockedExchange
#define InterlockedDecrement compatInterlockedDecrement
#define InterlockedIncrement compatInterlockedIncrement
#define MessageBoxA compatMessageBoxA
#define _beginthread compat_beginthread
#define WideCharToMultiByte compatWideCharToMultiByte
#define _control87 compat_control87
#define _controlfp compat_controlfp
#define _open compat_open
#define _chmod compat_chmod
#define _access compat_access
#define _stat compat_stat
#define _mkdir compat_mkdir
#define _unlink compat_unlink
#define _getcwd compat_getcwd
#define fopen compat_fopen
#define fgets compat_fgets

#define _strdup strdup
#define _strcmpi strcasecmp
#define _strnicmp strncasecmp
#define _fileno fileno
#define _read read
#define _write write
#define _close close
#define _onexit atexit

VOID WINAPI DebugBreak();
BOOL WINAPI CloseHandle(HANDLE hObject);
DWORD WINAPI GetLastError();
VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
DWORD WINAPI GetTickCount();
VOID WINAPI Sleep(DWORD dwMilliseconds);
DWORD WINAPI timeGetTime();
HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
BOOL WINAPI FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
BOOL WINAPI FindClose(HANDLE hFindFile);
HANDLE WINAPI CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
BOOL WINAPI ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
DWORD WINAPI SetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
BOOL WINAPI CopyFileA(LPCSTR lpExistingFileName, LPCSTR lpNewFileName, BOOL bFailIfExists);
BOOL WINAPI DeleteFileA(LPCSTR lpFileName);
BOOL WINAPI MoveFileA(LPCSTR lpExistingFileName, LPCSTR lpNewFileName);
BOOL WINAPI CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BOOL WINAPI RemoveDirectoryA(LPCSTR lpPathName);
DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer);
BOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName);
int WINAPI GetDateFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCSTR lpFormat, LPSTR lpDateStr, int cchDate);
LSTATUS WINAPI RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LSTATUS WINAPI RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LSTATUS WINAPI RegSetValueExA(HKEY, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData);
LSTATUS WINAPI RegCloseKey(HKEY hKey);
int WINAPI MulDiv(int nNumber, int nNumerator, int nDenominator);
LSTATUS WINAPI RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);
DWORD WINAPI GetModuleFileNameA(HMODULE hModule, LPSTR lpFileName, DWORD nSize);
BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount);
BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
BOOL WINAPI HeapDestroy(HANDLE hHeap);
BOOL WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
HINSTANCE WINAPI ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
int WINAPI GetTimeFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, int cchTime);
BOOL WINAPI SystemTimeToFileTime(const SYSTEMTIME *lpSystemTime, LPFILETIME lpFileTime);
LONG WINAPI CompareFileTime(const FILETIME *lpFileTime1, const FILETIME *lpFileTime2);
HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpSecurityAttributes, BOOL bInitialOwner, LPCSTR lpName);
BOOL WINAPI ReleaseMutex(HANDLE hMutex);
BOOL WINAPI SetEvent(HANDLE hEvent);
DWORD WINAPI WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
char *WINAPI inet_ntoa(struct in_addr in);
int WINAPI WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar);

LONG InterlockedExchange(volatile LONG *Target, LONG Value);
LONG InterlockedDecrement(volatile LONG *Addend);
LONG InterlockedIncrement(volatile LONG *Addend);
int WINAPI MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
int WINAPI WSAStartup(WORD wVersionRequested, struct WSAData *lpWSAData);
int WINAPI WSACleanup();
int WINAPI closesocket(SOCKET s);
int WINAPI ioctlsocket(SOCKET s, long cmd, unsigned long *argp);
int WINAPI WSAGetLastError();
SOCKET WINAPI socket(int domain, int type, int protocol);
int WINAPI setsockopt(SOCKET s, int level, int opt, const void *value, unsigned int len);
int WINAPI bind(int sockfd, const struct sockaddr *addr, unsigned int addrlen);
int WINAPI recvfrom(int sockfd, void *buffer, unsigned int length, int flags, struct sockaddr *addr, unsigned int *addrlen);
int WINAPI sendto(int sockfd, void *buffer, unsigned int length, int flags, const struct sockaddr *addr, unsigned int addrlen);

unsigned int _control87(unsigned int new_, unsigned int mask);
unsigned int _controlfp(unsigned int new_, unsigned int mask);
uintptr_t _beginthread(void( __cdecl *start_address )( void * ), unsigned int stack_size, void *arglist);
char *_strrev(char *str);
char *_itoa(int val, char *s, int radix);
wchar_t *_itow(int val, wchar_t *s, int radix);
void _makepath(char *path, const char *drive, const char *dir, const char *fname, const char *ext);
void _splitpath(const char *path, char *drive, char *dir, char *fname, char *ext);
char *_getcwd(char *buffer, int maxlen);
int _open(const char *filename, int oflag, ...);
int _chmod(const char *filename, int mode);
int _access(const char *filename, int mode);
int _stat(const char *path, struct _stat *buffer);
int _mkdir(const char *path);
int _unlink(const char *filename);
char *_getcwd(char *buffer, int maxlen);
FILE *fopen(const char *path, const char *mode);
char *fgets(char *str, int size, FILE *stream);

static inline unsigned int _rotl(unsigned int value, int shift)
{
    unsigned int c = shift & 31;
    if (c == 0)
        return value;
    return (value << c) | (value >> (32 - c));
}
static inline BOOL WINAPI CopyRect(LPRECT lprcDst, const RECT *lprcSrc)
{
    *lprcDst = *lprcSrc;
    return TRUE;
}
static inline BOOL WINAPI SetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom)
{
    lprc->left = xLeft;
    lprc->top = yTop;
    lprc->right = xRight;
    lprc->bottom = yBottom;
    return TRUE;
}
static inline BOOL WINAPI IsRectEmpty(const RECT *lprc)
{
    return lprc->right <= lprc->left || lprc->bottom <= lprc->top;
}


#ifdef __cplusplus
}
#endif

#endif
