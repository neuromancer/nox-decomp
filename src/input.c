#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

#include "proto.h"

#ifdef USE_SDL
#include "sdl2_scancode_to_dinput.h"

enum
{
    MOUSE_MOTION,
    MOUSE_BUTTON0,
    MOUSE_BUTTON1,
    MOUSE_BUTTON2,
};

struct keyboard_event
{
    BYTE code;
    BYTE state;
    DWORD seq;
};

struct mouse_event
{
    unsigned int type;
    int x, y, z;
    DWORD state;
    DWORD seq;
};

struct finger_state
{
    SDL_FingerID id;
    unsigned int timestamp;
    float x, y;
};

extern int g_rotated;
float input_sensitivity = 1.0;
static struct keyboard_event keyboard_event_queue[256];
static DWORD keyboard_event_ridx;
static DWORD keyboard_event_widx;
static struct mouse_event mouse_event_queue[256];
static DWORD mouse_event_ridx;
static DWORD mouse_event_widx;
static struct finger_state fingers[8];
static int mouse0_state;
static int mouse1_state;
static int seqnum;
static int orientation;
static int move_speed;
static int jump;

void process_keyboard_event(const SDL_KeyboardEvent *event)
{
    struct keyboard_event *ke = &keyboard_event_queue[keyboard_event_widx];

    ke->code = scanCodeToKeyNum[event->keysym.scancode];
    ke->state = event->state == SDL_PRESSED;
    ke->seq = seqnum++;

    keyboard_event_widx = (keyboard_event_widx + 1) % 256;
}

void process_mouse_event(const SDL_MouseButtonEvent *event)
{
    struct mouse_event *me = &mouse_event_queue[mouse_event_widx];

    switch (event->button)
    {
    case SDL_BUTTON_LEFT:
        me->type = MOUSE_BUTTON0;
        break;
    case SDL_BUTTON_RIGHT:
        me->type = MOUSE_BUTTON1;
        break;
    case SDL_BUTTON_MIDDLE:
        me->type = MOUSE_BUTTON2;
        break;
    default:
        return;
    }

    me->state = event->state == SDL_PRESSED;
    me->seq = seqnum++;

    mouse_event_widx = (mouse_event_widx + 1) % 256;
}

void process_motion_event(const SDL_MouseMotionEvent *event)
{
    struct mouse_event *me = &mouse_event_queue[mouse_event_widx];

    me->type = MOUSE_MOTION;
    me->x = input_sensitivity * event->xrel;
    me->y = input_sensitivity * event->yrel;
    me->z = 0;
    me->seq = seqnum++;

    mouse_event_widx = (mouse_event_widx + 1) % 256;
}

void process_wheel_event(const SDL_MouseWheelEvent *event)
{
    struct mouse_event *me = &mouse_event_queue[mouse_event_widx];

    me->type = MOUSE_MOTION;
    me->x = 0;
    me->y = 0;
    me->z = event->y;
    me->seq = seqnum++;

    mouse_event_widx = (mouse_event_widx + 1) % 256;
}

void fake_keyup(void *arg)
{
    struct keyboard_event *ke = &keyboard_event_queue[keyboard_event_widx];
    ke->code = scanCodeToKeyNum[SDL_SCANCODE_SPACE];
    ke->state = 0;
    ke->seq = seqnum++;
    keyboard_event_widx = (keyboard_event_widx + 1) % 256;
}

void fake_mouseup(void *arg)
{
    struct mouse_event *me = &mouse_event_queue[mouse_event_widx];
    me->type = MOUSE_BUTTON0;
    me->state = 0;
    me->seq = seqnum++;
    mouse_event_widx = (mouse_event_widx + 1) % 256;
}

struct finger_state *find_finger(SDL_FingerID id, int alloc)
{
    int i;
    for (i = 0; i < sizeof(fingers) / sizeof(fingers[0]); i++)
    {
        if (fingers[i].id == id)
            return &fingers[i];

        if (alloc && fingers[i].id == 0)
        {
            fingers[i].id = id;
            return &fingers[i];
        }
    }
    return NULL;
}

void send_mouse1_event()
{
    struct mouse_event *me = &mouse_event_queue[mouse_event_widx];
    me->type = MOUSE_BUTTON1;
    me->state = mouse1_state;// && !mouse0_state;
    me->seq = seqnum++;
    mouse_event_widx = (mouse_event_widx + 1) % 256;
}

