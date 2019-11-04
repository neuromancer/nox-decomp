#include "proto.h"

#ifdef NO_IMM
static wchar_t g_ime_buf[512];
static unsigned int g_ime_idx;

void process_textediting_event(const SDL_TextEditingEvent *event)
{
}

void process_textinput_event(const SDL_TextInputEvent *event)
{
    //g_ime_buf[g_ime_idx++] = event->text[0];
    //g_ime_buf[g_ime_idx] = 0;
    g_ime_buf[0] = 0;

    sub_488BD0(event->text[0]);
}

int **__thiscall sub_56FFE0(int **this)
{
	return this;
}

int **__thiscall sub_570070(int ***this)
{
	return this;
}

//----- (005700CA) --------------------------------------------------------
int __thiscall sub_5700CA(int **this, HWND hWnd)
{
    SDL_StartTextInput();
	return 0;
}

//----- (005700F6) --------------------------------------------------------
int *__thiscall sub_5700F6(int **this)
{
    SDL_StopTextInput();
	return 0;
}

//----- (0057011C) --------------------------------------------------------
wchar_t *__thiscall sub_57011C(_DWORD **this)
{
    return g_ime_buf;
}

//----- (00570142) --------------------------------------------------------
_DWORD *__thiscall sub_570142(_DWORD **this, char a2)
{
	return 0;
}

//----- (005702B4) --------------------------------------------------------
bool __thiscall sub_5702B4(_DWORD **this)
{
	return 1;
}

//----- (00570392) --------------------------------------------------------
int __thiscall sub_570392(_DWORD **this)
{
	return 0;
}

#else

