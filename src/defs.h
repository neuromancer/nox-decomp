#ifndef NOX_DEFS_H
#define NOX_DEFS_H

#define DIRECTINPUT_VERSION 0x0700
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <wctype.h>

#define NO_IMM 1
#define NO_MOVIE 1
#define NO_WOLAPI 1

#define USE_SDL 1
#include <SDL2/SDL.h>

#ifdef __EMSCRIPTEN__
#define wchar_t int16_t
#endif

#ifdef _WIN32
#include <windows.h>
#include <mmreg.h>
#else
#pragma GCC poison fgetwln fgetws fputwc fputws fwprintf fwscanf mbrtowc mbsnrtowcs mbsrtowcs putwc putwchar swprintf swscanf vfwprintf vfwscanf vswprintf vswscanf vwprintf vwscanf wcrtomb wcscat wcschr wcscmp wcscoll wcscpy wcscspn wcsftime wcsftime wcslcat wcslcpy wcslen wcsncat wcsncmp wcsncpy wcsnrtombs wcspbrk wcsrchr wcsrtombs wcsspn wcsstr wcstod wcstof wcstok wcstol wcstold wcstoll wcstoul wcstoull wcswidth wcsxfrm wcwidth wmemchr wmemcmp wmemcpy wmemmove wmemset wprintf wscanf
#include "windows.h"
#endif
#include "compat_mss.h"
#include "string.h"

typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned __int64 _QWORD;
typedef int bool;
 
#if !defined(__MMINTRIN_H) && !defined(_MMINTRIN_H_INCLUDED)
typedef struct __m64 __m64;
#endif

#undef LOBYTE
#undef HIBYTE
#define LOBYTE(x) (((_BYTE*)(&x))[0])
#define SLOBYTE(x) (((signed char*)(&x))[0])
#define BYTE1(x) (((_BYTE*)(&x))[1])
#define SBYTE1(x) (((signed char*)(&x))[1])
#define BYTE2(x) (((_BYTE*)(&x))[2])
#define HIBYTE(x) (((_BYTE*)(&x))[sizeof(x)-1])
#define BYTE4(x) (((_BYTE*)(&x))[4])

#undef LOWORD
#undef HIWORD
#define LOWORD(x) (((_WORD*)(&x))[0])
#define SLOWORD(x) (((short*)(&x))[0])
#define HIWORD(x) (((_WORD*)(&x))[1])
#define SHIWORD(x) (((short*)(&x))[1])
#define WORD2(x) (((_WORD*)(&x))[2])
#define SWORD2(x) (((short*)(&x))[2])

#undef LODWORD
#undef HIDWORD
#define LODWORD(x) (((_DWORD*)(&x))[0])
#define SLODWORD(x) (((int*)(&x))[0])
#define HIDWORD(x) (((_DWORD*)(&x))[1])
#define SHIDWORD(x) (((int*)(&x))[1])

#define __PAIR64__(x,y) ((((_QWORD)(x)) << 32) | ((_DWORD)(y)))
#define __SPAIR64__(x,y) ((__int64)((((_QWORD)(x)) << 32) | ((_DWORD)(y))))

static int __OFSUB__(int x, int y)
{
	DebugBreak();
	return 0;
}
static int __CFSHR__(int x, int y)
{
	DebugBreak();
	return 0;
}
static int __CFSHL__(int x, int y)
{
	DebugBreak();
	return 0;
}
static int __CFADD__(int x, int y)
{
	DebugBreak();
	return 0;
}
static int __OFADD__(int x, int y)
{
	DebugBreak();
	return 0;
}

// saturating 8-bit addition
static _BYTE SADD8(_BYTE x, _BYTE y)
{
	unsigned int z = x + y;
	return z > 0xFF ? 0xFF : (_BYTE)z;
}

#define abs32 abs
#define qmemcpy memcpy

