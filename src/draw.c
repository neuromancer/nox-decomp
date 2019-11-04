// This must come before the SDL includes.
#ifdef _WIN32
#include <windows.h>
#include <GL/glew.h>
#else
#define GL_GLEXT_PROTOTYPES
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <GLUT/glut.h>
#include <SDL2/SDL_opengl.h>
#else
#include <GL/gl.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_opengl_glext.h>
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

#include "proto.h"

#ifdef USE_SDL
enum {
    DDSD_CAPS = 1,
    DDSD_WIDTH = 2,
    DDSD_HEIGHT = 4,
};

enum {
    DDSCAPS_OFFSCREENPLAIN = 1,
    DDSCAPS_SYSTEMMEMORY = 2,
    DDSCAPS_VIDEOMEMORY = 4,
    DDSCAPS_PRIMARYSURFACE = 8,
};

static inline void rect_to_sdl(const RECT *r, SDL_Rect *sr)
{
    sr->x = r->left;
    sr->y = r->top;
    sr->w = r->right - r->left;
    sr->h = r->bottom - r->top;
}
void sdl_present();
int sdl_unk1(int);
int create_surfaces(HWND a1, int width, int height);

void __cdecl sub_48B1B0(SDL_GLContext *a1);
void __cdecl sub_48B1D0(SDL_Surface **a1);
SDL_Surface * __cdecl sub_48A600(int a1, int a2, int a3, int a4);
int __cdecl sub_48A720(SDL_Surface *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, int *a5);
void __cdecl sub_48A670(SDL_Surface *a1);
void __cdecl sub_48A6B0(SDL_Surface *a1);

SDL_Window *dword_973FE0;
#else
void __cdecl sub_435380(LPDIRECTDRAWGAMMACONTROL *a1);
void __cdecl sub_4353A0(LPDIRECTDRAWPALETTE *a1);
LPDIRECTDRAWSURFACE __cdecl sub_48A600(int a1, int a2, int a3, int a4);
void __cdecl sub_48A670(LPDIRECTDRAWSURFACE a1);
void __cdecl sub_48A6B0(LPDIRECTDRAWSURFACE a1);
LPVOID __cdecl sub_48A6C0(LPDIRECTDRAWSURFACE a1);
int __cdecl sub_48A720(LPDIRECTDRAWSURFACE a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, int *a5);
void __cdecl sub_48A7B0(LPDIRECTDRAWSURFACE a1);
int __stdcall sub_48AE80(LPDIRECTDRAWSURFACE a1, LPDDSURFACEDESC a2, LPVOID a3);
BOOL __stdcall Callback(GUID *, LPSTR, LPSTR, LPVOID); // idb
int __cdecl sub_48B140(LPDIRECTDRAW a1, const IID *a2, int *a3);
void __cdecl sub_48B190(LPDIRECTDRAWCLIPPER *a1);
void __cdecl sub_48B1B0(LPDIRECTDRAW *a1);
void __cdecl sub_48B1D0(LPDIRECTDRAWSURFACE *a1);
int __cdecl sub_48AD40(HWND a1, int a2, int a3, int a4);
int __cdecl sub_48AED0(HWND a1, int a2, int a3);

HWND dword_973FE0;
#endif

DWORD dword_974868;
DWORD dword_973C64;

//----- (00444AC0) --------------------------------------------------------
int __cdecl sub_444AC0(HWND a1, int a2, int a3, int a4, int a5)
{
	int v5; // eax
	bool v6; // zf
	unsigned __int8 v7; // al
	int v8; // esi
	int v9; // eax
	int v10; // eax
	int result; // eax

	InitializeCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
	*(_DWORD *)&byte_5D4594[823780] = 1;
#ifdef USE_SDL
	dword_973FE0 = (SDL_Window *)a1;
#else
	dword_973FE0 = a1;
#endif
	*(_DWORD *)&byte_5D4594[3801784] = a2;
	*(_DWORD *)&byte_5D4594[3801788] = a3;
	*(_DWORD *)&byte_5D4594[3799568] = a4;
	*(_DWORD *)&byte_5D4594[3801772] = a5;
	v5 = sub_48C870(0);
	*(_DWORD *)&byte_5D4594[3799620] = v5;
	v6 = v5 == 5;
	v7 = byte_5D4594[3801772];
	if (v6)
	{
		v7 = byte_5D4594[3801772] | 0x20;
		*(_DWORD *)&byte_5D4594[3801772] |= 0x120u;
	}
	v8 = a2 & 0xFFFFFFE0;
	if (v7 & 4)
	{
		v9 = (v7 & 0x17) - 20;
		*(_DWORD *)&byte_5D4594[3801796] = 0;
		*(_DWORD *)&byte_5D4594[3801784] = a2 & 0xFFFFFFE0;
		*(_DWORD *)&byte_5D4594[3801788] = a3;
		dword_974868 = 0;
		dword_973C64 = 0;
		if (v9)
		{
			v10 = v9 - 1;
			if (v10)
			{
				if (v10 != 1)
					return 0;
				*(_DWORD *)&byte_5D4594[3801780] = 1;
				*(_DWORD *)&byte_5D4594[3801808] = 2 * v8;
				*(_DWORD *)&byte_5D4594[3801776] = v8 >> 1;
				*(_DWORD *)&byte_5D4594[3801800] = v8 >> 4;
				*(_DWORD *)&byte_5D4594[3799624] = 2;
				goto LABEL_9;
			}
			*(_DWORD *)&byte_5D4594[3801808] = 2 * v8;
			*(_DWORD *)&byte_5D4594[3801780] = 1;
			*(_DWORD *)&byte_5D4594[3801776] = v8 >> 1;
			*(_DWORD *)&byte_5D4594[3801800] = v8 >> 4;
			*(_DWORD *)&byte_5D4594[3799624] = 1;
			*(_DWORD *)&byte_5D4594[3801804] = sub_444D90();
			result = 1;
		}
		else
		{
			*(_DWORD *)&byte_5D4594[3801808] = a2 & 0xFFFFFFE0;
			*(_DWORD *)&byte_5D4594[3801780] = 0;
			*(_DWORD *)&byte_5D4594[3801776] = v8 >> 2;
			*(_DWORD *)&byte_5D4594[3801800] = v8 >> 5;
			*(_DWORD *)&byte_5D4594[3799624] = 0;
			*(_DWORD *)&byte_5D4594[3801804] = sub_444D90();
			result = 1;
		}
	}
	else
	{
		result = sub_48A040(a1, v8, a3, a4);
		if (result)
		{
		LABEL_9:
			*(_DWORD *)&byte_5D4594[3801804] = sub_444D90();
			return 1;
		}
	}
	return result;
}

#if 0
// update screen
int __cdecl sub_48B5D0(int a1, int a2)
{
	return 0;
}

// on focus
void __cdecl sub_48A820(UINT uFlags)
{
}

// on deactivate
void __cdecl sub_48A9C0(int a1)
{
}

// restore device
int sub_48A2A0()
{
	return 0;
}

// check flip status, restore device if needed
void __cdecl sub_48A220()
{
}

// flip?
void __cdecl sub_48AAF0()
{
}

// flip?
void __cdecl sub_48AB50()
{
}

// initialize flip?
int sub_48ACC0()
{
}

// blit?
int __cdecl sub_48B840(int a1)
{
}

// blit?
int __cdecl sub_48BA50(int a1)
{
}

// draws to g_cursor_surf surface
int __cdecl sub_48B3F0(int a1, int a2, int a3)
{
}

// GfxInit
int __cdecl sub_444930(HWND a1, int a2, int a3, int a4, int a5)
{
	return 1;
}

// uninit?
void sub_444C50()
{
}

// init?
int sub_486090()
{
	return 1;
}

int sub_48B1F0()
{
	return 1;
}

// init?
int sub_4AD100()
{
	return 1;
}

void sub_4AD150()
{
}

// load palette
BOOL __cdecl sub_4347F0(char *a1, int a2)
{
	return 0;
}

int sub_4348C0()
{
	return 0;
}

// set color key of g_cursor_surf
BOOL sub_48BDE0()
{
	return 1;
}

// init gamma?
int sub_4338D0()
{
	return 1;
}

// current gamma
int sub_434B00()
{
	return 0;
}

// set gamma
int __cdecl sub_434B30(int a1)
{
	return 0;
}

// apply gamma
BOOL sub_434B60()
{
	return 0;
}

int(*g_on_movie_finished)();

// queue movie
int __cdecl sub_4B0300(char *a1)
{
	return 0;
}

// show movies
int __cdecl sub_4B0340(int a1)
{
	g_on_movie_finished();
	return 0;
}

// set on movies finished
int __cdecl sub_4B0640(int(*a1)(void))
{
	g_on_movie_finished = a1;
	return 0;
}

void sub_48A290()
{
}

char sub_48A190()
{
}

int __cdecl sub_4344A0(int a1, int a2, int a3)
{
	return 0;
}

void sub_434430(int a1, int a2, int a3)
{
}

int __cdecl sub_433E40(int a1)
{
	return 0;
}

int __cdecl sub_434040(int a1)
{
	return 0;
}

int __cdecl sub_4341D0(int a1, int a2)
{
	return 0;
}

int sub_4AD170(void)
{
	return 0;
}

int __cdecl sub_433CD0(int a1, int a2, int a3)
{
	return 0;
}

void __cdecl sub_434480(int a1, int a2, int a3, int a4)
{
}

int __cdecl sub_434AA0(int a1, int a2, int a3)
{
}

void sub_4343B0(int a1, int a2, int a3)
{
}

void __cdecl sub_4340A0(int a1, int a2, int a3, int a4)
{
}

int __cdecl sub_48A040(int a1, int a2, int a3, int a4)
{
	return 0;
}

#else

#ifdef USE_SDL
int g_rotate;
int g_rotated;
Uint32 g_format;
SDL_GLContext g_ddraw;
GLuint g_texture, g_program, g_tex_coord_buffer, g_tex_coord_attr, g_gamma_uniform, g_matrix_uniform, g_sampler_uniform;
unsigned int g_tex_coord_itemsize, g_tex_coord_numitems;
float draw_gamma = 1.0;

SDL_Surface *dword_6F7C48;
SDL_Surface *g_cursor_surf;
SDL_Surface *dword_973C60;
SDL_Surface *g_backbuffer1;
SDL_Surface *g_backbufferrgb;
SDL_Surface *dword_973C88;

static void glCheckError()
{
#if 0
    GLenum error = glGetError();
    if (error)
        DebugBreak();
#endif
}
#else
GUID *g_driver_guid;
LPDIRECTDRAW g_ddraw;
LPDIRECTDRAWSURFACE dword_6F7C48;
LPDIRECTDRAWSURFACE g_cursor_surf;
LPDIRECTDRAWSURFACE dword_973C60;
LPDIRECTDRAWSURFACE g_backbuffer2;
LPDIRECTDRAWSURFACE g_frontbuffer;
LPDIRECTDRAWSURFACE g_backbuffer1;
LPDIRECTDRAWSURFACE dword_973C88;
LPDIRECTDRAWCLIPPER g_clipper;
LPDIRECTDRAWPALETTE g_ddraw_palette;
LPDIRECTDRAWGAMMACONTROL g_ddraw_gamma_control;
#endif
DWORD dword_973C70;
DWORD dword_973C7C;
DWORD g_backbuffer_count;
DWORD dword_5ACFAC;
DWORD dword_6F7B9C;
void(*dword_6F7BA0)();
DWORD dword_6F7BB0;
DWORD dword_6F7BF8;
BYTE *dword_6F7C74;
BYTE *dword_6F7C78;
extern DWORD dword_974854;
int(*dword_6F7BF0)(int);
void(*dword_6F7C10)(_DWORD, _DWORD, _DWORD);
void(*dword_6F7C40)();
void(*dword_6F7C34)();
void(*dword_975240)(_DWORD, _DWORD *, _DWORD *, _DWORD *);
int(*dword_975380)(_DWORD, _DWORD, _DWORD);
void(*dword_69A014)(_DWORD, _DWORD, _DWORD, _DWORD *);
void(*dword_714204)();

//----- (0048A040) --------------------------------------------------------
int __cdecl sub_48A040(HWND a1, int a2, int a3, int a4)
{
	int result; // eax

	g_backbuffer_count = 2;
	dword_6F7BB0 = 0;
#ifdef USE_SDL
	g_ddraw = 0;
	g_backbuffer1 = 0;
#else
	g_ddraw = 0;
	g_frontbuffer = 0;
	g_backbuffer1 = 0;
	g_clipper = 0;
#endif
	dword_973C88 = 0;
	dword_973C60 = 0;
	dword_973C70 = 0;
	dword_973C7C = 0;
	dword_974854 = 0;
	dword_6F7B9C = 1;
	dword_5ACFAC = 1;
	if (!(byte_5D4594[3801772] & 4))
	{
		sub_48AA40();
		result = sub_48B000();
		if (!result)
			return result;
#ifdef USE_SDL
        create_surfaces(a1, a2, a3);
#else
		if (byte_5D4594[3801772] & 0x10)
		{
            // windowed mode
			result = sub_48AED0(a1, a2, a3);
			if (!result)
				return result;
		}
		else
		{
            // fullscreen mode
			result = sub_48AD40(a1, a2, a3, a4);
			if (!result)
				return result;
		}
#endif
	}
	dword_6F7BB0 = 1;
	sub_48A820(1u);
	result = sub_48A3D0();
	if (result)
	{
		sub_48A7F0();
		result = 1;
	}
	return result;
}

//----- (0048A120) --------------------------------------------------------
void sub_48A120()
{
	dword_6F7BB0 = 0;
#ifndef USE_SDL
	if (g_ddraw)
		g_ddraw->lpVtbl->RestoreDisplayMode(g_ddraw);
	sub_48B190(&g_clipper);
	sub_48B1D0(&g_frontbuffer);
#endif
	sub_48B1D0(&dword_973C60);
	sub_48B1D0(&dword_973C88);
	sub_48B1D0(&g_backbuffer1);
	sub_48B1B0(&g_ddraw);
	sub_48A9C0(0);
	sub_48AA40();
}

//----- (0048A190) --------------------------------------------------------
char sub_48A190()
{
	int v0; // eax

#ifdef USE_SDL
    dword_6F7BA0 = sdl_present;

    dword_6F7B9C = 1;
    *(_DWORD *)&byte_5D4594[1193492] = g_backbuffer1->pixels;
    *(_DWORD *)&byte_5D4594[3798752] = *(_DWORD *)&byte_5D4594[1193492];
#else
	if (*(_DWORD *)&byte_5D4594[3801796] && byte_5D4594[3801772] & 0x20 && (v0 = sub_48ACC0()) != 0)
	{
		dword_6F7BA0 = sub_48AB50;
	}
	else
	{
		v0 = *(_DWORD *)&byte_5D4594[3801772];
		dword_6F7BA0 = sub_48AAF0;
		LOBYTE(v0) = byte_5D4594[3801772] & 0xDF;
		*(_DWORD *)&byte_5D4594[3801772] = v0;
	}
#endif
	return v0;
}