#ifdef __EMSCRIPTEN__
void process_touch_event(SDL_TouchFingerEvent *event)
{
    if (g_rotated)
    {
        float tmp = event->x;
        event->x = 1.0 - event->y;
        event->y = tmp;

        tmp = event->dx;
        event->dx = -event->dy;
        event->dy = tmp;
    }

    if (event->type == SDL_FINGERDOWN)
    {
        struct finger_state *finger = find_finger(event->fingerId, 1);
        finger->timestamp = event->timestamp;
        finger->x = event->x;
        finger->y = event->y;

        if (finger->x < 0.5)
        {
            mouse1_state = 1;
            //send_mouse1_event();
        }
        else
        {
            mouse0_state = 1;
            //send_mouse1_event();
        }
        #if 0
        else if (finger->y < 0.25)
        {
            struct keyboard_event *ke = &keyboard_event_queue[keyboard_event_widx];
            ke->code = scanCodeToKeyNum[SDL_SCANCODE_SPACE];
            ke->state = 1;
            ke->seq = event->timestamp;
            keyboard_event_widx = (keyboard_event_widx + 1) % 256;
        }
        else
        {
            struct mouse_event *me = &mouse_event_queue[mouse_event_widx];
            me->type = MOUSE_BUTTON0;
            me->state = 1;
            me->seq = event->timestamp;
            mouse_event_widx = (mouse_event_widx + 1) % 256;
        }
        #endif
    }
    else if (event->type == SDL_FINGERUP)
    {
        unsigned int ms;
        float dist, theta;
        struct finger_state *finger = find_finger(event->fingerId, 0);
        if (!finger)
            return;

        dist = sqrtf((event->x - finger->x) * (event->x - finger->x) + (event->y - finger->y) * (event->y - finger->y));
        theta = atan2f(-event->y + finger->y, -event->x + finger->x) / M_PI;
        ms = event->timestamp - finger->timestamp;

        if (finger->x < 0.5)
        {
            mouse1_state = 0;
            //send_mouse1_event();

            move_speed = 0;

            if (ms < 250 && dist > 0.1)
                jump = 1;

            printf("%d\n", event->timestamp - finger->timestamp);
        }
        else
        {
            mouse0_state = 0;
            //send_mouse1_event();

            if (ms < 500 && dist > 0.1 && theta <= 0.7 && theta >= 0.3)
            {
                struct keyboard_event *ke = &keyboard_event_queue[keyboard_event_widx];
                ke->code = scanCodeToKeyNum[SDL_SCANCODE_SPACE];
                ke->state = 1;
                ke->seq = seqnum++;
                keyboard_event_widx = (keyboard_event_widx + 1) % 256;

                emscripten_set_timeout(fake_keyup, 90, NULL);
            }
            else
            {
                struct mouse_event *me = &mouse_event_queue[mouse_event_widx];
                me->type = MOUSE_BUTTON0;
                me->state = 1;
                me->seq = seqnum++;
                mouse_event_widx = (mouse_event_widx + 1) % 256;

                emscripten_set_timeout(fake_mouseup, 90, NULL);
            }
        }

        printf("up dist=%4d, theta=%4d\n", (int)(dist * 1000), (int)(theta * 1000));

        memset(finger, 0, sizeof(*finger));
    }
    else
    {
        unsigned int ms;
        float dist, theta;
        struct finger_state *finger = find_finger(event->fingerId, 0);
        if (!finger)
            return;

        dist = sqrtf((event->x - finger->x) * (event->x - finger->x) + (event->y - finger->y) * (event->y - finger->y));
        theta = atan2f(-event->y + finger->y, -event->x + finger->x) / M_PI;
        ms = event->timestamp - finger->timestamp;

        if (finger->x < 0.5)
        {
            dist = sqrtf((event->x - 0.1) * (event->x - 0.1) + (event->y - 0.5) * (event->y - 0.5));
            theta = atan2f(-event->y + 0.5, -event->x + 0.1) / M_PI;
        #if 0
            struct mouse_event *me = &mouse_event_queue[mouse_event_widx];
            me->type = MOUSE_MOTION;
            me->x = 2000.0f * event->dx;
            me->y = 2000.0f * event->dy;
            me->z = 0;
            me->seq = seqnum++;
            mouse_event_widx = (mouse_event_widx + 1) % 256;
        #endif
            orientation = ((int)((theta + 1) * 128 + 0.5)) & 255;
            if (dist < 0.05)
                move_speed = 0;
            else
                move_speed = 1;
        }
        else if ((event->timestamp - finger->timestamp) > 200)
        {
            struct mouse_event *me = &mouse_event_queue[mouse_event_widx];
            me->type = MOUSE_MOTION;
            me->x = 2000.0f * event->dx;
            me->y = 2000.0f * event->dy;
            me->z = 0;
            me->seq = seqnum++;
            mouse_event_widx = (mouse_event_widx + 1) % 256;
        }
    }
}
#endif

// init keyboard
void sub_47FB10()
{
    keyboard_event_ridx = 0;
    keyboard_event_widx = 0;

    // On non-IME languages, Nox uses this input for text input. This sets up
    // current SHIFT state and the mapping from DIK code -> wide character.
	*(_DWORD *)&byte_5D4594[1193132] = (SDL_GetModState() & (KMOD_LSHIFT | KMOD_RSHIFT)) != 0;
	sub_47DBD0();
}

// free keyboard
int sub_47FCC0()
{
	return 0;
}

// get keyboard data
void __cdecl sub_47FA80(signed int a1)
{
    struct keyboard_event *ke = &keyboard_event_queue[keyboard_event_ridx];

	*(_BYTE *)a1 = 0;
	*(_DWORD *)(a1 + 4) = 0;

    if (keyboard_event_ridx == keyboard_event_widx)
        return;

    *(_BYTE *)a1 = ke->code;
    *(_BYTE *)(a1 + 1) = ke->state + 1;
    *(_BYTE *)(a1 + 2) = 0;
    *(_DWORD *)(a1 + 4) = ke->seq;

    keyboard_event_ridx = (keyboard_event_ridx + 1) % 256;
}

// init mouse
int sub_47D8D0()
{
    SDL_SetRelativeMouseMode(SDL_TRUE);
    mouse_event_ridx = 0;
    mouse_event_widx = 0;

    // indicates that mouse is present so cursor should be drawn
	*(_DWORD *)&byte_5D4594[1193108] = 1;
    return 1;
}

// acquire mouse
int sub_47D8C0()
{
    SDL_SetRelativeMouseMode(SDL_TRUE);
	return 0;
}