unsigned __int8 *__thiscall sub_57016E(void *this, unsigned int a2);
int __thiscall sub_5701D1(void *this);
int **__thiscall sub_570217(int **this, DWORD dwValue, int a3, int a4);
int *__thiscall sub_57027C(int **this, DWORD dwValue);
int sub_570485();
int sub_57049B();
int *__thiscall sub_5704C0(int *this);
int **__thiscall sub_570530(int **this, char a2);
wstring *__thiscall sub_570570(int **this);
int **__thiscall sub_5705D0(int **this);
_DWORD *__thiscall sub_570600(_DWORD *this, _DWORD *a2);
int **__thiscall sub_570670(int **this);
_DWORD *__thiscall sub_5706E0(_DWORD *this, _DWORD *a2);
int __thiscall sub_5708A0(_DWORD *this);
int __thiscall sub_5708F0(_DWORD *this, int a2);
unsigned __int8 *__thiscall sub_570920(_DWORD *this);
int __thiscall sub_570970(_DWORD *this);
int *__stdcall sub_5709C0(int *a1, int *a2);
char *__stdcall sub_570A00(int *a1, int *a2, char *a3);
void *__stdcall sub_570A50(int a1, int a2);
void __stdcall sub_570A80(LPVOID lpMem, int); // idb
unsigned __int8 *sub_570AB0();
wstring *__stdcall sub_570AC0(void *a1, int *a2);
int *__stdcall sub_570AF0(int *a1);
int *__cdecl sub_570B20(int *a1, int *a2, int *a3);
void *__cdecl sub_570B60(int a1);
wstring *__cdecl sub_570B90(void *a1, int *a2);
int __cdecl sub_570C20(int a1, int a2);
int *__cdecl sub_570C30(int *a1);
int *__thiscall sub_570C50(int *this, char a2);
wstring *__thiscall sub_570C90(int *this, int *a2);
wstring *__thiscall sub_570CE0(int *this);
wstring *__thiscall sub_570D10(wstring *this, wstring *a2); // idb
wstring *__thiscall wstring__assign_0(wstring *this, wstring *a2); // idb
wstring *__thiscall sub_570D80(wstring *this, wstring *a2, unsigned int a3, unsigned int a4); // idb
_WORD *__cdecl sub_570F00(_WORD *a1, _WORD *a2, int a3);
_WORD *__cdecl sub_570F20(_WORD *a1, _WORD *a2, int a3);
wstring *__thiscall sub_570F70(wstring *this, char a2);
wstring *__thiscall sub_571040(wstring *this, unsigned int a2, unsigned int a3);
unsigned int __cdecl sub_571110(unsigned int a1, _WORD *a2, int a3);
unsigned int __cdecl sub_571130(unsigned int a1, _WORD *a2, int a3);
int __thiscall sub_5711E0(_DWORD *this);
_WORD *__thiscall wstring___Eos(_DWORD *this, int a2);
_WORD *__cdecl wchar_t__assign_0(_WORD *a1, _WORD *a2);
char __thiscall wstring___Grow(int *this, unsigned int _N, char a3); // idb
int wstring__max_size();
_WORD *__thiscall sub_571430(int *this, unsigned int a2);
wstring *__thiscall sub_571590(wstring *this);
int *__thiscall sub_571610(int *this, wchar_t *a2);
size_t __cdecl sub_571650(wchar_t *a1);
void *__stdcall sub_571670(int a1, int a2);
int sub_5716A0();
int *__thiscall sub_5716F0(int *this, _WORD *a2, unsigned int a3);
char sub_571750();
void *__cdecl sub_571760(int a1);
int sub_571790();
void __cdecl sub_5717C0(); // idb
_DWORD *__thiscall sub_5717D0(_DWORD *this);
char __cdecl sub_571810(int a1, LPCSTR lpMultiByteStr);
unsigned __int8 *sub_571905();
void __cdecl sub_57194A(); // idb
int __thiscall sub_571960(int *this, char a2);
int __thiscall sub_5719DA(int *this, char a2);
int __thiscall sub_571A54(int *this, int a2, int a3, int a4);
int __thiscall sub_571AEA(int *this, char a2);
LONG __thiscall sub_571B63(HIMC *this, DWORD a2, LPWSTR lpWideCharStr, int cchWideChar);
int __thiscall sub_571C0E(HIMC *this, DWORD dwIndex, LPCWSTR lpWideCharStr, int a4, LPCWSTR a5, int a6);
BOOL __thiscall sub_571EAD(HIMC *this, DWORD dwIndex, DWORD dwValue, int a4);
void __stdcall sub_571EF2(int a1, int a2);
BOOL __thiscall sub_571F06(HIMC *this, DWORD dwIndex, DWORD dwValue);
BOOL __thiscall sub_571F46(HIMC *this, DWORD dwAction, DWORD dwIndex, DWORD dwValue);
BOOL __thiscall sub_571F7C(HIMC *this);
BOOL __thiscall sub_571FA4(HIMC *this, BOOL a2);
BOOL __thiscall sub_571FE1(HIMC *this, LPCOMPOSITIONFORM lpCompForm);
DWORD __thiscall sub_57200F(HIMC *this, DWORD deIndex, LPCANDIDATELIST lpCandList, DWORD dwBufLen);
int *__thiscall sub_572045(int *this);
wstring *__thiscall sub_57211C(HIMC *this);
_BYTE *__thiscall sub_5721B7(_BYTE *this);
int *__thiscall sub_5721D0(int this);
unsigned __int8 *__thiscall sub_572203(_DWORD *this);
void __thiscall sub_57222A(int *this, int a2, int a3);
void __thiscall sub_572333(int *this, int a2);
int *__thiscall sub_572442(int *this, int a2, int a3, int a4);
int *__thiscall sub_5726A9(_DWORD *this);
void __thiscall sub_5726E0(_DWORD *this);
int __stdcall sub_572796(int a1);
int __thiscall sub_5727AC(void (__stdcall **this)(HWND, int, _DWORD, LPARAM), HWND hWnd, int a3, LPARAM lParam);
int __thiscall sub_5728C1(void (__stdcall **this)(HWND, int, _DWORD, LPARAM), HWND hWnd, char a3, LPARAM lParam);
void __thiscall sub_572A06(_DWORD *this, int a2);
char __thiscall sub_572AC5(_DWORD *this, int a2, int a3, int a4);
HKL __cdecl sub_572BD6(char a1);
LRESULT __thiscall sub_572E05(_DWORD *this, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
void __thiscall sub_573153(_DWORD *this, int a2, int a3);
int __thiscall sub_573266(_DWORD *this, int a2, int a3);
void __thiscall sub_57330C(_DWORD *this, int a2, int a3);
int __thiscall sub_573401(_DWORD *this, int a2, DWORD deIndex);
int __thiscall sub_57366C(int *this, HWND hWnd);
int *__thiscall sub_57381A(int *this);
void __thiscall sub_57390B(int *this, DWORD dwValue, int a3, int a4);
void __thiscall sub_5739D2(int *this, DWORD dwValue);
LRESULT __stdcall sub_573A68(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
int __thiscall sub_573AE4(_DWORD *this);
_DWORD *__thiscall sub_573B1F(_DWORD *this, _DWORD a2);
unsigned __int8 *__thiscall sub_573B56(_DWORD *this);
unsigned __int8 *__thiscall sub_573B7D(_DWORD *this);
int sub_573C05();
int sub_573C1B();
void *__thiscall sub_573C40(void *this);
void __thiscall sub_573C80(int *this);
void __thiscall sub_573CB0(int *this);
_DWORD *__thiscall sub_573CE0(_DWORD *this, int a2, int a3);
HIMC *__thiscall sub_573D10(HIMC *this, char a2);
int *__thiscall sub_573D50(int *this, _BYTE *a2);
int *__thiscall sub_573D90(int *this, _DWORD *a2, char a3, _BYTE *a4);
int *__thiscall sub_573DE0(int *this);
int *__thiscall sub_573E10(int *this, int *a2);
int __thiscall sub_573E40(int *this);
unsigned __int8 *__thiscall sub_573E70(_DWORD *this);
int __thiscall sub_573EC0(_DWORD *this, int *a2);
int *__thiscall sub_573F00(_DWORD *this);
int *__thiscall sub_573F40(int *this, _BYTE *a2);
int *__thiscall sub_573F80(int *this, wchar_t *a2, _BYTE *a3);
wstring *__thiscall wstring__wstring(wstring *this, int _N, wchar_t _C, _BYTE *a4); // idb
int *__thiscall sub_574020(int *this, wchar_t *a2);
int __thiscall sub_574050(int *this);
int __thiscall sub_574080(int *this);
int ***__thiscall sub_5740C0(int ***this);
int __thiscall wstring__size(_DWORD *this);
_DWORD *__thiscall sub_574160(_DWORD *this, unsigned int a2, _DWORD *a3);
int __thiscall sub_5741E0(_DWORD *this, int a2);
_DWORD *__thiscall sub_574210(_DWORD *this);
void *__thiscall sub_574250(void *this, _BYTE *a2, _BYTE *a3);
_DWORD *__thiscall sub_574290(int *this, _DWORD *a2);
int __thiscall sub_5742D0(int *this, _DWORD *a2);
_DWORD *__thiscall sub_574340(_DWORD *this);
_DWORD *__thiscall sub_574370(int *this, _DWORD *a2, int a3);
int *__thiscall sub_5743C0(int *this, int *a2, _DWORD *a3);
void __thiscall sub_574410(int *this);
int __thiscall sub_574500(int *this);
BOOL __thiscall sub_574530(_DWORD *this, _DWORD *a2);
BOOL __thiscall sub_574560(_DWORD *this, _DWORD *a2);
_DWORD *__thiscall sub_5745A0(_DWORD *this, _BYTE *a2);
_DWORD *__thiscall sub_5745E0(_DWORD *this, int a2, _DWORD *a3, _BYTE *a4);
int *__thiscall sub_574660(int *this);
_DWORD *__thiscall sub_5746D0(_DWORD *this, unsigned int a2);
_DWORD *__thiscall sub_5747A0(_DWORD *this, _DWORD *a2);
_DWORD *__thiscall sub_5747F0(_DWORD *this, _DWORD *a2);
int __thiscall sub_574840(_DWORD *this, _DWORD *a2);
void *__thiscall sub_574880(void *this);
int __thiscall sub_5748A0(_DWORD *this);
_DWORD *__thiscall sub_5748C0(int *this, _DWORD *a2, int a3);
_DWORD *__thiscall sub_574900(_DWORD *this, int a2);
LPVOID *__thiscall sub_574930(LPVOID *this);
int __thiscall sub_574980(_DWORD *this);
int *__thiscall sub_5749A0(int *this, int *a2);
int *__thiscall sub_5749E0(int *this, int *a2, unsigned int a3, unsigned int a4);
unsigned int __cdecl sub_574B60(void *a1, void *a2, unsigned int a3);
int __thiscall sub_574B80(_DWORD *this);
int __thiscall string__assign(_DWORD *this, int N, char C);
void *__cdecl char_t__assign_0(void *a1, size_t a2, char *a3);
char __thiscall sub_574C40(int *this);
unsigned __int8 *sub_574CD0();
int *__thiscall sub_574CE0(int *this, char a2);
int __thiscall sub_574DB0(_DWORD *this, int *a2, int *a3);
int __thiscall sub_574E10(int this, int a2);
int *__thiscall sub_574E50(_DWORD *this, int *a2, int *a3);
BOOL __thiscall sub_574EC0(int this);
bool __thiscall sub_574F00(char *this);
BOOL __thiscall sub_574F30(char *this);
char *__thiscall sub_574F60(char *this);
int __thiscall wstring__assign(_DWORD *this, int _N, wchar_t _C);
_WORD *__cdecl wchar_t__assign(_WORD *a1, int a2, __int16 *a3);
_WORD *__cdecl sub_575020(_WORD *a1, __int16 a2, int a3);
char __thiscall sub_575060(int *this);
int __cdecl sub_5750F0(int a1, int a2);
int __thiscall sub_575120(_DWORD *this);
int __thiscall sub_575140(_DWORD *this);
unsigned int __thiscall sub_575190(unsigned int this, _DWORD *a2, unsigned int a3, _DWORD *a4);
_DWORD *__thiscall sub_5753F0(_DWORD *this, _DWORD *a2, _DWORD *a3);
int **__stdcall sub_575460(int **a1, int **a2);
_DWORD *__thiscall sub_5754A0(int *this, _DWORD *a2, _DWORD *a3);
int __thiscall sub_575510(int this, _BYTE *a2, char a3, _BYTE *a4);
_DWORD *__thiscall sub_575560(_DWORD *this, _DWORD *a2);
_DWORD *__thiscall sub_5755B0(int *this, _DWORD *a2);
_DWORD *__thiscall sub_5755F0(int *this, _DWORD *a2, int a3);
_DWORD *__thiscall sub_575E60(int *this, _DWORD *a2, int a3, char a4);
int *__thiscall sub_575FC0(int *this, int *a2, _DWORD *a3);
void __stdcall sub_576080(LPVOID lpMem);
_DWORD *__thiscall sub_5760B0(_DWORD *this, _DWORD *a2, _DWORD *a3);
int __thiscall sub_5760F0(int *this);
int __thiscall sub_576120(_DWORD *this);
int __thiscall sub_576170(_DWORD *this);
int __thiscall sub_5761C0(_DWORD *this, _DWORD *a2, _DWORD *a3);
int __stdcall sub_576220(int a1, int a2);
char *__stdcall sub_576260(_DWORD *a1, _DWORD *a2, char *a3);
int __stdcall sub_5762B0(char *a1, int a2, _DWORD *a3);
void *__stdcall sub_576300(int a1, int a2);
void __stdcall sub_576330(LPVOID lpMem, int); // idb
int *__thiscall sub_576360(int *this, unsigned int a2, unsigned int a3);
unsigned int __cdecl sub_576420(unsigned int a1, _BYTE *a2, unsigned int a3);
_BYTE *__thiscall string___Eos(_DWORD *this, int a2);
_BYTE *__cdecl char_t__assign(_BYTE *a1, _BYTE *a2);
char __thiscall string___Grow(int *this, unsigned int a2, char a3);
int __stdcall sub_576600(int a1);
char *__thiscall sub_576620(int this, int *a2, unsigned int a3, int *a4);
char *__stdcall sub_576870(_DWORD *a1, _DWORD *a2, char *a3);
int __stdcall sub_5768C0(char *a1, int a2, _DWORD *a3);
void *__stdcall sub_576910(int a1, int a2);
int **__stdcall sub_576940(int **a1);
BOOL __stdcall sub_576970(_DWORD *a1, _DWORD *a2);
int __cdecl sub_5769A0(int a1);
int __cdecl sub_5769B0(int a1);
int __cdecl sub_5769E0(int a1);
int __cdecl sub_5769F0(int a1);
int __cdecl sub_576A00(int a1);
int __cdecl sub_576A10(int a1);
_DWORD *__thiscall sub_576A20(int *this, _DWORD *a2, _DWORD *a3);
_DWORD *__thiscall sub_576C80(int *this, _DWORD *a2, _DWORD *a3);
void __stdcall sub_576CD0(void *a1);
void __thiscall sub_576DA0(int *this);
int __thiscall sub_576EA0(_DWORD *this);
void __thiscall sub_576ED0(int *this, int a2);
int __cdecl sub_577060(int a1);
int __cdecl sub_577100(int a1);
int __thiscall sub_5771A0(int *this);
int __thiscall sub_5771D0(int *this);
void __thiscall sub_577200(int *this, int a2);
void __stdcall sub_577390(int a1);
int __thiscall sub_5773C0(void *this);
_DWORD *__thiscall sub_5773E0(_DWORD *this, int a2);
int *__thiscall sub_577410(int *this, int *a2, int a3);
unsigned int __thiscall sub_577460(unsigned int this, _DWORD *a2, unsigned int a3, _DWORD *a4);
_DWORD *__stdcall sub_5776A0(void *a1, _DWORD *a2);
_BYTE *__thiscall sub_5776D0(_BYTE *this, _DWORD *a2, _BYTE *a3);
int string__max_size();
_BYTE *__thiscall sub_577760(int *this, unsigned int a2);
int *__thiscall sub_5778C0(int *this);
int *__thiscall sub_577940(int *this, char *a2);
size_t __cdecl sub_577980(char *a1);
int *__thiscall sub_5779A0(int *this, _BYTE *a2, unsigned int a3);
int __stdcall sub_577A00(char *a1, int a2, int *a3);
_DWORD *__stdcall sub_577A50(void *a1, _DWORD *a2);
int __stdcall sub_577A80(int a1);
_DWORD *__thiscall sub_577AA0(int *this, _DWORD *a2, int a3, int a4, _DWORD *a5);
int __thiscall sub_577F90(int *this, _DWORD *a2);
int __stdcall sub_578080(int a1, int a2);
_DWORD *__thiscall sub_5780E0(_DWORD *this, int a2);
int *__thiscall sub_578100(int *this);
int *__thiscall sub_578130(int *this);
void *__stdcall sub_578160(signed int a1, int a2);
int sub_578190();
void *__stdcall sub_5781E0(signed int a1);
_DWORD *__stdcall sub_578210(void *a1, _DWORD *a2);
void __thiscall sub_578240(int *this);
void __thiscall sub_578370(int *this);
_DWORD *__cdecl sub_578460(_DWORD *a1, int a2, char a3, _DWORD *a4);
BOOL __cdecl sub_5784B0(void *a1, void *a2);
int __cdecl sub_5784E0(int a1, unsigned __int16 *a2, unsigned __int16 **a3);
int __cdecl sub_578520(int a1, char a2);
_DWORD *__cdecl sub_578540(_DWORD *a1, _DWORD *a2);
_DWORD *__cdecl sub_578580(_DWORD *a1, _DWORD *a2, _DWORD *a3);
_DWORD *__cdecl sub_5785B0(_DWORD *a1, _DWORD *a2, _DWORD *a3);
_DWORD *__cdecl sub_5785F0(_DWORD *a1, _DWORD *a2, _DWORD *a3);
int __cdecl sub_578630(int *a1, int *a2);
void *__cdecl sub_578660(int a1);
int *__cdecl sub_578690(int *a1, int *a2, int *a3);
int *__cdecl sub_5786C0(int *a1, int *a2, int *a3);
void *__cdecl sub_578700(int a1);
int **__cdecl sub_578730(int **a1);
_DWORD *__cdecl sub_578750(_DWORD *a1, _DWORD *a2, _DWORD *a3);
_DWORD *__cdecl sub_578780(_DWORD *a1, _DWORD *a2, _DWORD *a3);
_DWORD *__cdecl sub_5787B0(void *a1, _DWORD *a2);
_DWORD *__cdecl sub_578810(void *a1, _DWORD *a2);
void *__cdecl sub_5788A0(signed int a1);
_DWORD *__cdecl sub_5788D0(void *a1, _DWORD *a2);
int **__thiscall sub_578930(int **this, char a2);
_DWORD *__thiscall sub_578970(_DWORD *this, _DWORD *a2);
_DWORD *__thiscall sub_5789E0(_BYTE *this, _DWORD *a2);
_DWORD *__thiscall sub_578A60(_DWORD *this);
bool __cdecl sub_578A90(void *a1, void *a2);

//----- (0056FFE0) --------------------------------------------------------
int **__thiscall sub_56FFE0(int **this)
{
	int *v2; // [esp+0h] [ebp-1Ch]
	int **v3; // [esp+4h] [ebp-18h]
	int *v4; // [esp+8h] [ebp-14h]

	v3 = this;
	v4 = (int *)operator_new(0x18Cu);
	if (v4)
		v2 = sub_5704C0(v4);
	else
		v2 = 0;
	*v3 = v2;
	return v3;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00570070) --------------------------------------------------------
int **__thiscall sub_570070(int ***this)
{
	int **result; // eax

	result = (int **)this;
	if (*this)
	{
		result = *this;
		if (*this)
			result = sub_570530(*this, 1);
	}
	return result;
}

//----- (005700CA) --------------------------------------------------------
int __thiscall sub_5700CA(int **this, HWND hWnd)
{
	return sub_57366C(*this, hWnd);
}

//----- (005700F6) --------------------------------------------------------
int *__thiscall sub_5700F6(int **this)
{
	return sub_57381A(*this);
}

//----- (0057011C) --------------------------------------------------------
wchar_t *__thiscall sub_57011C(_DWORD **this)
{
	return sub_573B56(*this);
}

//----- (00570142) --------------------------------------------------------
_DWORD *__thiscall sub_570142(_DWORD **this, char a2)
{
	return sub_573B1F(*this, a2);
}

//----- (0057016E) --------------------------------------------------------
unsigned __int8 *__thiscall sub_57016E(void *this, unsigned int a2)
{
	_DWORD *v3; // eax
	void *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	if (!*(_BYTE *)(*(_DWORD *)this + 388) || a2 >= sub_5708A0((_DWORD *)(*(_DWORD *)this + 368)))
		return 0;
	v3 = (_DWORD *)sub_5708F0((_DWORD *)(*(_DWORD *)v4 + 368), a2);
	return sub_570920(v3);
}

//----- (005701D1) --------------------------------------------------------
int __thiscall sub_5701D1(void *this)
{
	int v2; // [esp+0h] [ebp-8h]

	if (*(_BYTE *)(*(_DWORD *)this + 388))
		v2 = *(_DWORD *)(*(_DWORD *)this + 364);
	else
		v2 = 0;
	return v2;
}

//----- (00570217) --------------------------------------------------------
int **__thiscall sub_570217(int **this, DWORD dwValue, int a3, int a4)
{
	int **result; // eax

	if (!*((_BYTE *)*this + 388) || (*this)[90] != dwValue || (result = this, a4 != (*this)[91]))
		sub_57390B(*this, dwValue, a3, a4);
	return result;
}

//----- (0057027C) --------------------------------------------------------
int *__thiscall sub_57027C(int **this, DWORD dwValue)
{
	int *result; // eax
	int **v3; // [esp+0h] [ebp-4h]

	v3 = this;
	sub_5739D2(*this, dwValue);
	result = *v3;
	*((_BYTE *)*v3 + 388) = 0;
	return result;
}

//----- (005702B4) --------------------------------------------------------
bool __thiscall sub_5702B4(_DWORD **this)
{
	bool v2; // [esp+0h] [ebp-10h]
	_DWORD **v3; // [esp+4h] [ebp-Ch]
	_DWORD *v4; // [esp+8h] [ebp-8h]

	v3 = this;
	v4 = (_DWORD *)sub_573AE4(*this);
	if (v4)
	{
		if (!*((_BYTE *)*v3 + 388) || *v4 != (*v3)[88])
		{
			sub_570600(*v3 + 88, v4);
			*((_BYTE *)*v3 + 388) = 1;
		}
	}
	else
	{
		*((_BYTE *)*v3 + 388) = 0;
	}
	if (*((_BYTE *)*v3 + 388))
		v2 = v4[8] == (*v3)[96];
	else
		v2 = 0;
	(*v3)[98] = (*v3)[96];
	return v2;
}

//----- (00570392) --------------------------------------------------------
int __thiscall sub_570392(_DWORD **this)
{
	int v2; // [esp+0h] [ebp-Ch]
	_DWORD **v3; // [esp+4h] [ebp-8h]
	_DWORD *v4; // [esp+8h] [ebp-4h]

	v3 = this;
	v4 = (_DWORD *)sub_573AE4(*this);
	if (v4)
	{
		if (!*((_BYTE *)*v3 + 388) || *v4 != (*v3)[88])
		{
			sub_570600(*v3 + 88, v4);
			if (!(*v3)[98])
				(*v3)[98] = (*v3)[96];
			*((_BYTE *)*v3 + 388) = 1;
		}
	}
	else
	{
		(*v3)[98] = 0;
		*((_BYTE *)*v3 + 388) = 0;
	}
	if (*((_BYTE *)*v3 + 388))
		v2 = sub_5708A0(*v3 + 92);
	else
		v2 = 0;
	return v2;
}

//----- (00570485) --------------------------------------------------------
int sub_570485()
{
	sub_571790();
	return sub_57049B();
}

//----- (0057049B) --------------------------------------------------------
int sub_57049B()
{
	return atexit(sub_5717C0);
}

//----- (005704C0) --------------------------------------------------------
int *__thiscall sub_5704C0(int *this)
{
	int *v2; // [esp+0h] [ebp-10h]

	v2 = this;
	sub_572045(this);
	sub_5717D0(v2 + 88);
	return v2;
}

//----- (00570530) --------------------------------------------------------
int **__thiscall sub_570530(int **this, char a2)
{
	int **lpMem; // [esp+0h] [ebp-4h]

	lpMem = this;
	sub_570570(this);
	if (a2 & 1)
		operator_delete(lpMem);
	return lpMem;
}

//----- (00570570) --------------------------------------------------------
wstring *__thiscall sub_570570(int **this)
{
	int **v2; // [esp+0h] [ebp-10h]

	v2 = this;
	sub_5705D0(this + 88);
	return sub_57211C((HIMC *)v2);
}

//----- (005705D0) --------------------------------------------------------
int **__thiscall sub_5705D0(int **this)
{
	return sub_570670(this + 4);
}

//----- (00570600) --------------------------------------------------------
_DWORD *__thiscall sub_570600(_DWORD *this, _DWORD *a2)
{
	_DWORD *v3; // [esp+0h] [ebp-4h]

	v3 = this;
	*this = *a2;
	this[1] = a2[1];
	this[2] = a2[2];
	this[3] = a2[3];
	sub_5706E0(this + 4, a2 + 4);
	v3[8] = a2[8];
	return v3;
}

//----- (00570670) --------------------------------------------------------
int **__thiscall sub_570670(int **this)
{
	int **result; // eax
	int **v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_5709C0(this[1], this[2]);
	sub_570A80(v2[1], ((char *)v2[3] - (char *)v2[1]) >> 4);
	result = v2;
	v2[1] = 0;
	v2[2] = 0;
	v2[3] = 0;
	return result;
}

//----- (005706E0) --------------------------------------------------------
_DWORD *__thiscall sub_5706E0(_DWORD *this, _DWORD *a2)
{
	unsigned int v2; // esi
	int *v3; // eax
	unsigned int v4; // esi
	int v5; // esi
	int v6; // eax
	int *v7; // eax
	int *v8; // eax
	int v9; // eax
	int *v10; // eax
	int *v12; // [esp-8h] [ebp-18h]
	int *v13; // [esp-8h] [ebp-18h]
	int *v14; // [esp-8h] [ebp-18h]
	int *v15; // [esp-4h] [ebp-14h]
	int *v16; // [esp-4h] [ebp-14h]
	char *v17; // [esp-4h] [ebp-14h]
	char *v18; // [esp-4h] [ebp-14h]
	_DWORD *v19; // [esp+4h] [ebp-Ch]
	int *v20; // [esp+8h] [ebp-8h]
	int *v21; // [esp+Ch] [ebp-4h]

	v19 = this;
	if (this != a2)
	{
		v2 = sub_5708A0(a2);
		if (v2 > sub_5708A0(v19))
		{
			v4 = sub_5708A0(a2);
			if (v4 > sub_570970(v19))
			{
				sub_5709C0((int *)v19[1], (int *)v19[2]);
				sub_570A80((LPVOID)v19[1], (v19[3] - v19[1]) >> 4);
				v9 = sub_5708A0(a2);
				v19[1] = sub_570A50(v9, 0);
				v18 = (char *)v19[1];
				v14 = (int *)wstring__size(a2);
				v10 = (int *)sub_575120(a2);
				v19[2] = sub_570A00(v10, v14, v18);
				v19[3] = v19[2];
			}
			else
			{
				v5 = sub_575120(a2);
				v6 = sub_5708A0(v19);
				v20 = (int *)(16 * v6 + v5);
				v16 = (int *)v19[1];
				v13 = (int *)(16 * v6 + v5);
				v7 = (int *)sub_575120(a2);
				sub_570B20(v7, v13, v16);
				v17 = (char *)v19[2];
				v8 = (int *)wstring__size(a2);
				sub_570A00(v20, v8, v17);
				v19[2] = 16 * sub_5708A0(a2) + v19[1];
			}
		}
		else
		{
			v15 = (int *)v19[1];
			v12 = (int *)wstring__size(a2);
			v3 = (int *)sub_575120(a2);
			v21 = sub_570B20(v3, v12, v15);
			sub_5709C0(v21, (int *)v19[2]);
			v19[2] = 16 * sub_5708A0(a2) + v19[1];
		}
	}
	return v19;
}

//----- (005708A0) --------------------------------------------------------
int __thiscall sub_5708A0(_DWORD *this)
{
	int v2; // [esp+0h] [ebp-8h]

	if (this[1])
		v2 = (this[2] - this[1]) >> 4;
	else
		v2 = 0;
	return v2;
}

//----- (005708F0) --------------------------------------------------------
int __thiscall sub_5708F0(_DWORD *this, int a2)
{
	return 16 * a2 + sub_575120(this);
}

//----- (00570920) --------------------------------------------------------
unsigned __int8 *__thiscall sub_570920(_DWORD *this)
{
	unsigned __int8 *v2; // [esp+0h] [ebp-8h]

	if (this[1])
		v2 = (unsigned __int8 *)this[1];
	else
		v2 = sub_570AB0();
	return v2;
}

//----- (00570970) --------------------------------------------------------
int __thiscall sub_570970(_DWORD *this)
{
	int v2; // [esp+0h] [ebp-8h]

	if (this[1])
		v2 = (this[3] - this[1]) >> 4;
	else
		v2 = 0;
	return v2;
}

//----- (005709C0) --------------------------------------------------------
int *__stdcall sub_5709C0(int *a1, int *a2)
{
	int *result; // eax

	while (a1 != a2)
	{
		sub_570AF0(a1);
		result = a1 + 4;
		a1 += 4;
	}
	return result;
}

//----- (00570A00) --------------------------------------------------------
char *__stdcall sub_570A00(int *a1, int *a2, char *a3)
{
	while (a1 != a2)
	{
		sub_570AC0(a3, a1);
		a3 += 16;
		a1 += 4;
	}
	return a3;
}

//----- (00570A50) --------------------------------------------------------
void *__stdcall sub_570A50(int a1, int a2)
{
	return sub_570B60(a1);
}

//----- (00570A80) --------------------------------------------------------
void __stdcall sub_570A80(LPVOID lpMem, int a2)
{
	operator_delete(lpMem);
}

//----- (00570AB0) --------------------------------------------------------
unsigned __int8 *sub_570AB0()
{
	return &byte_581450[11384];
}

//----- (00570AC0) --------------------------------------------------------
wstring *__stdcall sub_570AC0(void *a1, int *a2)
{
	return sub_570B90(a1, a2);
}

//----- (00570AF0) --------------------------------------------------------
int *__stdcall sub_570AF0(int *a1)
{
	return sub_570C30(a1);
}

//----- (00570B20) --------------------------------------------------------
int *__cdecl sub_570B20(int *a1, int *a2, int *a3)
{
	while (a1 != a2)
	{
		sub_570D10((wstring *)a3, (wstring *)a1);
		a3 += 4;
		a1 += 4;
	}
	return a3;
}

//----- (00570B60) --------------------------------------------------------
void *__cdecl sub_570B60(int a1)
{
	if (a1 < 0)
		a1 = 0;
	return operator_new(16 * a1);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00570B90) --------------------------------------------------------
wstring *__cdecl sub_570B90(void *a1, int *a2)
{
	wstring *result; // eax

	result = (wstring *)sub_570C20(16, (int)a1);
	if (result)
		result = sub_570C90(&result->_A, a2);
	return result;
}

//----- (00570C20) --------------------------------------------------------
int __cdecl sub_570C20(int a1, int a2)
{
	return a2;
}

//----- (00570C30) --------------------------------------------------------
int *__cdecl sub_570C30(int *a1)
{
	return sub_570C50(a1, 0);
}

//----- (00570C50) --------------------------------------------------------
int *__thiscall sub_570C50(int *this, char a2)
{
	int *lpMem; // [esp+0h] [ebp-4h]

	lpMem = this;
	sub_570CE0(this);
	if (a2 & 1)
		operator_delete(lpMem);
	return lpMem;
}

//----- (00570C90) --------------------------------------------------------
wstring *__thiscall sub_570C90(int *this, int *a2)
{
	wstring *v3; // [esp+0h] [ebp-4h]

	v3 = (wstring *)this;
	*(_BYTE *)this = *(_BYTE *)a2;
	sub_570F70((wstring *)this, 0);
	sub_570D80(v3, (wstring *)a2, 0, 0xFFFFFFFF);
	return v3;
}

//----- (00570CE0) --------------------------------------------------------
wstring *__thiscall sub_570CE0(int *this)
{
	return sub_570F70((wstring *)this, 1);
}

//----- (00570D10) --------------------------------------------------------
wstring *__thiscall sub_570D10(wstring *this, wstring *a2)
{
	return wstring__assign_0(this, a2);
}

//----- (00570D40) --------------------------------------------------------
wstring *__thiscall wstring__assign_0(wstring *this, wstring *a2)
{
	return sub_570D80(this, a2, 0, 0xFFFFFFFF);
}

//----- (00570D80) --------------------------------------------------------
wstring *__thiscall sub_570D80(wstring *this, wstring *a2, unsigned int a3, unsigned int a4)
{
	unsigned __int8 *v4; // eax
	unsigned __int8 *v5; // eax
	_BYTE *v7; // [esp+0h] [ebp-Ch]
	unsigned int _N; // [esp+8h] [ebp-4h]

	if (wstring__size(a2) < a3)
		std___Xran();
	_N = wstring__size(a2) - a3;
	if (a4 < _N)
		_N = a4;
	if (this == a2)
	{
		sub_571040(this, _N + a3, 0xFFFFFFFF);
		sub_571040(this, 0, a3);
	}
	else if (_N
		&& _N == wstring__size(a2)
		&& (v4 = sub_570920(a2), (int)*(unsigned __int8 *)sub_576600((int)v4) < 254)
		&& sub_571750())
	{
		sub_570F70(this, 1);
		this->_Ptr = (int)sub_570920(a2);
		this->_Len = wstring__size(a2);
		this->_Rem = sub_5711E0(a2);
		v7 = (_BYTE *)sub_576600(this->_Ptr);
		++*v7;
	}
	else if (wstring___Grow(&this->_A, _N, 1))
	{
		v5 = sub_570920(a2);
		sub_570F00((_WORD *)this->_Ptr, &v5[2 * a3], _N);
		wstring___Eos(this, _N);
	}
	return this;
}
// 57F54C: using guessed type void __cdecl std___Xran();

//----- (00570F00) --------------------------------------------------------
_WORD *__cdecl sub_570F00(_WORD *a1, _WORD *a2, int a3)
{
	return sub_570F20(a1, a2, a3);
}

//----- (00570F20) --------------------------------------------------------
_WORD *__cdecl sub_570F20(_WORD *a1, _WORD *a2, int a3)
{
	_WORD *v4; // [esp+0h] [ebp-4h]

	v4 = a1;
	while (a3)
	{
		*v4 = *a2;
		++v4;
		++a2;
		--a3;
	}
	return a1;
}

//----- (00570F70) --------------------------------------------------------
wstring *__thiscall sub_570F70(wstring *this, char a2)
{
	_BYTE *v2; // ecx
	wstring *result; // eax

	if (a2 && this->_Ptr)
	{
		if (*(_BYTE *)sub_576600(this->_Ptr) && *(unsigned __int8 *)sub_576600(this->_Ptr) != 255)
		{
			v2 = (_BYTE *)sub_576600(this->_Ptr);
			--*v2;
		}
		else
		{
			sub_576330((LPVOID)(this->_Ptr - 2), this->_Rem + 2);
		}
	}
	this->_Ptr = 0;
	result = this;
	this->_Len = 0;
	this->_Rem = 0;
	return result;
}

//----- (00571040) --------------------------------------------------------
wstring *__thiscall sub_571040(wstring *this, unsigned int a2, unsigned int a3)
{
	wstring *v4; // [esp+0h] [ebp-8h]
	unsigned int v5; // [esp+4h] [ebp-4h]

	v4 = this;
	if (this->_Len < a2)
		std___Xran();
	sub_571590(v4);
	if (v4->_Len - a2 < a3)
		a3 = v4->_Len - a2;
	if (a3)
	{
		sub_571110(v4->_Ptr + 2 * a2, (_WORD *)(v4->_Ptr + 2 * a2 + 2 * a3), v4->_Len - a2 - a3);
		v5 = v4->_Len - a3;
		if (wstring___Grow(&v4->_A, v5, 0))
			wstring___Eos(v4, v5);
	}
	return v4;
}
// 57F54C: using guessed type void __cdecl std___Xran();

//----- (00571110) --------------------------------------------------------
unsigned int __cdecl sub_571110(unsigned int a1, _WORD *a2, int a3)
{
	return sub_571130(a1, a2, a3);
}

//----- (00571130) --------------------------------------------------------
unsigned int __cdecl sub_571130(unsigned int a1, _WORD *a2, int a3)
{
	_WORD *v4; // [esp+0h] [ebp-4h]
	_WORD *v5; // [esp+0h] [ebp-4h]
	_WORD *v6; // [esp+10h] [ebp+Ch]

	v4 = (_WORD *)a1;
	if ((unsigned int)a2 >= a1 || a1 >= (unsigned int)&a2[a3])
	{
		while (a3)
		{
			*v4 = *a2;
			++v4;
			++a2;
			--a3;
		}
	}
	else
	{
		v5 = (_WORD *)(a1 + 2 * a3);
		v6 = &a2[a3];
		while (a3)
		{
			--v6;
			--v5;
			*v5 = *v6;
			--a3;
		}
	}
	return a1;
}

//----- (005711E0) --------------------------------------------------------
int __thiscall sub_5711E0(_DWORD *this)
{
	return this[3];
}

//----- (00571200) --------------------------------------------------------
_WORD *__thiscall wstring___Eos(_DWORD *this, int a2)
{
	int v3; // [esp+4h] [ebp-4h]

	v3 = -859045888;
	this[2] = a2;
	return wchar_t__assign_0((_WORD *)(this[1] + 2 * a2), &v3);
}

//----- (00571250) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
_WORD *__cdecl wchar_t__assign_0(_WORD *a1, _WORD *a2)
{
	_WORD *result; // eax

	result = a1;
	*a1 = *a2;
	return result;
}

//----- (00571270) --------------------------------------------------------
char __thiscall wstring___Grow(int *this, unsigned int _N, char a3)
{
	_BYTE *v3; // eax
	char result; // al
	wstring *v5; // [esp+4h] [ebp-4h]

	v5 = (wstring *)this;
	if (wstring__max_size() < _N)
		std___Xlen();
	if (v5->_Ptr && *(_BYTE *)sub_576600(v5->_Ptr) && *(unsigned __int8 *)sub_576600(v5->_Ptr) != 255)
	{
		if (_N)
		{
			sub_571430(&v5->_A, _N);
			result = 1;
		}
		else
		{
			v3 = (_BYTE *)sub_576600(v5->_Ptr);
			--*v3;
			sub_570F70(v5, 0);
			result = 0;
		}
	}
	else if (_N)
	{
		if (a3 && (v5->_Rem > 0x1Fu || v5->_Rem < _N))
		{
			sub_570F70(v5, 1);
			sub_571430(&v5->_A, _N);
		}
		else if (!a3 && v5->_Rem < _N)
		{
			sub_571430(&v5->_A, _N);
		}
		result = 1;
	}
	else
	{
		if (a3)
		{
			sub_570F70(v5, 1);
		}
		else if (v5->_Ptr)
		{
			wstring___Eos(v5, 0);
		}
		result = 0;
	}
	return result;
}

//----- (005713D0) --------------------------------------------------------
int wstring__max_size()
{
	int v1; // [esp+0h] [ebp-Ch]
	unsigned int v2; // [esp+8h] [ebp-4h]

	v2 = sub_5716A0();
	if (v2 > 2)
		v1 = v2 - 2;
	else
		v1 = 1;
	return v1;
}

//----- (00571430) --------------------------------------------------------
_WORD *__thiscall sub_571430(int *this, unsigned int a2)
{
	unsigned int v2; // eax
	int v4; // [esp+0h] [ebp-38h]
	int v5; // [esp+Ch] [ebp-2Ch]
	int v6; // [esp+10h] [ebp-28h]
	_WORD *v7; // [esp+14h] [ebp-24h]
	wstring *v8; // [esp+18h] [ebp-20h]
	unsigned int v9; // [esp+1Ch] [ebp-1Ch]
	_WORD *v10; // [esp+20h] [ebp-18h]
	unsigned int v11; // [esp+24h] [ebp-14h]
	int *v12; // [esp+28h] [ebp-10h]
	int v13; // [esp+34h] [ebp-4h]

	v12 = &v4;
	v5 = 0xCCCCCCCC;
	v6 = 0xCCCCCCCC;
	v7 = (_WORD *)0xCCCCCCCC;
	v10 = (_WORD *)0xCCCCCCCC;
	v11 = 0xCCCCCCCC;
	v8 = (wstring *)this;
	v2 = a2;
	LOBYTE(v2) = a2 | 0x1F;
	v9 = v2;
	if (wstring__max_size() < v2)
		v9 = a2;
	v13 = 0;
	v7 = sub_571670(v9 + 2, 0);
	v10 = v7;
	v13 = -1;
	if (v8->_Len)
	{
		if (v8->_Len <= v9)
			v6 = v8->_Len;
		else
			v6 = v9;
		sub_570F00(v10 + 1, (_WORD *)v8->_Ptr, v6);
	}
	v11 = v8->_Len;
	sub_570F70(v8, 1);
	v8->_Ptr = (int)(v10 + 1);
	*(_BYTE *)sub_576600(v8->_Ptr) = 0;
	v8->_Rem = v9;
	if (v11 <= v9)
		v5 = v11;
	else
		v5 = v9;
	return wstring___Eos(v8, v5);
}

//----- (00571590) --------------------------------------------------------
wstring *__thiscall sub_571590(wstring *this)
{
	wstring *result; // eax
	wstring *v2; // [esp+0h] [ebp-8h]
	wchar_t *v3; // [esp+4h] [ebp-4h]

	v2 = this;
	result = this;
	if (this->_Ptr)
	{
		result = (wstring *)sub_576600(this->_Ptr);
		if (LOBYTE(result->_A))
		{
			result = (wstring *)sub_576600(v2->_Ptr);
			if (LOBYTE(result->_A) != 255)
			{
				v3 = (wchar_t *)v2->_Ptr;
				sub_570F70(v2, 1);
				result = (wstring *)sub_571610(&v2->_A, v3);
			}
		}
	}
	return result;
}

//----- (00571610) --------------------------------------------------------
int *__thiscall sub_571610(int *this, wchar_t *a2)
{
	unsigned int v2; // eax
	int *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v2 = sub_571650(a2);
	return sub_5716F0(v4, a2, v2);
}

//----- (00571650) --------------------------------------------------------
size_t __cdecl sub_571650(wchar_t *a1)
{
	return wcslen(a1);
}

//----- (00571670) --------------------------------------------------------
void *__stdcall sub_571670(int a1, int a2)
{
	return sub_571760(a1);
}

//----- (005716A0) --------------------------------------------------------
int sub_5716A0()
{
	return 0x7FFFFFFF;
}

//----- (005716F0) --------------------------------------------------------
int *__thiscall sub_5716F0(int *this, _WORD *a2, unsigned int a3)
{
	int *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	if (wstring___Grow(this, a3, 1))
	{
		sub_570F00((_WORD *)v4[1], a2, a3);
		wstring___Eos(v4, a3);
	}
	return v4;
}

//----- (00571750) --------------------------------------------------------
char sub_571750()
{
	return 1;
}

//----- (00571760) --------------------------------------------------------
void *__cdecl sub_571760(int a1)
{
	if (a1 < 0)
		a1 = 0;
	return operator_new(2 * a1);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00571790) --------------------------------------------------------
int sub_571790()
{
	int result; // eax

	result = byte_5D4594[2659988] & 1;
	if (!(byte_5D4594[2659988] & 1))
		byte_5D4594[2659988] |= 1u;
	return result;
}

//----- (005717C0) --------------------------------------------------------
void __cdecl sub_5717C0()
{
	;
}

//----- (005717D0) --------------------------------------------------------
_DWORD *__thiscall sub_5717D0(_DWORD *this)
{
	_DWORD *v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	v3 = -858993460;
	v2 = this;
	*this = 0;
	sub_5745A0(this + 4, &v3);
	return v2;
}

//----- (00571810) --------------------------------------------------------
char __cdecl sub_571810(int a1, LPCSTR lpMultiByteStr)
{
	WCHAR *v2; // eax
	int v4; // [esp-4h] [ebp-38h]
	wstring *v5; // [esp+4h] [ebp-30h]
	int v6; // [esp+Ch] [ebp-28h]
	int v7[4]; // [esp+10h] [ebp-24h]
	int cchWideChar; // [esp+20h] [ebp-14h]
	int v9; // [esp+24h] [ebp-10h]
	int v10; // [esp+30h] [ebp-4h]

	v6 = -858993460;
	v7[0] = -858993460;
	v7[1] = -858993460;
	v7[2] = -858993460;
	v7[3] = -858993460;
	v9 = -858993664;
	cchWideChar = MultiByteToWideChar(0, 0, lpMultiByteStr, -1, 0, 0);
	if (cchWideChar)
	{
		v5 = wstring__wstring((wstring *)v7, cchWideChar - 1, 0x58u, &v6);
		v10 = 0;
		sub_570D10((wstring *)a1, v5);
		v10 = -1;
		sub_570CE0(v7);
		v4 = cchWideChar;
		v2 = (WCHAR *)sub_574050((int *)a1);
		cchWideChar = MultiByteToWideChar(0, 0, lpMultiByteStr, -1, v2, v4);
		if (cchWideChar)
			LOBYTE(v9) = 1;
	}
	return v9;
}

//----- (00571905) --------------------------------------------------------
unsigned __int8 *sub_571905()
{
	if (!(byte_5D4594[2516444] & 1))
	{
		byte_5D4594[2516444] |= 1u;
		sub_573C40(&byte_5D4594[2516428]);
		atexit(sub_57194A);
	}
	return &byte_5D4594[2516428];
}

//----- (0057194A) --------------------------------------------------------
void __cdecl sub_57194A()
{
	sub_573C80((int *)&byte_5D4594[2516428]);
}

//----- (00571960) --------------------------------------------------------
int __thiscall sub_571960(int *this, char a2)
{
	_DWORD *v2; // eax
	int v4; // [esp+0h] [ebp-14h]
	int *v5; // [esp+4h] [ebp-10h]
	int v6; // [esp+8h] [ebp-Ch]
	int v7; // [esp+Ch] [ebp-8h]
	int v8; // [esp+10h] [ebp-4h]

	v6 = -858993460;
	v7 = -858993460;
	v8 = -858993460;
	v5 = this;
	v8 = *sub_5743C0(this, &v7, &a2);
	v2 = sub_574290(v5, &v6);
	if (sub_574530(&v8, v2))
		v4 = 0;
	else
		v4 = *(_DWORD *)(sub_574500(&v8) + 4);
	return v4;
}

//----- (005719DA) --------------------------------------------------------
int __thiscall sub_5719DA(int *this, char a2)
{
	_DWORD *v2; // eax
	int v4; // [esp+0h] [ebp-14h]
	int *v5; // [esp+4h] [ebp-10h]
	int v6; // [esp+8h] [ebp-Ch]
	int v7; // [esp+Ch] [ebp-8h]
	int v8; // [esp+10h] [ebp-4h]

	v6 = -858993460;
	v7 = -858993460;
	v8 = -858993460;
	v5 = this;
	v8 = *sub_5743C0(this, &v7, &a2);
	v2 = sub_574290(v5, &v6);
	if (sub_574530(&v8, v2))
		v4 = 0;
	else
		v4 = *(_DWORD *)(sub_574500(&v8) + 8);
	return v4;
}

//----- (00571A54) --------------------------------------------------------
int __thiscall sub_571A54(int *this, int a2, int a3, int a4)
{
	_DWORD *v4; // eax
	int *v6; // eax
	int v7; // esi
	int v8; // edi
	_DWORD *v9; // eax
	int *v10; // [esp+8h] [ebp-18h]
	int v11[2]; // [esp+Ch] [ebp-14h]
	int v12; // [esp+14h] [ebp-Ch]
	int v13; // [esp+18h] [ebp-8h]
	int v14; // [esp+1Ch] [ebp-4h]

	v11[0] = 0xCCCCCCCC;
	v11[1] = 0xCCCCCCCC;
	v12 = 0xCCCCCCCC;
	v13 = 0xCCCCCCCC;
	v14 = 0xCCCCCCCC;
	v10 = this;
	v14 = *sub_5743C0(this, &v13, &a2);
	v4 = sub_574290(v10, &v12);
	if (sub_574560(&v14, v4))
		return -2147467259;
	v6 = sub_573CE0(v11, a3, a4);
	v7 = *v6;
	v8 = v6[1];
	v9 = (_DWORD *)sub_5742D0(v10, &a2);
	*v9 = v7;
	v9[1] = v8;
	return 0;
}

//----- (00571AEA) --------------------------------------------------------
int __thiscall sub_571AEA(int *this, char a2)
{
	_DWORD *v2; // eax
	int *v4; // [esp+0h] [ebp-14h]
	int v5; // [esp+4h] [ebp-10h]
	int v6; // [esp+8h] [ebp-Ch]
	int v7; // [esp+Ch] [ebp-8h]
	int v8; // [esp+10h] [ebp-4h]

	v5 = -858993460;
	v6 = -858993460;
	v7 = -858993460;
	v8 = -858993460;
	v4 = this;
	v8 = *sub_5743C0(this, &v7, &a2);
	v2 = sub_574290(v4, &v6);
	if (sub_574530(&v8, v2))
		return -2147467259;
	sub_574370(v4, &v5, v8);
	return 0;
}

//----- (00571B63) --------------------------------------------------------
LONG __thiscall sub_571B63(HIMC *this, DWORD a2, LPWSTR lpWideCharStr, int cchWideChar)
{
	int v5; // eax
	int v6; // [esp+8h] [ebp-20h]
	char Buf[24]; // [esp+Ch] [ebp-1Ch]
	LONG v8; // [esp+24h] [ebp-4h]

	*(_DWORD *)Buf = -858993460;
	*(_DWORD *)&Buf[4] = -858993460;
	*(_DWORD *)&Buf[8] = -858993460;
	*(_DWORD *)&Buf[12] = -858993460;
	*(_DWORD *)&Buf[16] = -858993460;
	*(_DWORD *)&Buf[20] = -858993460;
	v8 = -858993460;
	v8 = ImmGetCompositionStringA(this[1], a2, Buf, 0x18u);
	if (v8 < 0)
		return v8;
	Buf[v8] = 0;
	v5 = strlen(Buf);
	v6 = MultiByteToWideChar(0, 0, Buf, v5, lpWideCharStr, cchWideChar);
	if (lpWideCharStr)
		lpWideCharStr[v6] = 0;
	return v6;
}

//----- (00571C0E) --------------------------------------------------------
int __thiscall sub_571C0E(HIMC *this, DWORD dwIndex, LPCWSTR lpWideCharStr, int a4, LPCWSTR a5, int a6)
{
	CHAR *v6; // eax
	CHAR *v8; // eax
	int v9; // [esp-Ch] [ebp-A8h]
	int v10; // [esp-Ch] [ebp-A8h]
	int *v11; // [esp+8h] [ebp-94h]
	int *v12; // [esp+10h] [ebp-8Ch]
	HIMC *v13; // [esp+18h] [ebp-84h]
	BOOL v14; // [esp+1Ch] [ebp-80h]
	int v15; // [esp+20h] [ebp-7Ch]
	char v16; // [esp+24h] [ebp-78h]
	int v17[6]; // [esp+28h] [ebp-74h]
	int v18[6]; // [esp+40h] [ebp-5Ch]
	int v19; // [esp+58h] [ebp-44h]
	int cbMultiByte; // [esp+5Ch] [ebp-40h]
	LPVOID lpRead; // [esp+60h] [ebp-3Ch]
	DWORD dwCompLen; // [esp+64h] [ebp-38h]
	DWORD dwReadLen; // [esp+68h] [ebp-34h]
	int v24[4]; // [esp+6Ch] [ebp-30h]
	LPVOID lpComp; // [esp+7Ch] [ebp-20h]
	int v26[6]; // [esp+80h] [ebp-1Ch]
	int v27; // [esp+98h] [ebp-4h]

	v13 = this;
	sub_573D50(v24, &v18[5]);
	v27 = 0;
	sub_573D50(v26, &v18[4]);
	LOBYTE(v27) = 1;
	lpRead = 0;
	lpComp = 0;
	dwCompLen = 0;
	dwReadLen = 0;
	if (lpWideCharStr)
	{
		cbMultiByte = WideCharToMultiByte(0, 0, lpWideCharStr, -1, 0, 0, 0, 0);
		v12 = sub_573D90(v18, (_DWORD *)cbMultiByte, 88, &v17[5]);
		LOBYTE(v27) = 2;
		sub_573E10(v26, v12);
		LOBYTE(v27) = 1;
		sub_573DE0(v18);
		v9 = cbMultiByte;
		v6 = (CHAR *)sub_573E40(v26);
		cbMultiByte = WideCharToMultiByte(0, 0, lpWideCharStr, -1, v6, v9, 0, 0);
		if (cbMultiByte < 0)
		{
			v17[4] = cbMultiByte;
			LOBYTE(v27) = 0;
			sub_573DE0(v26);
			v27 = -1;
			sub_573DE0(v24);
			return v17[4];
		}
		lpComp = sub_573E70(v26);
		dwCompLen = wstring__size(v26);
	}
	if (a5)
	{
		v19 = WideCharToMultiByte(0, 0, a5, -1, 0, 0, 0, 0);
		v11 = sub_573D90(v17, (_DWORD *)v19, 88, &v16);
		LOBYTE(v27) = 3;
		sub_573E10(v24, v11);
		LOBYTE(v27) = 1;
		sub_573DE0(v17);
		v10 = v19;
		v8 = (CHAR *)sub_573E40(v24);
		v19 = WideCharToMultiByte(0, 0, a5, -1, v8, v10, 0, 0);
		if (v19 < 0)
		{
			v15 = v19;
			LOBYTE(v27) = 0;
			sub_573DE0(v26);
			v27 = -1;
			sub_573DE0(v24);
			return v15;
		}
		lpRead = sub_573E70(v24);
		dwReadLen = wstring__size(v24);
	}
	v14 = ImmSetCompositionStringA(v13[1], dwIndex, lpComp, dwCompLen, lpRead, dwReadLen);
	LOBYTE(v27) = 0;
	sub_573DE0(v26);
	v27 = -1;
	sub_573DE0(v24);
	return v14;
}

//----- (00571EAD) --------------------------------------------------------
BOOL __thiscall sub_571EAD(HIMC *this, DWORD dwIndex, DWORD dwValue, int a4)
{
	HIMC *v5; // [esp+0h] [ebp-4h]

	v5 = this;
	sub_571F46(this, NI_SETCANDIDATE_PAGESIZE, dwIndex, a4 - dwValue);
	return sub_571F46(v5, NI_SETCANDIDATE_PAGESTART, dwIndex, dwValue);
}

//----- (00571EF2) --------------------------------------------------------
void __stdcall sub_571EF2(int a1, int a2)
{
	;
}

//----- (00571F06) --------------------------------------------------------
BOOL __thiscall sub_571F06(HIMC *this, DWORD dwIndex, DWORD dwValue)
{
	HIMC *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	sub_571F46(this, NI_SELECTCANDIDATESTR, dwIndex, dwValue);
	return sub_571F46(v4, NI_CLOSECANDIDATE, dwIndex, 0);
}

//----- (00571F46) --------------------------------------------------------
BOOL __thiscall sub_571F46(HIMC *this, DWORD dwAction, DWORD dwIndex, DWORD dwValue)
{
	return ImmNotifyIME(this[1], dwAction, dwIndex, dwValue);
}

//----- (00571F7C) --------------------------------------------------------
BOOL __thiscall sub_571F7C(HIMC *this)
{
	return ImmGetOpenStatus(this[1]);
}

//----- (00571FA4) --------------------------------------------------------
BOOL __thiscall sub_571FA4(HIMC *this, BOOL a2)
{
	return ImmSetOpenStatus(this[1], a2);
}

//----- (00571FE1) --------------------------------------------------------
BOOL __thiscall sub_571FE1(HIMC *this, LPCOMPOSITIONFORM lpCompForm)
{
	return ImmSetCompositionWindow(this[1], lpCompForm);
}

//----- (0057200F) --------------------------------------------------------
DWORD __thiscall sub_57200F(HIMC *this, DWORD deIndex, LPCANDIDATELIST lpCandList, DWORD dwBufLen)
{
	return ImmGetCandidateListA(this[1], deIndex, lpCandList, dwBufLen);
}

//----- (00572045) --------------------------------------------------------
int *__thiscall sub_572045(int *this)
{
	int *v2; // [esp+0h] [ebp-20h]
	int v3; // [esp+4h] [ebp-1Ch]
	int v4; // [esp+8h] [ebp-18h]
	int v5; // [esp+Ch] [ebp-14h]
	int v6; // [esp+10h] [ebp-10h]
	int v7; // [esp+1Ch] [ebp-4h]

	v3 = -858993460;
	v4 = -858993460;
	v5 = -858993460;
	v6 = -858993460;
	v2 = this;
	sub_573F40(this + 2, &v6);
	v7 = 0;
	sub_573F40(v2 + 6, &v5);
	LOBYTE(v7) = 1;
	sub_573F40(v2 + 10, &v4);
	LOBYTE(v7) = 2;
	sub_5745A0(v2 + 14, &v3);
	*((_BYTE *)v2 + 72) = 0;
	v2[19] = 0;
	v2[20] = 0;
	v2[21] = -1;
	v2[23] = 0;
	*v2 = (int)&byte_581450[11420];
	return v2;
}

//----- (0057211C) --------------------------------------------------------
wstring *__thiscall sub_57211C(HIMC *this)
{
	HIMC *v2; // [esp+0h] [ebp-10h]

	v2 = this;
	*this = (HIMC)&byte_581450[11420];
	if (this[23])
		ImmDestroyContext(this[23]);
	sub_5740C0((int ***)v2 + 14);
	sub_570CE0((int *)v2 + 10);
	sub_570CE0((int *)v2 + 6);
	return sub_570CE0((int *)v2 + 2);
}

//----- (005721B7) --------------------------------------------------------
_BYTE *__thiscall sub_5721B7(_BYTE *this)
{
	_BYTE *result; // eax

	result = this;
	this[72] = 1;
	return result;
}

//----- (005721D0) --------------------------------------------------------
int *__thiscall sub_5721D0(int this)
{
	*(_BYTE *)(this + 72) = 0;
	return sub_574020((int *)(this + 8), (wchar_t *)&byte_5D4594[2516448]);
}

//----- (00572203) --------------------------------------------------------
unsigned __int8 *__thiscall sub_572203(_DWORD *this)
{
	return sub_570920(this + 2);
}

//----- (0057222A) --------------------------------------------------------
void __thiscall sub_57222A(int *this, int a2, int a3)
{
	wstring *v4; // eax
	WCHAR *v5; // eax
	int v6; // [esp-4h] [ebp-40h]
	int *v7; // [esp+Ch] [ebp-30h]
	char a4; // [esp+10h] [ebp-2Ch]
	int v9[4]; // [esp+14h] [ebp-28h]
	int cchWideChar; // [esp+24h] [ebp-18h]
	struc_35 v11; // [esp+28h] [ebp-14h]

	v7 = this;
	sub_574E10(&v11, (HWND)a2);
	v11.field_10 = 0;
	if (sub_574F30(&v11))
	{
		v11.field_10 = -1;
		sub_574EC0(&v11);
	}
	else
	{
		cchWideChar = sub_571B63(&v11, 8u, 0, 0);
		if (cchWideChar >= 0)
		{
			v4 = wstring__wstring((wstring *)v9, cchWideChar, 0x58u, &a4);
			LOBYTE(v11.field_10) = 1;
			sub_570D10((wstring *)(v7 + 2), v4);
			LOBYTE(v11.field_10) = 0;
			sub_570CE0(v9);
			v6 = cchWideChar;
			v5 = (WCHAR *)sub_574050(v7 + 2);
			sub_571B63(&v11, 8u, v5, v6);
			v11.field_10 = -1;
			sub_574EC0(&v11);
		}
		else
		{
			v11.field_10 = -1;
			sub_574EC0(&v11);
		}
	}
}

//----- (00572333) --------------------------------------------------------
void __thiscall sub_572333(int *this, int a2)
{
	wstring *v3; // eax
	WCHAR *v4; // eax
	int v5; // [esp-4h] [ebp-40h]
	int *v6; // [esp+Ch] [ebp-30h]
	char a4; // [esp+10h] [ebp-2Ch]
	int v8[4]; // [esp+14h] [ebp-28h]
	int cchWideChar; // [esp+24h] [ebp-18h]
	struc_35 v10; // [esp+28h] [ebp-14h]

	v6 = this;
	sub_574E10(&v10, (HWND)a2);
	v10.field_10 = 0;
	if (sub_574F30(&v10))
	{
		v10.field_10 = -1;
		sub_574EC0(&v10);
	}
	else
	{
		cchWideChar = sub_571B63(&v10, 0x800u, 0, 0);
		if (cchWideChar >= 0)
		{
			v3 = wstring__wstring((wstring *)v8, cchWideChar, 0x58u, &a4);
			LOBYTE(v10.field_10) = 1;
			sub_570D10((wstring *)(v6 + 6), v3);
			LOBYTE(v10.field_10) = 0;
			sub_570CE0(v8);
			v5 = cchWideChar;
			v4 = (WCHAR *)sub_574050(v6 + 6);
			sub_571B63(&v10, 0x800u, v4, v5);
			v10.field_10 = -1;
			sub_574EC0(&v10);
		}
		else
		{
			v10.field_10 = -1;
			sub_574EC0(&v10);
		}
	}
}

//----- (00572442) --------------------------------------------------------
int *__thiscall sub_572442(int *this, int a2, int a3, int a4)
{
	int *result; // eax
	unsigned __int8 *v5; // eax
	int v6; // [esp-Ch] [ebp-148h]
	int *v7; // [esp+8h] [ebp-134h]
	int v8[4]; // [esp+Ch] [ebp-130h]
	int v9; // [esp+1Ch] [ebp-120h]
	unsigned __int8 *v10; // [esp+20h] [ebp-11Ch]
	CHAR szDescription[256]; // [esp+24h] [ebp-118h]
	HKL v12; // [esp+124h] [ebp-18h]
	struc_35 v13; // [esp+128h] [ebp-14h]

	v7 = this;
	result = (int *)(a4 & 0x800);
	if (a4 & 0x800)
	{
		sub_572333(this, a2);
		sub_57222A(v7, a2, a4);
		goto LABEL_8;
	}
	if (a4 & 8)
	{
		sub_57222A(this, a2, a4);
	LABEL_8:
		sub_574E10(&v13, (HWND)a2);
		v13.field_10 = 0;
		if (sub_574F30(&v13))
		{
			v13.field_10 = -1;
			result = (int *)sub_574EC0(&v13);
		}
		else
		{
			v12 = GetKeyboardLayout(0);
			ImmGetDescriptionA(v12, szDescription, 0x100u);
			LOBYTE(v9) = strncmp(szDescription, (const char *)&byte_587000[311272], 0x10u) == 0;
			v10 = sub_570920(v7 + 2);
			if (wstring__size(v7 + 2) > (unsigned int)v7[22])
			{
				sub_570C90(v8, v7 + 2);
				LOBYTE(v13.field_10) = 1;
				sub_571040((wstring *)v8, v7[22], 0xFFFFFFFF);
				if (wstring__size(v8))
				{
					sub_571F46(&v13, NI_COMPOSITIONSTR, CPS_CANCEL, 0);
					v6 = wstring__size(v8);
					v5 = sub_570920(v8);
					sub_571C0E((HIMC *)&v13, 9u, (LPCWSTR)v5, v6, 0, 0);
				}
				else
				{
					sub_571F46(&v13, NI_COMPOSITIONSTR, CPS_CANCEL, 0);
				}
				LOBYTE(v13.field_10) = 0;
				sub_570CE0(v8);
			}
			v13.field_10 = -1;
			result = (int *)sub_574EC0(&v13);
		}
		return result;
	}
	if (!a4)
		result = sub_574020(this + 2, (wchar_t *)&byte_5D4594[2516452]);
	return result;
}

//----- (005726A9) --------------------------------------------------------
int *__thiscall sub_5726A9(_DWORD *this)
{
	_DWORD *v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_574210(this + 14);
	return sub_574020(v2 + 2, (wchar_t *)&byte_5D4594[2516456]);
}

//----- (005726E0) --------------------------------------------------------
void __thiscall sub_5726E0(_DWORD *this)
{
	_DWORD *v2; // [esp+0h] [ebp-1Ch]
	struc_35 v3; // [esp+8h] [ebp-14h]

	v3.field_0 = (HWND)-858993460;
	v3.field_4 = (HIMC)-858993460;
	v2 = this;
	sub_5726A9(this);
	sub_574E10(&v3, (HWND)v2[19]);
	v3.field_10 = 0;
	if (sub_574F30(&v3))
	{
		v3.field_10 = -1;
		sub_574EC0(&v3);
	}
	else
	{
		if (sub_571F7C((HIMC *)&v3))
		{
			sub_571FA4(&v3, 0);
			sub_571FA4(&v3, 1);
		}
		v3.field_10 = -1;
		sub_574EC0(&v3);
	}
}

//----- (00572796) --------------------------------------------------------
int __stdcall sub_572796(int a1)
{
	return 0;
}

//----- (005727AC) --------------------------------------------------------
int __thiscall sub_5727AC(void(__stdcall **this)(HWND, int, _DWORD, LPARAM), HWND hWnd, int a3, LPARAM lParam)
{
	int v4; // eax
	void(__stdcall **v6)(HWND, int, _DWORD, LPARAM); // [esp+4h] [ebp-14h]
	int v7; // [esp+8h] [ebp-10h]
	int v8; // [esp+Ch] [ebp-Ch]
	WCHAR WideCharStr[2]; // [esp+10h] [ebp-8h]
	LPCSTR lpMultiByteStr; // [esp+14h] [ebp-4h]

	v6 = this;
	v8 = -858993460;
	v7 = 52428;
	*(_DWORD *)WideCharStr = 0;
	lpMultiByteStr = (LPCSTR)&v7;
	v4 = strlen((const char *)&v7);
	if (MultiByteToWideChar(0, 0, lpMultiByteStr, v4, WideCharStr, 1) == 1)
	{
		if (v6[20])
			v6[20](hWnd, 1040, WideCharStr[0], lParam);
		else
			DefWindowProcA(hWnd, 0x410u, WideCharStr[0], lParam);
	}
	return 1;
}

//----- (005728C1) --------------------------------------------------------
int __thiscall sub_5728C1(void(__stdcall **this)(HWND, int, _DWORD, LPARAM), HWND hWnd, char a3, LPARAM lParam)
{
	void(__stdcall **v5)(HWND, int, _DWORD, LPARAM); // [esp+8h] [ebp-34h]
	struct tagMSG Msg; // [esp+Ch] [ebp-30h]
	CHAR MultiByteStr[4]; // [esp+28h] [ebp-14h]
	int v8; // [esp+2Ch] [ebp-10h]
	WCHAR WideCharStr[2]; // [esp+30h] [ebp-Ch]
	int v10; // [esp+34h] [ebp-8h]
	int v11; // [esp+38h] [ebp-4h]

	v5 = this;
	v11 = 1;
	LOBYTE(v10) = a3;
	if (!IsDBCSLeadByte(a3))
		return 0;
	v8 = 10;
	while (!PeekMessageA(&Msg, hWnd, 0x102u, 0x102u, 1u))
	{
		if (!--v8)
			return 1;
	}
	*(_DWORD *)MultiByteStr = (unsigned __int16)((unsigned __int8)v10 | (unsigned __int16)(LOWORD(Msg.wParam) << 8));
	*(_DWORD *)WideCharStr = 0;
	if (MultiByteToWideChar(0, 0, MultiByteStr, 2, WideCharStr, 1) == 1)
	{
		if (v5[20])
			v5[20](hWnd, 1040, WideCharStr[0], lParam);
		else
			DefWindowProcA(hWnd, 0x410u, WideCharStr[0], lParam);
	}
	return v11;
}

//----- (00572A06) --------------------------------------------------------
void __thiscall sub_572A06(_DWORD *this, int a2)
{
	_DWORD *v3; // [esp+4h] [ebp-34h]
	struct tagCOMPOSITIONFORM CompForm; // [esp+8h] [ebp-30h]
	struc_35 v5; // [esp+24h] [ebp-14h]

	v3 = this;
	sub_574E10(&v5, (HWND)a2);
	v5.field_10 = 0;
	if (sub_574F30(&v5))
	{
		v5.field_10 = -1;
		sub_574EC0(&v5);
	}
	else
	{
		if (!sub_571F7C(&v5))
		{
			sub_5726A9(v3);
			CompForm.dwStyle = 2;
			CompForm.ptCurrentPos.x = 0;
			CompForm.ptCurrentPos.y = 0;
			sub_571FE1(&v5, &CompForm);
		}
		v5.field_10 = -1;
		sub_574EC0(&v5);
	}
}

//----- (00572AC5) --------------------------------------------------------
char __thiscall sub_572AC5(_DWORD *this, int a2, int a3, int a4)
{
	int v4; // eax
	char result; // al
	struct tagMSG Msg; // [esp+10h] [ebp-20h]
	int v7; // [esp+2Ch] [ebp-4h]

	switch (a3)
	{
	case 3:
		sub_57330C(this, a2, a4);
		goto LABEL_11;
	case 4:
		sub_573266(this, a2, a4);
		goto LABEL_11;
	case 5:
		sub_573153(this, a2, a4);
		v7 = 200;
		while (PeekMessageA(&Msg, 0, 0, 0, 1u))
		{
			v4 = v7--;
			if (!v4)
				break;
			TranslateMessage(&Msg);
			DispatchMessageA(&Msg);
		}
		goto LABEL_11;
	case 8:
		sub_572A06(this, a2);
	LABEL_11:
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (00572BD6) --------------------------------------------------------
HKL __cdecl sub_572BD6(char a1)
{
	HKL *v1; // eax
	int *v2; // eax
	_DWORD *v3; // eax
	_DWORD *v4; // eax
	_DWORD *v5; // eax
	_DWORD *v6; // eax
	int v7; // eax
	int v8; // eax
	int v10; // [esp-8h] [ebp-7Ch]
	char v11; // [esp+8h] [ebp-6Ch]
	char v12; // [esp+Ch] [ebp-68h]
	char v13; // [esp+10h] [ebp-64h]
	char v14; // [esp+14h] [ebp-60h]
	char v15; // [esp+18h] [ebp-5Ch]
	char v16; // [esp+1Ch] [ebp-58h]
	char v17; // [esp+20h] [ebp-54h]
	char v18; // [esp+24h] [ebp-50h]
	char v19; // [esp+28h] [ebp-4Ch]
	int v20; // [esp+2Ch] [ebp-48h]
	char v21; // [esp+30h] [ebp-44h]
	HKL *j; // [esp+34h] [ebp-40h]
	int v23[4]; // [esp+38h] [ebp-3Ch]
	int i; // [esp+48h] [ebp-2Ch]
	int v25; // [esp+4Ch] [ebp-28h]
	int v26[4]; // [esp+50h] [ebp-24h]
	int nBuff; // [esp+60h] [ebp-14h]
	HKL v28; // [esp+64h] [ebp-10h]
	int v29; // [esp+70h] [ebp-4h]

	v28 = 0;
	nBuff = GetKeyboardLayoutList(0, 0);
	if (nBuff)
	{
		v20 = 0;
		sub_5745E0(v26, nBuff, &v20, &v21);
		v29 = 0;
		sub_5746D0(v26, nBuff);
		v1 = (HKL *)sub_575120(v26);
		nBuff = GetKeyboardLayoutList(nBuff, v1);
		v10 = *sub_5747F0(v26, &v19);
		v2 = sub_5747A0(v26, &v18);
		v25 = *sub_578460(&v17, *v2, v10, &a1);
		v3 = sub_5747F0(v26, &v16);
		if (sub_5784B0(&v25, v3))
		{
			sub_5745A0(v23, &v15);
			LOBYTE(v29) = 1;
			sub_574880(&i);
			for (i = v25; ; sub_5748C0(&i, &v14, 0))
			{
				v4 = sub_5747F0(v26, &v13);
				if (!sub_5784B0(&i, v4))
					break;
				v5 = (_DWORD *)sub_5748A0(&i);
				sub_574840(v23, v5);
			}
			for (i = *sub_5747A0(v26, &v12); sub_5784B0(&i, &v25); sub_5748C0(&i, &v11, 0))
			{
				v6 = (_DWORD *)sub_5748A0(&i);
				sub_574840(v23, v6);
			}
			for (j = (HKL *)sub_575120(v23); ; ++j)
			{
				v7 = wstring__size(v23);
				if (j == (HKL *)v7 || !(ImmGetProperty(*j, 4u) & 0x30000))
					break;
			}
			v8 = wstring__size(v23);
			if (j != (HKL *)v8)
				v28 = *j;
			LOBYTE(v29) = 0;
			sub_574660(v23);
		}
		v29 = -1;
		sub_574660(v26);
	}
	return v28;
}

//----- (00572E05) --------------------------------------------------------
LRESULT __thiscall sub_572E05(_DWORD *this, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result; // eax
	_DWORD *v6; // [esp+8h] [ebp-Ch]
	HKL v7; // [esp+Ch] [ebp-8h]
	char v8; // [esp+10h] [ebp-4h]

	v8 = 1;
	v6 = this;
	if (Msg > 0x10F)
	{
		switch (Msg)
		{
		case WM_IME_SETCONTEXT:
			lParam &= 0x3FFFFFF0u;
			goto LABEL_28;
		case WM_IME_NOTIFY:
			if (!sub_572AC5(this, (int)hWnd, wParam, lParam))
				goto LABEL_28;
			result = 1;
			break;
		case WM_IME_CONTROL:
			result = 1;
			break;
		case WM_IME_COMPOSITIONFULL:
			result = 1;
			break;
		case WM_IME_CHAR:
			if (!sub_5727AC((void(__stdcall **)(HWND, int, _DWORD, LPARAM))this, hWnd, (unsigned __int16)wParam, lParam))
				goto LABEL_28;
			result = 1;
			break;
		case WM_IME_KEYDOWN:
		case WM_IME_KEYUP:
			result = 1;
			break;
		default:
			goto LABEL_28;
		}
	}
	else if (Msg == WM_IME_COMPOSITION)
	{
		sub_572442(this, (int)hWnd, wParam, lParam);
		result = DefWindowProcA(hWnd, 0x10Fu, wParam, lParam);
	}
	else
	{
		switch (Msg)
		{
		case WM_INPUTLANGCHANGEREQUEST:
			v7 = sub_572BD6(lParam);
			if (!v7)
				return 0;
			lParam = (LPARAM)v7;
			break;
		case WM_KEYDOWN:
			*((_BYTE *)this + wParam + 96) = 1;
			break;
		case WM_KEYUP:
			if (!*((_BYTE *)this + wParam + 96))
				v8 = 0;
			*((_BYTE *)this + wParam + 96) = 0;
			break;
		case WM_CHAR:
			if (!sub_5728C1((void(__stdcall **)(HWND, int, _DWORD, LPARAM))this, hWnd, wParam, lParam))
				break;
			return 1;
		case WM_IME_STARTCOMPOSITION:
			sub_5721B7(this);
			return 1;
		case WM_IME_ENDCOMPOSITION:
			sub_5721D0((int)this);
			return 1;
		default:
			break;
		}
	LABEL_28:
		if (v6[20] && v8)
			result = ((int(__stdcall *)(HWND, UINT, WPARAM, LPARAM))v6[20])(hWnd, Msg, wParam, lParam);
		else
			result = DefWindowProcA(hWnd, Msg, wParam, lParam);
	}
	return result;
}

//----- (00573153) --------------------------------------------------------
void __thiscall sub_573153(_DWORD *this, int a2, int a3)
{
	_DWORD *v4; // [esp+4h] [ebp-48h]
	_DWORD *v5; // [esp+Ch] [ebp-40h]
	int *v6[9]; // [esp+10h] [ebp-3Ch]
	DWORD deIndex; // [esp+34h] [ebp-18h]
	struc_35 v8; // [esp+38h] [ebp-14h]

	v5 = this;
	sub_574E10(&v8, (HWND)a2);
	v8.field_10 = 0;
	if (sub_574F30(&v8))
	{
		v8.field_10 = -1;
		sub_574EC0(&v8);
	}
	else
	{
		v4 = sub_5717D0(v6);
		LOBYTE(v8.field_10) = 1;
		sub_574160(v5 + 14, 0x20u, v4);
		LOBYTE(v8.field_10) = 0;
		sub_5705D0(v6);
		for (deIndex = 0; deIndex < 0x20; ++deIndex)
		{
			if ((1 << deIndex) & a3)
			{
				if (sub_573401(v5, (int)&v8, deIndex))
				{
					v5[1] = 2;
					v5[21] = deIndex;
				}
			}
		}
		v8.field_10 = -1;
		sub_574EC0(&v8);
	}
}

//----- (00573266) --------------------------------------------------------
int __thiscall sub_573266(_DWORD *this, int a2, int a3)
{
	int result; // eax
	_DWORD *v4; // [esp+0h] [ebp-Ch]
	int v5; // [esp+4h] [ebp-8h]
	int i; // [esp+8h] [ebp-4h]

	v4 = this;
	v5 = 0;
	for (i = sub_575120(this + 14); ; i += 36)
	{
		result = wstring__size(v4 + 14);
		if (i == result)
			break;
		if ((1 << v5) & a3)
		{
			if (v5 == v4[21])
				v4[21] = -1;
			sub_573F00((_DWORD *)(i + 16));
		}
		++v5;
	}
	v4[1] = 1;
	return result;
}

//----- (0057330C) --------------------------------------------------------
void __thiscall sub_57330C(_DWORD *this, int a2, int a3)
{
	_DWORD *v4; // [esp+4h] [ebp-48h]
	_DWORD *v5; // [esp+Ch] [ebp-40h]
	int *v6[9]; // [esp+10h] [ebp-3Ch]
	DWORD deIndex; // [esp+34h] [ebp-18h]
	struc_35 v8; // [esp+38h] [ebp-14h]

	v5 = this;
	sub_574E10(&v8, (HWND)a2);
	v8.field_10 = 0;
	v4 = sub_5717D0(v6);
	LOBYTE(v8.field_10) = 1;
	sub_574160(v5 + 14, 0x20u, v4);
	LOBYTE(v8.field_10) = 0;
	sub_5705D0(v6);
	for (deIndex = 0; deIndex < 0x20; ++deIndex)
	{
		if ((1 << deIndex) & a3 && sub_573401(v5, (int)&v8, deIndex))
		{
			v5[1] = 2;
			v5[21] = deIndex;
			break;
		}
	}
	v8.field_10 = -1;
	sub_574EC0(&v8);
}

//----- (00573401) --------------------------------------------------------
int __thiscall sub_573401(_DWORD *this, int a2, DWORD deIndex)
{
	int v3; // eax
	struct tagCANDIDATELIST *v4; // eax
	int v5; // eax
	int v6; // eax
	unsigned __int16 *v7; // eax
	int v8; // eax
	int v9; // eax
	DWORD v11; // [esp-4h] [ebp-70h]
	_DWORD *v12; // [esp+4h] [ebp-68h]
	_DWORD *v13; // [esp+8h] [ebp-64h]
	char v14; // [esp+Ch] [ebp-60h]
	wstring v15; // [esp+10h] [ebp-5Ch]
	int v16; // [esp+20h] [ebp-4Ch]
	char v17; // [esp+24h] [ebp-48h]
	void *v18; // [esp+28h] [ebp-44h]
	LPCSTR lpMultiByteStr; // [esp+2Ch] [ebp-40h]
	wstring v20; // [esp+30h] [ebp-3Ch]
	_DWORD *v21; // [esp+40h] [ebp-2Ch]
	unsigned int i; // [esp+44h] [ebp-28h]
	_DWORD *v23; // [esp+48h] [ebp-24h]
	LPVOID v24[2]; // [esp+4Ch] [ebp-20h]
	DWORD dwBufLen; // [esp+54h] [ebp-18h]
	int v26; // [esp+58h] [ebp-14h]
	int v27; // [esp+5Ch] [ebp-10h]
	int v28; // [esp+68h] [ebp-4h]

	v13 = this;
	v26 = 0;
	v27 = 0;
	v3 = sub_5741E0(this + 14, deIndex);
	sub_573F00((_DWORD *)(v3 + 16));
	v12 = (_DWORD *)sub_5741E0(v13 + 14, deIndex);
	++*v12;
	dwBufLen = sub_57200F((HIMC *)a2, deIndex, 0, 0);
	if (dwBufLen)
	{
		v18 = operator_new(dwBufLen);
		sub_574900(v24, (int)v18);
		v28 = 0;
		v11 = dwBufLen;
		v4 = (struct tagCANDIDATELIST *)sub_574980(v24);
		sub_57200F((HIMC *)a2, deIndex, v4, v11);
		v23 = (_DWORD *)sub_574980(v24);
		*(_DWORD *)(sub_5741E0(v13 + 14, deIndex) + 4) = v23[5];
		*(_DWORD *)(sub_5741E0(v13 + 14, deIndex) + 12) = v23[3];
		*(_DWORD *)(sub_5741E0(v13 + 14, deIndex) + 8) = v23[4];
		v21 = v23 + 6;
		sub_573F40(&v20, &v17);
		LOBYTE(v28) = 1;
		for (i = 0; i < v23[2]; ++i)
		{
			v5 = sub_574980(v24);
			lpMultiByteStr = (LPCSTR)(*v21 + v5);
			++v21;
			if (sub_571810((int)&v20, lpMultiByteStr))
			{
				v6 = sub_5741E0(v13 + 14, deIndex);
				sub_573EC0((_DWORD *)(v6 + 16), &v20);
				v16 = sub_574080(&v20);
				v7 = (unsigned __int16 *)sub_574050(&v20);
				v26 = sub_5784E0(v26, v7, (unsigned __int16 **)&v16);
			}
			else
			{
				sub_573F80(&v15, (wchar_t *)&byte_5D4594[2516460], &v14);
				LOBYTE(v28) = 2;
				v8 = sub_5741E0(v13 + 14, deIndex);
				sub_573EC0((_DWORD *)(v8 + 16), &v15);
				LOBYTE(v28) = 1;
				sub_570CE0(&v15);
			}
		}
		v9 = sub_5741E0(v13 + 14, deIndex);
		*(_DWORD *)(v9 + 32) = v26;
		v27 = 1;
		LOBYTE(v28) = 0;
		sub_570CE0(&v20);
		v28 = -1;
		sub_574930(v24);
	}
	return v27;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0057366C) --------------------------------------------------------
int __thiscall sub_57366C(int *this, HWND hWnd)
{
	int result; // eax
	int *v3; // [esp+4h] [ebp-30h]
	int *v4; // [esp+14h] [ebp-20h]
	unsigned int i; // [esp+18h] [ebp-1Ch]
	int v6; // [esp+1Ch] [ebp-18h]
	struc_35 v7; // [esp+20h] [ebp-14h]

	v7.field_0 = (HWND)-858993460;
	v7.field_4 = (HIMC)-858993460;
	v3 = this;
	if (this[19])
		return -2147467259;
	if (!this[23])
		this[23] = (int)ImmCreateContext();
	if (!v3[23])
		return -2147467259;
	for (i = 0; i < 0x100; ++i)
		*((_BYTE *)v3 + i + 96) = 0;
	v3[22] = 12;
	v3[19] = 0;
	v4 = (int *)sub_571905();
	v6 = sub_571A54(v4, (char)hWnd, (int)v3, -1);
	if (v6 < 0)
		return v6;
	v3[20] = SetWindowLongA(hWnd, GWL_WNDPROC, (LONG)sub_573A68);
	if (v3[20] || !GetLastError())
	{
		v3[19] = (int)hWnd;
		sub_574E10(&v7, (HWND)v3[19]);
		v7.field_10 = 0;
		if (sub_574F00(&v7))
			sub_571F46(&v7, NI_COMPOSITIONSTR, CPS_CANCEL, 0);
		v7.field_10 = -1;
		sub_574EC0(&v7);
		result = 0;
	}
	else
	{
		sub_571AEA(v4, (char)hWnd);
		result = -2147467259;
	}
	return result;
}

//----- (0057381A) --------------------------------------------------------
int *__thiscall sub_57381A(int *this)
{
	int *result; // eax
	int *v2; // eax
	int v3; // [esp-4h] [ebp-20h]
	int *v4; // [esp+4h] [ebp-18h]
	struc_35 v5; // [esp+8h] [ebp-14h]

	v5.field_0 = (HWND)-858993460;
	v5.field_4 = (HIMC)-858993460;
	v4 = this;
	result = this;
	if (this[19])
	{
		sub_574E10(&v5, (HWND)this[19]);
		v5.field_10 = 0;
		if (sub_574F00(&v5))
			sub_571FA4(&v5, 0);
		SetWindowLongA((HWND)v4[19], -4, v4[20]);
		v3 = v4[19];
		v2 = (int *)sub_571905();
		sub_571AEA(v2, v3);
		v4[19] = 0;
		v4[20] = 0;
		sub_574020(v4 + 2, (wchar_t *)&byte_5D4594[2516464]);
		v5.field_10 = -1;
		result = (int *)sub_574EC0(&v5);
	}
	return result;
}

//----- (0057390B) --------------------------------------------------------
void __thiscall sub_57390B(int *this, DWORD dwValue, int a3, int a4)
{
	unsigned __int8 *v4; // eax
	int *v6; // [esp+0h] [ebp-18h]
	struc_35 v7; // [esp+4h] [ebp-14h]

	v7.field_0 = (HWND)-858993460;
	v7.field_4 = (HIMC)-858993460;
	v6 = this;
	sub_574E10(&v7, (HWND)this[19]);
	v7.field_10 = 0;
	if (sub_574F00(&v7))
	{
		sub_571EAD(&v7, v6[21], dwValue, a3);
		v4 = sub_573B7D(v6);
		if (wcscmp((const wchar_t *)v4, (const wchar_t *)&byte_581450[11396]))
			sub_571EF2(v6[21], a4);
	}
	v7.field_10 = -1;
	sub_574EC0(&v7);
}

//----- (005739D2) --------------------------------------------------------
void __thiscall sub_5739D2(int *this, DWORD dwValue)
{
	int *v3; // [esp+0h] [ebp-18h]
	struc_35 v4; // [esp+4h] [ebp-14h]

	v4.field_0 = (HWND)-858993460;
	v4.field_4 = (HIMC)-858993460;
	v3 = this;
	sub_574E10(&v4, (HWND)this[19]);
	v4.field_10 = 0;
	if (sub_574F00(&v4))
		sub_571F06(&v4, v3[21], dwValue);
	v4.field_10 = -1;
	sub_574EC0(&v4);
}

//----- (00573A68) --------------------------------------------------------
LRESULT __stdcall sub_573A68(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	int *v4; // eax
	LRESULT result; // eax
	_DWORD *v6; // [esp+8h] [ebp-4h]

	v4 = (int *)sub_571905();
	v6 = (_DWORD *)sub_571960(v4, (char)hWnd);
	if (v6)
		result = sub_572E05(v6, hWnd, Msg, wParam, lParam);
	else
		result = DefWindowProcA(hWnd, Msg, wParam, lParam);
	return result;
}

//----- (00573AE4) --------------------------------------------------------
int __thiscall sub_573AE4(_DWORD *this)
{
	int result; // eax

	if (this[21] == -1)
		result = 0;
	else
		result = sub_5741E0(this + 14, this[21]);
	return result;
}

//----- (00573B1F) --------------------------------------------------------
_DWORD *__thiscall sub_573B1F(_DWORD *this, _DWORD a2)
{
	_DWORD *result; // eax
	_DWORD *v3; // [esp+0h] [ebp-4h]

	v3 = this;
	result = sub_578540(&a2, &byte_581450[11392]);
	v3[22] = *result;
	return result;
}

//----- (00573B56) --------------------------------------------------------
unsigned __int8 *__thiscall sub_573B56(_DWORD *this)
{
	return sub_570920(this + 2);
}

//----- (00573B7D) --------------------------------------------------------
unsigned __int8 *__thiscall sub_573B7D(_DWORD *this)
{
	_DWORD *v2; // [esp+8h] [ebp-108h]
	CHAR szDescription[256]; // [esp+Ch] [ebp-104h]
	HKL v4; // [esp+10Ch] [ebp-4h]

	v2 = this;
	v4 = GetKeyboardLayout(0);
	ImmGetDescriptionA(v4, szDescription, 0x100u);
	sub_571810((int)(v2 + 10), szDescription);
	return sub_570920(v2 + 10);
}

//----- (00573C05) --------------------------------------------------------
int sub_573C05()
{
	sub_571790();
	return sub_573C1B();
}

//----- (00573C1B) --------------------------------------------------------
int sub_573C1B()
{
	return atexit(sub_5717C0);
}

//----- (00573C40) --------------------------------------------------------
void *__thiscall sub_573C40(void *this)
{
	void *v2; // [esp+0h] [ebp-Ch]
	int v3; // [esp+4h] [ebp-8h]
	int v4; // [esp+8h] [ebp-4h]

	v3 = -858993460;
	v4 = -858993460;
	v2 = this;
	sub_574250(this, &v3, &v4);
	return v2;
}

//----- (00573C80) --------------------------------------------------------
void __thiscall sub_573C80(int *this)
{
	sub_573CB0(this);
}

//----- (00573CB0) --------------------------------------------------------
void __thiscall sub_573CB0(int *this)
{
	sub_574410(this);
}

//----- (00573CE0) --------------------------------------------------------
_DWORD *__thiscall sub_573CE0(_DWORD *this, int a2, int a3)
{
	*this = a2;
	this[1] = a3;
	return this;
}

//----- (00573D10) --------------------------------------------------------
HIMC *__thiscall sub_573D10(HIMC *this, char a2)
{
	HIMC *lpMem; // [esp+0h] [ebp-4h]

	lpMem = this;
	sub_57211C(this);
	if (a2 & 1)
		operator_delete(lpMem);
	return lpMem;
}

//----- (00573D50) --------------------------------------------------------
int *__thiscall sub_573D50(int *this, _BYTE *a2)
{
	int *v3; // [esp+0h] [ebp-4h]

	v3 = this;
	*(_BYTE *)this = *a2;
	sub_574CE0(this, 0);
	return v3;
}

//----- (00573D90) --------------------------------------------------------
int *__thiscall sub_573D90(int *this, _DWORD *a2, char a3, _BYTE *a4)
{
	int *v5; // [esp+0h] [ebp-4h]

	v5 = this;
	*(_BYTE *)this = *a4;
	sub_574CE0(this, 0);
	string__assign(v5, (int)a2, a3);
	return v5;
}

//----- (00573DE0) --------------------------------------------------------
int *__thiscall sub_573DE0(int *this)
{
	return sub_574CE0(this, 1);
}

//----- (00573E10) --------------------------------------------------------
int *__thiscall sub_573E10(int *this, int *a2)
{
	return sub_5749A0(this, a2);
}

//----- (00573E40) --------------------------------------------------------
int __thiscall sub_573E40(int *this)
{
	int *v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_574C40(this);
	return v2[1];
}

//----- (00573E70) --------------------------------------------------------
unsigned __int8 *__thiscall sub_573E70(_DWORD *this)
{
	unsigned __int8 *v2; // [esp+0h] [ebp-8h]

	if (this[1])
		v2 = (unsigned __int8 *)this[1];
	else
		v2 = sub_574CD0();
	return v2;
}

//----- (00573EC0) --------------------------------------------------------
int __thiscall sub_573EC0(_DWORD *this, int *a2)
{
	int *v2; // eax
	_DWORD *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v2 = (int *)wstring__size(this);
	return sub_574DB0(v4, v2, a2);
}

//----- (00573F00) --------------------------------------------------------
int *__thiscall sub_573F00(_DWORD *this)
{
	int *v1; // eax
	int *v3; // [esp-4h] [ebp-8h]
	_DWORD *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v3 = (int *)wstring__size(this);
	v1 = (int *)sub_575120(v4);
	return sub_574E50(v4, v1, v3);
}

//----- (00573F40) --------------------------------------------------------
int *__thiscall sub_573F40(int *this, _BYTE *a2)
{
	int *v3; // [esp+0h] [ebp-4h]

	v3 = this;
	*(_BYTE *)this = *a2;
	sub_570F70((wstring *)this, 0);
	return v3;
}

//----- (00573F80) --------------------------------------------------------
int *__thiscall sub_573F80(int *this, wchar_t *a2, _BYTE *a3)
{
	int *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	*(_BYTE *)this = *a3;
	sub_570F70((wstring *)this, 0);
	sub_571610(v4, a2);
	return v4;
}

//----- (00573FD0) --------------------------------------------------------
wstring *__thiscall wstring__wstring(wstring *this, int _N, wchar_t _C, _BYTE *a4)
{
	wstring *v5; // [esp+0h] [ebp-4h]

	v5 = this;
	LOBYTE(this->_A) = *a4;
	sub_570F70(this, 0);
	wstring__assign(v5, _N, _C);
	return v5;
}

//----- (00574020) --------------------------------------------------------
int *__thiscall sub_574020(int *this, wchar_t *a2)
{
	return sub_571610(this, a2);
}

//----- (00574050) --------------------------------------------------------
int __thiscall sub_574050(int *this)
{
	int *v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_575060(this);
	return v2[1];
}

//----- (00574080) --------------------------------------------------------
int __thiscall sub_574080(int *this)
{
	int *v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_575060(this);
	return sub_5750F0(v2[1], v2[2]);
}

//----- (005740C0) --------------------------------------------------------
int ***__thiscall sub_5740C0(int ***this)
{
	int ***result; // eax
	int ***v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_575460(this[1], this[2]);
	sub_576330(v2[1], ((char *)v2[3] - (char *)v2[1]) / 36);
	v2[1] = 0;
	v2[2] = 0;
	result = v2;
	v2[3] = 0;
	return result;
}

//----- (00574140) --------------------------------------------------------
int __thiscall wstring__size(_DWORD *this)
{
	return this[2];
}

//----- (00574160) --------------------------------------------------------
_DWORD *__thiscall sub_574160(_DWORD *this, unsigned int a2, _DWORD *a3)
{
	_DWORD *v3; // eax
	_DWORD *result; // eax
	int v5; // eax
	unsigned int v6; // [esp-8h] [ebp-Ch]
	_DWORD *v7; // [esp-4h] [ebp-8h]
	_DWORD *v8; // [esp+0h] [ebp-4h]

	v8 = this;
	if (sub_575140(this) >= a2)
	{
		result = (_DWORD *)sub_575140(v8);
		if (a2 < (unsigned int)result)
		{
			v7 = (_DWORD *)wstring__size(v8);
			v5 = sub_575120(v8);
			result = sub_5753F0(v8, (_DWORD *)(36 * a2 + v5), v7);
		}
	}
	else
	{
		v6 = a2 - sub_575140(v8);
		v3 = (_DWORD *)wstring__size(v8);
		result = (_DWORD *)sub_575190((unsigned int)v8, v3, v6, a3);
	}
	return result;
}

//----- (005741E0) --------------------------------------------------------
int __thiscall sub_5741E0(_DWORD *this, int a2)
{
	return 36 * a2 + sub_575120(this);
}

//----- (00574210) --------------------------------------------------------
_DWORD *__thiscall sub_574210(_DWORD *this)
{
	_DWORD *v1; // eax
	_DWORD *v3; // [esp-4h] [ebp-8h]
	_DWORD *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v3 = (_DWORD *)wstring__size(this);
	v1 = (_DWORD *)sub_575120(v4);
	return sub_5753F0(v4, v1, v3);
}

//----- (00574250) --------------------------------------------------------
void *__thiscall sub_574250(void *this, _BYTE *a2, _BYTE *a3)
{
	void *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	sub_575510((int)this, a2, 0, a3);
	return v4;
}

//----- (00574290) --------------------------------------------------------
_DWORD *__thiscall sub_574290(int *this, _DWORD *a2)
{
	int v3; // [esp+4h] [ebp-4h]

	v3 = -858993460;
	*a2 = *sub_5755B0(this, &v3);
	return a2;
}

//----- (005742D0) --------------------------------------------------------
int __thiscall sub_5742D0(int *this, _DWORD *a2)
{
	_DWORD *v2; // eax
	_DWORD *v3; // eax
	int *v5; // [esp+0h] [ebp-24h]
	int v6[2]; // [esp+4h] [ebp-20h]
	int v7[2]; // [esp+Ch] [ebp-18h]
	int v8[3]; // [esp+14h] [ebp-10h]
	int v9; // [esp+20h] [ebp-4h]

	v6[0] = -858993460;
	v6[1] = -858993460;
	v7[0] = -858993460;
	v7[1] = -858993460;
	v8[0] = -858993460;
	v8[1] = -858993460;
	v8[2] = -858993460;
	v9 = -858993460;
	v5 = this;
	v2 = sub_574340(v7);
	v3 = sub_5760B0(v8, a2, v2);
	v9 = *sub_5754A0(v5, v6, v3);
	return sub_5760F0(&v9) + 4;
}

//----- (00574340) --------------------------------------------------------
_DWORD *__thiscall sub_574340(_DWORD *this)
{
	*this = 0;
	this[1] = 0;
	return this;
}

//----- (00574370) --------------------------------------------------------
_DWORD *__thiscall sub_574370(int *this, _DWORD *a2, int a3)
{
	int v4; // [esp+4h] [ebp-4h]

	v4 = -858993460;
	*a2 = *sub_5755F0(this, &v4, a3);
	return a2;
}

//----- (005743C0) --------------------------------------------------------
int *__thiscall sub_5743C0(int *this, int *a2, _DWORD *a3)
{
	int v4; // [esp+4h] [ebp-4h]

	v4 = -858993460;
	*a2 = *sub_575FC0(this, &v4, a3);
	return a2;
}

//----- (00574410) --------------------------------------------------------
void __thiscall sub_574410(int *this)
{
	int *v1; // eax
	int v2; // [esp-4h] [ebp-24h]
	int *v3; // [esp+0h] [ebp-20h]
	int v4; // [esp+4h] [ebp-1Ch]
	int v5; // [esp+8h] [ebp-18h]
	int v6; // [esp+Ch] [ebp-14h]
	int v7; // [esp+10h] [ebp-10h]
	int v8; // [esp+1Ch] [ebp-4h]

	v4 = -858993460;
	v5 = -858993460;
	v6 = -858993460;
	v7 = -858993460;
	v3 = this;
	v2 = *sub_5755B0(this, &v6);
	v1 = sub_575560(v3, &v5);
	sub_575E60(v3, &v4, *v1, v2);
	sub_576080((LPVOID)v3[1]);
	v3[1] = 0;
	v3[3] = 0;
	std___Lockit___Lockit((std___Lockit *)&v7);
	v8 = 0;
	if (!--*(_DWORD *)&byte_5D4594[2516472])
	{
		sub_576080(*(LPVOID *)&byte_5D4594[2516468]);
		*(_DWORD *)&byte_5D4594[2516468] = 0;
	}
	v8 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v7);
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00574500) --------------------------------------------------------
int __thiscall sub_574500(int *this)
{
	return sub_5760F0(this);
}

//----- (00574530) --------------------------------------------------------
BOOL __thiscall sub_574530(_DWORD *this, _DWORD *a2)
{
	return *this == *a2;
}

//----- (00574560) --------------------------------------------------------
BOOL __thiscall sub_574560(_DWORD *this, _DWORD *a2)
{
	return !sub_574530(this, a2);
}

//----- (005745A0) --------------------------------------------------------
_DWORD *__thiscall sub_5745A0(_DWORD *this, _BYTE *a2)
{
	*(_BYTE *)this = *a2;
	this[1] = 0;
	this[2] = 0;
	this[3] = 0;
	return this;
}

//----- (005745E0) --------------------------------------------------------
_DWORD *__thiscall sub_5745E0(_DWORD *this, int a2, _DWORD *a3, _BYTE *a4)
{
	_DWORD *v5; // [esp+0h] [ebp-4h]

	v5 = this;
	*(_BYTE *)this = *a4;
	this[1] = sub_576300(a2, 0);
	sub_5762B0((char *)v5[1], a2, a3);
	v5[2] = v5[1] + 4 * a2;
	v5[3] = v5[2];
	return v5;
}

//----- (00574660) --------------------------------------------------------
int *__thiscall sub_574660(int *this)
{
	int *result; // eax
	int *v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_576220(this[1], this[2]);
	sub_576330((LPVOID)v2[1], (v2[3] - v2[1]) >> 2);
	result = v2;
	v2[1] = 0;
	v2[2] = 0;
	v2[3] = 0;
	return result;
}

//----- (005746D0) --------------------------------------------------------
_DWORD *__thiscall sub_5746D0(_DWORD *this, unsigned int a2)
{
	_DWORD *result; // eax
	int v3; // edx
	_DWORD *v4; // [esp+0h] [ebp-8h]
	char *v5; // [esp+4h] [ebp-4h]

	v4 = this;
	result = (_DWORD *)sub_576120(this);
	if ((unsigned int)result < a2)
	{
		v5 = (char *)sub_576300(a2, 0);
		sub_576260((_DWORD *)v4[1], (_DWORD *)v4[2], v5);
		sub_576220(v4[1], v4[2]);
		sub_576330((LPVOID)v4[1], (v4[3] - v4[1]) >> 2);
		v4[3] = &v5[4 * a2];
		v3 = (int)&v5[4 * sub_576170(v4)];
		result = v4;
		v4[2] = v3;
		v4[1] = v5;
	}
	return result;
}

//----- (005747A0) --------------------------------------------------------
_DWORD *__thiscall sub_5747A0(_DWORD *this, _DWORD *a2)
{
	int v2; // eax
	int v4; // [esp+4h] [ebp-4h]

	v4 = -858993460;
	v2 = wstring__size(this);
	*a2 = *sub_5780E0(&v4, v2);
	return a2;
}

//----- (005747F0) --------------------------------------------------------
_DWORD *__thiscall sub_5747F0(_DWORD *this, _DWORD *a2)
{
	int v2; // eax
	int v4; // [esp+4h] [ebp-4h]

	v4 = -858993460;
	v2 = sub_575120(this);
	*a2 = *sub_5780E0(&v4, v2);
	return a2;
}

//----- (00574840) --------------------------------------------------------
int __thiscall sub_574840(_DWORD *this, _DWORD *a2)
{
	_DWORD *v2; // eax
	_DWORD *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v2 = (_DWORD *)wstring__size(this);
	return sub_5761C0(v4, v2, a2);
}

//----- (00574880) --------------------------------------------------------
void *__thiscall sub_574880(void *this)
{
	return this;
}

//----- (005748A0) --------------------------------------------------------
int __thiscall sub_5748A0(_DWORD *this)
{
	return *this - 4;
}

//----- (005748C0) --------------------------------------------------------
_DWORD *__thiscall sub_5748C0(int *this, _DWORD *a2, int a3)
{
	int v4; // [esp+4h] [ebp-4h]

	v4 = *this;
	*this -= 4;
	*a2 = v4;
	return a2;
}

//----- (00574900) --------------------------------------------------------
_DWORD *__thiscall sub_574900(_DWORD *this, int a2)
{
	*(_BYTE *)this = a2 != 0;
	this[1] = a2;
	return this;
}

//----- (00574930) --------------------------------------------------------
LPVOID *__thiscall sub_574930(LPVOID *this)
{
	LPVOID *result; // eax

	result = this;
	if (*(_BYTE *)this)
		operator_delete(this[1]);
	return result;
}

//----- (00574980) --------------------------------------------------------
int __thiscall sub_574980(_DWORD *this)
{
	return this[1];
}

//----- (005749A0) --------------------------------------------------------
int *__thiscall sub_5749A0(int *this, int *a2)
{
	return sub_5749E0(this, a2, 0, 0xFFFFFFFF);
}

//----- (005749E0) --------------------------------------------------------
int *__thiscall sub_5749E0(int *this, int *a2, unsigned int a3, unsigned int a4)
{
	unsigned __int8 *v4; // eax
	unsigned __int8 *v5; // eax
	_BYTE *v7; // [esp+0h] [ebp-Ch]
	int *v8; // [esp+4h] [ebp-8h]
	unsigned int v9; // [esp+8h] [ebp-4h]

	v8 = this;
	if (sub_574B80(a2) < a3)
		std___Xran();
	v9 = sub_574B80(a2) - a3;
	if (a4 < v9)
		v9 = a4;
	if (v8 == a2)
	{
		sub_576360(v8, v9 + a3, 0xFFFFFFFF);
		sub_576360(v8, 0, a3);
	}
	else if (v9
		&& v9 == sub_574B80(a2)
		&& (v4 = sub_573E70(a2), (int)*(unsigned __int8 *)sub_576600((int)v4) < 254)
		&& sub_571750())
	{
		sub_574CE0(v8, 1);
		v8[1] = (int)sub_573E70(a2);
		v8[2] = sub_574B80(a2);
		v8[3] = sub_5711E0(a2);
		v7 = (_BYTE *)sub_576600(v8[1]);
		++*v7;
	}
	else if (string___Grow(v8, v9, 1))
	{
		v5 = sub_573E70(a2);
		sub_574B60(v8[1], &v5[a3], v9);
		string___Eos(v8, v9);
	}
	return v8;
}
// 57F54C: using guessed type void __cdecl std___Xran();

//----- (00574B60) --------------------------------------------------------
unsigned int __cdecl sub_574B60(void *a1, void *a2, unsigned int a3)
{
	return memcpy(a1, a2, a3);
}

//----- (00574B80) --------------------------------------------------------
int __thiscall sub_574B80(_DWORD *this)
{
	return this[2];
}

//----- (00574BA0) --------------------------------------------------------
int __thiscall string__assign(_DWORD *this, int N, char C)
{
	int *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	if (N == -1)
		std___Xlen();
	if (string___Grow(v4, N, 1))
	{
		char_t__assign_0((void *)v4[1], N, &C);
		string___Eos(v4, N);
	}
	return (int)v4;
}

//----- (00574C10) --------------------------------------------------------
void *__cdecl char_t__assign_0(void *a1, size_t a2, char *a3)
{
	return memset(a1, *a3, a2);
}

//----- (00574C40) --------------------------------------------------------
char __thiscall sub_574C40(int *this)
{
	_BYTE *v1; // eax
	int *v3; // [esp+0h] [ebp-4h]

	v3 = this;
	LOBYTE(v1) = (_BYTE)this;
	if (this[1])
	{
		v1 = (_BYTE *)sub_576600(this[1]);
		if (*v1)
		{
			v1 = (_BYTE *)sub_576600(v3[1]);
			if ((unsigned __int8)*v1 != 255)
				LOBYTE(v1) = string___Grow(v3, v3[2], 0);
		}
	}
	if (v3[1])
	{
		v1 = (_BYTE *)sub_576600(v3[1]);
		*v1 = -1;
	}
	return (char)v1;
}

//----- (00574CD0) --------------------------------------------------------
unsigned __int8 *sub_574CD0()
{
	return &byte_581450[11428];
}

//----- (00574CE0) --------------------------------------------------------
int *__thiscall sub_574CE0(int *this, char a2)
{
	_BYTE *v2; // ecx
	int *result; // eax
	int *v4; // [esp+4h] [ebp-4h]

	v4 = this;
	if (a2 && this[1])
	{
		if (*(_BYTE *)sub_576600(this[1]) && *(unsigned __int8 *)sub_576600(v4[1]) != 255)
		{
			v2 = (_BYTE *)sub_576600(v4[1]);
			--*v2;
		}
		else
		{
			sub_576330((LPVOID)(v4[1] - 1), v4[3] + 2);
		}
	}
	v4[1] = 0;
	result = v4;
	v4[2] = 0;
	v4[3] = 0;
	return result;
}

//----- (00574DB0) --------------------------------------------------------
int __thiscall sub_574DB0(_DWORD *this, int *a2, int *a3)
{
	_DWORD *v4; // [esp+0h] [ebp-8h]
	int v5; // [esp+4h] [ebp-4h]

	v4 = this;
	v5 = ((int)a2 - sub_575120(this)) >> 4;
	sub_576620((int)v4, a2, 1u, a3);
	return 16 * v5 + sub_575120(v4);
}

//----- (00574E10) --------------------------------------------------------
int __thiscall sub_574E10(int this, int a2)
{
	int v3; // [esp+0h] [ebp-4h]

	v3 = this;
	*(_DWORD *)this = a2;
	*(_DWORD *)(this + 4) = ImmGetContext(*(HWND *)this);
	return v3;
}

//----- (00574E50) --------------------------------------------------------
int *__thiscall sub_574E50(_DWORD *this, int *a2, int *a3)
{
	int *v3; // eax
	int *v4; // eax
	_DWORD *v6; // [esp+0h] [ebp-8h]
	int *v7; // [esp+4h] [ebp-4h]

	v6 = this;
	v3 = (int *)wstring__size(this);
	v7 = sub_570B20(a3, v3, a2);
	v4 = (int *)wstring__size(v6);
	sub_5709C0(v7, v4);
	v6[2] = v7;
	return a2;
}

//----- (00574EC0) --------------------------------------------------------
BOOL __thiscall sub_574EC0(int this)
{
	BOOL result; // eax

	result = this;
	if (*(_DWORD *)(this + 4))
		result = ImmReleaseContext(*(HWND *)this, *(HIMC *)(this + 4));
	return result;
}

//----- (00574F00) --------------------------------------------------------
bool __thiscall sub_574F00(char *this)
{
	return *(_DWORD *)sub_574F60(this) != 0;
}

//----- (00574F30) --------------------------------------------------------
BOOL __thiscall sub_574F30(char *this)
{
	return *(_DWORD *)sub_574F60(this) == 0;
}

//----- (00574F60) --------------------------------------------------------
char *__thiscall sub_574F60(char *this)
{
	return this + 4;
}

//----- (00574F80) --------------------------------------------------------
int __thiscall wstring__assign(_DWORD *this, int _N, wchar_t _C)
{
	int *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	if (_N == -1)
		std___Xlen();
	if (wstring___Grow(v4, _N, 1))
	{
		wchar_t__assign((_WORD *)v4[1], _N, (__int16 *)&_C);
		wstring___Eos(v4, _N);
	}
	return (int)v4;
}

//----- (00574FF0) --------------------------------------------------------
_WORD *__cdecl wchar_t__assign(_WORD *a1, int a2, __int16 *a3)
{
	return sub_575020(a1, *a3, a2);
}

//----- (00575020) --------------------------------------------------------
_WORD *__cdecl sub_575020(_WORD *a1, __int16 a2, int a3)
{
	_WORD *v4; // [esp+0h] [ebp-4h]

	v4 = a1;
	while (a3)
	{
		*v4 = a2;
		++v4;
		--a3;
	}
	return a1;
}

//----- (00575060) --------------------------------------------------------
char __thiscall sub_575060(int *this)
{
	_BYTE *v1; // eax
	int *v3; // [esp+0h] [ebp-4h]

	v3 = this;
	LOBYTE(v1) = (_BYTE)this;
	if (this[1])
	{
		v1 = (_BYTE *)sub_576600(this[1]);
		if (*v1)
		{
			v1 = (_BYTE *)sub_576600(v3[1]);
			if ((unsigned __int8)*v1 != 255)
				LOBYTE(v1) = wstring___Grow(v3, v3[2], 0);
		}
	}
	if (v3[1])
	{
		v1 = (_BYTE *)sub_576600(v3[1]);
		*v1 = -1;
	}
	return (char)v1;
}

//----- (005750F0) --------------------------------------------------------
int __cdecl sub_5750F0(int a1, int a2)
{
	int v3; // [esp+0h] [ebp-4h]

	if (a1)
		v3 = a1 + 2 * a2;
	else
		v3 = 0;
	return v3;
}

//----- (00575120) --------------------------------------------------------
int __thiscall sub_575120(_DWORD *this)
{
	return this[1];
}

//----- (00575140) --------------------------------------------------------
int __thiscall sub_575140(_DWORD *this)
{
	int v2; // [esp+0h] [ebp-8h]

	if (this[1])
		v2 = (this[2] - this[1]) / 36;
	else
		v2 = 0;
	return v2;
}

//----- (00575190) --------------------------------------------------------
unsigned int __thiscall sub_575190(unsigned int this, _DWORD *a2, unsigned int a3, _DWORD *a4)
{
	int v4; // ecx
	unsigned int result; // eax
	unsigned int v6; // [esp+0h] [ebp-14h]
	unsigned int v7; // [esp+4h] [ebp-10h]
	int v8; // [esp+8h] [ebp-Ch]
	char *v9; // [esp+Ch] [ebp-8h]
	char *v10; // [esp+10h] [ebp-4h]

	v7 = this;
	if ((*(_DWORD *)(this + 12) - *(_DWORD *)(this + 8)) / 36 >= a3)
	{
		result = (*(_DWORD *)(this + 8) - (int)a2) / 36;
		if (result >= a3)
		{
			if (a3)
			{
				sub_576870((_DWORD *)(*(_DWORD *)(this + 8) - 36 * a3), *(_DWORD **)(this + 8), *(char **)(this + 8));
				sub_5785B0(a2, (_DWORD *)(*(_DWORD *)(v7 + 8) - 36 * a3), *(_DWORD **)(v7 + 8));
				sub_578580(a2, &a2[9 * a3], a4);
				result = v7;
				*(_DWORD *)(v7 + 8) += 36 * a3;
			}
		}
		else
		{
			sub_576870(a2, *(_DWORD **)(this + 8), (char *)&a2[9 * a3]);
			sub_5768C0(*(char **)(v7 + 8), a3 - (*(_DWORD *)(v7 + 8) - (int)a2) / 36, a4);
			sub_578580(a2, *(_DWORD **)(v7 + 8), a4);
			result = v7;
			*(_DWORD *)(v7 + 8) += 36 * a3;
		}
	}
	else
	{
		if (a3 >= sub_575140((_DWORD *)this))
			v6 = a3;
		else
			v6 = sub_575140((_DWORD *)v7);
		v8 = v6 + sub_575140((_DWORD *)v7);
		v9 = (char *)sub_576910(v8, 0);
		v10 = sub_576870(*(_DWORD **)(v7 + 4), a2, v9);
		sub_5768C0(v10, a3, a4);
		sub_576870(a2, *(_DWORD **)(v7 + 8), &v10[36 * a3]);
		sub_575460(*(int ***)(v7 + 4), *(int ***)(v7 + 8));
		sub_576330(*(LPVOID *)(v7 + 4), (*(_DWORD *)(v7 + 12) - *(_DWORD *)(v7 + 4)) / 36);
		*(_DWORD *)(v7 + 12) = &v9[36 * v8];
		v4 = (int)&v9[36 * sub_575140((_DWORD *)v7)];
		result = v7;
		*(_DWORD *)(v7 + 8) = 36 * a3 + v4;
		*(_DWORD *)(v7 + 4) = v9;
	}
	return result;
}

//----- (005753F0) --------------------------------------------------------
_DWORD *__thiscall sub_5753F0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
	_DWORD *v3; // eax
	int **v4; // eax
	_DWORD *v6; // [esp+0h] [ebp-8h]
	int **v7; // [esp+4h] [ebp-4h]

	v6 = this;
	v3 = (_DWORD *)wstring__size(this);
	v7 = (int **)sub_5785F0(a3, v3, a2);
	v4 = (int **)wstring__size(v6);
	sub_575460(v7, v4);
	v6[2] = v7;
	return a2;
}

//----- (00575460) --------------------------------------------------------
int **__stdcall sub_575460(int **a1, int **a2)
{
	int **result; // eax

	while (a1 != a2)
	{
		sub_576940(a1);
		result = a1 + 9;
		a1 += 9;
	}
	return result;
}

//----- (005754A0) --------------------------------------------------------
_DWORD *__thiscall sub_5754A0(int *this, _DWORD *a2, _DWORD *a3)
{
	int *v3; // eax
	int v4; // edx
	int v5; // eax
	_DWORD *v6; // eax
	int v7; // edx
	int v9[5]; // [esp+4h] [ebp-18h]
	int v10; // [esp+18h] [ebp-4h]

	v9[0] = -858993460;
	v9[1] = -858993460;
	v9[2] = -858993460;
	v9[3] = -858993460;
	v9[4] = -858993460;
	v10 = -858993460;
	v3 = sub_576A20(this, &v9[2], a3);
	v4 = *v3;
	v5 = v3[1];
	v9[4] = v4;
	v10 = v5;
	v6 = sub_5776D0(v9, &v9[4], &v10);
	v7 = v6[1];
	*a2 = *v6;
	a2[1] = v7;
	return a2;
}

//----- (00575510) --------------------------------------------------------
int __thiscall sub_575510(int this, _BYTE *a2, char a3, _BYTE *a4)
{
	int v5; // [esp+0h] [ebp-4h]

	v5 = this;
	*(_BYTE *)this = *a4;
	*(_BYTE *)(this + 1) = *a2;
	*(_BYTE *)(this + 8) = a3;
	sub_576DA0((int *)this);
	return v5;
}

//----- (00575560) --------------------------------------------------------
_DWORD *__thiscall sub_575560(_DWORD *this, _DWORD *a2)
{
	int *v2; // eax
	int v4; // [esp+4h] [ebp-4h]

	v4 = -858993460;
	v2 = (int *)sub_576EA0(this);
	*a2 = *sub_5773E0(&v4, *v2);
	return a2;
}

//----- (005755B0) --------------------------------------------------------
_DWORD *__thiscall sub_5755B0(int *this, _DWORD *a2)
{
	int v3; // [esp+4h] [ebp-4h]

	v3 = -858993460;
	*a2 = *sub_5773E0(&v3, this[1]);
	return a2;
}

//----- (005755F0) --------------------------------------------------------
_DWORD *__thiscall sub_5755F0(int *this, _DWORD *a2, int a3)
{
	int *v3; // eax
	int *v4; // eax
	int *v5; // eax
	_DWORD *v6; // eax
	_DWORD *v7; // esi
	_DWORD *v8; // eax
	_DWORD *v9; // eax
	_DWORD *v10; // esi
	int *v11; // eax
	_DWORD *v12; // eax
	_DWORD *v13; // esi
	int *v14; // eax
	_DWORD *v15; // eax
	_DWORD *v16; // eax
	int *v17; // eax
	_DWORD *v18; // eax
	int *v19; // eax
	_DWORD *v20; // eax
	int *v21; // eax
	_DWORD *v22; // esi
	int *v23; // eax
	_DWORD *v24; // esi
	_DWORD *v25; // eax
	_DWORD *v26; // eax
	int *v27; // eax
	_DWORD *v28; // eax
	int *v29; // eax
	_DWORD *v30; // eax
	int *v31; // eax
	_DWORD *v32; // eax
	_DWORD *v33; // esi
	int v34; // esi
	_DWORD *v35; // eax
	_DWORD *v36; // esi
	int v37; // esi
	_DWORD *v38; // eax
	int *v39; // eax
	_DWORD *v40; // eax
	int *v41; // eax
	int *v42; // eax
	int *v43; // eax
	int *v44; // eax
	int *v45; // eax
	int *v46; // eax
	int *v47; // eax
	int *v48; // eax
	int *v49; // eax
	int *v50; // eax
	_DWORD *v51; // esi
	int *v52; // eax
	int *v53; // eax
	int *v54; // eax
	int *v55; // eax
	int *v56; // eax
	int *v57; // eax
	int *v58; // eax
	int *v59; // eax
	int *v60; // eax
	int *v61; // eax
	int *v62; // eax
	int *v63; // eax
	int *v64; // eax
	_DWORD *v65; // esi
	int *v66; // eax
	int *v67; // eax
	int *v68; // eax
	int v69; // eax
	int *v71; // [esp-4h] [ebp-34h]
	int *v72; // [esp+4h] [ebp-2Ch]
	int v73; // [esp+8h] [ebp-28h]
	int v74; // [esp+Ch] [ebp-24h]
	int v75; // [esp+10h] [ebp-20h]
	int v76; // [esp+14h] [ebp-1Ch]
	int v77; // [esp+18h] [ebp-18h]
	int v78; // [esp+1Ch] [ebp-14h]
	int v79; // [esp+20h] [ebp-10h]
	int v80; // [esp+2Ch] [ebp-4h]

	v73 = -858993460;
	v74 = -858993460;
	v75 = -858993460;
	v76 = -858993460;
	v77 = -858993460;
	v78 = -858993460;
	v79 = -858993460;
	v72 = this;
	v3 = sub_577410(&a3, &v73, 0);
	v78 = sub_5773C0(v3);
	v76 = v78;
	std___Lockit___Lockit((std___Lockit *)&v77);
	v80 = 0;
	if (*(_DWORD *)sub_5769E0(v78) == *(_DWORD *)&byte_5D4594[2516468])
	{
		v79 = *(_DWORD *)sub_576A00(v78);
	}
	else if (*(_DWORD *)sub_576A00(v78) == *(_DWORD *)&byte_5D4594[2516468])
	{
		v79 = *(_DWORD *)sub_5769E0(v78);
	}
	else
	{
		v4 = (int *)sub_576A00(v78);
		v78 = sub_577100(*v4);
		v79 = *(_DWORD *)sub_576A00(v78);
	}
	if (v78 == v76)
	{
		v24 = (_DWORD *)sub_5769F0(v78);
		*(_DWORD *)sub_5769F0(v79) = *v24;
		v25 = (_DWORD *)sub_5771D0(v72);
		if (*v25 == v76)
		{
			v26 = (_DWORD *)sub_5771D0(v72);
			*v26 = v79;
		}
		else
		{
			v27 = (int *)sub_5769F0(v76);
			v28 = (_DWORD *)sub_5769E0(*v27);
			if (*v28 == v76)
			{
				v29 = (int *)sub_5769F0(v76);
				v30 = (_DWORD *)sub_5769E0(*v29);
			}
			else
			{
				v31 = (int *)sub_5769F0(v76);
				v30 = (_DWORD *)sub_576A00(*v31);
			}
			*v30 = v79;
		}
		v32 = (_DWORD *)sub_576EA0(v72);
		if (*v32 == v76)
		{
			if (*(_DWORD *)sub_576A00(v76) == *(_DWORD *)&byte_5D4594[2516468])
			{
				v33 = (_DWORD *)sub_5769F0(v76);
				*(_DWORD *)sub_576EA0(v72) = *v33;
			}
			else
			{
				v34 = sub_577100(v79);
				*(_DWORD *)sub_576EA0(v72) = v34;
			}
		}
		v35 = (_DWORD *)sub_5771A0(v72);
		if (*v35 == v76)
		{
			if (*(_DWORD *)sub_5769E0(v76) == *(_DWORD *)&byte_5D4594[2516468])
			{
				v36 = (_DWORD *)sub_5769F0(v76);
				*(_DWORD *)sub_5771A0(v72) = *v36;
			}
			else
			{
				v37 = sub_577060(v79);
				*(_DWORD *)sub_5771A0(v72) = v37;
			}
		}
	}
	else
	{
		v5 = (int *)sub_5769E0(v76);
		v6 = (_DWORD *)sub_5769F0(*v5);
		*v6 = v78;
		v7 = (_DWORD *)sub_5769E0(v76);
		*(_DWORD *)sub_5769E0(v78) = *v7;
		v8 = (_DWORD *)sub_576A00(v76);
		if (v78 == *v8)
		{
			v9 = (_DWORD *)sub_5769F0(v79);
		}
		else
		{
			v10 = (_DWORD *)sub_5769F0(v78);
			*(_DWORD *)sub_5769F0(v79) = *v10;
			v11 = (int *)sub_5769F0(v78);
			v12 = (_DWORD *)sub_5769E0(*v11);
			*v12 = v79;
			v13 = (_DWORD *)sub_576A00(v76);
			*(_DWORD *)sub_576A00(v78) = *v13;
			v14 = (int *)sub_576A00(v76);
			v9 = (_DWORD *)sub_5769F0(*v14);
		}
		*v9 = v78;
		v15 = (_DWORD *)sub_5771D0(v72);
		if (*v15 == v76)
		{
			v16 = (_DWORD *)sub_5771D0(v72);
			*v16 = v78;
		}
		else
		{
			v17 = (int *)sub_5769F0(v76);
			v18 = (_DWORD *)sub_5769E0(*v17);
			if (*v18 == v76)
			{
				v19 = (int *)sub_5769F0(v76);
				v20 = (_DWORD *)sub_5769E0(*v19);
			}
			else
			{
				v21 = (int *)sub_5769F0(v76);
				v20 = (_DWORD *)sub_576A00(*v21);
			}
			*v20 = v78;
		}
		v22 = (_DWORD *)sub_5769F0(v76);
		*(_DWORD *)sub_5769F0(v78) = *v22;
		v71 = (int *)sub_5769A0(v76);
		v23 = (int *)sub_5769A0(v78);
		sub_578630(v23, v71);
		v78 = v76;
	}
	if (*(_DWORD *)sub_5769A0(v78) == 1)
	{
		while (1)
		{
			v38 = (_DWORD *)sub_5771D0(v72);
			if (v79 == *v38 || *(_DWORD *)sub_5769A0(v79) != 1)
				break;
			v39 = (int *)sub_5769F0(v79);
			v40 = (_DWORD *)sub_5769E0(*v39);
			if (v79 == *v40)
			{
				v41 = (int *)sub_5769F0(v79);
				v75 = *(_DWORD *)sub_576A00(*v41);
				if (!*(_DWORD *)sub_5769A0(v75))
				{
					*(_DWORD *)sub_5769A0(v75) = 1;
					v42 = (int *)sub_5769F0(v79);
					*(_DWORD *)sub_5769A0(*v42) = 0;
					v43 = (int *)sub_5769F0(v79);
					sub_576ED0(v72, *v43);
					v44 = (int *)sub_5769F0(v79);
					v75 = *(_DWORD *)sub_576A00(*v44);
				}
				v45 = (int *)sub_5769E0(v75);
				if (*(_DWORD *)sub_5769A0(*v45) != 1 || (v46 = (int *)sub_576A00(v75), *(_DWORD *)sub_5769A0(*v46) != 1))
				{
					v47 = (int *)sub_576A00(v75);
					if (*(_DWORD *)sub_5769A0(*v47) == 1)
					{
						v48 = (int *)sub_5769E0(v75);
						*(_DWORD *)sub_5769A0(*v48) = 1;
						*(_DWORD *)sub_5769A0(v75) = 0;
						sub_577200(v72, v75);
						v49 = (int *)sub_5769F0(v79);
						v75 = *(_DWORD *)sub_576A00(*v49);
					}
					v50 = (int *)sub_5769F0(v79);
					v51 = (_DWORD *)sub_5769A0(*v50);
					*(_DWORD *)sub_5769A0(v75) = *v51;
					v52 = (int *)sub_5769F0(v79);
					*(_DWORD *)sub_5769A0(*v52) = 1;
					v53 = (int *)sub_576A00(v75);
					*(_DWORD *)sub_5769A0(*v53) = 1;
					v54 = (int *)sub_5769F0(v79);
					sub_576ED0(v72, *v54);
					break;
				}
				*(_DWORD *)sub_5769A0(v75) = 0;
				v79 = *(_DWORD *)sub_5769F0(v79);
			}
			else
			{
				v55 = (int *)sub_5769F0(v79);
				v74 = *(_DWORD *)sub_5769E0(*v55);
				if (!*(_DWORD *)sub_5769A0(v74))
				{
					*(_DWORD *)sub_5769A0(v74) = 1;
					v56 = (int *)sub_5769F0(v79);
					*(_DWORD *)sub_5769A0(*v56) = 0;
					v57 = (int *)sub_5769F0(v79);
					sub_577200(v72, *v57);
					v58 = (int *)sub_5769F0(v79);
					v74 = *(_DWORD *)sub_5769E0(*v58);
				}
				v59 = (int *)sub_576A00(v74);
				if (*(_DWORD *)sub_5769A0(*v59) != 1 || (v60 = (int *)sub_5769E0(v74), *(_DWORD *)sub_5769A0(*v60) != 1))
				{
					v61 = (int *)sub_5769E0(v74);
					if (*(_DWORD *)sub_5769A0(*v61) == 1)
					{
						v62 = (int *)sub_576A00(v74);
						*(_DWORD *)sub_5769A0(*v62) = 1;
						*(_DWORD *)sub_5769A0(v74) = 0;
						sub_576ED0(v72, v74);
						v63 = (int *)sub_5769F0(v79);
						v74 = *(_DWORD *)sub_5769E0(*v63);
					}
					v64 = (int *)sub_5769F0(v79);
					v65 = (_DWORD *)sub_5769A0(*v64);
					*(_DWORD *)sub_5769A0(v74) = *v65;
					v66 = (int *)sub_5769F0(v79);
					*(_DWORD *)sub_5769A0(*v66) = 1;
					v67 = (int *)sub_5769E0(v74);
					*(_DWORD *)sub_5769A0(*v67) = 1;
					v68 = (int *)sub_5769F0(v79);
					sub_577200(v72, *v68);
					break;
				}
				*(_DWORD *)sub_5769A0(v74) = 0;
				v79 = *(_DWORD *)sub_5769F0(v79);
			}
		}
		*(_DWORD *)sub_5769A0(v79) = 1;
	}
	v69 = sub_576A10(v78);
	sub_577390(v69);
	sub_576080((LPVOID)v78);
	--v72[3];
	*a2 = a3;
	v80 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v77);
	return a2;
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00575E60) --------------------------------------------------------
_DWORD *__thiscall sub_575E60(int *this, _DWORD *a2, int a3, char a4)
{
	_DWORD *v4; // eax
	_DWORD *v5; // eax
	int *v6; // eax
	_DWORD *result; // eax
	void **v8; // eax
	int *v9; // [esp+0h] [ebp-28h]
	int v10; // [esp+4h] [ebp-24h]
	int v11; // [esp+8h] [ebp-20h]
	int v12; // [esp+Ch] [ebp-1Ch]
	int v13; // [esp+10h] [ebp-18h]
	int v14; // [esp+14h] [ebp-14h]
	int v15; // [esp+18h] [ebp-10h]
	int v16; // [esp+24h] [ebp-4h]

	v10 = -858993460;
	v11 = -858993460;
	v12 = -858993460;
	v13 = -858993460;
	v14 = -858993460;
	v15 = -858993460;
	v9 = this;
	if (!sub_5711E0(this)
		|| (v4 = sub_575560(v9, &v14), sub_574560(&a3, v4))
		|| (v5 = sub_5755B0(v9, &v13), sub_574560(&a4, v5)))
	{
		while (sub_574560(&a3, &a4))
		{
			v6 = sub_577410(&a3, &v12, 0);
			sub_5755F0(v9, &v11, *v6);
		}
		*a2 = a3;
		result = a2;
	}
	else
	{
		std___Lockit___Lockit((std___Lockit *)&v15);
		v16 = 0;
		v8 = (void **)sub_5771D0(v9);
		sub_576CD0(*v8);
		*(_DWORD *)sub_5771D0(v9) = *(_DWORD *)&byte_5D4594[2516468];
		v9[3] = 0;
		*(_DWORD *)sub_576EA0(v9) = v9[1];
		*(_DWORD *)sub_5771A0(v9) = v9[1];
		*a2 = *sub_575560(v9, &v10);
		v16 = -1;
		std___Lockit__destructor_Lockit((std___Lockit *)&v15);
		result = a2;
	}
	return result;
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00575FC0) --------------------------------------------------------
int *__thiscall sub_575FC0(int *this, int *a2, _DWORD *a3)
{
	_DWORD *v3; // eax
	int v4; // eax
	_DWORD *v5; // eax
	int *v7; // [esp+0h] [ebp-1Ch]
	int *v8; // [esp+4h] [ebp-18h]
	int v9; // [esp+8h] [ebp-14h]
	int v10; // [esp+Ch] [ebp-10h]
	int v11; // [esp+10h] [ebp-Ch]
	int v12; // [esp+14h] [ebp-8h]
	int v13; // [esp+18h] [ebp-4h]

	v9 = -858993460;
	v10 = -858993460;
	v11 = -858993460;
	v12 = -858993460;
	v13 = -858993460;
	v8 = this;
	v13 = *sub_576C80(this, &v12, a3);
	v3 = sub_5755B0(v8, &v10);
	if (sub_574530(&v13, v3) || (v4 = sub_5773C0(&v13), v5 = (_DWORD *)sub_5769B0(v4), sub_576970(a3, v5)))
		v7 = sub_5755B0(v8, &v9);
	else
		v7 = &v13;
	v11 = (int)v7;
	*a2 = *v7;
	return a2;
}

//----- (00576080) --------------------------------------------------------
void __stdcall sub_576080(LPVOID lpMem)
{
	sub_576330(lpMem, 1);
}

//----- (005760B0) --------------------------------------------------------
_DWORD *__thiscall sub_5760B0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
	int v3; // edx

	*this = *a2;
	v3 = a3[1];
	this[1] = *a3;
	this[2] = v3;
	return this;
}