//----- (0048A220) --------------------------------------------------------
void __cdecl sub_48A220()
{
#ifndef USE_SDL
	HRESULT i; // eax

	if (g_ddraw && !dword_974854 && dword_973C64 && (!dword_973C70 || sub_48A2A0()))
	{
		for (i = g_frontbuffer->lpVtbl->GetFlipStatus(g_frontbuffer, 2);
			i;
			i = g_frontbuffer->lpVtbl->GetFlipStatus(g_frontbuffer, 2))
		{
			if (i == DDERR_SURFACELOST)
			{
				if (!sub_48A2A0())
					return;
			}
			else if (i == DDERR_SURFACEBUSY)
			{
				return;
			}
		}
	}
#endif
}

//----- (0048A290) --------------------------------------------------------
void sub_48A290()
{
	dword_6F7BA0();
	++dword_973C7C;
}

#ifdef USE_SDL
SDL_Surface * __cdecl sub_48A600(int width, int height, int flags, int caps)
{
    if (!(flags & DDSD_WIDTH))
        DebugBreak();
    if (!(flags & DDSD_HEIGHT))
        DebugBreak();
    return SDL_CreateRGBSurfaceWithFormat(0, width, height, 16, g_format);
// FIXME
//    return SDL_CreateRGBSurface(0, width, height, 16, 0xF800, 0x7E0, 0x1F, 0);
}

int __cdecl sub_48A720(SDL_Surface *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, int *a5)
{
    if (a2)
        *a2 = a1->w;
    if (a3)
        *a3 = a1->h;
    if (a4)
        *a4 = a1->pitch;
    if (a5)
        *a5 = a1->pixels;
    return 0;
}

void __cdecl sub_48A670(SDL_Surface *a1)
{
    SDL_LockSurface(a1);
}

void __cdecl sub_48A6B0(SDL_Surface *a1)
{
    SDL_UnlockSurface(a1);
}
#else
//----- (0048A2A0) --------------------------------------------------------
int sub_48A2A0()
{
	int v0; // esi

	if (!dword_6F7BB0 || !dword_974854)
		return 0;
	if (!(byte_5D4594[3801773] & 2))
		SetForegroundWindow(dword_973FE0);
	v0 = 0;
	if (g_frontbuffer && g_frontbuffer->lpVtbl->IsLost(g_frontbuffer))
		v0 = g_frontbuffer->lpVtbl->Restore(g_frontbuffer);
	if (dword_6F7C48 && dword_6F7C48->lpVtbl->IsLost(dword_6F7C48))
		v0 = dword_6F7C48->lpVtbl->Restore(dword_6F7C48);
	if (byte_5D4594[3801772] & 0x10)
	{
		if (v0 || g_backbuffer1 && g_backbuffer1->lpVtbl->IsLost(g_backbuffer1) && g_backbuffer1->lpVtbl->Restore(g_backbuffer1))
		{
			goto LABEL_22;
		}
		if (!g_backbuffer2 || !g_backbuffer2->lpVtbl->IsLost(g_backbuffer2))
		{
            goto LABEL_20;
		}
		v0 = g_backbuffer2->lpVtbl->Restore(g_backbuffer2);
	}
	if (!v0)
    {
LABEL_20:
        sub_48A820(1u);
        if (sub_48ACC0())
        {
            sub_48BE50(0);
            dword_973C70 = 0;
            return 1;
        }
    }
LABEL_22:
	if (!dword_973C70)
	{
		sub_48BE50(1);
		ShowWindow(dword_973FE0, SW_MINIMIZE);
		dword_973C70 = 1;
	}
	return 0;
}

//----- (0048A600) --------------------------------------------------------
LPDIRECTDRAWSURFACE __cdecl sub_48A600(int a1, int a2, int a3, int a4)
{
	LPDIRECTDRAWSURFACE result; // eax
	DDSURFACEDESC v5; // [esp+4h] [ebp-6Ch]
	LPDIRECTDRAWSURFACE surf;

	memset(&v5, 0, sizeof(v5));
	v5.dwSize = 108;
	v5.dwWidth = a1;
	v5.dwHeight = a2;
	v5.dwFlags = a3;
	v5.ddsCaps.dwCaps = a4;
	if (g_ddraw->lpVtbl->CreateSurface(g_ddraw, &v5, &surf, 0))
		surf = NULL;
	return surf;
}

//----- (0048A670) --------------------------------------------------------
void __cdecl sub_48A670(LPDIRECTDRAWSURFACE a1)
{
	DDSURFACEDESC v3; // [esp+4h] [ebp-6Ch]

	memset(&v3, 0, sizeof(v3));
	v3.dwSize = sizeof(v3);
	a1->lpVtbl->Lock(a1, 0, &v3, DDLOCK_WAIT | DDLOCK_WRITEONLY | DDLOCK_NOSYSLOCK, 0);
}

//----- (0048A6B0) --------------------------------------------------------
void __cdecl sub_48A6B0(LPDIRECTDRAWSURFACE a1)
{
	a1->lpVtbl->Unlock(a1, 0);
}

//----- (0048A6C0) --------------------------------------------------------
LPVOID __cdecl sub_48A6C0(LPDIRECTDRAWSURFACE a1)
{
	DDSURFACEDESC v3; // [esp+8h] [ebp-6Ch]

	memset(&v3, 0, sizeof(v3));
	v3.dwSize = 108;
	if (a1->lpVtbl->Lock(a1, 0, &v3, DDLOCK_WAIT, 0))
		return 0;
	a1->lpVtbl->Unlock(a1, v3.lpSurface);
	return v3.lpSurface;
}

//----- (0048A720) --------------------------------------------------------
int __cdecl sub_48A720(LPDIRECTDRAWSURFACE a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, int *a5)
{
	IDirectDrawSurfaceVtbl *v5; // eax
	int v6; // edi
	DDSURFACEDESC v8; // [esp+Ch] [ebp-6Ch]

	memset(&v8, 0, sizeof(v8));
	v8.dwSize = sizeof(v8);
	v8.dwFlags = DDSD_HEIGHT | DDSD_WIDTH | DDSD_PITCH;
	v6 = a1->lpVtbl->GetSurfaceDesc(a1, &v8);
	if (!v6)
	{
		if (a2)
			*a2 = v8.dwWidth;
		if (a3)
			*a3 = v8.dwHeight;
		if (a4)
			*a4 = v8.lPitch;
	}
	if (a5)
		*a5 = (int)sub_48A6C0(a1);
	return v6;
}

//----- (0048A7B0) --------------------------------------------------------
void __cdecl sub_48A7B0(LPDIRECTDRAWSURFACE a1)
{
	DDBLTFX v2; // [esp+0h] [ebp-64h]

	if (a1)
	{
		v2.dwSize = 100;
		v2.dwFillColor = 0;
		a1->lpVtbl->Blt(a1, 0, 0, 0, DDBLT_COLORFILL | DDBLT_WAIT, &v2);
	}
}
#endif

//----- (0048A7F0) --------------------------------------------------------
void sub_48A7F0()
{
#ifdef USE_SDL
#if 0
    SDL_SetRenderDrawColor(g_ddraw, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(g_ddraw);
    SDL_RenderPresent(g_ddraw);
#endif
#else
	sub_48A7B0(g_frontbuffer);
	sub_48A7B0(g_backbuffer1);
	sub_48A7B0(g_backbuffer2);
#endif
}

//----- (0048A820) --------------------------------------------------------
void __cdecl sub_48A820(UINT uFlags)
{
#ifdef USE_SDL
    DWORD width = *(_DWORD *)&byte_5D4594[3801784];
    DWORD height = *(_DWORD *)&byte_5D4594[3801788];

    //SDL_SetWindowSize(dword_973FE0, width, height);
    SDL_SetWindowGrab(dword_973FE0, SDL_TRUE);
#else
	HCURSOR result; // eax
	int v2; // ebp
	int v3; // eax
	int v4; // esi
	int v5; // edi
	int v6; // ebx
	int v7; // ecx
	int v8; // eax
	DWORD v9; // eax
	HMENU v10; // [esp-14h] [ebp-24h]
	RECT rc; // [esp+0h] [ebp-10h]
	UINT uFlagsa; // [esp+14h] [ebp+4h]

	if (byte_5D4594[3801773] & 2 || (result = (HCURSOR)uFlags) != 0)
	{
		result = (HCURSOR)IsWindow(dword_973FE0);
		if (result)
		{
			v2 = GetSystemMetrics(0);
			v3 = GetSystemMetrics(1);
			v4 = *(_DWORD *)&byte_5D4594[3801784];
			v5 = *(_DWORD *)&byte_5D4594[3801788];
			v6 = v3;
			v7 = 0;
			v8 = 0;
			if (uFlags)
			{
				uFlagsa = 0;
				if ((byte_5D4594[3801772] & 0x18) == 24)
				{
					v7 = (v2 - *(int *)&byte_5D4594[3801784]) / 2;
					v8 = (v6 - *(int *)&byte_5D4594[3801788]) / 2;
				LABEL_11:
					SetRect(&rc, v7, v8, v7 + v4, v8 + v5);
					v10 = GetMenu(dword_973FE0);
					v9 = GetWindowLongA(dword_973FE0, -16);
					AdjustWindowRect(&rc, v9, (BOOL)v10);
					SetWindowPos(
						dword_973FE0,
						(HWND)(((byte_5D4594[3801772] & 0x10) != 0) - 1),
						rc.left,
						rc.top,
						rc.right - rc.left,
						rc.bottom - rc.top,
						uFlagsa);
					ShowWindow(dword_973FE0, 1);
					GetClientRect(dword_973FE0, &rc);
					ClientToScreen(dword_973FE0, (LPPOINT)&rc);
					ClientToScreen(dword_973FE0, (LPPOINT)&rc.right);
					if (!(byte_5D4594[3801772] & 4))
						ClipCursor(&rc);
					sub_4348C0();
					dword_5ACFAC = 0;
					SetCursor(0);
					return;
				}
				if ((byte_5D4594[3801772] & 0x10) != 16)
					goto LABEL_11;
			}
			else
			{
				uFlagsa = SWP_NOMOVE;
				if ((byte_5D4594[3801772] & 0x18) != 16)
					goto LABEL_11;
			}
			v4 = v2;
			v5 = v6;
			goto LABEL_11;
		}
	}
#endif
}

//----- (0048A9C0) --------------------------------------------------------
void __cdecl sub_48A9C0(int a1)
{
	if (dword_6F7BB0)
	{
		EnterCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
		if (!dword_974854)
		{
			if (byte_5D4594[3801772] & 0x10)
			{
				dword_974854 = 1;
#ifdef USE_SDL
                SDL_SetWindowGrab(dword_973FE0, SDL_FALSE);
#else
				ClipCursor(0);
#endif
				LeaveCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
				return;
			}
			if (a1)
			{
				dword_974854 = 1;
				dword_973C70 = 1;
#ifdef USE_SDL
                SDL_MinimizeWindow(dword_973FE0);
#else
				ShowWindow(dword_973FE0, SW_MINIMIZE);
#endif
			}
		}
		LeaveCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
	}
}

//----- (0048AA40) --------------------------------------------------------
void sub_48AA40()
{
#ifdef USE_SDL
    // FIXME
#else
	int v1; // eax
	DWORD v2; // eax
	int v3; // [esp-8h] [ebp-18h]
	HMENU v4; // [esp-8h] [ebp-18h]
	RECT rc; // [esp+0h] [ebp-10h]

	if (IsWindow(dword_973FE0))
	{
		if ((byte_5D4594[3801772] & 0x18) != 24)
		{
			v3 = GetSystemMetrics(1);
			v1 = GetSystemMetrics(0);
			SetRect(&rc, 0, 0, v1, v3);
			v4 = GetMenu(dword_973FE0);
			v2 = GetWindowLongA(dword_973FE0, -16);
			AdjustWindowRect(&rc, v2, (BOOL)v4);
			SetWindowPos(dword_973FE0, 0, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, 0);
			ShowWindow(dword_973FE0, 1);
		}
	}
	return result;
#endif
}

#ifdef USE_SDL
static void set_viewport(float srcw, float srch)
{
    float ratio = srcw / srch, offx = 0, offy = 0;
	int vpw, vph, vpx, vpy;

#ifdef __EMSCRIPTEN__
	EM_ASM_({
		if (canvas.width != canvas.clientWidth * devicePixelRatio || canvas.height != canvas.clientHeight * devicePixelRatio) {
			canvas.width = canvas.clientWidth * devicePixelRatio;
			canvas.height = canvas.clientHeight * devicePixelRatio;
		}
	});
	vpw = EM_ASM_INT(return canvas.width);
	vph = EM_ASM_INT(return canvas.height);
#else
	SDL_GL_GetDrawableSize(dword_973FE0, &vpw, &vph);
#endif

    //
    // Maintain source aspect ratio
    //
    g_rotated = g_rotate && vph - ratio * vpw > vpw - ratio * vph;
    if (g_rotated)
      ratio = 1.0f / ratio;

    if (ratio * vph <= vpw) {
      offx = (vpw - vph * ratio) / 2;
      vpw = vph * ratio;
    } else {
      offy = (vph - vpw / ratio) / 2;
      vph = vpw / ratio;
    }
    vpx = offx;
    vpy = offy;

    glViewport(vpx, vpy, vpw, vph);
}

void sdl_present()
{
    if (g_ddraw)
    {
        SDL_Rect srcrect;
        char *srcpixels = g_backbuffer1->pixels;
        char *pixels;
        int srcpitch = g_backbuffer1->pitch;
        int pitch;
        const float matrix[] = {1.0, 0.0, 0.0, 1.0};
        const float matrixRotated[] = {0.0, 1.0, 1.0, 0.0};

		sub_48BE50(1);
		sub_48B5D0(0, 0);

        glBindTexture(GL_TEXTURE_2D, g_texture);
        glCheckError();
#ifndef __EMSCRIPTEN__
        glPixelStorei(GL_UNPACK_ROW_LENGTH, g_backbuffer1->pitch / 2);
        glCheckError();
#endif
#ifdef _WIN32
        // XXX FIXME WHY?
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, g_backbuffer1->w, g_backbuffer1->h, GL_BGRA, GL_UNSIGNED_SHORT_1_5_5_5_REV, g_backbuffer1->pixels);
#else
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, g_backbuffer1->w, g_backbuffer1->h, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, g_backbuffer1->pixels);
#endif
        glCheckError();

/*
        EM_ASM_({
            Module['renderTexture']($0, $1);
        }, g_backbuffer1->w, g_backbuffer1->h);
*/
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glCheckError();

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glCheckError();
        set_viewport(g_backbuffer1->w, g_backbuffer1->h);
        glCheckError();

        glClear(GL_COLOR_BUFFER_BIT);
        glCheckError();

        glUseProgram(g_program);
        glCheckError();
        glUniform1i(g_sampler_uniform, 0);
        glCheckError();
        glUniformMatrix2fv(g_matrix_uniform, 1, GL_FALSE, g_rotated ? matrixRotated : matrix);
        glCheckError();
        glUniform1f(g_gamma_uniform, draw_gamma);
        glCheckError();
        glBindBuffer(GL_ARRAY_BUFFER, g_tex_coord_buffer);
        glCheckError();
        glVertexAttribPointer(g_tex_coord_attr, g_tex_coord_itemsize, GL_FLOAT, GL_FALSE, 0, 0);
        glCheckError();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, g_tex_coord_numitems);
        glCheckError();

        SDL_GL_SwapWindow(dword_973FE0);

		sub_48BE50(0);
    }
}
#else
//----- (0048AAF0) --------------------------------------------------------
void __cdecl sub_48AAF0()
{
	if (g_ddraw && !dword_974854 && (!g_frontbuffer->lpVtbl->IsLost(g_frontbuffer) || sub_48A2A0()))
	{
		sub_48BE50(1);
		sub_48B5D0(0, 0);
		g_frontbuffer->lpVtbl->Flip(g_frontbuffer, 0, DDFLIP_WAIT);
		sub_48BE50(0);
	}
}