// unacquire mouse
int sub_47D8B0()
{
    SDL_SetRelativeMouseMode(SDL_FALSE);
	return 0;
}

// get mouse data
char __cdecl sub_47DB20(signed int *a1)
{
    struct mouse_event *me = &mouse_event_queue[mouse_event_ridx];

	a1[0] = 0;
	a1[1] = 0;
	a1[2] = 0;
	a1[5] = 0;
	a1[7] = 0;
	a1[8] = 0;
	a1[10] = 0;
	a1[11] = 0;
	a1[13] = 0;

    if (mouse_event_ridx == mouse_event_widx)
        return 0;

    switch (me->type)
    {
    case MOUSE_MOTION:
        a1[0] = me->x;
        a1[1] = me->y;
        a1[2] = me->z;
        break;
    case MOUSE_BUTTON0:
        a1[5] = me->state;
        a1[7] = me->seq;
        break;
    case MOUSE_BUTTON1:
        a1[8] = me->state;
        a1[10] = me->seq;
        break;
    case MOUSE_BUTTON2:
        a1[11] = me->state;
        a1[13] = me->seq;
        break;
    }

    mouse_event_ridx = (mouse_event_ridx + 1) % 256;
    return 1;
}

// init joystick
UINT __cdecl sub_47D660(UINT uJoyID, int a2)
{
	return 0;
}

#else

void __cdecl sub_47DA70(_DWORD *a1, LPDIDEVICEOBJECTDATA a2);

LPDIRECTINPUTA g_dinput_keyboard;
LPDIRECTINPUTDEVICEA g_device_keyboard;

LPDIRECTINPUTA g_dinput_mouse;
LPDIRECTINPUTDEVICEA g_device_mouse;

//----- (0047D8B0) --------------------------------------------------------
int sub_47D8B0()
{
	return g_device_mouse->lpVtbl->Unacquire(g_device_mouse);
}

//----- (0047D8C0) --------------------------------------------------------
int sub_47D8C0()
{
	return g_device_mouse->lpVtbl->Acquire(g_device_mouse);
}

