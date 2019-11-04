#include "string.h"

int __cdecl nox_vsnwprintf(wchar_t *buffer, size_t count, const wchar_t *format, va_list ap)
{
    int i = 0, j, out = 0;
    wchar_t ch;

#define EMIT(c) do { if (buffer && out < count) buffer[out++] = c; else out++; } while (0)

    if (count == 0)
        buffer = NULL;

    while ((ch = format[i++]) != 0)
    {
        char flag = 0;
        int width = -1, precision = -1;

        if (ch != '%')
        {
            EMIT(ch);
            continue;
        }

        ch = format[i++];
        switch (ch)
        {
        case '+':
        case '-':
        case '0':
            flag = ch;
            ch = format[i++];
            break;
        }

        while (ch >= '0' && ch <= '9')
        {
            if (width < 0) width = 0;
            width = width * 10 + ch - '0';
            ch = format[i++];
        }

        if (ch == '.')
        {
            ch = format[i++];
            precision = 0;
            while (ch >= '0' && ch <= '9')
            {
                precision = precision * 10 + ch - '0';
                ch = format[i++];
            }
        }

        switch (ch)
        {
        case 'c':
            {
                wchar_t c = va_arg(ap, wchar_t);
                EMIT(c);
            }
            break;
        case 's':
            {
                static const wchar_t null[] = { '(', 'n', 'u', 'l', 'l', ')', 0 };
                const wchar_t *pwch = va_arg(ap, const wchar_t *);
                if (pwch == NULL) pwch = null;
                for (j = 0; pwch[j]; j++)
                    EMIT(pwch[j]);
            }
            break;
        case 'S':
            {
                const char *pcch = va_arg(ap, const char *);
                if (pcch == NULL) pcch = "(null)";
                for (j = 0; pcch[j]; j++)
                    EMIT(pcch[j]);
            }
            break;
        case 'd':
        case 'i':
            {
                char tmp[32];
                int len;

                len = strlen(_itoa(va_arg(ap, int), tmp, 10));

                for (j = 0; j < width - (precision > 0 ? precision : len); j++)
                {
                    if (flag == '0') EMIT('0');
                    else EMIT(' ');
                }

                for (j = 0; j < precision - len; j++)
                    EMIT('0');

                for (j = 0; j < len; j++)
                    EMIT(tmp[j]);
            }
            break;
        case 'X':
        case 'x':
        case 'o':
        case 'u':
            {
                char tmp[32];
                int len;

                len = strlen(_itoa(va_arg(ap, unsigned int), tmp, ch == 'u' ? 10 : ch == 'o' ? 8 : 16));
                for (j = 0; j < width - (precision > 0 ? precision : len); j++)
                {
                    if (flag == '0') EMIT('0');
                    else EMIT(' ');
                }

                for (j = 0; j < precision - len; j++)
                    EMIT('0');

                for (j = 0; j < len; j++)
                    EMIT(ch == 'X' ? toupper(tmp[j]) : tmp[j]);
            }
            break;
        case '%':
            EMIT('%');
            break;
        default:
            dprintf("Unhandled format character: '%c'", ch);
            DebugBreak();
            break;
        }
    }

    EMIT(0);
    return out - 1;
#undef EMIT
}

int __cdecl nox_vsnprintf(char *buffer, size_t count, const char *format, va_list ap)
{
    
    int i = 0, j, out = 0;
    char ch;

#define EMIT(c) do { if (buffer && out < count) buffer[out++] = c; else out++; } while (0)

    if (count == 0)
        buffer = NULL;

    while ((ch = format[i++]) != 0)
    {
        char flag = 0;
        int width = -1, precision = -1;

        if (ch != '%')
        {
            EMIT(ch);
            continue;
        }

        ch = format[i++];
        switch (ch)
        {
        case '+':
        case '-':
        case '0':
            flag = ch;
            ch = format[i++];
            break;
        }

        while (ch >= '0' && ch <= '9')
        {
            if (width < 0) width = 0;
            width = width * 10 + ch - '0';
            ch = format[i++];
        }

        if (ch == '.')
        {
            ch = format[i++];
            precision = 0;
            while (ch >= '0' && ch <= '9')
            {
                precision = precision * 10 + ch - '0';
                ch = format[i++];
            }
        }

        switch (ch)
        {
        case 'c':
            {
                char c = va_arg(ap, char);
                EMIT(c);
            }
            break;
        case 's':
            {
                const char *pcch = va_arg(ap, const char *);
                if (pcch == NULL) pcch = "(null)";
                for (j = 0; pcch[j]; j++)
                    EMIT(pcch[j]);
            }
            break;
        case 'S':
            {
                static const wchar_t null[] = { '(', 'n', 'u', 'l', 'l', ')', 0 };
                const wchar_t *pwch = va_arg(ap, const wchar_t *);
                if (pwch == NULL) pwch = null;
                for (j = 0; pwch[j]; j++)
                    EMIT(pwch[j] < 0x80 ? pwch[j] : 0x7f);
            }
            break;
        case 'd':
        case 'i':
            {
                char tmp[32];
                int len;

                len = strlen(_itoa(va_arg(ap, int), tmp, 10));

                for (j = 0; j < width - (precision > 0 ? precision : len); j++)
                {
                    if (flag == '0') EMIT('0');
                    else EMIT(' ');
                }

                for (j = 0; j < precision - len; j++)
                    EMIT('0');

                for (j = 0; j < len; j++)
                    EMIT(tmp[j]);
            }
            break;
        case 'X':
        case 'x':
        case 'o':
        case 'u':
            {
                char tmp[32];
                int len;

                len = strlen(_itoa(va_arg(ap, unsigned int), tmp, ch == 'u' ? 10 : ch == 'o' ? 8 : 16));
                for (j = 0; j < width - (precision > 0 ? precision : len); j++)
                {
                    if (flag == '0') EMIT('0');
                    else EMIT(' ');
                }

                for (j = 0; j < precision - len; j++)
                    EMIT('0');

                for (j = 0; j < len; j++)
                    EMIT(ch == 'X' ? toupper(tmp[j]) : tmp[j]);
            }
            break;
        case '%':
            EMIT('%');
            break;
        default:
            dprintf("Unhandled format character: '%c'", ch);
            DebugBreak();
            break;
        }
    }

    EMIT(0);
    //puts("Printing: ");
    //puts(buffer);

    return out - 1;
#undef EMIT
}