//----- (0048AB50) --------------------------------------------------------
void __cdecl sub_48AB50()
{
	int v0; // eax

	if (g_ddraw)
	{
		sub_48BE50(1);
		sub_48B5D0(0, 0);
		if (!g_frontbuffer->lpVtbl->Flip(g_frontbuffer, 0, DDFLIP_WAIT))
		{
			v0 = ++dword_6F7B9C;
			if (dword_6F7B9C >= g_backbuffer_count)
			{
				v0 = 0;
				dword_6F7B9C = 0;
			}
			*(_DWORD *)&byte_5D4594[3798752] = *(_DWORD *)&byte_5D4594[4 * v0 + 1193488];
		}
		sub_48BE50(0);
	}
}

//----- (0048ABC0) --------------------------------------------------------
void __cdecl sub_48ABC0()
{
	POINT Point; // [esp+4h] [ebp-28h]
	RECT rectClient; // [esp+Ch] [ebp-20h]
	RECT rc; // [esp+1Ch] [ebp-10h]

	if (!dword_974854 && g_ddraw && (!g_frontbuffer->lpVtbl->IsLost(g_frontbuffer) || sub_48A2A0()))
	{
		if (IsWindow(dword_973FE0))
		{
			Point.x = 0;
			Point.y = 0;
			ClientToScreen(dword_973FE0, &Point);
			GetClientRect(dword_973FE0, &rectClient);
			OffsetRect(&rectClient, Point.x, Point.y);
			SetRect(&rc, 0, 0, *(int *)&byte_5D4594[3801784], *(int *)&byte_5D4594[3801788]);
			sub_48BE50(1);
			sub_48BD90(0);
			sub_48B5D0(0, 0);
			g_frontbuffer->lpVtbl->Blt(g_frontbuffer, &rectClient, g_backbuffer1, &rc, 0x1000000, 0);
			sub_48BE50(0);
		}
	}
}

//----- (0048ACC0) --------------------------------------------------------
int sub_48ACC0()
{
	int result; // eax

	if (!(byte_5D4594[3801772] & 0x20))
		return 1;
	result = sub_48A6C0(g_frontbuffer);
	if (result)
	{
		*(_DWORD *)&byte_5D4594[1193488] = result;
		result = sub_48A6C0(g_backbuffer1);
		if (result)
		{
			*(_DWORD *)&byte_5D4594[1193492] = result;
			if ((byte_5D4594[3801772] & 0x80u) != 0)
			{
				result = sub_48A6C0(g_backbuffer2);
				if (!result)
					return result;
				*(_DWORD *)&byte_5D4594[1193496] = result;
			}
			dword_6F7B9C = 1;
			*(_DWORD *)&byte_5D4594[3798752] = *(_DWORD *)&byte_5D4594[1193492];
			return 1;
		}
	}
	return result;
}
#endif

#ifdef USE_SDL
int create_surfaces(HWND a1, int width, int height)
{
    int result = 0;
    BYTE v3;

	v3 = byte_5D4594[3801772];
#if 0
	if ((v3 & 0x18) == 24)
		SetWindowLongA(dword_973FE0, GWL_STYLE, WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_GROUP);
#endif
    g_backbuffer1 = sub_48A600(width, height, DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH, DDSCAPS_OFFSCREENPLAIN);
    //g_backbufferrgb = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_ABGR8888);
    if (g_backbuffer1)
    {
        //if (SDL_RenderSetLogicalSize(g_ddraw, width, height) == 0)
            result = 1;
    }
    return result;
}
#else
//----- (0048AD40) --------------------------------------------------------
signed int __cdecl sub_48AD40(HWND a1, int a2, int a3, int a4)
{
	int v5; // [esp+2Ch] [ebp-70h]
	DDSURFACEDESC v6; // [esp+30h] [ebp-6Ch]

	SetWindowLongA(dword_973FE0, GWL_STYLE, WS_POPUP);
	SetForegroundWindow(dword_973FE0);
	if (g_ddraw->lpVtbl->SetCooperativeLevel(g_ddraw, dword_973FE0, 19))
		return 0;
	if (g_ddraw->lpVtbl->SetDisplayMode(g_ddraw, a2, a3, a4))
		return 0;
	memset(&v6, 0, sizeof(v6));
	v6.dwSize = 108;
	v6.dwFlags = 33;
	v6.ddsCaps.dwCaps = 536;
	v6.dwBackBufferCount = 1;
	if ((*(_DWORD *)&byte_5D4594[3801772] & 0x80u) != 0)
	{
		v6.dwBackBufferCount = 2;
		++g_backbuffer_count;
	}
	if (g_ddraw->lpVtbl->CreateSurface(g_ddraw, &v6, &g_frontbuffer, 0))
		return 0;
	v5 = 1;
	g_frontbuffer->lpVtbl->EnumAttachedSurfaces(g_frontbuffer, &v5, sub_48AE80);
	g_ddraw->lpVtbl->CreateClipper(g_ddraw, 0, &g_clipper, 0);
	g_clipper->lpVtbl->SetHWnd(g_clipper, 0, dword_973FE0);
	g_frontbuffer->lpVtbl->SetClipper(g_frontbuffer, g_clipper);
	return 1;
}

//----- (0048AE80) --------------------------------------------------------
int __stdcall sub_48AE80(LPDIRECTDRAWSURFACE a1, LPDDSURFACEDESC a2, LPVOID a3)
{
	int v4; // eax

	v4 = *(_DWORD *)a3 - 1;
	if ((*(_DWORD *)a3)++ == 1)
	{
		g_backbuffer1 = a1;
		a1->lpVtbl->EnumAttachedSurfaces(a1, a3, sub_48AE80);
	}
	else if (v4 == 1 && g_backbuffer_count > 2)
	{
		g_backbuffer2 = a1;
		return 0;
	}
	return 0;
}

//----- (0048AED0) --------------------------------------------------------
int __cdecl sub_48AED0(HWND a1, int a2, int a3)
{
	char v3; // al
	HDC v4; // esi
	int v5; // edi
	int result; // eax

	v3 = byte_5D4594[3801772];
	if (!(v3 & 4))
	{
		v4 = CreateICA("Display", 0, 0, 0);
		v5 = GetDeviceCaps(v4, 12);
		DeleteDC(v4);
		if (*(_DWORD *)&byte_5D4594[3799568] == 8)
		{
			if (v5 != *(_DWORD *)&byte_5D4594[3799568])
			{
				sub_48C940("8 bit color windowed mode requires you switch your desktop to 256 colors");
				return 0;
			}
		}
		else if (*(_DWORD *)&byte_5D4594[3799568] == 16 && v5 != 16)
		{
			sub_48C940("16 bit color windowed mode requires you switch your desktop to High Color (65536 colors)");
			return 0;
		}
	}
	if ((v3 & 0x18) == 24)
		SetWindowLongA(dword_973FE0, GWL_STYLE, WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_GROUP);
	if (g_ddraw->lpVtbl->SetCooperativeLevel(g_ddraw, dword_973FE0, 12))
		return 0;

	g_frontbuffer = sub_48A600(0, 0, DDSD_CAPS, DDSCAPS_PRIMARYSURFACE);
	if (g_frontbuffer)
	{
		g_backbuffer1 = sub_48A600(a2, a3, DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH, DDSCAPS_OFFSCREENPLAIN);
		if (g_backbuffer1)
		{
			g_ddraw->lpVtbl->CreateClipper(g_ddraw, 0, &g_clipper, 0);
			g_clipper->lpVtbl->SetHWnd(g_clipper, 0, dword_973FE0);
			g_frontbuffer->lpVtbl->SetClipper(g_frontbuffer, g_clipper);
			result = 1;
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}
#endif

#ifdef USE_SDL

#ifdef __EMSCRIPTEN__
#define FLOAT_PRECISION "precision mediump float;\n"
#else
#define FLOAT_PRECISION ""
#endif

const GLchar *vertex_source = FLOAT_PRECISION \
    "attribute vec2 aTextureCoord;\n" \
    "varying vec4 vColor;\n" \
    "varying vec2 vTextureCoord;\n" \
    "\n" \
    "void main(void) {\n" \
    "    vec2 pos = 2.0 * aTextureCoord - 1.0;\n" \
    "    gl_Position = vec4(pos.x, pos.y, 0.0, 1.0);\n" \
    "    vTextureCoord = aTextureCoord;\n" \
    "}\n";
const GLchar *fragment_source = FLOAT_PRECISION \
    "varying vec2 vTextureCoord;\n" \
    "uniform sampler2D uSampler;\n" \
    "uniform float uGamma;\n" \
    "uniform mat2 uMatrix;\n" \
    "\n" \
    "void main(void) {\n" \
    "    vec2 coordTex = vec3(vTextureCoord - 0.5, 1).xy + 0.5;\n" \
    "    coordTex.y = uMatrix[1].y - (2.0 * uMatrix[1].y - 1.0) * coordTex.y;\n" \
    "    gl_FragColor.rgb = pow(texture2D(uSampler, coordTex * uMatrix).rgb, vec3(1.0/uGamma));\n" \
    "}\n";

int sub_48B000()
{
    GLenum err;
    GLint status;
    GLuint vertex, fragment;
    float coords[] = {1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0};

#if __EMSCRIPTEN__
    g_rotate = EM_ASM_INT(return Module['shouldRotate']());
#else
    g_rotate = 0;
#endif
    g_format = SDL_PIXELFORMAT_RGBA5551;
    g_ddraw = SDL_GL_CreateContext(dword_973FE0);
    SDL_GL_SetSwapInterval(1);

#ifdef _WIN32
    err = glewInit();
    if (GLEW_OK != err)
    {
      /* Problem: glewInit failed, something is seriously wrong. */
      dprintf("Error: %s\n", glewGetErrorString(err));
    }
#endif

    glGenTextures(1, &g_texture);
    glCheckError();
    glActiveTexture(GL_TEXTURE0);
    glCheckError();
    glBindTexture(GL_TEXTURE_2D, g_texture);
    glCheckError();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *(_DWORD *)&byte_5D4594[3805496], *(_DWORD *)&byte_5D4594[3807120], 0, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, NULL);
    glCheckError();

#if 0
    EM_ASM_({
        Module['initGL']($0, $1);
    }, *(_DWORD *)&byte_5D4594[3805496], *(_DWORD *)&byte_5D4594[3807120]);
#endif

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glCheckError();
    glShaderSource(vertex, 1, &vertex_source, NULL);
    glCheckError();
    glCompileShader(vertex);
    glCheckError();
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        char tmp[8192];
        glGetShaderInfoLog(vertex, 8192, NULL, tmp);
        fprintf(stderr, "%s\n", tmp);
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glCheckError();
    glShaderSource(fragment, 1, &fragment_source, NULL);
    glCheckError();
    glCompileShader(fragment);
    glCheckError();
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        char tmp[8192];
        glGetShaderInfoLog(fragment, 8192, NULL, tmp);
        fprintf(stderr, "%s\n", tmp);
    }

    g_program = glCreateProgram();
    glCheckError();
    glAttachShader(g_program, vertex);
    glCheckError();
    glAttachShader(g_program, fragment);
    glCheckError();
    glLinkProgram(g_program);
    glCheckError();
    glGetProgramiv(g_program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        fprintf(stderr, "Link failed.\n");
    }

    glUseProgram(g_program);
    glCheckError();
    g_tex_coord_attr = glGetAttribLocation(g_program, "aTextureCoord");
    glCheckError();
    glEnableVertexAttribArray(g_tex_coord_attr);
    glCheckError();
    g_gamma_uniform = glGetUniformLocation(g_program, "uGamma");
    glCheckError();
    g_matrix_uniform = glGetUniformLocation(g_program, "uMatrix");
    glCheckError();
    g_sampler_uniform = glGetUniformLocation(g_program, "uSampler");
    glCheckError();

    glGenBuffers(1, &g_tex_coord_buffer);
    glCheckError();
    glBindBuffer(GL_ARRAY_BUFFER, g_tex_coord_buffer);
    glCheckError();
    glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);
    g_tex_coord_itemsize = 2;
    g_tex_coord_numitems = 4;

    return 1;
}
#else
//----- (0048B000) --------------------------------------------------------
int sub_48B000()
{
	int result; // eax
	GUID *v1; // eax
	LPDIRECTDRAW lpDD; // [esp+14h] [ebp-8h]
	int v3; // [esp+18h] [ebp-4h]

	lpDD = 0;
	g_driver_guid = NULL;
	if (DirectDrawEnumerateA(Callback, 0))
		return 0;
	if (DirectDrawCreate(g_driver_guid, &lpDD, 0))
		return 0;
	if (*(_DWORD *)&byte_5D4594[1193504])
		lpDD->lpVtbl->EnumDisplayModes(lpDD, 0, 0, 0, *(LPDDENUMMODESCALLBACK *)&byte_5D4594[1193504]);
	if (sub_48B140(lpDD, &IID_IDirectDraw, &v3))
	{
		if (v3)
			lpDD->lpVtbl->Release(lpDD);
		result = 1;
	}
	else
	{
		sub_48C940("You do not have the correct version of DirectX!");
		result = 0;
	}
	return result;
}

//----- (0048B0C0) --------------------------------------------------------
BOOL __stdcall Callback(GUID *lpGUID, LPSTR a2, LPSTR a3, LPVOID a4)
{
	LPDIRECTDRAW lpDD; // [esp+Ch] [ebp-180h]
	DDCAPS v6;

	if (!DirectDrawCreate(lpGUID, &lpDD, 0))
	{
		memset(&v6, 0, sizeof(v6));
		v6.dwSize = 380;
		if (!lpDD->lpVtbl->GetCaps(lpDD, &v6, 0) && (v6.dwCaps & (DDCAPS_BLT | DDCAPS_3D)) == DDCAPS_BLT)
			g_driver_guid = lpGUID;
		lpDD->lpVtbl->Release(lpDD);
	}
	return 1;
}

//----- (0048B140) --------------------------------------------------------
int __cdecl sub_48B140(LPDIRECTDRAW a1, const IID *a2, int *a3)
{
	LPVOID pvObj;
	int result; // eax

	if (a1->lpVtbl->QueryInterface(a1, a2, &pvObj))
	{
		g_ddraw = a1;
		result = 1;
		*a3 = 0;
	}
	else
	{
		g_ddraw = pvObj;
		result = 1;
		*a3 = 1;
	}
	return result;
}
#endif

