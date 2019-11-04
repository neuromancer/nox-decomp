#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "proto.h"

#ifdef USE_SDL
SDL_Window *g_window;
#else
WNDCLASSEXA g_wnd_class;
HWND g_hwnd;
#endif
DWORD dword_974854;
int g_fullscreen;

const char *g_argv[21];
unsigned int g_argc;

//----- (00401C70) --------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	char *v4; // edi
	int v5; // eax
	int v7; // esi
	int v10; // eax
	HWND v11; // esi
	HWND v13; // eax
	int v14; // eax

	init_data();

	g_argv[0] = "nox.exe";
	g_argc = 1;

	sub_43BEF0(0, 0, 0);

	for (v4 = strtok(lpCmdLine, " \t"); v4; v4 = strtok(0, " \t"))
	{
		if (!strcmp("-window", v4))
		{
			*(_DWORD *)&byte_587000[80848] = 0;
			*(_DWORD *)&byte_5D4594[805860] = 0;
		}
		else if (!strcmp("-swindow", v4))
		{
			*(_DWORD *)&byte_587000[80848] = 0;
			*(_DWORD *)&byte_5D4594[805860] = 1;
		}
		else if (!strcmp("-minimize", v4))
		{
			*(_DWORD *)&byte_5D4594[805864] = 1;
		}
		else
		{
			g_argv[g_argc++] = v4;
		}
	}
	g_argv[g_argc] = NULL;
	v7 = 0;
	v10 = 0;
	while (v7 < g_argc)
	{
		if (!_strcmpi(g_argv[v7++], "-serveronly"))
		{
			v10 = 1;
			break;
		}
	}
#ifdef USE_SDL
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
	g_window = SDL_CreateWindow("Nox Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, *(int *)&byte_5D4594[3805496], *(int *)&byte_5D4594[3807120], SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

#ifdef __EMSCRIPTEN__
    if (EM_ASM_INT(return isMobile()))
    {
        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
        SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
        SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
        SDL_EventState(SDL_MOUSEWHEEL, SDL_IGNORE);
    }
    else
    {
        SDL_EventState(SDL_FINGERDOWN, SDL_IGNORE);
        SDL_EventState(SDL_FINGERUP, SDL_IGNORE);
        SDL_EventState(SDL_FINGERMOTION, SDL_IGNORE);
    }
#endif

	sub_401070(g_argc, g_argv);
#else
	if (v10 || !(v11 = FindWindowA("Nox Game Window", 0)))
	{
		*(_DWORD *)&byte_5D4594[823784] = hInstance;
		*(_DWORD *)&byte_5D4594[823788] = nShowCmd;

		g_wnd_class.cbSize = 48;
		g_wnd_class.style = 4099;
		g_wnd_class.lpfnWndProc = sub_444FF0;
		g_wnd_class.cbClsExtra = 0;
		g_wnd_class.cbWndExtra = 0;
		g_wnd_class.hInstance = hInstance;
		g_wnd_class.hIcon = LoadIconA(hInstance, (LPCSTR)0x65);
		g_wnd_class.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
		g_wnd_class.hbrBackground = (HBRUSH)GetStockObject(4);
		g_wnd_class.lpszMenuName = 0;
		g_wnd_class.lpszClassName = "Nox Game Window";
		g_wnd_class.hIconSm = 0;

		RegisterClassExA(&g_wnd_class);
		v13 = CreateWindowExA(0x40000u, "Nox Game Window", "NOX", 0x80000000, 0, 0, *(int *)&byte_5D4594[3805496], *(int *)&byte_5D4594[3807120], 0, 0, hInstance, 0);
		if (!v13)
			return 0;
		g_hwnd = v13;

		sub_401070(g_argc, g_argv);
		if (byte_5D4594[2650637] & 0x10)
			sub_413E30(/* "Memory dump after GameLoop() :" */);
		*(_DWORD *)&byte_5D4594[823800] = 1;
		sub_4453A0();
		DestroyWindow(g_hwnd);
		sub_416B00();
		UnregisterClassA(g_wnd_class.lpszClassName, hInstance);
		ClipCursor(0);
	}
	else
	{
		SetForegroundWindow(v11);
		ShowWindow(v11, SW_RESTORE);
	}
#endif
	return 1;
}

//----- (00401FD0) --------------------------------------------------------
HWND sub_401FD0()
{
#ifdef USE_SDL
	return (HWND)g_window;
#else
	return g_hwnd;
#endif
}

//----- (00401FE0) --------------------------------------------------------
void __cdecl sub_401FE0(LPCSTR lpString)
{
#ifdef USE_SDL
	if (lpString)
		SDL_SetWindowTitle(g_window, lpString);
#else
	if (lpString)
		SetWindowTextA(g_hwnd, lpString);
#endif
}

//----- (0047D8A0) --------------------------------------------------------
void sub_47D8A0()
{
#ifdef USE_SDL
	SDL_RestoreWindow(g_window);
#else
	ShowWindow(sub_401FD0(), SW_RESTORE);
#endif
}