//----- (0047D8D0) --------------------------------------------------------
signed int sub_47D8D0()
{
	wchar_t *v0; // eax
	DIPROPDWORD v4; // [esp+20h] [ebp-2Ch]
	DIDEVCAPS_DX3 v9;

	if (DirectInputCreateA(*(HINSTANCE *)&byte_5D4594[823784], 0x300u, &g_dinput_mouse, 0) < 0)
	{
		v0 = sub_40F1D0("Dxinput.c:IM_CreateFailed", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 73);
		sub_4516C0(v0);
	}
	if (g_dinput_mouse->lpVtbl->CreateDevice(g_dinput_mouse, &GUID_SysMouse, &g_device_mouse, 0) < 0)
	{
		v0 = sub_40F1D0("Dxinput.c:IM_CreateDeviceFailed", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 87);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->SetCooperativeLevel(g_device_mouse, sub_401FD0(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) < 0)
	{
		v0 = sub_40F1D0("Dxinput.c:IM_SetCoopFailed", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 105);
		sub_4516C0(v0);
	}
	v4.diph.dwSize = 20;
	v4.diph.dwHeaderSize = 16;
	v4.diph.dwObj = 0;
	v4.diph.dwHow = 0;
	v4.dwData = 256;
	if (g_device_mouse->lpVtbl->SetProperty(g_device_mouse, DIPROP_BUFFERSIZE, (LPCDIPROPHEADER)&v4) < 0)
	{
		v0 = sub_40F1D0("Dxinput.c:IM_SetPropertyFailed", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 123);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->SetDataFormat(g_device_mouse, &c_dfDIMouse) < 0)
	{
		v0 = sub_40F1D0("Dxinput.c:IM_SetFormatFailed", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 135);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->Acquire(g_device_mouse) < 0)
	{
		v0 = sub_40F1D0("Dxinput.c:IM_AquireFailed", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 147);
		sub_4516C0(v0);
	}
	v9.dwSize = 24;
	if (g_device_mouse->lpVtbl->GetCapabilities(g_device_mouse, (LPDIDEVCAPS)&v9) >= 0)
		byte_5D4594[1193128] = v9.dwButtons;
	*(_DWORD *)&byte_5D4594[1193108] = 1;
	sub_42EBB0(2, sub_47D890, 0, "DXInput");
	sub_42EBB0(1, sub_47D8A0, 0, "DXInput");
	return 1;
}
// 47D890: using guessed type int sub_47D890();

//----- (0047DA70) --------------------------------------------------------
void __cdecl sub_47DA70(_DWORD *a1, LPDIDEVICEOBJECTDATA a2)
{
	switch (a2->dwOfs)
	{
	case DIMOFS_X:
		*a1 = a2->dwData;
		break;
	case DIMOFS_Y:
		a1[1] = a2->dwData;
		break;
	case DIMOFS_Z:
		a1[2] = a2->dwData;
		break;
	case DIMOFS_BUTTON0:
		a1[5] = (a2->dwData >> 7) & 1;
		a1[7] = a2->dwSequence;
		break;
	case DIMOFS_BUTTON1:
		a1[8] = (a2->dwData >> 7) & 1;
		a1[10] = a2->dwSequence;
		break;
	case DIMOFS_BUTTON2:
		a1[11] = (a2->dwData >> 7) & 1;
		a1[13] = a2->dwSequence;
		break;
	default:
		return;
	}
}

//----- (0047DB20) --------------------------------------------------------
char __cdecl sub_47DB20(signed int *a1)
{
	HRESULT v2; // eax
	HRESULT v4; // eax
	DIDEVICEOBJECTDATA v5; // [esp+14h] [ebp-10h]
	DWORD dw;

	a1[0] = 0;
	a1[1] = 0;
	a1[2] = 0;
	a1[5] = 0;
	a1[7] = 0;
	a1[8] = 0;
	a1[10] = 0;
	a1[11] = 0;
	a1[13] = 0;

	if (g_device_mouse)
	{
		dw = 1;
		v2 = g_device_mouse->lpVtbl->GetDeviceData(g_device_mouse, 16, &v5, &dw, 0);
		if (v2 == DIERR_NOTACQUIRED || v2 == DIERR_INPUTLOST)
		{
			v4 = g_device_mouse->lpVtbl->Acquire(g_device_mouse);
			if (v4 >= 0 && v4 <= 1)
				return -1;
		}
		else if (!v2 && dw)
		{
			sub_47DA70(a1, &v5);
			return 1;
		}
	}
	return 0;
}

//----- (0047D660) --------------------------------------------------------
UINT __cdecl sub_47D660(UINT uJoyID, int a2)
{
	UINT result; // eax
	UINT v3; // esi
	wchar_t *v4; // eax
	__int64 v5; // rax
	__int64 v6; // [esp+10h] [ebp-3Ch]
	struct joyinfoex_tag pji; // [esp+18h] [ebp-34h]

	result = joyGetNumDevs();
	if (result)
	{
		pji.dwSize = 52;
		pji.dwFlags = 255;
		if (joyGetPosEx(uJoyID, &pji))
		{
			result = 0;
		}
		else
		{
			v3 = 48 * uJoyID;
			*(_DWORD *)&byte_5D4594[v3 + 1189612] = 200;
			*(_DWORD *)&byte_5D4594[v3 + 1189620] = 0;
			*(_DWORD *)&byte_5D4594[v3 + 1189604] = -100;
			*(_DWORD *)&byte_5D4594[v3 + 1189628] = 0;
			*(_DWORD *)&byte_5D4594[v3 + 1189616] = 200;
			*(_DWORD *)&byte_5D4594[v3 + 1189624] = 0;
			*(_DWORD *)&byte_5D4594[v3 + 1189608] = -100;
			*(_DWORD *)&byte_5D4594[v3 + 1189632] = 0;
			if (joyGetDevCapsA(uJoyID, (LPJOYCAPSA)&byte_5D4594[404 * uJoyID + 1189700], 0x194u))
			{
				v4 = sub_40F1D0((char *)&byte_587000[153832], 0, (const char *)&byte_587000[153792], 79);
				sub_4517A0(v4, uJoyID);
				result = 0;
			}
			else
			{
				v6 = *(unsigned int *)&byte_5D4594[404 * uJoyID + 1189748];
				*(_DWORD *)&byte_5D4594[48 * uJoyID + 1189636] = (__int64)(200.0
					/ (double)*(unsigned int *)&byte_5D4594[404 * uJoyID + 1189740]
					* 1000000.0);
				v5 = (__int64)(200.0 / (double)v6 * 1000000.0);
				HIDWORD(v5) = *(_DWORD *)&byte_5D4594[404 * uJoyID + 1189760];
				*(_DWORD *)&byte_5D4594[48 * uJoyID + 1189640] = v5;
				*(_DWORD *)a2 = HIDWORD(v5);
				result = 2;
			}
		}
	}
	return result;
}

//----- (0047D7A0) --------------------------------------------------------
DWORD *__cdecl sub_47D7A0(DWORD *a1, UINT uJoyID)
{
	DWORD *result; // eax
	DWORD v3; // ebx
	DWORD v4; // edi
	struct joyinfoex_tag pji; // [esp+8h] [ebp-34h]

	pji.dwSize = 52;
	pji.dwFlags = 131;
	if (joyGetPosEx(uJoyID, &pji) == 167)
	{
		result = a1;
		a1[2] = 0;
		*a1 = 0;
		a1[1] = 0;
	}
	else
	{
		a1[2] = pji.dwButtons;
		*a1 = *(_DWORD *)&byte_5D4594[48 * uJoyID + 1189636]
			* (pji.dwXpos - *(_DWORD *)&byte_5D4594[404 * uJoyID + 1189736])
			/ 0xF4240;
		v3 = *a1;
		a1[1] = *(_DWORD *)&byte_5D4594[48 * uJoyID + 1189640]
			* (pji.dwYpos - *(_DWORD *)&byte_5D4594[404 * uJoyID + 1189744])
			/ 0xF4240;
		v4 = a1[1];
		*a1 = *(_DWORD *)&byte_5D4594[48 * uJoyID + 1189604] + v3;
		a1[1] = *(_DWORD *)&byte_5D4594[48 * uJoyID + 1189608] + v4;
		if (*(_DWORD *)&byte_5D4594[48 * uJoyID + 1189620])
			*a1 = -*a1;
		result = *(DWORD **)&byte_5D4594[48 * uJoyID + 1189624];
		if (result)
			a1[1] = -a1[1];
	}
	return result;
}

//----- (0047FB10) --------------------------------------------------------
void sub_47FB10()
{
	wchar_t *v0; // eax
	wchar_t *v1; // eax
	wchar_t *v2; // eax
	int v3; // edi
	HWND v4; // eax
	wchar_t *v5; // eax
	wchar_t *v6; // eax
	wchar_t *v7; // eax
	DIPROPDWORD v15; // [esp+24h] [ebp-14h]

	if (DirectInputCreateA(*(HINSTANCE *)&byte_5D4594[823784], 0x300u, &g_dinput_keyboard, 0) < 0)
	{
		v0 = sub_40F1D0("Dxinput.c:OK_CreateFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 827);
		sub_4516C0(v0);
	}

	if (g_dinput_keyboard->lpVtbl->CreateDevice(g_dinput_keyboard, &GUID_SysKeyboard, &g_device_keyboard, NULL) < 0)
	{
		v1 = sub_40F1D0("Dxinput.c:OK_CreateDeviceFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 841);
		sub_4516C0(v1);
	}

	if (g_device_keyboard->lpVtbl->SetDataFormat(g_device_keyboard, &c_dfDIKeyboard) < 0)
	{
		v2 = sub_40F1D0("Dxinput.c:OK_SetFormatFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 853);
		sub_4516C0(v2);
	}

	if (g_device_keyboard->lpVtbl->SetCooperativeLevel(g_device_keyboard, sub_401FD0(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) < 0)
	{
		v5 = sub_40F1D0("Dxinput.c:OK_SetCoopFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 868);
		sub_4516C0(v5);
	}

	v15.diph.dwSize = 20;
	v15.diph.dwHeaderSize = 16;
	v15.diph.dwObj = 0;
	v15.diph.dwHow = 0;
	v15.dwData = 256;
	if (g_device_keyboard->lpVtbl->SetProperty(g_device_keyboard, DIPROP_BUFFERSIZE, &v15) < 0)
	{
		v6 = sub_40F1D0("Dxinput.c:OK_SetPropertyFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 886);
		sub_4516C0(v6);
	}

	if (g_device_keyboard->lpVtbl->Acquire(g_device_keyboard) < 0)
	{
		v7 = sub_40F1D0("Dxinput.c:OK_AquireFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 899);
		sub_4516C0(v7);
	}

	byte_5D4594[1193132] = GetKeyState(20) & 1;
	*(_DWORD *)&byte_5D4594[1193132] = byte_5D4594[1193132];
	sub_47DBD0();
}

//----- (0047FCC0) --------------------------------------------------------
int sub_47FCC0()
{
	g_device_keyboard->lpVtbl->Unacquire(g_device_keyboard);
	return g_dinput_keyboard->lpVtbl->Release(g_dinput_keyboard);
}

//----- (0047FA80) --------------------------------------------------------
void __cdecl sub_47FA80(signed int a1)
{
	HRESULT v2; // eax
	char v3; // al
	char v4; // dl
	HRESULT v5; // eax
	DIDEVICEOBJECTDATA v6; // [esp+14h] [ebp-10h]
	DWORD dw;

	*(_BYTE *)a1 = 0;
	*(_DWORD *)(a1 + 4) = 0;
	if (g_device_keyboard)
	{
		dw = 1;
		v2 = g_device_keyboard->lpVtbl->GetDeviceData(g_device_keyboard, 16, &v6, &dw, 0);
		if (v2 == DIERR_INPUTLOST)
		{
			v5 = g_device_keyboard->lpVtbl->Acquire(g_device_keyboard);
			if (v5 >= 0 && v5 <= 1)
				*(_BYTE *)a1 = -1;
		}
		else if (!v2 && dw)
		{
			*(_BYTE *)a1 = v6.dwOfs; // key code
			*(_BYTE *)(a1 + 1) = (v6.dwData & 0x80 != 0) + 1;
			*(_BYTE *)(a1 + 2) = 0;
			*(_DWORD *)(a1 + 4) = v6.dwSequence;
		}
	}
}

int sub_47D890()
{
	return sub_47D8B0();
}
#endif

//----- (0042D6B0) --------------------------------------------------------
int __cdecl sub_42D6B0(_DWORD *a3, int a4)
{
  int v2; // ebp
  int i; // edi
  int j; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  _DWORD *v16; // esi
  int v17; // ecx
  __int64 v18; // rax
  int v19; // eax
  int v20; // ebp
  int v21; // ebx
  unsigned __int8 *v22; // edx
  int v23; // edx
  int k; // edi
  int v25; // ecx
  unsigned __int8 *v26; // eax
  int v27; // ebp
  int v28; // ebx
  int v29; // edx
  unsigned __int8 *v30; // esi
  int v31; // eax
  unsigned __int8 *v32; // ecx
  int result; // eax
  int v34; // ecx
  int l; // ebp
  int v36; // esi
  int v37; // eax
  int v38; // eax
  int v39; // eax
  wchar_t *v40; // eax
  wchar_t *v41; // [esp-20h] [ebp-28h]
  char v42[2]; // [esp+2h] [ebp-6h]
  int v43; // [esp+4h] [ebp-4h]

  *(_QWORD *)&byte_5D4594[747876] = sub_416BB0();
  if ( sub_40A5C0(1) && sub_40A5C0(0x2000) )
    *(_QWORD *)&byte_5D4594[747876] += sub_42E630();
  v2 = *(_DWORD *)&byte_5D4594[2618908];
  if ( !sub_40A5C0(1) )
    *(_DWORD *)&byte_5D4594[754036] = 0;
  for ( i = a4; i; i = *(_DWORD *)(i + 84) )
  {
    for ( j = 0; j < *(int *)(i + 68); ++j )
    {
      switch ( *(_DWORD *)(i + 4 * j + 36) )
      {
        case 1:
          v9 = sub_477620();
          switch ( v9 )
          {
            case 3:
              v10 = sub_476F90();
              sub_42E850(v10);
              break;
            case 4:
              v11 = sub_476F90();
              if ( *(_BYTE *)(v11 + 280) & 0x10 )
                sub_42E7B0(v11);
              break;
            case 13:
              v12 = sub_476F90();
              sub_42E810(v12);
              break;
            default:
              sub_42E670(6, 0);
              break;
          }
          break;
        case 2:
          if (SDL_GetEventState(SDL_MOUSEBUTTONDOWN))
          {
            v5 = 1;
            if ( byte_5D4594[754064] & 8 )
              v5 = 3;
            sub_42E670(2, v5);
          }
          break;
        case 3:
          v6 = (byte_5D4594[754064] & 1) != 0;
          if ( byte_5D4594[754064] & 8 )
            LOBYTE(v6) = v6 | 2;
          sub_42E670(3, v6);
          break;
        case 4:
          v7 = (byte_5D4594[754064] & 1) != 0;
          if ( byte_5D4594[754064] & 8 )
            LOBYTE(v7) = v7 | 2;
          sub_42E670(4, v7);
          break;
        case 5:
          v8 = (byte_5D4594[754064] & 1) != 0;
          if ( byte_5D4594[754064] & 8 )
            LOBYTE(v8) = v8 | 2;
          sub_42E670(5, v8);
          break;
        case 6:
          sub_42E670(7, 0);
          break;
        case 7:
          sub_42E670(19, 0);
          break;
        case 8:
          sub_42E670(8, 0);
          break;
        case 9:
          if ( !(*(_BYTE *)(v2 + 3680) & 1) )
            sub_42E670(9, 0);
          break;
        case 0xA:
          sub_42E670(10, 0);
          break;
        case 0xB:
          sub_42E670(11, 0);
          break;
        case 0xC:
          if ( !sub_413A50() )
            sub_42E670(12, 0);
          break;
        case 0xD:
          if ( !sub_413A50() )
            sub_42E670(13, 0);
          break;
        case 0xE:
          sub_42E670(14, 0);
          break;
        case 0xF:
          sub_42E670(15, 0);
          break;
        case 0x10:
          sub_42E670(18, 0);
          break;
        case 0x11:
          if ( !sub_45D9C0() )
          {
            v13 = sub_476F40();
            sub_42E780(29, v13);
          }
          break;
        case 0x12:
          if ( !sub_45D9C0() )
            sub_42E780(20, 0);
          break;
        case 0x13:
          if ( !sub_45D9C0() )
            sub_42E780(21, 0);
          break;
        case 0x14:
          if ( !sub_45D9C0() )
            sub_42E780(22, 0);
          break;
        case 0x15:
          if ( !sub_45D9C0() )
            sub_42E780(23, 0);
          break;
        case 0x16:
          if ( !sub_45D9C0() )
            sub_42E780(24, 0);
          break;
        case 0x17:
          if ( !sub_45D9C0() )
            sub_42E780(25, 0);
          break;
        case 0x18:
          if ( !sub_45D9C0() )
            sub_42E780(26, 0);
          break;
        case 0x19:
          if ( !sub_45D9C0() )
            sub_42E780(27, 0);
          break;
        case 0x1A:
          if ( !sub_45D9C0() )
            sub_42E780(28, 0);
          break;
        case 0x1B:
          if ( !sub_45D9C0() )
          {
            v14 = sub_476F40();
            sub_42E780(30, v14);
          }
          break;
        case 0x1C:
          sub_42E780(31, 0);
          break;
        case 0x1D:
          sub_42E780(32, 0);
          break;
        case 0x1E:
          sub_42E780(33, 0);
          break;
        case 0x1F:
          sub_42E780(34, 0);
          break;
        case 0x20:
          sub_42E780(35, 0);
          break;
        case 0x21:
          sub_42E670(36, 0);
          break;
        case 0x22:
          sub_42E670(37, 0);
          break;
        case 0x23:
          sub_42E780(38, 0);
          break;
        case 0x24:
          sub_42E780(39, 0);
          break;
        case 0x25:
          sub_42E780(40, 0);
          break;
        case 0x26:
          sub_42E780(41, 0);
          break;
        case 0x27:
          sub_42E780(42, 0);
          break;
        case 0x28:
          sub_42E780(43, 0);
          break;
        case 0x29:
          sub_42E780(44, 0);
          break;
        case 0x2A:
          sub_42E780(45, 0);
          break;
        case 0x2B:
          sub_42E670(16, 0);
          break;
        case 0x2C:
          sub_42E670(17, 0);
          break;
        case 0x2D:
          sub_42E670(46, 0);
          break;
        case 0x2E:
          if ( sub_40A5C0(0x2000) && sub_4160F0(0x15u, *(unsigned int *)&byte_5D4594[2649704]) )
          {
            sub_4160D0(21);
            sub_42E670(47, 0);
          }
          break;
        case 0x2F:
          if ( sub_40A5C0(0x2000) && sub_4160F0(0x14u, 2 * *(_DWORD *)&byte_5D4594[2649704]) )
          {
            sub_4160D0(20);
            sub_42E670(48, 0);
          }
          break;
        case 0x30:
          if ( sub_40A5C0(0x2000) && sub_4160F0(0x16u, *(unsigned int *)&byte_5D4594[2649704]) )
          {
            sub_4160D0(22);
            sub_42E670(49, 0);
          }
          break;
        case 0x31:
          sub_42E670(50, 0);
          break;
        case 0x32:
          if ( sub_40A5C0(0x2000) )
            sub_42E670(51, 0);
          break;
        case 0x33:
          if ( !sub_413A50() )
            sub_42E670(52, 0);
          break;
        case 0x34:
          sub_42E670(53, 0);
          break;
        case 0x35:
          if ( sub_40A5C0(2048) && !sub_477600() )
            sub_42E670(54, 0);
          break;
        case 0x36:
          if ( sub_40A5C0(2048) && !sub_477600() )
            sub_42E670(55, 0);
          break;
        case 0x37:
          sub_42E670(56, 0);
          break;
        default:
          continue;
      }
    }
  }
#ifdef __EMSCRIPTEN__
  if (!SDL_GetEventState(SDL_MOUSEBUTTONDOWN))
  {
    sub_42E670(1, orientation); 
    if (move_speed)
       sub_42E670(2, 3);
    if (jump)
    {
       sub_42E670(2, 3);
       sub_42E670(7, 0);
       jump = 0;
    }
  }
  else
#endif
  {
    if ( byte_5D4594[747848] != 2 && *(_DWORD *)&byte_5D4594[747868] == 4 )
    {
      v15 = sub_476F80();
      v16 = a3;
      if ( v15 )
        v17 = sub_4739D0(*(_DWORD *)(v15 + 16));
      else
        v17 = a3[1];
      a4 = *v16 - *(int *)&byte_5D4594[3805496] / 2;
      v18 = (__int64)((atan2((double)(v17 - *(int *)&byte_5D4594[3807120] / 2), (double)a4) + 6.2831855) * 40.743664 + 0.5);
      *(_DWORD *)&byte_5D4594[754060] = v18;
      if ( (int)v18 < 0 )
      {
        LODWORD(v18) = ((unsigned int)(255 - v18) >> 8 << 8) + v18;
        *(_DWORD *)&byte_5D4594[754060] = v18;
      }
      if ( (int)v18 >= 256 )
      {
        LODWORD(v18) = -256 * ((unsigned int)v18 >> 8) + v18;
        *(_DWORD *)&byte_5D4594[754060] = v18;
      }
      sub_42E670(1, v18);
    }
    sub_42E670(1, *(int *)&byte_5D4594[754060]);
  }
  if ( byte_5D4594[2661958] )
    sub_45DBB0();
  if ( byte_5D4594[754064] & 4 )
    sub_42E670(28, 0);
  if ( sub_40A5C0(1) )
  {
    v19 = *(_DWORD *)&byte_5D4594[754048];
    v20 = *(_DWORD *)&byte_5D4594[754040];
    v21 = 0;
    if ( *(_DWORD *)&byte_5D4594[754048] == *(_DWORD *)&byte_5D4594[754040] )
      goto LABEL_226;
    v22 = &byte_5D4594[750964];
    do
    {
      qmemcpy(v22, &byte_5D4594[24 * v19 + 747884], 0x18u);
      v19 = (v19 + 1) % 128;
      ++v21;
      v22 += 24;
    }
    while ( v19 != v20 );
    if ( v21 <= 0 )
    {
LABEL_226:
      v23 = *(_DWORD *)&byte_5D4594[754044];
    }
    else
    {
      v23 = v21;
      *(_DWORD *)&byte_5D4594[754048] = v20;
      *(_DWORD *)&byte_5D4594[754044] = v21;
    }
    for ( k = v20; k != *(_DWORD *)&byte_5D4594[754036]; k = (k + 1) % 128 )
    {
      v25 = 0;
      if ( v23 > 0 )
      {
        v26 = &byte_5D4594[750972];
        while ( *(_DWORD *)&byte_5D4594[24 * k + 747892] != *(_DWORD *)v26 )
        {
          ++v25;
          v26 += 24;
          if ( v25 >= v23 )
            goto LABEL_137;
        }
        if ( sub_42D4B0(*(_DWORD *)&byte_5D4594[24 * k + 747892]) )
          *(_DWORD *)&byte_5D4594[24 * k + 747900] = 0;
        v23 = *(_DWORD *)&byte_5D4594[754044];
      }
LABEL_137:
      ;
    }
  }
  else
  {
    v27 = *(_DWORD *)&byte_5D4594[754036];
    v28 = 0;
    if ( *(_DWORD *)&byte_5D4594[754036] > 0 )
    {
      v29 = *(_DWORD *)&byte_5D4594[754044];
      v30 = &byte_5D4594[747900];
      do
      {
        v31 = 0;
        *(_DWORD *)v30 = 1;
        if ( v29 > 0 )
        {
          v32 = &byte_5D4594[750972];
          while ( *((_DWORD *)v30 - 2) != *(_DWORD *)v32 )
          {
            ++v31;
            v32 += 24;
            if ( v31 >= v29 )
              goto LABEL_149;
          }
          if ( sub_42D4B0(*((_DWORD *)v30 - 2)) )
            *(_DWORD *)v30 = 0;
          v27 = *(_DWORD *)&byte_5D4594[754036];
          v29 = *(_DWORD *)&byte_5D4594[754044];
        }
LABEL_149:
        ++v28;
        v30 += 24;
      }
      while ( v28 < v27 );
      if ( v27 > 0 )
        qmemcpy(&byte_5D4594[750964], &byte_5D4594[747884], 4 * ((unsigned int)(24 * v27) >> 2));
    }
    *(_DWORD *)&byte_5D4594[754044] = v27;
  }
  *(_DWORD *)&byte_5D4594[754064] = 0;
  if ( sub_40A5C0(1) )
  {
    result = *(_DWORD *)&byte_5D4594[754040];
    v34 = *(_DWORD *)&byte_5D4594[754036];
    if ( *(_DWORD *)&byte_5D4594[754036] < *(int *)&byte_5D4594[754040] )
      v34 = *(_DWORD *)&byte_5D4594[754036] + 128;
  }
  else
  {
    v34 = *(_DWORD *)&byte_5D4594[754036];
    result = 0;
  }
  v43 = v34;
  for ( l = result; l < v43; ++l )
  {
    v36 = 24 * (l % 128);
    if ( *(_DWORD *)&byte_5D4594[24 * (l % 128) + 747900] )
    {
      switch ( *(_DWORD *)&byte_5D4594[24 * (l % 128) + 747892] )
      {
        case 0x14:
          if ( !sub_40A5C0(128) )
          {
            sub_452D80(186, 100);
            sub_476E00(1);
          }
          break;
        case 0x15:
          if ( !sub_40A5C0(128) )
          {
            sub_452D80(190, 100);
            sub_476E00(6);
          }
          break;
        case 0x16:
          if ( !sub_40A5C0(128) )
          {
            sub_452D80(192, 100);
            sub_476E00(3);
          }
          break;
        case 0x17:
          if ( !sub_40A5C0(128) )
          {
            sub_452D80(188, 100);
            sub_476E00(4);
          }
          break;
        case 0x18:
          if ( !sub_40A5C0(128) )
          {
            sub_452D80(187, 100);
            sub_476E00(2);
          }
          break;
        case 0x19:
          if ( !sub_40A5C0(128) )
          {
            sub_452D80(193, 100);
            sub_476E00(0);
          }
          break;
        case 0x1A:
          if ( !sub_40A5C0(128) )
          {
            sub_452D80(189, 100);
            sub_476E00(7);
          }
          break;
        case 0x1B:
          if ( !sub_40A5C0(128) )
          {
            sub_452D80(191, 100);
            sub_476E00(5);
          }
          break;
        default:
          break;
      }
      v37 = *(_DWORD *)&byte_5D4594[v36 + 747892];
      switch ( v37 )
      {
        case 8:
          sub_46A430(0);
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 9:
          sub_46A430(1);
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 10:
          sub_45AC70();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 11:
          sub_451350();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 12:
          sub_452D80(921, 100);
          sub_4766E0();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 13:
          sub_452D80(921, 100);
          sub_4766F0();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 14:
          sub_452D80(921, 100);
          v38 = sub_434B00();
          sub_434B30(v38 + 1);
          sub_434B60();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 15:
          sub_452D80(921, 100);
          v39 = sub_434B00();
          sub_434B30(v39 - 1);
          sub_434B60();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 16:
          sub_4460C0();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 17:
          if ( sub_450560() )
            sub_46D580();
          else
            sub_42EB90(1);
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 18:
          sub_473610();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 19:
          sub_467C60();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
          sub_45DA50(v37 - 31);
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 36:
          sub_4724E0();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 37:
          sub_472500();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 38:
          sub_4672C0();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 39:
          sub_472220();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 40:
          sub_472240();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 41:
          sub_472260();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 42:
          sub_4604F0();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 43:
          sub_460540();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 44:
          sub_460590();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 45:
          sub_45E040();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 46:
          if ( sub_40A5C0(8) || !sub_40A5C0(0x2000) )
            goto LABEL_211;
          sub_457500();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 47:
          LOWORD(a4) = 739;
          sub_4E53C0(31, &a4, 2, 0, 1);
          break;
        case 48:
          LOWORD(a3) = 483;
          sub_4E53C0(31, &a3, 2, 0, 1);
          break;
        case 49:
          v42[0] = -29;
          v42[1] = 4;
          sub_4E53C0(31, v42, 2, 0, 1);
          break;
        case 50:
          sub_460630();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 51:
          sub_452D80(921, 100);
          sub_4703F0();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 52:
          sub_470A60();
          sub_452D80(921, 100);
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 53:
          if ( *(_DWORD *)&byte_5D4594[2650636] & 0x40000 )
            goto LABEL_211;
          *(_DWORD *)&byte_587000[80828] ^= 1u;
          *(_DWORD *)&byte_587000[80832] = *(_DWORD *)&byte_587000[80828];
          sub_452D80(921, 100);
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 54:
          if ( !sub_40A5C0(2048) )
            goto LABEL_211;
          if ( !sub_4DCCB0() )
            goto LABEL_210;
          sub_452D80(921, 100);
          sub_4DB130((const char *)&byte_587000[80252]);
          sub_4DB170(1, 0, 0);
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        case 55:
          if ( !sub_40A5C0(2048) )
            goto LABEL_211;
          if ( sub_4DCCB0() )
          {
            sub_452D80(921, 100);
            sub_413A00(1);
            v41 = sub_40F1D0((char *)&byte_587000[80304], 0, (const char *)&byte_587000[80264], 1867);
            v40 = sub_40F1D0((char *)&byte_587000[80372], 0, (const char *)&byte_587000[80332], 1866);
            sub_449A10(0, (int)v40, (int)v41, 56, (int (*)(void))sub_42E600, sub_42E620);
            *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          }
          else
          {
LABEL_210:
            sub_452D80(231, 100);
LABEL_211:
            *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          }
          break;
        case 56:
          sub_46DB00();
          *(_DWORD *)&byte_5D4594[v36 + 747900] = 0;
          break;
        default:
          break;
      }
    }
    result = v43;
  }
  return result;
}