#ifdef USE_SDL
void __cdecl sub_48B1B0(SDL_GLContext *a1)
{
    if (*a1)
    {
        SDL_GL_DeleteContext(*a1);
        *a1 = NULL;
    }
}

void __cdecl sub_48B1D0(SDL_Surface **a1)
{
    if (*a1)
    {
        SDL_FreeSurface(*a1);
        *a1 = NULL;
    }
}
#else
//----- (0048B190) --------------------------------------------------------
void __cdecl sub_48B190(LPDIRECTDRAWCLIPPER *a1)
{
	if (*a1)
	{
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (0048B1B0) --------------------------------------------------------
void __cdecl sub_48B1B0(LPDIRECTDRAW *a1)
{
	if (*a1)
	{
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (0048B1D0) --------------------------------------------------------
void __cdecl sub_48B1D0(LPDIRECTDRAWSURFACE *a1)
{
	if (*a1)
	{
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}
#endif

//----- (0048B1F0) --------------------------------------------------------
int sub_48B1F0()
{
	int result; // eax

	if (byte_5D4594[3801773] & 1)
	{
		*(_DWORD *)&byte_5D4594[3798724] = 0;
		return 1;
	}
	*(_DWORD *)&byte_5D4594[3798724] = 1;
	if (byte_5D4594[3801772] & 4)
		return 1;
	*(_DWORD *)&byte_5D4594[1193640] = 0;
	*(_DWORD *)&byte_5D4594[1193628] = 0;
	*(_DWORD *)&byte_5D4594[1193648] = 0;
	*(_DWORD *)&byte_5D4594[1193524] = 0;
	*(_DWORD *)&byte_5D4594[1193580] = 0;
	*(_DWORD *)&byte_5D4594[1193636] = 0;
	*(_DWORD *)&byte_5D4594[1193600] = 0;
	*(_DWORD *)&byte_5D4594[1193620] = 0;
	SetRect((LPRECT)&byte_5D4594[1193532], 0, 0, 0, 0);
	SetRect((LPRECT)&byte_5D4594[1193548], 0, 0, 0, 0);
	SetRect((LPRECT)&byte_5D4594[1193604], 0, 0, 0, 0);
	*(_DWORD *)&byte_5D4594[1193624] = 0;
	*(_DWORD *)&byte_5D4594[3798728] = 0;
	*(_DWORD *)&byte_5D4594[1193664] = 0;
	*(_DWORD *)&byte_5D4594[1193668] = 0;
	*(_DWORD *)&byte_5D4594[1193672] = 0;
	*(_DWORD *)&byte_5D4594[1193676] = 0;
	*(_DWORD *)&byte_5D4594[1193680] = 0;
	sub_48C110();
	if (*(_DWORD *)&byte_5D4594[3801780])
	{
		if (*(_DWORD *)&byte_5D4594[3801780] == 1)
		{
			dword_6F7C10 = sub_48C200;
			dword_6F7C40 = sub_48C480;
			dword_6F7C34 = sub_48C4D0;
		}
	}
	else
	{
		dword_6F7C10 = sub_48C320;
		dword_6F7C40 = sub_48C420;
		dword_6F7C34 = sub_48C420;
	}
#ifdef USE_SDL
    dword_6F7BF0 = sdl_unk1;
#else
	if (byte_5D4594[3801772] & 0x10)
        // windowed mode
        dword_6F7BF0 = sub_48BA50;
    else
        // fullscreen mode
		dword_6F7BF0 = sub_48B840;
#endif
	result = sub_48BF70();
    printf("%s: %d\n", __FUNCTION__, result);
	if (result)
	{
		result = sub_48C060();
    printf("%s: %d\n", __FUNCTION__, result);
		if (result)
		{
			result = sub_48BDE0();
    printf("%s: %d\n", __FUNCTION__, result);
			if (result)
			{
				result = sub_48BE70();
    printf("%s: %d\n", __FUNCTION__, result);
				if (result)
				{
					*(_DWORD *)&byte_5D4594[1193660] = 1;
					return 1;
				}
			}
		}
	}
	return result;
}

int sdl_unk1(int a1)
{
    RECT *r1 = (RECT *)&byte_5D4594[1193532];
    RECT *r2 = (RECT *)&byte_5D4594[1193548];
    RECT *r3 = (RECT *)&byte_5D4594[1193604];
    RECT v4;
    SDL_Rect src, dst;

    if (a1 && (*(_DWORD *)&byte_5D4594[1193668] || *(_DWORD *)&byte_5D4594[1193664]) && !IsRectEmpty(r1))
    {
        // FIXME frontbuffer?
        rect_to_sdl(r2, &src);
        rect_to_sdl(r1, &dst);
        // SDL_BlitScaled(dword_6F7C48, &src, g_backbuffer1, &dst);
    }

    r1->left = *(_DWORD *)&byte_5D4594[1193648] - *(_DWORD *)&byte_5D4594[1193580];
    r1->right = r1->left + *(_DWORD *)&byte_5D4594[1193600];
    r1->top = *(_DWORD *)&byte_5D4594[1193524] - *(_DWORD *)&byte_5D4594[1193636];
    r1->bottom = r1->top + *(_DWORD *)&byte_5D4594[1193620];

	if ((!a1 || *(_DWORD *)&byte_5D4594[1193668] || *(_DWORD *)&byte_5D4594[1193664])
		&& sub_49F930((int4 *)&v4, r1, (int4 *)&byte_5D4594[3800752]))
	{
        r2->left = 0;
        r2->top = 0;
        r2->right = v4.right - v4.left;
        r2->bottom = v4.bottom - v4.top;

        // FIXME frontbuffer?
        rect_to_sdl(&v4, &src);
        rect_to_sdl(r2, &dst);
        //if (SDL_BlitScaled(g_backbuffer1, &src, dword_6F7C48, &dst))
		//	return 0;
	}

	if (sub_49F930((int4 *)&v4, r1, (int4 *)&byte_5D4594[3800752]))
	{
        r3->left = v4.left - r1->left;
        r3->top = v4.top - r1->top;
        r3->right = v4.right - r1->left;
        r3->bottom = v4.bottom - r1->top;

        // FIXME frontbuffer?
        rect_to_sdl(r3, &src);
        rect_to_sdl(&v4, &dst);

#if 0
        uint16_t *dstpixels;
        int dstpitch;

        if (SDL_LockTexture(g_texture, &dst, (void **)&dstpixels, &dstpitch) == 0)
        {
            unsigned int x, y;
            unsigned int colorkey;
            int srcpitch = g_cursor_surf->pitch;
            uint16_t *srcpixels = (uint16_t *)g_cursor_surf->pixels;
            SDL_Rect srcrect;

            SDL_GetColorKey(g_cursor_surf, &colorkey);

            srcpixels += src.x + src.y * srcpitch / sizeof(*srcpixels);

            for (y = 0; y < src.h; y++)
            {
                for (x = 0; x < src.w; x++)
                {
                    uint16_t pixel = srcpixels[x];
                    if (pixel != colorkey)
                        dstpixels[x] = pixel;
                    dstpixels[x] = 0;
                }
                dstpixels += dstpitch / sizeof(*dstpixels);
                srcpixels += srcpitch / sizeof(*srcpixels);
            }

            SDL_UnlockTexture(g_texture);
            SDL_RenderCopy(g_ddraw, g_texture, &dst, &dst);
            SDL_RenderPresent(g_ddraw);
        }
#endif

        if (SDL_BlitScaled(g_cursor_surf, &src, g_backbuffer1, &dst))
			return 0;

        *r1 = v4;
	}

	*(_DWORD *)&byte_5D4594[1193664] = 0;
	*(_DWORD *)&byte_5D4594[1193668] = 0;
	return 1;
}

#if 0
//----- (0048B840) --------------------------------------------------------
int __cdecl sub_48B840(int a1)
{
	LPDIRECTDRAWSURFACE v1;
	LPDIRECTDRAWSURFACE v3; // eax
	RECT v4; // [esp+30h] [ebp-10h]

	if (a1
		&& (*(_DWORD *)&byte_5D4594[1193668] || *(_DWORD *)&byte_5D4594[1193664])
		&& !IsRectEmpty((const RECT *)&byte_5D4594[1193532]))
	{
		g_frontbuffer->lpVtbl->Blt(g_frontbuffer,
				&byte_5D4594[1193532],
				dword_6F7C48,
				&byte_5D4594[1193548],
				0x1000000,
				0);
	}
	*(_DWORD *)&byte_5D4594[1193532] = *(_DWORD *)&byte_5D4594[1193648] - *(_DWORD *)&byte_5D4594[1193580];
	*(_DWORD *)&byte_5D4594[1193540] = *(_DWORD *)&byte_5D4594[1193648]
		- *(_DWORD *)&byte_5D4594[1193580]
		+ *(_DWORD *)&byte_5D4594[1193600];
	*(_DWORD *)&byte_5D4594[1193536] = *(_DWORD *)&byte_5D4594[1193524] - *(_DWORD *)&byte_5D4594[1193636];
	*(_DWORD *)&byte_5D4594[1193544] = *(_DWORD *)&byte_5D4594[1193524]
		- *(_DWORD *)&byte_5D4594[1193636]
		+ *(_DWORD *)&byte_5D4594[1193620];
	if ((!a1 || *(_DWORD *)&byte_5D4594[1193668] || *(_DWORD *)&byte_5D4594[1193664])
		&& sub_49F930((int4 *)&v4, (int4 *)&byte_5D4594[1193532], (int4 *)&byte_5D4594[3800752]))
	{
		*(_DWORD *)&byte_5D4594[1193556] = v4.right - v4.left;
		v1 = g_frontbuffer;
		*(_DWORD *)&byte_5D4594[1193548] = 0;
		*(_DWORD *)&byte_5D4594[1193552] = 0;
		*(_DWORD *)&byte_5D4594[1193560] = v4.bottom - v4.top;
		if (!a1)
			v1 = g_backbuffer1;
		if (dword_6F7C48->lpVtbl->Blt(dword_6F7C48,
				&byte_5D4594[1193548],
				v1,
				&v4,
				0x1000000,
				0))
		{
			return 0;
		}
	}
	if (sub_49F930((int4 *)&v4, (int4 *)&byte_5D4594[1193532], (int4 *)&byte_5D4594[3800752]))
	{
		*(_DWORD *)&byte_5D4594[1193604] = v4.left - *(_DWORD *)&byte_5D4594[1193532];
		*(_DWORD *)&byte_5D4594[1193608] = v4.top - *(_DWORD *)&byte_5D4594[1193536];
		*(_DWORD *)&byte_5D4594[1193612] = v4.right - *(_DWORD *)&byte_5D4594[1193532];
		v3 = g_frontbuffer;
		*(_DWORD *)&byte_5D4594[1193616] = v4.bottom - *(_DWORD *)&byte_5D4594[1193536];
		if (!a1)
			v3 = g_backbuffer1;
		if (v3->lpVtbl->Blt(v3,
			&v4,
			g_cursor_surf,
			&byte_5D4594[1193604],
			16809984,
			0))
		{
			return 0;
		}
		*(RECT *)&byte_5D4594[1193532] = v4;
	}
	*(_DWORD *)&byte_5D4594[1193664] = 0;
	*(_DWORD *)&byte_5D4594[1193668] = 0;
	return 1;
}

//----- (0048BA50) --------------------------------------------------------
int __cdecl sub_48BA50(int a1)
{
	int v2; // eax
	struct tagPOINT Point; // [esp+28h] [ebp-38h]
	RECT v4; // [esp+30h] [ebp-30h]
	RECT rc; // [esp+40h] [ebp-20h]
	int v6[4]; // [esp+50h] [ebp-10h]

	if (a1
		&& (*(_DWORD *)&byte_5D4594[1193668] || *(_DWORD *)&byte_5D4594[1193664])
		&& !IsRectEmpty((const RECT *)&byte_5D4594[1193532]))
	{
		sub_48C170((int4 *)&rc, (int4 *)&byte_5D4594[1193532]);
		sub_48C170((int4 *)v6, (int4 *)&byte_5D4594[1193548]);
		Point.x = 0;
		Point.y = 0;
		ClientToScreen(dword_973FE0, &Point);
		OffsetRect(&rc, Point.x, Point.y);
		g_frontbuffer->lpVtbl->Blt(g_frontbuffer,
			&rc,
			dword_6F7C48,
			v6,
			0x1000000,
			0);
	}
	*(_DWORD *)&byte_5D4594[1193532] = *(_DWORD *)&byte_5D4594[1193648] - *(_DWORD *)&byte_5D4594[1193580];
	*(_DWORD *)&byte_5D4594[1193540] = *(_DWORD *)&byte_5D4594[1193648]
		- *(_DWORD *)&byte_5D4594[1193580]
		+ *(_DWORD *)&byte_5D4594[1193600];
	*(_DWORD *)&byte_5D4594[1193536] = *(_DWORD *)&byte_5D4594[1193524] - *(_DWORD *)&byte_5D4594[1193636];
	*(_DWORD *)&byte_5D4594[1193544] = *(_DWORD *)&byte_5D4594[1193524]
		- *(_DWORD *)&byte_5D4594[1193636]
		+ *(_DWORD *)&byte_5D4594[1193620];
	if ((!a1 || *(_DWORD *)&byte_5D4594[1193668] || *(_DWORD *)&byte_5D4594[1193664])
		&& sub_49F930((int4 *)&v4, (int4 *)&byte_5D4594[1193532], (int4 *)&byte_5D4594[3800752]))
	{
		*(_DWORD *)&byte_5D4594[1193556] = v4.right - v4.left;
		*(_DWORD *)&byte_5D4594[1193548] = 0;
		*(_DWORD *)&byte_5D4594[1193552] = 0;
		*(_DWORD *)&byte_5D4594[1193560] = v4.bottom - v4.top;
		if (a1)
		{
			sub_48C170((int4 *)&rc, (int4 *)&v4);
			sub_48C170((int4 *)v6, (int4 *)&byte_5D4594[1193548]);
			Point.x = 0;
			Point.y = 0;
			ClientToScreen(dword_973FE0, &Point);
			OffsetRect(&rc, Point.x, Point.y);
			if (dword_6F7C48->lpVtbl->Blt(dword_6F7C48,
					v6,
					g_frontbuffer,
					&rc,
					0x1000000,
					0))
			{
				return 0;
			}
		}
		else
		{
			sub_48C170((int4 *)v6, (int4 *)&byte_5D4594[1193548]);
			if (dword_6F7C48->lpVtbl->Blt(dword_6F7C48,
				v6,
				g_backbuffer1,
				&v4,
				0x1000000,
				0))
			{
				return 0;
			}
		}
	}
	if (sub_49F930((int4 *)&v4, (int4 *)&byte_5D4594[1193532], (int4 *)&byte_5D4594[3800752]))
	{
		*(_DWORD *)&byte_5D4594[1193604] = v4.left - *(_DWORD *)&byte_5D4594[1193532];
		*(_DWORD *)&byte_5D4594[1193608] = v4.top - *(_DWORD *)&byte_5D4594[1193536];
		*(_DWORD *)&byte_5D4594[1193612] = v4.right - *(_DWORD *)&byte_5D4594[1193532];
		*(_DWORD *)&byte_5D4594[1193616] = v4.bottom - *(_DWORD *)&byte_5D4594[1193536];
		if (a1)
		{
			sub_48C170((int4 *)&rc, (int4 *)&v4);
			Point.x = 0;
			Point.y = 0;
			ClientToScreen(dword_973FE0, &Point);
			OffsetRect(&rc, Point.x, Point.y);
			v2 = g_frontbuffer->lpVtbl->Blt(g_frontbuffer,
					&rc,
					g_cursor_surf,
					&byte_5D4594[1193604],
					16809984,
					0);
		}
		else
		{
			v2 = g_backbuffer1->lpVtbl->Blt(g_backbuffer1,
					&v4,
					g_cursor_surf,
					&byte_5D4594[1193604],
					16809984,
					0);
		}
		if (v2)
			return 0;
		*(RECT *)&byte_5D4594[1193532] = v4;
	}
	*(_DWORD *)&byte_5D4594[1193664] = 0;
	*(_DWORD *)&byte_5D4594[1193668] = 0;
	return 1;
}
#endif

//----- (004340A0) --------------------------------------------------------
void __cdecl sub_4340A0(int a1, int a2, int a3, int a4)
{
	unsigned __int64 v4; // rax
	int v5; // esi
	unsigned __int64 v6; // rax
	unsigned __int64 v7; // rax

	LODWORD(v4) = a1;
	if (a1 >= 0 && a1 < 16)
	{
		v5 = 48 * a1 + *(_DWORD *)&byte_5D4594[3799572] + 264;
		*(_DWORD *)(v5 + 32) = (unsigned __int8)a4;
		*(_DWORD *)(v5 + 24) = (unsigned __int8)a2;
		*(_DWORD *)(v5 + 28) = (unsigned __int8)a3;
		dword_69A014(a2, a3, a4, (DWORD *)(v5 + 40));
		LODWORD(v4) = *(_DWORD *)&byte_5D4594[3801804];
		if (*(_DWORD *)&byte_5D4594[3801804])
		{
			v6 = ((unsigned __int8)a2 | (((unsigned __int8)a2 | ((unsigned __int64)(unsigned __int8)a2 << 16)) << 16)) << 16;
			*(_DWORD *)v5 = (unsigned __int8)a2 | (unsigned int)v6;
			*(_DWORD *)(v5 + 4) = HIDWORD(v6);
			v7 = ((unsigned __int8)a3 | (((unsigned __int8)a3 | ((unsigned __int64)(unsigned __int8)a3 << 16)) << 16)) << 16;
			*(_DWORD *)(v5 + 8) = (unsigned __int8)a3 | (unsigned int)v7;
			*(_DWORD *)(v5 + 12) = HIDWORD(v7);
			v4 = ((unsigned __int8)a4 | (((unsigned __int8)a4 | ((unsigned __int64)(unsigned __int8)a4 << 16)) << 16)) << 16;
			LODWORD(v4) = (unsigned __int8)a4 | (unsigned int)v4;
			*(_QWORD *)(v5 + 16) = v4;
		}
	}
}

//----- (004347F0) --------------------------------------------------------
BOOL __cdecl sub_4347F0(char *a1, int a2)
{
	if (a2 <= 256)
	{
		sub_435120(&byte_5D4594[3803308], a1);
		sub_4353F0();
		sub_435040();
		sub_434F00();
	}
	return sub_48BDE0();
}

//----- (004348C0) --------------------------------------------------------
int sub_4348C0()
{
#ifdef USE_SDL
    // FIXME 8-bit support
    return 0;
#else
	int result; // eax
	PALETTEENTRY v1[256]; // [esp+0h] [ebp-400h]

	if (!g_ddraw_palette)
		return 0;
	sub_4350E0(v1, &byte_5D4594[3803308]);
	if (g_ddraw_palette->lpVtbl->SetEntries(g_ddraw_palette, 0, 0, 256, v1))
	{
		return 0;
	}
	sub_4354F0();
	result = 1;
	*(_DWORD *)&byte_5D4594[3804660] = 1;
	return result;
#endif
}

//----- (00434FB0) --------------------------------------------------------
int sub_434FB0()
{
#ifdef USE_SDL
    // FIXME 8-bit support
    return 1;
#else
	PALETTEENTRY v1[256]; // [esp+0h] [ebp-400h]

	g_ddraw_palette = 0;
	if (byte_5D4594[3801772] & 4 || *(_DWORD *)&byte_5D4594[3799624])
        return 1;

	sub_4350E0(v1, &byte_5D4594[3803308]);
	if (g_ddraw->lpVtbl->CreatePalette(g_ddraw, 68, v1, &g_ddraw_palette, 0))
		return 0;
	if (g_frontbuffer->lpVtbl->SetPalette(g_frontbuffer, g_ddraw_palette))
        return 0;
    return 1;
#endif
}

//----- (004352E0) --------------------------------------------------------
void __cdecl sub_4352E0()
{
#ifdef USE_SDL
    // FIXME gamma control
#else
	DDCAPS v0; // [esp+4h] [ebp-2F8h]
	DDCAPS v1; // [esp+180h] [ebp-17Ch]

	if (g_ddraw)
	{
		memset(&v0, 0, 0x17Cu);
		memset(&v1, 0, 0x17Cu);
		v0.dwSize = 380;
		v1.dwSize = 380;
		if (!g_ddraw->lpVtbl->GetCaps(g_ddraw, &v0, &v1)
			&& (v0.dwCaps2 & DDCAPS2_PRIMARYGAMMA || v1.dwCaps2 & DDCAPS2_PRIMARYGAMMA))
		{
			g_frontbuffer->lpVtbl->QueryInterface(g_frontbuffer, &IID_IDirectDrawGammaControl, &g_ddraw_gamma_control);
		}
	}
#endif
}

//----- (00444F90) --------------------------------------------------------
HDC sub_444F90()
{
    DebugBreak();

#if 0
	HDC result; // eax
	HDC v1; // [esp+8h] [ebp-4h]

	result = 0;
	v1 = 0;
	if (g_frontbuffer)
	{
		g_frontbuffer->lpVtbl->GetDC(g_frontbuffer, &v1);
		result = v1;
	}
	return result;
#endif
}

//----- (00444FC0) --------------------------------------------------------
void __cdecl sub_444FC0(HDC a1)
{
    DebugBreak();

#if 0
	if (g_frontbuffer)
	{
		if (a1)
			g_frontbuffer->lpVtbl->ReleaseDC(g_frontbuffer, a1);
	}
#endif
}

//----- (004353C0) --------------------------------------------------------
void sub_4353C0()
{
#ifdef USE_SDL
    // FIXME 8-bit support
#else
	HDC v0; // esi

	v0 = GetDC(0);
	GetSystemPaletteEntries(v0, 0, 0x100u, (LPPALETTEENTRY)&byte_587000[84412]);
	return ReleaseDC(0, v0);
#endif
}

//----- (004353F0) --------------------------------------------------------
void sub_4353F0()
{
#ifdef USE_SDL
    // FIXME 8-bit support
#else
	char *v1; // eax
	int v2; // ecx
	HDC v3; // esi
	HPALETTE v4; // eax
	HPALETTE v5; // ebp
	HPALETTE v6; // eax
	int i; // eax
	unsigned __int8 v8; // cl
	unsigned __int8 v9; // dl
	char plpal[1028]; // [esp+8h] [ebp-404h]

	*(_WORD *)plpal = 768;
	*(_WORD *)&plpal[2] = 256;
	memset(&plpal[4], 0, 0x400u);
	if (!*(_DWORD *)&byte_5D4594[3799624] && byte_5D4594[3801772] & 0x10)
	{
		sub_435550();
		v1 = &plpal[5];
		v2 = 256;
		do
		{
			*(v1 - 1) = 0;
			*v1 = 0;
			v1[1] = 0;
			v1[2] = 4;
			v1 += 4;
			--v2;
		} while (v2);
		v3 = GetDC(0);
		v4 = CreatePalette((const LOGPALETTE *)plpal);
		if (v4)
		{
			v5 = SelectPalette(v3, v4, 0);
			RealizePalette(v3);
			v6 = SelectPalette(v3, v5, 0);
			DeleteObject(v6);
		}
		GetSystemPaletteEntries(v3, 0, 0x100u, (LPPALETTEENTRY)&plpal[4]);
		ReleaseDC(0, v3);
		for (i = 0; i < 944; i += 4)
		{
			v8 = byte_5D4594[i + 3803349];
			plpal[i + 44] = byte_5D4594[i + 3803348];
			v9 = byte_5D4594[i + 3803350];
			plpal[i + 45] = v8;
			plpal[i + 46] = v9;
			plpal[i + 47] = 4;
		}
		
		*(_DWORD *)&byte_5D4594[809596] = CreatePalette((const LOGPALETTE *)plpal);
	}
#endif
}

//----- (004354F0) --------------------------------------------------------
void sub_4354F0()
{
#ifdef USE_SDL
    // FIXME 8-bit support
#else
	HDC v1; // esi

	if (!*(_DWORD *)&byte_5D4594[3799624] && byte_5D4594[3801772] & 0x10)
	{
		if (*(_DWORD *)&byte_5D4594[809596])
		{
			v1 = GetDC(dword_973FE0);
			SelectPalette(v1, *(HPALETTE *)&byte_5D4594[809596], 0);
			RealizePalette(v1);
			ReleaseDC(dword_973FE0, v1);
		}
	}
#endif
}

//----- (00435550) --------------------------------------------------------
void sub_435550()
{
#ifdef USE_SDL
    // FIXME 8-bit support
#else
	if (*(_DWORD *)&byte_5D4594[809596])
	{
		DeleteObject(*(HGDIOBJ *)&byte_5D4594[809596]);
		*(_DWORD *)&byte_5D4594[809596] = 0;
	}
#endif
}

//----- (00433C20) --------------------------------------------------------
void sub_433C20()
{
	sub_48A7F0();
#ifdef USE_SDL
#else
	sub_435380(&g_ddraw_gamma_control);
	sub_4353A0(&g_ddraw_palette);
#endif
	if (*(_DWORD *)&byte_5D4594[810640])
	{
		free(*(LPVOID *)&byte_5D4594[810640]);
		*(_DWORD *)&byte_5D4594[810640] = 0;
	}
	if (*(_DWORD *)&byte_5D4594[3804668])
	{
		free(*(LPVOID *)&byte_5D4594[3804668]);
		*(_DWORD *)&byte_5D4594[3804668] = 0;
	}
	if (*(_DWORD *)&byte_5D4594[3804672])
	{
		free(*(LPVOID *)&byte_5D4594[3804672]);
		*(_DWORD *)&byte_5D4594[3804672] = 0;
	}
	if (*(_DWORD *)&byte_5D4594[3804656])
	{
		free(*(LPVOID *)&byte_5D4594[3804656]);
		*(_DWORD *)&byte_5D4594[3804656] = 0;
	}
	if (*(_DWORD *)&byte_5D4594[3804664])
	{
		free(*(LPVOID *)&byte_5D4594[3804664]);
		*(_DWORD *)&byte_5D4594[3804664] = 0;
	}
	sub_435550();
	*(_DWORD *)&byte_5D4594[3804660] = 0;
}

//----- (00444930) --------------------------------------------------------
int __cdecl sub_444930(HWND a1, int a2, int a3, int a4, int a5)
{
	int result; // eax

	*(_DWORD *)&byte_5D4594[823776] = 0;
	*(_DWORD *)&byte_5D4594[3799572] = &byte_5D4594[3799660];
	result = sub_4449D0(a1, a2, a3, a4, a5);
    printf("%s: %d\n", __FUNCTION__, result);
	if (result)
	{
		*(_DWORD *)&byte_5D4594[3799572] = &byte_5D4594[3800716];
		qmemcpy(&byte_5D4594[3800716], &byte_5D4594[3799660], 0x420u);
		if (byte_5D4594[3801773] & 2)
		{
#ifdef USE_SDL
            // FIXME
#else
			ShowWindow(dword_973FE0, SW_MINIMIZE);
			PostMessageA(dword_973FE0, WM_ACTIVATEAPP, 0, 0);
#endif
		}
		result = 1;
		*(_DWORD *)&byte_5D4594[823776] = 1;
		++*(_DWORD *)&byte_5D4594[823772];
	}
	return result;
}

//----- (00444C50) --------------------------------------------------------
void sub_444C50()
{
	if (*(_DWORD *)&byte_5D4594[823776])
	{
		sub_48B350();
		nullsub_6();
		sub_486110();
		nullsub_19();
		nullsub_3();
		nullsub_14();
		sub_433C20();
		nullsub_15();
		sub_48A120();
		sub_44D9D0();
		sub_4B0660();
		nullsub_13();
		nullsub_11();
		nullsub_18();
		sub_4AF950();
		nullsub_17();
		sub_4AE540();
		nullsub_12();
		sub_43F2E0();
		nullsub_16();
		sub_49F4D0();
		dword_973FE0 = 0;
		*(_DWORD *)&byte_5D4594[823776] = 0;
		if (*(_DWORD *)&byte_5D4594[823780])
		{
			DeleteCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
			*(_DWORD *)&byte_5D4594[823780] = 0;
		}
	}
}

//----- (0048C110) --------------------------------------------------------
void sub_48C110()
{
	RECT Rect; // [esp+0h] [ebp-10h]

#ifdef USE_SDL
    *(_DWORD *)&byte_5D4594[1193684] = *(_DWORD *)&byte_5D4594[3801784];
    *(_DWORD *)&byte_5D4594[1193688] = *(_DWORD *)&byte_5D4594[3801788];
#else
	if (byte_5D4594[3801772] & 0x10)
	{
		GetClientRect(dword_973FE0, &Rect);
		*(_DWORD *)&byte_5D4594[1193684] = Rect.right - Rect.left;
		*(_DWORD *)&byte_5D4594[1193688] = Rect.bottom - Rect.top;
	}
	else
	{
		*(_DWORD *)&byte_5D4594[1193684] = *(_DWORD *)&byte_5D4594[3801784];
		*(_DWORD *)&byte_5D4594[1193688] = *(_DWORD *)&byte_5D4594[3801788];
	}
#endif
}

#ifndef USE_SDL
//----- (0048C940) --------------------------------------------------------
int __cdecl sub_48C940(LPCSTR lpText)
{
	if (g_ddraw)
		g_ddraw->lpVtbl->FlipToGDISurface(g_ddraw);
	ClipCursor(0);
	ShowCursor(1);
	return MessageBoxA(dword_973FE0, lpText, "NOX", 0x42010u);
}
#endif

//----- (004AD100) --------------------------------------------------------
int sub_4AD100()
{
	if (byte_5D4594[3801772] & 0x40)
		dword_714204 = sub_4AD180;
	else
		sub_4AD150();
	*(_DWORD *)&byte_5D4594[3798652] = 0;
	return 1;
}

//----- (004AD150) --------------------------------------------------------
void sub_4AD150()
{
	dword_714204 = sub_4AD2A0;
	if (!(byte_5D4594[3801772] & 0x20))
		dword_714204 = sub_4AD1E0;
}

void sub_4AD170(void)
{
	dword_714204();
}

//----- (004AD180) --------------------------------------------------------
void sub_4AD180()
{
    DebugBreak();

#if 0
	int result; // eax
	DDBLTFX v1; // [esp+4h] [ebp-64h]

	memset(&v1, 0, sizeof(v1));
	v1.dwSize = 100;
	v1.dwROP = SRCCOPY;
	result = g_backbuffer1->lpVtbl->Blt(g_backbuffer1, 0, dword_973C88, 0, 0, &v1);
	if (!result)
	{
		sub_4861A0();
		result = sub_48A5E0();
	}
	return result;
#endif
}

//----- (004AD1E0) --------------------------------------------------------
void sub_4AD1E0()
{
	int result; // eax
	_WORD *v1; // edi
	int v2; // edx
	_WORD **v3; // ebp
	_WORD *v4; // esi
	int v5; // ecx
	int v6; // ebx
	int v7; // ebx
	int v8; // ebx
	int v9; // ebx

	if (!dword_973C70)
	{
#ifdef USE_SDL
        result = SDL_LockSurface(g_backbuffer1);
        v1 = g_backbuffer1->pixels;
#else
        DDSURFACEDESC v11; // [esp+Ch] [ebp-70h]
		v11.dwSize = sizeof(v11);
		v11.dwFlags = 0;
		result = g_backbuffer1->lpVtbl->Lock(g_backbuffer1, 0, &v11, 1, 0);
        v1 = v11.lpSurface;
#endif
		if (!result)
		{
			v2 = *(_DWORD *)&byte_5D4594[3801788];
			v3 = *(_WORD ***)&byte_5D4594[3798784];
            while (v2 > 0)
			{
				v4 = *v3;
				v5 = *(_DWORD *)&byte_5D4594[3801800];
                while (v5 > 0)
                {
                    int i;
                    for ( i = 0 ; i < 16 ; i++ )
                        *v1++ = *v4++ << 1;
                    v5--;
                }
                //memcpy(v1, v4, v5 * 32);
                //v1 = (_DWORD *)((char *)v1 + v5 * 32);
				v1 = (_WORD *)((char *)v1 + dword_974868);
				++v3;
                v2--;
            }
#ifdef USE_SDL
            SDL_UnlockSurface(g_backbuffer1);
#else
			g_backbuffer1->lpVtbl->Unlock(g_backbuffer1, v11.lpSurface);
#endif
			++*(_DWORD *)&byte_5D4594[3798652];
		}
	}
}

//----- (004AD2A0) --------------------------------------------------------
void sub_4AD2A0()
{
	int result; // eax
	_DWORD *v1; // edi
	int v2; // edx
	_DWORD **v3; // ebp
	_DWORD *v4; // esi
	int v5; // ecx
	int v6; // ebx
	int v7; // ebx
	int v8; // ebx
	int v9; // ebx
	bool v10; // cc

    // FIXME unlocked surfaces

	if (!dword_973C70)
	{
		v1 = *(_DWORD **)&byte_5D4594[3798752];
		v2 = *(_DWORD *)&byte_5D4594[3801788];
		v3 = *(_DWORD ***)&byte_5D4594[3798784];
		do
		{
			v4 = *v3;
			v5 = *(_DWORD *)&byte_5D4594[3801800];
			do
			{
				v6 = v4[1];
				*v1 = *v4;
				v1[1] = v6;
				v7 = v4[3];
				v1[2] = v4[2];
				v1[3] = v7;
				v8 = v4[5];
				v1[4] = v4[4];
				v1[5] = v8;
				result = v4[6];
				v9 = v4[7];
				v1[6] = result;
				v1[7] = v9;
				v4 += 8;
				v1 += 8;
				v10 = v5-- <= 1;
			} while (!v10);
			++v3;
			v1 = (_DWORD *)((char *)v1 + dword_974868);
			v10 = v2-- <= 1;
		} while (!v10);
		++*(_DWORD *)&byte_5D4594[3798652];
	}
}

//----- (00486090) --------------------------------------------------------
int sub_486090()
{
	int result; // eax

	result = sub_4861D0();
	if (result)
	{
		result = sub_486230();
		if (result)
		{
			if (!(byte_5D4594[3801772] & 0x40)
				|| (result = sub_48A5D0(), (dword_973C88 = result) != 0)
				&& (result = sub_48A5D0(), (dword_973C60 = result) != 0))
			{
				result = 1;
			}
		}
	}
	return result;
}

//----- (0048A5E0) --------------------------------------------------------
int sub_48A5E0()
{
	int result; // eax

	result = dword_973C88;
	dword_973C88 = dword_973C60;
	dword_973C60 = result;
	return result;
}

//----- (0048A3D0) --------------------------------------------------------
int sub_48A3D0()
{
#ifdef USE_SDL
    int width, height, pitch;

	*(_DWORD *)&byte_5D4594[3801780] = 2;
	*(_DWORD *)&byte_5D4594[3801796] = 0;
	if (g_backbuffer1)
	{
        *(_DWORD *)&byte_5D4594[3801784] = g_backbuffer1->w;
        *(_DWORD *)&byte_5D4594[3801788] = g_backbuffer1->h;
        *(_DWORD *)&byte_5D4594[3799564] = g_backbuffer1->pitch;
        *(_DWORD *)&byte_5D4594[3801796] = 1;
        sub_48A190();
        if (g_format == SDL_PIXELFORMAT_RGBA5551 || g_format == SDL_PIXELFORMAT_RGB565)
        {
            *(_DWORD *)&byte_5D4594[3801800] = g_backbuffer1->w >> 4;
            *(_DWORD *)&byte_5D4594[3801776] = g_backbuffer1->w >> 1;
            *(_DWORD *)&byte_5D4594[3801780] = 1;
            *(_DWORD *)&byte_5D4594[3801808] = 2 * g_backbuffer1->w;
            dword_974868 = g_backbuffer1->pitch - 2 * g_backbuffer1->w;

            if (g_format == SDL_PIXELFORMAT_RGBA5551)
                *(_DWORD *)&byte_5D4594[3799624] = 1;
            else if (g_format == SDL_PIXELFORMAT_RGB565)
                *(_DWORD *)&byte_5D4594[3799624] = 2;
            return 1;
        }
    }
    return 0;
#else
	int result; // eax
	int v1; // eax
	int v2; // ecx
	int v3; // edx
	int v4; // esi
	int v5; // ecx
	unsigned int v6; // eax
	int v7; // esi
	unsigned int v8; // eax
	int i; // edx
	unsigned int v10; // eax
	int j; // ecx
	DDSURFACEDESC v12; // [esp+4h] [ebp-6Ch]

	*(_DWORD *)&byte_5D4594[3801780] = 2;
	*(_DWORD *)&byte_5D4594[3801796] = 0;
	if (g_backbuffer1)
	{
		if (g_backbuffer1->lpVtbl->IsLost(g_backbuffer1))
		{
			result = sub_48A2A0();
			if (!result)
				return result;
		}
		v12.dwSize = 108;
		v12.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PITCH | DDSD_CKDESTBLT;
		if (!g_backbuffer1->lpVtbl->GetSurfaceDesc(g_backbuffer1, &v12))
		{
			v1 = v12.dwWidth;
			v2 = v12.lPitch;
			*(_DWORD *)&byte_5D4594[3801788] = v12.dwHeight;
			*(_DWORD *)&byte_5D4594[3801784] = v12.dwWidth;
			*(_DWORD *)&byte_5D4594[3799564] = v12.lPitch;
			dword_973C64 = v12.ddsCaps.dwCaps & DDSCAPS_FLIP;
			if (v12.ddsCaps.dwCaps & DDSCAPS_FLIP)
			{
				*(_DWORD *)&byte_5D4594[3801796] = 1;
				sub_48A190();
				v1 = *(_DWORD *)&byte_5D4594[3801784];
				v2 = *(_DWORD *)&byte_5D4594[3799564];
			}
			else
			{
				*(_DWORD *)&byte_5D4594[3801796] = 0;
				dword_6F7BA0 = sub_48ABC0;
				*(_DWORD *)&byte_5D4594[3801772] &= 0xFFFFFFDF;
			}
			if (v12.ddpfPixelFormat.dwRGBBitCount == 16)
			{
				v3 = 2 * v1;
				v4 = v1;
				v5 = v2 - 2 * v1;
				*(_DWORD *)&byte_5D4594[3801800] = v1 >> 4;
				v6 = v12.ddpfPixelFormat.dwRBitMask;
				*(_DWORD *)&byte_5D4594[3801776] = v4 >> 1;
				v7 = 0;
				*(_DWORD *)&byte_5D4594[3801780] = 1;
				*(_DWORD *)&byte_5D4594[3801808] = v3;
				for (dword_974868 = v5; v6; v6 >>= 1)
				{
					if (v6 & 1)
						++v7;
				}
				v8 = v12.ddpfPixelFormat.dwGBitMask;
				for (i = 0; v8; v8 >>= 1)
				{
					if (v8 & 1)
						++i;
				}
				v10 = v12.ddpfPixelFormat.dwBBitMask;
				for (j = 0; v10; v10 >>= 1)
				{
					if (v10 & 1)
						++j;
				}
				if (v7 != 5)
					return 1;
				if (i == 5)
				{
					if (j == 5)
						*(_DWORD *)&byte_5D4594[3799624] = 1;
					return 1;
				}
				if (i != 6 || j != 5)
					return 1;
				*(_DWORD *)&byte_5D4594[3799624] = 2;
				return 1;
			}
			if (v12.ddpfPixelFormat.dwRGBBitCount == 8)
			{
				*(_DWORD *)&byte_5D4594[3801780] = 0;
				*(_DWORD *)&byte_5D4594[3801776] = v1 >> 2;
				*(_DWORD *)&byte_5D4594[3799624] = 0;
				*(_DWORD *)&byte_5D4594[3801808] = v1;
				*(_DWORD *)&byte_5D4594[3801800] = v1 >> 5;
				dword_974868 = v2 - v1;
				return 1;
			}
		}
		if (*(_DWORD *)&byte_5D4594[3801780] != 2)
			return 1;
	}
	if (!(byte_5D4594[3801772] & 4))
	{
		if (byte_5D4594[3801772] & 0x10)
		{
			sub_48C940("Unsupported windowed video mode detected\r\n\r\nPlease change your desktop to 16 bit color");
			return 0;
		}
		sub_48C940("Unsupported video mode\r\n\r\nPlease select either 16 bit color or 256 colors");
	}
	return 0;
#endif
}

//----- (0048BF70) --------------------------------------------------------
int sub_48BF70()
{
	int result; // eax
	int v1; // [esp+0h] [ebp-18h]
	int v2; // [esp+4h] [ebp-14h]
	int4 a1; // [esp+8h] [ebp-10h]

	g_cursor_surf = sub_48A600(128, 128, DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT, DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY);
	if (g_cursor_surf)
	{
		if (sub_48A720(g_cursor_surf, &v2, &v1, &dword_6F7BF8, &dword_6F7C74))
		{
			result = 0;
		}
		else if (dword_6F7C74)
		{
			a1.field_0 = 0;
			a1.field_4 = 0;
			a1.field_8 = 128;
			a1.field_C = 128;
			sub_48C170(&a1, &a1);
			dword_6F7C48 = sub_48A600(a1.field_8, a1.field_C, DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT, DDSCAPS_VIDEOMEMORY);
			if (dword_6F7C48)
			{
				if (sub_48A720(dword_6F7C48, &v2, &v1, 0, &dword_6F7C78))
					result = 0;
				else
					result = dword_6F7C78 != 0;
			}
			else
			{
				result = 0;
			}
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (0048B3F0) --------------------------------------------------------
int __cdecl sub_48B3F0(int a1, int a2, int a3)
{
	int i; // esi

	if (*(_DWORD *)&byte_5D4594[3798724])
	{
		EnterCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
		*(_DWORD *)&byte_5D4594[1193640] = *(_DWORD *)&byte_5D4594[1193648];
		*(_DWORD *)&byte_5D4594[1193628] = *(_DWORD *)&byte_5D4594[1193524];
		*(_DWORD *)&byte_5D4594[1193648] = a2;
		*(_DWORD *)&byte_5D4594[1193524] = a3;
		if (a1 && a1 != *(_DWORD *)&byte_5D4594[1193624])
		{
			*(_DWORD *)&byte_5D4594[1193624] = a1;
			sub_48A670(g_cursor_surf);
			for (i = 0; i < 512; i += 4)
				sub_49D1C0(*(_DWORD *)(i + *(_DWORD *)&byte_5D4594[1193704]), *(int *)&byte_5D4594[1193592], 128);
			a3 = 0;
			a2 = 0;
			if (sub_48C0C0(a1, &a2, &a3))
			{
				dword_6F7C10(a1, a2, a3);
				*(_DWORD *)&byte_5D4594[1193580] = a2;
				*(_DWORD *)&byte_5D4594[1193600] = *(_DWORD *)&byte_5D4594[1193568];
				*(_DWORD *)&byte_5D4594[1193620] = *(_DWORD *)&byte_5D4594[1193576];
				*(_DWORD *)&byte_5D4594[1193636] = a3;
				*(_DWORD *)&byte_5D4594[1193604] = 0;
				*(_DWORD *)&byte_5D4594[1193608] = 0;
				*(_DWORD *)&byte_5D4594[1193612] = *(_DWORD *)&byte_5D4594[1193568];
				*(_DWORD *)&byte_5D4594[1193616] = *(_DWORD *)&byte_5D4594[1193576];
				*(_DWORD *)&byte_5D4594[1193664] = 1;
			}
			sub_48A6B0(g_cursor_surf);
		}
		if (*(_DWORD *)&byte_5D4594[1193648] != *(_DWORD *)&byte_5D4594[1193640]
			|| *(_DWORD *)&byte_5D4594[1193524] != *(_DWORD *)&byte_5D4594[1193628])
		{
			*(_DWORD *)&byte_5D4594[1193668] = 1;
		}
		LeaveCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
	}
	else if (*(_DWORD *)&byte_5D4594[1193672] && a1)
	{
		sub_47D2C0(a1, a2, a3);
		return 1;
	}
	return 1;
}

//----- (0048BDE0) --------------------------------------------------------
BOOL sub_48BDE0()
{
	int v0; // eax

	v0 = sub_4344A0(255, 0, 255);
	*(_DWORD *)&byte_5D4594[1193592] = v0;
	if (g_cursor_surf)
	{
#if USE_SDL
        // FIXME use SDL_MapRGB instead?
		v0 = *(_DWORD *)&byte_5D4594[3799624] ? (unsigned __int16)v0 : (unsigned __int8)v0;
        SDL_SetColorKey(g_cursor_surf, SDL_TRUE, v0);
#else
        DDCOLORKEY v2; // [esp+0h] [ebp-8h]

		v0 = *(_DWORD *)&byte_5D4594[3799624] ? (unsigned __int16)v0 : (unsigned __int8)v0;
		v2.dwColorSpaceHighValue = v0;
		v2.dwColorSpaceLowValue = v0;
		if (g_cursor_surf->lpVtbl->SetColorKey(g_cursor_surf, DDCKEY_SRCBLT, &v2))
            return 0;
#endif
	}
    return 1;
}

//----- (0048C060) --------------------------------------------------------
int sub_48C060()
{
	int result; // eax
	int v1; // ecx
	int v2; // edx

	if (g_cursor_surf && dword_6F7C74)
	{
		result = (int)malloc(0x200u);
		*(_DWORD *)&byte_5D4594[1193704] = result;
		if (!result)
			return result;
		v1 = dword_6F7C74;
		v2 = 0;
		while (1)
		{
			*(_DWORD *)(v2 + result) = v1;
			v2 += 4;
			v1 += dword_6F7BF8;
			if (v2 >= 512)
				break;
			result = *(_DWORD *)&byte_5D4594[1193704];
		}
	}
	return 1;
}

//----- (0048B350) --------------------------------------------------------
LPVOID sub_48B350()
{
	LPVOID result; // eax

	*(_DWORD *)&byte_5D4594[1193660] = 0;
	*(_DWORD *)&byte_5D4594[1193680] = 0;
	if (*(_DWORD *)&byte_5D4594[1193656])
	{
		*(_DWORD *)&byte_5D4594[1193676] = 1;
		WaitForSingleObject(*(HANDLE *)&byte_5D4594[1193656], 0x108u);
		CloseHandle(*(HANDLE *)&byte_5D4594[1193656]);
		*(_DWORD *)&byte_5D4594[1193656] = 0;
	}
#ifdef USE_SDL
    sub_48B1D0(&g_cursor_surf);
    sub_48B1D0(&dword_6F7C48);
#else
	if ( g_cursor_surf )
	{
		g_cursor_surf->lpVtbl->Release(g_cursor_surf);
		g_cursor_surf = 0;
	}
	if ( dword_6F7C48 )
	{
		dword_6F7C48->lpVtbl->Release(dword_6F7C48);
		dword_6F7C48 = 0;
	}
#endif
	result = *(LPVOID *)&byte_5D4594[1193704];
	if (*(_DWORD *)&byte_5D4594[1193704])
	{
		free(*(LPVOID *)&byte_5D4594[1193704]);
		*(_DWORD *)&byte_5D4594[1193704] = 0;
	}
	*(_DWORD *)&byte_5D4594[1193624] = 0;
	return result;
}

#ifdef USE_SDL
#else
//----- (00435380) --------------------------------------------------------
void __cdecl sub_435380(LPDIRECTDRAWGAMMACONTROL *a1)
{
	if (*a1)
	{
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}

//----- (004353A0) --------------------------------------------------------
void __cdecl sub_4353A0(LPDIRECTDRAWPALETTE *a1)
{
	if (*a1)
	{
		(*a1)->lpVtbl->Release(*a1);
		*a1 = 0;
	}
}
#endif

//----- (004338D0) --------------------------------------------------------
int sub_4338D0()
{
	unsigned __int8 *v0; // esi
	int result; // eax
	pixel888 v2[256]; // [esp+Ch] [ebp-300h]

	switch (*(_DWORD *)&byte_5D4594[3799624])
	{
	case 0:
		dword_69A014 = sub_435180;
		dword_975240 = sub_435240;
		goto LABEL_7;
	case 1:
		dword_69A014 = sub_4351C0;
		dword_975240 = sub_435280;
	LABEL_7:
		dword_975380 = sub_434E80;
		v0 = &byte_581450[9176];
		goto LABEL_8;
	case 2:
		dword_69A014 = sub_435200;
		dword_975240 = sub_435280;
		dword_975380 = sub_434EC0;
		v0 = &byte_581450[9336];
	LABEL_8:
		qmemcpy(&byte_5D4594[3804364], v0, 0xA0u);
		break;
	}
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 52) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 56) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 68) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 96) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 100) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 104) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 176) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 180) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 184) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 216) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 220) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 224) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 232) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 236) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 240) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 244) = 0;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 1036) = 255;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 1040) = 16711935;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 1044) = 16711935;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 1048) = 0;
	sub_434990(25, 25, 25);
	result = sub_434CC0();
	if (result)
	{
		result = sub_434DA0();
		if (result)
		{
			if (!*(_DWORD *)&byte_5D4594[823772])
				sub_4353C0();
			*(_DWORD *)&byte_5D4594[809596] = 0;
			*(_DWORD *)&byte_5D4594[808568] = 0;
			*(_DWORD *)&byte_5D4594[810628] = 0;
			if (*(_DWORD *)&byte_5D4594[823772])
			{
				sub_435150(v2, (char *)&byte_5D4594[3803308]);
				sub_4347F0((char *)v2, 256);
			}
			else
			{
				sub_4347F0((char *)&byte_581450[8404], 256);
			}
			result = sub_434FB0();
			if (result)
			{
				sub_4340A0(0, 0, 0, 255);
				sub_4340A0(1, 0, 255, 0);
				sub_4340A0(2, 0, 255, 255);
				sub_4340A0(3, 255, 0, 0);
				sub_4340A0(4, 255, 0, 255);
				sub_4340A0(5, 255, 255, 0);
				sub_4340A0(6, 255, 255, 255);
				sub_4340A0(7, 0, 0, 0);
				sub_4340A0(8, 0, 0, 128);
				sub_4340A0(9, 0, 128, 0);
				sub_4340A0(10, 0, 128, 128);
				sub_4340A0(11, 128, 0, 0);
				sub_4340A0(12, 128, 0, 128);
				sub_4340A0(13, 128, 128, 0);
				sub_4340A0(14, 128, 128, 128);
				sub_4340A0(15, 0, 0, 0);
#ifdef USE_SDL
                // TODO gamma control
#else
				g_ddraw_gamma_control = 0;
#endif
				*(_DWORD *)&byte_5D4594[808564] = 0;
				sub_4348C0();
				sub_4352E0();
				*(_DWORD *)&byte_5D4594[3804660] = 0;
				result = 1;
			}
		}
	}
	return result;
}