#ifdef USE_SDL
void process_keyboard_event(const SDL_KeyboardEvent *event);
void process_mouse_event(const SDL_MouseButtonEvent *event);
void process_motion_event(const SDL_MouseMotionEvent *event);
void process_wheel_event(const SDL_MouseWheelEvent *event);
void process_touch_event(const SDL_TouchFingerEvent *event);
void process_textediting_event(const SDL_TextEditingEvent *event);
void process_textinput_event(const SDL_TextInputEvent *event);

void process_event(const SDL_Event *event)
{
	switch (event->type)
	{
    case SDL_TEXTEDITING:
        process_textediting_event(&event->edit);
        break;
    case SDL_TEXTINPUT:
        process_textinput_event(&event->text);
        break;
    case SDL_KEYDOWN:
    case SDL_KEYUP:
        process_keyboard_event(&event->key);
        break;
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
        process_mouse_event(&event->button);
        break;
    case SDL_MOUSEMOTION:
        process_motion_event(&event->motion);
        break;
    case SDL_MOUSEWHEEL:
        process_wheel_event(&event->wheel);
        break;
#ifdef __EMSCRIPTEN__
    case SDL_FINGERMOTION:
    case SDL_FINGERDOWN:
    case SDL_FINGERUP:
        process_touch_event(&event->tfinger);
        break;
#endif
	default:
		break;
	}
}
#else
//----- (00444FF0) --------------------------------------------------------
int __stdcall sub_444FF0(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LPARAM v4; // ebx
	WPARAM v5; // esi
	UINT v6; // edi
	int result; // eax
	WPARAM v8; // esi

	v4 = lParam;
	v5 = wParam;
	v6 = Msg;
	if (Msg > 0x102)
	{
		if (Msg > 0x3B9)
		{
			if (Msg == 1040)
			{
                // character from IME
				v8 = wParam;
				sub_488BD0(wParam);
				return DefWindowProcA(hWnd, 0x410u, v8, v4);
			}
			if (Msg == 3024)
			{
				sub_414690((unsigned int *)wParam, (void(__stdcall *)(char *))lParam);
				if (sub_414800())
				{
				LABEL_41:
					PostQuitMessage(0);
					sub_43DDD0(0);
					sub_43DE60();
					return DefWindowProcA(hWnd, v6, v5, v4);
				}
			}
			return DefWindowProcA(hWnd, v6, v5, v4);
		}
		switch (Msg)
		{
		case 0x3B9u:
			sub_413870(wParam);
			return 1;
		case 0x201u:
			if (*(_DWORD *)&byte_5D4594[823776])
				sub_4B0610(0);
			break;
		case 0x30Fu:
			goto LABEL_34;
		case 0x311u:
			v5 = wParam;
			if ((HWND)wParam == hWnd)
				return DefWindowProcA(hWnd, v6, v5, v4);
		LABEL_34:
			sub_4348C0();
			return 1;
		}
	LABEL_23:
		v5 = wParam;
		return DefWindowProcA(hWnd, v6, v5, v4);
	}
	if (Msg == WM_CHAR)
	{
		v5 = wParam;
		Msg = wParam;
		wParam = 0;
		if (MultiByteToWideChar(0, 0, (LPCSTR)&Msg, -1, (LPWSTR)&wParam, 2) > 0)
		{
			sub_488BD0(wParam);
			return DefWindowProcA(hWnd, 0x102u, v5, v4);
		}
		return DefWindowProcA(hWnd, v6, v5, v4);
	}
	switch (Msg)
	{
	case WM_DESTROY:
		goto LABEL_41;
	case WM_ACTIVATE:
		v5 = (_WORD)wParam == 1 || (_WORD)wParam == 2;
		goto LABEL_13;
	case WM_SETFOCUS:
		if (*(_DWORD *)&byte_5D4594[823776])
			sub_48A820(0);
		goto LABEL_23;
	case WM_ACTIVATEAPP:
	LABEL_13:
		*(_DWORD *)&byte_5D4594[823792] = v5;
		if (v5)
		{
			if (*(_DWORD *)&byte_5D4594[823776])
			{
				if (sub_48A2A0())
					dword_974854 = 0;
			}
			sub_42ED20();
			result = DefWindowProcA(hWnd, v6, v5, v4);
		}
		else
		{
			if (*(_DWORD *)&byte_5D4594[823776])
				sub_48A9C0(1);
			sub_42ED70();
			result = DefWindowProcA(hWnd, v6, 0, v4);
		}
		return result;
	case WM_SETCURSOR:
		SetCursor(0);
		return 1;
	case WM_KEYDOWN:
		if (!*(_DWORD *)&byte_5D4594[823776])
			goto LABEL_23;
		v5 = wParam;
		if (wParam == 27)
		{
			sub_4B0610(1);
			return DefWindowProcA(hWnd, v6, 0x1Bu, v4);
		}
		sub_4B0610(0);
		if (v5 != 19)
			return DefWindowProcA(hWnd, v6, v5, v4);
		sub_48A9C0(0);
		result = DefWindowProcA(hWnd, v6, 0x13u, v4);
		break;
	default:
		return DefWindowProcA(hWnd, v6, v5, v4);
	}
	return result;
}
#endif

