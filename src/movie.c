#include "proto.h"

#ifdef NO_MOVIE
void __cdecl sub_555430(HWND *a1)
{
	return;
}

char __cdecl sub_555500(char a1)
{
	return 0;
}
#else

// byte_5D4594[2513944]
LPDIRECTSOUND g_dsound;
// byte_5D4594[2513948]
LPDIRECTSOUNDBUFFER g_dsound_buffer;

//----- (00555430) --------------------------------------------------------
void __cdecl sub_555430(HWND *a1)
{
	HWND v2; // edi

	if (!a1)
	{
		sub_413B70("No VQ pointer!\n");
		return;
	}
	*(_DWORD *)&byte_5D4594[2514000] = *a1;
	*(_DWORD *)&byte_5D4594[2513996] = a1[1];
	v2 = a1[10];
	sub_413B70("Before Audio_Init\n");
	if (!sub_555520(*(HWND *)&byte_5D4594[2514000]))
	{
		sub_413B70("Failure to initialize audio\n");
		return;
	}
	sub_413B70("Before ShowCursor\n");
	ShowCursor(0);
	sub_413B70("Before Set_Option\n");
	sub_556280(15);
	sub_413B70("Before VQA_Test\n");
	if (v2)
		sub_555C40(a1);
	sub_413B70("Before Reset_Video_System\n");
	sub_555A40();
	ShowCursor(1);
	sub_413B70("Before Audio_Uninit\n");
	sub_5555D0();
}

//----- (00555500) --------------------------------------------------------
char __cdecl sub_555500(char a1)
{
	char result; // al

	result = a1;
	byte_5D4594[2513936] = a1;
	return result;
}

//----- (00555510) --------------------------------------------------------
int sub_555510()
{
	return *(_DWORD *)&byte_5D4594[2513940] | (char)byte_5D4594[2513936];
}

//----- (00555520) --------------------------------------------------------
signed int __cdecl sub_555520(HWND a1)
{
	HRESULT v1; // ebx
	signed int result; // eax

	AIL_lock();
	sub_413B70("Before DirectSoundCreate\n");
	v1 = DirectSoundCreate(0, &g_dsound, 0);
	AIL_unlock();
	if (v1)
	{
		sub_413B70("!! Failure to create a Direct Sound object !!\r\n");
		result = 0;
	}
	else
	{
		sub_413B70("Before SetCooperativeLevel\n");
		AIL_lock();
		if (g_dsound->lpVtbl->SetCooperativeLevel(g_dsound, a1, 1))
		{
			sub_413B70("!! Failure to obtain exclusive use of sound card !!\r\n");
			AIL_lock();
			g_dsound->lpVtbl->Release(g_dsound);
			AIL_unlock();
			g_dsound = 0;
			AIL_unlock();
			result = 0;
		}
		else
		{
			AIL_unlock();
			result = 1;
		}
	}
	return result;
}
// 5813E8: using guessed type _DWORD __stdcall AIL_unlock();
// 5813EC: using guessed type _DWORD __stdcall AIL_lock();

//----- (005555D0) --------------------------------------------------------
void __cdecl sub_5555D0()
{
	if (g_dsound_buffer)
	{
		g_dsound_buffer->lpVtbl->Stop(g_dsound_buffer);
		g_dsound_buffer->lpVtbl->Release(g_dsound_buffer);
		g_dsound_buffer = 0;
	}
	if (g_dsound)
	{
		AIL_lock();
		g_dsound->lpVtbl->Release(g_dsound);
		AIL_unlock();
		g_dsound = 0;
	}
}
// 5813E8: using guessed type _DWORD __stdcall AIL_unlock();
// 5813EC: using guessed type _DWORD __stdcall AIL_lock();

//----- (00555620) --------------------------------------------------------
int *__cdecl sub_555620(_DWORD *a1)
{
	_DWORD *v1; // esi
	void *v2; // edi
	int v3; // ebx
	int v4; // ecx
	void *v5; // ebp
	int *result; // eax
	int *v7; // edi
	void *v8; // edi
	void *v9; // edi
	void *v10; // eax
	void *v11; // eax
	void *v12; // eax
	void *v13; // eax
	void *v14; // eax
	void *v15; // eax
	void *v16; // eax
	void *v17; // eax
	void *v18; // eax
	void *v19; // eax
	void *v20; // eax
	void *v21; // eax
	void *v22; // eax
	void *v23; // eax
	void *v24; // eax
	void *v25; // eax
	int *v26; // esi
	int *v27; // eax
	int *v28; // eax
	int *v29; // esi
	int *v30; // eax
	int v31; // [esp+24h] [ebp+4h]

	v1 = a1;
	v2 = *(void **)&byte_5D4594[2515916];
	v3 = a1[9];
	v4 = a1[8];
	v5 = (void *)a1[7];
	result = *(int **)&byte_5D4594[2515920];
	v31 = a1[8];
	if (v3 != *(_DWORD *)&byte_5D4594[2513960]
		|| v5 != *(void **)&byte_5D4594[2513952]
		|| v4 != *(_DWORD *)&byte_5D4594[2513956]
		|| !*(_DWORD *)&byte_5D4594[2515916]
		|| !*(_DWORD *)&byte_5D4594[2515920]
		|| !*(_DWORD *)&byte_5D4594[2515928]
		|| !*(_DWORD *)&byte_5D4594[2515924])
	{
		*(_DWORD *)&byte_5D4594[2513952] = 0;
		*(_DWORD *)&byte_5D4594[2513956] = 0;
		*(_DWORD *)&byte_5D4594[2513960] = 0;
		if (*(_DWORD *)&byte_5D4594[2515916])
		{
			sub_556650(*(_DWORD **)&byte_5D4594[2515916]);
			operator_delete(v2);
			result = *(int **)&byte_5D4594[2515920];
			*(_DWORD *)&byte_5D4594[2515916] = 0;
		}
		if (result)
		{
			v7 = result;
			sub_556650(result);
			operator_delete(v7);
			*(_DWORD *)&byte_5D4594[2515920] = 0;
		}
		v8 = *(void **)&byte_5D4594[2515928];
		if (*(_DWORD *)&byte_5D4594[2515928])
		{
			sub_556650(*(_DWORD **)&byte_5D4594[2515928]);
			operator_delete(v8);
			*(_DWORD *)&byte_5D4594[2515928] = 0;
		}
		v9 = *(void **)&byte_5D4594[2515924];
		if (*(_DWORD *)&byte_5D4594[2515924])
		{
			sub_556650(*(_DWORD **)&byte_5D4594[2515924]);
			operator_delete(v9);
			*(_DWORD *)&byte_5D4594[2515924] = 0;
		}
		if (v3 == 1)
		{
			*(_DWORD *)&byte_5D4594[2515908] = v1[2];
			v18 = (void *)operator_new(0xA8u);
			if (v18)
				v19 = sub_556500(v18, (void *)v1[7], v1[8], v1[5]);
			else
				v19 = 0;
			*(_DWORD *)&byte_5D4594[2515916] = v19;
			v20 = (void *)operator_new(0xA8u);
			if (v20)
				v21 = sub_556500(v20, (void *)v1[7], v1[8], v1[6]);
			else
				v21 = 0;
			*(_DWORD *)&byte_5D4594[2515920] = v21;
			v22 = (void *)operator_new(0xA8u);
			if (v22)
				v23 = sub_5565E0(v22, (void *)v1[7], v1[8], 3, v1[3]);
			else
				v23 = 0;
			*(_DWORD *)&byte_5D4594[2515928] = v23;
			v24 = (void *)operator_new(0xA8u);
			if (v24)
				v25 = sub_5565E0(v24, (void *)v1[7], v1[8], 1, v1[3]);
			else
				v25 = 0;
			*(_DWORD *)&byte_5D4594[2515924] = v25;
			*(_DWORD *)&byte_5D4594[2513952] = v5;
			*(_DWORD *)&byte_5D4594[2513956] = v31;
			*(_DWORD *)&byte_5D4594[2513960] = 1;
		}
		else
		{
			sub_5569B0(*(HWND *)&byte_5D4594[2514000]);
			v10 = (void *)operator_new(0xA8u);
			if (v10)
				v11 = sub_556500(v10, v5, v31, 0);
			else
				v11 = 0;
			*(_DWORD *)&byte_5D4594[2515916] = v11;
			v12 = (void *)operator_new(0xA8u);
			if (v12)
				v13 = sub_556500(v12, v5, v31, 0);
			else
				v13 = 0;
			*(_DWORD *)&byte_5D4594[2515920] = v13;
			v14 = (void *)operator_new(0xA8u);
			if (v14)
				v15 = sub_556570(v14, v5, v31, 3);
			else
				v15 = 0;
			*(_DWORD *)&byte_5D4594[2515928] = v15;
			v16 = (void *)operator_new(0xA8u);
			if (v16)
				v17 = sub_556570(v16, v5, v31, 1);
			else
				v17 = 0;
			*(_DWORD *)&byte_5D4594[2515924] = v17;
			*(_DWORD *)&byte_5D4594[2513952] = v5;
			*(_DWORD *)&byte_5D4594[2513956] = v31;
			*(_DWORD *)&byte_5D4594[2513960] = 0;
		}
		v26 = *(int **)&byte_5D4594[2515916];
		if (sub_556710(*(_DWORD **)(*(_DWORD *)&byte_5D4594[2515916] + 28)))
		{
			v27 = (int *)v26[7];
			if (v26 != v27)
				sub_5562F0(v26, v27, v26[4], v26[5], v26[1], v26[2]);
			sub_556920(v26, 0);
		}
		if (sub_556820((_DWORD *)v26[7]))
		{
			v28 = (int *)v26[7];
			if (v26 != v28 && v26[8] && !v28[9])
				*v26 = 0;
		}
		v29 = *(int **)&byte_5D4594[2515920];
		if (sub_556710(*(_DWORD **)(*(_DWORD *)&byte_5D4594[2515920] + 28)))
		{
			v30 = (int *)v29[7];
			if (v29 != v30)
				sub_5562F0(v29, v30, v29[4], v29[5], v29[1], v29[2]);
			sub_556920(v29, 0);
		}
		result = (int *)sub_556820((_DWORD *)v29[7]);
		if (result)
		{
			result = (int *)v29[7];
			if (v29 != result)
			{
				if (v29[8])
				{
					if (!result[9])
						*v29 = 0;
				}
			}
		}
	}
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00555A40) --------------------------------------------------------
int sub_555A40()
{
	void *v0; // esi
	void *v1; // esi
	void *v2; // esi
	void *v3; // esi
	int result; // eax

	v0 = *(void **)&byte_5D4594[2515924];
	if (*(_DWORD *)&byte_5D4594[2515924])
	{
		sub_556650(*(_DWORD **)&byte_5D4594[2515924]);
		operator_delete(v0);
	}
	v1 = *(void **)&byte_5D4594[2515928];
	*(_DWORD *)&byte_5D4594[2515924] = 0;
	if (*(_DWORD *)&byte_5D4594[2515928])
	{
		sub_556650(*(_DWORD **)&byte_5D4594[2515928]);
		operator_delete(v1);
	}
	v2 = *(void **)&byte_5D4594[2515920];
	*(_DWORD *)&byte_5D4594[2515928] = 0;
	if (*(_DWORD *)&byte_5D4594[2515920])
	{
		sub_556650(*(_DWORD **)&byte_5D4594[2515920]);
		operator_delete(v2);
	}
	v3 = *(void **)&byte_5D4594[2515916];
	*(_DWORD *)&byte_5D4594[2515920] = 0;
	if (*(_DWORD *)&byte_5D4594[2515916])
	{
		sub_556650(*(_DWORD **)&byte_5D4594[2515916]);
		operator_delete(v3);
	}
	*(_DWORD *)&byte_5D4594[2515916] = 0;
	result = sub_5569F0();
	*(_DWORD *)&byte_5D4594[2513952] = 0;
	*(_DWORD *)&byte_5D4594[2513956] = 0;
	*(_DWORD *)&byte_5D4594[2513960] = 0;
	return result;
}

//----- (00555AE0) --------------------------------------------------------
_DWORD *__cdecl sub_555AE0(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
	_DWORD *result; // eax

	*a6 = a3;
	if (a3)
		goto LABEL_24;
	if (!sub_5562A0(6))
	{
		result = (_DWORD *)sub_5562A0(7);
		if (result)
		{
			*a4 = 640;
			*a5 = 400;
			return result;
		}
		if (sub_5562A0(8))
		{
			result = a4;
			*a4 = 640;
			*a5 = 400;
			return result;
		}
		if (sub_5562A0(9))
			goto LABEL_24;
	}
	result = (_DWORD *)a1;
	if (a1 <= 320 && a2 <= 200)
	{
		*a4 = 640;
		*a5 = 400;
		return result;
	}
	if (a1 <= 640)
	{
		if (a2 <= 400)
		{
			result = a4;
			*a4 = 640;
			*a5 = 400;
			return result;
		}
		if (a2 <= 480)
			goto LABEL_24;
	}
	if (a1 <= 800 && a2 <= 600)
	{
		*a4 = 800;
		*a5 = 600;
		return result;
	}
	if (a1 > 1024 || a2 > 768)
	{
	LABEL_24:
		result = a5;
		*a4 = 640;
		*a5 = 480;
	}
	else
	{
		result = a4;
		*a4 = 1024;
		*a5 = 768;
	}
	return result;
}

//----- (00555C10) --------------------------------------------------------
int __cdecl sub_555C10(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
	int result; // eax

	*a1 = *(_DWORD *)&byte_5D4594[2513952];
	result = *(_DWORD *)&byte_5D4594[2513956];
	*a2 = *(_DWORD *)&byte_5D4594[2513956];
	*a3 = *(_DWORD *)&byte_5D4594[2513960];
	return result;
}

//----- (00555C40) --------------------------------------------------------
int __cdecl sub_555C40(_DWORD *a1)
{
	const char *v1; // ebp
	int v2; // ebx
	int v3; // esi
	int v4; // edi
	_BYTE *v5; // eax
	_BYTE *v6; // eax
	int v7; // eax
	void *v8; // esi
	int v10; // eax
	int v11; // eax
	unsigned int v12; // esi
	int v13; // ebp
	int v14; // ebx
	int v15; // esi
	BOOL v16; // edi
	bool v17; // zf
	void *v18; // esi
	int v19; // [esp-14h] [ebp-40h]
	int v20; // [esp-10h] [ebp-3Ch]
	int v21; // [esp+10h] [ebp-1Ch]
	unsigned int v22; // [esp+14h] [ebp-18h]
	unsigned int v23; // [esp+18h] [ebp-14h]
	_BYTE *v24; // [esp+1Ch] [ebp-10h]
	int v25; // [esp+28h] [ebp-4h]

	v1 = (const char *)a1[10];
	sub_413B70((char *)&byte_587000[293584]);
	v2 = sub_5562A0(0);
	if (*(_DWORD *)&byte_5D4594[2513988] == 1)
	{
		v2 |= 2u;
		if (*(_DWORD *)&byte_5D4594[2513984])
			v2 |= 4u;
	}
	v3 = *(_DWORD *)&byte_587000[293360];
	if (*(int *)&byte_587000[293360] == -1)
	{
		v3 = *(_DWORD *)&byte_587000[293364];
		v4 = *(_DWORD *)&byte_587000[293368];
	}
	else
	{
		v4 = *(_DWORD *)&byte_587000[293360];
	}
	v5 = operator_new(0x618u);
	v24 = v5;
	v25 = 0;
	if (v5)
		v6 = sub_557C70(v5, v1, v2, (int)sub_556010, (int)sub_556040, (int)sub_556050, (int)sub_556030, v3, v4);
	else
		v6 = 0;
	v25 = -1;
	*(_DWORD *)&byte_5D4594[2513964] = v6;
	if (!v6)
		return 0;
	if (v2 & 1)
	{
		v7 = sub_557F60((int)v6, 0);
		if (v7 != -1 && v7 != -2)
		{
		LABEL_16:
			v8 = *(void **)&byte_5D4594[2513964];
			if (*(_DWORD *)&byte_5D4594[2513964])
			{
				sub_557F50(*(char **)&byte_5D4594[2513964]);
				operator_delete(v8);
			}
			*(_DWORD *)&byte_5D4594[2513964] = 0;
			return 0;
		}
		sub_413B70((char *)&byte_587000[293568]);
	}
	sub_413B70((char *)&byte_587000[293548]);
	if (!sub_5581C0(*(_DWORD **)&byte_5D4594[2513964]))
		goto LABEL_16;
	v20 = sub_558720(*(_DWORD **)&byte_5D4594[2513964]);
	v19 = sub_5587F0(*(_DWORD **)&byte_5D4594[2513964]);
	v10 = sub_5587E0(*(_DWORD **)&byte_5D4594[2513964]);
	sub_555AE0(v10, v19, v20, &v22, &v23, &v21);
	if (v21 == 4)
		v21 = 1;
	sub_413B70((char *)&byte_587000[293524]);
	sub_555620(a1);
	sub_413B70((char *)&byte_587000[293496]);
	if (v21 == 1 || v21 == 4)
	{
		v11 = sub_556A10();
		sub_558790(*(_DWORD **)&byte_5D4594[2513964], v11);
	}
	if (sub_5562A0(7) || sub_5562A0(16))
	{
		*(_DWORD *)&byte_5D4594[2513968] = *(_DWORD *)&byte_5D4594[2515916];
	}
	else if (sub_5562A0(15))
	{
		*(_DWORD *)&byte_5D4594[2513968] = *(_DWORD *)&byte_5D4594[2515928];
	}
	else
	{
		*(_DWORD *)&byte_5D4594[2513968] = *(_DWORD *)&byte_5D4594[2515924];
	}
	sub_558730(*(int **)&byte_5D4594[2513964], 0, v22, v23, -1, -1);
	v12 = v23 * v22;
	if (v21 == 1 || v21 == 4)
		v12 *= 2;
	sub_413B70((char *)&byte_587000[293480]);
	sub_556710(*(_DWORD **)&byte_5D4594[2513968]);
	sub_413B70((char *)&byte_587000[293472]);
	memset(**(void ***)&byte_5D4594[2513968], 0, v12);
	sub_413B70((char *)&byte_587000[293452]);
	sub_556820(*(_DWORD **)&byte_5D4594[2513968]);
	sub_413B70((char *)&byte_587000[293440]);
	v13 = 0;
	v14 = -1;
	v15 = 0;
	if (sub_5562A0(2))
	{
		v13 = *(_DWORD *)&byte_5D4594[2513980];
		if ((int)*(_DWORD *)&byte_587000[293372] >= 0)
			v14 = *(_DWORD *)&byte_587000[293372];
		v15 = *(_DWORD *)&byte_587000[293376];
		if (*(_DWORD *)&byte_5D4594[2513988] == 1)
		{
			if (*(_DWORD *)&byte_5D4594[2513972])
				sub_558260(*(int **)&byte_5D4594[2513964], *(int *)&byte_5D4594[2513980], v14, *(int *)&byte_587000[293376]);
			else
				sub_558230(*(int **)&byte_5D4594[2513964], *(int *)&byte_5D4594[2513976], *(int *)&byte_587000[293376]);
		}
	}
	do
	{
		if (*(_DWORD *)&byte_5D4594[2513988] == 2 || v13)
			sub_5582C0(*(int **)&byte_5D4594[2513964], v13);
		sub_413B70((char *)&byte_587000[293420]);
		v16 = sub_558370(*(int **)&byte_5D4594[2513964], v14);
		sub_413B70((char *)&byte_587000[293396]);
		if (*(_DWORD *)&byte_5D4594[2513988] == 1)
			v15 = 0;
		sub_558710(*(int **)&byte_5D4594[2513964]);
		if (v16)
			break;
		v17 = v15 == 0;
		if (v15 > 0)
			v17 = --v15 == 0;
	} while (!v17);
	sub_5586D0(*(int *)&byte_5D4594[2513964]);
	v18 = *(void **)&byte_5D4594[2513964];
	if (*(_DWORD *)&byte_5D4594[2513964])
	{
		sub_557F50(*(char **)&byte_5D4594[2513964]);
		operator_delete(v18);
	}
	*(_DWORD *)&byte_5D4594[2513964] = 0;
	sub_413B70((char *)&byte_587000[293380]);
	return 1;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00556010) --------------------------------------------------------
int sub_556010()
{
	sub_556710(*(_DWORD **)&byte_5D4594[2513968]);
	return **(_DWORD **)&byte_5D4594[2513968];
}

//----- (00556030) --------------------------------------------------------
int sub_556030()
{
	return *(_DWORD *)(*(_DWORD *)&byte_5D4594[2513968] + 24);
}

//----- (00556040) --------------------------------------------------------
int sub_556040()
{
	return sub_556820(*(_DWORD **)&byte_5D4594[2513968]);
}

//----- (00556050) --------------------------------------------------------
_DWORD *sub_556050()
{
	_DWORD *v0; // edi
	_DWORD *v1; // esi
	_DWORD *v2; // eax
	_DWORD *v3; // eax
	_DWORD *v4; // eax
	_DWORD *result; // eax
	_DWORD *v6; // esi
	_DWORD *v7; // edi
	int v8; // edx
	int v9; // eax
	_DWORD *v10; // eax
	_DWORD *v11; // eax

	if (sub_5562A0(7))
	{
		v0 = *(_DWORD **)&byte_5D4594[2513968];
		v1 = *(_DWORD **)&byte_5D4594[2515928];
		if (sub_556710(*(_DWORD **)(*(_DWORD *)&byte_5D4594[2513968] + 28)))
		{
			v2 = (_DWORD *)v0[7];
			if (v0 != v2)
				sub_5562F0(v0, v2, v0[4], v0[5], v0[1], v0[2]);
			if (sub_556710((_DWORD *)v1[7]))
			{
				v3 = (_DWORD *)v1[7];
				if (v1 != v3)
					sub_5562F0(v1, v3, v1[4], v1[5], v1[1], v1[2]);
				sub_559030((int)v0, (int)v1, 0, 0, 0, 0, 320, 200, 640, 400, 0, 0);
			}
			if (sub_556820((_DWORD *)v1[7]))
			{
				v4 = (_DWORD *)v1[7];
				if (v1 != v4 && v1[8] && !v4[9])
					*v1 = 0;
			}
		}
		result = (_DWORD *)sub_556820((_DWORD *)v0[7]);
		if (result)
		{
			result = (_DWORD *)v0[7];
			if (v0 != result)
			{
				if (v0[8])
				{
					if (!result[9])
						*v0 = 0;
				}
			}
		}
	}
	else
	{
		result = (_DWORD *)sub_5562A0(15);
		if (!result)
		{
			v6 = *(_DWORD **)&byte_5D4594[2513968];
			v7 = *(_DWORD **)&byte_5D4594[2515928];
			if (*(_DWORD *)(*(_DWORD *)&byte_5D4594[2513968] + 32) && *(_DWORD *)(*(_DWORD *)&byte_5D4594[2515928] + 32))
			{
				v8 = *(_DWORD *)(*(_DWORD *)&byte_5D4594[2515928] + 8);
				if (*(_DWORD *)(*(_DWORD *)&byte_5D4594[2515928] + 8) <= *(int *)(*(_DWORD *)&byte_5D4594[2513968] + 8))
					v8 = *(_DWORD *)(*(_DWORD *)&byte_5D4594[2513968] + 8);
				v9 = *(_DWORD *)(*(_DWORD *)&byte_5D4594[2515928] + 4);
				if (v9 <= *(int *)(*(_DWORD *)&byte_5D4594[2513968] + 4))
					v9 = *(_DWORD *)(*(_DWORD *)&byte_5D4594[2513968] + 4);
				result = (_DWORD *)sub_556890(
					*(_DWORD **)&byte_5D4594[2513968],
					*(int *)&byte_5D4594[2515928],
					*(_DWORD *)(*(_DWORD *)&byte_5D4594[2513968] + 16),
					*(_DWORD *)(*(_DWORD *)&byte_5D4594[2513968] + 20),
					*(_DWORD *)(*(_DWORD *)&byte_5D4594[2515928] + 16),
					*(_DWORD *)(*(_DWORD *)&byte_5D4594[2515928] + 20),
					v9,
					v8,
					0);
			}
			else
			{
				if (sub_556710(*(_DWORD **)(*(_DWORD *)&byte_5D4594[2513968] + 28)))
				{
					v10 = (_DWORD *)v6[7];
					if (v6 != v10)
						sub_5562F0(v6, v10, v6[4], v6[5], v6[1], v6[2]);
					if (sub_556710((_DWORD *)v7[7]))
					{
						v11 = (_DWORD *)v7[7];
						if (v7 != v11)
							sub_5562F0(v7, v11, v7[4], v7[5], v7[1], v7[2]);
						sub_558AA0(v6, v7, 0, 0, 0, 0, v6[1], v6[2], 0);
					}
					sub_556240((_DWORD **)v7);
				}
				result = (_DWORD *)sub_556240((_DWORD **)v6);
			}
		}
	}
	return result;
}

//----- (00556240) --------------------------------------------------------
int __thiscall sub_556240(_DWORD **this)
{
	_DWORD **v1; // esi
	int result; // eax
	_DWORD *v3; // eax

	v1 = this;
	result = sub_556820(this[7]);
	if (result)
	{
		v3 = v1[7];
		if (v1 != v3 && v1[8] && !v3[9])
			*v1 = 0;
		result = 1;
	}
	return result;
}

//----- (00556280) --------------------------------------------------------
int __cdecl sub_556280(int a1)
{
	int result; // eax

	result = a1 >> 3;
	byte_5D4594[(a1 >> 3) + 2513992] |= 1 << (a1 & 7);
	return result;
}

//----- (005562A0) --------------------------------------------------------
BOOL __cdecl sub_5562A0(int a1)
{
	return (byte_5D4594[(a1 >> 3) + 2513992] & (unsigned __int8)(1 << (a1 & 7))) != 0;
}

//----- (005562C0) --------------------------------------------------------
void *__thiscall sub_5562C0(void *this)
{
	return this;
}

//----- (005562D0) --------------------------------------------------------
int __thiscall sub_5562D0(_DWORD *this)
{
	int result; // eax

	result = 0;
	*this = 0;
	this[1] = 0;
	this[2] = 0;
	this[3] = 0;
	this[4] = 0;
	this[5] = 0;
	this[6] = 0;
	this[8] = 0;
	this[9] = 0;
	this[7] = 0;
	return result;
}

//----- (005562F0) --------------------------------------------------------
void __thiscall sub_5562F0(_DWORD *this, _DWORD *a2, int a3, int a4, int a5, int a6)
{
	int v6; // edi
	int v7; // ebx
	int v8; // edx
	int v9; // esi
	int v10; // esi
	int v11; // ebx
	int v12; // edx
	int v13; // [esp+8h] [ebp+8h]

	if (this != (_DWORD *)this[7])
	{
		v6 = a3;
		if (a3 < 0)
			v6 = 0;
		v7 = a2[1];
		if (v6 >= v7)
			v6 = v7 - 1;
		v8 = a4;
		if (a4 < 0)
			v8 = 0;
		v9 = a2[2];
		v13 = a2[2];
		if (v8 >= v9)
			v8 = v9 - 1;
		v10 = a5;
		if (v6 + a5 > v7)
			v10 = v7 - v6;
		if (v8 + a6 > v13)
			a6 = v13 - v8;
		v11 = *a2 + v8 * (a2[1] + a2[6]);
		this[4] = v6;
		this[5] = v8;
		*this = v6 + v11;
		v12 = a2[1] - v10;
		this[1] = v10;
		this[3] = v12;
		this[2] = a6;
		this[6] = a2[6];
		this[7] = a2;
		this[8] = a2[8];
	}
}

//----- (005563A0) --------------------------------------------------------
int __thiscall sub_5563A0(_DWORD *this, int a2, char a3)
{
	_DWORD *v3; // esi
	int v4; // eax
	int v5; // ecx
	int *v6; // edi
	int result; // eax

	v3 = this;
	memset(this + 14, 0, 0x6Cu);
	this[14] = 108;
	this[15] = 1;
	this[40] = 512;
	if (!(a3 & 2))
	{
		v4 = this[2];
		v5 = this[1];
		v3[40] = 64;
		v3[15] = 7;
		v3[16] = v4;
		v3[17] = v5;
	}
	if (v3[1] == 320)
		v3[40] |= 0x200000u;
	if (a2)
	{
		(*(void(__stdcall **)(int, _DWORD *))(*(_DWORD *)a2 + 88))(a2, v3 + 14);
		v6 = v3 + 13;
		v3[41] = 1;
		v3[13] = a2;
	}
	else
	{
		v6 = v3 + 13;
		(*(void(__stdcall **)(_DWORD, _DWORD *, _DWORD *, _DWORD))(**(_DWORD **)&byte_5D4594[2515908] + 24))(
			*(_DWORD *)&byte_5D4594[2515908],
			v3 + 14,
			v3 + 13,
			0);
		v3[41] = 0;
	}
	result = sub_556AE0(&byte_5D4594[2514012], *v6);
	if (a3 & 2)
	{
		result = *v6;
		*(_DWORD *)&byte_5D4594[2515900] = *v6;
	}
	v3[12] = 0;
	v3[8] = 1;
	*v3 = 0;
	v3[9] = 0;
	return result;
}

//----- (00556470) --------------------------------------------------------
void *__thiscall sub_556470(_DWORD *this, void *a2, int a3, int a4, int a5, char a6, int a7)
{
	void *result; // eax
	_DWORD *v8; // esi
	int v9; // edx

	result = a2;
	v8 = this;
	this[11] = a5;
	this[1] = a2;
	this[2] = a3;
	if (a6 & 3)
	{
		result = (void *)sub_5563A0(this, a7, a6);
	}
	else
	{
		if (a4)
		{
			this[10] = a4;
			this[12] = 0;
		}
		else
		{
			if (!a5)
				this[11] = a3 * (_DWORD)a2;
			result = operator_new(this[11]);
			v8[10] = result;
			v8[12] = 1;
		}
		v9 = v8[10];
		v8[8] = 0;
		*v8 = v9;
	}
	v8[6] = 0;
	v8[3] = 0;
	v8[4] = 0;
	v8[5] = 0;
	v8[7] = v8;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00556500) --------------------------------------------------------
void *__thiscall sub_556500(void *this, void *a2, int a3, int a4)
{
	void *v4; // esi

	v4 = this;
	sub_5562C0(this);
	sub_559AA0((_DWORD *)v4 + 10);
	sub_556470(v4, a2, a3, a4, a3 * (_DWORD)a2, 0, 0);
	return v4;
}

//----- (00556570) --------------------------------------------------------
void *__thiscall sub_556570(void *this, void *a2, int a3, char a4)
{
	void *v4; // esi

	v4 = this;
	sub_5562C0(this);
	sub_559AA0((_DWORD *)v4 + 10);
	sub_556470(v4, a2, a3, 0, a3 * (_DWORD)a2, a4, 0);
	return v4;
}

//----- (005565E0) --------------------------------------------------------
void *__thiscall sub_5565E0(void *this, void *a2, int a3, char a4, int a5)
{
	void *v5; // esi

	v5 = this;
	sub_5562C0(this);
	sub_559AA0((_DWORD *)v5 + 10);
	sub_556470(v5, a2, a3, 0, a3 * (_DWORD)a2, a4, a5);
	return v5;
}

//----- (00556650) --------------------------------------------------------
int __thiscall sub_556650(_DWORD *this)
{
	_DWORD *v1; // esi
	int v2; // ecx

	v1 = this;
	if (this[8] && this[13])
	{
		if (this[9])
		{
			do
			{
				if ((*(int(__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)v1[13] + 128))(v1[13], 0) == -2005532222)
				{
					if (*(_DWORD *)&byte_5D4594[2515948])
						(*(void(**)(void))&byte_5D4594[2515948])();
					sub_556C10(&byte_5D4594[2514012]);
				}
			} while (v1[9]);
		}
		if (!v1[41])
			(*(void(__stdcall **)(_DWORD))(*(_DWORD *)v1[13] + 8))(v1[13]);
		sub_556B20(&byte_5D4594[2514012], v1[13]);
	}
	if (v1)
		v2 = (int)(v1 + 10);
	else
		v2 = 0;
	sub_559AB0(v2);
	return sub_5562D0(v1);
}

//----- (00556710) --------------------------------------------------------
int __thiscall sub_556710(_DWORD *this)
{
	_DWORD *v1; // esi
	int v2; // edi
	int result; // eax
	int v4; // eax
	int v5; // eax
	int v6; // ecx
	int v7; // edi

	v1 = this;
	v2 = 0;
	if (!this[8])
		return 1;
	if (this[13])
	{
		if (*(_DWORD *)&byte_587000[293604])
		{
			nullsub_31(this);
			v4 = v1[9];
			if (v4)
			{
				v1[9] = v4 + 1;
				nullsub_31(v1);
				result = 1;
			}
			else
			{
				if (v1[13])
				{
					while (v2 < 2)
					{
						v5 = (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD *, int, _DWORD))(*(_DWORD *)v1[13] + 100))(
							v1[13],
							0,
							v1 + 14,
							1,
							0);
						if (v5 != -2005532222)
						{
							if (v5)
							{
								nullsub_31(v1);
								result = 0;
							}
							else
							{
								v6 = v1[18];
								v7 = v1[9];
								*v1 = v1[23];
								v1[6] = v6 - v1[1];
								v1[9] = v7 + 1;
								++*(_DWORD *)&byte_5D4594[2514004];
								nullsub_31(v1);
								result = 1;
							}
							return result;
						}
						if (*(_DWORD *)&byte_5D4594[2515948])
							(*(void(**)(void))&byte_5D4594[2515948])();
						sub_556C10(&byte_5D4594[2514012]);
						++v2;
						if (v1[9])
							break;
					}
				}
				nullsub_31(v1);
				nullsub_31(&byte_587000[293608]);
				result = 0;
			}
		}
		else
		{
			nullsub_31(&byte_587000[293644]);
			result = 0;
		}
	}
	else
	{
		nullsub_31(&byte_587000[293656]);
		result = 0;
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (00556820) --------------------------------------------------------
int __thiscall sub_556820(_DWORD *this)
{
	_DWORD *v1; // esi
	int v2; // eax
	int result; // eax
	int v4; // edx

	v1 = this;
	v2 = this[9];
	if (!v2 || !this[8])
		return 1;
	if (v2 != 1 || !this[13])
	{
		this[9] = v2 - 1;
		return 1;
	}
	nullsub_31(this);
	if ((*(int(__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)v1[13] + 128))(v1[13], 0))
	{
		nullsub_31(v1);
		result = 0;
	}
	else
	{
		v4 = v1[9] - 1;
		*v1 = 0;
		v1[9] = v4;
		nullsub_31(v1);
		result = 1;
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (00556890) --------------------------------------------------------
int __thiscall sub_556890(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
	int v9; // eax
	int v10; // ecx
	int v12[4]; // [esp+0h] [ebp-20h]
	int v13[4]; // [esp+10h] [ebp-10h]

	v9 = 0;
	if (a9)
		v9 = 0x8000;
	v12[0] = a3;
	v12[2] = a7 + a3;
	v10 = this[7];
	v12[1] = a4;
	v12[3] = a8 + a4;
	v13[0] = a5;
	v13[1] = a6;
	v13[2] = a7 + a5;
	v13[3] = a8 + a6;
	return (*(int(__stdcall **)(_DWORD, int *, _DWORD, int *, int, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 28) + 52) + 20))(
		*(_DWORD *)(*(_DWORD *)(a2 + 28) + 52),
		v13,
		*(_DWORD *)(v10 + 52),
		v12,
		v9 | 0x1000200,
		0);
}

//----- (00556920) --------------------------------------------------------
void __cdecl sub_556920(int *a1, char a2)
{
	int v2; // eax
	int v3; // edi
	int v4; // edx
	signed int v5; // esi
	int v6; // ebx
	__int16 v7; // cx
	int v8; // eax
	int v9; // ecx
	char v10; // bl
	char *v11; // edi
	unsigned int v12; // ecx
	char *v13; // edi
	int v14; // ecx
	int v15; // [esp+0h] [ebp-1Ch]
	int v16; // [esp+0h] [ebp-1Ch]

	v3 = *a1;
	v4 = a1[2];
	v5 = a1[1];
	v15 = a1[6];
	v6 = v15 + a1[3];
	LOBYTE(v2) = a2;
	BYTE1(v2) = a2;
	v7 = v2;
	v8 = v2 << 16;
	LOWORD(v8) = v7;
	if (v5 < 14)
	{
		do
		{
			memset((void *)v3, v7, v5);
			v3 += v6 + v5;
			--v4;
		} while (v4);
	}
	else
	{
		v16 = v15 + a1[3];
		do
		{
			v9 = -v3 & 3;
			v10 = v5 - v9;
			memset((void *)v3, v8, v9);
			v11 = (char *)(v3 + v9);
			v12 = (unsigned int)(v5 - v9) >> 2;
			memset32(v11, v8, v12);
			v13 = &v11[4 * v12];
			v14 = v10 & 3;
			memset(v13, v8, v14);
			v3 = (int)&v13[v14 + v16];
			--v4;
		} while (v4);
	}
}
// 556948: variable 'v2' is possibly undefined

//----- (005569A0) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
_DWORD *sub_5569A0()
{
	return sub_556AC0(&byte_5D4594[2514012]);
}

//----- (005569B0) --------------------------------------------------------
int __cdecl sub_5569B0(HWND a1)
{
	int v1; // eax

	*(_DWORD *)&byte_5D4594[2515892] = a1;
	v1 = (*(int(__stdcall **)(_DWORD, int, unsigned __int8 *, unsigned __int8 *, _DWORD))(**(_DWORD **)&byte_5D4594[2515908]
		+ 20))(
			*(_DWORD *)&byte_5D4594[2515908],
			68,
			&byte_5D4594[2514100],
			&byte_5D4594[2515896],
			0);
	sub_556C60(v1, 0);
	*(_DWORD *)&byte_5D4594[2515904] = 0;
	return 1;
}

//----- (005569F0) --------------------------------------------------------
int sub_5569F0()
{
	int result; // eax

	result = *(_DWORD *)&byte_5D4594[2515908];
	if (*(_DWORD *)&byte_5D4594[2515908])
		*(_DWORD *)&byte_5D4594[2515908] = 0;
	return result;
}

//----- (00556A10) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
int sub_556A10()
{
	return sub_556B80((int *)&byte_5D4594[2514012]);
}

//----- (00556A20) --------------------------------------------------------
char *__cdecl sub_556A20(char *a1)
{
	char *result; // eax
	int v2; // ebp
	unsigned __int8 *v3; // ecx
	unsigned __int8 v4; // dl
	char *v5; // eax
	unsigned __int8 v6; // dl
	char v7; // dl

	result = a1;
	if (a1)
	{
		if (*(_DWORD *)&byte_5D4594[2515908])
		{
			v2 = *(_DWORD *)&byte_5D4594[2515900];
			if (*(_DWORD *)&byte_5D4594[2515900])
			{
				qmemcpy(&byte_5D4594[2515124], a1, 0x300u);
				v3 = &byte_5D4594[2514101];
				do
				{
					v4 = *result;
					v5 = result + 1;
					*(v3 - 1) = v4;
					v3 += 4;
					v6 = *v5++;
					*(v3 - 4) = v6;
					v7 = *v5;
					result = v5 + 1;
					*(v3 - 3) = v7;
				} while ((int)v3 < (int)&byte_5D4594[2515125]);
				if (!*(_DWORD *)&byte_5D4594[2515904])
				{
					(*(void(__stdcall **)(int, _DWORD))(*(_DWORD *)v2 + 124))(v2, *(_DWORD *)&byte_5D4594[2515896]);
					*(_DWORD *)&byte_5D4594[2515904] = 1;
				}
				result = (char *)(*(int(__stdcall **)(_DWORD, _DWORD, _DWORD, int, unsigned __int8 *))(**(_DWORD **)&byte_5D4594[2515896]
					+ 24))(
						*(_DWORD *)&byte_5D4594[2515896],
						0,
						0,
						256,
						&byte_5D4594[2514100]);
			}
		}
	}
	return result;
}

//----- (00556AC0) --------------------------------------------------------
_DWORD *__thiscall sub_556AC0(_DWORD *this)
{
	memset(this + 1, 0, 0x50u);
	this[21] = 0;
	*this = 0;
	return this;
}

//----- (00556AE0) --------------------------------------------------------
int __thiscall sub_556AE0(_DWORD *this, int a2)
{
	_DWORD *v2; // esi
	int result; // eax
	_DWORD *i; // ecx

	v2 = this;
	result = sub_556B50(this, a2);
	if (!result)
	{
		for (i = v2 + 1; *i; ++i)
		{
			if (++result >= 20)
				return result;
		}
		v2[result + 1] = a2;
	}
	return result;
}

//----- (00556B20) --------------------------------------------------------
int __thiscall sub_556B20(_DWORD *this, int a2)
{
	int result; // eax
	_DWORD *i; // edx

	result = 0;
	for (i = this + 1; *i != a2; ++i)
	{
		if (++result >= 20)
			return result;
	}
	this[result + 1] = 0;
	return result;
}

//----- (00556B50) --------------------------------------------------------
int __thiscall sub_556B50(_DWORD *this, int a2)
{
	int v2; // eax
	_DWORD *i; // ecx

	v2 = 0;
	for (i = this + 1; *i != a2; ++i)
	{
		if (++v2 >= 20)
			return 0;
	}
	return 1;
}

//----- (00556B80) --------------------------------------------------------
int __thiscall sub_556B80(int *this)
{
	int v1; // edi
	int *i; // esi
	int v3; // eax
	int v5[27]; // [esp+8h] [ebp-6Ch]

	v1 = 0;
	for (i = this + 1; ; ++i)
	{
		v3 = *i;
		if (*i)
		{
			v5[0] = 108;
			v5[1] = 4097;
			(*(void(__stdcall **)(int, int *))(*(_DWORD *)v3 + 88))(v3, v5);
			if (v5[26] & 0x200)
				break;
		}
		if (++v1 >= 20)
			return 3;
	}
	if (v5[22] == 64512)
		return 0;
	if (v5[23] == 2016)
		return 1;
	return (v5[24] != 63) + 2;
}

//----- (00556C10) --------------------------------------------------------
char *__thiscall sub_556C10(_DWORD *this)
{
	_DWORD *v1; // ebx
	char *result; // eax
	int v3; // edi
	_DWORD *i; // esi

	v1 = this;
	result = (char *)this[21];
	if (result)
	{
		v3 = 0;
		for (i = this + 1; !*i || !(*(int(__stdcall **)(_DWORD))(*(_DWORD *)*i + 108))(*i); ++i)
		{
			if (++v3 >= 20)
			{
				*v1 = 1;
				return sub_556A20((char *)&byte_5D4594[2515124]);
			}
		}
		result = *(char **)&byte_5D4594[2515912];
		if (*(_DWORD *)&byte_5D4594[2515912])
			result = (char *)(*(int(**)(void))&byte_5D4594[2515912])();
	}
	return result;
}

//----- (00556C60) --------------------------------------------------------
int __cdecl sub_556C60(int a1, int a2)
{
	int result; // eax
	CHAR Text; // [esp+0h] [ebp-100h]

	if (a1 > -2005532285)
	{
		if (a1 > -2005532104)
		{
			if (a1 > 0)
			{
			LABEL_116:
				sprintf(&Text, (const char *)&byte_587000[293696], (unsigned __int16)a1);
				return MessageBoxA(*(HWND *)&byte_5D4594[2515892], &Text, (LPCSTR)&byte_587000[300280], 0x30u);
			}
			if (a1)
			{
				switch (a1 + 2005532103)
				{
				case 0:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294468],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 1:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294856],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 2:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294968],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 3:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294288],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 4:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294236],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 5:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[295292],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 6:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294644],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 7:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294572],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 8:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[293852],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 9:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294336],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 10:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294672],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 11:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294164],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 12:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[295088],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 13:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294096],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 14:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[295176],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 15:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[293972],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 16:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[295256],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 17:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294600],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 18:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[293772],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 19:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[294776],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 20:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[293916],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				default:
					goto LABEL_116;
				}
			}
			else
			{
				result = a2;
				if (a2)
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[293740],
						(LPCSTR)&byte_587000[300280],
						0x30u);
			}
		}
		else if (a1 == -2005532104)
		{
			result = MessageBoxA(
				*(HWND *)&byte_5D4594[2515892],
				(LPCSTR)&byte_587000[295384],
				(LPCSTR)&byte_587000[300280],
				0x30u);
		}
		else
		{
			switch (a1 + 2005532272)
			{
			case 0:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296908],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 10:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296412],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 20:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296324],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 30:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296224],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 40:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296164],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 50:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295996],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 60:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295956],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 70:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295908],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 80:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295820],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 90:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295776],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 110:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295720],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 120:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295652],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 137:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295620],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 140:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295504],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 160:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[295432],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 161:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296732],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 162:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296816],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 163:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296628],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 164:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296540],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 165:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296592],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 166:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296488],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 167:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[296956],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			default:
				goto LABEL_116;
			}
		}
	}
	else
	{
		if (a1 == -2005532285)
			return MessageBoxA(
				*(HWND *)&byte_5D4594[2515892],
				(LPCSTR)&byte_587000[297052],
				(LPCSTR)&byte_587000[300280],
				0x30u);
		if (a1 > -2005532460)
		{
			switch (a1 + 2005532457)
			{
			case 0:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298896],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 5:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298792],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 10:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298684],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 15:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298640],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 25:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298612],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 35:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298524],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 40:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297676],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 45:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298428],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 65:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298320],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 75:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298224],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 95:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298136],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 101:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298028],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 102:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297908],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 105:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297812],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 115:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297708],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 120:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297560],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 125:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297468],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 135:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297340],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 145:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297264],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 165:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[300168],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 167:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297216],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			case 169:
				result = MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[297152],
					(LPCSTR)&byte_587000[300280],
					0x30u);
				break;
			default:
				goto LABEL_116;
			}
		}
		else
		{
			if (a1 == -2005532460)
				return MessageBoxA(
					*(HWND *)&byte_5D4594[2515892],
					(LPCSTR)&byte_587000[298940],
					(LPCSTR)&byte_587000[300280],
					0x30u);
			if (a1 > -2005532572)
			{
				switch (a1 + 2005532562)
				{
				case 0:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299560],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 10:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299512],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 20:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299440],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 35:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299396],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 40:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299364],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 50:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299288],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 60:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299264],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 70:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299160],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 95:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299136],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 100:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299032],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				default:
					goto LABEL_116;
				}
			}
			else
			{
				if (a1 == -2005532572)
					return MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299612],
						(LPCSTR)&byte_587000[300280],
						0x30u);
				if (a1 <= -2005532662)
				{
					if (a1 == -2005532662)
						return MessageBoxA(
							*(HWND *)&byte_5D4594[2515892],
							(LPCSTR)&byte_587000[300004],
							(LPCSTR)&byte_587000[300280],
							0x30u);
					if (a1 > -2147024882)
					{
						if (a1 == -2147024809)
							return MessageBoxA(
								*(HWND *)&byte_5D4594[2515892],
								(LPCSTR)&byte_587000[300064],
								(LPCSTR)&byte_587000[300280],
								0x30u);
						if (a1 == -2005532667)
							return MessageBoxA(
								*(HWND *)&byte_5D4594[2515892],
								(LPCSTR)&byte_587000[300132],
								(LPCSTR)&byte_587000[300280],
								0x30u);
					}
					else
					{
						switch (a1)
						{
						case -2147024882:
							return MessageBoxA(
								*(HWND *)&byte_5D4594[2515892],
								(LPCSTR)&byte_587000[300168],
								(LPCSTR)&byte_587000[300280],
								0x30u);
						case -2147467263:
							return MessageBoxA(
								*(HWND *)&byte_5D4594[2515892],
								(LPCSTR)&byte_587000[300236],
								(LPCSTR)&byte_587000[300280],
								0x30u);
						case -2147467259:
							return MessageBoxA(
								*(HWND *)&byte_5D4594[2515892],
								(LPCSTR)&byte_587000[300260],
								(LPCSTR)&byte_587000[300280],
								0x30u);
						}
					}
					goto LABEL_116;
				}
				switch (a1 + 2005532652)
				{
				case 0:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299940],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 20:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299900],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 35:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299828],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 70:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299760],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				case 75:
					result = MessageBoxA(
						*(HWND *)&byte_5D4594[2515892],
						(LPCSTR)&byte_587000[299680],
						(LPCSTR)&byte_587000[300280],
						0x30u);
					break;
				default:
					goto LABEL_116;
				}
			}
		}
	}
	return result;
}

//----- (00557C70) --------------------------------------------------------
_BYTE *__thiscall sub_557C70(_BYTE *this, const char *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
	_BYTE *v9; // ebp
	_DWORD *v10; // edi
	int v11; // eax
	int v12; // eax
	int v13; // eax
	int v14; // eax
	int v15; // edx
	int v16; // eax
	bool v17; // zf
	int v18; // eax
	int v19; // eax
	int v20; // eax
	char v21; // al
	char v23[17]; // [esp+13h] [ebp-11h]

	v9 = this;
	*(_DWORD *)&v23[1] = this;
	sub_559AD0(this + 4);
	v10 = v9 + 572;
	*(_DWORD *)&v23[13] = 0;
	sub_55A760(v9 + 572);
	*((_DWORD *)v9 + 380) = a3;
	*((_DWORD *)v9 + 170) = v9;
	*((_DWORD *)v9 + 150) = v23;
	*((_DWORD *)v9 + 159) = 0;
	if (!sub_5562A0(15))
	{
		v11 = *((_DWORD *)v9 + 159);
		LOBYTE(v11) = v11 | 1;
		*((_DWORD *)v9 + 159) = v11;
	}
	if (!sub_5562A0(1))
	{
		v12 = *((_DWORD *)v9 + 159);
		LOBYTE(v12) = v12 | 4;
		*((_DWORD *)v9 + 159) = v12;
	}
	if (sub_5562A0(10))
	{
		v13 = *((_DWORD *)v9 + 159);
		LOBYTE(v13) = v13 | 0x40;
		*((_DWORD *)v9 + 159) = v13;
	}
	if (sub_5562A0(12))
	{
		v14 = *((_DWORD *)v9 + 159);
		LOBYTE(v14) = v14 | 0x80;
		*((_DWORD *)v9 + 159) = v14;
	}
	v15 = *((_DWORD *)v9 + 160) | 8;
	*((_DWORD *)v9 + 160) = v15;
	v16 = v15;
	if (v9[1520] & 2)
	{
		LOBYTE(v16) = v15 | 0x20;
		*((_DWORD *)v9 + 160) = v16;
		if (!(v9[1520] & 4))
			goto LABEL_14;
		BYTE1(v16) |= 1u;
	}
	else
	{
		LOBYTE(v16) = v15 & 0xDF;
	}
	*((_DWORD *)v9 + 160) = v16;
LABEL_14:
	v17 = !sub_5562A0(17);
	v18 = *((_DWORD *)v9 + 160);
	if (v17)
		LOBYTE(v18) = v18 & 0xFB;
	else
		LOBYTE(v18) = v18 | 4;
	*((_DWORD *)v9 + 160) = v18;
	v17 = !sub_5562A0(3);
	v19 = *((_DWORD *)v9 + 160);
	if (v17)
		LOBYTE(v19) = v19 | 1;
	else
		LOBYTE(v19) = v19 & 0xFE;
	*((_DWORD *)v9 + 160) = v19;
	*((_DWORD *)v9 + 151) = -1;
	*((_DWORD *)v9 + 152) = -1;
	*((_DWORD *)v9 + 153) = 0;
	*((_DWORD *)v9 + 154) = 0;
	*((_DWORD *)v9 + 146) = 0;
	*((_DWORD *)v9 + 155) = a8;
	*((_DWORD *)v9 + 156) = a9;
	if (sub_5562A0(3))
	{
		*((_DWORD *)v9 + 161) = 1;
	}
	else
	{
		v20 = *((_DWORD *)v9 + 160);
		*((_DWORD *)v9 + 161) = 14;
		BYTE1(v20) |= 2u;
		*((_DWORD *)v9 + 160) = v20;
	}
	v21 = v9[1520];
	*((_DWORD *)v9 + 162) = -1;
	if (v21 & 1)
		*v10 = sub_558990;
	else
		*v10 = sub_558970;
	*((_DWORD *)v9 + 144) = sub_5589B0;
	*((_DWORD *)v9 + 145) = sub_558A20;
	if (sub_5562A0(4))
		*((_DWORD *)v9 + 147) = sub_55A740;
	else
		*((_DWORD *)v9 + 147) = sub_559C40;
	*((_DWORD *)v9 + 157) = 60;
	*((_DWORD *)v9 + 149) = sub_559DB0;
	*((_DWORD *)v9 + 166) = 0x2000;
	*((_DWORD *)v9 + 370) = 0;
	*((_DWORD *)v9 + 388) = 0;
	*((_DWORD *)v9 + 371) = 0;
	strcpy(v9 + 309, a2);
	*((_DWORD *)v9 + 387) = a6;
	*((_DWORD *)v9 + 385) = a4;
	*(_DWORD *)v9 = a7;
	*((_DWORD *)v9 + 375) = 0;
	*((_DWORD *)v9 + 376) = 0;
	*((_DWORD *)v9 + 377) = 0;
	*((_DWORD *)v9 + 378) = 0;
	*((_DWORD *)v9 + 373) = -1;
	v9[1516] = 0;
	*((_DWORD *)v9 + 386) = a5;
	*((_DWORD *)v9 + 177) = 0;
	v9[308] = 0;
	v9[1496] = 0;
	v9[1556] = 0;
	return v9;
}
// 55A740: using guessed type int __cdecl sub_55A740(_DWORD);

//----- (00557F50) --------------------------------------------------------
int __thiscall sub_557F50(char *this)
{
	return sub_559AE0(this + 4);
}
// 559AE0: using guessed type int __thiscall sub_559AE0(_DWORD);

//----- (00557F60) --------------------------------------------------------
int __thiscall sub_557F60(int this, size_t a2)
{
	int v2; // esi
	char v3; // al
	int result; // eax
	int v5; // eax
	void *v6; // eax
	int v7; // edi
	int v8; // ecx
	int v9; // eax
	int v10; // ecx
	int v11; // edx

	v2 = this;
	if (*(_BYTE *)(this + 308))
		goto LABEL_17;
	v3 = sub_559AF0((char *)(this + 4), (LPCSTR)(this + 309), 0);
	*(_BYTE *)(v2 + 308) = v3;
	if (!v3)
		return -4;
	v5 = sub_559C10((_DWORD *)(v2 + 4));
	*(_DWORD *)(v2 + 1524) = v5;
	*(_DWORD *)(v2 + 1532) = 0;
	*(_DWORD *)(v2 + 1528) = 0;
	v6 = malloc(v5);
	*(_DWORD *)(v2 + 1536) = v6;
	if (v6)
	{
	LABEL_17:
		v7 = a2;
		if (a2)
		{
			v8 = *(_DWORD *)(v2 + 1528);
			v9 = *(_DWORD *)(v2 + 1524);
			if ((int)(v8 + a2) > v9)
				v7 = v9 - v8;
		}
		else
		{
			v7 = *(_DWORD *)(v2 + 1524) - *(_DWORD *)(v2 + 1528);
		}
		if (sub_559BA0(v2 + 4, (void *)(*(_DWORD *)(v2 + 1528) + *(_DWORD *)(v2 + 1536)), v7) == v7)
		{
			v10 = *(_DWORD *)(v2 + 1524);
			v11 = v7 + *(_DWORD *)(v2 + 1528);
			*(_DWORD *)(v2 + 1528) = v11;
			if (v11 < v10)
			{
				result = -1;
			}
			else
			{
				sub_559B60(v2 + 4);
				*(_BYTE *)(v2 + 308) = 0;
				result = -2;
			}
		}
		else
		{
			sub_559B60(v2 + 4);
			*(_BYTE *)(v2 + 308) = 0;
			*(_DWORD *)(v2 + 1532) = 0;
			*(_DWORD *)(v2 + 1528) = 0;
			result = -5;
		}
	}
	else
	{
		sub_559B60(v2 + 4);
		*(_BYTE *)(v2 + 308) = 0;
		result = -3;
	}
	return result;
}

//----- (00558090) --------------------------------------------------------
int __thiscall sub_558090(_DWORD *this, int a2, void *a3, unsigned int a4)
{
	int result; // eax
	int v5; // edi

	switch (a2)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		result = 0;
		break;
	case 5:
		v5 = this[383];
		if ((int)(v5 + a4) > this[381])
			goto LABEL_11;
		qmemcpy(a3, (const void *)(v5 + this[384]), a4);
		this[383] += a4;
		result = 0;
		break;
	case 7:
		if (a3)
		{
			if (a3 == (void *)1)
			{
				this[383] += a4;
				result = 0;
			}
			else
			{
				if (a3 != (void *)2)
					goto LABEL_11;
				this[383] = this[381] - a4 - 1;
				result = 0;
			}
		}
		else
		{
			this[383] = a4;
			result = 0;
		}
		break;
	default:
	LABEL_11:
		result = 1;
		break;
	}
	return result;
}

//----- (00558180) --------------------------------------------------------
_BYTE *__thiscall sub_558180(_BYTE *this, const void *a2)
{
	_BYTE *result; // eax

	result = this;
	qmemcpy(this + 712, a2, 0x300u);
	this[1516] = 1;
	return result;
}

//----- (005581B0) --------------------------------------------------------
char *__thiscall sub_5581B0(char *this)
{
	return sub_55A780(this + 712);
}

//----- (005581C0) --------------------------------------------------------
char __thiscall sub_5581C0(_DWORD *this)
{
	_DWORD *v1; // esi
	unsigned __int16 **v2; // edi
	char result; // al
	unsigned __int16 *v4; // eax
	int v5; // ecx

	v1 = this;
	v2 = (unsigned __int16 **)(this + 177);
	if (sub_55A7B0((int)this + 309, (int)(this + 143), this + 177) == -1)
	{
		v4 = *v2;
		v1[371] = *((_DWORD *)*v2 + 4);
		v1[372] = v4[6];
		v1[375] = v4[1];
		v5 = v4[2];
		result = 1;
		v1[376] = v5;
		*((_BYTE *)v1 + 1496) = 1;
	}
	else
	{
		*((_BYTE *)v1 + 1496) = 0;
		result = 0;
	}
	return result;
}

//----- (00558230) --------------------------------------------------------
bool __thiscall sub_558230(int *this, int a2, int a3)
{
	int v3; // eax

	v3 = a3;
	if (a3 < 0)
		v3 = -1;
	return sub_55B690(this[177], a2, v3, 1) == -1;
}

//----- (00558260) --------------------------------------------------------
bool __thiscall sub_558260(int *this, int a2, int a3, int a4)
{
	int v4; // esi
	int v5; // eax
	int v6; // edx

	v4 = a2;
	if (a2 < 0 || a2 >= this[371])
		v4 = 0;
	v5 = a3;
	if (a3 < 0 || a3 >= this[371])
		v5 = this[371] - 1;
	v6 = a4;
	if (a4 < 0)
		v6 = -1;
	return sub_55B710(this[177], v4, v5, v6, 0) == -1;
}

//----- (005582C0) --------------------------------------------------------
void __thiscall sub_5582C0(int *this, int a2)
{
	int *v2; // esi

	v2 = this;
	if (a2 != this[370] && sub_55B2D0(this[177], a2) != -6)
		v2[370] = a2;
}

//----- (00558300) --------------------------------------------------------
BOOL sub_558300()
{
	BOOL result; // eax
	struct tagMSG Msg; // [esp+10h] [ebp-1Ch]

	for (result = PeekMessageA(&Msg, 0, 0, 0, 0); result; result = PeekMessageA(&Msg, 0, 0, 0, 0))
	{
		result = GetMessageA(&Msg, 0, 0, 0);
		if (!result)
			break;
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
	}
	return result;
}

//----- (00558370) --------------------------------------------------------
BOOL __thiscall sub_558370(int *this, int a2)
{
	int v2; // eax
	int *v3; // esi
	int v4; // ebx
	unsigned int v5; // edi
	HDC v6; // ebp
	void *v8; // [esp+4h] [ebp-30h]
	void *v9; // [esp+8h] [ebp-2Ch]
	char v10; // [esp+12h] [ebp-22h]
	char v11; // [esp+13h] [ebp-21h]
	int v12; // [esp+14h] [ebp-20h]
	int v13; // [esp+18h] [ebp-1Ch]
	DWORD v14; // [esp+1Ch] [ebp-18h]
	char v15; // [esp+20h] [ebp-14h]
	char v16; // [esp+24h] [ebp-10h]
	char v17; // [esp+28h] [ebp-Ch]
	CHAR String[8]; // [esp+2Ch] [ebp-8h]

	v2 = a2;
	v3 = this;
	v10 = 0;
	v11 = 0;
	if (a2 < 0 || a2 >= this[371])
		v2 = this[371] - 1;
	sub_55B8F0(this[177], v2);
	if (v3[373] != -1)
	{
		sub_55B930((unsigned __int8 *)v3[177], &v16, &v15, &a2);
		if (a2 != 1)
		{
			if (a2 != 4)
				goto LABEL_13;
			sub_55BB30(v3[373]);
			v10 = 1;
			if (!sub_5562A0(11))
				goto LABEL_13;
			v9 = sub_55C530;
			v8 = sub_55C3F0;
			goto LABEL_12;
		}
		sub_55BB30(v3[373]);
		v10 = 1;
		if (sub_5562A0(11))
		{
			v9 = sub_55C050;
			v8 = sub_55CA59;
		LABEL_12:
			sub_55B430(v3[177], (int)v8, (int)v9);
			goto LABEL_13;
		}
		sub_55B430(v3[177], (int)sub_55C950, (int)sub_55BCB0);
	}
LABEL_13:
	v4 = 0;
	v14 = sub_55C920();
	sub_555500(0);
	while ((v4 >= 0 || v4 == -10 || v4 == -9 || v4 == -11 || v4 == -1) && !v11)
	{
		sub_558300();
		if (!*(_DWORD *)&byte_587000[293604] || *((_BYTE *)v3 + 1556))
		{
			if (!byte_5D4594[2515932])
			{
				sub_5586A0((int)v3);
				byte_5D4594[2515932] = 1;
			}
		}
		else
		{
			v5 = v3[377] + ((int(*)(void))*v3)();
			sub_558800(v3);
			sub_55B470(v3[177], 0, v3[377], v3[378], v5, -1, -1);
			v4 = sub_55AEF0(v3[177], 1, 0);
			sub_558810(v3);
			if (v4 >= 0)
			{
				if (*((_BYTE *)v3 + 1516))
				{
					sub_5581B0((char *)v3);
					*((_BYTE *)v3 + 1516) = 0;
				}
				((void(*)(void))v3[387])();
				if (sub_5562A0(5))
				{
					v6 = GetWindowDC(*(HWND *)&byte_5D4594[2514000]);
					sub_555C10(&v13, &v12, &v17);
					sprintf(String, (const char *)&byte_587000[300348], v3[370]);
					TextOutA(v6, 0, 0, String, strlen(String));
					TextOutA(v6, v13 / 2, v12 / 2, String, strlen(String));
					ReleaseDC(*(HWND *)&byte_5D4594[2514000], v6);
				}
				v3[370] = v4 + 1;
			}
			if ((unsigned __int16)sub_555510())
				v11 = 1;
		}
	}
	*(_QWORD *)String = sub_55C920() - v14;
	nullsub_31(&byte_587000[300288]);
	if (v10)
		sub_55BC60();
	return v11 != 0;
}
// 558800: using guessed type int __thiscall sub_558800(_DWORD);
// 558810: using guessed type int __thiscall sub_558810(_DWORD);
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (005586A0) --------------------------------------------------------
char __thiscall sub_5586A0(int this)
{
	int v1; // esi
	char result; // al

	v1 = this;
	result = *(_BYTE *)(this + 1496);
	if (result)
		result = sub_55AEF0(*(_DWORD *)(this + 708), 2, 0);
	*(_BYTE *)(v1 + 1556) = 1;
	return result;
}

//----- (005586D0) --------------------------------------------------------
char __thiscall sub_5586D0(int this)
{
	int v1; // esi
	char result; // al
	void *v3; // esi

	v1 = this;
	result = *(_BYTE *)(this + 1496);
	if (result)
		result = sub_55AE50(*(_DWORD *)(this + 708));
	if (*(_BYTE *)(v1 + 1520) & 1)
	{
		v3 = *(void **)(v1 + 1536);
		if (v3)
			free(v3);
	}
	return result;
}

//----- (00558710) --------------------------------------------------------
_DWORD *__thiscall sub_558710(int *this)
{
	return sub_55B820(this[177]);
}

//----- (00558720) --------------------------------------------------------
int __thiscall sub_558720(_DWORD *this)
{
	return this[372];
}

//----- (00558730) --------------------------------------------------------
bool __thiscall sub_558730(int *this, int a2, unsigned int a3, unsigned int a4, int a5, int a6)
{
	int v6; // edx
	int v7; // eax

	v6 = a3;
	if (a3 == -1)
		v6 = this[377];
	else
		this[377] = a3;
	v7 = a4;
	if (a4 == -1)
		v7 = this[378];
	else
		this[378] = a4;
	return sub_55B470(this[177], a2, v6, v7, 0, a5, a6) == -1;
}

//----- (00558790) --------------------------------------------------------
int __thiscall sub_558790(_DWORD *this, int a2)
{
	int result; // eax

	result = a2;
	this[373] = a2;
	return result;
}

//----- (005587A0) --------------------------------------------------------
unsigned __int16 *__thiscall sub_5587A0(_DWORD *this, unsigned __int16 *a2, unsigned int a3)
{
	_DWORD *v3; // esi
	unsigned __int16 *result; // eax

	v3 = this;
	if (this[373] == -1)
	{
		result = (unsigned __int16 *)this[370];
		this[388] = result;
	}
	else
	{
		result = sub_55BC80(a2, a3 >> 1);
		v3[388] = v3[370];
	}
	return result;
}

//----- (005587E0) --------------------------------------------------------
int __thiscall sub_5587E0(_DWORD *this)
{
	return this[375];
}

//----- (005587F0) --------------------------------------------------------
int __thiscall sub_5587F0(_DWORD *this)
{
	return this[376];
}

//----- (00558820) --------------------------------------------------------
BOOL __thiscall sub_558820(char *this, int a2, CHAR *a3, signed int a4)
{
	char *v4; // esi
	BOOL result; // eax
	char v6; // al
	signed int v7; // edi
	char *v8; // esi
	char *v9; // esi

	v4 = this;
	result = 0;
	switch (a2)
	{
	case 1:
	case 2:
		goto LABEL_14;
	case 3:
		v6 = sub_559AF0(this + 4, a3, 0);
		v4[308] = v6;
		result = v6 == 0;
		break;
	case 4:
		sub_559B60((int)(this + 4));
		v4[308] = 0;
	LABEL_14:
		result = 0;
		break;
	case 5:
		v7 = a4;
		result = sub_559BA0((int)(this + 4), a3, a4) != v7;
		break;
	case 6:
		result = 1;
		break;
	case 7:
		result = !sub_559BE0((int)(this + 4), a4, (int)a3);
		break;
	case 8:
		if (a4 <= 0)
		{
			v9 = this + 4;
			result = !sub_559BE0((int)(this + 4), a4, (int)a3);
			if (!result)
			{
				result = sub_559BA0((int)v9, &a4, 1u) != 1;
				if (!result)
					result = !sub_559BE0((int)v9, -1, 1);
			}
		}
		else
		{
			v8 = this + 4;
			result = !sub_559BE0((int)(this + 4), a4 - 1, (int)a3);
			if (!result)
				result = sub_559BA0((int)v8, &a4, 1u) != 1;
		}
		break;
	case 9:
		*(_DWORD *)a3 = sub_559C10((_DWORD *)this + 1);
		result = 0;
		break;
	default:
		return result;
	}
	return result;
}

//----- (00558970) --------------------------------------------------------
BOOL __cdecl sub_558970(int a1, int a2, CHAR *a3, signed int a4)
{
	return sub_558820(*(char **)(a1 + 172), a2, a3, a4);
}

//----- (00558990) --------------------------------------------------------
int __cdecl sub_558990(int a1, int a2, void *a3, unsigned int a4)
{
	return sub_558090(*(_DWORD **)(a1 + 172), a2, a3, a4);
}

//----- (005589B0) --------------------------------------------------------
_DWORD *__cdecl sub_5589B0(int a1, int a2, _DWORD *lpMem, size_t a4)
{
	_DWORD *result; // eax

	switch (a2)
	{
	case 2:
		result = malloc(a4);
		break;
	case 3:
		free(lpMem);
		result = 0;
		break;
	case 4:
	case 5:
		result = lpMem;
		break;
	case 6:
		*lpMem = -1;
		goto LABEL_6;
	default:
	LABEL_6:
		result = 0;
		break;
	}
	return result;
}

//----- (00558A20) --------------------------------------------------------
int __cdecl sub_558A20(int a1, int a2, void *a3, unsigned int a4)
{
	_BYTE *v4; // esi
	int result; // eax

	v4 = *(_BYTE **)(a1 + 172);
	switch (a2)
	{
	case 2:
		sub_55A790((int)a3);
		sub_558180(v4, a3);
		result = 0;
		break;
	case 3:
		sub_5587A0(v4, (unsigned __int16 *)a3, a4);
		result = 0;
		break;
	case 6:
		result = sub_558800(*(_DWORD *)(a1 + 172));
		break;
	case 7:
		sub_558810(*(_DWORD *)(a1 + 172));
		goto LABEL_6;
	default:
	LABEL_6:
		result = 0;
		break;
	}
	return result;
}
// 558800: using guessed type int __thiscall sub_558800(_DWORD);
// 558810: using guessed type int __thiscall sub_558810(_DWORD);

char __cdecl sub_558AA0(_DWORD *a1, _DWORD *a2, unsigned int a3, unsigned int a4, signed int a5, signed int a6, int a7, int a8, char a9)
{
	DebugBreak();
	return 0;
}

#if 0
//----- (00558AA0) --------------------------------------------------------
char __cdecl sub_558AA0(_DWORD *a1, _DWORD *a2, unsigned int a3, unsigned int a4, signed int a5, signed int a6, int a7, int a8, char a9)
{
	int v9; // edi
	unsigned int v10; // ecx
	unsigned __int64 v11; // rt0
	int v12; // edi
	int v13; // edx
	int v14; // ecx
	unsigned __int8 v15; // cl
	unsigned __int8 v16; // dl
	signed int v17; // eax
	int v18; // edi
	unsigned int v19; // ecx
	unsigned __int64 v20; // rt0
	int v21; // edi
	int v22; // edx
	int v23; // ecx
	unsigned __int8 v24; // cl
	unsigned __int8 v25; // dl
	signed int v26; // eax
	signed int v27; // eax
	signed int v28; // eax
	int v29; // eax
	char *v30; // esi
	int v31; // eax
	int v32; // ecx
	int v33; // edi
	int v34; // edx
	int v35; // ecx
	char v36; // bl
	char *v37; // edi
	char *v38; // esi
	unsigned int v39; // ecx
	char *v40; // edi
	char *v41; // esi
	int v42; // ecx
	int v43; // edx
	char *v44; // esi
	char *v45; // edi
	int v46; // ecx
	char v47; // bl
	char *v48; // esi
	char *v49; // edi
	unsigned int v50; // ecx
	bool v51; // cc
	char *v53; // [esp-18h] [ebp-3Ch]
	char *v54; // [esp-14h] [ebp-38h]
	int v55; // [esp+4h] [ebp-20h]
	int v56; // [esp+8h] [ebp-1Ch]
	int v57; // [esp+Ch] [ebp-18h]
	unsigned int v58; // [esp+10h] [ebp-14h]
	signed int v59; // [esp+14h] [ebp-10h]
	signed int v60; // [esp+18h] [ebp-Ch]
	unsigned int v61; // [esp+1Ch] [ebp-8h]
	unsigned int v62; // [esp+20h] [ebp-4h]

	v62 = a7 + a3;
	v9 = a1[1] + 1;
	HIDWORD(v11) = (unsigned __int64)a3 >> 31;
	LODWORD(v11) = a3 - v9;
	v10 = v11 >> 31;
	HIDWORD(v11) = (unsigned __int64)(a7 + a3) >> 31;
	LODWORD(v11) = a7 + a3 - v9;
	v61 = a8 + a4;
	v12 = a1[2] + 1;
	HIDWORD(v11) = v11 >> 31;
	LODWORD(v11) = a8 + a4;
	v13 = v11 >> 31;
	HIDWORD(v11) = __PAIR64__(v10, a4) >> 31;
	LODWORD(v11) = a4 - v12;
	v14 = v11 >> 31;
	HIDWORD(v11) = v13;
	LODWORD(v11) = a8 + a4 - v12;
	v15 = v14 ^ 5;
	v16 = (unsigned int)(v11 >> 31) ^ 5;
	LOBYTE(v17) = v15;
	if (!(v16 & v15))
	{
		if (v16 | v15)
		{
			if (v15 & 8)
				a3 = 0;
			if (v15 & 2)
				a4 = 0;
			if (v16 & 4)
				v62 = a1[1];
			if (v16 & 1)
				v61 = a1[2];
		}
		v60 = v62 + a5 - a3;
		v59 = v61 + a6 - a4;
		v18 = a2[1] + 1;
		HIDWORD(v20) = (unsigned __int64)(unsigned int)a5 >> 31;
		LODWORD(v20) = a5 - v18;
		v19 = v20 >> 31;
		HIDWORD(v20) = (unsigned __int64)(v62 + a5 - a3) >> 31;
		LODWORD(v20) = v62 + a5 - a3 - v18;
		v21 = a2[2] + 1;
		HIDWORD(v20) = v20 >> 31;
		LODWORD(v20) = v61 + a6 - a4;
		v22 = v20 >> 31;
		HIDWORD(v20) = __PAIR64__(v19, a6) >> 31;
		LODWORD(v20) = a6 - v21;
		v23 = v20 >> 31;
		HIDWORD(v20) = v22;
		LODWORD(v20) = v61 + a6 - a4 - v21;
		v24 = v23 ^ 5;
		v25 = (unsigned int)(v20 >> 31) ^ 5;
		LOBYTE(v17) = v24;
		if (!(v25 & v24))
		{
			if (v25 | v24)
			{
				if (v24 & 8)
				{
					v26 = a5;
					a5 = 0;
					a3 -= v26;
				}
				if (v24 & 2)
				{
					v27 = a6;
					a6 = 0;
					a4 -= v27;
				}
				if (v25 & 4)
				{
					v28 = v60;
					v60 = a2[1];
					v62 -= v28 - v60;
				}
				if (v25 & 1)
					v59 = a2[2];
			}
			v29 = a1[6] + a1[1] + a1[3];
			v56 = v29;
			v30 = (char *)(a4 * v29 + a3 + *a1);
			v58 = a3 + v29 - v62;
			v31 = a2[6] + a2[1] + a2[3];
			v32 = v31;
			v55 = a2[6] + a2[1] + a2[3];
			v33 = a6 * v31 + a5 + *a2;
			v17 = v60 - a5;
			if (v60 > a5)
			{
				v57 = v32 - v17;
				v34 = v59 - a6;
				if (v59 > a6 && v30 != (char *)v33)
				{
					if ((int)v30 < v33)
					{
						v43 = v34 - 1;
						v44 = &v30[v17 - 1 + v43 * v56];
						v45 = (char *)(v43 * v55 + v17 + v33 - 1);
						if (a9 & 1)
							__asm { jmp[ebp + var_8] }
						if (v17 < 15)
						{
							do
							{
								qmemcpy(v45, v44, v17);
								v44 -= v56;
								v45 -= v55;
								v51 = v43-- < 1;
							} while (!v51);
						}
						else
						{
							do
							{
								v54 = v45;
								v53 = v44;
								v46 = ((_BYTE)v45 + 1) & 3;
								v47 = v17 - v46;
								qmemcpy(v45, v44, v46);
								v48 = &v44[v46 - 3];
								v49 = &v45[v46 - 3];
								v50 = (unsigned int)(v17 - v46) >> 2;
								qmemcpy(v49, v48, 4 * v50);
								qmemcpy(&v49[4 * v50 + 3], &v48[4 * v50 + 3], v47 & 3);
								v44 = &v53[-v56];
								v45 = &v54[-v55];
								v51 = v43-- < 1;
							} while (!v51);
						}
					}
					else
					{
						if (a9 & 1)
							__asm { jmp[ebp + var_8] }
						if (v17 < 10)
						{
							do
							{
								qmemcpy((void *)v33, v30, v17);
								v30 += v58 + v17;
								v33 += v32;
								--v34;
							} while (v34);
						}
						else
						{
							do
							{
								v35 = -v33 & 3;
								v36 = v17 - v35;
								qmemcpy((void *)v33, v30, v35);
								v38 = &v30[v35];
								v37 = (char *)(v33 + v35);
								v39 = (unsigned int)(v17 - v35) >> 2;
								qmemcpy(v37, v38, 4 * v39);
								v41 = &v38[4 * v39];
								v40 = &v37[4 * v39];
								v42 = v36 & 3;
								qmemcpy(v40, v41, v42);
								v30 = &v41[v42 + v58];
								v33 = (int)&v40[v42 + v57];
								--v34;
							} while (v34);
						}
					}
				}
			}
		}
	}
	return v17;
}
#endif

void __cdecl sub_559030(int a1, int a2, unsigned int a3, unsigned int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
	DebugBreak();
}

#if 0
//----- (00559030) --------------------------------------------------------
void __cdecl sub_559030(int a1, int a2, unsigned int a3, unsigned int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
	int v12; // edi
	unsigned int v13; // ecx
	unsigned __int64 v14; // rt0
	int v15; // edi
	int v16; // edx
	int v17; // ecx
	unsigned __int8 v18; // cl
	unsigned __int8 v19; // dl
	int v20; // edi
	unsigned int v21; // ecx
	unsigned __int64 v22; // rt0
	int v23; // edi
	int v24; // edx
	int v25; // ecx
	unsigned __int8 v26; // cl
	unsigned __int8 v27; // dl
	char v28; // bl
	int v29; // [esp+28h] [ebp-20h]
	int v30; // [esp+2Ch] [ebp-1Ch]
	int v31; // [esp+30h] [ebp-18h]
	int v32; // [esp+34h] [ebp-14h]

	if (a9)
	{
		if (a10)
		{
			if (a7)
			{
				if (a8)
				{
					v32 = a5;
					v31 = a6;
					v30 = a9 + a5;
					v29 = a10 + a6;
					v12 = *(_DWORD *)(a1 + 4) + 1;
					HIDWORD(v14) = (unsigned __int64)a3 >> 31;
					LODWORD(v14) = a3 - v12;
					v13 = v14 >> 31;
					HIDWORD(v14) = (unsigned __int64)(a7 + a3) >> 31;
					LODWORD(v14) = a7 + a3 - v12;
					v15 = *(_DWORD *)(a1 + 8) + 1;
					HIDWORD(v14) = v14 >> 31;
					LODWORD(v14) = a8 + a4;
					v16 = v14 >> 31;
					HIDWORD(v14) = __PAIR64__(v13, a4) >> 31;
					LODWORD(v14) = a4 - v15;
					v17 = v14 >> 31;
					HIDWORD(v14) = v16;
					LODWORD(v14) = a8 + a4 - v15;
					v18 = v17 ^ 5;
					v19 = (unsigned int)(v14 >> 31) ^ 5;
					if (!(v19 & v18))
					{
						if (v19 | v18)
						{
							if (v18 & 8)
								v32 = a5 + (unsigned __int64)(a9 * (__int64)-a3 / a7);
							if (v18 & 2)
								v31 = a6 + (unsigned __int64)(a10 * (__int64)-a4 / a8);
							if (v19 & 4)
								v30 = a5 + (unsigned __int64)(a9 * (__int64)(int)(*(_DWORD *)(a1 + 4) - a3) / a7);
							if (v19 & 1)
								v29 = a6 + (unsigned __int64)(a10 * (__int64)(int)(*(_DWORD *)(a1 + 8) - a4) / a8);
						}
						v20 = *(_DWORD *)(a2 + 4) + 1;
						HIDWORD(v22) = (unsigned __int64)(unsigned int)v32 >> 31;
						LODWORD(v22) = v32 - v20;
						v21 = v22 >> 31;
						HIDWORD(v22) = (unsigned __int64)(unsigned int)v30 >> 31;
						LODWORD(v22) = v30 - v20;
						v23 = *(_DWORD *)(a2 + 8) + 1;
						HIDWORD(v22) = v22 >> 31;
						LODWORD(v22) = v29;
						v24 = v22 >> 31;
						HIDWORD(v22) = __PAIR64__(v21, v31) >> 31;
						LODWORD(v22) = v31 - v23;
						v25 = v22 >> 31;
						HIDWORD(v22) = v24;
						LODWORD(v22) = v29 - v23;
						v26 = v25 ^ 5;
						v27 = (unsigned int)(v22 >> 31) ^ 5;
						if (!(v27 & v26))
						{
							if (v27 | v26)
							{
								if (v26 & 8)
									v32 = 0;
								if (v26 & 2)
									v31 = 0;
								if (v27 & 4)
									v30 = *(_DWORD *)(a2 + 4);
								if (v27 & 1)
									v29 = *(_DWORD *)(a2 + 8);
							}
							if (v29 > v31)
							{
								v28 = v30 - v32;
								if (v30 > v32)
								{
									if (!a11)
									{
										if (!a12)
											__asm { jmp[ebp + var_48] }
										__asm { jmp[ebp + var_48] }
									}
									if (!a12)
										__asm { jmp[ebp + var_48] }
									__asm { jmp[ebp + var_48] }
								}
							}
						}
					}
				}
			}
		}
	}
}
#endif
//----- (00559AA0) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
_DWORD *__thiscall sub_559AA0(_DWORD *this)
{
	_DWORD *result; // eax

	result = this;
	*this = 0;
	this[1] = 0;
	this[2] = 0;
	return result;
}

//----- (00559AB0) --------------------------------------------------------
int __thiscall sub_559AB0(int this)
{
	int result; // eax

	result = *(_DWORD *)(this + 8);
	if (result)
		operator_delete(*(LPVOID *)this);
	return result;
}

//----- (00559AD0) --------------------------------------------------------
_BYTE *__thiscall sub_559AD0(_BYTE *this)
{
	_BYTE *v1; // esi

	v1 = this;
	sub_559C30(this);
	return v1;
}

//----- (00559AF0) --------------------------------------------------------
char __thiscall sub_559AF0(char *this, LPCSTR lpFileName, int a3)
{
	char *v3; // ebx
	FILE *v4; // eax
	char result; // al
	unsigned int v6; // eax
	char *v7; // edi
	const CHAR *v8; // esi
	char v9; // cl
	unsigned __int8 *v10; // [esp-4h] [ebp-Ch]

	v3 = this;
	if (a3)
		v10 = "wb";
	else
		v10 = "rb";
	v4 = fopen(lpFileName, (const char *)v10);
	*(_DWORD *)v3 = v4;
	if (!v4)
		return 0;
	_stat(lpFileName, (int)(v3 + 4));
	v6 = strlen(lpFileName) + 1;
	qmemcpy(v3 + 40, lpFileName, 4 * (v6 >> 2));
	v8 = &lpFileName[4 * (v6 >> 2)];
	v7 = &v3[4 * (v6 >> 2) + 40];
	v9 = v6;
	result = 1;
	qmemcpy(v7, v8, v9 & 3);
	v3[300] = 1;
	return result;
}

//----- (00559B60) --------------------------------------------------------
bool __thiscall sub_559B60(int this)
{
	int v1; // esi
	int v2; // eax

	v1 = this;
	if (!*(_DWORD *)this || !*(_BYTE *)(this + 300))
		return 0;
	v2 = fclose(*(FILE **)this);
	*(_DWORD *)v1 = 0;
	*(_BYTE *)(v1 + 300) = 0;
	return v2 == 0;
}

//----- (00559BA0) --------------------------------------------------------
size_t __thiscall sub_559BA0(int this, void *a2, size_t a3)
{
	size_t result; // eax

	if (*(_DWORD *)this && *(_BYTE *)(this + 300))
		result = a3 * fread(a2, a3, 1u, *(FILE **)this);
	else
		result = 0;
	return result;
}

//----- (00559BE0) --------------------------------------------------------
bool __thiscall sub_559BE0(int this, int a2, int a3)
{
	bool result; // al

	if (*(_DWORD *)this && *(_BYTE *)(this + 300))
		result = fseek(*(FILE **)this, a2, a3) == 0;
	else
		result = 0;
	return result;
}

//----- (00559C10) --------------------------------------------------------
int __thiscall sub_559C10(_DWORD *this)
{
	int result; // eax

	if (*this && *((_BYTE *)this + 300))
		result = this[6];
	else
		result = -1;
	return result;
}

//----- (00559C30) --------------------------------------------------------
int __thiscall sub_559C30(_BYTE *this)
{
	int result; // eax

	result = 0;
	*(_DWORD *)this = 0;
	this[300] = 0;
	this[40] = 0;
	return result;
}

//----- (00559C40) --------------------------------------------------------
int __cdecl sub_559C40(int a1)
{
	unsigned __int8 *v1; // esi
	int result; // eax
	unsigned int v3; // ebx
	unsigned int v4; // eax
	unsigned int v5; // ecx
	int v6; // ecx
	unsigned __int16 v7; // cx
	unsigned int v8; // eax
	unsigned int v9; // ett
	unsigned int v10; // ecx

	v1 = &byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2515988];
	if (byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2516024] & 1)
		return *((_DWORD *)v1 + 7);
	v3 = sub_55A740(0);
	v4 = sub_559D00(a1, (unsigned int)v1, a1 + 64);
	if (v4 && v4 <= *((_DWORD *)v1 + 5))
	{
		v5 = *((_DWORD *)v1 + 6);
		if (v3 > v5)
		{
			*((_DWORD *)v1 + 6) = v3;
			v6 = v3 - v5 + *((_DWORD *)v1 + 7);
			*((_DWORD *)v1 + 7) = v6;
			return v6;
		}
	}
	else
	{
		*((_DWORD *)v1 + 5) = v4;
		*((_DWORD *)v1 + 6) = v3;
		v7 = *(_WORD *)(a1 + 60);
		v9 = 60 * (v4 / (*(unsigned __int8 *)(a1 + 62) * (*(unsigned __int8 *)(a1 + 63) >> 3)));
		v8 = 60 * (v4 / (*(unsigned __int8 *)(a1 + 62) * (*(unsigned __int8 *)(a1 + 63) >> 3))) / v7;
		*((_DWORD *)v1 + 7) = v9 / v7;
		v10 = *(_DWORD *)(a1 + 196);
		if (v8 >= v10)
		{
			result = v8 - v10;
			*((_DWORD *)v1 + 7) = result;
			return result;
		}
		*((_DWORD *)v1 + 7) = 0;
	}
	return *((_DWORD *)v1 + 7);
}
// 55A740: using guessed type int __cdecl sub_55A740(_DWORD);

//----- (00559D00) --------------------------------------------------------
int __cdecl sub_559D00(int a1, unsigned int a2, int a3)
{
	_DWORD *v3; // esi
	unsigned int v4; // ebp
	struct _RTL_CRITICAL_SECTION *v5; // ebx
	int v6; // edx
	int v7; // edi
	int v8; // esi
	unsigned int v9; // edi
	unsigned int v10; // eax
	unsigned int v11; // eax
	int v12; // edx
	int result; // eax
	int v14; // [esp+10h] [ebp-8h]
	int v15; // [esp+14h] [ebp-4h]
	int v16; // [esp+1Ch] [ebp+4h]

	v3 = (_DWORD *)a2;
	v4 = *(_DWORD *)(a2 + 156);
	v5 = (struct _RTL_CRITICAL_SECTION *)(a2 + 172);
	EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 172));
	v6 = v3[41];
	v7 = v3[40];
	v8 = v3[38];
	v14 = *(_DWORD *)(a1 + 56);
	v16 = v6;
	v9 = *(_DWORD *)(a3 + 92) * v7;
	if (!v8 || (*(int(__stdcall **)(int, unsigned int *, int *))(*(_DWORD *)v8 + 16))(v8, &a2, &v15))
		goto LABEL_10;
	if (v16)
	{
		v10 = a2;
	LABEL_9:
		v9 += v10;
		goto LABEL_10;
	}
	v11 = v4 >> 1;
	if (a2 >= v4 >> 1)
	{
		v9 += a2 - v11;
		goto LABEL_10;
	}
	if (v9)
	{
		v10 = a2 + v11;
		goto LABEL_9;
	}
LABEL_10:
	LeaveCriticalSection(v5);
	v12 = v14 * *(_DWORD *)(a3 + 92);
	result = v9 - v12;
	if (v9 - v12 > v9)
		result = 0;
	return result;
}

//----- (00559DB0) --------------------------------------------------------
int __cdecl sub_559DB0(DWORD_PTR dwUser, int a2, int a3, int a4)
{
	int result; // eax

	result = -1;
	switch (a2)
	{
	case 1:
		*(_DWORD *)(dwUser + 80) = sub_55A740;
		*(_DWORD *)(dwUser + 120) = 60;
		break;
	case 2:
		result = sub_559E80(dwUser, a3, a4);
		break;
	case 3:
		result = sub_55A0C0(dwUser);
		break;
	case 4:
		result = sub_55A130(dwUser);
		break;
	case 5:
		result = sub_55A2E0(dwUser, a3, a4);
		break;
	case 6:
		result = sub_55A360(dwUser);
		break;
	case 7:
		result = sub_55A3F0(dwUser);
		break;
	case 8:
		result = sub_55A3B0(dwUser);
		break;
	default:
		return result;
	}
	return result;
}
// 55A740: using guessed type int __cdecl sub_55A740(_DWORD);

//----- (00559E80) --------------------------------------------------------
int __cdecl sub_559E80(DWORD_PTR dwUser, int a2, int a3)
{
	int v3; // eax
	unsigned __int8 *v4; // ecx
	unsigned __int8 *v5; // esi
	int v6; // eax
	int v7; // edx
	unsigned int v8; // ecx
	MMRESULT v9; // eax
	__int16 v10; // dx
	unsigned __int16 v11; // ax
	int result; // eax
	WAVEFORMATEX waveFormat; // [esp+18h] [ebp-98h]
	DSBUFFERDESC dsBufferDesc; // [esp+2Ch] [ebp-84h]
	DSCAPS v15; // [esp+50h] [ebp-60h]

	if (!g_dsound)
		return -13;
	v3 = 0;
	v4 = &byte_5D4594[2515988];
	do
	{
		if (!*(_DWORD *)v4)
			break;
		v4 += 200;
		++v3;
	} while ((int)v4 < (int)&byte_5D4594[2516188]);
	if (v3 == 1 || a3 != 16)
		return -13;
	*(_DWORD *)(dwUser + 52) = v3;
	v5 = &byte_5D4594[200 * v3 + 2515988];
	memset(v5, 0, 0xC8u);
	*(_DWORD *)v5 = 1;
	*((_DWORD *)v5 + 1) = *(_DWORD *)(dwUser + 164);
	InitializeCriticalSection((LPCRITICAL_SECTION)(v5 + 172));
	v6 = *(_DWORD *)(dwUser + 160);
	if (v6 == -1)
	{
		v7 = *(_DWORD *)(dwUser + 112);
		v8 = *(unsigned __int16 *)(dwUser + 14);
		*((_WORD *)v5 + 4) = v7 == (unsigned __int16)v8 ? *(_WORD *)a2 : (unsigned __int16)(v7
			* (unsigned int)*(unsigned __int16 *)a2
			/ v8);
	}
	else
	{
		*((_WORD *)v5 + 4) = v6;
	}
	memset(&v15, 0, sizeof(v15));
	v15.dwSize = 96;
	AIL_lock();
	g_dsound->lpVtbl->GetCaps(g_dsound, &v15);
	AIL_unlock();
	if (!(v15.dwFlags & 0x20))
		*(_DWORD *)(dwUser + 196) = 0;
	v5[10] = *(_BYTE *)(a2 + 2);
	v5[11] = *(_BYTE *)(a2 + 3);
	*((_DWORD *)v5 + 8) = *(_DWORD *)(a2 + 4);
	*(_DWORD *)&byte_5D4594[2515980] = *(_DWORD *)(a2 + 8);
	*(_DWORD *)&byte_5D4594[2515984] = *(_DWORD *)(a2 + 12);
	if (timeBeginPeriod(0x10u) == 97)
		return -13;
	v9 = timeSetEvent(0x10u, 1u, fptc, dwUser, 1u);
	*((_DWORD *)v5 + 23) = v9;
	if (!v9)
		return -13;
	memset(&dsBufferDesc, 0, 0x24u);
	v10 = *(unsigned __int8 *)(a2 + 2);
	*(_DWORD *)&waveFormat.wFormatTag = 0;
	dsBufferDesc.dwFlags = 1;
	waveFormat.nSamplesPerSec = 0;
	waveFormat.wFormatTag = 1;
	v11 = *(unsigned __int8 *)(a2 + 3);
	waveFormat.nAvgBytesPerSec = 0;
	waveFormat.nChannels = v10;
	*(_DWORD *)&waveFormat.nBlockAlign = 0;
	waveFormat.wBitsPerSample = v11;
	waveFormat.cbSize = 0;
	waveFormat.nSamplesPerSec = *(unsigned __int16 *)a2;
	waveFormat.nBlockAlign = v10 * (v11 >> 3);
	dsBufferDesc.dwSize = 36;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * (unsigned __int16)(v10 * (v11 >> 3));
	AIL_lock();
	if (g_dsound->lpVtbl->CreateSoundBuffer(g_dsound, &dsBufferDesc, &g_dsound_buffer, 0) >= 0)
	{
		AIL_unlock();
		g_dsound_buffer->lpVtbl->SetFormat(g_dsound_buffer, &waveFormat);
		result = -1;
	}
	else
	{
		AIL_unlock();
		result = 0;
	}
	return result;
}
// 5813E8: using guessed type _DWORD __stdcall AIL_unlock();
// 5813EC: using guessed type _DWORD __stdcall AIL_lock();

//----- (0055A0C0) --------------------------------------------------------
int __cdecl sub_55A0C0(int a1)
{
	unsigned __int8 *v1; // esi

	v1 = &byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2515988];
	if (*(_DWORD *)&byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2515988] == 1)
	{
		if (*((_DWORD *)v1 + 38))
			sub_55A3F0(a1);
		timeKillEvent(*((_DWORD *)v1 + 23));
		*((_DWORD *)v1 + 23) = 0;
		timeEndPeriod(0x10u);
		*(_DWORD *)v1 = 0;
		DeleteCriticalSection((LPCRITICAL_SECTION)(v1 + 172));
	}
	return -1;
}

//----- (0055A130) --------------------------------------------------------
int __cdecl sub_55A130(int a1)
{
	unsigned __int8 *v1; // esi
	int v2; // eax
	LPDIRECTSOUNDBUFFER v3; // eax
	int result; // eax
	LPDIRECTSOUNDBUFFER v5; // eax
	LPDIRECTSOUNDBUFFER *v6; // ebx
	unsigned __int16 v7; // ax
	__int16 v8; // dx
	int v9; // ecx
	unsigned __int16 v10; // ax
	LPDIRECTSOUNDBUFFER v11; // eax
	struct _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+30h] [ebp-4h]

	v1 = &byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2515988];
	v2 = *(_DWORD *)&byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2516024];
	if (v2 & 1 && (LOBYTE(v2) = v2 & 0xFE, *((_DWORD *)v1 + 9) = v2, (v3 = *((_DWORD *)v1 + 38)) != 0))
	{
		(*(void(__stdcall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v3 + 48))(v3, 0, 0, 1);
		result = -1;
	}
	else
	{
		lpCriticalSection = (struct _RTL_CRITICAL_SECTION *)(v1 + 172);
		EnterCriticalSection((LPCRITICAL_SECTION)(v1 + 172));
		v5 = *(LPDIRECTSOUNDBUFFER *)(v1 + 152);
		v6 = (LPDIRECTSOUNDBUFFER *)(v1 + 152);
		if (v5)
		{
			v5->lpVtbl->Stop(*(IDirectSoundBuffer **)(v1 + 152));
			(*v6)->lpVtbl->Release(*v6);
			*v6 = 0;
		}
		*((_DWORD *)v1 + 39) = 2 * *(_DWORD *)(a1 + 156);
		memset(v1 + 96, 0, 0x24u);
		*((_DWORD *)v1 + 26) = *((_DWORD *)v1 + 39);
		*((_DWORD *)v1 + 24) = 36;
		*((_DWORD *)v1 + 25) = 65760;
		*((_DWORD *)v1 + 28) = v1 + 132;
		*((_DWORD *)v1 + 33) = 0;
		*((_DWORD *)v1 + 34) = 0;
		*((_DWORD *)v1 + 35) = 0;
		*((_DWORD *)v1 + 36) = 0;
		*((_WORD *)v1 + 74) = 0;
		*((_WORD *)v1 + 66) = 1;
		v7 = v1[11];
		v8 = v1[10];
		*((_WORD *)v1 + 73) = v7;
		v9 = *((unsigned __int16 *)v1 + 4);
		v10 = v8 * (v7 >> 3);
		*((_WORD *)v1 + 72) = v10;
		*((_DWORD *)v1 + 34) = v9;
		*((_WORD *)v1 + 67) = v8;
		*((_DWORD *)v1 + 35) = v9 * v10;
		AIL_lock();
		g_dsound->lpVtbl->CreateSoundBuffer(g_dsound, (LPCDSBUFFERDESC)(v1 + 96), (LPDIRECTSOUNDBUFFER *)(v1 + 152), 0);
		AIL_unlock();
		if (*v6)
		{
			(*(void(__cdecl **)(_DWORD))&byte_5D4594[2515980])(a1);
			(*(void(__cdecl **)(_DWORD))&byte_5D4594[2515980])(a1);
			v11 = *v6;
			*((_DWORD *)v1 + 16) = 0;
			*((_DWORD *)v1 + 42) = 0;
			*((_DWORD *)v1 + 40) = 0;
			v11->lpVtbl->SetCurrentPosition(v11, 0);
			if ((*v6)->lpVtbl->Play(*v6, 0, 0, 1))
			{
				LeaveCriticalSection(lpCriticalSection);
				result = -13;
			}
			else
			{
				LeaveCriticalSection(lpCriticalSection);
				result = -1;
			}
		}
		else
		{
			LeaveCriticalSection(lpCriticalSection);
			result = -13;
		}
	}
	return result;
}
// 5813E8: using guessed type _DWORD __stdcall AIL_unlock();
// 5813EC: using guessed type _DWORD __stdcall AIL_lock();

//----- (0055A2E0) --------------------------------------------------------
int __cdecl sub_55A2E0(int a1, int a2, int a3)
{
	unsigned __int8 *v3; // edi
	int v4; // esi
	int v5; // eax

	v3 = &byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2515988];
	if (!a2)
		return -13;
	if (!a3)
		return -13;
	v4 = *((_DWORD *)v3 + 15);
	if (*(_DWORD *)&v3[4 * v4 + 68] == 1)
		return -13;
	*(_DWORD *)&v3[4 * v4 + 76] = a2;
	*(_DWORD *)&v3[4 * v4 + 84] = a3;
	*(_DWORD *)&v3[4 * v4 + 68] = 1;
	AIL_lock();
	sub_55A610((char *)a1);
	AIL_unlock();
	v5 = v4 + 1;
	if (v4 + 1 >= 2)
		v5 = 0;
	*((_DWORD *)v3 + 15) = v5;
	return -1;
}
// 5813E8: using guessed type _DWORD __stdcall AIL_unlock();
// 5813EC: using guessed type _DWORD __stdcall AIL_lock();

//----- (0055A360) --------------------------------------------------------
int __cdecl sub_55A360(int a1)
{
	unsigned __int8 *v1; // esi
	int v2; // eax

	v1 = &byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2515988];
	EnterCriticalSection((LPCRITICAL_SECTION)(v1 + 172));
	if (*(_DWORD *)v1)
	{
		v2 = *((_DWORD *)v1 + 38);
		if (v2)
			(*(void(__stdcall **)(_DWORD))(*(_DWORD *)v2 + 72))(*((_DWORD *)v1 + 38));
	}
	*((_DWORD *)v1 + 9) |= 1u;
	LeaveCriticalSection((LPCRITICAL_SECTION)(v1 + 172));
	return -1;
}

//----- (0055A3B0) --------------------------------------------------------
int __cdecl sub_55A3B0(int a1)
{
	int v1; // eax
	int result; // eax

	if (!*(_DWORD *)&byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2515988]
		|| (v1 = *(_DWORD *)&byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2516140]) == 0
		|| (result = (*(int(__stdcall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v1 + 48))(v1, 0, 0, 1)) != 0)
	{
		result = -13;
	}
	return result;
}

//----- (0055A3F0) --------------------------------------------------------
int __cdecl sub_55A3F0(int a1)
{
	unsigned __int8 *v1; // esi
	int v2; // eax

	v1 = &byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2515988];
	if (!*(_DWORD *)&byte_5D4594[200 * *(_DWORD *)(a1 + 52) + 2516140])
		return -1;
	EnterCriticalSection((LPCRITICAL_SECTION)(v1 + 172));
	v2 = *((_DWORD *)v1 + 38);
	if (v2)
	{
		(*(void(__stdcall **)(_DWORD))(*(_DWORD *)v2 + 72))(*((_DWORD *)v1 + 38));
		(*(void(__stdcall **)(_DWORD))(**((_DWORD **)v1 + 38) + 8))(*((_DWORD *)v1 + 38));
		*((_DWORD *)v1 + 38) = 0;
	}
	*((_DWORD *)v1 + 15) = 0;
	*((_DWORD *)v1 + 16) = 0;
	*((_DWORD *)v1 + 17) = 0;
	*((_DWORD *)v1 + 18) = 0;
	LeaveCriticalSection((LPCRITICAL_SECTION)(v1 + 172));
	return -1;
}

//----- (0055A470) --------------------------------------------------------
void __stdcall fptc(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	DWORD v5; // ebp
	unsigned __int8 *v6; // esi
	int v7; // eax
	int v8; // edi
	unsigned int v9; // eax
	int v10; // eax
	int v11; // edi
	int v12; // [esp+28h] [ebp-14h]
	int v13; // [esp+2Ch] [ebp-10h]
	int v14; // [esp+30h] [ebp-Ch]
	volatile LONG *lpAddend; // [esp+34h] [ebp-8h]
	int v16; // [esp+38h] [ebp-4h]
	struct _RTL_CRITICAL_SECTION *dwUsera; // [esp+48h] [ebp+Ch]

	v5 = dwUser;
	v12 = 0;
	v6 = &byte_5D4594[200 * *(_DWORD *)(dwUser + 52) + 2515988];
	lpAddend = (volatile LONG *)(v6 + 196);
	if (InterlockedIncrement((volatile LONG *)v6 + 49) != 1 || v6[36] & 1)
		goto LABEL_20;
	dwUsera = (struct _RTL_CRITICAL_SECTION *)(v6 + 172);
	EnterCriticalSection((LPCRITICAL_SECTION)(v6 + 172));
	v7 = *((_DWORD *)v6 + 38);
	if (!v7
		|| *((_DWORD *)v6 + 23) != uTimerID
		|| ((*(void(__stdcall **)(int, int *))(*(_DWORD *)v7 + 36))(v7, &v13), !(v13 & 5)))
	{
		LeaveCriticalSection(dwUsera);
	LABEL_20:
		InterlockedDecrement((volatile LONG *)v6 + 49);
		return;
	}
	v8 = 0;
	if ((*(int(__stdcall **)(_DWORD, int *, int *))(**((_DWORD **)v6 + 38) + 16))(*((_DWORD *)v6 + 38), &v14, &v16) == -2005401450)
	{
		(*(void(__stdcall **)(_DWORD))(**((_DWORD **)v6 + 38) + 80))(*((_DWORD *)v6 + 38));
		(*(void(__stdcall **)(_DWORD))(**((_DWORD **)v6 + 38) + 72))(*((_DWORD *)v6 + 38));
		v8 = 1;
		v12 = 1;
		(*(void(__stdcall **)(_DWORD, _DWORD))(**((_DWORD **)v6 + 38) + 52))(*((_DWORD *)v6 + 38), 0);
		*((_DWORD *)v6 + 41) = 0;
		*((_DWORD *)v6 + 42) = 0;
	}
	v9 = *((_DWORD *)v6 + 42);
	if (v14 < v9 || (unsigned int)v14 >= *((_DWORD *)v6 + 39) >> 1 && !v9 || v8)
	{
		(*(void(__cdecl **)(_DWORD, _DWORD))&byte_5D4594[2515984])(v5, *(_DWORD *)&v6[4 * *((_DWORD *)v6 + 16) + 76]);
		v10 = *((_DWORD *)v6 + 16);
		v11 = v10 + 1;
		++*((_DWORD *)v6 + 40);
		if (v10 + 1 >= 2)
			v11 = 0;
		*(_DWORD *)&v6[4 * v10 + 68] = 0;
		(*(void(__cdecl **)(_DWORD))&byte_5D4594[2515980])(v5);
		if (*(_DWORD *)&v6[4 * v11 + 68])
			*((_DWORD *)v6 + 16) = v11;
		if (v12)
			(*(void(__stdcall **)(_DWORD, _DWORD, _DWORD, int))(**((_DWORD **)v6 + 38) + 48))(*((_DWORD *)v6 + 38), 0, 0, 1);
	}
	LeaveCriticalSection(dwUsera);
	InterlockedDecrement(lpAddend);
}

//----- (0055A610) --------------------------------------------------------
int __cdecl sub_55A610(char *a1)
{
	unsigned __int8 *v1; // ebx
	int result; // eax
	int v3; // ecx
	int v4; // esi
	int v5; // ebp
	unsigned int v6; // ecx
	unsigned int v7; // eax
	char *v8; // esi
	char *v9; // edi
	char *v10; // esi
	char *v11; // edi
	char *v12; // edi
	char *v13; // esi
	char v14; // cl
	char v15; // al
	unsigned int v16; // ecx
	int v17; // eax
	unsigned int v18; // eax
	unsigned int v19; // ecx
	unsigned int v20; // [esp+28h] [ebp-10h]
	void *v21; // [esp+2Ch] [ebp-Ch]
	int v22; // [esp+30h] [ebp-8h]
	int v23; // [esp+34h] [ebp-4h]

	v1 = &byte_5D4594[200 * *((_DWORD *)a1 + 13) + 2515988];
	result = *(_DWORD *)&byte_5D4594[200 * *((_DWORD *)a1 + 13) + 2516140];
	if (!result)
		return result;
	v3 = *((_DWORD *)a1 + 39);
	v4 = *(_DWORD *)result;
	v23 = *((_DWORD *)v1 + 42);
	if ((*(int(__stdcall **)(int, int, int, void **, unsigned int *, char **, int *, _DWORD))(v4 + 44))(
		result,
		v23,
		v3,
		&v21,
		&v20,
		&a1,
		&v22,
		0))
	{
		return 0;
	}
	v5 = *((_DWORD *)v1 + 15);
	if (*(_DWORD *)&v1[4 * v5 + 84] <= v20)
	{
		v8 = *(char **)&v1[4 * v5 + 76];
		v9 = (char *)v21;
		v6 = *(_DWORD *)&v1[4 * v5 + 84];
		goto LABEL_9;
	}
	qmemcpy(v21, *(const void **)&v1[4 * v5 + 76], v20);
	v6 = v22;
	v7 = *(_DWORD *)&v1[4 * v5 + 84] - v20;
	if (v7 > v22)
	{
		v8 = *(char **)&v1[4 * v5 + 76];
		v9 = a1;
	LABEL_9:
		v15 = v6;
		v16 = v6 >> 2;
		qmemcpy(v9, v8, 4 * v16);
		v13 = &v8[4 * v16];
		v12 = &v9[4 * v16];
		v14 = v15;
		goto LABEL_10;
	}
	v10 = *(char **)&v1[4 * v5 + 76];
	v11 = a1;
	qmemcpy(a1, v10, 4 * (v7 >> 2));
	v13 = &v10[4 * (v7 >> 2)];
	v12 = &v11[4 * (v7 >> 2)];
	v14 = v7;
LABEL_10:
	qmemcpy(v12, v13, v14 & 3);
	(*(void(__stdcall **)(_DWORD, void *, unsigned int, char *, int))(**((_DWORD **)v1 + 38) + 76))(
		*((_DWORD *)v1 + 38),
		v21,
		v20,
		a1,
		v22);
	v17 = v23;
	*((_DWORD *)v1 + 41) = v23;
	v18 = *(_DWORD *)&v1[4 * v5 + 84] + v17;
	v19 = *((_DWORD *)v1 + 39);
	*((_DWORD *)v1 + 42) = v18;
	if (v18 >= v19)
		*((_DWORD *)v1 + 42) = 0;
	return 1;
}

//----- (0055A750) --------------------------------------------------------
int sub_55A750()
{
	return 1;
}

//----- (0055A760) --------------------------------------------------------
void __cdecl sub_55A760(void *a1)
{
	qmemcpy(a1, &byte_587000[300360], 0x88u);
}

//----- (0055A780) --------------------------------------------------------
char *__cdecl sub_55A780(char *a1)
{
	return sub_556A20(a1);
}

//----- (0055A790) --------------------------------------------------------
int __cdecl sub_55A790(int a1)
{
	int result; // eax

	for (result = 0; result < 768; ++result)
		*(_BYTE *)(result + a1) *= 4;
	return result;
}

//----- (0055A7B0) --------------------------------------------------------
int __cdecl sub_55A7B0(int a1, int a2, _DWORD *a3)
{
	_DWORD *v3; // esi
	bool v4; // zf
	int result; // eax
	int(__cdecl *v6)(_DWORD, int, _DWORD, int); // eax
	_WORD *v7; // eax
	_WORD *v8; // ebx
	int v9; // eax
	int(__cdecl **v10)(int, int, char *, int); // ebp
	const char *v11; // esi
	signed int v12; // ecx
	int v13; // edx
	int v14; // eax
	_WORD *v15; // esi
	int v16; // eax
	int v17; // eax
	int v18; // eax
	int v19; // eax
	int v20; // eax
	char v21; // al
	int v22; // eax
	int v23; // eax
	int v24; // edx
	int v25; // eax
	int v26; // edx
	int v27; // eax
	int v28; // eax
	unsigned __int8 v29[8]; // [esp+10h] [ebp-8h]

	v3 = (_DWORD *)a2;
	v4 = a2 == 0;
	*a3 = 0;
	if (v4)
		return -17;
	if (!v3[4])
		return -15;
	if (!v3[14])
		return -16;
	v6 = (int(__cdecl *)(_DWORD, int, _DWORD, int))v3[1];
	if (v6)
	{
		v9 = v6(0, 2, 0, 2012);
		v8 = (_WORD *)v9;
		if (v9)
		{
			((void(__cdecl *)(int, int, int, int))v3[1])(v9, 4, v9, 2012);
			goto LABEL_12;
		}
		return -8;
	}
	v7 = sub_562770(0, 2, 0, 2012);
	v8 = v7;
	if (!v7)
		return -8;
	sub_562770((int)v7, 4, v7, 2012);
LABEL_12:
	v10 = (int(__cdecl **)(int, int, char *, int))(v8 + 32);
	memset(v8, 0, 0x7DCu);
	*((_DWORD *)v8 + 12) = 2012;
	qmemcpy(v8 + 32, v3, 0x88u);
	if (!*((_DWORD *)v8 + 17))
		*((_DWORD *)v8 + 17) = sub_562770;
	if (!*v10)
		*v10 = sub_562930;
	v11 = (const char *)a1;
	if ((*v10)((int)v8, 3, (char *)a1, 0))
	{
		(*((void(__cdecl **)(_WORD *, int, _WORD *, int))v8 + 17))(v8, 5, v8, 2012);
		(*((void(__cdecl **)(_WORD *, int, _WORD *, _DWORD))v8 + 17))(v8, 3, v8, 0);
		return -3;
	}
	v12 = strlen(v11) - 31;
	if (v12 < 0)
		v12 = 0;
	strcpy((char *)v8 + 200, &v11[v12]);
	if ((*v10)((int)v8, 5, (char *)v29, 8))
	{
		sub_55AE50((int)v8);
		return -4;
	}
	if (*(_DWORD *)v29 != 1297239878 || !*(_DWORD *)&v29[4])
		goto LABEL_27;
	if ((*v10)((int)v8, 5, (char *)v29, 4))
	{
		sub_55AE50((int)v8);
		return -4;
	}
	if (*(_DWORD *)v29 != 1095849559)
	{
	LABEL_27:
		sub_55AE50((int)v8);
		return -7;
	}
	while (1)
	{
		while (1)
		{
			while (1)
			{
				while (1)
				{
					if ((*v10)((int)v8, 5, (char *)v29, 8))
						goto LABEL_109;
					v13 = ((*(_DWORD *)&v29[4] << 16) | *(_WORD *)&v29[4] & 0xFF00) << 8;
					v14 = v13 | ((*(unsigned __int16 *)&v29[6] | *(_DWORD *)&v29[4] & 0xFF0000u) >> 8);
					*(_DWORD *)&v29[4] = v13 | ((*(unsigned __int16 *)&v29[6] | *(_DWORD *)&v29[4] & 0xFF0000u) >> 8);
					if (*(_DWORD *)v29 <= 0x464E4950u)
						break;
					switch (*(_DWORD *)v29)
					{
					case 0x4943464D:
						if (sub_55E5B0((int)v8) != -1)
							goto LABEL_109;
						break;
					case 0x4943534D:
						if (sub_55E8B0((int)v8) != -1)
							goto LABEL_109;
						break;
					case 0x50494C43:
						if (sub_55E3D0((int)v8, v14) != -1)
							goto LABEL_109;
						break;
					default:
						goto LABEL_57;
					}
				}
				if (*(_DWORD *)v29 != 1179535696)
					break;
				if (sub_55F020((int)v8) != -1)
					goto LABEL_109;
			}
			if (*(_DWORD *)v29 <= 0x464E4946u)
				break;
			if (*(_DWORD *)v29 != 1179535692)
				goto LABEL_57;
			if (sub_55E400((int)v8) != -1)
				goto LABEL_109;
		}
		if (*(_DWORD *)v29 == 1179535686)
			break;
		if (*(_DWORD *)v29 == 1145590102)
		{
			if (v14 != 42)
				goto LABEL_27;
			v15 = v8 + 116;
			if ((*v10)((int)v8, 5, (char *)v8 + 232, 42))
				goto LABEL_109;
			*v8 = *v15;
			*((_DWORD *)v8 + 4) = (unsigned __int16)v8[118];
			v8[1] = v8[119];
			v8[2] = v8[120];
			v8[6] = *((unsigned __int8 *)v8 + 264);
			v8[7] = *((unsigned __int8 *)v8 + 244);
			if (*((int *)v8 + 28) == -1)
				*((_DWORD *)v8 + 28) = *((unsigned __int8 *)v8 + 244);
			if (*((int *)v8 + 29) == -1)
				*((_DWORD *)v8 + 29) = *((unsigned __int8 *)v8 + 244);
			v16 = *((_DWORD *)v8 + 29);
			if (v16 == -1 || !v16)
				*((_DWORD *)v8 + 29) = *((unsigned __int8 *)v8 + 244);
			if (*v15 > 1u && !(v8[117] & 2))
			{
				v17 = *((_DWORD *)v8 + 33);
				LOBYTE(v17) = v17 & 0xBF;
				*((_DWORD *)v8 + 33) = v17;
			}
		}
		else if (*(_DWORD *)v29 == 1179535683)
		{
			if (sub_55EE60((int)v8) != -1)
				goto LABEL_109;
		}
		else
		{
		LABEL_57:
			v18 = v14 + 1;
			LOBYTE(v18) = v18 & 0xFE;
			if ((*v10)((int)v8, 7, (char *)1, v18))
			{
				sub_55AE50((int)v8);
				return -6;
			}
		}
	}
	if (sub_561980((int)v8) != -1)
	{
	LABEL_95:
		sub_55AE50((int)v8);
		return -8;
	}
	if (sub_55F1D0((int)v8, *(int *)&v29[4]) != -1)
		goto LABEL_109;
	if (!*((_BYTE *)v8 + 264) && !v8[940])
		v8[940] = sub_55BA50((int)v8);
	sub_55B820((int)v8);
	if (!(v8[117] & 1))
	{
		v19 = *((_DWORD *)v8 + 33);
		LOBYTE(v19) = v19 & 0xFE;
		*((_DWORD *)v8 + 33) = v19;
	}
	v20 = *((_DWORD *)v8 + 33);
	if (v20 & 1)
	{
		if (!*((_DWORD *)v8 + 22))
		{
			sub_55AE50((int)v8);
			return -21;
		}
		if (v20 & 0x40)
		{
			v8[30] = v8[130];
			*((_BYTE *)v8 + 62) = *((_BYTE *)v8 + 262);
			v21 = *((_BYTE *)v8 + 263);
		}
		else
		{
			v8[30] = v8[128];
			*((_BYTE *)v8 + 62) = *((_BYTE *)v8 + 258);
			v21 = *((_BYTE *)v8 + 259);
		}
		*((_BYTE *)v8 + 63) = v21;
		if (sub_561430((int)v8) != -1)
		{
			sub_55AE50((int)v8);
			return -13;
		}
		sub_55A750();
		*((_DWORD *)v8 + 495) |= 0x40000000u;
		sub_560860((int)(v8 + 1000));
	}
	else if (*((_DWORD *)v8 + 22))
	{
		(*((void(__cdecl **)(_WORD *, int, _DWORD, _DWORD))v8 + 22))(v8, 1, 0, 0);
	}
	v22 = *((_DWORD *)v8 + 33);
	if (v22 & 0x20)
	{
		if (v22 & 0x100 && v8[906])
		{
			if ((*v10)((int)v8, 9, (char *)&a2, 0))
				a2 = 0;
			*((_DWORD *)v8 + 446) = sub_55BA80((int)v8, a2);
			(*((void(__cdecl **)(_WORD *, int, int *, _DWORD))v8 + 17))(v8, 6, &a1, 0);
			v23 = a1;
			if (a1 < 0)
			{
				v24 = (a2 <= 0) - 1;
				v23 = v24 & a2;
				a1 = v24 & a2;
			}
			if (*((_DWORD *)v8 + 446) > v23)
				*((_DWORD *)v8 + 446) = v23;
			if (*((_DWORD *)v8 + 446) > 0)
			{
				v25 = (*((int(__cdecl **)(_WORD *, int, _DWORD, _DWORD))v8 + 17))(v8, 2, 0, *((_DWORD *)v8 + 446));
				*((_DWORD *)v8 + 445) = v25;
				if (!v25)
					goto LABEL_95;
				(*((void(__cdecl **)(_WORD *, int, _DWORD, _DWORD))v8 + 17))(
					v8,
					4,
					*((_DWORD *)v8 + 445),
					*((_DWORD *)v8 + 446));
				v26 = *((_DWORD *)v8 + 446) + *((_DWORD *)v8 + 12);
				*((_DWORD *)v8 + 85) |= 4u;
				*((_DWORD *)v8 + 12) = v26;
				sub_55B8D0(v8);
			}
		}
		v27 = *((_DWORD *)v8 + 44);
		if (v27 < 0)
			v28 = sub_55B710((int)v8, 0, *((_DWORD *)v8 + 71), 0, 0);
		else
			v28 = sub_55B690((int)v8, v27, *((_DWORD *)v8 + 45), 2);
		if (v28 != -1)
		{
			sub_55AE50((int)v8);
			return -23;
		}
	}
	else
	{
		*((_DWORD *)v8 + 75) = *((_DWORD *)v8 + 71);
	}
	if (sub_55FC50((int)v8) != -1)
		return -3;
	if (v8[66] & 0x20 && (int)*((_DWORD *)v8 + 44) >= 0 || sub_55D6F0((int)v8) == -1)
	{
		result = -1;
		*a3 = v8;
	}
	else
	{
	LABEL_109:
		sub_55AE50((int)v8);
		result = -4;
	}
	return result;
}

//----- (0055AE50) --------------------------------------------------------
int __cdecl sub_55AE50(int a1)
{
	int v1; // eax

	if (*(_BYTE *)(a1 + 132) & 1)
	{
		if (*(_BYTE *)(a1 + 234) & 3)
		{
			sub_5614E0(a1);
			if (*(_DWORD *)(a1 + 1980) & 0x40000000)
			{
				sub_55A750();
				*(_DWORD *)(a1 + 1980) &= 0xBFFFFFFF;
			}
		}
	}
	if (*(_BYTE *)(a1 + 336) & 0x20)
	{
		v1 = *(_DWORD *)(a1 + 344);
		if (v1)
		{
			(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 5, v1, *(_DWORD *)(a1 + 348) * *(_DWORD *)(a1 + 352));
			(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 344), 0);
		}
	}
	sub_562120(a1);
	(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 64))(a1, 4, 0, 0);
	(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 5, a1, 2012);
	return (*(int(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 3, a1, 0);
}

//----- (0055AEF0) --------------------------------------------------------
int __cdecl sub_55AEF0(int a1, int a2, char a3)
{
	int v3; // edi
	int v4; // eax
	int(__cdecl *v5)(int); // eax
	int v6; // eax
	int v7; // edx
	int v8; // eax
	int v9; // eax
	int v10; // eax
	int v11; // eax
	int v12; // eax
	int v13; // eax
	int v14; // eax
	int v15; // eax
	int v16; // eax
	int v17; // eax
	int v18; // eax
	int v19; // eax
	int v20; // eax
	int v21; // eax
	int v22; // eax
	int v23; // eax
	int v24; // eax

	v3 = -1;
	if (!(*(_BYTE *)(a1 + 336) & 8))
	{
		v3 = sub_55FC40(a1);
		if (v3 != -1)
			return v3;
		if (!(*(_BYTE *)(a1 + 336) & 0x10))
			sub_562640(a1);
		if (*(_BYTE *)(a1 + 132) & 1 && **(_BYTE **)(a1 + 1940))
			sub_561530(a1);
		sub_562B60(a1, 60 * *(_DWORD *)(*(_DWORD *)(a1 + 416) + 28) / *(_DWORD *)(a1 + 116));
		*(_DWORD *)(a1 + 32) = sub_562BA0(a1);
		v4 = *(_DWORD *)(a1 + 336);
		LOBYTE(v4) = v4 | 8;
		*(_DWORD *)(a1 + 336) = v4;
	}
	v5 = *(int(__cdecl **)(int))(a1 + 84);
	if (v5)
		v6 = v5(a1);
	else
		v6 = -1;
	v7 = *(_DWORD *)(a1 + 40);
	if (v7 == -1)
	{
		*(_DWORD *)(a1 + 40) = v6;
		*(_DWORD *)(a1 + 44) = 0;
	}
	else
	{
		*(_DWORD *)(a1 + 40) = v6;
		if (v6 - v7 > *(int *)(a1 + 44))
			*(_DWORD *)(a1 + 44) = v6 - v7;
	}
	v8 = *(_DWORD *)(a1 + 336);
	if (a2 != 2)
	{
		if (v8 & 0x40)
		{
			LOBYTE(v8) = v8 & 0xBF;
			*(_DWORD *)(a1 + 336) = v8;
			if (*(_BYTE *)(a1 + 132) & 1)
				sub_561530(a1);
			sub_562B60(a1, *(_DWORD *)(a1 + 36));
		}
		v9 = *(_DWORD *)(a1 + 336);
		if ((*(_BYTE *)(a1 + 336) & 6) != 6)
		{
			while (1)
			{
				if (!(v9 & 4))
				{
					v10 = sub_55CB20(a1, 0);
					v3 = v10;
					if (v10 == -1)
					{
						++*(_DWORD *)(a1 + 20);
					}
					else if (v10 != -9 && v10 != -11)
					{
						*(_DWORD *)(a1 + 336) |= 4u;
					}
					if (*(_DWORD *)(a1 + 132) & 0x200)
					{
						if (v10 == -9 || *(_BYTE *)(a1 + 336) & 4)
						{
							v13 = *(_DWORD *)(a1 + 336);
							if (v13 & 0x200)
							{
								if (!(v13 & 0x800))
								{
									BYTE1(v13) |= 4u;
									*(_DWORD *)(a1 + 336) = v13;
									if (*(_BYTE *)(a1 + 132) & 1)
										sub_561530(a1);
								}
							}
						}
						else
						{
							v11 = *(_DWORD *)(a1 + 1980);
							if (v11 & 0x400)
							{
								if (v11 & 0x40)
									sub_561560(a1);
								*(_DWORD *)(a1 + 336) |= 0x200u;
								v12 = *(_DWORD *)(a1 + 1980);
								BYTE1(v12) &= 0xFBu;
								*(_DWORD *)(a1 + 1980) = v12;
							}
						}
					}
				}
				if (!(*(_BYTE *)(a1 + 128) & 2))
					break;
				v20 = *(_DWORD *)(a1 + 336);
				LOBYTE(v20) = v20 | 2;
				*(_DWORD *)(a1 + 336) = v20;
				*(_DWORD *)(*(_DWORD *)(a1 + 416) + 20) = 0;
				*(_DWORD *)(a1 + 416) = *(_DWORD *)(*(_DWORD *)(a1 + 416) + 12);
			LABEL_62:
				if (a2 != 1)
				{
					v9 = *(_DWORD *)(a1 + 336);
					if ((*(_BYTE *)(a1 + 336) & 6) != 6)
						continue;
				}
				goto LABEL_80;
			}
			if (*(_DWORD *)(a1 + 132) & 0x200)
			{
				v14 = *(_DWORD *)(a1 + 336);
				if (v14 & 0x200)
				{
					if (v14 & 0x400)
					{
						BYTE1(v14) &= 0xF9u;
						*(_DWORD *)(a1 + 336) = v14;
					}
					else if (!(v14 & 0x800))
					{
						v3 = -10;
						goto LABEL_80;
					}
				}
			}
			if (a3 & 1)
			{
				v15 = *(_DWORD *)(a1 + 420);
				LOBYTE(v15) = v15 | 2;
			}
			else
			{
				if (!(a3 & 2))
					goto LABEL_50;
				v15 = *(_DWORD *)(a1 + 420) | 4;
			}
			*(_DWORD *)(a1 + 420) = v15;
		LABEL_50:
			v16 = (*(int(__cdecl **)(int))(a1 + 1916))(a1);
			v3 = v16;
			if (v16 == -1)
			{
				if (!(*(_BYTE *)(a1 + 420) & 8))
					++*(_DWORD *)(a1 + 24);
				v3 = sub_55B970(a1);
				if (v3 == -1)
				{
					v18 = *(_DWORD *)(a1 + 420);
					v3 = *(_DWORD *)(a1 + 1744);
					LOBYTE(v18) = v18 & 0xF9;
					*(_DWORD *)(a1 + 420) = v18;
					goto LABEL_62;
				}
				v17 = *(_DWORD *)(a1 + 336);
				LOBYTE(v17) = v17 | 6;
			}
			else
			{
				if (v16 != -9)
					goto LABEL_60;
				v17 = *(_DWORD *)(a1 + 336);
				if (!(v17 & 4))
					goto LABEL_60;
				LOBYTE(v17) = v17 | 2;
			}
			*(_DWORD *)(a1 + 336) = v17;
		LABEL_60:
			v19 = *(_DWORD *)(a1 + 420);
			LOBYTE(v19) = v19 & 0xF9;
			*(_DWORD *)(a1 + 420) = v19;
			goto LABEL_62;
		}
		goto LABEL_80;
	}
	if (!(v8 & 0x40))
	{
		LOBYTE(v8) = v8 | 0x40;
		*(_DWORD *)(a1 + 336) = v8;
		*(_DWORD *)(a1 + 36) = sub_562BA0(a1);
		if (*(_BYTE *)(a1 + 1980) & 0x40)
			sub_561560(a1);
	}
	if (!(a3 & 2))
	{
		v3 = -14;
		goto LABEL_80;
	}
	*(_DWORD *)(a1 + 420) |= 0x14u;
	v21 = (*(int(__cdecl **)(int))(a1 + 1916))(a1);
	v3 = v21;
	if (v21 != -1)
	{
		if (v21 != -9)
			goto LABEL_78;
		v22 = *(_DWORD *)(a1 + 336);
		if (!(v22 & 4))
			goto LABEL_78;
		LOBYTE(v22) = v22 | 2;
	LABEL_77:
		*(_DWORD *)(a1 + 336) = v22;
	LABEL_78:
		v24 = *(_DWORD *)(a1 + 420);
		LOBYTE(v24) = v24 & 0xE9;
		*(_DWORD *)(a1 + 420) = v24;
		goto LABEL_80;
	}
	v3 = sub_55B970(a1);
	if (v3 != -1)
	{
		v22 = *(_DWORD *)(a1 + 336);
		LOBYTE(v22) = v22 | 6;
		goto LABEL_77;
	}
	v23 = *(_DWORD *)(a1 + 420);
	v3 = *(_DWORD *)(a1 + 1744);
	LOBYTE(v23) = v23 & 0xE9;
	*(_DWORD *)(a1 + 420) = v23;
LABEL_80:
	if ((*(_BYTE *)(a1 + 336) & 6) == 6 || a2 == 3)
	{
		*(_DWORD *)(a1 + 36) = sub_562BA0(a1);
		if (*(_BYTE *)(a1 + 1980) & 0x40)
			sub_561590(a1);
		v3 = -2;
	}
	return v3;
}

//----- (0055B2D0) --------------------------------------------------------
int __cdecl sub_55B2D0(int a1, int a2)
{
	int v2; // esi
	int v3; // ebp
	char v4; // bl
	int v5; // edi
	int v6; // eax
	int v7; // ecx
	int v8; // eax
	int v9; // eax
	int v11; // [esp+8h] [ebp-4h]

	v2 = a1;
	v11 = *(_DWORD *)(a1 + 368);
	if (*(_BYTE *)(a1 + 1980) & 0x40)
		sub_561590(a1);
	v3 = a2;
	if (a2 <= *(int *)(v2 + 284) && *(_DWORD *)(v2 + 1892))
	{
		sub_55B8D0((_DWORD *)v2);
		sub_55FC40(v2);
		v4 = 0;
		if (!*(_BYTE *)(v2 + 264) && !sub_55D8C0(v2, v3))
		{
			v5 = sub_55D910(v2, v3, 1);
			if (v5 != -1)
				return v5;
			if (*(_BYTE *)(v11 + 20) & 4)
				v4 = 1;
		}
		*(_DWORD *)(v2 + 384) = v3;
		LOBYTE(a2) = ((unsigned __int8)~*(_BYTE *)(v2 + 234) >> 3) & 1;
		v5 = sub_55DB20((_DWORD *)v2, v3, *(unsigned __int8 *)(v2 + 245), a2, 1, (char *)&a1);
		if (v5 == -1)
		{
			v6 = *(_DWORD *)(v2 + 368);
			*(_DWORD *)(v2 + 384) = v3;
			*(_DWORD *)(v6 + 20) = 0;
			if (v4)
				*(_DWORD *)(*(_DWORD *)(v2 + 368) + 20) |= 4u;
			v7 = *(_DWORD *)(v2 + 368);
			v8 = *(_DWORD *)(v7 + 12);
			if (v8 != v7)
			{
				do
				{
					*(_DWORD *)(v8 + 20) = 0;
					v8 = *(_DWORD *)(v8 + 12);
				} while (v8 != *(_DWORD *)(v2 + 368));
			}
			*(_DWORD *)(v2 + 416) = *(_DWORD *)(v2 + 368);
			v9 = sub_55D6F0(v2);
			v5 = v9;
			if (v9 == -1 || v9 == -2)
			{
				v5 = v3;
				sub_562B60(v2, 60 * v3 / *(_DWORD *)(v2 + 116));
			}
		}
		return v5;
	}
	return -6;
}

//----- (0055B430) --------------------------------------------------------
int __cdecl sub_55B430(int a1, int a2, int a3)
{
	if (a2)
		*(_DWORD *)(a1 + 1924) = a2;
	else
		*(_DWORD *)(a1 + 1924) = nullsub_31;
	if (a3)
		*(_DWORD *)(a1 + 1928) = a3;
	else
		*(_DWORD *)(a1 + 1928) = nullsub_31;
	return -1;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0055B470) --------------------------------------------------------
int __cdecl sub_55B470(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6, int a7)
{
	int v7; // ecx
	char v8; // al
	int v9; // ebx
	int v10; // esi
	unsigned int v11; // edx
	unsigned int v12; // ebp
	unsigned int v13; // eax
	int v14; // esi
	int v15; // edi
	int v16; // eax
	int v17; // eax
	unsigned int v18; // edx
	unsigned int v19; // eax
	int v20; // eax
	int v22; // [esp+14h] [ebp+4h]
	unsigned int v23; // [esp+20h] [ebp+10h]

	v7 = a1;
	v8 = *(_BYTE *)(a1 + 264);
	v9 = *(_DWORD *)(a1 + 128) & 0x30;
	if (v8 == 1 || v8 == 4)
	{
		v22 = 1;
		v10 = 1;
	}
	else
	{
		v10 = 0;
		v22 = 0;
	}
	v11 = a3;
	if (!a3)
	{
		a3 = *(unsigned __int16 *)(v7 + 238);
		v11 = *(unsigned __int16 *)(v7 + 238);
	}
	v12 = a4;
	if (!a4)
		LOWORD(v12) = *(_WORD *)(v7 + 240);
	if (!a5)
	{
		if (!v10)
		{
			a5 = v11;
			goto LABEL_15;
		}
		a5 = 2 * v11;
	}
	if (!v10)
	{
	LABEL_15:
		v13 = a5;
		goto LABEL_16;
	}
	v13 = a5 >> 1;
LABEL_16:
	v14 = a6;
	v15 = a7;
	v23 = v13;
	if (a6 < 0 && a7 < 0)
	{
		v16 = *(_DWORD *)(v7 + 128);
		if (v16 & 8)
		{
			if (v16 & 0x40)
			{
				*(_DWORD *)(v7 + 436) = *(unsigned __int16 *)(v7 + 250) >> 1;
				v17 = *(unsigned __int16 *)(v7 + 252) >> 1;
			}
			else
			{
				*(_DWORD *)(v7 + 436) = *(unsigned __int16 *)(v7 + 250);
				v17 = *(unsigned __int16 *)(v7 + 252);
			}
		}
		else if (v16 & 0x40)
		{
			*(_DWORD *)(v7 + 436) = (v11 - (*(unsigned __int16 *)(v7 + 238) >> 1)) >> 1;
			v17 = (v12 - (*(unsigned __int16 *)(v7 + 240) >> 1)) >> 1;
		}
		else
		{
			*(_DWORD *)(v7 + 436) = (v11 - *(unsigned __int16 *)(v7 + 238)) >> 1;
			v17 = (v12 - *(unsigned __int16 *)(v7 + 240)) >> 1;
		}
		goto LABEL_32;
	}
	if (*(_BYTE *)(v7 + 128) & 0x40)
	{
		v14 = a6 / 2;
		v11 = a3;
		v15 = a7 / 2;
	}
	if (v9 == 32)
	{
		*(_DWORD *)(v7 + 436) = v11 - v14;
		v17 = v12 - v15;
	LABEL_32:
		*(_DWORD *)(v7 + 440) = v17;
		goto LABEL_33;
	}
	*(_DWORD *)(v7 + 436) = v14;
	if (v9 == 48)
		*(_DWORD *)(v7 + 440) = v12 - v15;
	else
		*(_DWORD *)(v7 + 440) = v15;
LABEL_33:
	v18 = *(_DWORD *)(v7 + 436);
	if ((v18 & 0x80000000) != 0)
		return -24;
	v19 = *(_DWORD *)(v7 + 440);
	if ((v19 & 0x80000000) != 0 || v18 >= a3 || v19 >= v12)
		return -24;
	if (v22)
		*(_DWORD *)(v7 + 444) = a5 * v19 + 2 * v18;
	else
		*(_DWORD *)(v7 + 444) = v18 + a5 * v19;
	*(_DWORD *)(v7 + 432) = v12;
	*(_DWORD *)(v7 + 428) = v23;
	if (a2)
	{
		*(_DWORD *)(v7 + 424) = a2;
		*(_DWORD *)(v7 + 8) = a2;
	}
	v20 = *(_DWORD *)(v7 + 336);
	LOBYTE(v20) = v20 | 0x10;
	*(_DWORD *)(v7 + 336) = v20;
	return -1;
}

//----- (0055B690) --------------------------------------------------------
int __cdecl sub_55B690(int a1, int a2, int a3, int a4)
{
	int v4; // edx
	unsigned __int16 v5; // ax
	int v6; // ecx
	int result; // eax

	if (a2 >= *(unsigned __int16 *)(a1 + 1812) || a2 < 0 || *(_BYTE *)(a1 + 132) & 1 && !*(_WORD *)(a1 + 1812))
		return -23;
	v4 = *(_DWORD *)(a1 + 1820);
	v5 = *(_WORD *)(v4 + 4 * a2);
	v6 = *(unsigned __int16 *)(v4 + 4 * a2 + 2);
	*(_DWORD *)(a1 + 288) = a2;
	result = sub_55B710(a1, v5, v6, a3, a4);
	if (result == -1)
		*(_DWORD *)(a1 + 288) = a2;
	return result;
}

//----- (0055B710) --------------------------------------------------------
int __cdecl sub_55B710(int a1, int a2, int a3, int a4, int a5)
{
	int v5; // edx
	int v6; // edi
	int result; // eax
	int v8; // esi
	int v9; // edi
	int v10; // ebx

	v5 = a2;
	v6 = *(_DWORD *)(a1 + 16);
	result = -1;
	if (a2 >= v6)
		return -23;
	v8 = a3;
	if (a3 >= v6)
		return -23;
	if (a2 >= a3)
		return -23;
	v9 = a5;
	if (a5 < 0 || a5 >= 3)
		return -23;
	v10 = a4;
	if (a4 < 0)
		v10 = -1;
	if (*(_DWORD *)(a1 + 292) || a5 != 1)
	{
		if (a5 != 2)
		{
			if ((signed char)*(_BYTE *)(a1 + 336) >= 0)
			{
				*(_DWORD *)(a1 + 324) = a2;
				*(_DWORD *)(a1 + 320) = a3;
			}
			else
			{
				*(_DWORD *)(a1 + 316) = a2;
				if (a5)
				{
					v5 = *(_DWORD *)(a1 + 296);
					*(_DWORD *)(a1 + 312) = *(_DWORD *)(a1 + 300);
				}
				else
				{
					*(_DWORD *)(a1 + 312) = a3;
					v8 = *(_DWORD *)(a1 + 300);
				}
			}
		}
	}
	else
	{
		v9 = 2;
	}
	*(_DWORD *)(a1 + 296) = v5;
	if (v9 == 1)
	{
		*(_DWORD *)(a1 + 304) = v8;
		*(_DWORD *)(a1 + 308) = v10;
	}
	else
	{
		*(_DWORD *)(a1 + 292) = v10;
		if (v9 == 2)
		{
			*(_DWORD *)(a1 + 300) = v8;
			*(_DWORD *)(a1 + 284) = v8;
			result = sub_55B2D0(a1, v5) < 0 ? -23 : -1;
		}
	}
	return result;
}

//----- (0055B820) --------------------------------------------------------
_DWORD *__cdecl sub_55B820(int a1)
{
	unsigned __int16 v1; // dx
	int v2; // esi
	unsigned int v3; // esi

	v1 = *(_WORD *)(a1 + 236);
	*(_DWORD *)(a1 + 20) = 0;
	*(_DWORD *)(a1 + 24) = 0;
	v2 = v1 - 1;
	*(_DWORD *)(a1 + 284) = v2;
	*(_DWORD *)(a1 + 300) = v2;
	*(_DWORD *)(a1 + 320) = v2;
	v3 = *(_DWORD *)(a1 + 1980) & 0xFFFFF87F;
	*(_DWORD *)(a1 + 32) = 0;
	*(_DWORD *)(a1 + 36) = 0;
	*(_DWORD *)(a1 + 336) = 0;
	*(_DWORD *)(a1 + 292) = 0;
	*(_DWORD *)(a1 + 288) = -1;
	*(_DWORD *)(a1 + 296) = -1;
	*(_DWORD *)(a1 + 304) = -1;
	*(_DWORD *)(a1 + 308) = -1;
	*(_DWORD *)(a1 + 316) = -1;
	*(_DWORD *)(a1 + 312) = -1;
	*(_DWORD *)(a1 + 324) = -1;
	*(_DWORD *)(a1 + 40) = -1;
	*(_DWORD *)(a1 + 44) = 0;
	*(_DWORD *)(a1 + 1980) = v3;
	*(_DWORD *)(a1 + 1952) = 0;
	*(_DWORD *)(a1 + 1956) = -1;
	*(_DWORD *)(a1 + 1988) = 0;
	*(_DWORD *)(a1 + 56) = 0;
	return sub_55B8D0((_DWORD *)a1);
}

//----- (0055B8D0) --------------------------------------------------------
_DWORD *__cdecl sub_55B8D0(_DWORD *a1)
{
	_DWORD *result; // eax

	result = a1;
	a1[452] = -1;
	a1[450] = -1;
	a1[451] = -1;
	return result;
}

//----- (0055B8F0) --------------------------------------------------------
int __cdecl sub_55B8F0(int a1, int a2)
{
	int result; // eax

	result = -1;
	if (a2 > 0 && *(unsigned __int16 *)(a1 + 236) >= a2)
	{
		result = *(_DWORD *)(a1 + 284);
		*(_DWORD *)(a1 + 284) = (unsigned __int16)a2;
	}
	return result;
}

//----- (0055B930) --------------------------------------------------------
int __cdecl sub_55B930(unsigned __int8 *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
	int result; // eax

	*a2 = a1[242];
	*a3 = a1[243];
	result = -1;
	*a4 = a1[264];
	return result;
}

//----- (0055B970) --------------------------------------------------------
int __cdecl sub_55B970(int a1)
{
	void(__cdecl *v1)(int, int, _DWORD, _DWORD); // eax
	_DWORD *v2; // esi
	int v3; // ecx
	int v4; // eax
	int v5; // eax
	int v6; // eax
	int v7; // eax
	int v8; // eax
	int result; // eax
	int v10; // ecx
	int v11; // edx
	int v12; // edx

	v1 = *(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 72);
	v2 = *(_DWORD **)(a1 + 1756);
	if (v1)
	{
		v3 = v2[5];
		if (v3 & 0x100)
		{
			v1(a1, 4, v2[7], *(_DWORD *)(a1 + 288));
			v4 = v2[5];
			BYTE1(v4) &= 0xFEu;
			v2[5] = v4;
		}
		v5 = v2[5];
		if (v5 & 0x200)
		{
			(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 72))(a1, 5, v2[7], *(_DWORD *)(a1 + 288));
			v6 = v2[5];
			BYTE1(v6) &= 0xFDu;
			v2[5] = v6;
		}
		v7 = v2[5];
		if (v7 & 0x400)
		{
			sub_55FE20(a1, v2[7]);
			v8 = v2[5];
			BYTE1(v8) &= 0xFBu;
			v2[5] = v8;
		}
	}
	result = (*(int(__cdecl **)(int))(a1 + 1920))(a1);
	*(_DWORD *)(a1 + 1760) = v2[7];
	v10 = *(_DWORD *)(a1 + 420);
	if (v10 & 8)
	{
		if (v10 & 0x10)
		{
			v12 = v2[5];
			BYTE1(v12) |= 8u;
			v2[5] = v12;
			*(_DWORD *)(a1 + 420) &= 0xFFFFFFEF;
		}
		*(_DWORD *)(a1 + 420) &= 0xFFFFFFF7;
	}
	else
	{
		v11 = v2[5];
		v2[5] = 0;
		v2[6] = v11;
	}
	return result;
}

//----- (0055BA50) --------------------------------------------------------
int __cdecl sub_55BA50(int a1)
{
	int result; // eax
	int v2; // edx
	_DWORD *v3; // ecx

	result = 0;
	v2 = *(_DWORD *)(a1 + 16);
	if (v2 > 0)
	{
		v3 = *(_DWORD **)(a1 + 1892);
		do
		{
			if (*v3 & 0x40000000)
				++result;
			++v3;
			--v2;
		} while (v2);
	}
	return result;
}

//----- (0055BA80) --------------------------------------------------------
int __cdecl sub_55BA80(int a1, int a2)
{
	int v2; // edi
	int result; // eax
	unsigned __int16 *v4; // ebx
	int v5; // eax
	int v6; // ecx
	int v7; // edx
	int v8; // esi
	int v9; // ecx
	int v10; // ecx
	int v11; // edx
	int v12; // ecx
	int v13; // [esp+4h] [ebp-4h]
	int v14; // [esp+Ch] [ebp+4h]

	v2 = a1;
	result = 0;
	v13 = 0;
	if ((int)*(unsigned __int16 *)(a1 + 1812) > 0)
	{
		v4 = *(unsigned __int16 **)(a1 + 1820);
		v5 = *(_DWORD *)(a1 + 16) - 1;
		v14 = *(unsigned __int16 *)(a1 + 1812);
		while (1)
		{
			v6 = v4[1];
			v7 = *v4;
			if ((unsigned __int16)v6 != v5)
				break;
			if (a2 <= 0)
			{
				v8 = *(_DWORD *)(v2 + 1892);
				v9 = *(_DWORD *)(v8 + 4 * v6);
				goto LABEL_8;
			}
			v10 = a2;
			v11 = 2 * (*(_DWORD *)(*(_DWORD *)(v2 + 1892) + 4 * v7) & 0xFFFFFFF);
		LABEL_9:
			v12 = v10 - v11;
			if (v12 > v13)
				v13 = v12;
			v4 += 2;
			if (!--v14)
				return v13;
		}
		v8 = *(_DWORD *)(v2 + 1892);
		v9 = *(_DWORD *)(v8 + 4 * v6 + 4);
	LABEL_8:
		v10 = 2 * (v9 & 0xFFFFFFF);
		v11 = 2 * (*(_DWORD *)(v8 + 4 * v7) & 0xFFFFFFF);
		goto LABEL_9;
	}
	return result;
}

//----- (0055BB30) --------------------------------------------------------
int __cdecl sub_55BB30(int a1)
{
	int v1; // ebx
	int v2; // edx
	int v3; // edi
	__int16 v4; // bx
	int v5; // eax
	int v6; // esi
	int v7; // edx
	int v8; // ecx
	int v9; // ebx
	char v11; // [esp+4h] [ebp-14h]
	char v12; // [esp+8h] [ebp-10h]
	int v13; // [esp+Ch] [ebp-Ch]
	int i; // [esp+10h] [ebp-8h]
	__int16 j; // [esp+14h] [ebp-4h]
	char v16; // [esp+1Ch] [ebp+4h]

	v1 = 0;
	*(_DWORD *)&byte_5D4594[2516188] = operator_new(0x1FFFCu);
	if (!*(_DWORD *)&byte_5D4594[2516188])
		return 0;
	switch (a1)
	{
	case 0:
		v16 = 11;
		v11 = 5;
		v12 = 0;
		break;
	case 1:
		v16 = 11;
		v11 = 6;
		v12 = 0;
		break;
	case 2:
		v16 = 11;
		v11 = 6;
		v12 = 1;
		break;
	case 3:
		v16 = 10;
		v11 = 5;
		v12 = 0;
		break;
	default:
		return 0;
	}
	for (i = 0; i < 32; ++i)
	{
		v2 = 0;
		v3 = v1 << v16;
		v4 = 32 * v1;
		v13 = 0;
		for (j = v4; ; v4 = j)
		{
			v5 = 0;
			v6 = v2 << v11;
			v7 = (unsigned __int16)(32 * (v4 | v2));
			do
			{
				v8 = v7 | (unsigned __int16)v5;
				v9 = v6 | v3 | (v5++ << v12);
				*(_WORD *)(*(_DWORD *)&byte_5D4594[2516188] + 2 * v8) = v9;
			} while (v5 < 32);
			v2 = ++v13;
			if (v13 >= 32)
				break;
		}
		v1 = i + 1;
	}
	return 1;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0055BC60) --------------------------------------------------------
int sub_55BC60()
{
	int result; // eax

	operator_delete(*(LPVOID *)&byte_5D4594[2516188]);
	*(_DWORD *)&byte_5D4594[2516188] = 0;
	return result;
}

//----- (0055BC80) --------------------------------------------------------
unsigned __int16 *__cdecl sub_55BC80(unsigned __int16 *a1, int a2)
{
	int v2; // ecx
	unsigned __int16 *result; // eax
	unsigned __int16 v4; // dx

	v2 = a2;
	result = a1;
	if (a2 > 0)
	{
		do
		{
			v4 = *result;
			++result;
			--v2;
			*(result - 1) = *(_WORD *)(*(_DWORD *)&byte_5D4594[2516188] + 2 * v4);
		} while (v2);
	}
	return result;
}

//----- (0055BCB0) --------------------------------------------------------
char *__cdecl sub_55BCB0(int a1, unsigned __int16 *a2, char *a3, int a4, int a5, int a6)
{
	unsigned int v6; // edi
	char *result; // eax
	unsigned __int16 *v8; // ebx
	char *v9; // ebp
	char *v10; // ecx
	int v11; // eax
	int v12; // esi
	int v13; // eax
	unsigned int v14; // esi
	int *v15; // eax
	int v16; // ecx
	int *v17; // eax
	char *v18; // edx
	unsigned int v19; // edi
	int v20; // ecx
	_DWORD *v21; // edx
	unsigned int v22; // edi
	unsigned __int16 v23; // ax
	unsigned int v24; // edx
	int v25; // eax
	unsigned int v26; // ecx
	__int16 *v27; // edi
	char *v28; // ebx
	__int16 v29; // cx
	char *v30; // eax
	unsigned int v31; // edx
	int v32; // esi
	_WORD *v33; // eax
	char *v34; // ebx
	char *v35; // edx
	int v36; // edi
	int v37; // edi
	unsigned int v38; // ebx
	_DWORD *v39; // edx
	unsigned __int16 *v40; // eax
	int v41; // esi
	unsigned __int16 v42; // cx
	unsigned __int16 v43; // bp
	unsigned __int16 *v44; // eax
	unsigned __int16 v45; // cx
	unsigned __int16 v46; // bp
	int v47; // edi
	unsigned __int16 v48; // cx
	int v49; // edx
	int v50; // eax
	_DWORD *v51; // ecx
	char *v52; // [esp+Ch] [ebp-Ch]
	char *v53; // [esp+10h] [ebp-8h]
	char *v54; // [esp+14h] [ebp-4h]
	int v55; // [esp+20h] [ebp+8h]
	unsigned __int16 *v56; // [esp+24h] [ebp+Ch]
	int v57; // [esp+24h] [ebp+Ch]
	int v58; // [esp+24h] [ebp+Ch]
	char *v59; // [esp+2Ch] [ebp+14h]
	int v60; // [esp+2Ch] [ebp+14h]
	int v61; // [esp+2Ch] [ebp+14h]
	unsigned int v62; // [esp+2Ch] [ebp+14h]
	unsigned int v63; // [esp+30h] [ebp+18h]

	v6 = 2 * a6;
	result = a3;
	v8 = a2;
	v9 = a3;
	v10 = &a3[4 * 2 * a6 * a5];
	v63 = 2 * a6;
	v54 = v10;
	v52 = a3;
	v53 = &a3[8 * a4];
	v59 = a3;
	if (a3 < v10)
	{
		do
		{
			LOWORD(v11) = *v8;
			++v8;
			v11 = (unsigned __int16)v11;
			v56 = v8;
			v12 = v11;
			v13 = v11 & 0xF000;
			v14 = v12 & 0xFFFF0FFF;
			if (v13 > 12288)
			{
				if (v13 == 20480)
				{
					if (v14)
					{
						v47 = 4 * (v6 >> 2);
						do
						{
							v48 = *(_WORD *)(*(_DWORD *)&byte_5D4594[2516188] + 2 * *v8);
							v49 = 4;
							v50 = v48 | (v48 << 16);
							++v8;
							v51 = v9;
							do
							{
								*v51 = v50;
								v51[1] = v50;
								v51 = (_DWORD *)((char *)v51 + v47);
								--v49;
							} while (v49);
							v9 += 8;
							--v14;
							v59 = v9;
						} while (v14);
					}
				}
				else if (v13 == 24576)
				{
					if (v14)
					{
						v37 = 4 * (v6 >> 2);
						v38 = v14;
						do
						{
							v39 = v9;
							v40 = (unsigned __int16 *)(a1 + 32 * *v56);
							++v56;
							v41 = 4;
							do
							{
								v42 = v40[1];
								v43 = *v40;
								v44 = v40 + 2;
								*v39 = v43 | (v42 << 16);
								v45 = v44[1];
								v46 = *v44;
								v40 = v44 + 2;
								v39[1] = v46 | (v45 << 16);
								v39 = (_DWORD *)((char *)v39 + v37);
								--v41;
							} while (v41);
							v9 = v59 + 8;
							--v38;
							v59 += 8;
						} while (v38);
						v8 = v56;
					}
				}
				else if (v13 == 28672 && v14)
				{
					v62 = v14;
					while (1)
					{
						v32 = 4;
						v33 = (_WORD *)(a1 + 32 * *v8);
						v58 = (int)(v8 + 1);
						v34 = v9;
						do
						{
							v35 = v34;
							v36 = 4;
							do
							{
								if (((*v33 >> 8) & 0x80u) == 0)
									*(_WORD *)v35 = *v33;
								v35 += 2;
								++v33;
								--v36;
							} while (v36);
							--v32;
							v34 += 2 * (v63 >> 1);
						} while (v32);
						v9 += 8;
						if (!--v62)
							break;
						v8 = (unsigned __int16 *)v58;
					}
					v8 = (unsigned __int16 *)v58;
					v59 = v9;
				}
				goto LABEL_59;
			}
			if (v13 == 12288)
			{
				v55 = 4;
				v27 = (__int16 *)(a1 + 32 * *v8);
				v57 = (int)(v8 + 1);
				do
				{
					v28 = v9;
					v61 = 4;
					do
					{
						v29 = *v27;
						if ((((unsigned __int16)*v27 >> 8) & 0x80u) == 0)
						{
							v30 = v28;
							if (v14)
							{
								v31 = v14;
								do
								{
									*(_WORD *)v30 = v29;
									v30 += 8;
									--v31;
								} while (v31);
							}
						}
						v28 += 2;
						++v27;
						--v61;
					} while (v61);
					v9 += v63;
					--v55;
				} while (v55);
				v8 = (unsigned __int16 *)v57;
				v9 += 8 * v14 - 4 * v63;
				v59 = v9;
				goto LABEL_59;
			}
			if (v13)
			{
				if (v13 != 4096)
				{
					if (v13 == 0x2000)
					{
						v60 = 4;
						v15 = (int *)(a1 + 32 * *v8);
						++v8;
						do
						{
							v16 = *v15;
							v17 = v15 + 1;
							v18 = v9;
							if (v14)
							{
								v19 = v14;
								do
								{
									*(_DWORD *)v18 = v16;
									v18 += 8;
									--v19;
								} while (v19);
							}
							v20 = *v17;
							v15 = v17 + 1;
							v21 = v9 + 4;
							if (v14)
							{
								v22 = v14;
								do
								{
									*v21 = v20;
									v21 += 2;
									--v22;
								} while (v22);
							}
							v9 += v63;
							--v60;
						} while (v60);
						v9 += 8 * v14 - 4 * v63;
						v59 = v9;
					}
					goto LABEL_59;
				}
			}
			else
			{
				v23 = *v8;
				v24 = 2 * v14;
				++v8;
				v25 = *(unsigned __int16 *)(*(_DWORD *)&byte_5D4594[2516188] + 2 * v23) | (*(unsigned __int16 *)(*(_DWORD *)&byte_5D4594[2516188] + 2 * v23) << 16);
				if (2 * v14)
					memset32(v9, v25, v24);
				if (v24)
					memset32(&v9[v63], v25, v24);
				v26 = v63;
				if (v24)
				{
					memset32(&v9[2 * v63], v25, v24);
					v26 = v63;
				}
				if (v24)
					memset32(&v9[2 * v26 + v26], v25, v24);
			}
			v9 += 8 * v14;
			v59 = v9;
		LABEL_59:
			result = v53;
			v6 = v63;
			if (v9 == v53)
			{
				result = (char *)(4 * v63);
				v9 = &v52[4 * v63];
				v52 = v9;
				v59 = v9;
				v53 = &v9[8 * a4];
			}
		} while (v9 < v54);
	}
	return result;
}

//----- (0055C050) --------------------------------------------------------
int *__cdecl sub_55C050(int a1, unsigned __int16 *a2, int *a3, int a4, int a5, int a6)
{
	unsigned int v6; // edi
	int *result; // eax
	unsigned __int16 *v8; // ebx
	int *v9; // ebp
	int *v10; // ecx
	int v11; // eax
	int v12; // esi
	int v13; // eax
	unsigned int v14; // esi
	int *v15; // eax
	int v16; // ecx
	int *v17; // eax
	int *v18; // edx
	unsigned int v19; // edi
	int v20; // ecx
	_DWORD *v21; // edx
	unsigned int v22; // edi
	unsigned __int16 v23; // cx
	unsigned int v24; // edx
	int v25; // ecx
	__int16 *v26; // edi
	int *v27; // ebx
	int v28; // ebp
	__int16 v29; // cx
	int *v30; // eax
	unsigned int v31; // edx
	bool v32; // zf
	int v33; // esi
	_WORD *v34; // eax
	int *v35; // ebx
	int *v36; // edx
	int v37; // edi
	int v38; // edi
	int v39; // esi
	unsigned __int16 *v40; // eax
	int *v41; // edx
	unsigned __int16 v42; // cx
	unsigned __int16 v43; // bx
	unsigned __int16 *v44; // eax
	unsigned __int16 v45; // cx
	unsigned __int16 v46; // bx
	int v47; // edi
	unsigned __int16 v48; // cx
	int v49; // edx
	int v50; // eax
	int *v51; // ecx
	int *v52; // [esp+Ch] [ebp-Ch]
	int *v53; // [esp+10h] [ebp-8h]
	int *v54; // [esp+14h] [ebp-4h]
	int v55; // [esp+20h] [ebp+8h]
	int v56; // [esp+24h] [ebp+Ch]
	int v57; // [esp+24h] [ebp+Ch]
	int v58; // [esp+24h] [ebp+Ch]
	int v59; // [esp+24h] [ebp+Ch]
	int *v60; // [esp+2Ch] [ebp+14h]
	unsigned int v61; // [esp+2Ch] [ebp+14h]
	unsigned int v62; // [esp+2Ch] [ebp+14h]
	int v63; // [esp+30h] [ebp+18h]

	v6 = 2 * a6;
	result = a3;
	v8 = a2;
	v9 = a3;
	v10 = &a3[2 * a6 * a5];
	v63 = a6;
	v54 = v10;
	v52 = a3;
	v53 = &a3[2 * a4];
	v60 = a3;
	if (a3 < v10)
	{
		do
		{
			v11 = *v8;
			++v8;
			v12 = v11;
			v13 = v11 & 0xF000;
			v14 = v12 & 0xFFFF0FFF;
			if (v13 > 12288)
			{
				if (v13 == 20480)
				{
					if (v14)
					{
						v47 = 4 * (v6 >> 1);
						do
						{
							v48 = *(_WORD *)(*(_DWORD *)&byte_5D4594[2516188] + 2 * *v8);
							v49 = 2;
							v50 = v48 | (v48 << 16);
							++v8;
							v51 = v9;
							do
							{
								*v51 = v50;
								v51[1] = v50;
								v51 = (int *)((char *)v51 + v47);
								--v49;
							} while (v49);
							v9 += 2;
							--v14;
							v60 = v9;
						} while (v14);
					}
				}
				else if (v13 == 24576)
				{
					if (v14)
					{
						v38 = 4 * (v6 >> 1);
						v62 = v14;
						while (1)
						{
							v39 = 2;
							v40 = (unsigned __int16 *)(a1 + 32 * *v8);
							v59 = (int)(v8 + 1);
							v41 = v9;
							do
							{
								v42 = v40[1];
								v43 = *v40;
								v44 = v40 + 2;
								*v41 = v43 | (v42 << 16);
								v45 = v44[1];
								v46 = *v44;
								v40 = v44 + 6;
								v41[1] = v46 | (v45 << 16);
								v41 = (int *)((char *)v41 + v38);
								--v39;
							} while (v39);
							v9 += 2;
							if (!--v62)
								break;
							v8 = (unsigned __int16 *)v59;
						}
						v8 = (unsigned __int16 *)v59;
						v60 = v9;
					}
				}
				else if (v13 == 28672 && v14)
				{
					v61 = v14;
					while (1)
					{
						v33 = 2;
						v34 = (_WORD *)(a1 + 32 * *v8);
						v58 = (int)(v8 + 1);
						v35 = v9;
						do
						{
							v36 = v35;
							v37 = 4;
							do
							{
								if (((*v34 >> 8) & 0x80u) == 0)
									*(_WORD *)v36 = *v34;
								v36 = (int *)((char *)v36 + 2);
								++v34;
								--v37;
							} while (v37);
							--v33;
							v35 = (int *)((char *)v35 + 1 * v63);
						} while (v33);
						v9 += 2;
						if (!--v61)
							break;
						v8 = (unsigned __int16 *)v58;
					}
					v8 = (unsigned __int16 *)v58;
					v60 = v9;
				}
			}
			else if (v13 == 12288)
			{
				v55 = 2;
				v26 = (__int16 *)(a1 + 32 * *v8);
				v57 = (int)(v8 + 1);
				while (1)
				{
					v27 = v9;
					v28 = 4;
					do
					{
						v29 = *v26;
						if ((((unsigned __int16)*v26 >> 8) & 0x80u) == 0)
						{
							v30 = v27;
							if (v14)
							{
								v31 = v14;
								do
								{
									*(_WORD *)v30 = v29;
									v30 += 2;
									--v31;
								} while (v31);
							}
						}
						v27 = (int *)((char *)v27 + 2);
						++v26;
						--v28;
					} while (v28);
					v26 += 4;
					v32 = v55 == 1;
					v60 = (int *)((char *)v60 + 1 * v63);
					--v55;
					if (v32)
						break;
					v9 = v60;
				}
				v8 = (unsigned __int16 *)v57;
				v60 = (int *)((char *)v60 + 8 * v14 - 2 * v63);
				v9 = v60;
			}
			else if (v13)
			{
				if (v13 == 4096)
				{
					v60 = &v9[2 * v14];
					v9 += 2 * v14;
				}
				else if (v13 == 0x2000)
				{
					v56 = 2;
					v15 = (int *)(a1 + 32 * *v8);
					++v8;
					while (1)
					{
						v16 = *v15;
						v17 = v15 + 1;
						v18 = v9;
						if (v14)
						{
							v19 = v14;
							do
							{
								*v18 = v16;
								v18 += 2;
								--v19;
							} while (v19);
						}
						v20 = *v17;
						v15 = v17 + 3;
						v21 = v9 + 1;
						if (v14)
						{
							v22 = v14;
							do
							{
								*v21 = v20;
								v21 += 2;
								--v22;
							} while (v22);
						}
						if (!--v56)
							break;
						v9 = (int *)((char *)v9 + 1 * v63);
					}
					v60 = (int *)((char *)&v9[v63] + 8 * v14 - 2 * v63);
					v9 = (int *)((char *)v9 + 1 * v63 + 8 * v14 - 2 * v63);
				}
			}
			else
			{
				v23 = *v8;
				++v8;
				v24 = 2 * v14;
				v25 = *(unsigned __int16 *)(*(_DWORD *)&byte_5D4594[2516188] + 2 * v23);
				if (2 * v14)
					memset32(v9, v25 | (v25 << 16), v24);
				if (v24)
					memset32(&v9[v63], v25 | (v25 << 16), v24);
				v60 = &v9[2 * v14];
				v9 += 2 * v14;
			}
			result = v53;
			v6 = v63 * 2;
			if (v9 == v53)
			{
				v52 += v63 * 2;
				v60 = v52;
				result = &v52[2 * a4];
				v9 = v52;
				v53 = &v52[2 * a4];
			}
		} while (v9 < v54);
	}
	return result;
}

//----- (0055C3F0) --------------------------------------------------------
int *__cdecl sub_55C3F0(int a1, _WORD *a2, int *a3, unsigned int a4, int a5, int a6)
{
	int *v6; // edx
	int v7; // ebp
	int v8; // ecx
	_WORD *v9; // esi
	int *result; // eax
	int v11; // ecx
	_WORD *v12; // eax
	int v13; // ebx
	int *v14; // esi
	int v15; // edi
	unsigned __int16 *v16; // eax
	int v17; // esi
	unsigned __int16 v18; // cx
	unsigned __int16 v19; // bx
	unsigned __int16 *v20; // eax
	unsigned __int16 v21; // cx
	unsigned __int16 v22; // bx
	int *v23; // [esp+8h] [ebp-4h]
	int v24; // [esp+18h] [ebp+Ch]
	int *v25; // [esp+20h] [ebp+14h]
	int *v26; // [esp+24h] [ebp+18h]

	v6 = a3;
	v7 = 2 * a6;
	v8 = 2 * a6 * a5;
	v9 = a2;
	v26 = a3;
	result = &a3[v8];
	v23 = &a3[v8];
	v25 = &a3[2 * a4];
	if (a3 < result)
	{
		while (1)
		{
			result = (int *)(*v9 & 0x1FFF);
			v11 = *v9 & 0xE000;
			v24 = (int)(v9 + 1);
			if (!(*v9 & 0xE000))
				break;
			if (v11 == 0x2000)
			{
				v12 = (_WORD *)(a1 + 32 * (*v9 & 0x1FFF));
				v13 = 2;
				do
				{
					v14 = v6;
					v15 = 4;
					do
					{
						if (((*v12 >> 8) & 0x80u) == 0)
							*(_WORD *)v14 = *v12;
						v14 = (int *)((char *)v14 + 2);
						++v12;
						--v15;
					} while (v15);
					v12 += 4;
					--v13;
					v6 = (int *)((char *)v6 + 2 * v7);
				} while (v13);
				goto LABEL_17;
			}
			if (v11 == 0x4000)
				v6 += 2;
		LABEL_18:
			if (v6 == v25)
			{
				v6 = &v26[v7];
				result = (int *)a4;
				v26 = v6;
				v25 = &v6[2 * a4];
			}
			if (v6 >= v23)
				return result;
			v9 = (_WORD *)v24;
		}
		v16 = (unsigned __int16 *)(a1 + 32 * (*v9 & 0x1FFF));
		v17 = 2;
		do
		{
			v18 = v16[1];
			v19 = *v16;
			v20 = v16 + 2;
			*v6 = v19 | (v18 << 16);
			v21 = v20[1];
			v22 = *v20;
			v16 = v20 + 6;
			v6[1] = v22 | (v21 << 16);
			v6 = (int *)((char *)v6 + 2 * v7);
			--v17;
		} while (v17);
	LABEL_17:
		result = (int *)(4 * v7);
		v6 = (int *)((char *)v6 + 8 - 4 * v7);
		goto LABEL_18;
	}
	return result;
}

//----- (0055C530) --------------------------------------------------------
unsigned int __cdecl sub_55C530(int a1, _WORD *a2, int *a3, unsigned int a4, int a5, int a6)
{
	unsigned int v6; // ebx
	int v7; // ecx
	int *v8; // esi
	_WORD *v9; // edi
	unsigned int result; // eax
	unsigned int v11; // ecx
	unsigned __int8 *v12; // edi
	int v13; // ecx
	int *v14; // edi
	unsigned __int16 *v15; // ecx
	unsigned int v16; // ebx
	int v17; // eax
	unsigned __int16 v18; // dx
	unsigned __int16 v19; // bp
	unsigned __int16 *v20; // ecx
	unsigned __int16 v21; // dx
	unsigned __int16 v22; // bp
	unsigned __int8 *v23; // ecx
	int v24; // ebx
	int *v25; // edx
	unsigned __int16 *v26; // eax
	int v27; // edi
	unsigned __int16 v28; // cx
	unsigned __int16 v29; // bp
	unsigned __int16 *v30; // eax
	unsigned __int16 v31; // cx
	unsigned __int16 v32; // bp
	int v33; // edx
	unsigned __int16 *v34; // eax
	int v35; // edx
	unsigned __int16 v36; // cx
	unsigned __int16 v37; // bp
	unsigned __int16 *v38; // eax
	unsigned __int16 v39; // cx
	unsigned __int16 v40; // bp
	int v41; // ebx
	__int16 *v42; // eax
	int *v43; // ebp
	__int16 v44; // dx
	int *v45; // ecx
	int v46; // edi
	int v47; // edx
	int *v48; // ecx
	int v49; // eax
	int *v50; // ecx
	int *v51; // edi
	int v52; // ebp
	int v53; // eax
	_DWORD *v54; // edi
	int v55; // ebp
	_WORD *v56; // eax
	int v57; // ebp
	int *v58; // edx
	int v59; // edi
	int *v60; // [esp+Ch] [ebp-Ch]
	int *v61; // [esp+10h] [ebp-8h]
	unsigned int v62; // [esp+14h] [ebp-4h]
	int v63; // [esp+20h] [ebp+8h]
	unsigned int v64; // [esp+24h] [ebp+Ch]
	int v65; // [esp+24h] [ebp+Ch]
	int v66; // [esp+24h] [ebp+Ch]
	int v67; // [esp+24h] [ebp+Ch]
	int v68; // [esp+2Ch] [ebp+14h]
	unsigned int v69; // [esp+2Ch] [ebp+14h]
	int v70; // [esp+30h] [ebp+18h]

	v6 = 2 * a6;
	v7 = 2 * a6 * a5;
	v8 = a3;
	v9 = a2;
	v70 = 2 * a6;
	result = (unsigned int)&a3[v7];
	v62 = result;
	v60 = a3;
	v61 = &a3[2 * a4];
	if ((unsigned int)a3 < result)
	{
		while (1)
		{
			result = *v9 & 0x1FFF;
			v11 = *v9 & 0xE000;
			v12 = (unsigned __int8 *)(v9 + 1);
			v68 = (int)v12;
			if (v11 <= 0x6000)
				break;
			switch (v11)
			{
			case 0x8000u:
				v56 = (_WORD *)(a1 + 32 * (unsigned __int16)result);
				v57 = 4;
				do
				{
					v58 = v8;
					v59 = 4;
					do
					{
						if (((*v56 >> 8) & 0x80u) == 0)
							*(_WORD *)v58 = *v56;
						v58 = (int *)((char *)v58 + 2);
						++v56;
						--v59;
					} while (v59);
					v56 += 4;
					--v57;
					v8 = (int *)((char *)v8 + 2 * v6);
				} while (v57);
				goto LABEL_53;
			case 0xA000u:
				goto LABEL_18;
			case 0xC000u:
				v41 = *v12;
				v68 = (int)(v12 + 1);
				v63 = 2;
				v42 = (__int16 *)(a1 + 32 * (unsigned __int16)result);
				do
				{
					v43 = v8;
					v66 = 4;
					do
					{
						v44 = *v42;
						if ((((unsigned __int16)*v42 >> 8) & 0x80u) == 0)
						{
							v45 = v43;
							if (v41)
							{
								v46 = v41;
								do
								{
									*(_WORD *)v45 = v44;
									v45 += 2;
									--v46;
								} while (v46);
							}
						}
						v43 = (int *)((char *)v43 + 2);
						++v42;
						--v66;
					} while (v66);
					v42 += 4;
					v8 = (int *)((char *)v8 + 2 * v70);
					--v63;
				} while (v63);
				v47 = 8 * v41;
				v6 = v70;
				result = 4 * v70;
				v8 = (int *)((char *)v8 + v47 - 4 * v70);
				break;
			}
		LABEL_54:
			if (v8 == v61)
			{
				v8 = &v60[v6];
				result = a4;
				v60 = v8;
				v61 = &v8[2 * a4];
			}
			if ((unsigned int)v8 >= v62)
				return result;
			v9 = (_WORD *)v68;
		}
		if (v11 == 24576)
		{
			v34 = (unsigned __int16 *)(a1 + 32 * (unsigned __int16)result);
			v35 = 4;
			do
			{
				v36 = v34[1];
				v37 = *v34;
				v38 = v34 + 2;
				*v8 = v37 | (v36 << 16);
				v39 = v38[1];
				v40 = *v38;
				v34 = v38 + 6;
				v8[1] = v40 | (v39 << 16);
				v8 = (int *)((char *)v8 + 2 * v6);
				--v35;
			} while (v35);
		LABEL_53:
			result = 4 * v6;
			v8 = (int *)((char *)v8 + 8 - 4 * v6);
			goto LABEL_54;
		}
		if (!v11)
		{
			result = (unsigned __int8)result;
			v8 += 2 * (unsigned __int8)result;
			goto LABEL_54;
		}
		if (v11 != 0x2000)
		{
			if (v11 == 0x4000)
			{
				v13 = *(v12 - 2);
				v14 = v8;
				v64 = ((result >> 7) & 0x3E) + 2;
				v15 = (unsigned __int16 *)(a1 + 32 * v13);
				v16 = v6 >> 2;
				v17 = 2;
				do
				{
					v18 = v15[1];
					v19 = *v15;
					v20 = v15 + 2;
					*v14 = v19 | (v18 << 16);
					v21 = v20[1];
					v22 = *v20;
					v15 = v20 + 6;
					v14[1] = v22 | (v21 << 16);
					v14 += v16;
					--v17;
				} while (v17);
				result = v64;
				v23 = (unsigned __int8 *)v68;
				v8 += 2;
				if (v64)
				{
					v24 = 8 * v16;
					v69 = v64;
					do
					{
						v25 = v8;
						v65 = (int)(v23 + 1);
						v26 = (unsigned __int16 *)(a1 + 32 * *v23);
						v27 = 2;
						do
						{
							v28 = v26[1];
							v29 = *v26;
							v30 = v26 + 2;
							*v25 = v29 | (v28 << 16);
							v31 = v30[1];
							v32 = *v30;
							v26 = v30 + 6;
							v25[1] = v32 | (v31 << 16);
							v25 = (int *)((char *)v25 + v24);
							--v27;
						} while (v27);
						v23 = (unsigned __int8 *)v65;
						v8 += 2;
						result = --v69;
					} while (v69);
				}
				v6 = v70;
				v68 = (int)v23;
			}
			goto LABEL_54;
		}
		v33 = (((unsigned __int16)result >> 7) & 0x3E) + 2;
		if ((((unsigned __int16)result >> 7) & 0x3E) == -2)
		{
		LABEL_18:
			result = (unsigned __int16)result;
			v33 = *v12;
			v68 = (int)(v12 + 1);
		}
		else
		{
			result = (unsigned __int8)result;
		}
		v67 = 2;
		v48 = (int *)(a1 + 32 * result);
		do
		{
			v49 = *v48;
			v50 = v48 + 1;
			v51 = v8;
			if (v33)
			{
				v52 = v33;
				do
				{
					*v51 = v49;
					v51 += 2;
					--v52;
				} while (v52);
				v6 = v70;
			}
			v53 = *v50;
			v48 = v50 + 3;
			v54 = v8 + 1;
			if (v33)
			{
				v55 = v33;
				do
				{
					*v54 = v53;
					v54 += 2;
					--v55;
				} while (v55);
				v6 = v70;
			}
			v8 = (int *)((char *)v8 + 2 * v6);
			--v67;
		} while (v67);
		result = 4 * v6;
		v8 = (int *)((char *)v8 + 8 * v33 - 4 * v6);
		goto LABEL_54;
	}
	return result;
}

//----- (0055C8E0) --------------------------------------------------------
unsigned __int8 *sub_55C8E0()
{
	*(_DWORD *)&byte_5D4594[2516192] = timeGetTime();
	return &byte_5D4594[2516192];
}

//----- (0055C900) --------------------------------------------------------
DWORD __thiscall sub_55C900(DWORD *this)
{
	DWORD *v1; // esi
	DWORD v2; // eax
	DWORD v3; // ecx
	DWORD result; // eax

	v1 = this;
	v2 = timeGetTime();
	v3 = *v1;
	if (v2 > *v1)
		result = v2 - v3;
	else
		result = v2 - v3 - 1;
	return result;
}

//----- (0055C920) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
DWORD sub_55C920()
{
	return sub_55C900((DWORD *)&byte_5D4594[2516192]);
}

//----- (0055C930) --------------------------------------------------------
DWORD sub_55C930()
{
	return 3 * sub_55C900((DWORD *)&byte_5D4594[2516192]) / 0x32;
}

//----- (0055C950) --------------------------------------------------------
__int16 __cdecl sub_55C950(int a1, _BYTE *a2, int *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	int *v7; // edi
	int v8; // ecx
	int v9; // ebx
	int *v10; // ebx
	int v11; // edx
	int v12; // edx
	int v13; // edx
	int v14; // ebx
	int v15; // eax
	int v16; // edx
	int v17; // ebx
	int v18; // ebx
	int v19; // ebx
	int *v21; // [esp+8h] [ebp-10h]
	int v22; // [esp+Ch] [ebp-Ch]
	int *v23; // [esp+10h] [ebp-8h]
	_BYTE *v24; // [esp+14h] [ebp-4h]
	int v25; // [esp+34h] [ebp+1Ch]

	v25 = 2 * a6;
	v22 = v25;
	v6 = a2;
	v24 = &a2[a4 * a5];
	v7 = a3;
	v23 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				BYTE1(v9) = v6[a4 * a5];
				LOBYTE(v9) = *v6++;
				if ((BYTE1(v9) & 0x80 & 0x80u) != 0)
					break;
				v10 = (int *)(a1 + 32 * v9);
				v11 = v10[1];
				*v7 = *v10;
				v7[1] = v11;
				v12 = v10[3];
				v21 = v10;
				*(int *)((char *)v7 + v25) = v10[2];
				*(int *)((char *)v7 + v25 + 4) = v12;
				v13 = v10[5];
				v14 = 2 * v25;
				*(int *)((char *)v7 + v14) = v21[4];
				*(int *)((char *)v7 + v14 + 4) = v13;
				v15 = v21[6];
				v16 = v21[7];
				v17 = 3 * v25;
				*(int *)((char *)v7 + v17) = v15;
				*(int *)((char *)v7 + v17 + 4) = v16;
				v7 += 2;
				if (!--v8)
				{
					v7 = &v23[v22];
					v23 = (int *)((char *)v23 + v22 * 4);
					if (v6 >= v24)
						return v15;
					goto LABEL_2;
				}
			}
			v15 = (a4 * a5) << 16;
			LOWORD(v15) = *(_WORD *)(2 * (v9 & 0x7FFF) + *(_DWORD *)&byte_5D4594[2516188]);
			*v7 = v15;
			v7[1] = v15;
			*(int *)((char *)v7 + v25) = v15;
			*(int *)((char *)v7 + v25 + 4) = v15;
			v18 = 2 * v25;
			*(int *)((char *)v7 + v18) = v15;
			*(int *)((char *)v7 + v18 + 4) = v15;
			v19 = 3 * v25;
			*(int *)((char *)v7 + v19) = v15;
			*(int *)((char *)v7 + v19 + 4) = v15;
			v7 += 2;
			--v8;
		} while (v8);
		v7 = &v23[v22];
		v23 = (int *)((char *)v23 + v22 * 4);
	} while (v6 < v24);
	return v15;
}

//----- (0055CA59) --------------------------------------------------------
__int16 __cdecl sub_55CA59(int a1, _BYTE *a2, int *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	int *v7; // edi
	int v8; // ecx
	int v9; // ebx
	int *v10; // ebx
	int v11; // edx
	int v12; // eax
	int v13; // edx
	int v14; // ebx
	int v15; // ebx
	int v17; // [esp+Ch] [ebp-Ch]
	int *v18; // [esp+10h] [ebp-8h]
	_BYTE *v19; // [esp+14h] [ebp-4h]
	int v20; // [esp+34h] [ebp+1Ch]

	v20 = 2 * a6;
	v17 = v20;
	v6 = a2;
	v19 = &a2[a4 * a5];
	v7 = a3;
	v18 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				BYTE1(v9) = v6[a4 * a5];
				LOBYTE(v9) = *v6++;
				if ((BYTE1(v9) & 0x80 & 0x80u) != 0)
					break;
				v10 = (int *)(a1 + 32 * v9);
				v11 = v10[1];
				*v7 = *v10;
				v7[1] = v11;
				v12 = v10[4];
				v13 = v10[5];
				v14 = 2 * v20;
				*(int *)((char *)v7 + v14) = v12;
				*(int *)((char *)v7 + v14 + 4) = v13;
				v7 += 2;
				if (!--v8)
				{
					v7 = &v18[v17];
					v18 = (int *)((char *)v18 + v17 * 4);
					if (v6 >= v19)
						return v12;
					goto LABEL_2;
				}
			}
			v12 = (a4 * a5) << 16;
			LOWORD(v12) = *(_WORD *)(2 * (v9 & 0x7FFF) + *(_DWORD *)&byte_5D4594[2516188]);
			*v7 = v12;
			v7[1] = v12;
			v15 = 2 * v20;
			*(int *)((char *)v7 + v15) = v12;
			*(int *)((char *)v7 + v15 + 4) = v12;
			v7 += 2;
			--v8;
		} while (v8);
		v7 = &v18[v17];
		v18 = (int *)((char *)v18 + v17 * 4);
	} while (v6 < v19);
	return v12;
}

//----- (0055CB20) --------------------------------------------------------
int __cdecl sub_55CB20(int a1, char a2)
{
	int v2; // esi
	int v3; // ebp
	char v4; // al
	int v5; // ecx
	int v6; // ebx
	int v7; // eax
	int v8; // ebx
	int v9; // edi
	int v10; // eax
	_DWORD *v11; // ecx
	int v12; // edi
	int v13; // edi
	int(__cdecl *v14)(_DWORD *, int, void *, signed int); // eax
	int result; // eax
	int v16; // eax
	_DWORD *i; // [esp+10h] [ebp-14h]
	int v18; // [esp+14h] [ebp-10h]
	int v19; // [esp+18h] [ebp-Ch]
	int v20; // [esp+1Ch] [ebp-8h]
	int v21; // [esp+20h] [ebp-4h]
	char v22; // [esp+28h] [ebp+4h]

	v2 = a1;
	v3 = 0;
	v4 = *(_BYTE *)(a1 + 132);
	v5 = *(_DWORD *)(a1 + 1892);
	v6 = *(_DWORD *)(a1 + 384);
	v21 = 0;
	v18 = v5;
	v20 = v6;
	v22 = 0;
	if (!(v4 & 0x20))
		goto LABEL_40;
	if (!(*(_BYTE *)(v2 + 340) & 4))
		goto LABEL_40;
	v7 = *(_DWORD *)(v2 + 288);
	if (v7 < 0)
		goto LABEL_40;
	if (v6 < *(int *)(v2 + 16))
		v3 = 2 * (*(_DWORD *)(v5 + 4 * v6) & 0xFFFFFFF);
	if (v6 == *(_DWORD *)(v2 + 296) && v7 != *(_DWORD *)(v2 + 1808))
	{
		if (v6 != *(_DWORD *)(v2 + 1800))
		{
			*(_DWORD *)(v2 + 1788) = v3;
			*(_DWORD *)(v2 + 1792) = 0;
			*(_DWORD *)(v2 + 1796) = 0;
		}
		v8 = 0;
		*(_DWORD *)(v2 + 1808) = *(_DWORD *)(v2 + 288);
		*(_DWORD *)(v2 + 1800) = *(_DWORD *)(v2 + 296);
		*(_DWORD *)(v2 + 1804) = -1;
		v9 = *(_DWORD *)(v2 + 296);
		v10 = *(_DWORD *)(v2 + 300);
		if (v9 <= v10)
		{
			v11 = (_DWORD *)(v5 + 4 * v9);
			for (i = v11; ; v11 = i)
			{
				if (v9 >= *(int *)(v2 + 16) - 1)
				{
					if ((*(int(__cdecl **)(int, int, int *, _DWORD))(v2 + 64))(v2, 9, &v19, 0))
						break;
					v10 = *(_DWORD *)(v2 + 300);
					v8 += v19 - 2 * (*(_DWORD *)(v18 + 4 * v10) & 0xFFFFFFF);
				}
				else
				{
					v8 += 2 * (v11[1] & 0xFFFFFFF) - 2 * (*v11 & 0xFFFFFFF);
				}
				if (v8 >= *(int *)(v2 + 1784))
					break;
				++v9;
				++i;
				if (v9 > v10)
					goto LABEL_21;
			}
			*(_DWORD *)(v2 + 1804) = v9 - 1;
		}
	LABEL_21:
		if (v8 < *(int *)(v2 + 1784) && *(int *)(v2 + 1804) == -1)
			*(_DWORD *)(v2 + 1804) = *(_DWORD *)(v2 + 300);
		v6 = v20;
		v5 = v18;
	}
	if (v6 < *(int *)(v2 + 1800) || v6 > *(int *)(v2 + 1804))
		goto LABEL_40;
	if (v3 == *(_DWORD *)(v2 + 1788) + *(_DWORD *)(v2 + 1792))
	{
		if (v6 < *(int *)(v2 + 16) - 1)
		{
			v12 = 2 * (*(_DWORD *)(v5 + 4 * v6 + 4) & 0xFFFFFFF);
			goto LABEL_32;
		}
		if (!(*(int(__cdecl **)(int, int, int *, _DWORD))(v2 + 64))(v2, 9, &v19, 0))
		{
			v12 = v19;
		LABEL_32:
			v13 = v12 - v3;
			if (v13 > 0)
			{
				v14 = *(int(__cdecl **)(_DWORD *, int, void *, signed int))(v2 + 64);
				if (v14 != sub_562A90)
					v14((_DWORD *)v2, 7, 0, v3);
				if ((*(int(__cdecl **)(int, int, int, int))(v2 + 64))(
					v2,
					5,
					*(_DWORD *)(v2 + 1780) + *(_DWORD *)(v2 + 1796),
					v13))
				{
					return -4;
				}
				*(_DWORD *)(v2 + 1792) += v13;
			}
			goto LABEL_38;
		}
	}
LABEL_38:
	v16 = *(_DWORD *)(v2 + 1788);
	if (v3 < v16 + *(_DWORD *)(v2 + 1792))
	{
		v22 = 1;
		*(_DWORD *)(v2 + 1796) = v3 - v16;
		v21 = *(_DWORD *)(v2 + 64);
		*(_DWORD *)(v2 + 64) = sub_562A90;
	}
LABEL_40:
	if (sub_55D8C0(v2, v6) && !(a2 & 0x20))
		*(_DWORD *)(v2 + 360) = *(_DWORD *)(v2 + 356);
	result = sub_55CDB0(v2, a2);
	if (v22)
		*(_DWORD *)(v2 + 64) = v21;
	return result;
}

//----- (0055CDB0) --------------------------------------------------------
int __cdecl sub_55CDB0(int a1, char a2)
{
	int v2; // esi
	int v3; // eax
	_DWORD *v4; // edx
	int v5; // ecx
	int v6; // ebp
	int v7; // edi
	int v8; // ebx
	int v9; // eax
	int result; // eax
	int v11; // ebx
	bool v12; // zf
	int v13; // edi
	int v14; // ecx
	int v15; // ecx
	int v16; // eax
	int v17; // eax
	int v18; // eax
	int v19; // eax
	unsigned int v20; // eax
	int v21; // ecx
	int v22; // eax
	int v23; // eax
	int v24; // eax
	int v25; // eax
	int v26; // eax
	int v27; // eax
	int v28; // eax
	int v29; // eax
	int v30; // eax
	int v31; // eax
	int v32; // eax
	_DWORD *v33; // eax
	int v34; // edx
	int v35; // eax
	int v36; // eax
	int v37; // eax
	int v38; // ecx
	int v39; // eax
	int v40; // eax
	_DWORD *v41; // ecx
	char v42; // [esp+13h] [ebp-5h]
	int v43; // [esp+14h] [ebp-4h]
	_DWORD *v44; // [esp+1Ch] [ebp+4h]

	v2 = a1;
	v3 = *(_DWORD *)(a1 + 132);
	v4 = *(_DWORD **)(a1 + 368);
	v43 = 0;
	v42 = 0;
	v44 = *(_DWORD **)(a1 + 368);
	if (v3 & 0x20)
	{
		v5 = *(_DWORD *)(v2 + 292);
		if (v5 > 0 || v5 == -1)
		{
			v6 = *(_DWORD *)(v2 + 300);
			if (*(_DWORD *)(v2 + 384) > v6)
			{
				v7 = *(_DWORD *)(v2 + 304);
				v8 = *(_DWORD *)(v2 + 284);
				if (v7 != -1)
				{
					*(_DWORD *)(v2 + 300) = v7;
					*(_DWORD *)(v2 + 304) = -1;
					*(_DWORD *)(v2 + 284) = v7;
				}
				v9 = *(_DWORD *)(v2 + 296);
				if (*(_DWORD *)(v2 + 384) == v9)
				{
					result = -1;
				}
				else
				{
					*(_DWORD *)(v2 + 384) = v9;
					result = sub_55E030(v2, *(_DWORD *)(v2 + 296));
					if (result != -1 && result != -11)
					{
						*(_DWORD *)(v2 + 300) = v6;
						*(_DWORD *)(v2 + 304) = v7;
						*(_DWORD *)(v2 + 284) = v8;
						*(_DWORD *)(v2 + 384) = v6 + 1;
						return result;
					}
					v4 = v44;
				}
				v11 = *(_DWORD *)(v2 + 336);
				LOBYTE(v11) = v11 | 0x80;
				v12 = v7 == -1;
				*(_DWORD *)(v2 + 336) = v11;
				v13 = v4[5];
				if (v12)
				{
					v4[5] = v13 | 0x100;
					v14 = *(_DWORD *)(v2 + 292);
					if (v14 != -1)
						*(_DWORD *)(v2 + 292) = v14 - 1;
				}
				else
				{
					v4[5] = v13 | 0x200;
					*(_DWORD *)(v2 + 292) = *(_DWORD *)(v2 + 308);
					v15 = *(_DWORD *)(v2 + 336);
					BYTE1(v15) |= 1u;
					*(_DWORD *)(v2 + 320) = v6;
					*(_DWORD *)(v2 + 308) = -1;
					*(_DWORD *)(v2 + 336) = v15;
				}
				return result;
			}
		}
	}
	if (*(_DWORD *)(v2 + 384) <= *(int *)(v2 + 284))
	{
		v18 = v4[5];
		if (v18 & 1 && !(v18 & 0x800))
		{
			++*(_DWORD *)(v2 + 392);
			return -9;
		}
		if (!(*(_BYTE *)(v2 + 336) & 1))
		{
			v19 = *(_DWORD *)(v2 + 360);
			*(_DWORD *)(v2 + 400) = 0;
			v4[1] = v19;
		}
		while (1)
		{
			while (1)
			{
				if (!(*(_BYTE *)(v2 + 336) & 1))
				{
					if ((*(int(__cdecl **)(int, int, int, int))(v2 + 64))(v2, 5, v2 + 408, 8))
						return -2;
					*(_DWORD *)&byte_5D4594[2516196] = ((*(_DWORD *)(v2 + 412) & 0xFF00 | (*(_DWORD *)(v2 + 412) << 16)) << 8) | (((*(_DWORD *)(v2 + 412) >> 16) | *(_DWORD *)(v2 + 412) & 0xFF0000u) >> 8);
					*(_DWORD *)(v2 + 400) += *(_DWORD *)&byte_5D4594[2516196];
				}
				v20 = *(_DWORD *)(v2 + 408);
				v21 = 1;
				if (v20 > 'KFQV')
					break;
				if (v20 == 'KFQV')
				{
					if ((a2 & 0x1D) != 29)
					{
						if (sub_55E100(v2, *(int *)&byte_5D4594[2516196], a2) != -1)
							return -4;
						v44[5] |= 2u;
						v21 = 0;
					}
					goto LABEL_151;
				}
				if (v20 > '1ANS')
				{
					if (v20 > 0x32444E53)
					{
						if (v20 == 1146376278)
						{
						LABEL_96:
							if (!(a2 & 4))
							{
								if (sub_55F6D0(v2, *(int *)&byte_5D4594[2516196]) != -1)
									return -4;
								v21 = 0;
							}
							goto LABEL_151;
						}
						if (v20 == 1244810835)
						{
							if (a2 & 2)
								goto LABEL_152;
							v31 = *(_DWORD *)(v2 + 132);
							if (!(v31 & 1) || v31 & 0x40)
								goto LABEL_152;
							v24 = sub_55FBA0(v2, *(int *)&byte_5D4594[2516196]);
							goto LABEL_50;
						}
					}
					else
					{
						switch (v20)
						{
						case 0x32444E53u:
							if (a2 & 2)
								goto LABEL_152;
							v30 = *(_DWORD *)(v2 + 132);
							if (!(v30 & 1) || v30 & 0x40)
								goto LABEL_152;
							if (sub_5615C0(v2) == -11)
							{
							LABEL_155:
								v23 = *(_DWORD *)(v2 + 336);
							LABEL_156:
								*(_DWORD *)(v2 + 336) = v23 | 1;
								return -11;
							}
							*(_DWORD *)(v2 + 336) &= 0xFFFFFFFE;
							v24 = sub_55FA20(v2, *(int *)&byte_5D4594[2516196]);
							goto LABEL_50;
						case 0x31444E53u:
							if (a2 & 2)
								goto LABEL_152;
							v29 = *(_DWORD *)(v2 + 132);
							if (!(v29 & 1) || v29 & 0x40)
								goto LABEL_152;
							v12 = sub_5615C0(v2) == -11;
							v23 = *(_DWORD *)(v2 + 336);
							if (v12)
								goto LABEL_156;
							LOBYTE(v23) = v23 & 0xFE;
							*(_DWORD *)(v2 + 336) = v23;
							v24 = sub_55F860(v2, *(int *)&byte_5D4594[2516196]);
							goto LABEL_50;
						case 0x32414E53u:
							if (a2 & 2)
								goto LABEL_152;
							v28 = *(_DWORD *)(v2 + 132);
							if (!(v28 & 1) || !(v28 & 0x40))
								goto LABEL_152;
							if (sub_5615C0(v2) == -11)
								goto LABEL_155;
							*(_DWORD *)(v2 + 336) &= 0xFFFFFFFE;
							v24 = sub_55FA20(v2, *(int *)&byte_5D4594[2516196]);
							goto LABEL_50;
						}
					}
					goto LABEL_140;
				}
				if (v20 == '1ANS')
				{
					if (a2 & 2)
						goto LABEL_152;
					v27 = *(_DWORD *)(v2 + 132);
					if (!(v27 & 1) || !(v27 & 0x40))
						goto LABEL_152;
					if (sub_5615C0(v2) == -11)
						goto LABEL_155;
					*(_DWORD *)(v2 + 336) &= 0xFFFFFFFE;
					v24 = sub_55F860(v2, *(int *)&byte_5D4594[2516196]);
					goto LABEL_50;
				}
				if (v20 > '0LPC')
				{
					if (v20 != 810566211)
					{
						if (v20 == 810831958)
							goto LABEL_96;
						goto LABEL_140;
					}
					if (a2 & 8)
						goto LABEL_152;
					v24 = sub_55F300(v2, *(int *)&byte_5D4594[2516196]);
				LABEL_50:
					if (v24 != -1)
						return -4;
				}
				else
				{
					switch (v20)
					{
					case '0LPC':
						if (a2 & 1)
							goto LABEL_152;
						v26 = sub_55F570(v2, *(unsigned int *)&byte_5D4594[2516196]);
						goto LABEL_59;
					case '0ANS':
						if (a2 & 2)
							goto LABEL_152;
						v25 = *(_DWORD *)(v2 + 132);
						if (!(v25 & 1) || !(v25 & 0x40))
							goto LABEL_152;
						if (sub_5615C0(v2) == -11)
							goto LABEL_155;
						*(_DWORD *)(v2 + 336) &= 0xFFFFFFFE;
						v24 = sub_55F780(v2, *(unsigned int *)&byte_5D4594[2516196]);
						goto LABEL_50;
					case '0DNS':
						if (a2 & 2)
							goto LABEL_152;
						v22 = *(_DWORD *)(v2 + 132);
						if (!(v22 & 1) || v22 & 0x40)
							goto LABEL_152;
						v12 = sub_5615C0(v2) == -11;
						v23 = *(_DWORD *)(v2 + 336);
						if (v12)
							goto LABEL_156;
						LOBYTE(v23) = v23 & 0xFE;
						*(_DWORD *)(v2 + 336) = v23;
						v24 = sub_55F780(v2, *(unsigned int *)&byte_5D4594[2516196]);
						goto LABEL_50;
					}
					if (v20 != '0FBC')
						goto LABEL_140;
					if (a2 & 0x10)
					{
					LABEL_152:
						v37 = *(_DWORD *)&byte_5D4594[2516196] + 1;
						LOBYTE(v37) = (byte_5D4594[2516196] + 1) & 0xFE;
						if ((*(int(__cdecl **)(int, int, int, int))(v2 + 64))(v2, 7, 1, v37))
							return -6;
						if (v43)
						{
						LABEL_159:
							v38 = *(_DWORD *)(v2 + 384);
							if (v38 > 0)
							{
								v39 = *(_DWORD *)(v2 + 400);
								if (v39 > *(int *)(v2 + 404))
									*(_DWORD *)(v2 + 404) = v39;
							}
							if (!sub_55D8C0(v2, v38) || a2 & 0x20 || v42)
							{
								v41 = v44;
							}
							else
							{
								v40 = *(_DWORD *)(*(_DWORD *)(v2 + 356) + 8);
								v41 = v44;
								*(_DWORD *)(v2 + 360) = v40;
								v44[1] = v40;
							}
							if (!(a2 & 4))
							{
								v41[7] = *(_DWORD *)(v2 + 384);
								*(_DWORD *)(v2 + 388) = *(_DWORD *)(v2 + 384);
								*(_DWORD *)(v2 + 364) = v41[1];
								v41[5] |= 1u;
								*(_DWORD *)(v2 + 368) = v41[3];
							}
							++*(_DWORD *)(v2 + 384);
							return -1;
						}
					}
					else if (sub_55F220(v2, *(int *)&byte_5D4594[2516196]) != -1)
					{
						return -4;
					}
				}
			}
			if (v20 > 0x5A464243)
			{
				if (v20 > 0x5A504243)
				{
					if (v20 == 1515343958)
					{
						if (a2 & 4)
							goto LABEL_151;
						if (sub_55F710(v2, *(int *)&byte_5D4594[2516196]) != -1)
							return -4;
					LABEL_149:
						v33 = v44;
						v21 = 0;
						v34 = v44[5] | 0x20;
					LABEL_150:
						v33[5] = v34;
						goto LABEL_151;
					}
					if (v20 == 1515475030)
					{
					LABEL_144:
						if (!(a2 & 4))
						{
							if (sub_55F710(v2, *(int *)&byte_5D4594[2516196]) != -1)
								return -4;
							v21 = 0;
						}
					LABEL_151:
						v43 = 1;
						if (v21 != 1)
							goto LABEL_159;
						goto LABEL_152;
					}
				LABEL_140:
					v35 = sub_55D740(v2, *(_DWORD *)(v2 + 408));
					if (v35 < 0)
					{
						v36 = sub_55D800(v2, *(_DWORD *)(v2 + 408));
						if (v36 < 0)
							goto LABEL_152;
						v24 = sub_55D830(v2, *(int *)&byte_5D4594[2516196], v36);
					}
					else
					{
						v24 = sub_55D770(v2, *(int *)&byte_5D4594[2516196], v35);
					}
					goto LABEL_50;
				}
				if (v20 == 1515209283)
				{
					if (a2 & 8)
						goto LABEL_152;
					v24 = sub_55F440(v2, *(int *)&byte_5D4594[2516196]);
					goto LABEL_50;
				}
				if (v20 == 1514885206)
				{
					if (a2 & 4)
						goto LABEL_151;
					v32 = sub_55F710(v2, *(int *)&byte_5D4594[2516196]);
				LABEL_134:
					if (v32 != -1)
						return -4;
					v33 = v44;
					v21 = 0;
					v34 = v44[5] | 2;
					goto LABEL_150;
				}
				if (v20 != 1514950723)
					goto LABEL_140;
				if (a2 & 1)
					goto LABEL_152;
				v26 = sub_55F600(v2, *(int *)&byte_5D4594[2516196]);
			LABEL_59:
				if (v26 != -1)
					return -4;
				v44[5] |= 4u;
			}
			else
			{
				if (v20 == 1514553923)
				{
					if (a2 & 0x10)
						goto LABEL_152;
					v24 = sub_55F280(v2, *(int *)&byte_5D4594[2516196]);
					goto LABEL_50;
				}
				if (v20 > 0x52465156)
				{
					if (v20 == 1381257302)
					{
						if (a2 & 4)
							goto LABEL_151;
						if (sub_55F6D0(v2, *(int *)&byte_5D4594[2516196]) != -1)
							return -4;
						goto LABEL_149;
					}
					if (v20 == 1514426454)
						goto LABEL_144;
					goto LABEL_140;
				}
				if (v20 == 1380340054)
				{
					if ((a2 & 0x1D) != 29)
					{
						if (sub_55E100(v2, *(int *)&byte_5D4594[2516196], a2) != -1)
							return -4;
						v21 = 0;
					}
					goto LABEL_151;
				}
				if (v20 == 1263816790)
				{
					if (a2 & 4)
						goto LABEL_151;
					v32 = sub_55F6D0(v2, *(int *)&byte_5D4594[2516196]);
					goto LABEL_134;
				}
				if (v20 != 1279676758)
					goto LABEL_140;
				if (a2 & 0x20)
					goto LABEL_152;
				if (sub_55E100(v2, *(int *)&byte_5D4594[2516196], a2) != -1)
					return -4;
				v42 = 1;
				if (*(_BYTE *)(v2 + 234) & 0x10 && a2 & 4)
					goto LABEL_159;
			}
		}
	}
	if (!(a2 & 2) && v3 & 1 && !(v3 & 0x40))
	{
		if (sub_5615C0(v2) == -11)
		{
			v16 = *(_DWORD *)(v2 + 336);
			LOBYTE(v16) = v16 | 1;
			*(_DWORD *)(v2 + 336) = v16;
			return -11;
		}
		v17 = *(_DWORD *)(v2 + 1980);
		BYTE1(v17) |= 1u;
		*(_DWORD *)(v2 + 336) &= 0xFFFFFFFE;
		*(_DWORD *)(v2 + 1980) = v17;
	}
	return -2;
}

//----- (0055D6F0) --------------------------------------------------------
int __cdecl sub_55D6F0(int a1)
{
	int i; // edi
	int result; // eax

	for (i = 0; i < *(int *)(a1 + 136); ++i)
	{
		result = sub_55CB20(a1, 32);
		if (result == -1)
		{
			++*(_DWORD *)(a1 + 20);
		}
		else if (result != -9 && result != -11)
		{
			return result;
		}
	}
	return -1;
}

//----- (0055D740) --------------------------------------------------------
unsigned int __cdecl sub_55D740(int a1, int a2)
{
	_DWORD *v2; // edx
	unsigned int v3; // ecx
	unsigned int result; // eax

	v2 = *(_DWORD **)(a1 + 1844);
	v3 = *(_DWORD *)(a1 + 1828);
	result = 0;
	if (!v3)
		return -1;
	while (a2 != *v2)
	{
		++result;
		v2 += 4;
		if (result >= v3)
			return -1;
	}
	return result;
}

//----- (0055D770) --------------------------------------------------------
int __cdecl sub_55D770(int a1, int a2, int a3)
{
	int v3; // edi
	int v4; // edx
	int v5; // eax
	unsigned int *v6; // ecx
	int v7; // edx
	int *v8; // ebx
	unsigned int v9; // eax
	int v11; // edi
	int v12; // eax
	int v13; // [esp+14h] [ebp+4h]

	v3 = a1;
	v4 = *(_DWORD *)(a1 + 1848);
	v5 = *(_DWORD *)(v4 + 12 * a3 + 4);
	v6 = (unsigned int *)(v4 + 12 * a3);
	v7 = 12 * v5;
	v8 = (int *)(12 * v5 + v6[2]);
	v9 = v5 + 1;
	v13 = *v8;
	v8[1] = a2;
	*(_DWORD *)(v6[2] + v7 + 8) = *(_DWORD *)(v3 + 384);
	if (v9 >= *v6)
		v9 = 0;
	v6[1] = v9;
	if ((*(int(__cdecl **)(int, int, int, unsigned int))(v3 + 64))(v3, 5, v13, (a2 + 1) & 0xFFFFFFFE))
		return -4;
	v11 = *(_DWORD *)(v3 + 368);
	v12 = *(_DWORD *)(v11 + 20);
	BYTE1(v12) |= 4u;
	*(_DWORD *)(v11 + 20) = v12;
	return -1;
}

//----- (0055D800) --------------------------------------------------------
unsigned int __cdecl sub_55D800(int a1, int a2)
{
	_DWORD *v2; // edx
	unsigned int v3; // ecx
	unsigned int result; // eax

	v2 = *(_DWORD **)(a1 + 1860);
	v3 = *(_DWORD *)(a1 + 1852);
	result = 0;
	if (!v3)
		return -1;
	while (a2 != *v2)
	{
		++result;
		v2 += 4;
		if (result >= v3)
			return -1;
	}
	return result;
}

//----- (0055D830) --------------------------------------------------------
int __cdecl sub_55D830(int a1, int a2, int a3)
{
	int v3; // edi
	int v4; // edx
	int v5; // eax
	unsigned int *v6; // ecx
	int v7; // edx
	int *v8; // ebx
	unsigned int v9; // eax
	int v11; // edi
	int v12; // eax
	int v13; // [esp+14h] [ebp+4h]

	v3 = a1;
	v4 = *(_DWORD *)(a1 + 1864);
	v5 = *(_DWORD *)(v4 + 12 * a3 + 4);
	v6 = (unsigned int *)(v4 + 12 * a3);
	v7 = 12 * v5;
	v8 = (int *)(12 * v5 + v6[2]);
	v9 = v5 + 1;
	v13 = *v8;
	v8[1] = a2;
	*(_DWORD *)(v6[2] + v7 + 8) = *(_DWORD *)(v3 + 384);
	if (v9 >= *v6)
		v9 = 0;
	v6[1] = v9;
	if ((*(int(__cdecl **)(int, int, int, unsigned int))(v3 + 64))(v3, 5, v13, (a2 + 1) & 0xFFFFFFFE))
		return -4;
	v11 = *(_DWORD *)(v3 + 368);
	v12 = *(_DWORD *)(v11 + 20);
	BYTE1(v12) |= 4u;
	*(_DWORD *)(v11 + 20) = v12;
	return -1;
}

//----- (0055D8C0) --------------------------------------------------------
char __cdecl sub_55D8C0(int a1, int a2)
{
	int v3; // eax
	unsigned __int16 *v4; // edx
	int v5; // ecx

	if (!a2)
		return 1;
	v3 = *(unsigned __int16 *)(a1 + 1812);
	if ((int)(unsigned __int16)v3 > 0)
	{
		if (*(_BYTE *)(a1 + 1814) & 3)
		{
			v4 = *(unsigned __int16 **)(a1 + 1820);
			v5 = 0;
			if (v3 > 0)
			{
				while (a2 != *v4)
				{
					++v5;
					v4 += 2;
					if (v5 >= v3)
						return 0;
				}
				return 1;
			}
		}
	}
	return 0;
}

//----- (0055D910) --------------------------------------------------------
int __cdecl sub_55D910(int a1, int a2, int a3)
{
	int v3; // esi
	int v4; // edx
	int v5; // eax
	int v6; // ebx
	int v7; // edi
	int v8; // ecx
	int v9; // eax
	_DWORD *v10; // ecx
	int v12; // [esp+Ch] [ebp-8h]
	int v13; // [esp+10h] [ebp-4h]

	v3 = a1;
	v4 = -1;
	v13 = *(_DWORD *)(a1 + 368);
	v5 = a2;
	v12 = -1;
	if (a2 > *(int *)(a1 + 284))
		return -6;
	v6 = *(_DWORD *)(a1 + 1892);
	if (!v6)
		return -6;
	if (*(_DWORD *)(a1 + 1888))
	{
		sub_55DA90(a1, a2, &a1, 0);
		if (a3)
		{
			v7 = a1;
		}
		else
		{
			sub_55DA90(v3, *(_DWORD *)(v3 + 388), &a2, 0);
			v7 = a1;
			if (a1 == a2)
				return v12;
		}
	}
	else
	{
		v7 = -1;
		a1 = -1;
		if (a2 >= 0)
		{
			v8 = v6 + 4 * a2;
			while (!(*(_BYTE *)(v8 + 3) & 0x40))
			{
				--v5;
				v8 -= 4;
				if (v5 < 0)
					goto LABEL_13;
			}
			v7 = v5;
			a1 = v5;
		}
	LABEL_13:
		if (!a3)
		{
			v9 = *(_DWORD *)(v3 + 388);
			a2 = -1;
			if (v9 >= 0)
			{
				v10 = (_DWORD *)(v6 + 4 * v9);
				while (!(*v10 & 0x40000000))
				{
					--v9;
					--v10;
					if (v9 < 0)
						goto LABEL_20;
				}
				v4 = v9;
				a2 = v9;
			}
		LABEL_20:
			if (v7 == v4)
				return v12;
		}
	}
	if (v7 < 0)
		return v12;
	if ((*(int(__cdecl **)(int, int, _DWORD, int))(v3 + 64))(
		v3,
		7,
		0,
		2 * (*(_DWORD *)(*(_DWORD *)(v3 + 1892) + 4 * v7) & 0xFFFFFFF)))
	{
		return -6;
	}
	if (a3)
	{
		*(_DWORD *)(v3 + 372) = 0;
		*(_DWORD *)(v3 + 376) = 0;
		*(_DWORD *)(v3 + 360) = *(_DWORD *)(v3 + 1772);
		*(_DWORD *)(v3 + 356) = *(_DWORD *)(v3 + 1772);
		*(_DWORD *)(v3 + 384) = 0;
		*(_DWORD *)(v13 + 20) = 0;
	}
	return sub_55CB20(v3, 30);
}

//----- (0055DA90) --------------------------------------------------------
int __cdecl sub_55DA90(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
	int v4; // edx
	int v5; // ebx
	int v6; // ecx
	int result; // eax
	unsigned __int16 *v8; // esi

	v4 = 1;
	v5 = *(_DWORD *)(a1 + 1888);
	v6 = *(unsigned __int16 *)(a1 + 1880);
	result = 0;
	if ((int)(unsigned __int16)v6 <= 1)
	{
	LABEL_6:
		result = v6 - 1;
	}
	else
	{
		v8 = (unsigned __int16 *)(v5 + 2);
		while (a2 < *(v8 - 1) || a2 >= *v8)
		{
			++result;
			++v4;
			++v8;
			if (v4 >= v6)
				goto LABEL_6;
		}
	}
	if (a3)
		*a3 = *(unsigned __int16 *)(v5 + 2 * result);
	if (a4)
	{
		if (result >= v6 - 1)
			*a4 = *(_DWORD *)(a1 + 16);
		else
			*a4 = *(unsigned __int16 *)(v5 + 2 * result + 2) - 1;
	}
	return result;
}

//----- (0055DB20) --------------------------------------------------------
int __cdecl sub_55DB20(_DWORD *a1, int a2, int a3, char a4, char a5, char *a6)
{
	_DWORD *v6; // esi
	int v7; // ebp
	int v8; // eax
	int v9; // ebx
	int v10; // ecx
	int v11; // eax
	int v12; // eax
	int v13; // eax
	int v14; // ecx
	int v15; // eax
	int v16; // ebp
	unsigned __int16 v17; // ax
	int v18; // edi
	int v19; // eax
	int v20; // ecx
	int v21; // edx
	int v22; // ecx
	int v23; // eax
	int v24; // eax
	int result; // eax
	bool v26; // zf
	int v27; // edi
	int v28; // ebp
	bool v29; // cc
	int v30; // [esp+10h] [ebp-Ch]
	int v31; // [esp+14h] [ebp-8h]
	int v32; // [esp+18h] [ebp-4h]
	char v33; // [esp+20h] [ebp+4h]
	int v34; // [esp+28h] [ebp+Ch]
	int v35; // [esp+34h] [ebp+18h]

	v6 = a1;
	v32 = 0;
	v7 = a1[104];
	if (!a1[473])
		return -6;
	v8 = a2;
	v9 = a2;
	if (a1[35] <= 1)
	{
		v33 = 1;
		v31 = a2;
		v30 = a2;
	}
	else
	{
		v33 = 0;
		if (a3 <= 0)
		{
			v32 = sub_55EDD0((int)v6, a2, &v31, &v30);
			v12 = sub_55EDD0((int)v6, v6[97], 0, 0);
			v10 = v31;
		}
		else
		{
			v32 = a2 / a3;
			v10 = a3 * (a2 / a3);
			v31 = a3 * (a2 / a3);
			if (a3 * (a2 / a3) >= a3)
			{
				v10 -= a3;
				v31 = v10;
			}
			if (a2 / a3)
			{
				v30 = v10 + a3 - 1;
				v12 = v6[97] / a3;
			}
			else
			{
				v11 = v6[97];
				v30 = -1;
				v12 = v11 / a3;
			}
		}
		v9 = v10;
		if (a5)
		{
			v6[90] = v6[443];
			v6[89] = v6[443];
		}
		else if (v12 == v32)
		{
			v13 = v6[91];
			v14 = v30;
			v6[90] = v13;
			v33 = 1;
			v9 = v14 + 1;
			v6[89] = *(_DWORD *)(v13 + 4);
		}
		else if (!v6[93])
		{
			v15 = v6[90];
			while (v15 != *(_DWORD *)(v7 + 4) || !(*(_BYTE *)(v7 + 20) & 1))
			{
				v7 = *(_DWORD *)(v7 + 12);
				if (v6[104] == v7)
				{
					v6[89] = v15;
					break;
				}
			}
		}
		v6[93] = 0;
		v6[94] = 0;
		v8 = a2;
	}
	*a6 = v33;
	if (v6[33] & 1 && v6[483])
	{
		v16 = *(_DWORD *)((char *)v6 + 270);
		v17 = *((_WORD *)v6 + 30);
		v18 = v17 * *((unsigned __int8 *)v6 + 62) * (*((unsigned __int8 *)v6 + 63) >> 3) / v6[28];
		if (!(*((_BYTE *)v6 + 234) & 8) && !v16)
			v16 = v17 * *((unsigned __int8 *)v6 + 62) * (*((unsigned __int8 *)v6 + 63) >> 3) / 2;
		if (a4 && v16 > 0)
		{
			v19 = v16 / v18;
			v20 = v18 * (v16 / v18);
			if (v16 > v20)
				++v19;
			v21 = a2 - v19;
			v34 = a2 - v19;
			if (a2 - v19 >= 0)
			{
				v6[491] = v18 + v20 - v16;
			}
			else
			{
				v34 = 0;
				v6[491] = a2 * v18;
				v21 = 0;
			}
			if (v21 < v9)
				v9 = v21;
		}
		else
		{
			v6[491] = 0;
			v34 = a2;
		}
		if (a5)
		{
			memset((void *)v6[485], 0, v6[487]);
			memset((void *)v6[483], 0, v6[38]);
			v22 = 0;
			v6[492] = 0;
			if (v34)
			{
				v6[484] = v16;
				v24 = (unsigned int)v16 / v6[39];
				if (v24 > 0)
				{
					do
						*(_BYTE *)(v6[485] + ++v22 - 1) = 1;
					while (v22 < v24);
				}
			}
			else
			{
				v6[484] = 0;
			}
		}
		v8 = a2;
	}
	else
	{
		a4 = 0;
		v34 = v8;
		v6[491] = 0;
	}
	if (sub_55D8C0((int)v6, v8))
	{
		if (a5)
			*(_DWORD *)(v6[92] + 20) = 0;
		if (v33)
		{
			v23 = 16;
		}
		else
		{
			v23 = 0;
			v6[90] = v6[89];
		}
		result = sub_55DF50((int)v6, a2, v23);
		if (a5 && (result == -9 || result == -11))
			result = -1;
		return result;
	}
	if (((int(__cdecl *)(_DWORD *, int, _DWORD, int))v6[16])(v6, 7, 0, 2 * (*(_DWORD *)(v6[473] + 4 * v9) & 0xFFFFFFF)))
		return -6;
	result = -1;
	v26 = v32 == 0;
	v6[96] = v9;
	v27 = 5;
	if (!v26)
		v27 = 21;
	if (!a4)
		v27 |= 2u;
	v35 = 0;
	v28 = a2 - v9;
	if (a2 - v9 > 0)
	{
		while (1)
		{
			if (a5)
				*(_DWORD *)(v6[92] + 20) &= 0xFFFFFFFE;
			if (a4)
				break;
		LABEL_71:
			if (v33 && v9 <= v30)
				v27 |= 8u;
			else
				v27 &= 0xFFFFFFF7;
			result = sub_55CB20((int)v6, v27);
			if (result != -1)
			{
				if (!a5 || result != -9 && result != -11)
					return result;
				result = -1;
			}
			++v9;
			if (++v35 >= v28)
				return result;
		}
		if (a5)
		{
			v29 = v9 < v34;
			if (v9 != v34)
				goto LABEL_68;
			v6[492] = 0;
		}
		v29 = v9 < v34;
	LABEL_68:
		if (v29)
			v27 |= 2u;
		else
			v27 &= 0xFFFFFFFD;
		goto LABEL_71;
	}
	return result;
}

//----- (0055DF50) --------------------------------------------------------
int __cdecl sub_55DF50(int a1, int a2, int a3)
{
	int v3; // edi
	char v4; // bl
	int v5; // eax
	int v6; // ecx
	bool v7; // zf
	int result; // eax

	v3 = -1;
	v4 = 0;
	v5 = *(_DWORD *)(a1 + 1892);
	if (*(_BYTE *)(a1 + 340) & 4 && a2 == *(_DWORD *)(a1 + 1800) && (v6 = *(_DWORD *)(a1 + 1792)) != 0)
	{
		if (v6 + *(_DWORD *)(a1 + 1788) <= 2 * (*(_DWORD *)(v5 + 4 * *(_DWORD *)(a1 + 300)) & 0xFFFFFFF))
			v4 = 1;
		*(_DWORD *)(a1 + 1796) = 0;
	}
	else if ((*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(a1, 7, 0, 2 * (*(_DWORD *)(v5 + 4 * a2) & 0xFFFFFFF)))
	{
		return -6;
	}
	if (a2 > 0 && (!(a3 & 0x10) || !(*(_BYTE *)(a1 + 234) & 0x10)) && (v3 = sub_55CB20(a1, a3 | 6), v3 != -1)
		|| !v4
		|| (v7 = (*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(
			a1,
			8,
			0,
			*(_DWORD *)(a1 + 1788) + *(_DWORD *)(a1 + 1792)) == 0,
			result = -6,
			v7))
	{
		result = v3;
	}
	return result;
}

//----- (0055E030) --------------------------------------------------------
int __cdecl sub_55E030(int a1, int a2)
{
	int result; // eax
	char v3; // al
	char v4; // [esp+Bh] [ebp-1h]

	v4 = 0;
	if (*(_BYTE *)(*(_DWORD *)(a1 + 368) + 20) & 1)
		return -9;
	if (a2 >= *(int *)(a1 + 284) || !*(_DWORD *)(a1 + 1892) || *(_BYTE *)(a1 + 132) & 1 && !(*(_BYTE *)(a1 + 234) & 8))
		return -6;
	if (*(_BYTE *)(a1 + 264) || sub_55D8C0(a1, a2) || (result = sub_55D910(a1, a2, 1), result == -1))
		result = sub_55DB20((_DWORD *)a1, a2, *(unsigned __int8 *)(a1 + 245), 0, 0, &v4);
	*(_DWORD *)(a1 + 384) = a2;
	if (result == -1)
	{
		v3 = 32;
		if (v4)
			v3 = 48;
		result = sub_55CB20(a1, v3);
	}
	return result;
}

//----- (0055E100) --------------------------------------------------------
int __cdecl sub_55E100(int a1, int a2, char a3)
{
	int v3; // esi
	unsigned int v4; // ebp
	unsigned int *v5; // edi
	unsigned int v6; // eax
	unsigned int v7; // ecx
	int v8; // eax
	int v9; // eax
	int v11; // [esp+14h] [ebp+4h]
	unsigned int v12; // [esp+18h] [ebp+8h]

	v3 = a1;
	v4 = 0;
	v5 = (unsigned int *)(a1 + 408);
	v11 = *(_DWORD *)(a1 + 368);
	v12 = (a2 + 1) & 0xFFFFFFFE;
	if (!v12)
		return -1;
	while (1)
	{
		if ((*(int(__cdecl **)(int, int, unsigned int *, int))(v3 + 64))(v3, 5, v5, 8))
			return -2;
		v6 = ((v5[1] & 0xFF00 | (v5[1] << 16)) << 8) | (((v5[1] >> 16) | v5[1] & 0xFF0000) >> 8);
		v4 += ((v6 + 1) & 0xFFFFFFFE) + 8;
		v7 = *v5;
		if (*v5 > 0x5A445056)
			break;
		if (*v5 == 1514426454)
			goto LABEL_49;
		if (v7 > 0x30545056)
		{
			if (v7 == 1146376278)
			{
			LABEL_26:
				if (a3 & 4)
					goto LABEL_56;
				if (sub_55F6D0(v3, v6) != -1)
					return -4;
				goto LABEL_57;
			}
			if (v7 != 1263816790)
			{
				if (v7 != 1381257302)
					return -4;
				if (a3 & 4)
					goto LABEL_56;
				v8 = sub_55F6D0(v3, v6);
				goto LABEL_54;
			}
			if (a3 & 4)
				goto LABEL_56;
			v9 = sub_55F6D0(v3, v6);
		LABEL_39:
			if (v9 != -1)
				return -4;
			*(_DWORD *)(v11 + 20) |= 2u;
			goto LABEL_57;
		}
		switch (v7)
		{
		case 0x30545056u:
			goto LABEL_26;
		case 0x30464243u:
			if (a3 & 0x10)
				goto LABEL_56;
			if (sub_55F220(v3, v6) != -1)
				return -4;
			break;
		case 0x304C5043u:
			if (a3 & 1)
				goto LABEL_56;
			if (sub_55F570(v3, v6) != -1)
				return -4;
			*(_DWORD *)(v11 + 20) |= 4u;
			break;
		case 0x30504243u:
			if (a3 & 8)
				goto LABEL_56;
			if (sub_55F300(v3, v6) != -1)
				return -4;
			break;
		default:
			return -4;
		}
	LABEL_57:
		if (v4 >= v12)
			return -1;
	}
	if (v7 > 0x5A504243)
	{
		if (v7 == 1515343958)
		{
			if (a3 & 4)
				goto LABEL_56;
			v8 = sub_55F710(v3, v6);
		LABEL_54:
			if (v8 != -1)
				return -4;
			*(_DWORD *)(v11 + 20) |= 0x20u;
			goto LABEL_57;
		}
		if (v7 != 1515475030)
			return -4;
	LABEL_49:
		if (a3 & 4)
			goto LABEL_56;
		if (sub_55F710(v3, v6) != -1)
			return -4;
		goto LABEL_57;
	}
	switch (v7)
	{
	case 0x5A504243u:
		if (a3 & 8)
			goto LABEL_56;
		if (sub_55F440(v3, v6) != -1)
			return -4;
		goto LABEL_57;
	case 0x5A464243u:
		if (a3 & 0x10)
			goto LABEL_56;
		if (sub_55F280(v3, v6) != -1)
			return -4;
		goto LABEL_57;
	case 0x5A4B5056u:
		if (a3 & 4)
			goto LABEL_56;
		v9 = sub_55F710(v3, v6);
		goto LABEL_39;
	}
	if (v7 != 1514950723)
		return -4;
	if (!(a3 & 1))
	{
		if (sub_55F600(v3, v6) != -1)
			return -4;
		*(_DWORD *)(v11 + 20) |= 4u;
		goto LABEL_57;
	}
LABEL_56:
	if (!(*(int(__cdecl **)(int, int, int, unsigned int))(v3 + 64))(v3, 7, 1, (v6 + 1) & 0xFFFFFFFE))
		goto LABEL_57;
	return -6;
}

//----- (0055E3D0) --------------------------------------------------------
int __cdecl sub_55E3D0(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, a1 + 274, v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055E400) --------------------------------------------------------
int __cdecl sub_55E400(int a1)
{
	int result; // eax
	int v2; // edi
	int v3; // eax
	unsigned __int8 v4[8]; // [esp+8h] [ebp-8h]

	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v4, 8))
		return -2;
	if (*(_DWORD *)v4 != 1213090124)
		return -4;
	if (sub_55E550(
		a1,
		(((*(_DWORD *)&v4[4] << 16) | *(_WORD *)&v4[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v4[6] | *(_DWORD *)&v4[4] & 0xFF0000u) >> 8)) != -1)
		return -4;
	if (!*(_WORD *)(a1 + 1812))
		goto LABEL_19;
	v2 = 4 * *(unsigned __int16 *)(a1 + 1812);
	v3 = (*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 68))(a1, 2, 0, 4 * *(unsigned __int16 *)(a1 + 1812));
	*(_DWORD *)(a1 + 1820) = v3;
	if (!v3)
		return -8;
	(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 4, v3, v2);
	*(_DWORD *)(a1 + 48) += v2;
	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v4, 8))
		return -2;
	if (*(_DWORD *)v4 != 1145981260)
		return -4;
	if (sub_55E580(
		a1,
		(((*(_DWORD *)&v4[4] << 16) | *(_WORD *)&v4[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v4[6] | *(_DWORD *)&v4[4] & 0xFF0000u) >> 8)) != -1)
		result = -4;
	else
		LABEL_19:
	result = -1;
	return result;
}

//----- (0055E550) --------------------------------------------------------
int __cdecl sub_55E550(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, a1 + 1812, v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055E580) --------------------------------------------------------
int __cdecl sub_55E580(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(a1, 5, *(_DWORD *)(a1 + 1820), v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055E5B0) --------------------------------------------------------
int __cdecl sub_55E5B0(int a1)
{
	int result; // eax
	int v2; // eax
	int v3; // edi
	int v4; // eax
	int v5; // edi
	int v6; // edi
	int v7; // eax
	unsigned int v8; // ebx
	int v9; // eax
	int v10; // edi
	unsigned __int8 v11[8]; // [esp+Ch] [ebp-8h]

	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v11, 8))
		return -2;
	if (*(_DWORD *)v11 != 1212368461)
		return -4;
	if (sub_55E820(
		a1,
		(((*(_DWORD *)&v11[4] << 16) | *(_WORD *)&v11[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v11[6] | *(_DWORD *)&v11[4] & 0xFF0000u) >> 8)) != -1)
		return -4;
	v2 = *(_DWORD *)(a1 + 1824);
	if (v2)
	{
		v3 = 24 * v2;
		v4 = (*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 68))(a1, 2, 0, 24 * v2);
		*(_DWORD *)(a1 + 1840) = v4;
		if (!v4)
			return -8;
		(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 4, v4, v3);
		*(_DWORD *)(a1 + 48) += v3;
		if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v11, 8))
			return -2;
		if (*(_DWORD *)v11 != 1145259597)
			return -4;
		if (sub_55E850(
			a1,
			(((*(_DWORD *)&v11[4] << 16) | *(_WORD *)&v11[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v11[6] | *(_DWORD *)&v11[4] & 0xFF0000u) >> 8)) != -1)
			return -4;
	}
	v5 = *(_DWORD *)(a1 + 1828);
	if (!v5)
		goto LABEL_34;
	v6 = 16 * v5;
	v7 = (*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 68))(a1, 2, 0, v6);
	*(_DWORD *)(a1 + 1844) = v7;
	if (!v7)
		return -8;
	(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 4, v7, v6);
	*(_DWORD *)(a1 + 48) += v6;
	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v11, 8))
		return -2;
	if (*(_DWORD *)v11 != 1413695053)
		return -4;
	if (sub_55E880(
		a1,
		(((*(_DWORD *)&v11[4] << 16) | *(_WORD *)&v11[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v11[6] | *(_DWORD *)&v11[4] & 0xFF0000u) >> 8)) != -1)
		return -4;
LABEL_34:
	v8 = *(_DWORD *)(a1 + 1828);
	if (!v8)
		return -1;
	v9 = (*(int(__cdecl **)(int, int, _DWORD, unsigned int))(a1 + 68))(a1, 2, 0, 12 * v8);
	*(_DWORD *)(a1 + 1848) = v9;
	if (!v9)
		return -8;
	(*(void(__cdecl **)(int, int, int, unsigned int))(a1 + 68))(a1, 4, v9, 12 * v8);
	v10 = 0;
	*(_DWORD *)(a1 + 48) += 12 * v8;
	while (1)
	{
		result = sub_55EAC0((_DWORD *)a1, v10);
		if (result != -1)
			break;
		if (++v10 >= v8)
			return -1;
	}
	return result;
}

//----- (0055E820) --------------------------------------------------------
int __cdecl sub_55E820(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, a1 + 1824, v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055E850) --------------------------------------------------------
int __cdecl sub_55E850(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(a1, 5, *(_DWORD *)(a1 + 1840), v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055E880) --------------------------------------------------------
int __cdecl sub_55E880(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(a1, 5, *(_DWORD *)(a1 + 1844), v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055E8B0) --------------------------------------------------------
int __cdecl sub_55E8B0(int a1)
{
	int result; // eax
	int v2; // eax
	int v3; // edi
	int v4; // eax
	unsigned int v5; // ebx
	int v6; // eax
	int v7; // edi
	unsigned __int8 v8[8]; // [esp+Ch] [ebp-8h]

	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v8, 8))
		return -2;
	if (*(_DWORD *)v8 != 1212371789)
		return -4;
	if (sub_55EA60(
		a1,
		(((*(_DWORD *)&v8[4] << 16) | *(_WORD *)&v8[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v8[6] | *(_DWORD *)&v8[4] & 0xFF0000u) >> 8)) != -1)
		return -4;
	v2 = *(_DWORD *)(a1 + 1852);
	if (!v2)
		goto LABEL_25;
	v3 = 16 * v2;
	v4 = (*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 68))(a1, 2, 0, 16 * v2);
	*(_DWORD *)(a1 + 1860) = v4;
	if (!v4)
		return -8;
	(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 4, v4, v3);
	*(_DWORD *)(a1 + 48) += v3;
	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v8, 8))
		return -2;
	if (*(_DWORD *)v8 != 1413698381)
		return -4;
	if (sub_55EA90(
		a1,
		(((*(_DWORD *)&v8[4] << 16) | *(_WORD *)&v8[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v8[6] | *(_DWORD *)&v8[4] & 0xFF0000u) >> 8)) != -1)
		return -4;
LABEL_25:
	v5 = *(_DWORD *)(a1 + 1852);
	if (!v5)
		return -1;
	v6 = (*(int(__cdecl **)(int, int, _DWORD, unsigned int))(a1 + 68))(a1, 2, 0, 12 * v5);
	*(_DWORD *)(a1 + 1864) = v6;
	if (!v6)
		return -8;
	(*(void(__cdecl **)(int, int, int, unsigned int))(a1 + 68))(a1, 4, v6, 12 * v5);
	v7 = 0;
	*(_DWORD *)(a1 + 48) += 12 * v5;
	while (1)
	{
		result = sub_55ECE0((_DWORD *)a1, v7);
		if (result != -1)
			break;
		if (++v7 >= v5)
			return -1;
	}
	return result;
}

//----- (0055EA60) --------------------------------------------------------
int __cdecl sub_55EA60(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, a1 + 1852, v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055EA90) --------------------------------------------------------
int __cdecl sub_55EA90(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(a1, 5, *(_DWORD *)(a1 + 1860), v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055EAC0) --------------------------------------------------------
int __cdecl sub_55EAC0(_DWORD *a1, int a2)
{
	_DWORD *v2; // esi
	int v3; // ecx
	int *v4; // eax
	int v5; // ebp
	signed int v6; // eax
	signed int v7; // edi
	int v8; // ebx
	signed int *v9; // ebp
	int v10; // eax
	unsigned int v12; // ebx
	int v13; // eax
	int v14; // eax
	int v15; // [esp+14h] [ebp+4h]
	int v16; // [esp+18h] [ebp+8h]
	int v17; // [esp+18h] [ebp+8h]

	v2 = a1;
	v3 = a1[34];
	v4 = (int *)(16 * a2 + a1[461]);
	v5 = a1[462];
	v15 = v4[2];
	v6 = sub_55EBD0((int)v2, *v4, v3, v4[1]);
	v7 = v6;
	if (v6 > 0)
	{
		v8 = 12 * v6;
		v9 = (signed int *)(v5 + 12 * a2);
		*v9 = v6;
		v9[1] = 0;
		v10 = ((int(__cdecl *)(_DWORD *, int, _DWORD, int))v2[17])(v2, 2, 0, 12 * v6);
		v16 = v10;
		if (!v10)
			return -8;
		((void(__cdecl *)(_DWORD *, int, int, int))v2[17])(v2, 4, v10, 12 * v7);
		v2[12] += v8;
		v12 = v7 * ((v15 + 1) & 0xFFFFFFFE);
		v9[2] = v16;
		v13 = ((int(__cdecl *)(_DWORD *, int, _DWORD, unsigned int))v2[17])(v2, 2, 0, v7 * ((v15 + 1) & 0xFFFFFFFE));
		v17 = v13;
		if (!v13)
			return -8;
		((void(__cdecl *)(_DWORD *, int, int, unsigned int))v2[17])(v2, 4, v13, v12);
		v2[12] += v12;
		if (v7 > 0)
		{
			v14 = 0;
			do
			{
				*(_DWORD *)(v9[2] + v14) = v17;
				*(_DWORD *)(v9[2] + v14 + 8) = -1;
				v14 += 12;
				--v7;
				v17 += v15;
			} while (v7);
		}
	}
	return -1;
}

//----- (0055EBD0) --------------------------------------------------------
unsigned int __cdecl sub_55EBD0(int a1, int a2, int a3, unsigned int a4)
{
	unsigned int v5; // esi

	if (!a4)
		return 0;
	v5 = (a3 - 1) / a4 + 1;
	if (sub_55EC10(a1, a2, a4))
		v5 = (a3 - 1) / a4 + 2;
	return v5;
}

//----- (0055EC10) --------------------------------------------------------
char __cdecl sub_55EC10(int a1, int a2, unsigned int a3)
{
	unsigned int v3; // edx
	int v4; // ebx
	_WORD *i; // ebp
	int v6; // esi
	unsigned int *v7; // edi
	unsigned int v8; // ecx
	int v9; // edx
	int v10; // eax
	unsigned int v12; // [esp+10h] [ebp-10h]
	int v13; // [esp+14h] [ebp-Ch]
	unsigned int *v14; // [esp+18h] [ebp-8h]
	unsigned int v15; // [esp+1Ch] [ebp-4h]
	unsigned int v16; // [esp+24h] [ebp+4h]

	v3 = *(unsigned __int16 *)(a1 + 1812);
	v4 = 0;
	v15 = (unsigned __int16)v3;
	v12 = *(_DWORD *)(a1 + 1824);
	v14 = *(unsigned int **)(a1 + 1840);
	v13 = 0;
	if (!(_WORD)v3)
		return 0;
	for (i = (_WORD *)(*(_DWORD *)(a1 + 1820) + 2); ; i += 2)
	{
		v6 = -1;
		v16 = 0;
		if (v12)
			break;
	LABEL_15:
		if (++v13 >= v3)
			return 0;
	}
	v7 = v14;
	do
	{
		if (v7[1] == a2)
		{
			v8 = *v7;
			v9 = (unsigned __int16)*(i - 1);
			if (*v7 >= (unsigned __int16)v9)
			{
				HIWORD(v10) = 0;
				if (v8 > (unsigned __int16)*i)
					break;
				if (v6 < 0)
					v6 = v8 - v9;
				LOWORD(v10) = *i;
				v4 = v10 - v8;
			}
		}
		v7 += 6;
		++v16;
	} while (v16 < v12);
	if (v6 <= 0 || v6 + v4 + 1 >= a3)
	{
		v3 = v15;
		goto LABEL_15;
	}
	return 1;
}

//----- (0055ECE0) --------------------------------------------------------
int __cdecl sub_55ECE0(_DWORD *a1, int a2)
{
	_DWORD *v2; // esi
	int v3; // ebx
	int v4; // ebp
	_DWORD *v5; // ebp
	int v6; // eax
	unsigned int v8; // edi
	int v9; // eax
	int v10; // eax
	int v11; // [esp+14h] [ebp+4h]
	int v12; // [esp+18h] [ebp+8h]
	int v13; // [esp+18h] [ebp+8h]

	v2 = a1;
	v3 = a1[34];
	v4 = a1[466];
	v11 = *(_DWORD *)(a1[465] + 16 * a2 + 4);
	if (v3 > 0)
	{
		v5 = (_DWORD *)(v4 + 12 * a2);
		*v5 = v3;
		v5[1] = 0;
		v6 = ((int(__cdecl *)(_DWORD *, int, _DWORD, int))v2[17])(v2, 2, 0, 12 * v3);
		v12 = v6;
		if (!v6)
			return -8;
		((void(__cdecl *)(_DWORD *, int, int, int))v2[17])(v2, 4, v6, 12 * v3);
		v2[12] += 12 * v3;
		v5[2] = v12;
		v8 = v3 * ((v11 + 1) & 0xFFFFFFFE);
		v9 = ((int(__cdecl *)(_DWORD *, int, _DWORD, unsigned int))v2[17])(v2, 2, 0, v3 * ((v11 + 1) & 0xFFFFFFFE));
		v13 = v9;
		if (!v9)
			return -8;
		((void(__cdecl *)(_DWORD *, int, int, unsigned int))v2[17])(v2, 4, v9, v8);
		v2[12] += v8;
		v10 = 0;
		do
		{
			*(_DWORD *)(v5[2] + v10) = v13;
			*(_DWORD *)(v5[2] + v10 + 8) = -1;
			v10 += 12;
			--v3;
			v13 += v11;
		} while (v3);
	}
	return -1;
}

//----- (0055EDD0) --------------------------------------------------------
int __cdecl sub_55EDD0(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
	int v4; // edx
	int v5; // ebx
	int v6; // ecx
	int result; // eax
	unsigned __int16 *v8; // esi
	int v9; // ecx
	int v10; // edx

	v4 = 1;
	v5 = *(_DWORD *)(a1 + 1876);
	v6 = *(unsigned __int16 *)(a1 + 1868);
	result = 0;
	if ((int)(unsigned __int16)v6 <= 1)
	{
	LABEL_6:
		result = v6 - 1;
	}
	else
	{
		v8 = (unsigned __int16 *)(v5 + 6);
		while (a2 < *(v8 - 3) || a2 >= *v8)
		{
			++result;
			++v4;
			v8 += 3;
			if (v4 >= v6)
				goto LABEL_6;
		}
	}
	if (result)
	{
		v9 = result - 1;
		v10 = result;
	}
	else
	{
		v9 = 0;
		v10 = 0;
	}
	if (a3)
		*a3 = *(unsigned __int16 *)(v5 + 6 * v9);
	if (a4)
		*a4 = *(unsigned __int16 *)(v5 + 6 * v10) - 1;
	return result;
}

//----- (0055EE60) --------------------------------------------------------
int __cdecl sub_55EE60(int a1)
{
	int result; // eax
	int v2; // edi
	int v3; // eax
	unsigned __int8 v4[8]; // [esp+8h] [ebp-8h]

	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v4, 8))
		return -2;
	if (*(_DWORD *)v4 != 1213090115)
		return -4;
	if (sub_55EFC0(
		a1,
		(((*(_DWORD *)&v4[4] << 16) | *(_WORD *)&v4[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v4[6] | *(_DWORD *)&v4[4] & 0xFF0000u) >> 8)) != -1)
		return -4;
	if (*(_BYTE *)(a1 + 245) || !*(_WORD *)(a1 + 1868))
		goto LABEL_20;
	v2 = 6 * *(unsigned __int16 *)(a1 + 1868);
	v3 = (*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 68))(a1, 2, 0, v2);
	*(_DWORD *)(a1 + 1876) = v3;
	if (!v3)
		return -8;
	(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 4, v3, v2);
	*(_DWORD *)(a1 + 48) += v2;
	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v4, 8))
		return -2;
	if (*(_DWORD *)v4 != 1145981251)
		return -4;
	if (sub_55EFF0(
		a1,
		(((*(_DWORD *)&v4[4] << 16) | *(_WORD *)&v4[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v4[6] | *(_DWORD *)&v4[4] & 0xFF0000u) >> 8)) == -1)
		LABEL_20:
	result = -1;
	else
		result = -4;
	return result;
}

//----- (0055EFC0) --------------------------------------------------------
int __cdecl sub_55EFC0(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, a1 + 1868, v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055EFF0) --------------------------------------------------------
int __cdecl sub_55EFF0(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(a1, 5, *(_DWORD *)(a1 + 1876), v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055F020) --------------------------------------------------------
int __cdecl sub_55F020(int a1)
{
	int result; // eax
	int v2; // edi
	int v3; // eax
	unsigned __int8 v4[8]; // [esp+8h] [ebp-8h]

	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v4, 8))
		return -2;
	if (*(_DWORD *)v4 != 1213090128)
		return -4;
	if (sub_55F170(
		a1,
		(((*(_DWORD *)&v4[4] << 16) | *(_WORD *)&v4[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v4[6] | *(_DWORD *)&v4[4] & 0xFF0000u) >> 8)) != -1)
		return -4;
	if (!*(_WORD *)(a1 + 1880))
		goto LABEL_19;
	v2 = 2 * *(unsigned __int16 *)(a1 + 1880);
	v3 = (*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 68))(a1, 2, 0, 2 * *(unsigned __int16 *)(a1 + 1880));
	*(_DWORD *)(a1 + 1888) = v3;
	if (!v3)
		return -8;
	(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 4, v3, v2);
	*(_DWORD *)(a1 + 48) += v2;
	if ((*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 64))(a1, 5, v4, 8))
		return -2;
	if (*(_DWORD *)v4 != 1145981264)
		return -4;
	if (sub_55F1A0(
		a1,
		(((*(_DWORD *)&v4[4] << 16) | *(_WORD *)&v4[4] & 0xFF00) << 8) | ((*(unsigned __int16 *)&v4[6] | *(_DWORD *)&v4[4] & 0xFF0000u) >> 8)) != -1)
		result = -4;
	else
		LABEL_19:
	result = -1;
	return result;
}

//----- (0055F170) --------------------------------------------------------
int __cdecl sub_55F170(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, a1 + 1880, v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055F1A0) --------------------------------------------------------
int __cdecl sub_55F1A0(int a1, int a2)
{
	int v2; // eax
	int v3; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = -((*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(a1, 5, *(_DWORD *)(a1 + 1888), v2) != 0);
	LOBYTE(v3) = v3 & 0xFD;
	return v3 - 1;
}

//----- (0055F1D0) --------------------------------------------------------
int __cdecl sub_55F1D0(int a1, int a2)
{
	int v2; // ecx

	v2 = *(_DWORD *)(a1 + 1892);
	if (v2)
	{
		if ((*(int(__cdecl **)(int, int, int, unsigned int))(a1 + 64))(a1, 5, v2, (a2 + 1) & 0xFFFFFFFE))
			return -4;
	}
	else if ((*(int(__cdecl **)(int, int, int, unsigned int))(a1 + 64))(a1, 7, 1, (a2 + 1) & 0xFFFFFFFE))
	{
		return -6;
	}
	return -1;
}

//----- (0055F220) --------------------------------------------------------
int __cdecl sub_55F220(int a1, int a2)
{
	int v2; // eax
	_DWORD *v3; // esi

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = *(_DWORD **)(a1 + 356);
	if ((*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 64))(a1, 5, *v3, v2))
		return -4;
	*(_DWORD *)(a1 + 372) = 0;
	v3[4] = 0;
	v3[5] = a2;
	v3[3] = 8;
	*(_DWORD *)(a1 + 360) = v3;
	*(_DWORD *)(a1 + 356) = v3[1];
	return -1;
}

//----- (0055F280) --------------------------------------------------------
int __cdecl sub_55F280(int a1, int a2)
{
	int v2; // eax
	_DWORD *v3; // ebp
	int v4; // edi
	int v5; // ebx

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = *(_DWORD **)(a1 + 356);
	v4 = *(_DWORD *)(a1 + 1896) - v2;
	v5 = v4 + *v3;
	if ((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, v4 + *v3, v2))
		return -4;
	*(_DWORD *)(a1 + 372) = 0;
	v3[3] = 10;
	v3[4] = v4;
	*(_DWORD *)(a1 + 360) = v3;
	*(_DWORD *)(a1 + 356) = v3[1];
	if (*(_WORD *)(a1 + 232) < 3u)
		*(_BYTE *)(v5 + a2 + 1) = -128;
	return -1;
}

//----- (0055F300) --------------------------------------------------------
int __cdecl sub_55F300(int a1, int a2)
{
	_DWORD *v2; // edi
	int v4; // eax
	int v5; // ebp
	int v6; // ecx

	v2 = *(_DWORD **)(a1 + 356);
	if (!*(_BYTE *)(a1 + 245) && !*(_DWORD *)(a1 + 376))
		*(_DWORD *)(a1 + 380) = sub_55F3F0(a1, *(_DWORD *)(a1 + 384));
	if ((*(int(__cdecl **)(int, int, int, unsigned int))(a1 + 64))(
		a1,
		5,
		*(_DWORD *)(a1 + 376) + *v2,
		(a2 + 1) & 0xFFFFFFFE))
	{
		return -4;
	}
	v4 = a2 + *(_DWORD *)(a1 + 376);
	v5 = *(_DWORD *)(a1 + 372) + 1;
	*(_DWORD *)(a1 + 376) = v4;
	*(_DWORD *)(a1 + 372) = v5;
	if (*(_BYTE *)(a1 + 245))
	{
		if (v5 != *(unsigned __int8 *)(a1 + 245))
			return -1;
	LABEL_8:
		v2[5] = v4;
		*(_DWORD *)(a1 + 372) = 0;
		*(_DWORD *)(a1 + 376) = 0;
		v2[4] = 0;
		v2[3] = 8;
		*(_DWORD *)(a1 + 360) = v2;
		*(_DWORD *)(a1 + 356) = v2[1];
		return -1;
	}
	v6 = *(_DWORD *)(a1 + 380);
	if (v4 == v6)
		goto LABEL_8;
	if (v4 <= v6)
		return -1;
	return -4;
}

//----- (0055F3F0) --------------------------------------------------------
int __cdecl sub_55F3F0(int a1, int a2)
{
	int v2; // eax
	int v3; // ecx
	unsigned __int16 *i; // edx

	v2 = *(unsigned __int16 *)(a1 + 1868);
	v3 = 0;
	if ((int)(unsigned __int16)v2 <= 0)
		return 0;
	for (i = *(unsigned __int16 **)(a1 + 1876); *i <= a2; i += 3)
	{
		if (++v3 >= v2)
			return 0;
	}
	return *(_DWORD *)(*(_DWORD *)(a1 + 1876) + 6 * v3 + 2);
}

//----- (0055F440) --------------------------------------------------------
int __cdecl sub_55F440(int a1, int a2)
{
	_DWORD *v2; // ebx
	unsigned int v3; // edi
	int v4; // ebp
	int v5; // eax
	int v7; // ecx
	int v8; // edx
	int v9; // ecx
	int v10; // ecx

	v2 = *(_DWORD **)(a1 + 356);
	v3 = (a2 + 1) & 0xFFFFFFFE;
	v4 = *(unsigned __int8 *)(a1 + 245);
	if (!*(_DWORD *)(a1 + 376))
	{
		if (*(_BYTE *)(a1 + 245))
		{
			v5 = v4 + 1;
			LOBYTE(v5) = (v4 + 1) & 0xFE;
			*(_DWORD *)(a1 + 380) = v5 + v3 * v4;
		}
		else
		{
			*(_DWORD *)(a1 + 380) = sub_55F3F0(a1, *(_DWORD *)(a1 + 384));
		}
		if (*(_BYTE *)(a1 + 340) & 1)
			v2[4] = 0;
		else
			v2[4] = *(_DWORD *)(a1 + 1896) - *(_DWORD *)(a1 + 380);
	}
	if ((*(int(__cdecl **)(int, int, int, unsigned int))(a1 + 64))(a1, 5, *(_DWORD *)(a1 + 376) + v2[4] + *v2, v3))
		return -4;
	v7 = *(_DWORD *)(a1 + 372);
	v8 = a2 + *(_DWORD *)(a1 + 376);
	*(_DWORD *)(a1 + 376) = v8;
	v9 = v7 + 1;
	*(_DWORD *)(a1 + 372) = v9;
	if (v4)
	{
		if (v9 == v4)
			goto LABEL_12;
		return -1;
	}
	v10 = *(_DWORD *)(a1 + 380);
	if (v8 == v10)
	{
	LABEL_12:
		*(_DWORD *)(a1 + 372) = 0;
		*(_DWORD *)(a1 + 376) = 0;
		v2[3] = 10;
		*(_DWORD *)(a1 + 360) = v2;
		*(_DWORD *)(a1 + 356) = v2[1];
		if (*(_WORD *)(a1 + 232) < 3u)
			*(_BYTE *)(*v2 + *(_DWORD *)(a1 + 380) + v2[4] + 1) = -128;
		return -1;
	}
	if (v8 <= v10)
		return -1;
	return -4;
}

//----- (0055F570) --------------------------------------------------------
int __cdecl sub_55F570(int a1, unsigned int a2)
{
	int v2; // ebx
	unsigned int v3; // eax
	unsigned int v5; // edx

	v2 = *(_DWORD *)(a1 + 368);
	v3 = a2 + 1;
	LOBYTE(v3) = (a2 + 1) & 0xFE;
	if ((*(int(__cdecl **)(int, int, _DWORD, unsigned int))(a1 + 64))(a1, 5, *(_DWORD *)(v2 + 8), v3))
		return -4;
	v5 = *(_DWORD *)(v2 + 20) & 0xFFFFFFF7;
	*(_DWORD *)(v2 + 36) = 0;
	*(_DWORD *)(v2 + 20) = v5;
	*(_DWORD *)(v2 + 40) = a2;
	if (*(_WORD *)(a1 + 1880) == 1)
	{
		qmemcpy((void *)(a1 + 452), *(const void **)(v2 + 8), a2);
		*(_DWORD *)(a1 + 448) = *(_DWORD *)(v2 + 40);
		*(_DWORD *)(a1 + 420) |= 1u;
	}
	return -1;
}

//----- (0055F600) --------------------------------------------------------
int __cdecl sub_55F600(int a1, int a2)
{
	int v2; // eax
	int v3; // ebx
	int v4; // esi
	int v5; // edi
	int v7; // edx
	int v8; // eax
	const void *v9; // esi
	int v10; // eax

	v2 = a2 + 1;
	v3 = *(_DWORD *)(a1 + 368);
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v4 = *(_DWORD *)(a1 + 1904) - v2;
	v5 = v4 + *(_DWORD *)(v3 + 8);
	if ((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, v4 + *(_DWORD *)(v3 + 8), v2))
		return -4;
	v7 = *(_DWORD *)(v3 + 20) | 8;
	*(_DWORD *)(v3 + 36) = v4;
	*(_DWORD *)(v3 + 20) = v7;
	*(_DWORD *)(v3 + 40) = a2;
	if (*(_WORD *)(a1 + 232) < 3u)
		*(_BYTE *)(v5 + a2 + 1) = -128;
	if (*(_WORD *)(a1 + 1880) == 1)
	{
		v8 = sub_562C9B(
			(unsigned __int8 *)(*(_DWORD *)(v3 + 8) + *(_DWORD *)(v3 + 36)),
			*(char **)(v3 + 8),
			*(_DWORD *)(a1 + 1904));
		*(_DWORD *)(v3 + 20) &= 0xFFFFFFF7;
		v9 = *(const void **)(v3 + 8);
		*(_DWORD *)(v3 + 40) = v8;
		qmemcpy((void *)(a1 + 452), v9, v8);
		v10 = *(_DWORD *)(a1 + 420);
		LOBYTE(v10) = v10 | 1;
		*(_DWORD *)(a1 + 448) = *(_DWORD *)(v3 + 40);
		*(_DWORD *)(a1 + 420) = v10;
	}
	return -1;
}

//----- (0055F6D0) --------------------------------------------------------
int __cdecl sub_55F6D0(int a1, int a2)
{
	_DWORD *v2; // esi
	int v4; // eax

	v2 = *(_DWORD **)(a1 + 368);
	if ((*(int(__cdecl **)(int, int, _DWORD, unsigned int))(a1 + 64))(a1, 5, *v2, (a2 + 1) & 0xFFFFFFFE))
		return -4;
	v4 = v2[5];
	v2[8] = 0;
	LOBYTE(v4) = v4 & 0xEF;
	v2[5] = v4;
	return -1;
}

//----- (0055F710) --------------------------------------------------------
int __cdecl sub_55F710(int a1, int a2)
{
	int v2; // eax
	_DWORD *v3; // ebp
	int v4; // edi
	int v5; // ebx
	int v7; // ecx

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	v3 = *(_DWORD **)(a1 + 368);
	v4 = *(_DWORD *)(a1 + 1900) - v2;
	v5 = v4 + *v3;
	if ((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, v4 + *v3, v2))
		return -4;
	v7 = v3[5];
	v3[8] = v4;
	v3[5] = v7 | 0x10;
	if (*(_WORD *)(a1 + 232) < 3u)
		*(_BYTE *)(v5 + a2 + 1) = -128;
	return -1;
}

//----- (0055F780) --------------------------------------------------------
int __cdecl sub_55F780(int a1, unsigned int a2)
{
	unsigned int v2; // eax
	int v3; // ecx
	int result; // eax
	unsigned int v5; // ecx
	int v6; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	if (*(_BYTE *)(a1 + 132) & 1 && (v3 = *(_DWORD *)(a1 + 1932)) != 0)
	{
		if (v2 <= *(int *)(a1 + 1972) || *(_DWORD *)(a1 + 1936))
		{
			if ((*(int(__cdecl **)(int, int, _DWORD, unsigned int))(a1 + 64))(a1, 5, *(_DWORD *)(a1 + 1960), v2))
			{
				result = -4;
			}
			else
			{
				*(_DWORD *)(a1 + 1968) = a2;
				result = -1;
			}
		}
		else if ((*(int(__cdecl **)(int, int, int, unsigned int))(a1 + 64))(a1, 5, v3, v2))
		{
			result = -4;
		}
		else
		{
			v5 = 0;
			*(_DWORD *)(a1 + 1936) += a2;
			if (a2 / *(_DWORD *)(a1 + 156))
			{
				do
					*(_BYTE *)(*(_DWORD *)(a1 + 1940) + v5++) = 1;
				while (v5 < a2 / *(_DWORD *)(a1 + 156));
			}
			result = -1;
		}
	}
	else
	{
		v6 = -((*(int(__cdecl **)(int, int, int, unsigned int))(a1 + 64))(a1, 7, 1, v2) != 0);
		LOBYTE(v6) = v6 & 0xFB;
		result = v6 - 1;
	}
	return result;
}

//----- (0055F860) --------------------------------------------------------
int __cdecl sub_55F860(int a1, int a2)
{
	int v2; // esi
	unsigned int v3; // edi
	int result; // eax
	unsigned int v5; // eax
	int v6; // edi
	_WORD *v7; // ebx
	int v8; // ecx
	__int64 v9; // rax
	_WORD *v10; // ebx
	int v11; // eax

	v2 = a1;
	v3 = (a2 + 1) & 0xFFFFFFFE;
	if (*(_BYTE *)(a1 + 132) & 1 && *(_DWORD *)(a1 + 1932))
	{
		if ((*(int(__cdecl **)(int, int, int *, int))(a1 + 64))(a1, 5, &a1, 4))
			return -4;
		v5 = *(_DWORD *)(v2 + 1972);
		v6 = v3 - 4;
		if ((unsigned __int16)a1 <= v5 || *(_DWORD *)(v2 + 1936))
		{
			if ((_WORD)a1 == HIWORD(a1))
			{
				if ((*(int(__cdecl **)(int, int, _DWORD, int))(v2 + 64))(v2, 5, *(_DWORD *)(v2 + 1960), v6))
					return -4;
			}
			else
			{
				v10 = (_WORD *)(v5 + *(_DWORD *)(v2 + 1960) - v6);
				if ((*(int(__cdecl **)(int, int, unsigned int, int))(v2 + 64))(v2, 5, v5 + *(_DWORD *)(v2 + 1960) - v6, v6))
					return -4;
				sub_562E30(v10, *(char **)(v2 + 1960), (unsigned __int16)a1);
			}
			result = -1;
			*(_DWORD *)(v2 + 1968) = (unsigned __int16)a1;
		}
		else
		{
			if ((_WORD)a1 == HIWORD(a1))
			{
				if ((*(int(__cdecl **)(int, int, _DWORD, int))(v2 + 64))(v2, 5, *(_DWORD *)(v2 + 1932), v6))
					return -4;
			}
			else
			{
				v7 = (_WORD *)(*(_DWORD *)(v2 + 1932) + *(_DWORD *)(v2 + 152) - v6);
				if ((*(int(__cdecl **)(int, int, _WORD *, int))(v2 + 64))(v2, 5, v7, v6))
					return -4;
				sub_562E30(v7, *(char **)(v2 + 1932), (unsigned __int16)a1);
			}
			v8 = 0;
			v9 = (unsigned __int16)a1;
			*(_DWORD *)(v2 + 1936) += (unsigned __int16)a1;
			if ((int)(v9 / *(int *)(v2 + 156)) > 0)
			{
				do
					*(_BYTE *)(*(_DWORD *)(v2 + 1940) + ++v8 - 1) = 1;
				while (v8 < (int)(unsigned __int16)a1 / *(_DWORD *)(v2 + 156));
			}
			result = -1;
		}
	}
	else
	{
		v11 = -((*(int(__cdecl **)(int, int, int, unsigned int))(a1 + 64))(a1, 7, 1, (a2 + 1) & 0xFFFFFFFE) != 0);
		LOBYTE(v11) = v11 & 0xFB;
		result = v11 - 1;
	}
	return result;
}

//----- (0055FA20) --------------------------------------------------------
int __cdecl sub_55FA20(int a1, int a2)
{
	int v2; // eax
	int v3; // edi
	unsigned int v4; // ecx
	unsigned int v5; // ebp
	unsigned __int16 *v6; // esi
	int result; // eax
	int v8; // eax
	unsigned int i; // ecx
	unsigned __int16 *v10; // esi
	int v11; // eax

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	if (*(_BYTE *)(a1 + 132) & 1 && (v3 = *(_DWORD *)(a1 + 1932)) != 0)
	{
		v4 = *(_DWORD *)(a1 + 1972);
		v5 = a2 * (*(unsigned __int8 *)(a1 + 63) >> 2);
		if (v5 <= v4 || *(_DWORD *)(a1 + 1936))
		{
			v10 = (unsigned __int16 *)(v4 + *(_DWORD *)(a1 + 1960) - v2);
			if ((*(int(__cdecl **)(int, int, unsigned int, int))(a1 + 64))(a1, 5, v4 + *(_DWORD *)(a1 + 1960) - v2, v2))
			{
				result = -4;
			}
			else
			{
				sub_560881(
					v10,
					*(_WORD **)(a1 + 1960),
					*(unsigned __int8 *)(a1 + 63),
					*(unsigned __int8 *)(a1 + 62),
					v5,
					a1 + 2000);
				*(_DWORD *)(a1 + 1968) = v5;
				result = -1;
			}
		}
		else
		{
			v6 = (unsigned __int16 *)(v3 + *(_DWORD *)(a1 + 152) - v2);
			if ((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 5, v3 + *(_DWORD *)(a1 + 152) - v2, v2))
			{
				result = -4;
			}
			else
			{
				sub_560881(
					v6,
					*(_WORD **)(a1 + 1932),
					*(unsigned __int8 *)(a1 + 63),
					*(unsigned __int8 *)(a1 + 62),
					v5,
					a1 + 2000);
				v8 = *(_DWORD *)(a1 + 1964);
				if (v8)
				{
					v5 -= v8;
					qmemcpy(*(void **)(a1 + 1932), (const void *)(v8 + *(_DWORD *)(a1 + 1932)), v5);
					*(_DWORD *)(a1 + 1964) = 0;
				}
				*(_DWORD *)(a1 + 1936) += v5;
				for (i = 0; i < v5 / *(_DWORD *)(a1 + 156); ++i)
					*(_BYTE *)(i + *(_DWORD *)(a1 + 1940)) = 1;
				result = -1;
			}
		}
	}
	else
	{
		v11 = -((*(int(__cdecl **)(int, int, int, int))(a1 + 64))(a1, 7, 1, v2) != 0);
		LOBYTE(v11) = v11 & 0xFB;
		result = v11 - 1;
	}
	return result;
}

//----- (0055FBA0) --------------------------------------------------------
int __cdecl sub_55FBA0(int a1, int a2)
{
	unsigned int v2; // eax
	int result; // eax
	__int16 v4; // ax
	__int16 v5; // dx
	int v6; // eax
	unsigned __int8 v7[12]; // [esp+4h] [ebp-Ch]

	v2 = a2 + 1;
	LOBYTE(v2) = (a2 + 1) & 0xFE;
	if (*(_BYTE *)(a1 + 132) & 1 && *(_DWORD *)(a1 + 1932))
	{
		if (v2 > 0xC || (*(int(__cdecl **)(int, int, unsigned __int8 *, unsigned int))(a1 + 64))(a1, 5, v7, v2))
		{
			result = -4;
		}
		else
		{
			v4 = *(_WORD *)v7;
			*(_DWORD *)(a1 + 2000) = *(_DWORD *)&v7[2];
			*(_WORD *)(a1 + 2004) = v4;
			if (*(_BYTE *)(a1 + 62) == 2)
			{
				v5 = *(_WORD *)&v7[6];
				*(_DWORD *)(a1 + 2006) = *(_DWORD *)&v7[8];
				*(_WORD *)(a1 + 2010) = v5;
			}
			result = -1;
		}
	}
	else
	{
		v6 = -((*(int(__cdecl **)(int, int, int, unsigned int))(a1 + 64))(a1, 7, 1, v2) != 0);
		LOBYTE(v6) = v6 & 0xFB;
		result = v6 - 1;
	}
	return result;
}

//----- (0055FC40) --------------------------------------------------------
int __cdecl sub_55FC40(int a1)
{
	int result; // eax

	result = -1;
	*(_DWORD *)(a1 + 1744) = -1;
	return result;
}

//----- (0055FC50) --------------------------------------------------------
int __cdecl sub_55FC50(int a1)
{
	int v1; // eax
	int v2; // edx
	int v3; // ecx
	int v4; // eax
	int v5; // ecx
	int result; // eax
	char v7; // cl

	*(_DWORD *)(a1 + 1732) = *(unsigned __int16 *)(a1 + 238) / (int)*(unsigned __int8 *)(a1 + 242);
	v1 = *(unsigned __int16 *)(a1 + 240) / (int)*(unsigned __int8 *)(a1 + 243);
	HIWORD(v3) = 0;
	v2 = v1 * *(_DWORD *)(a1 + 1732);
	*(_DWORD *)(a1 + 1736) = v1;
	*(_DWORD *)(a1 + 1740) = v2;
	BYTE1(v3) = *(_BYTE *)(a1 + 242);
	LOBYTE(v3) = *(_BYTE *)(a1 + 243);
	*(_DWORD *)(a1 + 1924) = nullsub_31;
	*(_DWORD *)(a1 + 1928) = nullsub_31;
	v4 = *(_DWORD *)(a1 + 128);
	*(_DWORD *)(a1 + 1920) = sub_560850;
	if (v4 & 1)
	{
		*(_DWORD *)(a1 + 1916) = sub_560760;
		*(_DWORD *)(a1 + 1920) = sub_5607B0;
	}
	else
	{
		*(_DWORD *)(a1 + 1916) = sub_560030;
		*(_DWORD *)(a1 + 1920) = sub_5606D0;
	}
	v5 = v3 - 1026;
	if (!v5)
	{
		v7 = *(_BYTE *)(a1 + 264);
		if (v7)
		{
			if (v7 == 4)
			{
				*(_DWORD *)(a1 + 1924) = sub_565360;
				*(_DWORD *)(a1 + 1928) = sub_5654A0;
				return -1;
			}
		}
		else
		{
			*(_DWORD *)(a1 + 1924) = sub_5644B0;
			if (*(_BYTE *)(a1 + 234) & 4)
			{
				if ((v4 & 0x80u) != 0)
				{
					*(_DWORD *)(a1 + 1928) = sub_5640C0;
					return -1;
				}
				*(_DWORD *)(a1 + 1928) = sub_563C90;
			}
		}
		return -1;
	}
	if (v5 != 2)
		return -1;
	if (*(_BYTE *)(a1 + 264))
	{
		if (*(_BYTE *)(a1 + 264) == 1)
		{
			*(_DWORD *)(a1 + 1924) = sub_564738;
			*(_DWORD *)(a1 + 1928) = sub_564AC0;
			return -1;
		}
		if (*(_BYTE *)(a1 + 264) == 4)
		{
			*(_DWORD *)(a1 + 1924) = sub_564E60;
			*(_DWORD *)(a1 + 1928) = sub_564FB0;
			return -1;
		}
		return -1;
	}
	*(_DWORD *)(a1 + 1924) = sub_564546;
	if (!(*(_BYTE *)(a1 + 234) & 4))
	{
		if (v4 & 0x40)
		{
			*(_DWORD *)(a1 + 1924) = sub_564604;
			return -1;
		}
		return -1;
	}
	if ((v4 & 0x80u) == 0)
	{
		if (v4 & 0x40)
			*(_DWORD *)(a1 + 1928) = sub_563880;
		else
			*(_DWORD *)(a1 + 1928) = sub_563020;
		result = -1;
	}
	else
	{
		*(_DWORD *)(a1 + 1928) = sub_563470;
		result = -1;
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);
// 560850: using guessed type int sub_560850();

//----- (0055FE20) --------------------------------------------------------
int __cdecl sub_55FE20(int a1, int a2)
{
	int v2; // esi
	int v3; // ebp
	int v4; // eax
	int v5; // ebx
	int *v6; // eax
	int v7; // ecx
	int v8; // eax
	_DWORD *v9; // edi
	bool v10; // zf
	int result; // eax
	int v12; // ebp
	int v13; // ebx
	int *v14; // eax
	int v15; // ecx
	int v16; // eax
	_DWORD *v17; // edi
	int v18; // [esp+10h] [ebp-8h]
	int v19; // [esp+10h] [ebp-8h]
	int v20; // [esp+14h] [ebp-4h]
	int v21; // [esp+14h] [ebp-4h]
	int v22; // [esp+1Ch] [ebp+4h]
	int v23; // [esp+1Ch] [ebp+4h]

	v2 = a1;
	v3 = 0;
	v4 = *(_DWORD *)(a1 + 1828);
	if (v4)
	{
		v22 = 0;
		v20 = v4;
		do
		{
			v5 = *(_DWORD *)(*(_DWORD *)(v2 + 1844) + v3);
			v6 = (int *)(v22 + *(_DWORD *)(v2 + 1848));
			v7 = v6[2];
			v8 = *v6;
			if (v8)
			{
				v9 = (_DWORD *)(v7 + 4);
				v18 = v8;
				do
				{
					if (v9[1] == a2)
						(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(v2 + 72))(v2, v5, *(v9 - 1), *v9);
					v9 += 3;
					--v18;
				} while (v18);
			}
			v3 += 16;
			v10 = v20 == 1;
			v22 += 12;
			--v20;
		} while (!v10);
	}
	result = *(_DWORD *)(v2 + 1852);
	v12 = 0;
	if (result)
	{
		v23 = 0;
		v19 = *(_DWORD *)(v2 + 1852);
		do
		{
			v13 = *(_DWORD *)(*(_DWORD *)(v2 + 1860) + v12);
			v14 = (int *)(*(_DWORD *)(v2 + 1864) + v23);
			v15 = v14[2];
			v16 = *v14;
			if (v16)
			{
				v17 = (_DWORD *)(v15 + 4);
				v21 = v16;
				do
				{
					if (v17[1] == a2)
						(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(v2 + 72))(v2, v13, *(v17 - 1), *v17);
					v17 += 3;
					--v21;
				} while (v21);
			}
			v12 += 16;
			result = v19 - 1;
			v10 = v19 == 1;
			v23 += 12;
			--v19;
		} while (!v10);
	}
	return result;
}

//----- (0055FF30) --------------------------------------------------------
char __cdecl sub_55FF30(int a1, int *a2)
{
	int v2; // esi
	int *v3; // ebx
	int v4; // eax
	int(__cdecl *v5)(int, int, _DWORD, _DWORD); // eax
	int v6; // ecx
	int v7; // edx
	int v8; // edi
	int v9; // ebp
	int v10; // eax
	int v11; // ebx
	int v13; // [esp-8h] [ebp-1Ch]
	int v14; // [esp+Ch] [ebp-8h]
	int v15; // [esp+10h] [ebp-4h]
	int v16; // [esp+18h] [ebp+4h]

	v2 = a1;
	v3 = (int *)a2[1];
	LOBYTE(v4) = *(_BYTE *)(a1 + 420);
	v16 = a2[1];
	if (!(v4 & 2))
	{
		if ((v5 = *(int(__cdecl **)(int, int, _DWORD, _DWORD))(v2 + 72)) != 0 && (v4 = v5(v2, 6, 0, 0)) != 0
			|| (v4 = *(_DWORD *)(v2 + 424)) != 0)
		{
			v6 = *(_DWORD *)(v2 + 1732);
			v7 = *(_DWORD *)(v2 + 1736);
			v8 = v4 + *(_DWORD *)(v2 + 444);
			v15 = *(_DWORD *)(v2 + 1732);
			v14 = *(_DWORD *)(v2 + 1736);
			if (a2[5] & 0x40)
				v9 = *(_DWORD *)(v2 + 1768);
			else
				v9 = *a2;
			v10 = v3[3];
			if (v10 & 4)
				v11 = *(_DWORD *)(v2 + 1776);
			else
				v11 = *v3;
			if (*(_DWORD *)(v2 + 72) && v10 & 8)
			{
				LOBYTE(v10) = v10 & 0xF7;
				*(_DWORD *)(v16 + 12) = v10;
				(*(void(__cdecl **)(int, int, int, _DWORD))(v2 + 72))(v2, 3, v11, *(_DWORD *)(v16 + 20));
				v7 = v14;
				v6 = v15;
			}
			v13 = *(_DWORD *)(v2 + 428);
			if (a2[5] & 0x20)
				(*(void(__cdecl **)(int, int, int, int, int, int))(v2 + 1928))(v11, v9, v8, v6, v7, v13);
			else
				(*(void(__cdecl **)(int, int, int, int, int, int))(v2 + 1924))(v11, v9, v8, v6, v7, v13);
			v4 = *(_DWORD *)(v2 + 72);
			if (v4)
				LOBYTE(v4) = ((int(__cdecl *)(int, int, _DWORD, _DWORD))v4)(v2, 7, 0, 0);
		}
	}
	return v4;
}

//----- (00560030) --------------------------------------------------------
int __cdecl sub_560030(int a1)
{
	int result; // eax
	int v2; // eax

	result = sub_560080(a1);
	if (result == -1)
	{
		sub_560600(a1);
		v2 = *(_DWORD *)(a1 + 416);
		*(_DWORD *)(a1 + 1756) = v2;
		if (!(*(_BYTE *)(a1 + 420) & 8))
			*(_DWORD *)(a1 + 416) = *(_DWORD *)(v2 + 12);
		result = -1;
	}
	return result;
}

//----- (00560080) --------------------------------------------------------
int __cdecl sub_560080(int a1)
{
	int v1; // ebx
	int v2; // ebp
	int v3; // edi
	int v4; // esi
	char v5; // al
	int v6; // eax
	int v7; // eax
	int result; // eax
	int v9; // eax
	signed int v10; // ecx
	int v11; // eax
	int v12; // eax
	signed int v13; // ecx
	int v14; // eax
	int v15; // eax
	int v16; // eax
	void(__cdecl *v17)(int, int, _DWORD, _DWORD); // eax
	int v18; // ecx
	int v19; // eax
	int v20; // eax
	int v21; // eax
	int v22; // eax
	int v23; // eax
	int(__cdecl *v24)(_DWORD, _DWORD); // eax
	int v25; // eax
	char v26; // al
	signed int v27; // [esp+10h] [ebp-4h]
	int v28; // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD *)(a1 + 416);
	v3 = a1 + 416;
	v4 = a1 + 64;
	if (*(_BYTE *)(v2 + 20) & 1)
	{
		if (*(_BYTE *)(a1 + 420) & 0x10)
		{
			sub_5605C0(a1);
			*(_DWORD *)(a1 + 420) |= 8u;
			v9 = *(_DWORD *)(v2 + 20);
			LOBYTE(v9) = v9 | 0x80;
			*(_DWORD *)(v2 + 20) = v9;
			result = -1;
		}
		else if (*(_BYTE *)(a1 + 132) & 2)
		{
			*(_DWORD *)(a1 + 1744) = *(_DWORD *)(v2 + 28);
			sub_562B60(a1, 60 * *(_DWORD *)(v2 + 28) / *(_DWORD *)(a1 + 116));
			result = -1;
		}
		else
		{
			v10 = sub_562BA0(a1);
			v11 = *(_DWORD *)(a1 + 1744);
			if (*(_BYTE *)(a1 + 420) & 2)
				v12 = v11 + 2;
			else
				v12 = v11 + 1;
			if (v10 >= 60 * v12 / *(_DWORD *)(a1 + 116))
			{
				v13 = sub_5603B0(a1, v4, v3, v2, v10);
				v27 = v13;
				if (!(*(_BYTE *)(a1 + 128) & 4))
				{
					v28 = *(_DWORD *)(a1 + 112) / 3 - 1;
					if (v28 < 0)
						v28 = 0;
					if (*(_DWORD *)(v2 + 28) != v13)
					{
						while (!(*(_BYTE *)(v2 + 20) & 2) && sub_560560((_DWORD *)v1) <= v28)
						{
							v14 = *(_DWORD *)(v2 + 20);
							if (v14 & 4)
							{
								if (v14 & 8)
								{
									*(_DWORD *)(v2 + 40) = sub_562C9B(
										(unsigned __int8 *)(*(_DWORD *)(v2 + 8) + *(_DWORD *)(v2 + 36)),
										*(char **)(v2 + 8),
										*(_DWORD *)(v1 + 1904));
									v15 = *(_DWORD *)(v2 + 20);
									LOBYTE(v15) = v15 & 0xF7;
									*(_DWORD *)(v2 + 20) = v15;
								}
								qmemcpy((void *)(v3 + 36), *(const void **)(v2 + 8), *(_DWORD *)(v2 + 40));
								v16 = *(_DWORD *)(v1 + 420);
								LOBYTE(v16) = v16 | 1;
								*(_DWORD *)(v1 + 448) = *(_DWORD *)(v2 + 40);
								*(_DWORD *)(v1 + 420) = v16;
							}
							v17 = *(void(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 72);
							if (v17)
							{
								v18 = *(_DWORD *)(v2 + 20);
								if (v18 & 0x100)
								{
									v17(v1, 4, *(_DWORD *)(v2 + 28), *(_DWORD *)(v1 + 288));
									v19 = *(_DWORD *)(v2 + 20);
									BYTE1(v19) &= 0xFEu;
									*(_DWORD *)(v2 + 20) = v19;
								}
								v20 = *(_DWORD *)(v2 + 20);
								if (v20 & 0x200)
								{
									(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 72))(
										v1,
										5,
										*(_DWORD *)(v2 + 28),
										*(_DWORD *)(v1 + 288));
									v21 = *(_DWORD *)(v2 + 20);
									BYTE1(v21) &= 0xFDu;
									*(_DWORD *)(v2 + 20) = v21;
								}
								v22 = *(_DWORD *)(v2 + 20);
								if (v22 & 0x400)
								{
									sub_55FE20(v1, *(_DWORD *)(v2 + 28));
									v23 = *(_DWORD *)(v2 + 20);
									BYTE1(v23) &= 0xFBu;
									*(_DWORD *)(v2 + 20) = v23;
								}
							}
							v24 = *(int(__cdecl **)(_DWORD, _DWORD))(v1 + 76);
							if (v24 && v24(0, *(_DWORD *)(v2 + 28)))
								return -2;
							v25 = *(_DWORD *)(v2 + 20);
							*(_DWORD *)(v2 + 20) = 0;
							*(_DWORD *)(v2 + 24) = v25;
							v2 = *(_DWORD *)(v2 + 12);
							v3 = v1 + 416;
							*(_DWORD *)(v1 + 416) = v2;
							++*(_DWORD *)(v1 + 28);
							if (!(*(_BYTE *)(v2 + 20) & 1))
							{
								v26 = *(_BYTE *)(v1 + 420);
								++*(_DWORD *)(v1 + 1752);
								if (v26 & 4 && !(*(_BYTE *)(v1 + 336) & 4))
								{
									sub_5605E0(v1);
									return -1;
								}
								goto LABEL_47;
							}
							if (*(_DWORD *)(v2 + 28) == v27)
								break;
						}
					}
				}
				result = sub_5605C0(v1);
			}
			else if (*(_BYTE *)(a1 + 420) & 4)
			{
				if (sub_5603B0(a1, v4, a1 + 416, v2, v10) == *(_DWORD *)(a1 + 1744) && *(_BYTE *)(v2 + 20) & 0x80)
				{
					result = -1;
					*(_DWORD *)(a1 + 1744) = *(_DWORD *)(v2 + 28);
				}
				else
				{
					*(_DWORD *)(a1 + 1744) = *(_DWORD *)(v2 + 28);
					*(_DWORD *)(a1 + 420) |= 8u;
					*(_DWORD *)(v2 + 20) |= 0x80u;
					result = -1;
				}
			}
			else
			{
				result = -10;
			}
		}
	}
	else
	{
		v5 = *(_BYTE *)(a1 + 420);
		++*(_DWORD *)(a1 + 1752);
		if (!(v5 & 4) || *(_BYTE *)(a1 + 336) & 4)
		{
		LABEL_47:
			result = -9;
		}
		else
		{
			sub_5605E0(a1);
			v6 = *(_DWORD *)(a1 + 420);
			if (v6 & 0x10)
			{
				LOBYTE(v6) = v6 | 8;
				*(_DWORD *)(a1 + 420) = v6;
				v7 = *(_DWORD *)(v2 + 20);
				LOBYTE(v7) = v7 | 0x80;
				*(_DWORD *)(v2 + 20) = v7;
			}
			result = -1;
		}
	}
	return result;
}

//----- (005603B0) --------------------------------------------------------
signed int __cdecl sub_5603B0(int a1, int a2, int a3, int a4, int a5)
{
	int v5; // ebp
	signed int v6; // esi
	int v7; // edi
	signed int result; // eax
	int v9; // ecx
	char v10; // bl
	int v11; // esi
	unsigned int v12; // eax
	bool v13; // zf
	int v14; // edx
	int v15; // ecx
	int v16; // ecx
	int v17; // ecx
	int v18; // esi
	int v19; // ecx
	signed int v20; // [esp+14h] [ebp+4h]
	signed int v21; // [esp+20h] [ebp+10h]

	v5 = *(_DWORD *)(a2 + 48);
	v6 = *(_DWORD *)(a4 + 28);
	v7 = a1;
	result = a5 * *(_DWORD *)(a2 + 48) / 0x3Cu;
	v21 = *(_DWORD *)(a4 + 28);
	if (*(_BYTE *)(a3 + 4) & 2)
		--result;
	v9 = *(_DWORD *)(a1 + 336);
	v10 = 0;
	v20 = *(_DWORD *)(a1 + 300);
	if ((v9 & 0x80u) != 0)
	{
		if (v9 & 0x100)
			v20 = *(_DWORD *)(v7 + 320);
		do
		{
			if ((*(_DWORD *)(a2 + 64) & 4 || result <= v20)
				&& (!(*(_DWORD *)(a2 + 64) & 4) || v6 != *(_DWORD *)(v7 + 296) || v10))
			{
				break;
			}
			v11 = *(_DWORD *)(v7 + 296) - v20 - 1;
			sub_562B90(v7, 60 * v11 / v5);
			v12 = sub_562BA0(v7);
			v10 = 1;
			v13 = v11 == 0;
			v6 = v21;
			result = (int)(v5 * v12) / 60;
		} while (!v13);
	}
	v14 = a2;
	if (*(_BYTE *)(a2 + 64) & 4)
	{
		if (result <= v6)
		{
			v16 = *(_DWORD *)(v7 + 336);
			BYTE1(v16) &= 0xF7u;
			*(_DWORD *)(v7 + 336) = v16;
		}
		else
		{
			if (!(*(_BYTE *)(v7 + 234) & 1) || !(*(_BYTE *)(a2 + 68) & 1))
				sub_562B90(v7, 60 * (v6 - result) / v5);
			v15 = *(_DWORD *)(v7 + 336);
			v14 = a2;
			BYTE1(v15) |= 8u;
			result = v6;
			*(_DWORD *)(v7 + 336) = v15;
		}
	}
	if (v10)
	{
		if (*(_BYTE *)(a3 + 4) & 2)
		{
			if (!(*(_BYTE *)(v14 + 64) & 4) && --result < *(int *)(v7 + 296))
				result = v20;
		}
		v17 = *(_DWORD *)(v7 + 312);
		if (v17 != -1)
		{
			v18 = *(_DWORD *)(v7 + 316);
			*(_DWORD *)(v7 + 316) = -1;
			*(_DWORD *)(v7 + 296) = v18;
			*(_DWORD *)(v7 + 300) = v17;
			*(_DWORD *)(v7 + 312) = -1;
		}
		v19 = *(_DWORD *)(v7 + 336);
		if (!(v19 & 0x100))
		{
			*(_DWORD *)(v7 + 324) = *(_DWORD *)(v7 + 296);
			*(_DWORD *)(v7 + 320) = *(_DWORD *)(v7 + 300);
		}
		*(_DWORD *)(v7 + 336) = v19 & 0xFFFFFE7F;
	}
	return result;
}

//----- (00560560) --------------------------------------------------------
int __cdecl sub_560560(_DWORD *a1)
{
	int v1; // ebx
	int v2; // ecx
	int v3; // edi
	int result; // eax
	int v5; // ecx
	int v6; // edi

	v1 = a1[436];
	v2 = a1[80];
	v3 = *(_DWORD *)(a1[104] + 28);
	if (v3 >= v1 && v3 <= v2)
		return v3 - v1;
	v5 = v2 - v1;
	result = a1[28] / 3;
	if (v5 >= 0)
	{
		v6 = v3 - a1[74];
		if (v6 >= 0)
			result = v6 + v5 + 1;
	}
	return result;
}

//----- (005605C0) --------------------------------------------------------
int __cdecl sub_5605C0(int a1)
{
	*(_DWORD *)(a1 + 1744) = *(_DWORD *)(*(_DWORD *)(a1 + 416) + 28);
	return -1;
}

//----- (005605E0) --------------------------------------------------------
int __cdecl sub_5605E0(int a1)
{
	int result; // eax

	result = *(_DWORD *)(*(_DWORD *)(a1 + 416) + 16);
	*(_DWORD *)(a1 + 416) = result;
	*(_DWORD *)(result + 20) = *(_DWORD *)(result + 24);
	return result;
}

//----- (00560600) --------------------------------------------------------
char __cdecl sub_560600(int a1)
{
	int v1; // esi
	int v2; // eax
	int v3; // edi
	int v4; // eax
	char *v5; // ecx
	int v6; // eax
	int v7; // eax
	char *v8; // ecx

	v1 = *(_DWORD *)(a1 + 416);
	LOBYTE(v2) = *(_BYTE *)(a1 + 420);
	v3 = *(_DWORD *)(v1 + 4);
	if (!(v2 & 2))
	{
		v4 = *(_DWORD *)(v3 + 12);
		if (v4 & 2)
		{
			if (*(_BYTE *)(a1 + 340) & 1)
			{
				v5 = *(char **)(a1 + 1776);
				LOBYTE(v4) = v4 | 4;
				*(_DWORD *)(v3 + 12) = v4;
			}
			else
			{
				v5 = *(char **)v3;
			}
			*(_DWORD *)(v3 + 20) = sub_562C9B(
				(unsigned __int8 *)(*(_DWORD *)v3 + *(_DWORD *)(v3 + 16)),
				v5,
				*(_DWORD *)(a1 + 1908));
			v6 = *(_DWORD *)(v3 + 12);
			LOBYTE(v6) = v6 & 0xFD;
			*(_DWORD *)(v3 + 12) = v6;
		}
		if (*(_BYTE *)(v1 + 20) & 8)
		{
			*(_DWORD *)(v1 + 40) = sub_562C9B(
				(unsigned __int8 *)(*(_DWORD *)(v1 + 8) + *(_DWORD *)(v1 + 36)),
				*(char **)(v1 + 8),
				*(_DWORD *)(a1 + 1904));
			v7 = *(_DWORD *)(v1 + 20);
			LOBYTE(v7) = v7 & 0xF7;
			*(_DWORD *)(v1 + 20) = v7;
		}
		v2 = *(_DWORD *)(v1 + 20);
		if (v2 & 0x10)
		{
			if (*(_BYTE *)(a1 + 340) & 2)
			{
				v8 = *(char **)(a1 + 1768);
				LOBYTE(v2) = v2 | 0x40;
				*(_DWORD *)(v1 + 20) = v2;
			}
			else
			{
				v8 = *(char **)v1;
			}
			sub_562C9B((unsigned __int8 *)(*(_DWORD *)v1 + *(_DWORD *)(v1 + 32)), v8, *(_DWORD *)(a1 + 1912));
			v2 = *(_DWORD *)(v1 + 20);
			LOBYTE(v2) = v2 & 0xEF;
			*(_DWORD *)(v1 + 20) = v2;
		}
	}
	return v2;
}

//----- (005606D0) --------------------------------------------------------
int __cdecl sub_5606D0(_DWORD *a1)
{
	int *v1; // edi
	void(__cdecl *v2)(_DWORD *, int, int, int); // eax
	int v3; // eax
	void(__cdecl *v4)(_DWORD *, int, _DWORD *, _DWORD); // eax
	int(__cdecl *v5)(_DWORD *, int); // eax
	int result; // eax

	v1 = (int *)a1[439];
	if (v1[5] & 4 || a1[105] & 1)
	{
		if (v1[5] & 4)
		{
			v2 = (void(__cdecl *)(_DWORD *, int, int, int))a1[18];
			if (v2)
				v2(a1, 2, v1[2], v1[10]);
		}
		else
		{
			v3 = a1[105];
			if (v3 & 1)
			{
				LOBYTE(v3) = v3 & 0xFE;
				a1[105] = v3;
				v4 = (void(__cdecl *)(_DWORD *, int, _DWORD *, _DWORD))a1[18];
				if (v4)
					v4(a1, 2, a1 + 113, a1[112]);
			}
		}
	}
	sub_55FF30((int)a1, v1);
	v5 = (int(__cdecl *)(_DWORD *, int))a1[19];
	if (v5 && v5(a1, v1[7]))
		result = -2;
	else
		result = -1;
	return result;
}

//----- (00560760) --------------------------------------------------------
int __cdecl sub_560760(int a1)
{
	int result; // eax
	int v2; // edi

	result = sub_560080(a1);
	if (result == -1)
	{
		sub_560600(a1);
		v2 = *(_DWORD *)(a1 + 416);
		sub_55FF30(a1, *(int **)(a1 + 416));
		*(_DWORD *)(a1 + 1756) = v2;
		if (!(*(_BYTE *)(a1 + 420) & 8))
			*(_DWORD *)(a1 + 416) = *(_DWORD *)(v2 + 12);
		result = -1;
	}
	return result;
}

//----- (005607B0) --------------------------------------------------------
int __cdecl sub_5607B0(_DWORD *a1)
{
	_DWORD *v1; // edi
	void(__cdecl *v2)(_DWORD *, int, _DWORD, _DWORD); // eax
	int v3; // eax
	void(__cdecl *v4)(_DWORD *, int, _DWORD *, _DWORD); // eax
	int(__cdecl *v5)(_DWORD *, _DWORD); // eax
	int result; // eax

	v1 = (_DWORD *)a1[439];
	if (v1[5] & 4 || a1[105] & 1)
	{
		if (v1[5] & 4)
		{
			v2 = (void(__cdecl *)(_DWORD *, int, _DWORD, _DWORD))a1[18];
			if (v2)
				v2(a1, 2, v1[2], v1[10]);
		}
		else
		{
			v3 = a1[105];
			if (v3 & 1)
			{
				LOBYTE(v3) = v3 & 0xFE;
				a1[105] = v3;
				v4 = (void(__cdecl *)(_DWORD *, int, _DWORD *, _DWORD))a1[18];
				if (v4)
					v4(a1, 2, a1 + 113, a1[112]);
			}
		}
	}
	v5 = (int(__cdecl *)(_DWORD *, _DWORD))a1[19];
	if (v5 && v5(a1, v1[7]))
		result = -2;
	else
		result = -1;
	return result;
}

//----- (00560850) --------------------------------------------------------
int sub_560850()
{
	return -1;
}
// 560850: using guessed type int sub_560850();

//----- (00560860) --------------------------------------------------------
int __cdecl sub_560860(int a1)
{
	int result; // eax

	result = a1;
	*(_WORD *)(a1 + 4) = 0;
	*(_DWORD *)a1 = 0;
	*(_WORD *)(a1 + 10) = 0;
	*(_DWORD *)(a1 + 6) = 0;
	return result;
}

//----- (00560881) --------------------------------------------------------
void __cdecl sub_560881(unsigned __int16 *a1, _WORD *a2, __int16 a3, __int16 a4, unsigned int a5, int a6)
{
	int v6; // eax
	int v7; // edx
	unsigned __int16 *v8; // esi
	_WORD *v9; // edi
	signed int v10; // ebp
	int v11; // ebx
	bool v12; // zf
	bool k; // cc
	unsigned int v14; // ecx
	unsigned int v15; // ecx
	unsigned int v16; // ecx
	unsigned int v17; // ecx
	int v18; // eax
	int v19; // edx
	unsigned __int16 *v20; // esi
	_WORD *v21; // edi
	unsigned int v22; // ebp
	signed int v23; // ebp
	int v24; // ebx
	bool v25; // zf
	bool i; // cc
	unsigned int v27; // ecx
	unsigned int v28; // ecx
	unsigned int v29; // ecx
	unsigned int v30; // ecx
	_WORD *v31; // edi
	unsigned __int16 *v32; // esi
	int v33; // eax
	int v34; // edx
	unsigned int v35; // ebp
	signed int v36; // ebp
	int v37; // ebx
	bool v38; // zf
	bool j; // cc
	unsigned int v40; // ecx
	unsigned int v41; // ecx
	unsigned int v42; // ecx
	unsigned int v43; // ecx
	unsigned int v44; // [esp-14h] [ebp-20h]
	unsigned int v45; // [esp-14h] [ebp-20h]
	unsigned int v46; // [esp-14h] [ebp-20h]

	if (a3 != 8 && a3 == 16)
	{
		if (a4 == 2)
		{
			v18 = *(_DWORD *)a6;
			v19 = *(unsigned __int16 *)(a6 + 4);
			v20 = a1;
			v21 = a2;
			v22 = a5 >> 1;
			if ((int)(a5 >> 1) >= 16 && (unsigned __int8)a1 & 3)
			{
				switch ((unsigned __int8)a1 & 3)
				{
				case 0:
					break;
				case 1:
					v45 = v22 - 12;
					v24 = 0;
					v23 = ((v22 - 12) >> 4) + 1;
				LABEL_122:
					v30 = *((unsigned __int8 *)v20 + 2) << 16;
					LOWORD(v30) = *v20;
					LOBYTE(v24) = *v20;
					v27 = v30 >> 8;
					v20 = (unsigned __int16 *)((char *)v20 - 1);
					v21 -= 4;
					LOBYTE(v19) = byte_587000[v24 + 309040] | v19;
					goto LABEL_80;
				case 2:
					v45 = v22 - 8;
					v24 = 0;
					v23 = ((v22 - 8) >> 4) + 1;
				LABEL_120:
					LOWORD(v27) = *v20;
					LOBYTE(v24) = *v20;
					v21 -= 8;
					--v20;
					LOBYTE(v19) = byte_587000[v24 + 309040] | v19;
					goto LABEL_88;
				case 3:
					v45 = v22 - 4;
					v24 = 0;
					v23 = ((v22 - 4) >> 4) + 1;
				LABEL_118:
					LOBYTE(v24) = *(_BYTE *)v20;
					v21 -= 12;
					v20 = (unsigned __int16 *)((char *)v20 - 3);
					LOBYTE(v19) = byte_587000[v24 + 309040] | v19;
					goto LABEL_96;
				}
			}
			v45 = a5 >> 1;
			v23 = a5 >> 5;
			v24 = 0;
			v25 = a5 >> 5 == 0;
			for (i = (int)(a5 >> 5) <= 0; !i; i = v23-- <= 1)
			{
				v28 = *(_DWORD *)v20;
				LOBYTE(v24) = *(_DWORD *)v20;
				LOBYTE(v19) = byte_587000[v24 + 309040] | v19;
				v18 += *(_DWORD *)&byte_587000[2 * v19 + 300496];
				LOWORD(v19) = *(_WORD *)&byte_587000[v19 + 306192];
				if (v18 > 0x7FFF)
				{
					v18 = 0x7FFF;
				}
				else if (v18 < -32768)
				{
					v18 = -32768;
				}
				LOBYTE(v19) = byte_587000[v24 + 309296] | v19;
				*v21 = v18;
			LABEL_76:
				LOBYTE(v24) = BYTE1(v28);
				v18 += *(_DWORD *)&byte_587000[2 * v19 + 300496];
				LOWORD(v19) = *(_WORD *)&byte_587000[v19 + 306192];
				if (v18 > 0x7FFF)
				{
					v18 = 0x7FFF;
				}
				else if (v18 < -32768)
				{
					v18 = -32768;
				}
				LOBYTE(v19) = byte_587000[v24 + 309040] | v19;
				v21[2] = v18;
				v27 = v28 >> 16;
			LABEL_80:
				v18 += *(_DWORD *)&byte_587000[2 * v19 + 300496];
				LOWORD(v19) = *(_WORD *)&byte_587000[v19 + 306192];
				if (v18 > 0x7FFF)
				{
					v18 = 0x7FFF;
				}
				else if (v18 < -32768)
				{
					v18 = -32768;
				}
				LOBYTE(v19) = byte_587000[v24 + 309296] | v19;
				v21[4] = v18;
			LABEL_84:
				LOBYTE(v24) = v27;
				v18 += *(_DWORD *)&byte_587000[2 * v19 + 300496];
				LOWORD(v19) = *(_WORD *)&byte_587000[v19 + 306192];
				if (v18 > 0x7FFF)
				{
					v18 = 0x7FFF;
				}
				else if (v18 < -32768)
				{
					v18 = -32768;
				}
				LOBYTE(v19) = byte_587000[v24 + 309040] | v19;
				v21[6] = v18;
			LABEL_88:
				v18 += *(_DWORD *)&byte_587000[2 * v19 + 300496];
				LOWORD(v19) = *(_WORD *)&byte_587000[v19 + 306192];
				if (v18 > 0x7FFF)
				{
					v18 = 0x7FFF;
				}
				else if (v18 < -32768)
				{
					v18 = -32768;
				}
				LOBYTE(v19) = byte_587000[v24 + 309296] | v19;
				v21[8] = v18;
			LABEL_92:
				LOBYTE(v24) = BYTE1(v27);
				v18 += *(_DWORD *)&byte_587000[2 * v19 + 300496];
				LOWORD(v19) = *(_WORD *)&byte_587000[v19 + 306192];
				if (v18 > 0x7FFF)
				{
					v18 = 0x7FFF;
				}
				else if (v18 < -32768)
				{
					v18 = -32768;
				}
				LOBYTE(v19) = byte_587000[v24 + 309040] | v19;
				v21[10] = v18;
			LABEL_96:
				v18 += *(_DWORD *)&byte_587000[2 * v19 + 300496];
				LOWORD(v19) = *(_WORD *)&byte_587000[v19 + 306192];
				if (v18 > 0x7FFF)
				{
					v18 = 0x7FFF;
				}
				else if (v18 < -32768)
				{
					v18 = -32768;
				}
				LOBYTE(v19) = byte_587000[v24 + 309296] | v19;
				v21[12] = v18;
			LABEL_100:
				v18 += *(_DWORD *)&byte_587000[2 * v19 + 300496];
				LOWORD(v19) = *(_WORD *)&byte_587000[v19 + 306192];
				if (v18 > 0x7FFF)
				{
					v18 = 0x7FFF;
				}
				else if (v18 < -32768)
				{
					v18 = -32768;
				}
				v21[14] = v18;
				v20 += 2;
				v21 += 16;
				v25 = v23 == 1;
			}
			if (v25)
			{
				switch ((v45 >> 1) & 7)
				{
				case 0u:
					break;
				case 1u:
					LOBYTE(v24) = 16 * *(_BYTE *)v20;
					v21 -= 14;
					LOBYTE(v19) = byte_587000[v24 + 309296] | v19;
					goto LABEL_100;
				case 2u:
					goto LABEL_118;
				case 3u:
					LOWORD(v27) = 16 * *v20;
					LOBYTE(v24) = 16 * *(_BYTE *)v20;
					v21 -= 10;
					LOBYTE(v19) = byte_587000[v24 + 309296] | v19;
					goto LABEL_92;
				case 4u:
					goto LABEL_120;
				case 5u:
					v29 = *((unsigned __int8 *)v20 + 2) << 16;
					LOWORD(v29) = *v20;
					v27 = v29 >> 4;
					LOBYTE(v24) = 16 * *v20;
					v21 -= 6;
					LOBYTE(v19) = byte_587000[v24 + 309296] | v19;
					goto LABEL_84;
				case 6u:
					goto LABEL_122;
				case 7u:
					v28 = 16 * *(_DWORD *)v20;
					LOBYTE(v24) = 16 * *(_BYTE *)v20;
					v21 -= 2;
					LOBYTE(v19) = byte_587000[v24 + 309296] | v19;
					goto LABEL_76;
				}
			}
			*(_DWORD *)a6 = v18;
			*(_WORD *)(a6 + 4) = v19;
			v31 = a2 + 1;
			v32 = (unsigned __int16 *)((char *)a1 + (a5 >> 3));
			v33 = *(_DWORD *)(a6 + 6);
			v34 = *(unsigned __int16 *)(a6 + 10);
			v35 = a5 >> 1;
			if ((int)(a5 >> 1) >= 16 && (unsigned __int8)v32 & 3)
			{
				switch ((unsigned __int8)v32 & 3)
				{
				case 0:
					break;
				case 1:
					v46 = v35 - 12;
					v37 = 0;
					v36 = ((v35 - 12) >> 4) + 1;
				LABEL_181:
					v43 = *((unsigned __int8 *)v32 + 2) << 16;
					LOWORD(v43) = *v32;
					LOBYTE(v37) = *v32;
					v40 = v43 >> 8;
					v32 = (unsigned __int16 *)((char *)v32 - 1);
					v31 -= 4;
					LOBYTE(v34) = byte_587000[v37 + 309040] | v34;
					goto LABEL_139;
				case 2:
					v46 = v35 - 8;
					v37 = 0;
					v36 = ((v35 - 8) >> 4) + 1;
				LABEL_179:
					LOWORD(v40) = *v32;
					LOBYTE(v37) = *v32;
					v31 -= 8;
					--v32;
					LOBYTE(v34) = byte_587000[v37 + 309040] | v34;
					goto LABEL_147;
				case 3:
					v46 = v35 - 4;
					v37 = 0;
					v36 = ((v35 - 4) >> 4) + 1;
				LABEL_177:
					LOBYTE(v37) = *(_BYTE *)v32;
					v31 -= 12;
					v32 = (unsigned __int16 *)((char *)v32 - 3);
					LOBYTE(v34) = byte_587000[v37 + 309040] | v34;
					goto LABEL_155;
				}
			}
			v46 = a5 >> 1;
			v36 = a5 >> 5;
			v37 = 0;
			v38 = a5 >> 5 == 0;
			for (j = (int)(a5 >> 5) <= 0; !j; j = v36-- <= 1)
			{
				v41 = *(_DWORD *)v32;
				LOBYTE(v37) = *(_DWORD *)v32;
				LOBYTE(v34) = byte_587000[v37 + 309040] | v34;
				v33 += *(_DWORD *)&byte_587000[2 * v34 + 300496];
				LOWORD(v34) = *(_WORD *)&byte_587000[v34 + 306192];
				if (v33 > 0x7FFF)
				{
					v33 = 0x7FFF;
				}
				else if (v33 < -32768)
				{
					v33 = -32768;
				}
				LOBYTE(v34) = byte_587000[v37 + 309296] | v34;
				*v31 = v33;
			LABEL_135:
				LOBYTE(v37) = BYTE1(v41);
				v33 += *(_DWORD *)&byte_587000[2 * v34 + 300496];
				LOWORD(v34) = *(_WORD *)&byte_587000[v34 + 306192];
				if (v33 > 0x7FFF)
				{
					v33 = 0x7FFF;
				}
				else if (v33 < -32768)
				{
					v33 = -32768;
				}
				LOBYTE(v34) = byte_587000[v37 + 309040] | v34;
				v31[2] = v33;
				v40 = v41 >> 16;
			LABEL_139:
				v33 += *(_DWORD *)&byte_587000[2 * v34 + 300496];
				LOWORD(v34) = *(_WORD *)&byte_587000[v34 + 306192];
				if (v33 > 0x7FFF)
				{
					v33 = 0x7FFF;
				}
				else if (v33 < -32768)
				{
					v33 = -32768;
				}
				LOBYTE(v34) = byte_587000[v37 + 309296] | v34;
				v31[4] = v33;
			LABEL_143:
				LOBYTE(v37) = v40;
				v33 += *(_DWORD *)&byte_587000[2 * v34 + 300496];
				LOWORD(v34) = *(_WORD *)&byte_587000[v34 + 306192];
				if (v33 > 0x7FFF)
				{
					v33 = 0x7FFF;
				}
				else if (v33 < -32768)
				{
					v33 = -32768;
				}
				LOBYTE(v34) = byte_587000[v37 + 309040] | v34;
				v31[6] = v33;
			LABEL_147:
				v33 += *(_DWORD *)&byte_587000[2 * v34 + 300496];
				LOWORD(v34) = *(_WORD *)&byte_587000[v34 + 306192];
				if (v33 > 0x7FFF)
				{
					v33 = 0x7FFF;
				}
				else if (v33 < -32768)
				{
					v33 = -32768;
				}
				LOBYTE(v34) = byte_587000[v37 + 309296] | v34;
				v31[8] = v33;
			LABEL_151:
				LOBYTE(v37) = BYTE1(v40);
				v33 += *(_DWORD *)&byte_587000[2 * v34 + 300496];
				LOWORD(v34) = *(_WORD *)&byte_587000[v34 + 306192];
				if (v33 > 0x7FFF)
				{
					v33 = 0x7FFF;
				}
				else if (v33 < -32768)
				{
					v33 = -32768;
				}
				LOBYTE(v34) = byte_587000[v37 + 309040] | v34;
				v31[10] = v33;
			LABEL_155:
				v33 += *(_DWORD *)&byte_587000[2 * v34 + 300496];
				LOWORD(v34) = *(_WORD *)&byte_587000[v34 + 306192];
				if (v33 > 0x7FFF)
				{
					v33 = 0x7FFF;
				}
				else if (v33 < -32768)
				{
					v33 = -32768;
				}
				LOBYTE(v34) = byte_587000[v37 + 309296] | v34;
				v31[12] = v33;
			LABEL_159:
				v33 += *(_DWORD *)&byte_587000[2 * v34 + 300496];
				LOWORD(v34) = *(_WORD *)&byte_587000[v34 + 306192];
				if (v33 > 0x7FFF)
				{
					v33 = 0x7FFF;
				}
				else if (v33 < -32768)
				{
					v33 = -32768;
				}
				v31[14] = v33;
				v32 += 2;
				v31 += 16;
				v38 = v36 == 1;
			}
			if (v38)
			{
				switch ((v46 >> 1) & 7)
				{
				case 0u:
					break;
				case 1u:
					LOBYTE(v37) = 16 * *(_BYTE *)v32;
					v31 -= 14;
					LOBYTE(v34) = byte_587000[v37 + 309296] | v34;
					goto LABEL_159;
				case 2u:
					goto LABEL_177;
				case 3u:
					LOWORD(v40) = 16 * *v32;
					LOBYTE(v37) = 16 * *(_BYTE *)v32;
					v31 -= 10;
					LOBYTE(v34) = byte_587000[v37 + 309296] | v34;
					goto LABEL_151;
				case 4u:
					goto LABEL_179;
				case 5u:
					v42 = *((unsigned __int8 *)v32 + 2) << 16;
					LOWORD(v42) = *v32;
					v40 = v42 >> 4;
					LOBYTE(v37) = 16 * *v32;
					v31 -= 6;
					LOBYTE(v34) = byte_587000[v37 + 309296] | v34;
					goto LABEL_143;
				case 6u:
					goto LABEL_181;
				case 7u:
					v41 = 16 * *(_DWORD *)v32;
					LOBYTE(v37) = 16 * *(_BYTE *)v32;
					v31 -= 2;
					LOBYTE(v34) = byte_587000[v37 + 309296] | v34;
					goto LABEL_135;
				}
			}
			*(_DWORD *)(a6 + 6) = v33;
			*(_WORD *)(a6 + 10) = v34;
		}
		else if (a4 == 1)
		{
			v6 = *(_DWORD *)a6;
			v7 = *(unsigned __int16 *)(a6 + 4);
			v8 = a1;
			v9 = a2;
			if ((int)a5 >= 16 && (unsigned __int8)a1 & 3)
			{
				switch ((unsigned __int8)a1 & 3)
				{
				case 0:
					break;
				case 1:
					v44 = a5 - 12;
					v11 = 0;
					v10 = ((a5 - 12) >> 4) + 1;
				LABEL_63:
					v17 = *((unsigned __int8 *)v8 + 2) << 16;
					LOWORD(v17) = *v8;
					LOBYTE(v11) = *v8;
					v14 = v17 >> 8;
					v8 = (unsigned __int16 *)((char *)v8 - 1);
					v9 -= 2;
					LOBYTE(v7) = byte_587000[v11 + 309040] | v7;
					goto LABEL_20;
				case 2:
					v44 = a5 - 8;
					v11 = 0;
					v10 = ((a5 - 8) >> 4) + 1;
				LABEL_61:
					LOWORD(v14) = *v8;
					LOBYTE(v11) = *v8;
					v9 -= 4;
					--v8;
					LOBYTE(v7) = byte_587000[v11 + 309040] | v7;
					goto LABEL_28;
				case 3:
					v44 = a5 - 4;
					v11 = 0;
					v10 = ((a5 - 4) >> 4) + 1;
				LABEL_59:
					LOBYTE(v11) = *(_BYTE *)v8;
					v9 -= 6;
					v8 = (unsigned __int16 *)((char *)v8 - 3);
					LOBYTE(v7) = byte_587000[v11 + 309040] | v7;
					goto LABEL_36;
				}
			}
			v44 = a5;
			v10 = a5 >> 4;
			v11 = 0;
			v12 = a5 >> 4 == 0;
			for (k = (int)(a5 >> 4) <= 0; !k; k = v10-- <= 1)
			{
				v15 = *(_DWORD *)v8;
				LOBYTE(v11) = *(_DWORD *)v8;
				LOBYTE(v7) = byte_587000[v11 + 309040] | v7;
				v6 += *(_DWORD *)&byte_587000[2 * v7 + 300496];
				LOWORD(v7) = *(_WORD *)&byte_587000[v7 + 306192];
				if (v6 > 0x7FFF)
				{
					v6 = 0x7FFF;
				}
				else if (v6 < -32768)
				{
					v6 = -32768;
				}
				LOBYTE(v7) = byte_587000[v11 + 309296] | v7;
				*v9 = v6;
			LABEL_16:
				LOBYTE(v11) = BYTE1(v15);
				v6 += *(_DWORD *)&byte_587000[2 * v7 + 300496];
				LOWORD(v7) = *(_WORD *)&byte_587000[v7 + 306192];
				if (v6 > 0x7FFF)
				{
					v6 = 0x7FFF;
				}
				else if (v6 < -32768)
				{
					v6 = -32768;
				}
				LOBYTE(v7) = byte_587000[v11 + 309040] | v7;
				v9[1] = v6;
				v14 = v15 >> 16;
			LABEL_20:
				v6 += *(_DWORD *)&byte_587000[2 * v7 + 300496];
				LOWORD(v7) = *(_WORD *)&byte_587000[v7 + 306192];
				if (v6 > 0x7FFF)
				{
					v6 = 0x7FFF;
				}
				else if (v6 < -32768)
				{
					v6 = -32768;
				}
				LOBYTE(v7) = byte_587000[v11 + 309296] | v7;
				v9[2] = v6;
			LABEL_24:
				LOBYTE(v11) = v14;
				v6 += *(_DWORD *)&byte_587000[2 * v7 + 300496];
				LOWORD(v7) = *(_WORD *)&byte_587000[v7 + 306192];
				if (v6 > 0x7FFF)
				{
					v6 = 0x7FFF;
				}
				else if (v6 < -32768)
				{
					v6 = -32768;
				}
				LOBYTE(v7) = byte_587000[v11 + 309040] | v7;
				v9[3] = v6;
			LABEL_28:
				v6 += *(_DWORD *)&byte_587000[2 * v7 + 300496];
				LOWORD(v7) = *(_WORD *)&byte_587000[v7 + 306192];
				if (v6 > 0x7FFF)
				{
					v6 = 0x7FFF;
				}
				else if (v6 < -32768)
				{
					v6 = -32768;
				}
				LOBYTE(v7) = byte_587000[v11 + 309296] | v7;
				v9[4] = v6;
			LABEL_32:
				LOBYTE(v11) = BYTE1(v14);
				v6 += *(_DWORD *)&byte_587000[2 * v7 + 300496];
				LOWORD(v7) = *(_WORD *)&byte_587000[v7 + 306192];
				if (v6 > 0x7FFF)
				{
					v6 = 0x7FFF;
				}
				else if (v6 < -32768)
				{
					v6 = -32768;
				}
				LOBYTE(v7) = byte_587000[v11 + 309040] | v7;
				v9[5] = v6;
			LABEL_36:
				v6 += *(_DWORD *)&byte_587000[2 * v7 + 300496];
				LOWORD(v7) = *(_WORD *)&byte_587000[v7 + 306192];
				if (v6 > 0x7FFF)
				{
					v6 = 0x7FFF;
				}
				else if (v6 < -32768)
				{
					v6 = -32768;
				}
				LOBYTE(v7) = byte_587000[v11 + 309296] | v7;
				v9[6] = v6;
			LABEL_40:
				v6 += *(_DWORD *)&byte_587000[2 * v7 + 300496];
				LOWORD(v7) = *(_WORD *)&byte_587000[v7 + 306192];
				if (v6 > 0x7FFF)
				{
					v6 = 0x7FFF;
				}
				else if (v6 < -32768)
				{
					v6 = -32768;
				}
				v9[7] = v6;
				v8 += 2;
				v9 += 8;
				v12 = v10 == 1;
			}
			if (v12)
			{
				switch ((v44 >> 1) & 7)
				{
				case 0u:
					break;
				case 1u:
					LOBYTE(v11) = 16 * *(_BYTE *)v8;
					v9 -= 7;
					LOBYTE(v7) = byte_587000[v11 + 309296] | v7;
					goto LABEL_40;
				case 2u:
					goto LABEL_59;
				case 3u:
					LOWORD(v14) = 16 * *v8;
					LOBYTE(v11) = 16 * *(_BYTE *)v8;
					v9 -= 5;
					LOBYTE(v7) = byte_587000[v11 + 309296] | v7;
					goto LABEL_32;
				case 4u:
					goto LABEL_61;
				case 5u:
					v16 = *((unsigned __int8 *)v8 + 2) << 16;
					LOWORD(v16) = *v8;
					v14 = v16 >> 4;
					LOBYTE(v11) = 16 * *v8;
					v9 -= 3;
					LOBYTE(v7) = byte_587000[v11 + 309296] | v7;
					goto LABEL_24;
				case 6u:
					goto LABEL_63;
				case 7u:
					v15 = 16 * *(_DWORD *)v8;
					LOBYTE(v11) = 16 * *(_BYTE *)v8;
					--v9;
					LOBYTE(v7) = byte_587000[v11 + 309296] | v7;
					goto LABEL_16;
				}
			}
			*(_DWORD *)a6 = v6;
			*(_WORD *)(a6 + 4) = v7;
		}
	}
}

//----- (00561430) --------------------------------------------------------
int __cdecl sub_561430(int a1)
{
	int result; // eax
	unsigned __int8 v2; // cl
	unsigned __int8 v3; // dl
	int v4; // eax
	unsigned __int8 v5[16]; // [esp+4h] [ebp-10h]

	if (!*(_DWORD *)(a1 + 1932))
		return -13;
	*(_DWORD *)(a1 + 1952) = 0;
	*(_DWORD *)(a1 + 1956) = -1;
	*(_DWORD *)(a1 + 1988) = 0;
	v2 = *(_BYTE *)(a1 + 62);
	v3 = *(_BYTE *)(a1 + 63);
	*(_WORD *)v5 = *(_WORD *)(a1 + 60);
	*(_DWORD *)(a1 + 56) = 0;
	v5[2] = v2;
	v5[3] = v3;
	*(_DWORD *)&v5[8] = sub_561760;
	*(_DWORD *)&v5[12] = sub_5618B0;
	result = (*(int(__cdecl **)(int, int, unsigned __int8 *, int))(a1 + 88))(a1, 2, v5, 16);
	if (result >= 0 || result == -1)
	{
		v4 = *(_DWORD *)(a1 + 1980);
		if (v4 >= 0)
			*(_DWORD *)(a1 + 1980) = v4 | 0x80000000;
		result = -1;
	}
	return result;
}

//----- (005614E0) --------------------------------------------------------
int __cdecl sub_5614E0(int a1)
{
	int result; // eax

	if (*(_BYTE *)(a1 + 1980) & 0x40)
		sub_561590(a1);
	(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 88))(a1, 3, 0, 0);
	result = *(_DWORD *)(a1 + 1980);
	if ((*(_DWORD *)(a1 + 1980) & 0x80000000) == 1)
	{
		result &= 0x7FFFFFFFu;
		*(_DWORD *)(a1 + 1980) = result;
	}
	return result;
}

//----- (00561530) --------------------------------------------------------
int __cdecl sub_561530(int a1)
{
	int result; // eax

	(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 88))(a1, 4, 0, 0);
	result = *(_DWORD *)(a1 + 1980);
	LOBYTE(result) = result | 0x40;
	*(_DWORD *)(a1 + 1980) = result;
	return result;
}

//----- (00561560) --------------------------------------------------------
char __cdecl sub_561560(int a1)
{
	int v1; // eax

	(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 88))(a1, 6, 0, 0);
	v1 = *(_DWORD *)(a1 + 1980);
	LOBYTE(v1) = v1 & 0xBF;
	*(_DWORD *)(a1 + 1980) = v1;
	return v1;
}

//----- (00561590) --------------------------------------------------------
char __cdecl sub_561590(int a1)
{
	int v1; // eax

	(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 88))(a1, 7, 0, 0);
	v1 = *(_DWORD *)(a1 + 1980);
	LOBYTE(v1) = v1 & 0xBF;
	*(_DWORD *)(a1 + 1980) = v1;
	return v1;
}

//----- (005615C0) --------------------------------------------------------
int __cdecl sub_5615C0(int a1)
{
	int v1; // ebx
	int v2; // ebp
	int v3; // eax
	int v4; // edi
	unsigned int v5; // ecx
	const void *v6; // esi
	unsigned int v7; // ebp
	unsigned int v8; // eax
	unsigned int v9; // ecx
	int v11; // esi
	unsigned int v12; // ecx
	unsigned int v13; // edx
	unsigned int v14; // ecx
	unsigned int v15; // esi
	unsigned int i; // ecx
	int v17; // [esp+14h] [ebp-4h]
	unsigned int v18; // [esp+1Ch] [ebp+4h]

	v1 = a1;
	if (!(*(_BYTE *)(a1 + 132) & 1))
		return -1;
	if (!*(_DWORD *)(a1 + 1932))
		return -1;
	v2 = *(_DWORD *)(a1 + 1968);
	if (!v2)
		return -1;
	v3 = *(_DWORD *)(a1 + 1964);
	v4 = *(_DWORD *)(a1 + 1936);
	v5 = *(_DWORD *)(a1 + 156);
	v6 = (const void *)(v3 + *(_DWORD *)(a1 + 1960));
	v7 = v2 - v3;
	v17 = v3 + *(_DWORD *)(a1 + 1960);
	v18 = *(_DWORD *)(a1 + 1936) / v5;
	v8 = (v4 + v7) / v5;
	v9 = *(_DWORD *)(v1 + 1948);
	if (v8 >= v9)
		v8 -= v9;
	if (*(_BYTE *)(*(_DWORD *)(v1 + 1940) + v8) == 1)
	{
		++*(_DWORD *)(v1 + 396);
		return -11;
	}
	if (v18 > v8)
	{
		v13 = *(_DWORD *)(v1 + 152) - v4;
		qmemcpy((void *)(*(_DWORD *)(v1 + 1932) + v4), v6, v13);
		qmemcpy(*(void **)(v1 + 1932), (const void *)(v13 + v17), v7 - v13);
		v14 = v18;
		v15 = *(_DWORD *)(v1 + 1948);
		*(_DWORD *)(v1 + 1936) = v7 - v13;
		*(_DWORD *)(v1 + 1968) = 0;
		*(_DWORD *)(v1 + 1964) = 0;
		if (v18 < v15)
		{
			do
				*(_BYTE *)(*(_DWORD *)(v1 + 1940) + ++v14 - 1) = 1;
			while (v14 < *(int *)(v1 + 1948));
		}
		for (i = 0; i < v8; *(_BYTE *)(*(_DWORD *)(v1 + 1940) + i - 1) = 1)
			++i;
		return -1;
	}
	qmemcpy((void *)(*(_DWORD *)(v1 + 1932) + v4), v6, v7);
	v11 = *(_DWORD *)(v1 + 1936);
	*(_DWORD *)(v1 + 1968) = 0;
	*(_DWORD *)(v1 + 1964) = 0;
	v12 = v18;
	*(_DWORD *)(v1 + 1936) = v7 + v11;
	if (v18 >= v8)
		return -1;
	do
		*(_BYTE *)(*(_DWORD *)(v1 + 1940) + ++v12 - 1) = 1;
	while (v12 < v8);
	return -1;
}

//----- (00561760) --------------------------------------------------------
int __cdecl sub_561760(int a1)
{
	int v1; // ebx
	int v2; // edi
	int v4; // edx
	int v5; // ecx
	int v6; // esi
	int v7; // edx
	char v8; // bl
	int v9; // ecx
	int v10; // edx
	int v11; // edx
	unsigned int v12; // ecx
	int v13; // ecx

	v1 = *(_DWORD *)(a1 + 1980);
	v2 = *(_DWORD *)(a1 + 156);
	if (v1 & 0x200)
		return 0;
	v4 = *(_DWORD *)(a1 + 132);
	v5 = *(_DWORD *)(a1 + 1952);
	v6 = *(_DWORD *)(a1 + 1988);
	if (v4 & 0x200)
	{
		v7 = v5 + 1;
		if ((unsigned int)(v5 + 1) >= *(int *)(a1 + 1948))
			v7 = 0;
		if (!(v1 & 0x100) && !*(_BYTE *)(v7 + *(_DWORD *)(a1 + 1940)))
		{
			BYTE1(v1) |= 4u;
			*(_DWORD *)(a1 + 1980) = v1;
		}
	}
	v8 = 0;
	if (*(_BYTE *)(*(_DWORD *)(a1 + 1940) + v5) == 1)
	{
		if (*(int *)(a1 + 1956) == -1)
		{
			*(_DWORD *)(a1 + 1956) = v5;
			*(_DWORD *)(a1 + 1984) = v6;
		}
		v9 = v5 + 1;
		*(_WORD *)(*(_DWORD *)(a1 + 1944) + 2 * v9 - 2) = 0;
		v10 = v6 + v2;
		if (v6 + v2 >= *(int *)(a1 + 152))
		{
			v10 = 0;
			v9 = 0;
		}
		*(_DWORD *)(a1 + 1988) = v10;
		*(_DWORD *)(a1 + 1952) = v9;
	}
	else
	{
		v11 = *(_DWORD *)(a1 + 1980);
		if (v11 & 0x100)
		{
			v12 = *(_DWORD *)(a1 + 1936);
			BYTE1(v11) |= 2u;
			*(_DWORD *)(a1 + 1980) = v11;
			if (v6 >= v12)
				return 0;
			v2 = v12 - v6;
		}
		else
		{
			LOBYTE(v11) = v11 | 0x80;
			v6 -= v2;
			*(_DWORD *)(a1 + 1980) = v11;
			v13 = v5 - 1;
			v8 = 1;
			++*(_DWORD *)(a1 + 56);
			if (v6 < 0)
			{
				v6 = *(_DWORD *)(a1 + 152) - v2;
				v13 = *(_DWORD *)(a1 + 1948) - 1;
			}
			++*(_WORD *)(*(_DWORD *)(a1 + 1944) + 2 * v13);
		}
	}
	if (v2 > 0)
	{
		if (v8 == 1)
		{
			(*(void(__cdecl **)(int, int, _DWORD, int))(a1 + 88))(a1, 5, *(_DWORD *)(a1 + 1976), v2);
			return v2;
		}
		(*(void(__cdecl **)(int, int, int, int))(a1 + 88))(a1, 5, v6 + *(_DWORD *)(a1 + 1932), v2);
	}
	return v2;
}

//----- (005618B0) --------------------------------------------------------
int __cdecl sub_5618B0(_DWORD *a1, int a2)
{
	int result; // eax
	int v3; // ecx
	int v4; // edx
	__int16 v5; // si
	_WORD *v6; // edx
	unsigned int v7; // ecx
	unsigned int v8; // ebx

	if (a2 != a1[483] + a1[496] && a2 != a1[494])
		return -19;
	v3 = a1[489];
	if (v3 == -1)
		return -20;
	v4 = a1[486];
	v5 = *(_WORD *)(v4 + 2 * v3);
	v6 = (_WORD *)(v4 + 2 * v3);
	if (v5)
	{
		result = -1;
		*v6 = v5 - 1;
	}
	else
	{
		v7 = v3 + 1;
		*(_BYTE *)(a1[485] + v7 - 1) = 0;
		if (v7 >= a1[487])
			v7 = 0;
		if (*(_BYTE *)(a1[485] + v7) == 1)
		{
			v8 = a1[39] + a1[496];
			a1[496] = v8;
			if (v8 >= a1[38])
				a1[496] = 0;
			a1[489] = v7;
			result = -1;
		}
		else
		{
			a1[489] = -1;
			result = -1;
		}
	}
	return result;
}

//----- (00561980) --------------------------------------------------------
int __cdecl sub_561980(int a1)
{
	int v1; // esi
	_DWORD *v2; // ebx
	int v4; // eax
	char v5; // cl
	unsigned int v6; // eax
	unsigned int v7; // ecx
	int v8; // ecx
	int v9; // eax
	int v10; // edi
	int v11; // eax
	int v12; // eax
	int v13; // eax
	int v14; // eax
	_DWORD *v15; // ebp
	int v16; // eax
	int v17; // ebx
	_DWORD *v18; // ebx
	unsigned int v19; // ecx
	unsigned int v20; // eax
	int v21; // eax
	int v22; // eax
	_DWORD *v23; // ebp
	int v24; // edx
	int v25; // eax
	int v26; // edi
	int v27; // edx
	__int16 v28; // ax
	int v29; // ecx
	unsigned __int8 v30; // cl
	int v31; // edx
	int v32; // ecx
	int v33; // eax
	int v34; // eax
	int v35; // eax
	int v36; // eax
	unsigned int v37; // eax
	int v38; // eax
	int v39; // eax
	int v40; // eax
	int v41; // [esp-4h] [ebp-1Ch]
	int v42; // [esp-4h] [ebp-1Ch]
	int v43; // [esp+10h] [ebp-8h]
	int v44; // [esp+14h] [ebp-4h]
	int v45; // [esp+1Ch] [ebp+4h]
	int v46; // [esp+1Ch] [ebp+4h]

	v1 = a1;
	v2 = 0;
	if (!*(_DWORD *)(a1 + 136))
		return -8;
	v4 = *(unsigned __int8 *)(a1 + 243) * *(unsigned __int8 *)(a1 + 242) * *(unsigned __int16 *)(a1 + 248) + 4;
	LOBYTE(v4) = v4 & 0xFC;
	*(_DWORD *)(a1 + 1908) = v4;
	v5 = *(_BYTE *)(a1 + 264);
	if (v5 == 1 || v5 == 4)
		*(_DWORD *)(a1 + 1908) = 2 * v4;
	v6 = *(_DWORD *)(a1 + 266);
	v7 = *(_DWORD *)(a1 + 1908);
	if (v6 > v7)
		return -3;
	if (!v6)
		*(_DWORD *)(a1 + 266) = v7;
	if (*(int *)(a1 + 140) <= 0)
	{
		if (*(_WORD *)(a1 + 1868) <= 0u)
			v8 = *(unsigned __int8 *)(a1 + 245);
		else
			v8 = *(unsigned __int16 *)(a1 + 1870);
		if (v8 == *(_DWORD *)(a1 + 16))
		{
			*(_DWORD *)(a1 + 140) = 1;
		}
		else
		{
			v9 = *(_DWORD *)(a1 + 136);
			v10 = 0;
			if (v9 > 1)
			{
				v10 = (v9 - 2) / v8 + 1;
				if (*(_BYTE *)(a1 + 132) & 0x20)
				{
					if (*(_WORD *)(a1 + 1812))
					{
						sub_5627E0(a1, &v43, &v44);
						if (v43)
							++v10;
						if (v44)
							++v10;
					}
					else
					{
						v10 = (v9 - 2) / v8 + 3;
					}
				}
			}
			*(_DWORD *)(a1 + 140) = v10 + 2;
		}
	}
	v11 = *(_DWORD *)(a1 + 340);
	LOBYTE(v11) = v11 | 1;
	v41 = *(_DWORD *)(a1 + 1908);
	*(_DWORD *)(a1 + 340) = v11;
	v12 = *(_DWORD *)(a1 + 266) + 16;
	LOBYTE(v12) = v12 & 0xFC;
	*(_DWORD *)(a1 + 1896) = v12;
	v13 = (*(int(__cdecl **)(int, int, _DWORD, int))(a1 + 68))(a1, 2, 0, v41);
	*(_DWORD *)(a1 + 1776) = v13;
	if (!v13)
	{
		sub_562120(a1);
		return -8;
	}
	(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 4, v13, *(_DWORD *)(a1 + 1908));
	*(_DWORD *)(a1 + 48) += *(_DWORD *)(a1 + 1908);
	v45 = 0;
	if (*(_DWORD *)(v1 + 140) > 0)
	{
		while (1)
		{
			v14 = (*(int(__cdecl **)(int, int, _DWORD, int))(v1 + 68))(v1, 2, 0, *(_DWORD *)(v1 + 1896) + 24);
			v15 = (_DWORD *)v14;
			if (!v14)
				goto LABEL_75;
			(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 4, v14, *(_DWORD *)(v1 + 1896) + 24);
			*(_DWORD *)(v1 + 48) += *(_DWORD *)(v1 + 1896) + 24;
			memset(v15, 0, 0x18u);
			*v15 = v15 + 6;
			if (v2)
			{
				v2[1] = v15;
				v15[2] = v2;
			}
			else
			{
				*(_DWORD *)(v1 + 1772) = v15;
			}
			v2 = v15;
			if (++v45 >= *(int *)(v1 + 140))
			{
				if (v15)
				{
					v15[1] = *(_DWORD *)(v1 + 1772);
					*(_DWORD *)(*(_DWORD *)(v1 + 1772) + 8) = v15;
				}
				break;
			}
		}
	}
	v16 = *(_DWORD *)(v1 + 1772);
	v17 = *(_DWORD *)(v1 + 1896);
	*(_DWORD *)(v1 + 356) = v16;
	*(_DWORD *)(v1 + 360) = v16;
	*(_DWORD *)(v1 + 1896) = v17 - 4;
	*(_DWORD *)(v1 + 1904) = 1020;
	v18 = 0;
	v19 = (2
		* *(unsigned __int16 *)(v1 + 240)
		/ (int)*(unsigned __int8 *)(v1 + 243)
		* (*(unsigned __int16 *)(v1 + 238)
			/ (int)*(unsigned __int8 *)(v1 + 242))
		+ 4) & 0xFFFFFFFC;
	*(_DWORD *)(v1 + 1912) = v19;
	if (*(_WORD *)(v1 + 254))
	{
		v20 = *(unsigned __int16 *)(v1 + 254);
		if (*(_WORD *)(v1 + 232) > 2u)
			v20 <<= 8;
	}
	else
	{
		v20 = v19;
	}
	v21 = v20 + 8;
	v42 = *(_DWORD *)(v1 + 1912);
	LOBYTE(v21) = v21 & 0xFC;
	*(_DWORD *)(v1 + 340) |= 2u;
	*(_DWORD *)(v1 + 1900) = v21;
	v22 = (*(int(__cdecl **)(int, int, _DWORD, int))(v1 + 68))(v1, 2, 0, v42);
	*(_DWORD *)(v1 + 1768) = v22;
	if (!v22)
	{
		sub_562120(v1);
		return -8;
	}
	(*(void(__cdecl **)(int, int, int, _DWORD))(v1 + 68))(v1, 4, v22, *(_DWORD *)(v1 + 1912));
	*(_DWORD *)(v1 + 48) += *(_DWORD *)(v1 + 1912);
	v46 = 0;
	if (*(_DWORD *)(v1 + 136) > 0)
	{
		while (1)
		{
			v23 = (_DWORD *)(*(int(__cdecl **)(int, int, _DWORD, int))(v1 + 68))(
				v1,
				2,
				0,
				*(_DWORD *)(v1 + 1904) + *(_DWORD *)(v1 + 1900) + 44);
			if (!v23)
				goto LABEL_75;
			(*(void(__cdecl **)(int, int, _DWORD *, int))(v1 + 68))(
				v1,
				4,
				v23,
				*(_DWORD *)(v1 + 1904) + *(_DWORD *)(v1 + 1900) + 44);
			*(_DWORD *)(v1 + 48) += *(_DWORD *)(v1 + 1904) + *(_DWORD *)(v1 + 1900) + 44;
			memset(v23, 0, 0x2Cu);
			*v23 = v23 + 11;
			v24 = (int)v23 + *(_DWORD *)(v1 + 1900) + 44;
			v23[1] = 0;
			v23[2] = v24;
			if (v18)
			{
				v18[3] = v23;
				v23[4] = v18;
			}
			else
			{
				*(_DWORD *)(v1 + 1764) = v23;
			}
			v18 = v23;
			if (++v46 >= *(int *)(v1 + 136))
			{
				v23[3] = *(_DWORD *)(v1 + 1764);
				*(_DWORD *)(*(_DWORD *)(v1 + 1764) + 16) = v23;
				break;
			}
		}
	}
	v25 = *(_DWORD *)(v1 + 1764);
	v26 = *(_DWORD *)(v1 + 1904);
	v27 = *(_DWORD *)(v1 + 1900);
	*(_DWORD *)(v1 + 368) = v25;
	*(_DWORD *)(v1 + 416) = v25;
	*(_DWORD *)(v1 + 1756) = v25;
	*(_DWORD *)(v1 + 1904) = v26 - 4;
	*(_DWORD *)(v1 + 1900) = v27 - 4;
	v28 = *(_WORD *)(v1 + 234);
	if (v28 & 1)
	{
		v29 = *(_DWORD *)(v1 + 132);
		if (v29 & 1)
		{
			if (*(_WORD *)(v1 + 232) >= 2u)
			{
				if (v29 & 0x40 && v28 & 2)
				{
					*(_WORD *)(v1 + 60) = *(_WORD *)(v1 + 260);
					*(_BYTE *)(v1 + 62) = *(_BYTE *)(v1 + 262);
					v30 = *(_BYTE *)(v1 + 263);
				}
				else
				{
					*(_WORD *)(v1 + 60) = *(_WORD *)(v1 + 256);
					*(_BYTE *)(v1 + 62) = *(_BYTE *)(v1 + 258);
					v30 = *(_BYTE *)(v1 + 259);
				}
				v31 = *(unsigned __int16 *)(v1 + 60) * (v30 >> 3);
				*(_BYTE *)(v1 + 63) = v30;
				*(_DWORD *)(v1 + 1996) = *(unsigned __int8 *)(v1 + 62) * v31;
			}
			else
			{
				*(_BYTE *)(v1 + 62) = 1;
				*(_WORD *)(v1 + 60) = 22050;
				*(_BYTE *)(v1 + 63) = 8;
				*(_DWORD *)(v1 + 1996) = 22050;
			}
			if (*(int *)(v1 + 152) == -1)
				*(_DWORD *)(v1 + 152) = *(_DWORD *)(v1 + 156)
				* ((unsigned int)(*(_DWORD *)(v1 + 1996) + (*(_DWORD *)(v1 + 1996) >> 1))
					/ *(_DWORD *)(v1 + 156));
			if (*(int *)(v1 + 152) <= 0)
			{
				sub_562120(v1);
				return -18;
			}
			v32 = *(_DWORD *)(v1 + 148);
			if (v32)
			{
				*(_DWORD *)(v1 + 1932) = v32;
			}
			else
			{
				v33 = (*(int(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 68))(v1, 2, 0, *(_DWORD *)(v1 + 152));
				*(_DWORD *)(v1 + 1932) = v33;
				if (!v33)
				{
					sub_562120(v1);
					return -8;
				}
				(*(void(__cdecl **)(int, int, int, _DWORD))(v1 + 68))(v1, 4, v33, *(_DWORD *)(v1 + 152));
				*(_DWORD *)(v1 + 48) += *(_DWORD *)(v1 + 152);
			}
			v34 = *(_DWORD *)(v1 + 152) / *(_DWORD *)(v1 + 156);
			*(_DWORD *)(v1 + 1948) = v34;
			v35 = (*(int(__cdecl **)(int, int, _DWORD, int))(v1 + 68))(v1, 2, 0, v34);
			*(_DWORD *)(v1 + 1940) = v35;
			if (!v35)
			{
				sub_562120(v1);
				return -8;
			}
			(*(void(__cdecl **)(int, int, int, _DWORD))(v1 + 68))(v1, 4, v35, *(_DWORD *)(v1 + 1948));
			*(_DWORD *)(v1 + 48) += *(_DWORD *)(v1 + 1948);
			memset(*(void **)(v1 + 1940), 0, *(_DWORD *)(v1 + 1948));
			v36 = (*(int(__cdecl **)(int, int, _DWORD, int))(v1 + 68))(v1, 2, 0, 2 * *(_DWORD *)(v1 + 1948));
			*(_DWORD *)(v1 + 1944) = v36;
			if (!v36)
			{
				sub_562120(v1);
				return -8;
			}
			(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 4, v36, 2 * *(_DWORD *)(v1 + 1948));
			*(_DWORD *)(v1 + 48) += 2 * *(_DWORD *)(v1 + 1948);
			memset(*(void **)(v1 + 1944), 0, 2 * *(_DWORD *)(v1 + 1948));
			v37 = 2 * (*(_DWORD *)(v1 + 1996) / (unsigned int)*(unsigned __int8 *)(v1 + 244)) + 100;
			*(_DWORD *)(v1 + 1972) = v37;
			v38 = (*(int(__cdecl **)(int, int, _DWORD, unsigned int))(v1 + 68))(v1, 2, 0, v37);
			*(_DWORD *)(v1 + 1960) = v38;
			if (!v38)
			{
				sub_562120(v1);
				return -8;
			}
			(*(void(__cdecl **)(int, int, int, _DWORD))(v1 + 68))(v1, 4, v38, *(_DWORD *)(v1 + 1972));
			*(_DWORD *)(v1 + 48) += *(_DWORD *)(v1 + 1972);
			v39 = (*(int(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 68))(v1, 2, 0, *(_DWORD *)(v1 + 156));
			*(_DWORD *)(v1 + 1976) = v39;
			if (!v39)
			{
				sub_562120(v1);
				return -8;
			}
			(*(void(__cdecl **)(int, int, int, _DWORD))(v1 + 68))(v1, 4, v39, *(_DWORD *)(v1 + 156));
			memset(*(void **)(v1 + 1976), 0, *(_DWORD *)(v1 + 156));
			*(_DWORD *)(v1 + 48) += *(_DWORD *)(v1 + 156);
		}
	}
	v40 = (*(int(__cdecl **)(int, int, _DWORD, int))(v1 + 68))(v1, 2, 0, 4 * *(unsigned __int16 *)(v1 + 236));
	*(_DWORD *)(v1 + 1892) = v40;
	if (!v40)
	{
	LABEL_75:
		sub_562120(v1);
		return -8;
	}
	(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 4, v40, 4 * *(unsigned __int16 *)(v1 + 236));
	*(_DWORD *)(v1 + 48) += 4 * *(unsigned __int16 *)(v1 + 236);
	return -1;
}

//----- (00562120) --------------------------------------------------------
int __cdecl sub_562120(int a1)
{
	int v1; // esi
	int v2; // eax
	int v3; // eax
	int v4; // eax
	int v5; // eax
	int v6; // eax
	int v7; // eax
	int v8; // eax
	int v9; // ebx
	int i; // edi
	int v11; // ebp
	int v12; // edx
	int v13; // eax
	int v14; // eax
	int v15; // edi
	int j; // ebx
	int v17; // ebp
	int v18; // edx
	int v19; // eax
	int v20; // eax
	int v21; // ecx
	int v22; // edi
	int v23; // eax
	int *v24; // eax
	int *v25; // ebp
	int v26; // ebx
	int v27; // edi
	bool v28; // zf
	int v29; // eax
	int v30; // eax
	int v31; // edi
	int v32; // eax
	int *v33; // eax
	int *v34; // ebp
	int v35; // ebx
	int v36; // edi
	int v37; // eax
	int v38; // eax
	int v39; // ecx
	int result; // eax
	int v41; // [esp+4h] [ebp-Ch]
	int v42; // [esp+4h] [ebp-Ch]
	int v43; // [esp+8h] [ebp-8h]
	int v44; // [esp+8h] [ebp-8h]
	int v45; // [esp+Ch] [ebp-4h]
	int v46; // [esp+Ch] [ebp-4h]
	int v47; // [esp+14h] [ebp+4h]
	int v48; // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD *)(a1 + 1780);
	if (v2)
	{
		(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 5, v2, *(_DWORD *)(a1 + 1784));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1780), 0);
	}
	v3 = *(_DWORD *)(a1 + 1892);
	if (v3)
	{
		(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 5, v3, 4 * *(unsigned __int16 *)(a1 + 236));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1892), 0);
	}
	if (!*(_DWORD *)(a1 + 148))
	{
		v4 = *(_DWORD *)(a1 + 1932);
		if (v4)
		{
			(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 5, v4, *(_DWORD *)(a1 + 152));
			(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1932), 0);
		}
	}
	v5 = *(_DWORD *)(a1 + 1940);
	if (v5)
	{
		(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 5, v5, *(_DWORD *)(a1 + 1948));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1940), 0);
	}
	v6 = *(_DWORD *)(a1 + 1944);
	if (v6)
	{
		(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 5, v6, 2 * *(_DWORD *)(a1 + 1948));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1944), 0);
	}
	v7 = *(_DWORD *)(a1 + 1960);
	if (v7)
	{
		(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 5, v7, *(_DWORD *)(a1 + 1972));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1960), 0);
	}
	v8 = *(_DWORD *)(a1 + 1976);
	if (v8)
	{
		(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 5, v8, *(_DWORD *)(a1 + 156));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1976), 0);
	}
	v9 = 0;
	for (i = *(_DWORD *)(a1 + 1764); v9 < *(int *)(a1 + 136); i = v11)
	{
		if (!i)
			break;
		v11 = *(_DWORD *)(i + 12);
		v12 = *(_DWORD *)(a1 + 1900) + 4;
		v13 = *(_DWORD *)(a1 + 1904) + 4;
		*(_DWORD *)(a1 + 1904) = v13;
		*(_DWORD *)(a1 + 1900) = v12;
		(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 5, i, v12 + v13 + 44);
		(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 3, i, 0);
		++v9;
	}
	if (*(_BYTE *)(a1 + 340) & 2)
	{
		v14 = *(_DWORD *)(a1 + 1768);
		if (v14)
		{
			(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 5, v14, *(_DWORD *)(a1 + 1912));
			(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1768), 0);
			*(_DWORD *)(a1 + 1768) = 0;
		}
	}
	v15 = *(_DWORD *)(a1 + 1772);
	for (j = 0; j < *(int *)(a1 + 140); v15 = v17)
	{
		if (!v15)
			break;
		v17 = *(_DWORD *)(v15 + 4);
		v18 = *(_DWORD *)(a1 + 1896) + 4;
		*(_DWORD *)(a1 + 1896) = v18;
		(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 5, v15, v18 + 24);
		(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 3, v15, 0);
		++j;
	}
	if (*(_BYTE *)(a1 + 340) & 1)
	{
		v19 = *(_DWORD *)(a1 + 1776);
		if (v19)
		{
			(*(void(__cdecl **)(int, int, int, _DWORD))(a1 + 68))(a1, 5, v19, *(_DWORD *)(a1 + 1908));
			(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1776), 0);
			*(_DWORD *)(a1 + 1776) = 0;
		}
	}
	v20 = *(_DWORD *)(a1 + 1888);
	if (v20)
	{
		(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 5, v20, 2 * *(unsigned __int16 *)(a1 + 1880));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1888), 0);
	}
	v21 = *(_DWORD *)(a1 + 1876);
	if (v21)
	{
		(*(void(__cdecl **)(int, int, int, int))(a1 + 68))(a1, 5, v21, 6 * *(unsigned __int16 *)(a1 + 1868));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(a1 + 68))(a1, 3, *(_DWORD *)(a1 + 1876), 0);
	}
	v22 = *(_DWORD *)(a1 + 1852);
	v45 = *(_DWORD *)(a1 + 1852);
	if (v22)
	{
		v23 = 0;
		v47 = 0;
		v41 = 0;
		v43 = *(_DWORD *)(v1 + 1852);
		do
		{
			v24 = (int *)(*(_DWORD *)(v1 + 1864) + v23);
			v25 = (int *)v24[2];
			v26 = *v24;
			v27 = *v25;
			if (*v25)
			{
				(*(void(__cdecl **)(int, int, int, unsigned int))(v1 + 68))(
					v1,
					5,
					v27,
					v26 * ((*(_DWORD *)(*(_DWORD *)(v1 + 1860) + v47 + 4) + 1) & 0xFFFFFFFE));
				(*(void(__cdecl **)(int, int, int, _DWORD))(v1 + 68))(v1, 3, v27, 0);
			}
			if (v25)
			{
				(*(void(__cdecl **)(int, int, int *, int))(v1 + 68))(v1, 5, v25, 12 * v26);
				(*(void(__cdecl **)(int, int, int *, _DWORD))(v1 + 68))(v1, 3, v25, 0);
			}
			v23 = v41 + 12;
			v28 = v43 == 1;
			v41 += 12;
			v47 += 16;
			--v43;
		} while (!v28);
		v22 = v45;
	}
	v29 = *(_DWORD *)(v1 + 1864);
	if (v29)
	{
		(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 5, v29, 12 * v22);
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 68))(v1, 3, *(_DWORD *)(v1 + 1864), 0);
	}
	v30 = *(_DWORD *)(v1 + 1860);
	if (v30)
	{
		(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 5, v30, 16 * v22);
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 68))(v1, 3, *(_DWORD *)(v1 + 1860), 0);
	}
	v31 = *(_DWORD *)(v1 + 1828);
	v46 = *(_DWORD *)(v1 + 1828);
	if (v31)
	{
		v32 = 0;
		v48 = 0;
		v44 = 0;
		v42 = *(_DWORD *)(v1 + 1828);
		do
		{
			v33 = (int *)(*(_DWORD *)(v1 + 1848) + v32);
			v34 = (int *)v33[2];
			v35 = *v33;
			v36 = *v34;
			if (*v34)
			{
				(*(void(__cdecl **)(int, int, int, unsigned int))(v1 + 68))(
					v1,
					5,
					v36,
					v35 * ((*(_DWORD *)(*(_DWORD *)(v1 + 1844) + v48 + 8) + 1) & 0xFFFFFFFE));
				(*(void(__cdecl **)(int, int, int, _DWORD))(v1 + 68))(v1, 3, v36, 0);
			}
			if (v34)
			{
				(*(void(__cdecl **)(int, int, int *, int))(v1 + 68))(v1, 5, v34, 12 * v35);
				(*(void(__cdecl **)(int, int, int *, _DWORD))(v1 + 68))(v1, 3, v34, 0);
			}
			v32 = v44 + 12;
			v28 = v42 == 1;
			v44 += 12;
			v48 += 16;
			--v42;
		} while (!v28);
		v31 = v46;
	}
	v37 = *(_DWORD *)(v1 + 1848);
	if (v37)
	{
		(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 5, v37, 12 * v31);
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 68))(v1, 3, *(_DWORD *)(v1 + 1848), 0);
	}
	v38 = *(_DWORD *)(v1 + 1844);
	if (v38)
	{
		(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 5, v38, 16 * v31);
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 68))(v1, 3, *(_DWORD *)(v1 + 1844), 0);
	}
	v39 = *(_DWORD *)(v1 + 1840);
	if (v39)
	{
		(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 5, v39, 24 * *(_DWORD *)(v1 + 1824));
		(*(void(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 68))(v1, 3, *(_DWORD *)(v1 + 1840), 0);
	}
	result = *(_DWORD *)(v1 + 1820);
	if (result)
	{
		(*(void(__cdecl **)(int, int, int, int))(v1 + 68))(v1, 5, result, 4 * *(unsigned __int16 *)(v1 + 1812));
		result = (*(int(__cdecl **)(int, int, _DWORD, _DWORD))(v1 + 68))(v1, 3, *(_DWORD *)(v1 + 1820), 0);
	}
	return result;
}

//----- (00562640) --------------------------------------------------------
int __cdecl sub_562640(int a1)
{
	int v1; // esi
	unsigned int v2; // ebp
	int v3; // eax
	void *v4; // ebx
	char v5; // al
	unsigned int v6; // edi
	int v7; // eax
	int v9; // eax
	int v10; // eax
	unsigned int v11; // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD *)(a1 + 96);
	if (v2 == -1 || (v3 = *(_DWORD *)(a1 + 100), v3 == -1))
	{
		v2 = *(unsigned __int16 *)(a1 + 238);
		v11 = *(unsigned __int16 *)(a1 + 240);
		if (!(*(_BYTE *)(v1 + 128) & 8))
			goto LABEL_6;
		v2 += *(unsigned __int16 *)(v1 + 250);
		v3 = *(unsigned __int16 *)(v1 + 252) + v11;
	}
	v11 = v3;
LABEL_6:
	v4 = *(void **)(v1 + 92);
	if (*(_BYTE *)(v1 + 128) & 1)
	{
		if (!v4)
		{
			v5 = *(_BYTE *)(v1 + 264);
			v6 = v2 * v11;
			if (v5 == 1 || v5 == 4)
				v6 *= 2;
			v7 = (*(int(__cdecl **)(int, int, _DWORD, unsigned int))(v1 + 68))(v1, 2, 0, v6);
			v4 = (void *)v7;
			if (!v7)
				return -8;
			*(_DWORD *)(v1 + 48) += v6;
			(*(void(__cdecl **)(int, int, int, unsigned int))(v1 + 68))(v1, 4, v7, v6);
			memset(v4, 0, v6);
			*(_DWORD *)(v1 + 344) = v4;
			*(_DWORD *)(v1 + 352) = v11;
			v9 = *(_DWORD *)(v1 + 336);
			LOBYTE(v9) = v9 | 0x20;
			*(_DWORD *)(v1 + 348) = v2;
			*(_DWORD *)(v1 + 336) = v9;
		}
		goto LABEL_15;
	}
	if (v4)
	{
	LABEL_15:
		sub_55B470(v1, (int)v4, v2, v11, 0, *(_DWORD *)(v1 + 104), *(_DWORD *)(v1 + 108));
		v10 = *(_DWORD *)(v1 + 336);
		LOBYTE(v10) = v10 | 0x10;
		*(_DWORD *)(v1 + 336) = v10;
		return -1;
	}
	return -9;
}

//----- (00562770) --------------------------------------------------------
void *__cdecl sub_562770(int a1, int a2, LPVOID lpMem, int a4)
{
	void *result; // eax

	switch (a2)
	{
	case 2:
		result = malloc(a4);
		break;
	case 3:
		free(lpMem);
		result = 0;
		break;
	case 4:
	case 5:
		result = lpMem;
		break;
	case 6:
		*(_DWORD *)lpMem = -1;
		goto LABEL_6;
	default:
	LABEL_6:
		result = 0;
		break;
	}
	return result;
}

//----- (005627E0) --------------------------------------------------------
__int16 __cdecl sub_5627E0(int a1, _DWORD *a2, _DWORD *a3)
{
	int v3; // ecx
	int v4; // ebx
	unsigned __int16 *v5; // esi
	int v6; // ebp
	_DWORD *v7; // edi
	int v8; // eax
	int v9; // ecx
	int v10; // ecx
	unsigned __int16 *i; // esi
	_WORD *v12; // ebx
	_WORD *v13; // ecx
	int v14; // esi
	_WORD *v15; // edx
	int v16; // esi
	_WORD *v17; // edx
	unsigned __int16 *v19; // [esp+14h] [ebp+4h]
	int v20; // [esp+14h] [ebp+4h]

	v3 = a1;
	v4 = *(unsigned __int8 *)(a1 + 245);
	v5 = *(unsigned __int16 **)(a1 + 1820);
	v6 = *(unsigned __int16 *)(a1 + 1812);
	v7 = a2;
	v19 = *(unsigned __int16 **)(a1 + 1820);
	if (v4 <= 0)
	{
		*a2 = 1;
		HIWORD(v8) = 0;
		v20 = 0;
		*a3 = 1;
		LOWORD(v8) = *(_WORD *)(v3 + 1868);
		v12 = *(_WORD **)(v3 + 1876);
		if (v6 > 0)
		{
			v13 = v5;
			do
			{
				if (*v7)
				{
					v14 = 0;
					if (v8 > 0)
					{
						v15 = v12;
						while (*v13 != *v15)
						{
							++v14;
							v15 += 3;
							if (v14 >= v8)
								goto LABEL_23;
						}
						*a2 = 0;
					}
				}
			LABEL_23:
				if (*a3)
				{
					v16 = 0;
					if (v8 > 0)
					{
						v17 = v12;
						while (v13[1] != *v17)
						{
							++v16;
							v17 += 3;
							if (v16 >= v8)
								goto LABEL_30;
						}
						*a3 = 0;
					}
				}
			LABEL_30:
				v7 = a2;
				if (!*a2 && !*a3)
					break;
				v13 += 2;
				++v20;
			} while (v20 < v6);
		}
	}
	else
	{
		LOWORD(v8) = (_WORD)a3;
		v9 = 0;
		*a2 = 0;
		*a3 = 0;
		if (v6 > 0)
		{
			while (1)
			{
				v8 = *v5 / v4;
				if (*v5 % v4)
					break;
				++v9;
				v5 += 2;
				if (v9 >= v6)
					goto LABEL_7;
			}
			*a2 = 1;
		LABEL_7:
			v5 = v19;
		}
		v10 = 0;
		if (v6 > 0)
		{
			for (i = v5 + 1; ; i += 2)
			{
				v8 = *i / v4;
				if (*i % v4)
					break;
				if (++v10 >= v6)
					return v8;
			}
			*a3 = 1;
		}
	}
	return v8;
}

//----- (00562930) --------------------------------------------------------
int __cdecl sub_562930(int a1, int a2, char *a3, int a4)
{
	int result; // eax
	int v5; // esi
	int v6; // edi
	int v7; // eax

	result = 0;
	v5 = *(_DWORD *)(a1 + 184);
	switch (a2)
	{
	case 1:
	case 2:
		return 0;
	case 3:
		result = _open(a3, 0x8000);
		if (result != -1)
		{
			*(_DWORD *)(a1 + 184) = result;
			result = 0;
		}
		return result;
	case 4:
		_close(*(_DWORD *)(a1 + 184));
		return 0;
	case 5:
		v6 = a4;
		return _read(v5, a3, a4) != v6;
	case 6:
		return 1;
	case 7:
		v7 = _lseek(v5, a4, (int)a3);
		goto LABEL_13;
	case 8:
		if (a4 <= 0)
		{
			result = _lseek(v5, a4, (int)a3) == -1;
			if (!result)
			{
				result = _read(v5, &a4, 1u) != 1;
				if (!result)
				{
					v7 = _lseek(v5, -1, 1);
				LABEL_13:
					result = v7 == -1;
				}
			}
		}
		else
		{
			result = _lseek(v5, a4 - 1, (int)a3) == -1;
			if (!result)
				result = _read(v5, &a4, 1u) != 1;
		}
		return result;
	case 9:
		*(_DWORD *)a3 = _filelength(*(_DWORD *)(a1 + 184));
		return 0;
	default:
		return result;
	}
}

//----- (00562A90) --------------------------------------------------------
int __cdecl sub_562A90(_DWORD *a1, int a2, void *a3, signed int a4)
{
	int result; // eax
	int v5; // edi
	int v6; // esi

	result = 0;
	switch (a2)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 9:
		return 0;
	case 5:
		v5 = a1[449];
		if (v5 + a4 > a1[448])
			return 1;
		qmemcpy(a3, (const void *)(v5 + a1[445]), a4);
		result = 0;
		a1[449] += a4;
		return result;
	case 6:
		return 1;
	case 7:
	case 8:
		if (!a3)
		{
			v6 = a1[447];
			if (a4 >= v6)
			{
				a1[449] = a4 - v6;
				return result;
			}
			return 1;
		}
		if (a3 != (void *)1)
			return 1;
		a1[449] += a4;
		return 0;
	default:
		return result;
	}
}

//----- (00562B60) --------------------------------------------------------
unsigned int __cdecl sub_562B60(int a1, int a2)
{
	unsigned int result; // eax

	*(_DWORD *)(a1 + 328) = 0;
	result = sub_562BA0(a1);
	*(_DWORD *)(a1 + 328) = a2 - result;
	return result;
}

//----- (00562B90) --------------------------------------------------------
int __cdecl sub_562B90(int a1, int a2)
{
	int result; // eax

	result = a1;
	*(_DWORD *)(a1 + 328) += a2;
	return result;
}

//----- (00562BA0) --------------------------------------------------------
unsigned int __cdecl sub_562BA0(int a1)
{
	return (unsigned int)(60 * (*(int(__cdecl **)(int))(a1 + 80))(a1)) / *(_DWORD *)(a1 + 120) + *(_DWORD *)(a1 + 328);
}

//----- (00562BD0) --------------------------------------------------------
int __cdecl sub_562BD0(_BYTE *a1, char *a2, int a3)
{
	char *v3; // edi
	_BYTE *v4; // ebx
	int v5; // eax
	unsigned __int8 v6; // al
	_WORD *v7; // esi
	unsigned int v8; // ecx
	unsigned int v9; // ecx
	unsigned int v10; // ecx
	unsigned int v11; // ecx
	char v12; // al
	char *v13; // eax
	char *v15; // [esp+Ch] [ebp-Ch]
	unsigned int v16; // [esp+10h] [ebp-8h]

	v3 = a2;
	v15 = &a2[a3];
	v4 = a1;
	while (1)
	{
		v5 = v15 - v3;
		if (v15 == v3)
			break;
		v16 = v15 - v3;
		v6 = *v4;
		v7 = v4 + 1;
		if ((int)*v4 < 0)
		{
			if (v6 & 0x40)
			{
				v10 = (v6 & 0x3F) + 3;
				if (v6 == -2)
				{
					v11 = (unsigned __int16)*v7;
					v12 = v4[3];
					v4 += 4;
					if (v11 > v16)
						v11 = v15 - v3;
					memset(v3, v12, v11);
					v3 += v11;
				}
				else
				{
					if (v6 == -1)
					{
						v5 = (unsigned __int16)*v7;
						v7 = v4 + 3;
						v10 = v5;
					}
					LOWORD(v5) = *v7;
					v4 = v7 + 1;
					v13 = &a2[v5];
					if (v10 > v16)
						v10 = v15 - v3;
					qmemcpy(v3, v13, v10);
					v3 += v10;
				}
			}
			else
			{
				if (v6 == -128)
					return v3 - a2;
				v9 = v6 & 0x3F;
				if (v9 > v16)
					v9 = v15 - v3;
				qmemcpy(v3, v7, v9);
				v3 += v9;
				v4 = (char *)v7 + v9;
			}
		}
		else
		{
			BYTE1(v5) = v6 & 0xF;
			v8 = (v6 >> 4) + 3;
			if (v8 > v16)
				v8 = v15 - v3;
			LOBYTE(v5) = *(_BYTE *)v7;
			v4 += 2;
			qmemcpy(v3, &v3[-v5], v8);
			v3 += v8;
		}
	}
	return v3 - a2;
}

//----- (00562C9B) --------------------------------------------------------
int __cdecl sub_562C9B(unsigned __int8 *a1, char *a2, int a3)
{
	char *v3; // edi
	unsigned __int8 *v4; // ebx
	unsigned int v5; // eax
	_WORD *v6; // esi
	unsigned int v7; // ecx
	unsigned int v8; // ecx
	unsigned int v9; // ecx
	unsigned int v10; // ecx
	char v11; // al
	char *v12; // eax
	unsigned __int8 *v14; // ebx
	unsigned int v15; // eax
	_WORD *v16; // esi
	unsigned int v17; // ecx
	unsigned int v18; // ecx
	unsigned int v19; // ecx
	unsigned int v20; // ecx
	char v21; // al
	char *v22; // [esp+Ch] [ebp-Ch]
	char *v23; // [esp+Ch] [ebp-Ch]
	unsigned int v24; // [esp+10h] [ebp-8h]
	unsigned int v25; // [esp+10h] [ebp-8h]

	v3 = a2;
	if (*a1)
	{
		v22 = &a2[a3];
		v4 = a1;
		while (v22 != v3 && v22 - v3 >= 0)
		{
			v24 = v22 - v3;
			v5 = *v4;
			v6 = v4 + 1;
			if ((v5 & 0x80u) != 0)
			{
				if (v5 & 0x40)
				{
					v9 = (v5 & 0x3F) + 3;
					if ((_BYTE)v5 == (_BYTE)-2)
					{
						v10 = (unsigned __int16)*v6;
						v11 = v4[3];
						v4 += 4;
						if (v10 > v24)
							v10 = v22 - v3;
						memset(v3, v11, v10);
						v3 += v10;
					}
					else
					{
						if ((_BYTE)v5 == (_BYTE)-1)
						{
							v5 = (unsigned __int16)*v6;
							v6 = v4 + 3;
							v9 = v5;
						}
						LOWORD(v5) = *v6;
						v4 = (unsigned __int8 *)(v6 + 1);
						v12 = &a2[v5];
						if (v9 > v24)
							v9 = v22 - v3;
						qmemcpy(v3, v12, v9);
						v3 += v9;
					}
				}
				else
				{
					if ((_BYTE)v5 == (_BYTE)-128)
						return v3 - a2;
					v8 = v5 & 0x3F;
					if (v8 > v24)
						v8 = v22 - v3;
					qmemcpy(v3, v6, v8);
					v3 += v8;
					v4 = (unsigned __int8 *)v6 + v8;
				}
			}
			else
			{
				BYTE1(v5) = v5 & 0xF;
				v7 = ((unsigned __int8)v5 >> 4) + 3;
				if (v7 > v24)
					v7 = v22 - v3;
				LOBYTE(v5) = *(_BYTE *)v6;
				v4 += 2;
				qmemcpy(v3, &v3[-v5], v7);
				v3 += v7;
			}
		}
	}
	else
	{
		v23 = &a2[a3];
		v14 = a1 + 1;
		while (v23 != v3)
		{
			v25 = v23 - v3;
			v15 = *v14;
			v16 = v14 + 1;
			if ((v15 & 0x80u) != 0)
			{
				if (v15 & 0x40)
				{
					v19 = (v15 & 0x3F) + 3;
					if ((_BYTE)v15 == (_BYTE)-2)
					{
						v20 = (unsigned __int16)*v16;
						v21 = v14[3];
						v14 += 4;
						if (v20 > v25)
							v20 = v23 - v3;
						memset(v3, v21, v20);
						v3 += v20;
					}
					else
					{
						if ((_BYTE)v15 == (_BYTE)-1)
						{
							v15 = (unsigned __int16)*v16;
							v16 = v14 + 3;
							v19 = v15;
						}
						v14 = (unsigned __int8 *)(v16 + 1);
						if (v19 > v25)
							v19 = v23 - v3;
						LOWORD(v15) = *v16;
						qmemcpy(v3, &v3[-v15], v19);
						v3 += v19;
					}
				}
				else
				{
					if ((_BYTE)v15 == (_BYTE)-128)
						return v3 - a2;
					v18 = v15 & 0x3F;
					if (v18 > v25)
						v18 = v23 - v3;
					qmemcpy(v3, v16, v18);
					v3 += v18;
					v14 = (unsigned __int8 *)v16 + v18;
				}
			}
			else
			{
				BYTE1(v15) = v15 & 0xF;
				v17 = ((unsigned __int8)v15 >> 4) + 3;
				if (v17 > v25)
					v17 = v23 - v3;
				LOBYTE(v15) = *(_BYTE *)v16;
				v14 += 2;
				qmemcpy(v3, &v3[-v15], v17);
				v3 += v17;
			}
		}
	}
	return v3 - a2;
}

int __cdecl sub_562E30(_WORD *a1, char *a2, int a3)
{
	DebugBreak();
	return 0;
}
#if 0
//----- (00562E30) --------------------------------------------------------
int __cdecl sub_562E30(_WORD *a1, char *a2, int a3)
{
	unsigned int v3; // et0
	_WORD *v4; // esi
	char *v5; // edi
	int v6; // ecx
	char v7; // dl
	int v8; // eax
	unsigned int v9; // eax
	int v10; // ebx
	unsigned int i; // ecx
	int v12; // ecx
	int v13; // edi
	unsigned __int8 v14; // al
	unsigned __int8 v15; // ah
	char v16; // bl
	int v17; // ebx
	__int16 v18; // dx
	unsigned int v19; // et0
	char v20; // cf
	unsigned int v21; // et0
	char v22; // ah
	unsigned int v23; // ebx
	__int16 v24; // dx
	unsigned int v25; // et0
	unsigned int v26; // ebx
	int v27; // edx
	unsigned int v28; // et0
	unsigned int v29; // ebx
	int v30; // edx
	unsigned int v31; // et0
	unsigned int v32; // ebx
	int v33; // edx
	unsigned int v34; // et0
	int v35; // edx
	unsigned int v37; // [esp-18h] [ebp-24h]
	unsigned int v38; // [esp-18h] [ebp-24h]
	unsigned int v39; // [esp-18h] [ebp-24h]
	unsigned int v40; // [esp-18h] [ebp-24h]
	unsigned int v41; // [esp-18h] [ebp-24h]
	unsigned int v42; // [esp-18h] [ebp-24h]
	unsigned int v43; // [esp-14h] [ebp-20h]
	int v44; // [esp+4h] [ebp-8h]

	v3 = __readeflags();
	v43 = v3;
	v44 = 0;
	if (a1 && a2 && a3)
	{
		v4 = a1;
		v5 = a2;
		v6 = a3;
		v7 = -128;
		while (v6 > 0)
		{
			v8 = *(unsigned __int8 *)v4;
			++v44;
			v4 = (_WORD *)((char *)v4 + 1);
			v9 = 4 * v8;
			LOBYTE(v9) = (unsigned __int8)v9 >> 2;
			if (BYTE1(v9) == 2)
			{
				if (v9 & 0x20)
				{
					v7 += (char)(8 * v9) >> 3;
					*v5 = v7;
					--v6;
					++v5;
				}
				else
				{
					v10 = v6;
					LOWORD(v9) = (unsigned __int8)(v9 + 1);
					for (i = v9 >> 1; i; --i)
					{
						*(_WORD *)v5 = *v4;
						++v4;
						v5 += 2;
					}
					v12 = v9 & 1;
					qmemcpy(v5, v4, v12);
					v4 = (_WORD *)((char *)v4 + v12);
					v13 = (int)&v5[v12];
					v44 += v9;
					v6 = v10 - v9;
					v7 = *(_BYTE *)--v13;
					v5 = (char *)(v13 + 1);
				}
			}
			else
			{
				LOBYTE(v9) = v9 + 1;
				if (BYTE1(v9) == 1)
				{
					do
					{
						v15 = *(_BYTE *)v4;
						v16 = *(_BYTE *)v4;
						++v44;
						v4 = (_WORD *)((char *)v4 + 1);
						v17 = v16 & 0xF;
						LOBYTE(v18) = byte_563006[v17] + v7;
						v19 = __readeflags();
						v37 = v19;
						if (byte_563006[v17] < 0)
						{
							__writeeflags(v37);
							if (!v20)
								LOBYTE(v18) = 0;
						}
						else
						{
							__writeeflags(v37);
							if (v20)
								LOBYTE(v18) = -1;
						}
						LOBYTE(v17) = v15 >> 4;
						HIBYTE(v18) = byte_563006[v17] + v18;
						v21 = __readeflags();
						v38 = v21;
						if (byte_563006[v17] < 0)
						{
							__writeeflags(v38);
							if (!v20)
								HIBYTE(v18) = 0;
						}
						else
						{
							__writeeflags(v38);
							if (v20)
								HIBYTE(v18) = -1;
						}
						*(_WORD *)v5 = v18;
						v6 -= 2;
						v5 += 2;
						v7 = HIBYTE(v18);
						--v14;
					} while (v14);
				}
				else if (BYTE1(v9))
				{
					memset(v5, v7, v14);
					v5 += v14;
					v6 -= v14;
				}
				else
				{
					do
					{
						v22 = *(_BYTE *)v4;
						++v44;
						v4 = (_WORD *)((char *)v4 + 1);
						v23 = v22 & 3;
						LOBYTE(v24) = byte_563002[v23] + v7;
						v25 = __readeflags();
						v39 = v25;
						if (byte_563002[v23] < 0)
						{
							__writeeflags(v39);
							if (!v20)
								LOBYTE(v24) = 0;
						}
						else
						{
							__writeeflags(v39);
							if (v20)
								LOBYTE(v24) = -1;
						}
						HIBYTE(v24) = v24;
						v27 = __ROR4__(v24, 8);
						LOBYTE(v23) = v22;
						v26 = v23 >> 2;
						LOBYTE(v26) = v26 & 3;
						LOBYTE(v27) = byte_563002[v26] + v27;
						v28 = __readeflags();
						v40 = v28;
						if (byte_563002[v26] < 0)
						{
							__writeeflags(v40);
							if (!v20)
								LOBYTE(v27) = 0;
						}
						else
						{
							__writeeflags(v40);
							if (v20)
								LOBYTE(v27) = -1;
						}
						BYTE1(v27) = v27;
						v30 = __ROR4__(v27, 8);
						LOBYTE(v26) = v22;
						v29 = v26 >> 4;
						LOBYTE(v29) = v29 & 3;
						LOBYTE(v30) = byte_563002[v29] + v30;
						v31 = __readeflags();
						v41 = v31;
						if (byte_563002[v29] < 0)
						{
							__writeeflags(v41);
							if (!v20)
								LOBYTE(v30) = 0;
						}
						else
						{
							__writeeflags(v41);
							if (v20)
								LOBYTE(v30) = -1;
						}
						BYTE1(v30) = v30;
						v33 = __ROR4__(v30, 8);
						LOBYTE(v29) = v22;
						v32 = v29 >> 6;
						LOBYTE(v32) = v32 & 3;
						LOBYTE(v33) = byte_563002[v32] + v33;
						v34 = __readeflags();
						v42 = v34;
						if (byte_563002[v32] < 0)
						{
							__writeeflags(v42);
							if (!v20)
								LOBYTE(v33) = 0;
						}
						else
						{
							__writeeflags(v42);
							if (v20)
								LOBYTE(v33) = -1;
						}
						v35 = __ROR4__(v33, 8);
						*(_DWORD *)v5 = v35;
						v6 -= 4;
						v5 += 4;
						v7 = __ROL4__(v35, 8);
						--v14;
					} while (v14);
				}
			}
		}
	}
	__writeeflags(v43);
	return v44;
}
// 562EDC: variable 'v20' is possibly undefined
#endif
//----- (00563020) --------------------------------------------------------
unsigned int __cdecl sub_563020(int a1, unsigned __int16 *a2, _BYTE *a3, unsigned int a4, int a5, int a6)
{
	unsigned int result; // eax
	_BYTE *v7; // esi
	int v8; // ebx
	unsigned __int16 v9; // dx
	unsigned __int16 v10; // ax
	int v11; // ecx
	int v12; // eax
	unsigned int v13; // ecx
	char v14; // bp
	int v15; // eax
	unsigned int v16; // ecx
	unsigned __int16 v17; // dx
	int v18; // edi
	int v19; // eax
	_BYTE *v20; // ecx
	int v21; // ebp
	int v22; // edx
	int v23; // eax
	unsigned int v24; // ecx
	char v25; // bp
	int v26; // eax
	unsigned int v27; // ecx
	_BYTE *v28; // eax
	int v29; // ebp
	int v30; // ecx
	unsigned int v31; // eax
	unsigned __int16 *v32; // ebp
	unsigned int v33; // ecx
	unsigned int v34; // eax
	unsigned __int16 v35; // dx
	char v36; // cl
	int v37; // ebp
	int v38; // edi
	int v39; // esi
	int v40; // eax
	int v41; // esi
	int v42; // edi
	int v43; // ecx
	int v44; // esi
	int v45; // eax
	bool v46; // zf
	int v47; // edi
	int v48; // esi
	int v49; // eax
	_BYTE *v50; // eax
	int v51; // edi
	int v52; // edx
	_BYTE *v53; // edx
	int v54; // edi
	int v55; // eax
	int v56; // [esp+4h] [ebp-Ch]
	int v57; // [esp+4h] [ebp-Ch]
	unsigned int v58; // [esp+4h] [ebp-Ch]
	_BYTE *v59; // [esp+8h] [ebp-8h]
	unsigned int v60; // [esp+Ch] [ebp-4h]
	unsigned int v61; // [esp+1Ch] [ebp+Ch]
	int v62; // [esp+24h] [ebp+14h]
	int v63; // [esp+24h] [ebp+14h]
	int v64; // [esp+24h] [ebp+14h]
	int v65; // [esp+24h] [ebp+14h]
	unsigned int v66; // [esp+24h] [ebp+14h]

	result = a5 * a4;
	v7 = a3;
	v61 = 0;
	v59 = v7;
	v60 = a5 * a4;
	if (a5 * a4)
	{
		v8 = a6;
		do
		{
			v9 = *a2;
			if (((*a2 >> 8) & 0x80u) == 0)
			{
				v53 = (_BYTE *)(a1 + 16 * *a2);
				v54 = 4;
				do
				{
					v55 = 4;
					do
					{
						*v7++ = *v53++;
						--v55;
					} while (v55);
					--v54;
					v7 = &v7[v8 - 4];
				} while (v54);
				v7 += 4 - 4 * v8;
				goto LABEL_75;
			}
			v10 = *a2;
			v11 = v9 & 0xF000;
			if (v11 > 49152)
			{
				if (v11 == 57344)
				{
					v50 = (_BYTE *)(a1 + 16 * (v9 & 0xFFF));
					v51 = 4;
					do
					{
						v52 = 4;
						do
						{
							if (*v50)
								*v7 = *v50;
							++v7;
							++v50;
							--v52;
						} while (v52);
						--v51;
						v7 = &v7[v8 - 4];
					} while (v51);
					v7 += 4 - 4 * v8;
					++a2;
					goto LABEL_76;
				}
				if (v11 == 61440)
				{
					if ((_BYTE)v9)
					{
						v47 = 4;
						do
						{
							v48 = (int)(v7 + 4);
							LOBYTE(v11) = v9;
							BYTE1(v11) = v9;
							v49 = v11 << 16;
							LOWORD(v49) = v11;
							*(_DWORD *)(v48 - 4) = v49;
							v7 = (_BYTE *)(v8 - 4 + v48);
							--v47;
						} while (v47);
						v7 -= 4 * v8;
					}
					v7 += 4;
				LABEL_75:
					++a2;
				LABEL_76:
					v23 = v61 + 1;
				LABEL_77:
					v61 = v23;
					goto LABEL_78;
				}
			}
			else
			{
				if (v11 == 49152)
				{
					v31 = v9 & 0xFFF;
					v32 = a2 + 1;
					v33 = v31;
					++a2;
					v34 = v31 >> 1;
					v66 = v33;
					if (v34)
					{
						v58 = v34;
						do
						{
							v35 = *v32;
							v36 = *v32 >> 8;
							if (v36)
							{
								v37 = v8 - 4;
								v38 = 4;
								do
								{
									v39 = (int)(v7 + 4);
									LOBYTE(v8) = v36;
									BYTE1(v8) = v36;
									v40 = v8 << 16;
									LOWORD(v40) = v8;
									*(_DWORD *)(v39 - 4) = v40;
									v7 = (_BYTE *)(v37 + v39);
									--v38;
								} while (v38);
								v8 = a6;
								v7 -= 4 * a6;
							}
							v41 = (int)(v7 + 4);
							if ((_BYTE)v35)
							{
								v42 = v8 - 4;
								v43 = 4;
								do
								{
									v44 = v41 + 4;
									LOBYTE(v8) = v35;
									BYTE1(v8) = v35;
									v45 = v8 << 16;
									LOWORD(v45) = v8;
									*(_DWORD *)(v44 - 4) = v45;
									v41 = v42 + v44;
									--v43;
								} while (v43);
								v8 = a6;
								v41 -= 4 * a6;
							}
							v7 = (_BYTE *)(v41 + 4);
							v32 = a2 + 1;
							v46 = v58 == 1;
							++a2;
							--v58;
						} while (!v46);
						v33 = v66;
					}
					v23 = v33 + v61;
					goto LABEL_77;
				}
				if (v11 != 40960)
				{
					if (v11 == 45056)
					{
						v12 = (v9 >> 8) & 0xF;
						v62 = (v9 >> 8) & 0xF;
						if ((_BYTE)v9)
						{
							v13 = 4 * v12;
							v56 = 4;
							do
							{
								if (v13)
								{
									v14 = v13;
									LOBYTE(v8) = v9;
									BYTE1(v8) = v9;
									v15 = v8 << 16;
									LOWORD(v15) = v8;
									v8 = a6;
									v16 = v13 >> 2;
									memset32(v7, v15, v16);
									memset(&v7[4 * v16], v15, v14 & 3);
									v12 = (v9 >> 8) & 0xF;
									v13 = 4 * v62;
									v7 += 4 * v62;
								}
								v7 += v8 - v13;
								--v56;
							} while (v56);
							v7 -= 4 * v8;
						}
						v7 += 4 * v12;
						v61 += v12;
						++a2;
					}
					goto LABEL_78;
				}
				v17 = a2[1];
				++a2;
				v18 = v10 & 0xFFF;
				v63 = v10 & 0xFFF;
				if ((v17 & 0x8000u) == 0)
				{
					v65 = 4;
					v28 = (_BYTE *)(a1 + 16 * v17);
					do
					{
						if (v18)
						{
							v29 = v18;
							do
							{
								v30 = 4;
								do
								{
									*v7++ = *v28++;
									--v30;
								} while (v30);
								v28 -= 4;
								--v29;
							} while (v29);
						}
						v28 += 4;
						v7 += v8 - 4 * v18;
						--v65;
					} while (v65);
					++a2;
					v7 += 4 * (v18 - v8);
					v23 = v18 + v61;
					goto LABEL_77;
				}
				v19 = v17 & 0xC000;
				if (v19 == 0x8000)
				{
					if ((_BYTE)v17)
					{
						v24 = 4 * v18;
						v57 = 4;
						do
						{
							if (v24)
							{
								v25 = v24;
								LOBYTE(v8) = v17;
								BYTE1(v8) = v17;
								v26 = v8 << 16;
								LOWORD(v26) = v8;
								v8 = a6;
								v27 = v24 >> 2;
								memset32(v7, v26, v27);
								memset(&v7[4 * v27], v26, v25 & 3);
								v18 = v63;
								v24 = 4 * v63;
								v7 += 4 * v63;
							}
							v7 += v8 - v24;
							--v57;
						} while (v57);
						v7 -= 4 * v8;
					}
					v7 += 4 * v18;
					v61 += v18;
					++a2;
					goto LABEL_78;
				}
				if (v19 == 49152)
				{
					v20 = (_BYTE *)(a1 + 16 * (v17 & 0xFFF));
					v64 = 4;
					do
					{
						if (v18)
						{
							v21 = v18;
							do
							{
								v22 = 4;
								do
								{
									if (*v20)
										*v7 = *v20;
									++v7;
									++v20;
									--v22;
								} while (v22);
								v20 -= 4;
								--v21;
							} while (v21);
						}
						v20 += 4;
						v7 += v8 - 4 * v18;
						--v64;
					} while (v64);
					v7 += 4 * (v18 - v8);
					v23 = v18 + v61;
					++a2;
					goto LABEL_77;
				}
			}
		LABEL_78:
			result = v61 / a4;
			if (!(v61 % a4))
			{
				v7 = &v59[4 * v8];
				v59 += 4 * v8;
			}
		} while (v61 < v60);
	}
	return result;
}

//----- (00563470) --------------------------------------------------------
unsigned int __cdecl sub_563470(int a1, unsigned __int16 *a2, _BYTE *a3, unsigned int a4, int a5, int a6)
{
	unsigned int result; // eax
	unsigned __int16 *v7; // ebp
	_BYTE *v8; // esi
	int v9; // ebx
	unsigned __int16 v10; // dx
	unsigned __int16 v11; // ax
	int v12; // ecx
	int v13; // eax
	unsigned int v14; // ecx
	char v15; // bp
	int v16; // eax
	unsigned int v17; // ecx
	unsigned __int16 v18; // dx
	int v19; // edi
	int v20; // ecx
	_BYTE *v21; // eax
	int v22; // ebp
	int v23; // ecx
	unsigned int v24; // ecx
	char v25; // bp
	int v26; // eax
	unsigned int v27; // ecx
	_BYTE *v28; // eax
	int v29; // edx
	int v30; // ebp
	int v31; // ecx
	int v32; // eax
	unsigned int v33; // eax
	int v34; // ebp
	int v35; // edi
	unsigned __int16 v36; // dx
	char v37; // cl
	int v38; // esi
	int v39; // eax
	int v40; // ecx
	int v41; // esi
	int v42; // esi
	int v43; // eax
	bool v44; // zf
	int v45; // edi
	int v46; // esi
	int v47; // eax
	_BYTE *v48; // eax
	int v49; // edi
	int v50; // ecx
	_BYTE *v51; // edx
	int v52; // edi
	int v53; // eax
	int v54; // [esp+8h] [ebp-Ch]
	int v55; // [esp+8h] [ebp-Ch]
	unsigned int v56; // [esp+8h] [ebp-Ch]
	_BYTE *v57; // [esp+Ch] [ebp-8h]
	unsigned int v58; // [esp+10h] [ebp-4h]
	unsigned int v59; // [esp+20h] [ebp+Ch]
	int v60; // [esp+28h] [ebp+14h]
	int v61; // [esp+28h] [ebp+14h]
	int v62; // [esp+28h] [ebp+14h]
	unsigned int v63; // [esp+28h] [ebp+14h]

	result = a5 * a4;
	v7 = a2;
	v8 = a3;
	v57 = a3;
	v59 = 0;
	v58 = a5 * a4;
	if (a5 * a4)
	{
		v9 = a6;
		while (1)
		{
			v10 = *v7;
			if (((*v7 >> 8) & 0x80u) == 0)
				break;
			v11 = *v7;
			v12 = v10 & 0xF000;
			if (v12 > 49152)
			{
				if (v12 == 57344)
				{
					v48 = (_BYTE *)(a1 + 16 * (v10 & 0xFFF));
					v49 = 4;
					do
					{
						v50 = 4;
						do
						{
							*v8++ = *v48++;
							--v50;
						} while (v50);
						--v49;
						v8 = &v8[v9 - 4];
					} while (v49);
					v8 += 4 - 4 * v9;
				}
				else
				{
					if (v12 != 61440)
						goto LABEL_66;
					v45 = 4;
					do
					{
						v46 = (int)(v8 + 4);
						LOBYTE(v12) = v10;
						BYTE1(v12) = v10;
						v47 = v12 << 16;
						LOWORD(v47) = v12;
						*(_DWORD *)(v46 - 4) = v47;
						v8 = (_BYTE *)(v9 - 4 + v46);
						--v45;
					} while (v45);
				LABEL_63:
					v8 += 4 - 4 * v9;
				}
				v32 = v59 + 1;
				++a2;
				goto LABEL_65;
			}
			switch (v12)
			{
			case 49152:
				v33 = v10 & 0xFFF;
				v63 = v33;
				a2 = v7 + 1;
				if (v33 >> 1)
				{
					v34 = v9 - 4;
					v56 = v33 >> 1;
					do
					{
						v35 = 4;
						v36 = *a2;
						v37 = *a2 >> 8;
						do
						{
							v38 = (int)(v8 + 4);
							LOBYTE(v9) = v37;
							BYTE1(v9) = v37;
							v39 = v9 << 16;
							LOWORD(v39) = v9;
							*(_DWORD *)(v38 - 4) = v39;
							v8 = (_BYTE *)(v34 + v38);
							--v35;
						} while (v35);
						v40 = 4;
						v41 = (int)&v8[4 - 4 * a6];
						do
						{
							v42 = v41 + 4;
							LOBYTE(v9) = v36;
							BYTE1(v9) = v36;
							v43 = v9 << 16;
							LOWORD(v43) = v9;
							*(_DWORD *)(v42 - 4) = v43;
							v41 = v34 + v42;
							--v40;
						} while (v40);
						v8 = (_BYTE *)(4 - 4 * a6 + v41);
						v44 = v56 == 1;
						++a2;
						--v56;
					} while (!v44);
					v33 = v63;
					v9 = a6;
				}
				v59 += v33;
				break;
			case 40960:
				v18 = v7[1];
				a2 = v7 + 1;
				v19 = v11 & 0xFFF;
				v61 = v11 & 0xFFF;
				if ((v18 & 0x8000u) == 0)
				{
					v28 = (_BYTE *)(a1 + 16 * v7[1]);
					v29 = 4;
					do
					{
						if (v19)
						{
							v30 = v19;
							do
							{
								v31 = 4;
								do
								{
									*v8++ = *v28++;
									--v31;
								} while (v31);
								v28 -= 4;
								--v30;
							} while (v30);
							v9 = a6;
						}
						v28 += 4;
						v8 += v9 - 4 * v19;
						--v29;
					} while (v29);
					v8 += 4 * (v19 - v9);
					goto LABEL_39;
				}
				v20 = v18 & 0xC000;
				if (v20 != 0x8000)
				{
					if (v20 != 49152)
						break;
					v21 = (_BYTE *)(a1 + 16 * (v18 & 0xFFF));
					v62 = 4;
					do
					{
						if (v19)
						{
							v22 = v19;
							do
							{
								v23 = 4;
								do
								{
									*v8++ = *v21++;
									--v23;
								} while (v23);
								v21 -= 4;
								--v22;
							} while (v22);
						}
						v21 += 4;
						v8 += v9 - 4 * v19;
						--v62;
					} while (v62);
					v8 += 4 * (v19 - v9);
				LABEL_39:
					v32 = v19 + v59;
					++a2;
				LABEL_65:
					v59 = v32;
					break;
				}
				v24 = 4 * v19;
				v55 = 4;
				do
				{
					if (v24)
					{
						v25 = v24;
						LOBYTE(v9) = v18;
						BYTE1(v9) = v18;
						v26 = v9 << 16;
						LOWORD(v26) = v9;
						v9 = a6;
						v27 = v24 >> 2;
						memset32(v8, v26, v27);
						memset(&v8[4 * v27], v26, v25 & 3);
						v19 = v61;
						v24 = 4 * v61;
						v8 += 4 * v61;
					}
					v8 += v9 - v24;
					--v55;
				} while (v55);
				v8 += 4 * (v19 - v9);
				v59 += v19;
				++a2;
				break;
			case 45056:
				v13 = (v10 >> 8) & 0xF;
				v54 = 4;
				v60 = v13;
				v14 = 4 * v13;
				do
				{
					if (v14)
					{
						v15 = v14;
						LOBYTE(v9) = v10;
						BYTE1(v9) = v10;
						v16 = v9 << 16;
						LOWORD(v16) = v9;
						v9 = a6;
						v17 = v14 >> 2;
						memset32(v8, v16, v17);
						memset(&v8[4 * v17], v16, v15 & 3);
						v13 = v60;
						v14 = 4 * v60;
						v8 += 4 * v60;
					}
					v8 += v9 - v14;
					--v54;
				} while (v54);
				v8 += 4 * (v13 - v9);
				v59 += v13;
				++a2;
				break;
			}
		LABEL_66:
			result = v59 / a4;
			if (!(v59 % a4))
			{
				v8 = &v57[4 * v9];
				v57 += 4 * v9;
			}
			if (v59 >= v58)
				return result;
			v7 = a2;
		}
		v51 = (_BYTE *)(a1 + 16 * *v7);
		v52 = 4;
		do
		{
			v53 = 4;
			do
			{
				*v8++ = *v51++;
				--v53;
			} while (v53);
			--v52;
			v8 = &v8[v9 - 4];
		} while (v52);
		goto LABEL_63;
	}
	return result;
}

//----- (00563880) --------------------------------------------------------
unsigned int __cdecl sub_563880(int a1, unsigned __int16 *a2, _BYTE *a3, unsigned int a4, int a5, int a6)
{
	unsigned int result; // eax
	_BYTE *v7; // esi
	int v8; // ebx
	unsigned __int16 v9; // dx
	unsigned __int16 v10; // ax
	int v11; // ecx
	int v12; // eax
	unsigned int v13; // ecx
	char v14; // bp
	int v15; // eax
	unsigned int v16; // ecx
	unsigned __int16 v17; // dx
	int v18; // edi
	int v19; // ecx
	_BYTE *v20; // eax
	int v21; // ebp
	int v22; // edx
	unsigned int v23; // ecx
	char v24; // bp
	int v25; // eax
	unsigned int v26; // ecx
	char *v27; // eax
	int v28; // ebp
	int v29; // ecx
	char v30; // dl
	int v31; // eax
	unsigned int v32; // eax
	unsigned __int16 *v33; // ebp
	unsigned int v34; // ecx
	unsigned int v35; // eax
	unsigned __int16 v36; // dx
	char v37; // cl
	int v38; // edi
	__int16 v39; // ax
	int v40; // esi
	int v41; // esi
	int v42; // ecx
	__int16 v43; // ax
	int v44; // esi
	bool v45; // zf
	int v46; // edi
	__int16 v47; // ax
	int v48; // esi
	_BYTE *v49; // eax
	int v50; // edi
	int v51; // edx
	char *v52; // edx
	int v53; // edi
	int v54; // eax
	char v55; // cl
	int v56; // [esp+4h] [ebp-Ch]
	int v57; // [esp+4h] [ebp-Ch]
	unsigned int v58; // [esp+4h] [ebp-Ch]
	_BYTE *v59; // [esp+8h] [ebp-8h]
	unsigned int v60; // [esp+Ch] [ebp-4h]
	unsigned int v61; // [esp+1Ch] [ebp+Ch]
	int v62; // [esp+24h] [ebp+14h]
	int v63; // [esp+24h] [ebp+14h]
	int v64; // [esp+24h] [ebp+14h]
	int v65; // [esp+24h] [ebp+14h]
	unsigned int v66; // [esp+24h] [ebp+14h]

	result = a5 * a4;
	v7 = a3;
	v61 = 0;
	v59 = v7;
	v60 = a5 * a4;
	if (a5 * a4)
	{
		v8 = a6;
		do
		{
			v9 = *a2;
			if (((*a2 >> 8) & 0x80u) == 0)
			{
				v52 = (char *)(a1 + 16 * *a2);
				v53 = 2;
				do
				{
					v54 = 2;
					do
					{
						v55 = *v52;
						v52 += 2;
						*v7++ = v55;
						--v54;
					} while (v54);
					--v53;
					v7 = &v7[v8 - 2];
				} while (v53);
				v7 += 2 - 2 * v8;
				goto LABEL_76;
			}
			v10 = *a2;
			v11 = v9 & 0xF000;
			if (v11 > 49152)
			{
				if (v11 == 57344)
				{
					v49 = (_BYTE *)(a1 + 16 * (v9 & 0xFFF));
					v50 = 2;
					do
					{
						v51 = 2;
						do
						{
							if (*v49)
								*v7 = *v49;
							++v7;
							v49 += 2;
							--v51;
						} while (v51);
						--v50;
						v7 = &v7[v8 - 2];
					} while (v50);
					v7 += 2 - 2 * v8;
					++a2;
					goto LABEL_77;
				}
				if (v11 == 61440)
				{
					if ((_BYTE)v9)
					{
						v46 = 2;
						do
						{
							LOBYTE(v47) = v9;
							v48 = (int)(v7 + 2);
							HIBYTE(v47) = v9;
							*(_WORD *)(v48 - 2) = v47;
							v7 = (_BYTE *)(v8 - 2 + v48);
							--v46;
						} while (v46);
						v7 -= 2 * v8;
					}
					v7 += 2;
				LABEL_76:
					++a2;
				LABEL_77:
					v31 = v61 + 1;
					goto LABEL_78;
				}
			}
			else
			{
				if (v11 == 49152)
				{
					v32 = v9 & 0xFFF;
					v33 = a2 + 1;
					v34 = v32;
					++a2;
					v35 = v32 >> 1;
					v66 = v34;
					if (v35)
					{
						v58 = v35;
						do
						{
							v36 = *v33;
							v37 = *v33 >> 8;
							if (v37)
							{
								v38 = 2;
								do
								{
									LOBYTE(v39) = v37;
									v40 = (int)(v7 + 2);
									HIBYTE(v39) = v37;
									*(_WORD *)(v40 - 2) = v39;
									v7 = (_BYTE *)(v8 - 2 + v40);
									--v38;
								} while (v38);
								v8 = a6;
								v7 -= 2 * a6;
							}
							v41 = (int)(v7 + 2);
							if ((_BYTE)v36)
							{
								v42 = 2;
								do
								{
									LOBYTE(v43) = v36;
									v44 = v41 + 2;
									HIBYTE(v43) = v36;
									*(_WORD *)(v44 - 2) = v43;
									v41 = v8 - 2 + v44;
									--v42;
								} while (v42);
								v8 = a6;
								v41 -= 2 * a6;
							}
							v7 = (_BYTE *)(v41 + 2);
							v33 = a2 + 1;
							v45 = v58 == 1;
							++a2;
							--v58;
						} while (!v45);
						v34 = v66;
					}
					v31 = v34 + v61;
					goto LABEL_78;
				}
				if (v11 != 40960)
				{
					if (v11 == 45056)
					{
						v12 = (v9 >> 8) & 0xF;
						v62 = (v9 >> 8) & 0xF;
						if ((_BYTE)v9)
						{
							v13 = 2 * v12;
							v56 = 2;
							do
							{
								if (v13)
								{
									v14 = v13;
									LOBYTE(v8) = v9;
									BYTE1(v8) = v9;
									v15 = v8 << 16;
									LOWORD(v15) = v8;
									v8 = a6;
									v16 = v13 >> 2;
									memset32(v7, v15, v16);
									memset(&v7[4 * v16], v15, v14 & 3);
									v12 = (v9 >> 8) & 0xF;
									v13 = 2 * v62;
									v7 += 2 * v62;
								}
								v7 += v8 - v13;
								--v56;
							} while (v56);
							v7 -= 2 * v8;
						}
						v7 += 2 * v12;
						v61 += v12;
						++a2;
					}
					goto LABEL_79;
				}
				v17 = a2[1];
				++a2;
				v18 = v10 & 0xFFF;
				v63 = v10 & 0xFFF;
				if ((v17 & 0x8000u) == 0)
				{
					v65 = 2;
					v27 = (char *)(a1 + 16 * v17);
					do
					{
						if (v18)
						{
							v28 = v18;
							do
							{
								v29 = 2;
								do
								{
									v30 = *v27;
									v27 += 2;
									*v7++ = v30;
									--v29;
								} while (v29);
								v27 -= 4;
								--v28;
							} while (v28);
						}
						v27 += 4;
						v7 += v8 - 2 * v18;
						--v65;
					} while (v65);
					v7 += 2 * (v18 - v8);
				LABEL_43:
					v31 = v18 + v61;
					++a2;
				LABEL_78:
					v61 = v31;
					goto LABEL_79;
				}
				v19 = v17 & 0xC000;
				if (v19 == 0x8000)
				{
					if ((_BYTE)v17)
					{
						v23 = 2 * v18;
						v57 = 2;
						do
						{
							if (v23)
							{
								v24 = v23;
								LOBYTE(v8) = v17;
								BYTE1(v8) = v17;
								v25 = v8 << 16;
								LOWORD(v25) = v8;
								v8 = a6;
								v26 = v23 >> 2;
								memset32(v7, v25, v26);
								memset(&v7[4 * v26], v25, v24 & 3);
								v18 = v63;
								v23 = 2 * v63;
								v7 += 2 * v63;
							}
							v7 += v8 - v23;
							--v57;
						} while (v57);
						v7 -= 2 * v8;
					}
					v7 += 2 * v18;
					v61 += v18;
					++a2;
					goto LABEL_79;
				}
				if (v19 == 49152)
				{
					v20 = (_BYTE *)(a1 + 16 * (v17 & 0xFFF));
					v64 = 2;
					do
					{
						if (v18)
						{
							v21 = v18;
							do
							{
								v22 = 2;
								do
								{
									if (*v20)
										*v7 = *v20;
									++v7;
									v20 += 2;
									--v22;
								} while (v22);
								v20 -= 4;
								--v21;
							} while (v21);
						}
						v20 += 4;
						v7 += v8 - 2 * v18;
						--v64;
					} while (v64);
					v7 += 2 * (v18 - v8);
					goto LABEL_43;
				}
			}
		LABEL_79:
			result = v61 / a4;
			if (!(v61 % a4))
			{
				v7 = &v59[2 * v8];
				v59 += 2 * v8;
			}
		} while (v61 < v60);
	}
	return result;
}

//----- (00563C90) --------------------------------------------------------
unsigned int __cdecl sub_563C90(int a1, unsigned __int16 *a2, _BYTE *a3, unsigned int a4, int a5, int a6)
{
	unsigned int result; // eax
	_BYTE *v7; // esi
	int v8; // ebx
	unsigned __int16 v9; // dx
	unsigned __int16 v10; // ax
	int v11; // ecx
	int v12; // eax
	unsigned int v13; // ecx
	char v14; // bp
	int v15; // eax
	unsigned int v16; // ecx
	unsigned __int16 v17; // dx
	int v18; // edi
	int v19; // ecx
	_BYTE *v20; // ecx
	int v21; // ebp
	int v22; // edx
	unsigned int v23; // ecx
	char v24; // bp
	int v25; // eax
	unsigned int v26; // ecx
	_BYTE *v27; // eax
	int v28; // ebp
	int v29; // ecx
	int v30; // eax
	unsigned int v31; // eax
	unsigned __int16 *v32; // ebp
	unsigned int v33; // ecx
	unsigned int v34; // eax
	unsigned __int16 v35; // dx
	char v36; // cl
	int v37; // ebp
	int v38; // edi
	int v39; // esi
	int v40; // eax
	int v41; // esi
	int v42; // edi
	int v43; // ecx
	int v44; // esi
	int v45; // eax
	bool v46; // zf
	int v47; // edi
	int v48; // esi
	int v49; // eax
	int v50; // edi
	_BYTE *v51; // eax
	int v52; // edx
	int v53; // edi
	_BYTE *v54; // edx
	int v55; // eax
	int v56; // [esp+4h] [ebp-Ch]
	int v57; // [esp+4h] [ebp-Ch]
	unsigned int v58; // [esp+4h] [ebp-Ch]
	unsigned int v59; // [esp+8h] [ebp-8h]
	unsigned int v60; // [esp+Ch] [ebp-4h]
	unsigned int v61; // [esp+1Ch] [ebp+Ch]
	int v62; // [esp+24h] [ebp+14h]
	int v63; // [esp+24h] [ebp+14h]
	int v64; // [esp+24h] [ebp+14h]
	int v65; // [esp+24h] [ebp+14h]
	unsigned int v66; // [esp+24h] [ebp+14h]

	result = a5 * a4;
	v7 = a3;
	v61 = 0;
	v59 = (unsigned int)v7;
	v60 = a5 * a4;
	if (a5 * a4)
	{
		v8 = a6;
		do
		{
			v9 = *a2;
			if (((*a2 >> 8) & 0x80u) == 0)
			{
				v53 = 2;
				v54 = (_BYTE *)(a1 + 8 * *a2);
				do
				{
					v55 = 4;
					do
					{
						*v7++ = *v54++;
						--v55;
					} while (v55);
					--v53;
					v7 = &v7[v8 - 4];
				} while (v53);
				v7 += 2 * (2 - v8);
				goto LABEL_75;
			}
			v10 = *a2;
			v11 = v9 & 0xF000;
			if (v11 > 49152)
			{
				if (v11 == 57344)
				{
					v50 = 2;
					v51 = (_BYTE *)(a1 + 8 * (v9 & 0xFFF));
					do
					{
						v52 = 4;
						do
						{
							if (*v51)
								*v7 = *v51;
							++v7;
							++v51;
							--v52;
						} while (v52);
						--v50;
						v7 = &v7[v8 - 4];
					} while (v50);
					++a2;
					v7 += 2 * (2 - v8);
					goto LABEL_76;
				}
				if (v11 == 61440)
				{
					if ((_BYTE)v9)
					{
						v47 = 2;
						do
						{
							v48 = (int)(v7 + 4);
							LOBYTE(v11) = v9;
							BYTE1(v11) = v9;
							v49 = v11 << 16;
							LOWORD(v49) = v11;
							*(_DWORD *)(v48 - 4) = v49;
							v7 = (_BYTE *)(v8 - 4 + v48);
							--v47;
						} while (v47);
						v7 -= 2 * v8;
					}
					v7 += 4;
				LABEL_75:
					++a2;
				LABEL_76:
					v30 = v61 + 1;
					goto LABEL_77;
				}
			}
			else
			{
				if (v11 == 49152)
				{
					v31 = v9 & 0xFFF;
					v32 = a2 + 1;
					v33 = v31;
					++a2;
					v34 = v31 >> 1;
					v66 = v33;
					if (v34)
					{
						v58 = v34;
						do
						{
							v35 = *v32;
							v36 = *v32 >> 8;
							if (v36)
							{
								v37 = v8 - 4;
								v38 = 2;
								do
								{
									v39 = (int)(v7 + 4);
									LOBYTE(v8) = v36;
									BYTE1(v8) = v36;
									v40 = v8 << 16;
									LOWORD(v40) = v8;
									*(_DWORD *)(v39 - 4) = v40;
									v7 = (_BYTE *)(v37 + v39);
									--v38;
								} while (v38);
								v8 = a6;
								v7 -= 2 * a6;
							}
							v41 = (int)(v7 + 4);
							if ((_BYTE)v35)
							{
								v42 = v8 - 4;
								v43 = 2;
								do
								{
									v44 = v41 + 4;
									LOBYTE(v8) = v35;
									BYTE1(v8) = v35;
									v45 = v8 << 16;
									LOWORD(v45) = v8;
									*(_DWORD *)(v44 - 4) = v45;
									v41 = v42 + v44;
									--v43;
								} while (v43);
								v8 = a6;
								v41 -= 2 * a6;
							}
							v7 = (_BYTE *)(v41 + 4);
							v32 = a2 + 1;
							v46 = v58 == 1;
							++a2;
							--v58;
						} while (!v46);
						v33 = v66;
					}
					v30 = v33 + v61;
					goto LABEL_77;
				}
				if (v11 != 40960)
				{
					if (v11 == 45056)
					{
						v12 = (v9 >> 8) & 0xF;
						v62 = (v9 >> 8) & 0xF;
						if ((_BYTE)v9)
						{
							v13 = 4 * v12;
							v56 = 2;
							do
							{
								if (v13)
								{
									v14 = v13;
									LOBYTE(v8) = v9;
									BYTE1(v8) = v9;
									v15 = v8 << 16;
									LOWORD(v15) = v8;
									v8 = a6;
									v16 = v13 >> 2;
									memset32(v7, v15, v16);
									memset(&v7[4 * v16], v15, v14 & 3);
									v12 = (v9 >> 8) & 0xF;
									v13 = 4 * v62;
									v7 += 4 * v62;
								}
								v7 += v8 - v13;
								--v56;
							} while (v56);
							v7 -= 2 * v8;
						}
						v7 += 4 * v12;
						v61 += v12;
						++a2;
					}
					goto LABEL_78;
				}
				v17 = a2[1];
				++a2;
				v18 = v10 & 0xFFF;
				v63 = v10 & 0xFFF;
				if ((v17 & 0x8000u) == 0)
				{
					v65 = 2;
					v27 = (_BYTE *)(a1 + 8 * v17);
					do
					{
						if (v18)
						{
							v28 = v18;
							do
							{
								v29 = 4;
								do
								{
									*v7++ = *v27++;
									--v29;
								} while (v29);
								v27 -= 4;
								--v28;
							} while (v28);
						}
						v27 += 4;
						v7 += v8 - 4 * v18;
						--v65;
					} while (v65);
				LABEL_42:
					++a2;
					v7 += 2 * (2 * v18 - v8);
					v30 = v18 + v61;
				LABEL_77:
					v61 = v30;
					goto LABEL_78;
				}
				v19 = v17 & 0xC000;
				if (v19 == 0x8000)
				{
					if ((_BYTE)v17)
					{
						v23 = 4 * v18;
						v57 = 2;
						do
						{
							if (v23)
							{
								v24 = v23;
								LOBYTE(v8) = v17;
								BYTE1(v8) = v17;
								v25 = v8 << 16;
								LOWORD(v25) = v8;
								v8 = a6;
								v26 = v23 >> 2;
								memset32(v7, v25, v26);
								memset(&v7[4 * v26], v25, v24 & 3);
								v18 = v63;
								v23 = 4 * v63;
								v7 += 4 * v63;
							}
							v7 += v8 - v23;
							--v57;
						} while (v57);
						v7 -= 2 * v8;
					}
					v7 += 4 * v18;
					v61 += v18;
					++a2;
					goto LABEL_78;
				}
				if (v19 == 49152)
				{
					v64 = 2;
					v20 = (_BYTE *)(a1 + 8 * (v17 & 0xFFF));
					do
					{
						if (v10 & 0xFFF)
						{
							v21 = v10 & 0xFFF;
							do
							{
								v22 = 4;
								do
								{
									if (*v20)
										*v7 = *v20;
									++v7;
									++v20;
									--v22;
								} while (v22);
								v20 -= 4;
								--v21;
							} while (v21);
						}
						v20 += 4;
						v7 += v8 - 4 * v18;
						--v64;
					} while (v64);
					goto LABEL_42;
				}
			}
		LABEL_78:
			result = v61 / a4;
			if (!(v61 % a4))
			{
				result = v59;
				v7 = (_BYTE *)(v59 + 2 * v8);
				v59 += 2 * v8;
			}
		} while (v61 < v60);
	}
	return result;
}

//----- (005640C0) --------------------------------------------------------
unsigned int __cdecl sub_5640C0(int a1, unsigned __int16 *a2, _BYTE *a3, unsigned int a4, int a5, int a6)
{
	unsigned int result; // eax
	unsigned __int16 *v7; // ebp
	_BYTE *v8; // esi
	int v9; // ebx
	unsigned __int16 v10; // dx
	int v11; // eax
	int v12; // ecx
	int v13; // eax
	unsigned int v14; // ebp
	int v15; // eax
	_BYTE *v16; // edi
	unsigned __int16 v17; // dx
	int v18; // edi
	int v19; // ecx
	_BYTE *v20; // eax
	int v21; // ebp
	int v22; // ecx
	unsigned int v23; // ecx
	char v24; // bp
	int v25; // eax
	unsigned int v26; // ecx
	_BYTE *v27; // eax
	int v28; // edx
	int v29; // ebp
	int v30; // ecx
	int v31; // eax
	unsigned int v32; // eax
	int v33; // ebp
	int v34; // edi
	unsigned __int16 v35; // dx
	char v36; // cl
	int v37; // esi
	int v38; // eax
	int v39; // edi
	int v40; // ecx
	int v41; // esi
	int v42; // esi
	int v43; // eax
	bool v44; // zf
	int v45; // edi
	int v46; // esi
	int v47; // ecx
	int v48; // edi
	_BYTE *v49; // eax
	int v50; // ecx
	int v51; // edi
	_BYTE *v52; // eax
	int v53; // ecx
	int v54; // [esp+8h] [ebp-10h]
	int v55; // [esp+8h] [ebp-10h]
	unsigned int v56; // [esp+8h] [ebp-10h]
	_BYTE *v57; // [esp+Ch] [ebp-Ch]
	char v58; // [esp+10h] [ebp-8h]
	unsigned int v59; // [esp+14h] [ebp-4h]
	unsigned int v60; // [esp+24h] [ebp+Ch]
	int v61; // [esp+2Ch] [ebp+14h]
	int v62; // [esp+2Ch] [ebp+14h]
	int v63; // [esp+2Ch] [ebp+14h]
	unsigned int v64; // [esp+2Ch] [ebp+14h]

	result = a5 * a4;
	v7 = a2;
	v8 = a3;
	v57 = a3;
	v60 = 0;
	v59 = a5 * a4;
	if (a5 * a4)
	{
		v9 = a6;
		while (1)
		{
			v10 = *v7;
			v58 = *v7;
			if (((*v7 >> 8) & 0x80u) == 0)
				break;
			v11 = v10;
			v12 = v10 & 0xF000;
			if (v12 > 49152)
			{
				if (v12 != 57344)
				{
					if (v12 != 61440)
						goto LABEL_66;
					v45 = 2;
					do
					{
						v46 = (int)(v8 + 4);
						LOBYTE(v11) = v10;
						BYTE1(v11) = v10;
						v47 = v11 << 16;
						LOWORD(v47) = v11;
						*(_DWORD *)(v46 - 4) = v47;
						v8 = (_BYTE *)(v9 - 4 + v46);
						--v45;
					} while (v45);
					v8 += 2 * (2 - v9);
					goto LABEL_64;
				}
				v48 = 2;
				v49 = (_BYTE *)(a1 + 8 * (v10 & 0xFFF));
				do
				{
					v50 = 4;
					do
					{
						*v8++ = *v49++;
						--v50;
					} while (v50);
					--v48;
					v8 = &v8[v9 - 4];
				} while (v48);
			LABEL_63:
				v8 += 2 * (2 - v9);
			LABEL_64:
				v31 = v60 + 1;
				++a2;
				goto LABEL_65;
			}
			switch (v12)
			{
			case 49152:
				v32 = v10 & 0xFFF;
				v64 = v32;
				a2 = v7 + 1;
				if (v32 >> 1)
				{
					v33 = v9 - 4;
					v56 = v32 >> 1;
					do
					{
						v34 = 2;
						v35 = *a2;
						v36 = *a2 >> 8;
						do
						{
							v37 = (int)(v8 + 4);
							LOBYTE(v9) = v36;
							BYTE1(v9) = v36;
							v38 = v9 << 16;
							LOWORD(v38) = v9;
							*(_DWORD *)(v37 - 4) = v38;
							v8 = (_BYTE *)(v33 + v37);
							--v34;
						} while (v34);
						HIWORD(v9) = HIWORD(a6);
						v39 = 2;
						v40 = 2 * (2 - a6);
						v41 = (int)&v8[v40];
						do
						{
							v42 = v41 + 4;
							LOBYTE(v9) = v35;
							BYTE1(v9) = v35;
							v43 = v9 << 16;
							LOWORD(v43) = v9;
							*(_DWORD *)(v42 - 4) = v43;
							v41 = v33 + v42;
							--v39;
						} while (v39);
						v8 = (_BYTE *)(v40 + v41);
						v44 = v56 == 1;
						++a2;
						--v56;
					} while (!v44);
					v32 = v64;
					v9 = a6;
				}
				v60 += v32;
				break;
			case 40960:
				v17 = v7[1];
				a2 = v7 + 1;
				v18 = v11 & 0xFFF;
				v62 = v11 & 0xFFF;
				if ((v17 & 0x8000u) == 0)
				{
					v27 = (_BYTE *)(a1 + 8 * v7[1]);
					v28 = 2;
					do
					{
						if (v18)
						{
							v29 = v18;
							do
							{
								v30 = 4;
								do
								{
									*v8++ = *v27++;
									--v30;
								} while (v30);
								v27 -= 4;
								--v29;
							} while (v29);
							v9 = a6;
						}
						v27 += 4;
						v8 += v9 - 4 * v18;
						--v28;
					} while (v28);
					v8 += 2 * (2 * v18 - v9);
					goto LABEL_39;
				}
				v19 = v17 & 0xC000;
				if (v19 != 0x8000)
				{
					if (v19 != 49152)
						break;
					v63 = 2;
					v20 = (_BYTE *)(a1 + 8 * (v17 & 0xFFF));
					do
					{
						if (v18)
						{
							v21 = v18;
							do
							{
								v22 = 4;
								do
								{
									*v8++ = *v20++;
									--v22;
								} while (v22);
								v20 -= 4;
								--v21;
							} while (v21);
						}
						v20 += 4;
						v8 += v9 - 4 * v18;
						--v63;
					} while (v63);
					v8 += 2 * (2 * v18 - v9);
				LABEL_39:
					v31 = v18 + v60;
					++a2;
				LABEL_65:
					v60 = v31;
					break;
				}
				v23 = 4 * v18;
				v55 = 2;
				do
				{
					if (v23)
					{
						v24 = v23;
						LOBYTE(v9) = v17;
						BYTE1(v9) = v17;
						v25 = v9 << 16;
						LOWORD(v25) = v9;
						v9 = a6;
						v26 = v23 >> 2;
						memset32(v8, v25, v26);
						memset(&v8[4 * v26], v25, v24 & 3);
						v18 = v62;
						v23 = 4 * v62;
						v8 += 4 * v62;
					}
					v8 += v9 - v23;
					--v55;
				} while (v55);
				v8 += 2 * (2 * v18 - v9);
				v60 += v18;
				++a2;
				break;
			case 45056:
				v13 = (v10 >> 8) & 0xF;
				v54 = 2;
				v61 = v13;
				v14 = 4 * v13;
				do
				{
					if (v14)
					{
						LOBYTE(v9) = v10;
						BYTE1(v9) = v10;
						v15 = v9 << 16;
						LOWORD(v15) = v9;
						v9 = a6;
						memset32(v8, v15, v14 >> 2);
						v16 = &v8[4 * (v14 >> 2)];
						LOBYTE(v10) = v58;
						v8 += v14;
						memset(v16, v15, v14 & 3);
						v13 = v61;
					}
					v8 += v9 - v14;
					--v54;
				} while (v54);
				v60 += v13;
				++a2;
				v8 += 2 * (2 * v13 - v9);
				break;
			}
		LABEL_66:
			result = v60 / a4;
			if (!(v60 % a4))
			{
				v8 = &v57[2 * v9];
				v57 += 2 * v9;
			}
			if (v60 >= v59)
				return result;
			v7 = a2;
		}
		v51 = 2;
		v52 = (_BYTE *)(a1 + 8 * *v7);
		do
		{
			v53 = 4;
			do
			{
				*v8++ = *v52++;
				--v53;
			} while (v53);
			--v51;
			v8 = &v8[v9 - 4];
		} while (v51);
		goto LABEL_63;
	}
	return result;
}

//----- (005644B0) --------------------------------------------------------
__int16 __cdecl sub_5644B0(int a1, _BYTE *a2, int *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	int *v7; // edi
	int v8; // ecx
	int v9; // ebx
	int *v10; // ebx
	int v11; // eax
	int v12; // edx
	int v14; // [esp+8h] [ebp-Ch]
	int *v15; // [esp+Ch] [ebp-8h]
	_BYTE *v16; // [esp+10h] [ebp-4h]

	v14 = 2 * a6;
	v6 = a2;
	v16 = &a2[a4 * a5];
	v7 = a3;
	v15 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				BYTE1(v9) = v6[a4 * a5];
				LOBYTE(v9) = *v6++;
				if (BYTE1(v9) == 0xFF)
					break;
				v10 = (int *)(a1 + 8 * v9);
				v11 = *v10;
				v12 = v10[1];
				*v7 = *v10;
				*(int *)((char *)v7 + a6) = v12;
				++v7;
				if (!--v8)
				{
					v7 = (int *)((char *)v15 + v14);
					v15 = (int *)((char *)v15 + v14);
					if (v6 >= v16)
						return v11;
					goto LABEL_2;
				}
			}
			BYTE1(v9) = v9;
			v11 = __ROL4__(a4 * a5, 16);
			LOWORD(v11) = v9;
			*v7 = v11;
			*(int *)((char *)v7 + a6) = v11;
			++v7;
			--v8;
		} while (v8);
		v7 = (int *)((char *)v15 + v14);
		v15 = (int *)((char *)v15 + v14);
	} while (v6 < v16);
	return v11;
}

//----- (00564546) --------------------------------------------------------
__int16 __cdecl sub_564546(int a1, _BYTE *a2, _DWORD *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	_DWORD *v7; // edi
	int v8; // ecx
	int v9; // ebx
	_DWORD *v10; // ebx
	int v11; // edx
	int v12; // eax
	int v13; // edx
	int v15; // [esp+8h] [ebp-Ch]
	_DWORD *v16; // [esp+Ch] [ebp-8h]
	_BYTE *v17; // [esp+10h] [ebp-4h]

	v15 = a6;
	v6 = a2;
	v17 = &a2[a4 * a5];
	v7 = a3;
	v16 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				BYTE1(v9) = v6[a4 * a5];
				LOBYTE(v9) = *v6++;
				if (BYTE1(v9) == 0xFF)
					break;
				v10 = (_DWORD *)(a1 + 16 * v9);
				v11 = v10[1];
				*v7 = *v10;
				*(_DWORD *)((char *)v7 + a6) = v11;
				v12 = v10[2];
				v13 = v10[3];
				*(_DWORD *)((char *)v7 + 2 * a6) = v12;
				*(_DWORD *)((char *)v7 + 3 * a6) = v13;
				++v7;
				if (!--v8)
				{
					v7 = &v16[v15];
					v16 = (_DWORD *)((char *)v16 + v15 * 4);
					if (v6 >= v17)
						return v12;
					goto LABEL_2;
				}
			}
			BYTE1(v9) = v9;
			v12 = __ROL4__(a4 * a5, 16);
			LOWORD(v12) = v9;
			*v7 = v12;
			*(_DWORD *)((char *)v7 + a6) = v12;
			*(_DWORD *)((char *)v7 + 2 * a6) = v12;
			*(_DWORD *)((char *)v7 + 3 * a6) = v12;
			++v7;
			--v8;
		} while (v8);
		v7 = &v16[v15];
		v16 = (_DWORD *)((char *)v16 + v15 * 4);
	} while (v6 < v17);
	return v12;
}

//----- (00564604) --------------------------------------------------------
__int16 __cdecl sub_564604(int a1, _BYTE *a2, _WORD *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	_WORD *v7; // edi
	int v8; // ecx
	int v9; // ebx
	_BYTE *v10; // ebx
	__int16 v11; // ax
	__int16 result; // ax
	int v13; // [esp+8h] [ebp-Ch]
	_WORD *v14; // [esp+Ch] [ebp-8h]
	_BYTE *v15; // [esp+10h] [ebp-4h]

	v13 = a6;
	v6 = a2;
	v15 = &a2[a4 * a5];
	v7 = a3;
	v14 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				BYTE1(v9) = v6[a4 * a5];
				LOBYTE(v9) = *v6++;
				if (BYTE1(v9) == 0xFF)
					break;
				v10 = (_BYTE *)(a1 + 16 * v9);
				LOBYTE(v11) = *v10;
				HIBYTE(v11) = v10[2];
				*v7 = v11;
				LOBYTE(result) = v10[8];
				HIBYTE(result) = v10[10];
				*(_WORD *)((char *)v7 + a6) = result;
				++v7;
				if (!--v8)
				{
					v7 = &v14[v13];
					v14 = (_WORD *)((char *)v14 + v13 * 2);
					if (v6 >= v15)
						return result;
					goto LABEL_2;
				}
			}
			BYTE1(v9) = v9;
			result = v9;
			*v7 = v9;
			*(_WORD *)((char *)v7 + a6) = v9;
			++v7;
			--v8;
		} while (v8);
		v7 = &v14[v13];
		v14 = (_WORD *)((char *)v14 + v13 * 2);
	} while (v6 < v15);
	return result;
}

//----- (0056469E) --------------------------------------------------------
__int16 __cdecl sub_56469E(int a1, _BYTE *a2, _WORD *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	_WORD *v7; // edi
	int v8; // ecx
	int v9; // ebx
	_BYTE *v10; // ebx
	__int16 v11; // ax
	__int16 result; // ax
	int v13; // [esp+8h] [ebp-Ch]
	_WORD *v14; // [esp+Ch] [ebp-8h]
	_BYTE *v15; // [esp+10h] [ebp-4h]

	v13 = a6;
	v6 = a2;
	v15 = &a2[a4 * a5];
	v7 = a3;
	v14 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				BYTE1(v9) = v6[a4 * a5];
				LOBYTE(v9) = *v6++;
				if (BYTE1(v9) == 0xFF)
					break;
				v10 = (_BYTE *)(a1 + 8 * v9);
				LOBYTE(v11) = *v10;
				HIBYTE(v11) = v10[2];
				*v7 = v11;
				LOBYTE(result) = v10[8];
				HIBYTE(result) = v10[10];
				*(_WORD *)((char *)v7 + a6) = result;
				++v7;
				if (!--v8)
				{
					v7 = &v14[v13];
					v14 = (_WORD *)((char *)v14 + v13 * 2);
					if (v6 >= v15)
						return result;
					goto LABEL_2;
				}
			}
			BYTE1(v9) = v9;
			result = v9;
			*v7 = v9;
			*(_WORD *)((char *)v7 + a6) = v9;
			++v7;
			--v8;
		} while (v8);
		v7 = &v14[v13];
		v14 = (_WORD *)((char *)v14 + v13 * 2);
	} while (v6 < v15);
	return result;
}

//----- (00564738) --------------------------------------------------------
__int16 __cdecl sub_564738(int a1, _BYTE *a2, int *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	int *v7; // edi
	int v8; // ecx
	int v9; // ebx
	int *v10; // ebx
	int v11; // edx
	int v12; // edx
	int v13; // edx
	int v14; // ebx
	int v15; // eax
	int v16; // edx
	int v17; // ebx
	int v18; // ebx
	int v19; // ebx
	int *v21; // [esp+8h] [ebp-10h]
	int v22; // [esp+Ch] [ebp-Ch]
	int *v23; // [esp+10h] [ebp-8h]
	_BYTE *v24; // [esp+14h] [ebp-4h]
	int v25; // [esp+34h] [ebp+1Ch]

	v25 = 2 * a6;
	v22 = v25;
	v6 = a2;
	v24 = &a2[a4 * a5];
	v7 = a3;
	v23 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				BYTE1(v9) = v6[a4 * a5];
				LOBYTE(v9) = *v6++;
				if ((BYTE1(v9) & 0x80 & 0x80u) != 0)
					break;
				v10 = (int *)(a1 + 32 * v9);
				v11 = v10[1];
				*v7 = *v10;
				v7[1] = v11;
				v12 = v10[3];
				v21 = v10;
				*(int *)((char *)v7 + v25) = v10[2];
				*(int *)((char *)v7 + v25 + 4) = v12;
				v13 = v10[5];
				v14 = 2 * v25;
				*(int *)((char *)v7 + v14) = v21[4];
				*(int *)((char *)v7 + v14 + 4) = v13;
				v15 = v21[6];
				v16 = v21[7];
				v17 = 3 * v25;
				*(int *)((char *)v7 + v17) = v15;
				*(int *)((char *)v7 + v17 + 4) = v16;
				v7 += 2;
				if (!--v8)
				{
					v7 = &v23[v22];
					v23 = (int *)((char *)v23 + v22 * 4);
					if (v6 >= v24)
						return v15;
					goto LABEL_2;
				}
			}
			v15 = (a4 * a5) << 16;
			LOWORD(v15) = v9 & 0x7FFF;
			*v7 = v15;
			v7[1] = v15;
			*(int *)((char *)v7 + v25) = v15;
			*(int *)((char *)v7 + v25 + 4) = v15;
			v18 = 2 * v25;
			*(int *)((char *)v7 + v18) = v15;
			*(int *)((char *)v7 + v18 + 4) = v15;
			v19 = 3 * v25;
			*(int *)((char *)v7 + v19) = v15;
			*(int *)((char *)v7 + v19 + 4) = v15;
			v7 += 2;
			--v8;
		} while (v8);
		v7 = &v23[v22];
		v23 = (int *)((char *)v23 + v22 * 4);
	} while (v6 < v24);
	return v15;
}

//----- (00564834) --------------------------------------------------------
__int16 __cdecl sub_564834(int a1, _BYTE *a2, int *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	int *v7; // edi
	int v8; // ecx
	int v9; // ebx
	int *v10; // ebx
	int v11; // edx
	int v12; // eax
	int v13; // edx
	int v15; // [esp+Ch] [ebp-Ch]
	int *v16; // [esp+10h] [ebp-8h]
	_BYTE *v17; // [esp+14h] [ebp-4h]
	int v18; // [esp+34h] [ebp+1Ch]

	v18 = 2 * a6;
	v15 = 2 * v18;
	v6 = a2;
	v17 = &a2[a4 * a5];
	v7 = a3;
	v16 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				BYTE1(v9) = v6[a4 * a5];
				LOBYTE(v9) = *v6++;
				if ((BYTE1(v9) & 0x80 & 0x80u) != 0)
					break;
				v10 = (int *)(a1 + 16 * v9);
				v11 = v10[1];
				*v7 = *v10;
				v7[1] = v11;
				v12 = v10[2];
				v13 = v10[3];
				*(int *)((char *)v7 + v18) = v12;
				*(int *)((char *)v7 + v18 + 4) = v13;
				v7 += 2;
				if (!--v8)
				{
					v7 = (int *)((char *)v16 + v15);
					v16 = (int *)((char *)v16 + v15);
					if (v6 >= v17)
						return v12;
					goto LABEL_2;
				}
			}
			v12 = (a4 * a5) << 16;
			LOWORD(v12) = v9 & 0x7FFF;
			*v7 = v12;
			v7[1] = v12;
			*(int *)((char *)v7 + v18) = v12;
			*(int *)((char *)v7 + v18 + 4) = v12;
			v7 += 2;
			--v8;
		} while (v8);
		v7 = (int *)((char *)v16 + v15);
		v16 = (int *)((char *)v16 + v15);
	} while (v6 < v17);
	return v12;
}

//----- (005648E4) --------------------------------------------------------
__int16 __cdecl sub_5648E4(int a1, _BYTE *a2, _DWORD *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	_DWORD *v7; // edi
	int v8; // ecx
	int v9; // ebx
	_DWORD *v10; // ebx
	int v11; // eax
	int v13; // [esp+8h] [ebp-Ch]
	_DWORD *v14; // [esp+Ch] [ebp-8h]
	_BYTE *v15; // [esp+10h] [ebp-4h]

	v13 = 2 * a6;
	v6 = a2;
	v15 = &a2[a4 * a5];
	v7 = a3;
	v14 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				LOBYTE(v9) = *v6;
				BYTE1(v9) = (v6++)[a4 * a5];
				if (BYTE1(v9) == 0xFF)
					break;
				v10 = (_DWORD *)(a1 + 32 * v9);
				*v7 = *v10;
				*(_DWORD *)((char *)v7 + a6) = v10[1];
				*(_DWORD *)((char *)v7 + 2 * a6) = v10[2];
				*(_DWORD *)((char *)v7 + 3 * a6) = v10[3];
				v7[a6] = v10[4];
				*(_DWORD *)((char *)v7 + 5 * a6) = v10[5];
				*(_DWORD *)((char *)v7 + 6 * a6) = v10[6];
				v11 = v10[7];
				*(_DWORD *)((char *)v7 + 7 * a6) = v11;
				++v7;
				if (!--v8)
				{
					v7 = &v14[v13];
					v14 = (_DWORD *)((char *)v14 + v13 * 4);
					if (v6 >= v15)
						return v11;
					goto LABEL_2;
				}
			}
			BYTE1(v9) = v9;
			v11 = __ROL4__(a4 * a5, 16);
			LOWORD(v11) = v9;
			*v7 = v11;
			*(_DWORD *)((char *)v7 + a6) = v11;
			*(_DWORD *)((char *)v7 + 2 * a6) = v11;
			*(_DWORD *)((char *)v7 + 3 * a6) = v11;
			v7[a6] = v11;
			*(_DWORD *)((char *)v7 + 5 * a6) = v11;
			*(_DWORD *)((char *)v7 + 6 * a6) = v11;
			*(_DWORD *)((char *)v7 + 7 * a6) = v11;
			++v7;
			--v8;
		} while (v8);
		v7 = &v14[v13];
		v14 = (_DWORD *)((char *)v14 + v13 * 4);
	} while (v6 < v15);
	return v11;
}

//----- (005649DA) --------------------------------------------------------
__int16 __cdecl sub_5649DA(int a1, _BYTE *a2, _DWORD *a3, int a4, int a5, int a6)
{
	_BYTE *v6; // esi
	_DWORD *v7; // edi
	int v8; // ecx
	int v9; // ebx
	_DWORD *v10; // ebx
	int v11; // edx
	int v12; // edx
	int v13; // eax
	int v14; // ebx
	int v15; // ebx
	int v17; // [esp+8h] [ebp-Ch]
	_DWORD *v18; // [esp+Ch] [ebp-8h]
	_BYTE *v19; // [esp+10h] [ebp-4h]

	v17 = a6;
	v6 = a2;
	v19 = &a2[a4 * a5];
	v7 = a3;
	v18 = a3;
	do
	{
	LABEL_2:
		v8 = a4;
		do
		{
			while (1)
			{
				HIWORD(v9) = 0;
				LOBYTE(v9) = *v6;
				BYTE1(v9) = (v6++)[a4 * a5];
				if (BYTE1(v9) == 0xFF)
					break;
				v10 = (_DWORD *)(a1 + 32 * v9);
				*v7 = *v10;
				v7[1] = v10[1];
				*(_DWORD *)((char *)v7 + a6) = v10[2];
				*(_DWORD *)((char *)v7 + a6 + 4) = v10[3];
				v11 = 2 * a6;
				*(_DWORD *)((char *)v7 + v11) = v10[4];
				*(_DWORD *)((char *)v7 + v11 + 4) = v10[5];
				v12 = 3 * a6;
				*(_DWORD *)((char *)v7 + v12) = v10[6];
				v13 = v10[7];
				*(_DWORD *)((char *)v7 + v12 + 4) = v13;
				v7 += 2;
				if (!--v8)
				{
					v7 = &v18[v17];
					v18 = (_DWORD *)((char *)v18 + v17 * 4);
					if (v6 >= v19)
						return v13;
					goto LABEL_2;
				}
			}
			BYTE1(v9) = v9;
			v13 = __ROL4__(a4 * a5, 16);
			LOWORD(v13) = v9;
			*v7 = v13;
			v7[1] = v13;
			*(_DWORD *)((char *)v7 + a6) = v13;
			*(_DWORD *)((char *)v7 + a6 + 4) = v13;
			v14 = 2 * a6;
			*(_DWORD *)((char *)v7 + v14) = v13;
			*(_DWORD *)((char *)v7 + v14 + 4) = v13;
			v15 = 3 * a6;
			*(_DWORD *)((char *)v7 + v15) = v13;
			*(_DWORD *)((char *)v7 + v15 + 4) = v13;
			v7 += 2;
			--v8;
		} while (v8);
		v7 = &v18[v17];
		v18 = (_DWORD *)((char *)v18 + v17 * 4);
	} while (v6 < v19);
	return v13;
}

//----- (00564AC0) --------------------------------------------------------
int *__cdecl sub_564AC0(int a1, unsigned __int16 *a2, int *a3, int a4, int a5, int a6)
{
	unsigned int v6; // edi
	int *result; // eax
	unsigned __int16 *v8; // ebx
	int *v9; // ebp
	int *v10; // ecx
	int v11; // eax
	int v12; // esi
	int v13; // eax
	unsigned int v14; // esi
	int *v15; // eax
	int v16; // ecx
	int *v17; // eax
	int *v18; // edx
	unsigned int v19; // edi
	int v20; // ecx
	_DWORD *v21; // edx
	unsigned int v22; // edi
	unsigned int v23; // edx
	unsigned __int16 v24; // cx
	int v25; // eax
	unsigned int v26; // ecx
	__int16 *v27; // edi
	int *v28; // ebx
	int v29; // ebp
	__int16 v30; // cx
	int *v31; // eax
	unsigned int v32; // edx
	bool v33; // zf
	int v34; // esi
	_WORD *v35; // eax
	int *v36; // ebx
	int *v37; // edx
	int v38; // edi
	int v39; // edi
	int v40; // esi
	unsigned __int16 *v41; // eax
	int *v42; // edx
	unsigned __int16 v43; // cx
	unsigned __int16 v44; // bx
	unsigned __int16 *v45; // eax
	unsigned __int16 v46; // cx
	unsigned __int16 v47; // bx
	int v48; // edi
	int v49; // edx
	int v50; // eax
	int *v51; // ecx
	int *v52; // [esp+Ch] [ebp-Ch]
	int *v53; // [esp+10h] [ebp-8h]
	int *v54; // [esp+14h] [ebp-4h]
	int v55; // [esp+20h] [ebp+8h]
	int v56; // [esp+24h] [ebp+Ch]
	int v57; // [esp+24h] [ebp+Ch]
	int v58; // [esp+24h] [ebp+Ch]
	int *v59; // [esp+2Ch] [ebp+14h]
	int v60; // [esp+2Ch] [ebp+14h]
	unsigned int v61; // [esp+2Ch] [ebp+14h]
	unsigned int v62; // [esp+2Ch] [ebp+14h]
	unsigned int v63; // [esp+30h] [ebp+18h]

	v6 = 2 * a6;
	result = a3;
	v8 = a2;
	v9 = a3;
	v10 = &a3[2 * a6 * a5];
	v63 = 2 * a6;
	v54 = v10;
	v52 = a3;
	v53 = &a3[2 * a4];
	v59 = a3;
	if (a3 < v10)
	{
		do
		{
			LOWORD(v11) = *v8;
			++v8;
			v11 = (unsigned __int16)v11;
			v12 = v11;
			v13 = v11 & 0xF000;
			v14 = v12 & 0xFFFF0FFF;
			if (v13 > 12288)
			{
				if (v13 != 20480)
				{
					if (v13 == 24576)
					{
						if (v14)
						{
							v39 = 4 * (v6 >> 2);
							v62 = v14;
							while (1)
							{
								v40 = 4;
								v41 = (unsigned __int16 *)(a1 + 32 * *v8);
								v58 = (int)(v8 + 1);
								v42 = v9;
								do
								{
									v43 = v41[1];
									v44 = *v41;
									v45 = v41 + 2;
									*v42 = v44 | (v43 << 16);
									v46 = v45[1];
									v47 = *v45;
									v41 = v45 + 2;
									v42[1] = v47 | (v46 << 16);
									v42 = (int *)((char *)v42 + v39);
									--v40;
								} while (v40);
								v9 += 2;
								if (!--v62)
									break;
								v8 = (unsigned __int16 *)v58;
							}
							v8 = (unsigned __int16 *)v58;
							v59 = v9;
						}
					}
					else if (v13 == 28672 && v14)
					{
						v61 = v14;
						while (1)
						{
							v34 = 4;
							v35 = (_WORD *)(a1 + 32 * *v8);
							v57 = (int)(v8 + 1);
							v36 = v9;
							do
							{
								v37 = v36;
								v38 = 4;
								do
								{
									if (((*v35 >> 8) & 0x80u) == 0)
										*(_WORD *)v37 = *v35;
									v37 = (int *)((char *)v37 + 2);
									++v35;
									--v38;
								} while (v38);
								--v34;
								v36 = (int *)((char *)v36 + 2 * (v63 >> 1));
							} while (v34);
							v9 += 2;
							if (!--v61)
								break;
							v8 = (unsigned __int16 *)v57;
						}
						v8 = (unsigned __int16 *)v57;
						v59 = v9;
					}
					goto LABEL_63;
				}
				if (v14)
				{
					v48 = 4 * (v6 >> 2);
					do
					{
						v49 = 4;
						v50 = *v8 | (*v8 << 16);
						++v8;
						v51 = v9;
						do
						{
							*v51 = v50;
							v51[1] = v50;
							v51 = (int *)((char *)v51 + v48);
							--v49;
						} while (v49);
						v9 += 2;
						--v14;
					} while (v14);
				LABEL_62:
					v59 = v9;
					goto LABEL_63;
				}
			}
			else
			{
				switch (v13)
				{
				case 12288:
					v55 = 4;
					v27 = (__int16 *)(a1 + 32 * *v8);
					v56 = (int)(v8 + 1);
					while (1)
					{
						v28 = v9;
						v29 = 4;
						do
						{
							v30 = *v27;
							if ((((unsigned __int16)*v27 >> 8) & 0x80u) == 0)
							{
								v31 = v28;
								if (v14)
								{
									v32 = v14;
									do
									{
										*(_WORD *)v31 = v30;
										v31 += 2;
										--v32;
									} while (v32);
								}
							}
							v28 = (int *)((char *)v28 + 2);
							++v27;
							--v29;
						} while (v29);
						v33 = v55 == 1;
						v59 = (int *)((char *)v59 + v63);
						--v55;
						if (v33)
							break;
						v9 = v59;
					}
					v8 = (unsigned __int16 *)v56;
					v59 = (int *)((char *)v59 + 8 * v14 - 4 * v63);
					v9 = v59;
					break;
				case 0:
					v23 = 2 * v14;
					v24 = *v8;
					++v8;
					v25 = v24 | (v24 << 16);
					if (2 * v14)
						memset32(v9, v24 | (v24 << 16), v23);
					if (v23)
						memset32((char *)v9 + v63, v24 | (v24 << 16), v23);
					v26 = v63;
					if (v23)
					{
						memset32(&v9[v63 / 2], v25, v23);
						v26 = v63;
					}
					if (v23)
						memset32((char *)v9 + 2 * v26 + v26, v25, v23);
					v59 = &v9[2 * v14];
					v9 += 2 * v14;
					break;
				case 4096:
					v59 = &v9[2 * v14];
					v9 += 2 * v14;
					break;
				case 8192:
					v60 = 4;
					v15 = (int *)(a1 + 32 * *v8);
					++v8;
					do
					{
						v16 = *v15;
						v17 = v15 + 1;
						v18 = v9;
						if (v14)
						{
							v19 = v14;
							do
							{
								*v18 = v16;
								v18 += 2;
								--v19;
							} while (v19);
						}
						v20 = *v17;
						v15 = v17 + 1;
						v21 = v9 + 1;
						if (v14)
						{
							v22 = v14;
							do
							{
								*v21 = v20;
								v21 += 2;
								--v22;
							} while (v22);
						}
						v9 = (int *)((char *)v9 + v63);
						--v60;
					} while (v60);
					v9 = (int *)((char *)v9 + 8 * v14 - 4 * v63);
					goto LABEL_62;
				}
			}
		LABEL_63:
			result = v53;
			v6 = v63;
			if (v9 == v53)
			{
				v52 += v63;
				v59 = v52;
				result = &v52[2 * a4];
				v9 = v52;
				v53 = &v52[2 * a4];
			}
		} while (v9 < v54);
	}
	return result;
}

//----- (00564E60) --------------------------------------------------------
int *__cdecl sub_564E60(int a1, _WORD *a2, int *a3, unsigned int a4, int a5, int a6)
{
	int *v6; // edx
	int v7; // ebp
	_WORD *v8; // esi
	int *result; // eax
	int *v10; // edi
	int v11; // ecx
	_WORD *v12; // eax
	int v13; // ebx
	int *v14; // esi
	int v15; // edi
	unsigned __int16 *v16; // eax
	int v17; // esi
	unsigned __int16 v18; // cx
	unsigned __int16 v19; // bx
	unsigned __int16 *v20; // eax
	unsigned __int16 v21; // cx
	unsigned __int16 v22; // bx
	int *v23; // [esp+Ch] [ebp-4h]
	int v24; // [esp+1Ch] [ebp+Ch]
	int *v25; // [esp+24h] [ebp+14h]
	int *v26; // [esp+28h] [ebp+18h]

	v6 = a3;
	v7 = 2 * a6;
	v8 = a2;
	result = &a3[2 * a6 * a5];
	v10 = a3;
	v23 = &a3[2 * a6 * a5];
	v26 = a3;
	v25 = &a3[2 * a4];
	if (a3 < result)
	{
		while (1)
		{
			result = (int *)(*v8 & 0x1FFF);
			v11 = *v8 & 0xE000;
			v24 = (int)(v8 + 1);
			if (*v8 & 0xE000)
			{
				if (v11 == 0x2000)
				{
					v12 = (_WORD *)(a1 + 32 * (*v8 & 0x1FFF));
					v13 = 4;
					do
					{
						v14 = v6;
						v15 = 4;
						do
						{
							if (*v12 != -32768)
								*(_WORD *)v14 = *v12;
							v14 = (int *)((char *)v14 + 2);
							++v12;
							--v15;
						} while (v15);
						v6 = (int *)((char *)v6 + v7);
						--v13;
					} while (v13);
					v10 = v26;
					result = (int *)(4 * v7);
					v6 = (int *)((char *)v6 + 8 - 4 * v7);
				}
				else if (v11 == 0x4000)
				{
					v6 += 2;
				}
			}
			else
			{
				v16 = (unsigned __int16 *)(a1 + 32 * (*v8 & 0x1FFF));
				v17 = 4;
				do
				{
					v18 = v16[1];
					v19 = *v16;
					v20 = v16 + 2;
					*v6 = v19 | (v18 << 16);
					v21 = v20[1];
					v22 = *v20;
					v16 = v20 + 2;
					v6[1] = v22 | (v21 << 16);
					v6 = (int *)((char *)v6 + v7);
					--v17;
				} while (v17);
				result = (int *)(4 * v7);
				v6 = (int *)((char *)v6 + 8 - 4 * v7);
			}
			if (v6 == v25)
			{
				v10 += v7;
				result = (int *)a4;
				v26 = v10;
				v6 = v10;
				v25 = &v10[2 * a4];
			}
			if (v6 >= v23)
				break;
			v8 = (_WORD *)v24;
		}
	}
	return result;
}

//----- (00564FB0) --------------------------------------------------------
unsigned int __cdecl sub_564FB0(int a1, unsigned __int8 *a2, int *a3, unsigned int a4, int a5, int a6)
{
	int v6; // ebp
	int *v7; // ebx
	unsigned __int8 *v8; // esi
	unsigned int result; // eax
	__int16 v10; // ax
	__int16 v11; // cx
	unsigned int v12; // ecx
	int *v13; // edi
	unsigned __int16 *v14; // ecx
	int v15; // eax
	int v16; // esi
	unsigned __int16 v17; // dx
	unsigned __int16 v18; // bp
	unsigned __int16 *v19; // ecx
	unsigned __int16 v20; // dx
	unsigned __int16 v21; // bp
	unsigned __int8 *v22; // ecx
	int *v23; // edx
	unsigned __int16 *v24; // eax
	int v25; // edi
	unsigned __int16 v26; // cx
	unsigned __int16 v27; // bp
	unsigned __int16 *v28; // eax
	unsigned __int16 v29; // cx
	unsigned __int16 v30; // bp
	int v31; // edx
	unsigned __int16 *v32; // eax
	int v33; // edx
	unsigned __int16 v34; // cx
	unsigned __int16 v35; // di
	unsigned __int16 *v36; // eax
	unsigned __int16 v37; // cx
	unsigned __int16 v38; // di
	int v39; // ebp
	__int16 *v40; // eax
	int *v41; // edi
	__int16 v42; // dx
	int *v43; // ecx
	int v44; // esi
	int v45; // edx
	int *v46; // ecx
	int v47; // eax
	int *v48; // ecx
	int *v49; // esi
	int v50; // edi
	int v51; // eax
	_DWORD *v52; // esi
	int v53; // edi
	_WORD *v54; // eax
	int v55; // edi
	int *v56; // edx
	int v57; // esi
	int *v58; // [esp+Ch] [ebp-Ch]
	int *v59; // [esp+10h] [ebp-8h]
	unsigned int v60; // [esp+14h] [ebp-4h]
	int v61; // [esp+20h] [ebp+8h]
	unsigned int v62; // [esp+24h] [ebp+Ch]
	int v63; // [esp+24h] [ebp+Ch]
	int v64; // [esp+24h] [ebp+Ch]
	int v65; // [esp+24h] [ebp+Ch]
	int v66; // [esp+2Ch] [ebp+14h]
	unsigned int v67; // [esp+2Ch] [ebp+14h]
	unsigned int v68; // [esp+30h] [ebp+18h]

	v6 = 2 * a6;
	v7 = a3;
	v8 = a2;
	result = (unsigned int)&a3[2 * a6 * a5];
	v68 = 2 * a6;
	v60 = result;
	v58 = a3;
	v59 = &a3[2 * a4];
	if ((unsigned int)a3 < result)
	{
		do
		{
			v10 = *(_WORD *)v8;
			v8 += 2;
			v11 = v10;
			result = v10 & 0x1FFF;
			v12 = v11 & 0xE000;
			v66 = (int)v8;
			if (v12 > 0x6000)
			{
				switch (v12)
				{
				case 0x8000u:
					v54 = (_WORD *)(a1 + 32 * (unsigned __int16)result);
					v55 = 4;
					do
					{
						v56 = v7;
						v57 = 4;
						do
						{
							if (*v54 != -32768)
								*(_WORD *)v56 = *v54;
							v56 = (int *)((char *)v56 + 2);
							++v54;
							--v57;
						} while (v57);
						v7 = (int *)((char *)v7 + v6);
						--v55;
					} while (v55);
					result = 4 * v6;
					v7 = (int *)((char *)v7 + 8 - 4 * v6);
					goto LABEL_52;
				case 0xA000u:
					goto LABEL_16;
				case 0xC000u:
					v39 = *v8;
					v66 = (int)(v8 + 1);
					v40 = (__int16 *)(a1 + 32 * (unsigned __int16)result);
					v61 = 4;
					do
					{
						v41 = v7;
						v64 = 4;
						do
						{
							v42 = *v40;
							if (*v40 != -32768)
							{
								v43 = v41;
								if (v39)
								{
									v44 = v39;
									do
									{
										*(_WORD *)v43 = v42;
										v43 += 2;
										--v44;
									} while (v44);
								}
							}
							v41 = (int *)((char *)v41 + 2);
							++v40;
							--v64;
						} while (v64);
						v7 = (int *)((char *)v7 + v68);
						--v61;
					} while (v61);
					v45 = 8 * v39;
					v6 = v68;
					result = 4 * v68;
					v7 = (int *)((char *)v7 + v45 - 4 * v68);
					goto LABEL_52;
				}
			}
			else if (v12 == 24576)
			{
				v32 = (unsigned __int16 *)(a1 + 32 * (unsigned __int16)result);
				v33 = 4;
				do
				{
					v34 = v32[1];
					v35 = *v32;
					v36 = v32 + 2;
					*v7 = v35 | (v34 << 16);
					v37 = v36[1];
					v38 = *v36;
					v32 = v36 + 2;
					v7[1] = v38 | (v37 << 16);
					v7 = (int *)((char *)v7 + v6);
					--v33;
				} while (v33);
				result = 4 * v6;
				v7 = (int *)((char *)v7 + 8 - 4 * v6);
			}
			else if (v12)
			{
				if (v12 == 0x2000)
				{
					v31 = (((unsigned __int16)result >> 7) & 0x3E) + 2;
					if ((((unsigned __int16)result >> 7) & 0x3E) == -2)
					{
					LABEL_16:
						result = (unsigned __int16)result;
						v31 = *v8;
						v66 = (int)(v8 + 1);
					}
					else
					{
						result = (unsigned __int8)result;
					}
					v65 = 4;
					v46 = (int *)(a1 + 32 * result);
					do
					{
						v47 = *v46;
						v48 = v46 + 1;
						v49 = v7;
						if (v31)
						{
							v50 = v31;
							do
							{
								*v49 = v47;
								v49 += 2;
								--v50;
							} while (v50);
							v6 = v68;
						}
						v51 = *v48;
						v46 = v48 + 1;
						v52 = v7 + 1;
						if (v31)
						{
							v53 = v31;
							do
							{
								*v52 = v51;
								v52 += 2;
								--v53;
							} while (v53);
							v6 = v68;
						}
						v7 = (int *)((char *)v7 + v6);
						--v65;
					} while (v65);
					result = 4 * v6;
					v7 = (int *)((char *)v7 + 8 * v31 - 4 * v6);
				LABEL_52:
					v8 = (unsigned __int8 *)v66;
					goto LABEL_53;
				}
				if (v12 == 0x4000)
				{
					v13 = v7;
					v14 = (unsigned __int16 *)(a1 + 32 * *(v8 - 2));
					v62 = ((result >> 7) & 0x3E) + 2;
					v15 = 4;
					v16 = 4 * (v68 >> 2);
					do
					{
						v17 = v14[1];
						v18 = *v14;
						v19 = v14 + 2;
						*v13 = v18 | (v17 << 16);
						v20 = v19[1];
						v21 = *v19;
						v14 = v19 + 2;
						v13[1] = v21 | (v20 << 16);
						v13 = (int *)((char *)v13 + v16);
						--v15;
					} while (v15);
					result = v62;
					v22 = (unsigned __int8 *)v66;
					v7 += 2;
					if (v62)
					{
						v67 = v62;
						do
						{
							v23 = v7;
							v63 = (int)(v22 + 1);
							v24 = (unsigned __int16 *)(a1 + 32 * *v22);
							v25 = 4;
							do
							{
								v26 = v24[1];
								v27 = *v24;
								v28 = v24 + 2;
								*v23 = v27 | (v26 << 16);
								v29 = v28[1];
								v30 = *v28;
								v24 = v28 + 2;
								v23[1] = v30 | (v29 << 16);
								v23 = (int *)((char *)v23 + v16);
								--v25;
							} while (v25);
							v22 = (unsigned __int8 *)v63;
							v7 += 2;
							result = --v67;
						} while (v67);
					}
					v6 = v68;
					v66 = (int)v22;
					goto LABEL_52;
				}
			}
			else
			{
				result = (unsigned __int8)result;
				v7 += 2 * (unsigned __int8)result;
			}
		LABEL_53:
			if (v7 == v59)
			{
				v7 = &v58[v6];
				result = a4;
				v58 = v7;
				v59 = &v7[2 * a4];
			}
		} while ((unsigned int)v7 < v60);
	}
	return result;
}

_DWORD *sub_556990()
{
	return sub_5569A0();
}

void *sub_55C8D0()
{
	return sub_55C8E0();
}

int __thiscall sub_559AE0(_BYTE *this)
{
	return sub_559C30(this);
}

DWORD __cdecl sub_55A740()
{
	return sub_55C930();
}
#endif