//----- (00433CD0) --------------------------------------------------------
int __cdecl sub_433CD0(BYTE a1, BYTE a2, BYTE a3)
{
	__int64 v5; // rax
	unsigned __int64 v6; // rax
	unsigned __int64 v7; // rax
	int result; // eax

	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 96) = a1;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 100) = a2;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 104) = a3;
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 64) = a1 == 0xFF && a2 == 0xFF && a3 == 0xFF;
	if (*(_DWORD *)&byte_5D4594[3801804])
	{
		v5 = a1 | (a1 << 16);
		v5 <<= 16;
		LODWORD(v5) = a1 | (unsigned int)v5;
		v5 <<= 16;
		*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 72) = a1 | (unsigned int)v5;
		*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 76) = HIDWORD(v5);
		v6 = (a2 | ((a2 | ((unsigned __int64)a2 << 16)) << 16)) << 16;
		*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 80) = a2 | (unsigned int)v6;
		*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 84) = HIDWORD(v6);
		v7 = (a3 | ((a3 | ((unsigned __int64)a3 << 16)) << 16)) << 16;
		*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 88) = a3 | (unsigned int)v7;
		*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 92) = HIDWORD(v7);
	}
	result = dword_975380(a1, a2, a3);
	*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 1032) = result;
	return result;
}