static void memset32(_DWORD *x, _DWORD y, size_t z)
{
	while (z--) *x++ = y;
}

#define __ROL4__ _rotl

#if !defined(__clang__) && !defined(_MSC_VER)
static _QWORD __rdtsc()
{
#ifdef __GNUC__
	unsigned int low, high;
	asm ("rdtsc" : "=a" (low), "=d" (high));
	return ((_QWORD)high << 32) | low;
#else
	_asm rdtsc;
#endif
}
#endif

typedef struct std___Lockit
{
	_DWORD x;
} std___Lockit;

static void std___Lockit___Lockit(struct std___Lockit* l)
{
	return;
}

static void std___Lockit__destructor_Lockit(struct std___Lockit* l)
{
	return;
}

static void std___Xran()
{
	DebugBreak();
}

static void std___Xlen()
{
	DebugBreak();
}

static void *operator_new(size_t x)
{
	return malloc(x);
}

static void operator_delete(void *x)
{
	free(x);
}

static _WORD __ROL2__(_WORD x, int shift)
{
	if (shift == 0) return x;
	if (shift == 16) return x;
	return (_WORD)((x << shift) | (x >> (16 - shift)));
}

static float COERCE_FLOAT(_DWORD x)
{
	return *(float *)&x;
}

static _DWORD COERCE_INT(float x)
{
	return *(_DWORD *)&x;
}

typedef struct struc_13
{
  char field_0[80];
  int field_50;
} struc_13;

/* 288 */
typedef struct struc_14
{
  char field_0[4828];
} struc_14;

/* 289 */
typedef struct struc_15
{
  char field_0[80];
} struc_15;

/* 290 */
typedef struct struc_16
{
  char field_0[24];
} struc_16;

/* 291 */
typedef struct struc_17
{
  int field_0;
  int field_4;
  int field_8;
  int field_C;
} struc_17;

/* 292 */
typedef struct struc_18
{
  char field_0[2048];
  int field_800;
} struc_18;

/* 293 */
typedef struct struc_19
{
  int field_0[35];
} struc_19;

/* 294 */
typedef struct struc_20
{
  char field_0[80];
} struc_20;

/* 295 */
typedef struct struc_21
{
  char field_0[28];
} struc_21;

/* 296 */
typedef struct struc_22
{
  int field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
} struc_22;

/* 297 */
typedef struct struc_23
{
  char field_0[200];
} struc_23;

/* 298 */
typedef struct struc_24
{
  int field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
} struc_24;

/* 299 */
typedef struct struc_25
{
  char field_0[12332];
} struc_25;

/* 300 */
typedef struct pixel888
{
  char field_0;
  char field_1;
  char field_2;
} pixel888;

/* 301 */
typedef struct pixel8888
{
  char field_0;
  char field_1;
  char field_2;
  char field_3;
} pixel8888;

/* 302 */
typedef struct float2
{
  float field_0;
  float field_4;
} float2;

/* 303 */
typedef struct float4
{
  float field_0;
  float field_4;
  float field_8;
  float field_C;
} float4;

/* 306 */
typedef struct int2
{
  int field_0;
  int field_4;
} int2;

/* 307 */
typedef struct int4
{
  int field_0;
  int field_4;
  int field_8;
  int field_C;
} int4;

/* 308 */
typedef struct shape
{
  int field_0;
  float field_4;
  float field_8;
  float field_C;
  float field_10;
  float field_14;
  float field_18;
  float field_1C;
  float field_20;
  float field_24;
  float field_28;
  float field_2C;
  float field_30;
} shape;

typedef struct string
{
  int field_0;
  int field_4;
  int field_8;
  int field_C;
} string;

/* 310 */
typedef struct wstring
{
  int _A;
  int _Ptr;
  int _Len;
  int _Rem;
} wstring;

typedef struct struc_35
{
	HWND field_0;
	HIMC field_4;
	int field_8;
	int field_C;
	int field_10;
} struc_35;

#endif