int nox_vsprintf(char *str, const char *format, va_list ap)
{
    return nox_vsnprintf(str, 0x7fffffff, format, ap);
}

int nox_snprintf(char *str, size_t size, const char *format, ...)
{
    int ret;
    va_list ap;
    va_start(ap, format);
    ret = nox_vsnprintf(str, size, format, ap);
    va_end(ap);
    return ret;
}

int nox_sprintf(char *str, const char *format, ...)
{
    int ret;
    va_list ap;
    va_start(ap, format);
    ret = nox_vsprintf(str, format, ap);
    va_end(ap);
    return ret;
}

wchar_t *nox_wcscat(wchar_t *dest, const wchar_t *src)
{
    wchar_t *ret = dest;

    while (*dest)
        dest++;

    while (*src)
        *dest++ = *src++;
    *dest = 0;

    return ret;
}

wchar_t *nox_wcschr(wchar_t *nox_wcs, wchar_t wc)
{
    size_t result;
    for (result = 0; nox_wcs[result]; result++)
        if (nox_wcs[result] == wc)
            return &nox_wcs[result];
    return NULL;
}

int nox_wcscmp(const wchar_t *s1, const wchar_t *s2)
{
    size_t result;
    for (result = 0; s1[result] && s1[result] == s2[result]; result++) ;
    return s1[result] - s2[result];
}

wchar_t *nox_wcscpy(wchar_t *dest, const wchar_t *src)
{
    size_t result;
    for (result = 0; src[result]; result++)
        dest[result] = src[result];
    dest[result] = 0;
    return dest;
}

size_t nox_wcslen(const wchar_t *nox_wcs)
{
    size_t result;
    for (result = 0; nox_wcs[result]; result++) ;
    return result;
}

wchar_t *nox_wcsncpy(wchar_t *dest, const wchar_t *src, size_t n)
{
    size_t result;
    for (result = 0; src[result] && result < n; result++)
        dest[result] = src[result];
    while (result < n)
        dest[result++] = 0;
    return dest;
}

size_t nox_wcsspn(const wchar_t *nox_wcs, const wchar_t *accept)
{
    size_t i;

    for (i = 0; nox_wcs[i]; i++)
        if (!nox_wcschr(accept, nox_wcs[i]))
            break;

    return i;
}

wchar_t *nox_wcsstr(wchar_t *haystack, const wchar_t *needle)
{
    size_t i, len = nox_wcslen(needle);

    for (i = 0; haystack[i]; i++)
    {
        if (memcmp(&haystack[i], needle, len * sizeof(wchar_t)) == 0)
            return &haystack[i];
    }

    return NULL;
}

wchar_t *__cdecl nox_wcstok(wchar_t *str, const wchar_t *delim)
{
    static wchar_t *next;
    size_t i;

    if (str == NULL)
        str = next;
    if (str == NULL)
        return NULL;

    // skip deliminators
    while (*str)
    {
        if (!nox_wcschr(delim, *str))
            break;
        str++;
    }

    if (!*str)
    {
        next = NULL;
        return NULL;
    }

    // lookup for next delim
    for (i = 0; str[i]; i++)
    {
        if (nox_wcschr(delim, str[i]))
        {
            str[i] = 0;
            next = &str[i + 1];
            return str;
        }
    }

    next = &str[i];
    return str;
}

int _nox_wcsicmp(const wchar_t *string1, const wchar_t *string2)
{
    size_t i;

    for (i = 0; string1[i] && towlower(string1[i]) == towlower(string2[i]); i++) ;

    return towlower(string1[i]) - towlower(string2[i]);
}

long nox_wcstol(const wchar_t *nptr, wchar_t **endptr, int base)
{
    long result;
    size_t i, len = nox_wcslen(nptr);
    char *tmp, *ptr;

	tmp = malloc(len + 1);

    for (i = 0; i < len; i++)
        tmp[i] = nptr[i] < 0x80 ? nptr[i] : 0x7f;
    tmp[i] = 0;

    result = strtol(tmp, &ptr, base);
    
    if (endptr)
        *endptr = &nptr[ptr - tmp];
	
	free(tmp);
	return result;
}

int WINAPIV nox_wsprintfA(LPSTR lpBuffer, LPCSTR lpFmt, ...)
{
    DebugBreak();
}