//----- (005760F0) --------------------------------------------------------
int __thiscall sub_5760F0(int *this)
{
	return sub_576A10(*this);
}

//----- (00576120) --------------------------------------------------------
int __thiscall sub_576120(_DWORD *this)
{
	int v2; // [esp+0h] [ebp-8h]

	if (this[1])
		v2 = (this[3] - this[1]) >> 2;
	else
		v2 = 0;
	return v2;
}

//----- (00576170) --------------------------------------------------------
int __thiscall sub_576170(_DWORD *this)
{
	int v2; // [esp+0h] [ebp-8h]

	if (this[1])
		v2 = (this[2] - this[1]) >> 2;
	else
		v2 = 0;
	return v2;
}

//----- (005761C0) --------------------------------------------------------
int __thiscall sub_5761C0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
	_DWORD *v4; // [esp+0h] [ebp-8h]
	int v5; // [esp+4h] [ebp-4h]

	v4 = this;
	v5 = ((int)a2 - sub_575120(this)) >> 2;
	sub_577460((unsigned int)v4, a2, 1u, a3);
	return sub_575120(v4) + 4 * v5;
}

//----- (00576220) --------------------------------------------------------
int __stdcall sub_576220(int a1, int a2)
{
	int result; // eax

	while (a1 != a2)
	{
		sub_577390(a1);
		result = a1 + 4;
		a1 += 4;
	}
	return result;
}