//----- (00433E40) --------------------------------------------------------
int __cdecl sub_433E40(int a1)
{
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return sub_433CD0(v3, v2, a1);
}

//----- (00433ED0) --------------------------------------------------------
int __cdecl sub_433ED0(int a1)
{
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return sub_433E80(v3, v2, a1);
}

//----- (00434040) --------------------------------------------------------
int __cdecl sub_434040(int a1)
{
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return sub_433F10(v3, v2, a1);
}

//----- (004341D0) --------------------------------------------------------
int __cdecl sub_4341D0(int a1, int a2)
{
	int result; // eax
	int v3; // edi
	int v4; // esi
	int v5; // ecx
	unsigned __int64 v6; // rax
	unsigned __int64 v7; // rax
	__int64 v8; // kr10_8
	unsigned __int64 v9; // rax
	int v10; // [esp+8h] [ebp-4h]

	result = a1;
	if (a1 >= 0 && a1 < 16)
	{
		v3 = a2;
		v4 = 48 * a1 + *(_DWORD *)&byte_5D4594[3799572] + 264;
		result = *(_DWORD *)(48 * a1 + *(_DWORD *)&byte_5D4594[3799572] + 304);
		if (a2 != result)
		{
			dword_975240(a2, &a1, &a2, &v10);
			*(_DWORD *)(v4 + 24) = (unsigned __int8)a1;
			*(_DWORD *)(v4 + 28) = (unsigned __int8)a2;
			v5 = (unsigned __int8)v10;
			*(_DWORD *)(v4 + 40) = v3;
			*(_DWORD *)(v4 + 32) = v5;
			result = *(_DWORD *)&byte_5D4594[3801804];
			if (*(_DWORD *)&byte_5D4594[3801804])
			{
				v6 = (unsigned __int64)((unsigned __int8)a1 | ((unsigned __int8)a1 << 16)) << 16;
				LODWORD(v6) = (unsigned __int8)a1 | (unsigned int)v6;
				*(_QWORD *)v4 = (unsigned __int8)a1 | (v6 << 16);
				v7 = (unsigned __int64)((unsigned __int8)a2 | ((unsigned __int8)a2 << 16)) << 16;
				LODWORD(v7) = (unsigned __int8)a2 | (unsigned int)v7;
				*(_QWORD *)(v4 + 8) = (unsigned __int8)a2 | (v7 << 16);
				v8 = (unsigned __int8)v10;
				v9 = (unsigned __int64)((unsigned __int8)v10 | ((unsigned __int8)v10 << 16)) << 16;
				LODWORD(v9) = (unsigned __int8)v10 | (unsigned int)v9;
				v9 <<= 16;
				result = (unsigned __int8)v10 | (unsigned int)v9;
				*(_DWORD *)(v4 + 16) = result;
				*(_DWORD *)(v4 + 20) = HIDWORD(v8) | HIDWORD(v9);
			}
		}
	}
	return result;
}

