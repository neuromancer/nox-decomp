#ifndef NOX_STRING_H
#define NOX_STRING_H

#include "defs.h"

int _nox_wcsicmp(const wchar_t *string1, const wchar_t *string2);
int WINAPIV nox_wsprintfA(LPSTR lpBuffer, LPCSTR lpFmt, ...);
wchar_t *nox_wcscat(wchar_t *dest, const wchar_t *src);
wchar_t *nox_wcschr(wchar_t *nox_wcs, wchar_t wc);
int nox_wcscmp(const wchar_t *s1, const wchar_t *s2);
wchar_t *nox_wcscpy(wchar_t *dest, const wchar_t *src);
size_t nox_wcslen(const wchar_t *nox_wcs);
wchar_t *nox_wcsncpy(wchar_t *dest, const wchar_t *src, size_t n);
size_t nox_wcsspn(const wchar_t *nox_wcs, const wchar_t *accept);
wchar_t *nox_wcsstr(wchar_t *haystack, const wchar_t *needle);
long nox_wcstol(const wchar_t *nptr, wchar_t **endptr, int base);
wchar_t *__cdecl nox_wcstok(wchar_t *, const wchar_t *);
int __cdecl nox_vsnwprintf(wchar_t *buffer, size_t count, const wchar_t *format, va_list ap);
int __cdecl nox_vsnprintf(char *buffer, size_t count, const char *format, va_list ap);
int nox_vsprintf(char *str, const char *format, va_list ap);
int nox_snprintf(char *str, size_t size, const char *format, ...);
int nox_sprintf(char *str, const char *format, ...);

static int __cdecl nox_swprintf(wchar_t *str, const wchar_t *fmt, ...)
{
    int len;
	va_list ap;
    va_start(ap, fmt);
	len = nox_vsnwprintf(str, 0x3fffffff, fmt, ap);
    va_end(ap);
    return len;
}

static int __cdecl nox_vswprintf(wchar_t *str, const wchar_t *fmt, va_list ap)
{
	return nox_vsnwprintf(str, 0x3fffffff, fmt, ap);
}

#define dprintf _dprintf
static void dprintf(const char *fmt, ...)
{
	char buf[1024];
	int len;
	va_list ap;
    va_start(ap, fmt);
	len = nox_vsnprintf(buf, sizeof(buf) - 1, fmt, ap);
	buf[len] = '\n';
	buf[len + 1] = 0;
	OutputDebugStringA(buf);
    va_end(ap);
}

static void dhexdump(const BYTE *data, unsigned int len)
{
	char tmp[4];
	unsigned int i;

	for (i = 0; i < len; i++)
	{
		sprintf(tmp, "%02X ", data[i]);
		OutputDebugStringA(tmp);
	}
	OutputDebugStringA("\n");
}

#endif