//----- (00576260) --------------------------------------------------------
char *__stdcall sub_576260(_DWORD *a1, _DWORD *a2, char *a3)
{
	while (a1 != a2)
	{
		sub_5776A0(a3, a1);
		a3 += 4;
		++a1;
	}
	return a3;
}

//----- (005762B0) --------------------------------------------------------
int __stdcall sub_5762B0(char *a1, int a2, _DWORD *a3)
{
	int result; // eax

	while (a2)
	{
		sub_5776A0(a1, a3);
		result = --a2;
		a1 += 4;
	}
	return result;
}

//----- (00576300) --------------------------------------------------------
void *__stdcall sub_576300(int a1, int a2)
{
	return sub_578660(a1);
}

//----- (00576330) --------------------------------------------------------
void __stdcall sub_576330(LPVOID lpMem, int a2)
{
	operator_delete(lpMem);
}

//----- (00576360) --------------------------------------------------------
int *__thiscall sub_576360(int *this, unsigned int a2, unsigned int a3)
{
	int *v4; // [esp+0h] [ebp-8h]
	unsigned int v5; // [esp+4h] [ebp-4h]

	v4 = this;
	if (this[2] < a2)
		std___Xran();
	sub_5778C0(v4);
	if (v4[2] - a2 < a3)
		a3 = v4[2] - a2;
	if (a3)
	{
		sub_576420(a2 + v4[1], (_BYTE *)(a3 + a2 + v4[1]), v4[2] - a2 - a3);
		v5 = v4[2] - a3;
		if (string___Grow(v4, v5, 0))
			string___Eos(v4, v5);
	}
	return v4;
}
// 57F54C: using guessed type void __cdecl std___Xran();

