#include <cstdio>
#include <cstring>

#ifdef _WIN32
#include <windows.h>
#else
#include "windows.h"
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

extern "C" const char *progname;
const char *progname;

#if defined(__EMSCRIPTEN__)
extern "C" int main()
#elif defined(_WIN32)
int main(int argc, char *argv[])
#else
extern "C" int main(int argc, char *argv[])
#endif
{
    char cmdline[256];
    int i;

#ifdef __EMSCRIPTEN__
    EM_ASM(
        FS.syncfs(false, function (err) {});
    );

    progname = "nox.js";
    strcpy(cmdline, "nox.js -noskip -nolimit -nothread -sleep -swindow");

    if (chdir("assets"))
    {
        fprintf(stderr, "Failed to enter Nox directory.\n");
        return 1;
    }
#else
    progname = argv[0];
    strcpy(cmdline, argv[0]);
    for (i = 1; i < argc; i++)
        sprintf(cmdline + strlen(cmdline), " %s", argv[i]);
#endif

    return WinMain(NULL, NULL, cmdline, 0);
}