//----- (00434320) --------------------------------------------------------
void sub_434320(int a1, int a2, int a3)
{
	if (dword_69A014)
		dword_69A014(a1, a2, a3, (DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 232));
}

//----- (004343B0) --------------------------------------------------------
void sub_4343B0(int a1, int a2, int a3)
{
	if (dword_69A014)
		dword_69A014(a1, a2, a3, (DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 236));
}

//----- (00434400) --------------------------------------------------------
void sub_434400(int a1, int a2, int a3)
{
	if (dword_69A014)
		dword_69A014(a1, a2, a3, (DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 240));
}

//----- (00434430) --------------------------------------------------------
void sub_434430(int a1, int a2, int a3)
{
	if (dword_69A014)
		dword_69A014(a1, a2, a3, (DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 244));
}

//----- (00434480) --------------------------------------------------------
void __cdecl sub_434480(int a1, int a2, int a3, int a4)
{
	dword_975240(a1, a2, a3, a4);
}

//----- (004344A0) --------------------------------------------------------
int __cdecl sub_4344A0(int a1, int a2, int a3)
{
	int result; // eax
	int v4; // [esp+0h] [ebp-4h]

	result = 0;
	v4 = 0;
	if (dword_69A014)
	{
		dword_69A014(a1, a2, a3, (DWORD *)&v4);
		result = v4;
	}
	return result;
}

//----- (00434AA0) --------------------------------------------------------
int __cdecl sub_434AA0(int a1, int a2, int a3)
{
	return dword_975380(a1, a2, a3);
}

//----- (00434AC0) --------------------------------------------------------
int __cdecl sub_434AC0(int a1)
{
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	dword_975240(a1, &v3, &v2, &a1);
	return dword_975380(v3, v2, a1);
}

//----- (00434B00) --------------------------------------------------------
int sub_434B00()
{
	int result; // eax

	result = *(_DWORD *)&byte_587000[84400];
	if (*(int *)&byte_587000[84400] >= 1)
	{
		if (*(int *)&byte_587000[84400] > 10)
		{
			result = 10;
			*(_DWORD *)&byte_587000[84400] = 10;
		}
	}
	else
	{
		result = 1;
		*(_DWORD *)&byte_587000[84400] = 1;
	}
	return result;
}

//----- (00434B30) --------------------------------------------------------
int __cdecl sub_434B30(int a1)
{
	int result; // eax

	result = a1;
	if (a1 >= 1)
	{
		if (a1 > 10)
			result = 10;
		*(_DWORD *)&byte_587000[84400] = result;
	}
	else
	{
		result = 1;
		*(_DWORD *)&byte_587000[84400] = 1;
	}
	return result;
}

//----- (00434B60) --------------------------------------------------------
BOOL sub_434B60()
{
	int v0; // ebp
	pixel888 *v1; // edi
	int v2; // ebx
	char *v3; // esi
	__int64 v4; // rax
	unsigned __int8 *v5; // eax
	int v6; // ecx
	int v7; // edi
	char v8; // dl
	int v9; // ecx
	char v10; // dl
	int v11; // ecx
	int v13; // [esp+10h] [ebp-90Ch]
	char v14[1536];
	pixel888 v19[256]; // [esp+61Ch] [ebp-300h]

	v0 = *(_DWORD *)&byte_587000[84400];
	v1 = v19;
	if (*(int *)&byte_587000[84400] < 1)
	{
		v0 = 1;
	LABEL_5:
		*(_DWORD *)&byte_587000[84400] = v0;
		goto LABEL_6;
	}
	if (*(_DWORD *)&byte_587000[84400] > 10)
	{
		v0 = 10;
		goto LABEL_5;
	}
LABEL_6:
	v2 = 0;
	v3 = &v14[512];
	v13 = 0;
	do
	{
		if (v0 == 1)
			LOWORD(v4) = (_WORD)v2 << 8;
		else
			v4 = (__int64)(pow((double)v13 * 0.00392156862745098, 1.0 / ((double)(v0 - 1) * 0.1666666666666667 + 1.0)) * 65535.0);
		*((_WORD *)v3 + 256) = v4;
		*(_WORD *)v3 = v4;
		*((_WORD *)v3 - 256) = v4;
		++v2;
		v3 += 2;
		v13 = v2;
	} while (v2 < 256);
#ifdef USE_SDL
    // FIXME gamma control
#else
	if (*(_DWORD *)&byte_5D4594[3799624])
		return g_ddraw_gamma_control && !g_ddraw_gamma_control->lpVtbl->SetGammaRamp(g_ddraw_gamma_control, 0, &v14);
	sub_434920();
	v5 = &byte_5D4594[808573];
	do
	{
		v6 = *(v5 - 1);
		v7 = (int)&v1->field_1;
		v5 += 4;
		v8 = v14[2 * v6 + 1];
		v9 = *(v5 - 4);
		*(_BYTE *)(v7++ - 1) = v8;
		v10 = v14[2 * v9 + 513];
		v11 = *(v5 - 3);
		*(_BYTE *)(v7 - 1) = v10;
		v1 = (pixel888 *)(v7 + 1);
		v1[-1].field_2 = v14[2 * v11 + 1025];
	} while ((int)v5 < (int)&byte_5D4594[809597]);
	sub_4347F0((char *)v19, 256);
	sub_4348C0();
	return 1;
#endif
}
// 434B60: using guessed type char var_8FF[511];
// 434B60: using guessed type char var_6FF[512];
// 434B60: using guessed type char var_4FF[511];