//----- (004453A0) --------------------------------------------------------
int sub_4453A0()
{
#ifdef USE_SDL
	SDL_Event event;
	while (SDL_PollEvent(&event))
		process_event(&event);
	return 0;
#else
	struct tagMSG Msg; // [esp+4h] [ebp-1Ch]

	while (PeekMessageA(&Msg, 0, 0, 0, 0))
	{
		if (!GetMessageA(&Msg, 0, 0, 0))
			break;
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
	}
	if (!*(_DWORD *)&byte_5D4594[823800])
		return 0;
	PostMessageA(*(HWND *)&byte_5D4594[823796], WM_CLOSE, 0, 0);
	return 1;
#endif
}

//----- (004147E0) --------------------------------------------------------
BOOL __cdecl sub_4147E0(HWND hWnd)
{
#ifdef USE_SDL
#else
	// Trigger expiration time check.
	return PostMessageA(hWnd, 3024u, (WPARAM)&byte_5D4594[338464], *(LPARAM *)&byte_587000[32580]);
#endif
}

//----- (004516C0) --------------------------------------------------------
void sub_4516C0(wchar_t *a1, ...)
{
	wchar_t *v1; // eax
	HWND v2; // eax
	wchar_t *v3; // [esp-8h] [ebp-8h]
	va_list va; // [esp+8h] [ebp+8h]

	va_start(va, a1);
	if (!*(_DWORD *)&byte_5D4594[839880])
		sub_451630();
	sub_451610();
	v1 = sub_40F1D0("FatalErrorHeader", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Console.c", 314);
	nox_swprintf((wchar_t *)&byte_5D4594[833752], v1);
	nox_vswprintf((wchar_t *)&byte_5D4594[833778], a1, va);
	fprintf(*(FILE **)&byte_5D4594[839880], "%S", &byte_5D4594[833752]);
	fflush(*(FILE **)&byte_5D4594[839880]);
	v3 = sub_40F1D0("FatalError", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Console.c", 324);
	v2 = sub_401FD0();
	nullsub_4(v2, &byte_5D4594[833752], v3, 0);
	fprintf(*(FILE **)&byte_5D4594[839880], "exiting..\n");
	fclose(*(FILE **)&byte_5D4594[839880]);
	if (*(_DWORD *)&byte_5D4594[823776])
		sub_430EF0();
	sub_4453A0();
	sub_4453A0();
	exit(0);
}
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00416A10) --------------------------------------------------------
int sub_416A10()
{
	HWND v0; // esi
	int result; // eax
	HWND v2; // eax

#ifdef USE_SDL
	return 1;
#else
	*(_DWORD *)&byte_5D4594[371712] = CreateMutexA(0, 0, "843ED62B-354B-11d3-8F70-0060089C05B1");
	if (GetLastError() == 183)
	{
		if (*(_DWORD *)&byte_5D4594[371712])
		{
			CloseHandle(*(HANDLE *)&byte_5D4594[371712]);
			*(_DWORD *)&byte_5D4594[371712] = 0;
		}
		v0 = FindWindowA("Nox Game Window", 0);
		if (v0 || (v0 = FindWindowA("NOX Setup", 0)) != 0)
		{
			if (IsIconic(v0))
				ShowWindow(v0, 9);
			SetForegroundWindow(v0);
		}
		result = 0;
	}
	else
	{
		*(_DWORD *)&byte_5D4594[371708] = OpenMutexA(0x1F0001u, 0, "01AF9993-3492-11d3-8F6F-0060089C05B1");
		if (*(_DWORD *)&byte_5D4594[371708])
		{
			v2 = FindWindowA("NOX Autorun", 0);
			if (v2)
				SetForegroundWindow(v2);
			if (*(_DWORD *)&byte_5D4594[371708])
			{
				CloseHandle(*(HANDLE *)&byte_5D4594[371708]);
				*(_DWORD *)&byte_5D4594[371708] = 0;
			}
			if (*(_DWORD *)&byte_5D4594[371712])
			{
				CloseHandle(*(HANDLE *)&byte_5D4594[371712]);
				*(_DWORD *)&byte_5D4594[371712] = 0;
			}
			result = 0;
		}
		else
		{
			result = 1;
		}
	}
	return result;
#endif
}

//----- (00416B00) --------------------------------------------------------
HANDLE sub_416B00()
{
	HANDLE result; // eax

	result = *(HANDLE *)&byte_5D4594[371712];
	if (*(_DWORD *)&byte_5D4594[371712])
	{
		result = (HANDLE)CloseHandle(*(HANDLE *)&byte_5D4594[371712]);
		*(_DWORD *)&byte_5D4594[371712] = 0;
	}
	return result;
}