//----- (00576420) --------------------------------------------------------
unsigned int __cdecl sub_576420(unsigned int a1, _BYTE *a2, unsigned int a3)
{
	return memmove(a1, a2, a3);
}

//----- (00576440) --------------------------------------------------------
_BYTE *__thiscall string___Eos(_DWORD *this, int a2)
{
	int v3; // [esp+4h] [ebp-4h]

	v3 = -858993664;
	this[2] = a2;
	return char_t__assign((_BYTE *)(a2 + this[1]), &v3);
}

//----- (00576490) --------------------------------------------------------
_BYTE *__cdecl char_t__assign(_BYTE *a1, _BYTE *a2)
{
	_BYTE *result; // eax

	result = a1;
	*a1 = *a2;
	return result;
}

//----- (005764A0) --------------------------------------------------------
char __thiscall string___Grow(int *this, unsigned int a2, char a3)
{
	_BYTE *v3; // eax
	char result; // al
	int *v5; // [esp+4h] [ebp-4h]

	v5 = this;
	if (string__max_size() < a2)
		std___Xlen();
	if (v5[1] && *(_BYTE *)sub_576600(v5[1]) && *(unsigned __int8 *)sub_576600(v5[1]) != 255)
	{
		if (a2)
		{
			sub_577760(v5, a2);
			result = 1;
		}
		else
		{
			v3 = (_BYTE *)sub_576600(v5[1]);
			--*v3;
			sub_574CE0(v5, 0);
			result = 0;
		}
	}
	else if (a2)
	{
		if (a3 && ((unsigned int)v5[3] > 0x1F || v5[3] < a2))
		{
			sub_574CE0(v5, 1);
			sub_577760(v5, a2);
		}
		else if (!a3 && v5[3] < a2)
		{
			sub_577760(v5, a2);
		}
		result = 1;
	}
	else
	{
		if (a3)
		{
			sub_574CE0(v5, 1);
		}
		else if (v5[1])
		{
			string___Eos(v5, 0);
		}
		result = 0;
	}
	return result;
}