//----- (00434CC0) --------------------------------------------------------
int sub_434CC0()
{
	int v0; // edi
	int result; // eax
	int i; // esi
	int v3; // [esp+4h] [ebp-4h]

	if (!*(_DWORD *)&byte_5D4594[3801780])
	{
		v0 = dword_69A014;
		dword_69A014 = sub_4351C0;
	}
	result = (int)calloc(0x101u, 2u);
	*(_DWORD *)&byte_5D4594[3804672] = result;
	if (result)
	{
		result = (int)calloc(0x101u, 2u);
		*(_DWORD *)&byte_5D4594[3804656] = result;
		if (result)
		{
			result = (int)calloc(0x101u, 2u);
			*(_DWORD *)&byte_5D4594[3804664] = result;
			if (result)
			{
				for (i = 0; i < 256; ++i)
				{
					*(_WORD *)(*(_DWORD *)&byte_5D4594[3804672] + 2 * i) = sub_4344A0(i, 0, 0);
					*(_WORD *)(*(_DWORD *)&byte_5D4594[3804656] + 2 * i) = sub_4344A0(0, i, 0);
					*(_WORD *)(*(_DWORD *)&byte_5D4594[3804664] + 2 * i) = sub_4344A0(0, 0, i);
				}
				if (!*(_DWORD *)&byte_5D4594[3801780])
					dword_69A014 = v0;
				result = 1;
			}
		}
	}
	return result;
}
// 434CDD: variable 'v3' is possibly undefined

//----- (004B0300) --------------------------------------------------------
int __cdecl sub_4B0300(char *a1)
{
	int result; // eax

	result = *(_DWORD *)&byte_5D4594[1311928];
	if (*(int *)&byte_5D4594[1311928] < 2)
	{
		strncpy((char *)&byte_5D4594[260 * *(_DWORD *)&byte_5D4594[1311928] + 1311940], a1, 0x104u);
		result = ++*(_DWORD *)&byte_5D4594[1311928];
	}
	return result;
}

//----- (004B0340) --------------------------------------------------------
int __cdecl sub_4B0340(int a1)
{
	BOOL v1; // esi
	int v2; // ebp
	int v3; // edi
	int v4; // ebx
	int result; // eax
	unsigned __int8 *v6; // esi
	int v7; // [esp+10h] [ebp-44h]
	int v8; // [esp+14h] [ebp-40h]
	int v9; // [esp+18h] [ebp-3Ch]
	int v10; // [esp+1Ch] [ebp-38h]
	int v11; // [esp+20h] [ebp-34h]
	int v12; // [esp+24h] [ebp-30h]
	int v13[11]; // [esp+28h] [ebp-2Ch]

	*(_DWORD *)&byte_5D4594[1311936] = 1;
	*(_DWORD *)&byte_5D4594[1311932] = a1;
#ifdef USE_SDL
    // FIXME
    v1 = 0;
#else
	v1 = (GetAsyncKeyState(VK_SHIFT) & 0x8000u) != 0;
#endif
	if ((*(_WORD *)&byte_5D4594[2650636] & 0x200) == 512 || v1 || byte_5D4594[3801772] & 0x10)
		goto LABEL_23;
	sub_431290();
	sub_43DBD0();
	sub_44D8F0();
	while (sub_43DC40() || sub_44D930())
		sub_4312C0();
	sub_43E8E0();
	v12 = sub_48B3E0(0);
	sub_47D8B0();
	sub_48A7F0();
	v2 = *(_DWORD *)&byte_5D4594[3801780];
	if (*(_DWORD *)&byte_5D4594[3801780])
	{
		v3 = a1;
		v4 = a1;
	LABEL_13:
#ifdef USE_SDL
        // FIXME movie support
#else
		v13[1] = *(_DWORD *)&byte_5D4594[823784];
		v13[0] = dword_973FE0;
		v13[4] = g_backbuffer1;
		v13[2] = g_ddraw;
		v13[5] = *(_DWORD *)&byte_5D4594[3798780];
		v13[6] = *(_DWORD *)&byte_5D4594[3798780];
		v13[3] = g_frontbuffer;
		v13[7] = *(_DWORD *)&byte_5D4594[3801784];
		v13[8] = *(_DWORD *)&byte_5D4594[3801788];
		v13[9] = 1;
		if (*(_DWORD *)&byte_5D4594[1311928])
		{
			v6 = &byte_5D4594[1311940];
			do
			{
				v13[10] = (int)v6;
				v6 += 260;
				sub_555430((HWND *)v13);
				--*(_DWORD *)&byte_5D4594[1311928];
			} while (*(_DWORD *)&byte_5D4594[1311928]);
		}
#endif
		if (!v2)
		{
			sub_486110();
			sub_48A120();
			*(_DWORD *)&byte_5D4594[3801772] = v4;
			result = sub_48A040(v3, v8, v7, a1);
			if (!result)
				return result;
			result = sub_486090();
			if (!result)
				return result;
			result = sub_4338D0();
			if (!result)
				return result;
			result = sub_48B1F0();
			if (!result)
				return result;
			sub_48B3F0(v11, v10, v9);
		}
		sub_43E910();
		sub_43DBE0();
		sub_47D8C0();
		sub_48B3E0(v12);
	LABEL_23:
		sub_4B05D0();
		return 1;
	}
	sub_48B590(&v11, &v10, &v9);
	v2 = *(_DWORD *)&byte_5D4594[3801780];
	v3 = dword_973FE0;
	v4 = *(_DWORD *)&byte_5D4594[3801772];
	v8 = *(_DWORD *)&byte_5D4594[3801784];
	v7 = *(_DWORD *)&byte_5D4594[3801788];
	a1 = *(_DWORD *)&byte_5D4594[3799568];
	sub_48B350();
	sub_433C20();
	sub_486110();
	sub_48A120();
	*(_DWORD *)&byte_5D4594[3801772] = v4;
	result = sub_48A040(v3, 640, 480, 16);
	if (result)
	{
		result = sub_486090();
		if (result)
			goto LABEL_13;
	}
	return result;
}
// 4B0536: variable 'v8' is possibly undefined
// 4B0536: variable 'v7' is possibly undefined

//----- (004B05D0) --------------------------------------------------------
void sub_4B05D0()
{
	if (*(_DWORD *)&byte_5D4594[1311936])
	{
		sub_555500(1);
		*(_DWORD *)&byte_5D4594[1311936] = 0;
		*(_DWORD *)&byte_5D4594[1311928] = 0;
		if (*(_DWORD *)&byte_5D4594[1311924])
		{
			sub_440900();
			(*(int(**)(void))&byte_5D4594[1311924])();
		}
	}
}

//----- (004B0640) --------------------------------------------------------
int __cdecl sub_4B0640(int(*a1)(void))
{
	int result; // eax

	result = a1;
	*(_DWORD *)&byte_5D4594[1311924] = a1;
	return result;
}

//----- (0048B5D0) --------------------------------------------------------
int __cdecl sub_48B5D0(int a1, int a2)
{
	int result; // eax
	int v3; // esi

	result = 0;
	if (!*(_DWORD *)&byte_5D4594[1193708]
		&& *(_DWORD *)&byte_5D4594[1193660]
		&& *(_DWORD *)&byte_5D4594[823776]
		&& *(_DWORD *)&byte_5D4594[3798724]
		&& *(_DWORD *)&byte_5D4594[1193672]
		&& *(_DWORD *)&byte_5D4594[1193108]
		&& *(_DWORD *)&byte_5D4594[787144])
	{
		*(_DWORD *)&byte_5D4594[1193708] = 1;
		EnterCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
#ifdef USE_SDL
        // FIXME SDL will always wait for vblank?
#else
		if (a2)
			g_ddraw->lpVtbl->WaitForVerticalBlank(g_ddraw, 1, 0);
#endif
		v3 = dword_6F7BF0(a1);
		LeaveCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[3799596]);
		result = v3;
		*(_DWORD *)&byte_5D4594[1193708] = 0;
	}
	return result;
}

//----- (0048C200) --------------------------------------------------------
unsigned __int8 *__cdecl sub_48C200(int a1, int a2, int a3)
{
	unsigned __int8 *result; // eax
	int v4; // ebp
	unsigned __int8 *v5; // eax
	int v6; // ecx
	int v7; // edi
	int v8; // edx
	int v9; // ebx
	int v10; // esi
	void(*v11)(void); // edi
	int v12; // edi
	int v13; // ecx
	int v14; // ebx
	int v15; // edi
	int v16; // esi
	int v17; // ecx
	unsigned __int8 *v18; // eax
	int v19; // edx
	int v20; // ecx
	void(*v21)(void); // [esp+14h] [ebp+4h]
	int v22; // [esp+18h] [ebp+8h]
	int v23; // [esp+1Ch] [ebp+Ch]

	result = (unsigned __int8 *)(*(int(__cdecl **)(_DWORD))&byte_5D4594[3799492])(a1);
	*(_DWORD *)&byte_5D4594[1193516] = result;
	if (result)
	{
		v4 = *(_DWORD *)result;
		v5 = result + 4;
		*(_DWORD *)&byte_5D4594[1193516] = v5;
		v6 = *(_DWORD *)v5;
		v5 += 4;
		*(_DWORD *)&byte_5D4594[1193516] = v5;
		v7 = *(_DWORD *)v5;
		v5 += 4;
		*(_DWORD *)&byte_5D4594[1193516] = v5;
		v8 = v7 + a2;
		v9 = *(_DWORD *)v5;
		result = v5 + 5;
		v10 = v9 + a3;
		*(_DWORD *)&byte_5D4594[1193568] = v4;
		*(_DWORD *)&byte_5D4594[1193576] = v6;
		*(_DWORD *)&byte_5D4594[1193516] = result;
		v11 = dword_6F7C34;
		if (!*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 60))
			v11 = dword_6F7C40;
		v21 = v11;
		v12 = v6;
		v13 = v6 - 1;
		if (v12)
		{
			v23 = 2 * v8;
			v14 = 4 * v10;
			v22 = v13 + 1;
			do
			{
				v14 += 4;
				v15 = v4;
				v16 = v23 + *(_DWORD *)(v14 + *(_DWORD *)&byte_5D4594[1193704] - 4);
				for (*(_DWORD *)&byte_5D4594[1193584] = v23 + *(_DWORD *)(v14 + *(_DWORD *)&byte_5D4594[1193704] - 4);
					v15 > 0;
					v15 -= v19)
				{
					v17 = *result;
					v18 = result + 1;
					*(_DWORD *)&byte_5D4594[1193588] = v17;
					*(_DWORD *)&byte_5D4594[1193516] = v18;
					v19 = *v18;
					result = v18 + 1;
					v20 = (v17 & 0xF) - 1;
					*(_DWORD *)&byte_5D4594[1193520] = v19;
					*(_DWORD *)&byte_5D4594[1193516] = result;
					if (v20)
					{
						if (v20 == 1)
						{
							v21();
							result = *(unsigned __int8 **)&byte_5D4594[1193516];
							v16 = *(_DWORD *)&byte_5D4594[1193584];
							v19 = *(_DWORD *)&byte_5D4594[1193520];
						}
					}
					else
					{
						v16 += 2 * v19;
						*(_DWORD *)&byte_5D4594[1193584] = v16;
					}
				}
				--v22;
			} while (v22);
		}
	}
	return result;
}

//----- (0048C320) --------------------------------------------------------
unsigned __int8 *__cdecl sub_48C320(int a1, int a2, int a3)
{
	unsigned __int8 *result; // eax
	int v4; // edi
	unsigned __int8 *v5; // eax
	int v6; // ecx
	int v7; // esi
	int v8; // ebx
	int v9; // ebp
	void(*v10)(void); // esi
	int v11; // esi
	int v12; // ecx
	int v13; // ebp
	int v14; // esi
	int v15; // ecx
	unsigned __int8 *v16; // eax
	int v17; // edx
	int v18; // ecx
	void(*v19)(void); // [esp+14h] [ebp+4h]
	int v20; // [esp+18h] [ebp+8h]

	result = (unsigned __int8 *)(*(int(__cdecl **)(_DWORD))&byte_5D4594[3799492])(a1);
	*(_DWORD *)&byte_5D4594[1193516] = result;
	if (result)
	{
		v4 = *(_DWORD *)result;
		v5 = result + 4;
		*(_DWORD *)&byte_5D4594[1193516] = v5;
		v6 = *(_DWORD *)v5;
		v5 += 4;
		*(_DWORD *)&byte_5D4594[1193516] = v5;
		v7 = *(_DWORD *)v5;
		v5 += 4;
		*(_DWORD *)&byte_5D4594[1193516] = v5;
		v8 = v7 + a2;
		v9 = *(_DWORD *)v5;
		result = v5 + 5;
		*(_DWORD *)&byte_5D4594[1193568] = v4;
		*(_DWORD *)&byte_5D4594[1193576] = v6;
		*(_DWORD *)&byte_5D4594[1193516] = result;
		v10 = dword_6F7C34;
		if (!*(_DWORD *)(*(_DWORD *)&byte_5D4594[3799572] + 60))
			v10 = dword_6F7C40;
		v19 = v10;
		v11 = v6;
		v12 = v6 - 1;
		if (v11)
		{
			v13 = 4 * (v9 + a3);
			v20 = v12 + 1;
			do
			{
				v13 += 4;
				v14 = v4;
				for (*(_DWORD *)&byte_5D4594[1193584] = v8 + *(_DWORD *)(*(_DWORD *)&byte_5D4594[1193704] + v13 - 4);
					v14 > 0;
					v14 -= v17)
				{
					v15 = *result;
					v16 = result + 1;
					*(_DWORD *)&byte_5D4594[1193588] = v15;
					*(_DWORD *)&byte_5D4594[1193516] = v16;
					v17 = *v16;
					result = v16 + 1;
					v18 = (v15 & 0xF) - 1;
					*(_DWORD *)&byte_5D4594[1193520] = v17;
					*(_DWORD *)&byte_5D4594[1193516] = result;
					if (v18)
					{
						if (v18 == 1)
						{
							v19();
							result = *(unsigned __int8 **)&byte_5D4594[1193516];
							v17 = *(_DWORD *)&byte_5D4594[1193520];
						}
					}
					else
					{
						*(_DWORD *)&byte_5D4594[1193584] += v17;
					}
				}
				--v20;
			} while (v20);
		}
	}
	return result;
}
#endif