//----- (00576600) --------------------------------------------------------
int __stdcall sub_576600(int a1)
{
	return a1 - 1;
}

//----- (00576620) --------------------------------------------------------
char *__thiscall sub_576620(int this, int *a2, unsigned int a3, int *a4)
{
	char *result; // eax
	unsigned int v5; // [esp+0h] [ebp-14h]
	int v6; // [esp+4h] [ebp-10h]
	int v7; // [esp+8h] [ebp-Ch]
	char *v8; // [esp+Ch] [ebp-8h]
	char *v9; // [esp+10h] [ebp-4h]

	v6 = this;
	result = (char *)this;
	if ((*(_DWORD *)(this + 12) - *(_DWORD *)(this + 8)) >> 4 >= a3)
	{
		if ((*(_DWORD *)(this + 8) - (int)a2) >> 4 >= a3)
		{
			if (a3)
			{
				sub_570A00((int *)(*(_DWORD *)(this + 8) - 16 * a3), *(int **)(this + 8), *(char **)(this + 8));
				sub_5786C0(a2, (int *)(*(_DWORD *)(v6 + 8) - 16 * a3), *(int **)(v6 + 8));
				sub_578690(a2, &a2[4 * a3], a4);
				result = (char *)v6;
				*(_DWORD *)(v6 + 8) += 16 * a3;
			}
		}
		else
		{
			sub_570A00(a2, *(int **)(this + 8), (char *)&a2[4 * a3]);
			sub_577A00(*(char **)(v6 + 8), a3 - ((*(_DWORD *)(v6 + 8) - (int)a2) >> 4), a4);
			sub_578690(a2, *(int **)(v6 + 8), a4);
			result = (char *)v6;
			*(_DWORD *)(v6 + 8) += 16 * a3;
		}
	}
	else
	{
		if (a3 >= sub_5708A0((_DWORD *)this))
			v5 = a3;
		else
			v5 = sub_5708A0((_DWORD *)v6);
		v7 = v5 + sub_5708A0((_DWORD *)v6);
		v8 = (char *)sub_570A50(v7, 0);
		v9 = sub_570A00(*(int **)(v6 + 4), a2, v8);
		sub_577A00(v9, a3, a4);
		sub_570A00(a2, *(int **)(v6 + 8), &v9[16 * a3]);
		sub_5709C0(*(int **)(v6 + 4), *(int **)(v6 + 8));
		sub_570A80(*(LPVOID *)(v6 + 4), (*(_DWORD *)(v6 + 12) - *(_DWORD *)(v6 + 4)) >> 4);
		*(_DWORD *)(v6 + 12) = &v8[16 * v7];
		*(_DWORD *)(v6 + 8) = &v8[16 * sub_5708A0((_DWORD *)v6) + 16 * a3];
		result = v8;
		*(_DWORD *)(v6 + 4) = v8;
	}
	return result;
}

//----- (00576870) --------------------------------------------------------
char *__stdcall sub_576870(_DWORD *a1, _DWORD *a2, char *a3)
{
	while (a1 != a2)
	{
		sub_577A50(a3, a1);
		a3 += 36;
		a1 += 9;
	}
	return a3;
}

//----- (005768C0) --------------------------------------------------------
int __stdcall sub_5768C0(char *a1, int a2, _DWORD *a3)
{
	int result; // eax

	while (a2)
	{
		sub_577A50(a1, a3);
		result = --a2;
		a1 += 36;
	}
	return result;
}

//----- (00576910) --------------------------------------------------------
void *__stdcall sub_576910(int a1, int a2)
{
	return sub_578700(a1);
}

//----- (00576940) --------------------------------------------------------
int **__stdcall sub_576940(int **a1)
{
	return sub_578730(a1);
}

//----- (00576970) --------------------------------------------------------
BOOL __stdcall sub_576970(_DWORD *a1, _DWORD *a2)
{
	return *a1 < *a2;
}

//----- (005769A0) --------------------------------------------------------
int __cdecl sub_5769A0(int a1)
{
	return a1 + 24;
}

//----- (005769B0) --------------------------------------------------------
int __cdecl sub_5769B0(int a1)
{
	int v1; // eax

	v1 = sub_576A10(a1);
	return sub_577A80(v1);
}

//----- (005769E0) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
int __cdecl sub_5769E0(int a1)
{
	return a1;
}

//----- (005769F0) --------------------------------------------------------
int __cdecl sub_5769F0(int a1)
{
	return a1 + 4;
}

//----- (00576A00) --------------------------------------------------------
int __cdecl sub_576A00(int a1)
{
	return a1 + 8;
}

//----- (00576A10) --------------------------------------------------------
int __cdecl sub_576A10(int a1)
{
	return a1 + 12;
}

//----- (00576A20) --------------------------------------------------------
_DWORD *__thiscall sub_576A20(int *this, _DWORD *a2, _DWORD *a3)
{
	_DWORD *v3; // eax
	_DWORD *v4; // eax
	int *v5; // eax
	int v6; // edx
	int v7; // eax
	_DWORD *v9; // eax
	_DWORD *v10; // eax
	int *v11; // eax
	int v12; // edx
	int v13; // eax
	int v14; // eax
	_DWORD *v15; // eax
	_DWORD *v16; // eax
	int *v17; // eax
	int v18; // edx
	int v19; // eax
	_DWORD *v20; // eax
	int v21; // edx
	_DWORD *v22; // [esp-4h] [ebp-7Ch]
	_DWORD *v23; // [esp-4h] [ebp-7Ch]
	int v24; // [esp+4h] [ebp-74h]
	int *v25; // [esp+8h] [ebp-70h]
	char v26; // [esp+Ch] [ebp-6Ch]
	char v27; // [esp+10h] [ebp-68h]
	char v28; // [esp+18h] [ebp-60h]
	char v29; // [esp+1Ch] [ebp-5Ch]
	char v30; // [esp+20h] [ebp-58h]
	char v31; // [esp+2Ch] [ebp-4Ch]
	char v32; // [esp+30h] [ebp-48h]
	char v33; // [esp+34h] [ebp-44h]
	char v34; // [esp+3Ch] [ebp-3Ch]
	char v35; // [esp+40h] [ebp-38h]
	char v36; // [esp+44h] [ebp-34h]
	char v37; // [esp+48h] [ebp-30h]
	char v38; // [esp+4Ch] [ebp-2Ch]
	char v39; // [esp+58h] [ebp-20h]
	int v40; // [esp+5Ch] [ebp-1Ch]
	int v41; // [esp+60h] [ebp-18h]
	int v42; // [esp+64h] [ebp-14h]
	int v43; // [esp+68h] [ebp-10h]
	int v44; // [esp+74h] [ebp-4h]

	v25 = this;
	v41 = *(_DWORD *)sub_5771D0(this);
	v40 = v25[1];
	LOBYTE(v42) = 1;
	std___Lockit___Lockit((std___Lockit *)&v39);
	v44 = 0;
	while (v41 != *(_DWORD *)&byte_5D4594[2516468])
	{
		v40 = v41;
		v22 = (_DWORD *)sub_5769B0(v41);
		v3 = (_DWORD *)sub_577A80((int)a3);
		LOBYTE(v42) = sub_576970(v3, v22);
		if ((_BYTE)v42)
			v24 = *(_DWORD *)sub_5769E0(v41);
		else
			v24 = *(_DWORD *)sub_576A00(v41);
		v41 = v24;
	}
	v44 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v39);
	if (*((_BYTE *)v25 + 8))
	{
		v37 = 1;
		v4 = sub_577AA0(v25, &v36, v41, v40, a3);
		v5 = (int *)sub_5776D0(&v38, v4, &v37);
		v6 = *v5;
		v7 = v5[1];
		*a2 = v6;
		a2[1] = v7;
		return a2;
	}
	v43 = *sub_5773E0(&v35, v40);
	if ((_BYTE)v42)
	{
		v9 = sub_575560(v25, &v34);
		if (sub_574530(&v43, v9))
		{
			v32 = 1;
			v10 = sub_577AA0(v25, &v31, v41, v40, a3);
			v11 = (int *)sub_5776D0(&v33, v10, &v32);
			v12 = *v11;
			v13 = v11[1];
			*a2 = v12;
			a2[1] = v13;
			return a2;
		}
		sub_578130(&v43);
	}
	v23 = (_DWORD *)sub_577A80((int)a3);
	v14 = sub_5773C0(&v43);
	v15 = (_DWORD *)sub_5769B0(v14);
	if (sub_576970(v15, v23))
	{
		v29 = 1;
		v16 = sub_577AA0(v25, &v28, v41, v40, a3);
		v17 = (int *)sub_5776D0(&v30, v16, &v29);
		v18 = *v17;
		v19 = v17[1];
		*a2 = v18;
		a2[1] = v19;
	}
	else
	{
		v26 = 0;
		v20 = sub_5776D0(&v27, &v43, &v26);
		v21 = v20[1];
		*a2 = *v20;
		a2[1] = v21;
	}
	return a2;
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00576C80) --------------------------------------------------------
_DWORD *__thiscall sub_576C80(int *this, _DWORD *a2, _DWORD *a3)
{
	int v3; // eax
	int v5; // [esp+4h] [ebp-4h]

	v5 = -858993460;
	v3 = sub_577F90(this, a3);
	*a2 = *sub_5773E0(&v5, v3);
	return a2;
}

//----- (00576CD0) --------------------------------------------------------
void __stdcall sub_576CD0(void *a1)
{
	void **v1; // eax
	int v2; // eax
	int v3; // [esp+4h] [ebp-14h]
	int i; // [esp+8h] [ebp-10h]
	int v5; // [esp+14h] [ebp-4h]

	v3 = -858993460;
	i = -858993460;
	std___Lockit___Lockit((std___Lockit *)&v3);
	v5 = 0;
	for (i = (int)a1; i != *(_DWORD *)&byte_5D4594[2516468]; a1 = (void *)i)
	{
		v1 = (void **)sub_576A00(i);
		sub_576CD0(*v1);
		i = *(_DWORD *)sub_5769E0(i);
		v2 = sub_576A10((int)a1);
		sub_577390(v2);
		sub_576080(a1);
	}
	v5 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v3);
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00576DA0) --------------------------------------------------------
void __thiscall sub_576DA0(int *this)
{
	int *v1; // [esp+0h] [ebp-14h]
	int v2; // [esp+4h] [ebp-10h]
	int v3; // [esp+10h] [ebp-4h]

	v2 = -858993460;
	v1 = this;
	std___Lockit___Lockit((std___Lockit *)&v2);
	v3 = 0;
	if (!*(_DWORD *)&byte_5D4594[2516468])
	{
		*(_DWORD *)&byte_5D4594[2516468] = sub_578080(0, 1);
		*(_DWORD *)sub_5769E0(*(int *)&byte_5D4594[2516468]) = 0;
		*(_DWORD *)sub_576A00(*(int *)&byte_5D4594[2516468]) = 0;
	}
	++*(_DWORD *)&byte_5D4594[2516472];
	v1[1] = sub_578080(*(int *)&byte_5D4594[2516468], 0);
	v1[3] = 0;
	*(_DWORD *)sub_576EA0(v1) = v1[1];
	*(_DWORD *)sub_5771A0(v1) = v1[1];
	v3 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v2);
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00576EA0) --------------------------------------------------------
int __thiscall sub_576EA0(_DWORD *this)
{
	return sub_5769E0(this[1]);
}

//----- (00576ED0) --------------------------------------------------------
void __thiscall sub_576ED0(int *this, int a2)
{
	_DWORD *v2; // esi
	int *v3; // eax
	_DWORD *v4; // esi
	_DWORD *v5; // eax
	int *v6; // eax
	int *v7; // eax
	_DWORD *v8; // eax
	int *v9; // eax
	_DWORD *v10; // eax
	int *v11; // [esp+4h] [ebp-18h]
	int v12; // [esp+8h] [ebp-14h]
	int v13; // [esp+Ch] [ebp-10h]
	int v14; // [esp+18h] [ebp-4h]

	v12 = -858993460;
	v13 = -858993460;
	v11 = this;
	std___Lockit___Lockit((std___Lockit *)&v12);
	v14 = 0;
	v13 = *(_DWORD *)sub_576A00(a2);
	v2 = (_DWORD *)sub_5769E0(v13);
	*(_DWORD *)sub_576A00(a2) = *v2;
	if (*(_DWORD *)sub_5769E0(v13) != *(_DWORD *)&byte_5D4594[2516468])
	{
		v3 = (int *)sub_5769E0(v13);
		*(_DWORD *)sub_5769F0(*v3) = a2;
	}
	v4 = (_DWORD *)sub_5769F0(a2);
	*(_DWORD *)sub_5769F0(v13) = *v4;
	if (a2 == *(_DWORD *)sub_5771D0(v11))
	{
		v5 = (_DWORD *)sub_5771D0(v11);
		*v5 = v13;
	}
	else
	{
		v6 = (int *)sub_5769F0(a2);
		if (a2 == *(_DWORD *)sub_5769E0(*v6))
		{
			v7 = (int *)sub_5769F0(a2);
			v8 = (_DWORD *)sub_5769E0(*v7);
		}
		else
		{
			v9 = (int *)sub_5769F0(a2);
			v8 = (_DWORD *)sub_576A00(*v9);
		}
		*v8 = v13;
	}
	*(_DWORD *)sub_5769E0(v13) = a2;
	v10 = (_DWORD *)sub_5769F0(a2);
	*v10 = v13;
	v14 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v12);
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00577060) --------------------------------------------------------
int __cdecl sub_577060(int a1)
{
	int v2; // [esp+4h] [ebp-10h]
	int v3; // [esp+10h] [ebp-4h]

	v2 = -858993460;
	std___Lockit___Lockit((std___Lockit *)&v2);
	v3 = 0;
	while (*(_DWORD *)sub_576A00(a1) != *(_DWORD *)&byte_5D4594[2516468])
		a1 = *(_DWORD *)sub_576A00(a1);
	v3 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v2);
	return a1;
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00577100) --------------------------------------------------------
int __cdecl sub_577100(int a1)
{
	int v2; // [esp+4h] [ebp-10h]
	int v3; // [esp+10h] [ebp-4h]

	v2 = -858993460;
	std___Lockit___Lockit((std___Lockit *)&v2);
	v3 = 0;
	while (*(_DWORD *)sub_5769E0(a1) != *(_DWORD *)&byte_5D4594[2516468])
		a1 = *(_DWORD *)sub_5769E0(a1);
	v3 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v2);
	return a1;
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (005771A0) --------------------------------------------------------
int __thiscall sub_5771A0(int *this)
{
	return sub_576A00(this[1]);
}

//----- (005771D0) --------------------------------------------------------
int __thiscall sub_5771D0(int *this)
{
	return sub_5769F0(this[1]);
}

//----- (00577200) --------------------------------------------------------
void __thiscall sub_577200(int *this, int a2)
{
	_DWORD *v2; // esi
	int *v3; // eax
	_DWORD *v4; // esi
	_DWORD *v5; // eax
	int *v6; // eax
	int *v7; // eax
	_DWORD *v8; // eax
	int *v9; // eax
	_DWORD *v10; // eax
	int *v11; // [esp+4h] [ebp-18h]
	int v12; // [esp+8h] [ebp-14h]
	int v13; // [esp+Ch] [ebp-10h]
	int v14; // [esp+18h] [ebp-4h]

	v12 = -858993460;
	v13 = -858993460;
	v11 = this;
	std___Lockit___Lockit((std___Lockit *)&v12);
	v14 = 0;
	v13 = *(_DWORD *)sub_5769E0(a2);
	v2 = (_DWORD *)sub_576A00(v13);
	*(_DWORD *)sub_5769E0(a2) = *v2;
	if (*(_DWORD *)sub_576A00(v13) != *(_DWORD *)&byte_5D4594[2516468])
	{
		v3 = (int *)sub_576A00(v13);
		*(_DWORD *)sub_5769F0(*v3) = a2;
	}
	v4 = (_DWORD *)sub_5769F0(a2);
	*(_DWORD *)sub_5769F0(v13) = *v4;
	if (a2 == *(_DWORD *)sub_5771D0(v11))
	{
		v5 = (_DWORD *)sub_5771D0(v11);
		*v5 = v13;
	}
	else
	{
		v6 = (int *)sub_5769F0(a2);
		if (a2 == *(_DWORD *)sub_576A00(*v6))
		{
			v7 = (int *)sub_5769F0(a2);
			v8 = (_DWORD *)sub_576A00(*v7);
		}
		else
		{
			v9 = (int *)sub_5769F0(a2);
			v8 = (_DWORD *)sub_5769E0(*v9);
		}
		*v8 = v13;
	}
	*(_DWORD *)sub_576A00(v13) = a2;
	v10 = (_DWORD *)sub_5769F0(a2);
	*v10 = v13;
	v14 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v12);
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00577390) --------------------------------------------------------
void __stdcall sub_577390(int a1)
{
	sub_5717C0();
}

//----- (005773C0) --------------------------------------------------------
int __thiscall sub_5773C0(void *this)
{
	return *(_DWORD *)this;
}

//----- (005773E0) --------------------------------------------------------
_DWORD *__thiscall sub_5773E0(_DWORD *this, int a2)
{
	_DWORD *v3; // [esp+0h] [ebp-4h]

	v3 = this;
	sub_5780E0(this, a2);
	return v3;
}

//----- (00577410) --------------------------------------------------------
int *__thiscall sub_577410(int *this, int *a2, int a3)
{
	int v4; // [esp+4h] [ebp-4h]

	v4 = *this;
	sub_578100(this);
	*a2 = v4;
	return a2;
}

//----- (00577460) --------------------------------------------------------
unsigned int __thiscall sub_577460(unsigned int this, _DWORD *a2, unsigned int a3, _DWORD *a4)
{
	unsigned int result; // eax
	unsigned int v5; // [esp+0h] [ebp-14h]
	unsigned int v6; // [esp+4h] [ebp-10h]
	int v7; // [esp+8h] [ebp-Ch]
	char *v8; // [esp+Ch] [ebp-8h]
	char *v9; // [esp+10h] [ebp-4h]

	v6 = this;
	if ((*(_DWORD *)(this + 12) - *(_DWORD *)(this + 8)) >> 2 >= a3)
	{
		result = (*(_DWORD *)(this + 8) - (int)a2) >> 2;
		if (result >= a3)
		{
			if (a3)
			{
				sub_576260((_DWORD *)(*(_DWORD *)(this + 8) - 4 * a3), *(_DWORD **)(this + 8), *(char **)(this + 8));
				sub_578780(a2, (_DWORD *)(*(_DWORD *)(v6 + 8) - 4 * a3), *(_DWORD **)(v6 + 8));
				sub_578750(a2, &a2[a3], a4);
				result = a3;
				*(_DWORD *)(v6 + 8) += 4 * a3;
			}
		}
		else
		{
			sub_576260(a2, *(_DWORD **)(this + 8), (char *)&a2[a3]);
			sub_5762B0(*(char **)(v6 + 8), a3 - ((*(_DWORD *)(v6 + 8) - (int)a2) >> 2), a4);
			sub_578750(a2, *(_DWORD **)(v6 + 8), a4);
			result = v6;
			*(_DWORD *)(v6 + 8) += 4 * a3;
		}
	}
	else
	{
		if (a3 >= sub_576170((_DWORD *)this))
			v5 = a3;
		else
			v5 = sub_576170((_DWORD *)v6);
		v7 = v5 + sub_576170((_DWORD *)v6);
		v8 = (char *)sub_576300(v7, 0);
		v9 = sub_576260(*(_DWORD **)(v6 + 4), a2, v8);
		sub_5762B0(v9, a3, a4);
		sub_576260(a2, *(_DWORD **)(v6 + 8), &v9[4 * a3]);
		sub_576220(*(_DWORD *)(v6 + 4), *(_DWORD *)(v6 + 8));
		sub_576330(*(LPVOID *)(v6 + 4), (*(_DWORD *)(v6 + 12) - *(_DWORD *)(v6 + 4)) >> 2);
		*(_DWORD *)(v6 + 12) = &v8[4 * v7];
		*(_DWORD *)(v6 + 8) = &v8[4 * sub_576170((_DWORD *)v6) + 4 * a3];
		result = v6;
		*(_DWORD *)(v6 + 4) = v8;
	}
	return result;
}

//----- (005776A0) --------------------------------------------------------
_DWORD *__stdcall sub_5776A0(void *a1, _DWORD *a2)
{
	return sub_5787B0(a1, a2);
}

//----- (005776D0) --------------------------------------------------------
_BYTE *__thiscall sub_5776D0(_BYTE *this, _DWORD *a2, _BYTE *a3)
{
	*(_DWORD *)this = *a2;
	this[4] = *a3;
	return this;
}

//----- (00577700) --------------------------------------------------------
int string__max_size()
{
	int v1; // [esp+0h] [ebp-Ch]
	unsigned int v2; // [esp+8h] [ebp-4h]

	v2 = sub_578190();
	if (v2 > 2)
		v1 = v2 - 2;
	else
		v1 = 1;
	return v1;
}

//----- (00577760) --------------------------------------------------------
_BYTE *__thiscall sub_577760(int *this, unsigned int a2)
{
	unsigned int v2; // eax
	int v4; // [esp+0h] [ebp-38h]
	int v5; // [esp+Ch] [ebp-2Ch]
	unsigned int v6; // [esp+10h] [ebp-28h]
	int v7; // [esp+14h] [ebp-24h]
	int *v8; // [esp+18h] [ebp-20h]
	unsigned int v9; // [esp+1Ch] [ebp-1Ch]
	int v10; // [esp+20h] [ebp-18h]
	unsigned int v11; // [esp+24h] [ebp-14h]
	int *v12; // [esp+28h] [ebp-10h]
	int v13; // [esp+34h] [ebp-4h]

	v12 = &v4;
	v5 = -858993460;
	v6 = -858993460;
	v7 = -858993460;
	v10 = -858993460;
	v11 = -858993460;
	v8 = this;
	v2 = a2;
	LOBYTE(v2) = a2 | 0x1F;
	v9 = v2;
	if (string__max_size() < v2)
		v9 = a2;
	v13 = 0;
	v7 = (int)sub_578160(v9 + 2, 0);
	v10 = v7;
	v13 = -1;
	if (v8[2])
	{
		if (v8[2] <= v9)
			v6 = v8[2];
		else
			v6 = v9;
		sub_574B60(v10 + 1, (_BYTE *)v8[1], v6);
	}
	v11 = v8[2];
	sub_574CE0(v8, 1);
	v8[1] = v10 + 1;
	*(_BYTE *)sub_576600(v8[1]) = 0;
	v8[3] = v9;
	if (v11 <= v9)
		v5 = v11;
	else
		v5 = v9;
	return string___Eos(v8, v5);
}

//----- (005778C0) --------------------------------------------------------
int *__thiscall sub_5778C0(int *this)
{
	int *result; // eax
	int *v2; // [esp+0h] [ebp-8h]
	char *v3; // [esp+4h] [ebp-4h]

	v2 = this;
	result = this;
	if (this[1])
	{
		result = (int *)sub_576600(this[1]);
		if (*(_BYTE *)result)
		{
			result = (int *)sub_576600(v2[1]);
			if (*(unsigned __int8 *)result != 255)
			{
				v3 = (char *)v2[1];
				sub_574CE0(v2, 1);
				result = sub_577940(v2, v3);
			}
		}
	}
	return result;
}

//----- (00577940) --------------------------------------------------------
int *__thiscall sub_577940(int *this, char *a2)
{
	unsigned int v2; // eax
	int *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v2 = sub_577980(a2);
	return sub_5779A0(v4, a2, v2);
}

//----- (00577980) --------------------------------------------------------
size_t __cdecl sub_577980(char *a1)
{
	return strlen(a1);
}

//----- (005779A0) --------------------------------------------------------
int *__thiscall sub_5779A0(int *this, _BYTE *a2, unsigned int a3)
{
	int *v4; // [esp+0h] [ebp-4h]

	v4 = this;
	if (string___Grow(this, a3, 1))
	{
		sub_574B60(v4[1], a2, a3);
		string___Eos(v4, a3);
	}
	return v4;
}

//----- (00577A00) --------------------------------------------------------
int __stdcall sub_577A00(char *a1, int a2, int *a3)
{
	int result; // eax

	while (a2)
	{
		sub_570AC0(a1, a3);
		result = --a2;
		a1 += 16;
	}
	return result;
}

//----- (00577A50) --------------------------------------------------------
_DWORD *__stdcall sub_577A50(void *a1, _DWORD *a2)
{
	return sub_578810(a1, a2);
}

//----- (00577A80) --------------------------------------------------------
int __stdcall sub_577A80(int a1)
{
	return a1;
}

//----- (00577AA0) --------------------------------------------------------
_DWORD *__thiscall sub_577AA0(int *this, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
	void *v5; // eax
	_DWORD *v6; // eax
	_DWORD *v7; // eax
	_DWORD *v8; // eax
	_DWORD *v9; // eax
	_DWORD *v10; // eax
	_DWORD *v11; // eax
	_DWORD *v12; // eax
	int *v13; // eax
	_DWORD *v14; // esi
	int *v15; // eax
	int *v16; // eax
	int *v17; // eax
	int *v18; // eax
	int *v19; // eax
	int *v20; // eax
	int *v21; // eax
	int *v22; // eax
	int *v23; // eax
	int *v24; // eax
	int *v25; // eax
	int *v26; // eax
	int *v27; // eax
	int *v28; // eax
	int *v29; // eax
	int *v30; // eax
	int *v31; // eax
	int *v32; // eax
	int *v33; // eax
	int *v34; // eax
	int *v35; // eax
	int *v36; // eax
	int *v37; // eax
	int *v38; // eax
	int *v39; // eax
	int *v40; // eax
	int *v41; // eax
	int *v42; // eax
	int *v43; // eax
	_DWORD *v45; // [esp-4h] [ebp-28h]
	int *v46; // [esp+4h] [ebp-20h]
	int v47; // [esp+8h] [ebp-1Ch]
	int v48; // [esp+Ch] [ebp-18h]
	int v49; // [esp+10h] [ebp-14h]
	int v50; // [esp+14h] [ebp-10h]
	int v51; // [esp+20h] [ebp-4h]
	int v52; // [esp+30h] [ebp+Ch]
	int v53; // [esp+34h] [ebp+10h]
	int v54; // [esp+34h] [ebp+10h]

	v47 = -858993460;
	v48 = -858993460;
	v49 = -858993460;
	v50 = -858993460;
	v46 = this;
	std___Lockit___Lockit((std___Lockit *)&v49);
	v51 = 0;
	v50 = sub_578080(a4, 0);
	*(_DWORD *)sub_5769E0(v50) = *(_DWORD *)&byte_5D4594[2516468];
	*(_DWORD *)sub_576A00(v50) = *(_DWORD *)&byte_5D4594[2516468];
	v5 = (void *)sub_576A10(v50);
	sub_578210(v5, a5);
	++v46[3];
	if (a4 == v46[1]
		|| a3 != *(_DWORD *)&byte_5D4594[2516468]
		|| (v45 = (_DWORD *)sub_5769B0(a4), v6 = (_DWORD *)sub_577A80((int)a5), sub_576970(v6, v45)))
	{
		v7 = (_DWORD *)sub_5769E0(a4);
		*v7 = v50;
		if (a4 == v46[1])
		{
			v8 = (_DWORD *)sub_5771D0(v46);
			*v8 = v50;
			v9 = (_DWORD *)sub_5771A0(v46);
			*v9 = v50;
		}
		else if (a4 == *(_DWORD *)sub_576EA0(v46))
		{
			v10 = (_DWORD *)sub_576EA0(v46);
			*v10 = v50;
		}
	}
	else
	{
		v11 = (_DWORD *)sub_576A00(a4);
		*v11 = v50;
		if (a4 == *(_DWORD *)sub_5771A0(v46))
		{
			v12 = (_DWORD *)sub_5771A0(v46);
			*v12 = v50;
		}
	}
	v52 = v50;
	while (v52 != *(_DWORD *)sub_5771D0(v46))
	{
		v13 = (int *)sub_5769F0(v52);
		if (*(_DWORD *)sub_5769A0(*v13))
			break;
		v14 = (_DWORD *)sub_5769F0(v52);
		v15 = (int *)sub_5769F0(v52);
		v16 = (int *)sub_5769F0(*v15);
		if (*v14 == *(_DWORD *)sub_5769E0(*v16))
		{
			v17 = (int *)sub_5769F0(v52);
			v18 = (int *)sub_5769F0(*v17);
			v19 = (int *)sub_576A00(*v18);
			v53 = *v19;
			if (*(_DWORD *)sub_5769A0(*v19))
			{
				v24 = (int *)sub_5769F0(v52);
				if (v52 == *(_DWORD *)sub_576A00(*v24))
				{
					v52 = *(_DWORD *)sub_5769F0(v52);
					sub_576ED0(v46, v52);
				}
				v25 = (int *)sub_5769F0(v52);
				*(_DWORD *)sub_5769A0(*v25) = 1;
				v26 = (int *)sub_5769F0(v52);
				v27 = (int *)sub_5769F0(*v26);
				*(_DWORD *)sub_5769A0(*v27) = 0;
				v28 = (int *)sub_5769F0(v52);
				v29 = (int *)sub_5769F0(*v28);
				sub_577200(v46, *v29);
			}
			else
			{
				v20 = (int *)sub_5769F0(v52);
				*(_DWORD *)sub_5769A0(*v20) = 1;
				*(_DWORD *)sub_5769A0(v53) = 1;
				v21 = (int *)sub_5769F0(v52);
				v22 = (int *)sub_5769F0(*v21);
				*(_DWORD *)sub_5769A0(*v22) = 0;
				v23 = (int *)sub_5769F0(v52);
				v52 = *(_DWORD *)sub_5769F0(*v23);
			}
		}
		else
		{
			v30 = (int *)sub_5769F0(v52);
			v31 = (int *)sub_5769F0(*v30);
			v32 = (int *)sub_5769E0(*v31);
			v54 = *v32;
			if (*(_DWORD *)sub_5769A0(*v32))
			{
				v37 = (int *)sub_5769F0(v52);
				if (v52 == *(_DWORD *)sub_5769E0(*v37))
				{
					v52 = *(_DWORD *)sub_5769F0(v52);
					sub_577200(v46, v52);
				}
				v38 = (int *)sub_5769F0(v52);
				*(_DWORD *)sub_5769A0(*v38) = 1;
				v39 = (int *)sub_5769F0(v52);
				v40 = (int *)sub_5769F0(*v39);
				*(_DWORD *)sub_5769A0(*v40) = 0;
				v41 = (int *)sub_5769F0(v52);
				v42 = (int *)sub_5769F0(*v41);
				sub_576ED0(v46, *v42);
			}
			else
			{
				v33 = (int *)sub_5769F0(v52);
				*(_DWORD *)sub_5769A0(*v33) = 1;
				*(_DWORD *)sub_5769A0(v54) = 1;
				v34 = (int *)sub_5769F0(v52);
				v35 = (int *)sub_5769F0(*v34);
				*(_DWORD *)sub_5769A0(*v35) = 0;
				v36 = (int *)sub_5769F0(v52);
				v52 = *(_DWORD *)sub_5769F0(*v36);
			}
		}
	}
	v43 = (int *)sub_5771D0(v46);
	*(_DWORD *)sub_5769A0(*v43) = 1;
	*a2 = *sub_5773E0(&v47, v50);
	v51 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v49);
	return a2;
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00577F90) --------------------------------------------------------
int __thiscall sub_577F90(int *this, _DWORD *a2)
{
	_DWORD *v2; // eax
	int *v4; // [esp+0h] [ebp-20h]
	int v5; // [esp+4h] [ebp-1Ch]
	int v6; // [esp+8h] [ebp-18h]
	int v7; // [esp+Ch] [ebp-14h]
	int v8; // [esp+10h] [ebp-10h]
	int v9; // [esp+1Ch] [ebp-4h]

	v6 = -858993460;
	v7 = -858993460;
	v8 = -858993460;
	v4 = this;
	std___Lockit___Lockit((std___Lockit *)&v6);
	v9 = 0;
	v8 = *(_DWORD *)sub_5771D0(v4);
	v7 = v4[1];
	while (v8 != *(_DWORD *)&byte_5D4594[2516468])
	{
		v2 = (_DWORD *)sub_5769B0(v8);
		if (sub_576970(v2, a2))
		{
			v8 = *(_DWORD *)sub_576A00(v8);
		}
		else
		{
			v7 = v8;
			v8 = *(_DWORD *)sub_5769E0(v8);
		}
	}
	v5 = v7;
	v9 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v6);
	return v5;
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00578080) --------------------------------------------------------
int __stdcall sub_578080(int a1, int a2)
{
	void *v2; // eax
	int v4; // [esp+4h] [ebp-4h]

	v2 = sub_5781E0(28);
	v4 = (int)v2;
	*(_DWORD *)sub_5769F0((int)v2) = a1;
	*(_DWORD *)sub_5769A0(v4) = a2;
	return v4;
}

//----- (005780E0) --------------------------------------------------------
_DWORD *__thiscall sub_5780E0(_DWORD *this, int a2)
{
	*this = a2;
	return this;
}

//----- (00578100) --------------------------------------------------------
int *__thiscall sub_578100(int *this)
{
	int *v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_578370(this);
	return v2;
}

//----- (00578130) --------------------------------------------------------
int *__thiscall sub_578130(int *this)
{
	int *v2; // [esp+0h] [ebp-4h]

	v2 = this;
	sub_578240(this);
	return v2;
}

//----- (00578160) --------------------------------------------------------
void *__stdcall sub_578160(signed int a1, int a2)
{
	return sub_5788A0(a1);
}

//----- (00578190) --------------------------------------------------------
int sub_578190()
{
	return -1;
}

//----- (005781E0) --------------------------------------------------------
void *__stdcall sub_5781E0(signed int a1)
{
	return sub_5788A0(a1);
}

//----- (00578210) --------------------------------------------------------
_DWORD *__stdcall sub_578210(void *a1, _DWORD *a2)
{
	return sub_5788D0(a1, a2);
}

//----- (00578240) --------------------------------------------------------
void __thiscall sub_578240(int *this)
{
	int *v1; // eax
	int *v2; // eax
	int *v3; // eax
	int *v4; // [esp+0h] [ebp-18h]
	int v5; // [esp+4h] [ebp-14h]
	int v6; // [esp+8h] [ebp-10h]
	int v7; // [esp+14h] [ebp-4h]

	v6 = -858993460;
	v4 = this;
	std___Lockit___Lockit((std___Lockit *)&v6);
	v7 = 0;
	if (*(_DWORD *)sub_5769A0(*v4) || (v1 = (int *)sub_5769F0(*v4), *(_DWORD *)sub_5769F0(*v1) != *v4))
	{
		if (*(_DWORD *)sub_5769E0(*v4) == *(_DWORD *)&byte_5D4594[2516468])
		{
			while (1)
			{
				v3 = (int *)sub_5769F0(*v4);
				v5 = *v3;
				if (*v4 != *(_DWORD *)sub_5769E0(*v3))
					break;
				*v4 = v5;
			}
			*v4 = v5;
		}
		else
		{
			v2 = (int *)sub_5769E0(*v4);
			*v4 = sub_577060(*v2);
		}
	}
	else
	{
		*v4 = *(_DWORD *)sub_576A00(*v4);
	}
	v7 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v6);
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00578370) --------------------------------------------------------
void __thiscall sub_578370(int *this)
{
	int *v1; // eax
	int *v2; // eax
	int *v3; // [esp+0h] [ebp-18h]
	int v4; // [esp+4h] [ebp-14h]
	int v5; // [esp+8h] [ebp-10h]
	int v6; // [esp+14h] [ebp-4h]

	v5 = -858993460;
	v3 = this;
	std___Lockit___Lockit((std___Lockit *)&v5);
	v6 = 0;
	if (*(_DWORD *)sub_576A00(*v3) == *(_DWORD *)&byte_5D4594[2516468])
	{
		while (1)
		{
			v2 = (int *)sub_5769F0(*v3);
			v4 = *v2;
			if (*v3 != *(_DWORD *)sub_576A00(*v2))
				break;
			*v3 = v4;
		}
		if (*(_DWORD *)sub_576A00(*v3) != v4)
			*v3 = v4;
	}
	else
	{
		v1 = (int *)sub_576A00(*v3);
		*v3 = sub_577100(*v1);
	}
	v6 = -1;
	std___Lockit__destructor_Lockit((std___Lockit *)&v5);
}
// 57F677: using guessed type _DWORD __thiscall std___Lockit___Lockit(std___Lockit *__hidden this);
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00578460) --------------------------------------------------------
_DWORD *__cdecl sub_578460(_DWORD *a1, int a2, char a3, _DWORD *a4)
{
	_DWORD *v4; // eax

	while (sub_5784B0(&a2, &a3))
	{
		v4 = (_DWORD *)sub_5748A0(&a2);
		if (*v4 == *a4)
			break;
		sub_578A60(&a2);
	}
	*a1 = a2;
	return a1;
}

//----- (005784B0) --------------------------------------------------------
BOOL __cdecl sub_5784B0(void *a1, void *a2)
{
	return !sub_578A90(a1, a2);
}

//----- (005784E0) --------------------------------------------------------
int __cdecl sub_5784E0(int a1, unsigned __int16 *a2, unsigned __int16 **a3)
{
	while (a2 != *a3)
	{
		a1 = *a2 ^ sub_578520(a1, 1);
		++a2;
	}
	return a1;
}

//----- (00578520) --------------------------------------------------------
int __cdecl sub_578520(int a1, char a2)
{
	return __ROL4__(a1, a2);
}

//----- (00578540) --------------------------------------------------------
_DWORD *__cdecl sub_578540(_DWORD *a1, _DWORD *a2)
{
	_DWORD *v3; // [esp+0h] [ebp-8h]

	if (*a1 >= *a2)
		v3 = a2;
	else
		v3 = a1;
	return v3;
}

//----- (00578580) --------------------------------------------------------
_DWORD *__cdecl sub_578580(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
	_DWORD *result; // eax

	while (a1 != a2)
	{
		sub_570600(a1, a3);
		result = a1 + 9;
		a1 += 9;
	}
	return result;
}

//----- (005785B0) --------------------------------------------------------
_DWORD *__cdecl sub_5785B0(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
	while (a1 != a2)
	{
		a2 -= 9;
		a3 -= 9;
		sub_570600(a3, a2);
	}
	return a3;
}

//----- (005785F0) --------------------------------------------------------
_DWORD *__cdecl sub_5785F0(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
	while (a1 != a2)
	{
		sub_570600(a3, a1);
		a3 += 9;
		a1 += 9;
	}
	return a3;
}

//----- (00578630) --------------------------------------------------------
int __cdecl sub_578630(int *a1, int *a2)
{
	int result; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = *a1;
	*a1 = *a2;
	result = v3;
	*a2 = v3;
	return result;
}

//----- (00578660) --------------------------------------------------------
void *__cdecl sub_578660(int a1)
{
	if (a1 < 0)
		a1 = 0;
	return operator_new(4 * a1);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00578690) --------------------------------------------------------
int *__cdecl sub_578690(int *a1, int *a2, int *a3)
{
	int *result; // eax

	while (a1 != a2)
	{
		sub_570D10((wstring *)a1, (wstring *)a3);
		result = a1 + 4;
		a1 += 4;
	}
	return result;
}

//----- (005786C0) --------------------------------------------------------
int *__cdecl sub_5786C0(int *a1, int *a2, int *a3)
{
	while (a1 != a2)
	{
		a2 -= 4;
		a3 -= 4;
		sub_570D10((wstring *)a3, (wstring *)a2);
	}
	return a3;
}

//----- (00578700) --------------------------------------------------------
void *__cdecl sub_578700(int a1)
{
	if (a1 < 0)
		a1 = 0;
	return operator_new(36 * a1);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00578730) --------------------------------------------------------
int **__cdecl sub_578730(int **a1)
{
	return sub_578930(a1, 0);
}

//----- (00578750) --------------------------------------------------------
_DWORD *__cdecl sub_578750(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
	_DWORD *result; // eax

	while (a1 != a2)
	{
		*a1 = *a3;
		result = a1 + 1;
		++a1;
	}
	return result;
}

//----- (00578780) --------------------------------------------------------
_DWORD *__cdecl sub_578780(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
	while (a1 != a2)
	{
		--a2;
		--a3;
		*a3 = *a2;
	}
	return a3;
}

//----- (005787B0) --------------------------------------------------------
_DWORD *__cdecl sub_5787B0(void *a1, _DWORD *a2)
{
	_DWORD *result; // eax
	_DWORD *v3; // [esp+4h] [ebp-4h]

	result = (_DWORD *)sub_570C20(4, (int)a1);
	v3 = result;
	if (result)
	{
		result = (_DWORD *)*a2;
		*v3 = *a2;
	}
	return result;
}

//----- (00578810) --------------------------------------------------------
_DWORD *__cdecl sub_578810(void *a1, _DWORD *a2)
{
	_DWORD *result; // eax

	result = (_DWORD *)sub_570C20(36, (int)a1);
	if (result)
		result = sub_578970(result, a2);
	return result;
}

//----- (005788A0) --------------------------------------------------------
void *__cdecl sub_5788A0(signed int a1)
{
	if (a1 < 0)
		a1 = 0;
	return operator_new(a1);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (005788D0) --------------------------------------------------------
_DWORD *__cdecl sub_5788D0(void *a1, _DWORD *a2)
{
	_DWORD *result; // eax
	_DWORD *v3; // [esp+4h] [ebp-4h]

	result = (_DWORD *)sub_570C20(12, (int)a1);
	v3 = result;
	if (result)
	{
		*result = *a2;
		result = (_DWORD *)a2[1];
		v3[1] = result;
		v3[2] = a2[2];
	}
	return result;
}

//----- (00578930) --------------------------------------------------------
int **__thiscall sub_578930(int **this, char a2)
{
	int **lpMem; // [esp+0h] [ebp-4h]

	lpMem = this;
	sub_5705D0(this);
	if (a2 & 1)
		operator_delete(lpMem);
	return lpMem;
}

//----- (00578970) --------------------------------------------------------
_DWORD *__thiscall sub_578970(_DWORD *this, _DWORD *a2)
{
	_DWORD *v3; // [esp+0h] [ebp-4h]

	v3 = this;
	*this = *a2;
	this[1] = a2[1];
	this[2] = a2[2];
	this[3] = a2[3];
	sub_5789E0((_BYTE *)this + 16, a2 + 4);
	v3[8] = a2[8];
	return v3;
}

//----- (005789E0) --------------------------------------------------------
_DWORD *__thiscall sub_5789E0(_BYTE *this, _DWORD *a2)
{
	int v2; // eax
	int *v3; // eax
	int *v5; // [esp-8h] [ebp-Ch]
	char *v6; // [esp-4h] [ebp-8h]
	_DWORD *v7; // [esp+0h] [ebp-4h]

	v7 = this;
	*this = *(_BYTE *)a2;
	v2 = sub_5708A0(a2);
	v7[1] = sub_570A50(v2, 0);
	v6 = (char *)v7[1];
	v5 = (int *)wstring__size(a2);
	v3 = (int *)sub_575120(a2);
	v7[2] = sub_570A00(v3, v5, v6);
	v7[3] = v7[2];
	return v7;
}

//----- (00578A60) --------------------------------------------------------
_DWORD *__thiscall sub_578A60(_DWORD *this)
{
	*this -= 4;
	return this;
}

//----- (00578A90) --------------------------------------------------------
bool __cdecl sub_578A90(void *a1, void *a2)
{
	int v2; // esi

	v2 = sub_5773C0(a1);
	return v2 == sub_5773C0(a2);
}
#endif
