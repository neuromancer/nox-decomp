#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "proto.h"

void f(int);
void mainloop_exit_1();
void mainloop_exit_2();
// defined in GAME1.c
extern void (*mainloop_enter)(void *);
extern void *mainloop_enter_args;
extern void (*mainloop_exit)();
extern int g_v20, g_v21;
extern int g_a1, g_a2;

typedef union
{
    struct {
        BYTE data[153];
        const char *hostname;
        WORD port;
    } connect_server;

    struct {
        BYTE data[153];
        unsigned int id;
        const char *hostname;
        WORD port;
    } net_connect;

    struct {
        BYTE data[153];
        unsigned int id;
        char val;
        unsigned int retries;
        unsigned int flags;
        unsigned int counter;
    } net_connect_wait_loop;

    struct {
        BYTE data[153];
        unsigned int id;
        int result;
    } net_connect_wait_then;

    struct {
        int result;
    } net_connect_then;

    struct {
        ULONGLONG timeout;
    } connect_wait_loop;

    struct {
        int result;
    } connect_wait_then;

    struct {
        int result;
    } connect_result;

} sm_args_t;

void CONNECT_PREPARE (sm_args_t *args);
void CONNECT_SERVER (sm_args_t *args);
void NET_CONNECT (sm_args_t *args);
void NET_CONNECT_WAIT_LOOP (sm_args_t *args);
void NET_CONNECT_WAIT_THEN (sm_args_t *args);
void NET_CONNECT_THEN (sm_args_t *args);
void CONNECT_WAIT_LOOP (sm_args_t *args);
void CONNECT_WAIT_THEN (sm_args_t *args);
void CONNECT_RESULT (sm_args_t *args);

#define GOTO_(state,fps) do { \
  mainloop_enter = state; \
  mainloop_enter_args = args; \
  printf("goto %s\n", #state); \
  return; \
} while(0)

#define GOTO_CONNECT_PREPARE() do { \
  GOTO_(CONNECT_PREPARE, 0); \
} while(0)

#define GOTO_CONNECT_SERVER(hostname_, port_, data_) do { \
  args->connect_server.hostname = hostname_; \
  args->connect_server.port = port_; \
  memmove(args->connect_server.data, data_, sizeof(args->connect_server.data)); \
  GOTO_(CONNECT_SERVER, 0); \
} while(0)

#define GOTO_NET_CONNECT(id_, hostname_, port_, data_) do { \
  args->net_connect.id = id_; \
  args->net_connect.hostname = hostname_; \
  args->net_connect.port = port_; \
  memmove(args->net_connect.data, data_, sizeof(args->net_connect.data)); \
  GOTO_(NET_CONNECT, 0); \
} while(0)

#define GOTO_NET_CONNECT_WAIT_LOOP(data_, id_, val_, retries_, flags_) do { \
  memmove(args->net_connect_wait_loop.data, data_, sizeof(args->net_connect_wait_loop.data)); \
  args->net_connect_wait_loop.id = id_; \
  args->net_connect_wait_loop.val = val_; \
  args->net_connect_wait_loop.retries = retries_; \
  args->net_connect_wait_loop.flags = flags_; \
  args->net_connect_wait_loop.counter = 0; \
  GOTO_(NET_CONNECT_WAIT_LOOP, 0); \
} while(0)

#define GOTO_NET_CONNECT_WAIT_THEN(data_, id_, result_) do { \
  memmove(args->net_connect_wait_then.data, data_, sizeof(args->net_connect_wait_then.data)); \
  args->net_connect_wait_then.id = id_; \
  args->net_connect_wait_then.result = result_; \
  GOTO_(NET_CONNECT_WAIT_THEN, 0); \
} while (0)

#define GOTO_NET_CONNECT_THEN(result_) do { \
  args->net_connect_then.result = result_; \
  GOTO_(NET_CONNECT_THEN, 0); \
} while (0)

#define GOTO_CONNECT_WAIT_LOOP(timeout_) do { \
  args->connect_wait_loop.timeout = timeout_; \
  GOTO_(CONNECT_WAIT_LOOP, 0); \
} while (0)

#define GOTO_CONNECT_WAIT_THEN(result_) do { \
  args->connect_wait_then.result = result_; \
  GOTO_(CONNECT_WAIT_THEN, 0); \
} while (0)

#define GOTO_CONNECT_RESULT(result_) do { \
  args->connect_result.result = result_; \
  GOTO_(CONNECT_RESULT, 0); \
} while (0)

void CONNECT_PREPARE (sm_args_t *args)
{
  char *v1; // ebx
  int result; // eax
  unsigned __int16 v3; // ax
  int v4; // [esp+Ch] [ebp-A8h]
  int v5; // [esp+10h] [ebp-A4h]
  int v6; // [esp+14h] [ebp-A0h]
  BYTE Data[153]; // [esp+18h] [ebp-9Ch]

  sub_43BEB0(&v5, &v4, &v6);
  v1 = sub_431770();
  nox_wcscpy((wchar_t *)v1, (const wchar_t *)&byte_5D4594[2661908]);
  v1[66] = byte_5D4594[2661958];
  *(_WORD *)(v1 + 71) = *(_WORD *)&byte_5D4594[2661888];
  v1[73] = byte_5D4594[2661890];
  *((_WORD *)v1 + 34) = *(_WORD *)&byte_5D4594[2661891];
  v1[70] = byte_5D4594[2661893];
  *((_WORD *)v1 + 37) = *(_WORD *)&byte_5D4594[2661894];
  v1[76] = byte_5D4594[2661896];
  *(_WORD *)(v1 + 77) = *(_WORD *)&byte_5D4594[2661897];
  v1[79] = byte_5D4594[2661899];
  *((_WORD *)v1 + 40) = *(_WORD *)&byte_5D4594[2661900];
  v1[82] = byte_5D4594[2661902];
  v1[83] = byte_5D4594[2661903];
  v1[84] = byte_5D4594[2661904];
  v1[85] = byte_5D4594[2661905];
  v1[86] = byte_5D4594[2661906];
  v1[87] = byte_5D4594[2661907];
  v1[67] = byte_5D4594[2661959];
  sub_48D740();
  *(_DWORD *)&Data[97] = v5;
  *(_DWORD *)&Data[101] = v4;
  sub_420120(&Data[105]);
  if ( !sub_43AF70() )
    sub_40E0D0((int)&Data[105], (LPCSTR)&byte_587000[86344], 0);
  Data[152] = !sub_40ABD0();
  if ( byte_5D4594[2660684] & 4 )
    Data[152] |= 0x80u;
  strcpy((char *)&Data[142], (const char *)&byte_5D4594[2660099]);
  strcpy((char *)&Data[128], sub_41FA40());
  *(_DWORD *)&Data[138] = *(_DWORD *)&byte_5D4594[2660032];
  qmemcpy(Data, v1, 0x61u);

  if ( sub_40A5C0(1) )
  {
    sub_4D3860(Data);
    *(_DWORD *)&byte_5D4594[2616328] = sub_4DD320(31, Data);
    sub_409AE0(66458);
    sub_494E90(31);
    *(_DWORD *)&byte_5D4594[811372] = 2;
    GOTO_CONNECT_RESULT(0);
  }
  else
  {
    v3 = sub_43B320();
    GOTO_CONNECT_SERVER((char *)&byte_587000[85680], v3, Data);
  }
}

void CONNECT_SERVER (sm_args_t *args)
{
  int v4; // eax
  int v5; // eax
  int result; // eax
  char v7[40]; // [esp+8h] [ebp-28h]

  const char *cp = args->connect_server.hostname;
  int hostshort =  args->connect_server.port;

  memset(v7, 0, sizeof(v7));
  *(_DWORD *)&byte_5D4594[815704] = 0;
  *(_DWORD *)&byte_5D4594[815708] = 0;
  *(_DWORD *)&v7[20] = 2048;
  *(_DWORD *)&v7[8] = hostshort;
  sub_5520B0(200, 1024);
  *(_DWORD *)&v7[36] = sub_43C860;
  v4 = sub_5546F0((size_t *)v7);
  *(_DWORD *)&byte_5D4594[815700] = v4;

  GOTO_NET_CONNECT(v4, cp, hostshort, args->connect_server.data);
}

void NET_CONNECT (sm_args_t *args)
{
  int *v5; // ebp
  int v7; // eax
  unsigned int v8; // ebx
  struct hostent *v9; // eax
  int v10; // esi
  char v11; // al
  char v12; // [esp+12h] [ebp-1B2h]
  struct sockaddr name; // [esp+14h] [ebp-1B0h]
  WORD v14[2]; // [esp+24h] [ebp-1A0h]
  int v15; // [esp+28h] [ebp-19Ch]
  struct WSAData WSAData; // [esp+34h] [ebp-190h]

  int a1 = args->net_connect.id;
  const char *cp = args->net_connect.hostname;
  int hostshort = args->net_connect.port;

  v5 = *(int **)&byte_5D4594[4 * a1 + 3843788];
  if ( (unsigned int)a1 >= 0x80 )
    GOTO_NET_CONNECT_THEN(-3);
  if ( !v5 )
    GOTO_NET_CONNECT_THEN(-3);
  if ( !cp )
    GOTO_NET_CONNECT_THEN(-4);
  if ( hostshort < 1024 || hostshort > 0x10000 )
    GOTO_NET_CONNECT_THEN(-15);
  if ( WSAStartup(0x101u, &WSAData) == -1 )
    GOTO_NET_CONNECT_THEN(-21);
  v7 = socket(2, 2, 0);
  *v5 = v7;
  if ( v7 == -1 )
  {
    WSACleanup();
    GOTO_NET_CONNECT_THEN(-22);
  }
  if ( (unsigned __int8)*cp < 0x30u || (unsigned __int8)*cp > 0x39u )
  {
    v9 = gethostbyname(cp);
    if ( !v9 )
    {
      WSACleanup();
      GOTO_NET_CONNECT_THEN(-4);
    }
    v8 = **(_DWORD **)v9->h_addr_list;
  }
  else
  {
    v8 = inet_addr(cp);
  }
  v15 = 0;
  v14[0] = 2;
  v14[1] = htons(hostshort);
  v5[1] = *(_DWORD *)v14;
  v5[2] = v8;
  v5[3] = 0;
  v5[4] = 0;
  v10 = sub_40A420();
  name.sa_family = 2;
  *(_DWORD *)&name.sa_data[6] = 0;
  *(_DWORD *)&name.sa_data[10] = 0;
  *(_WORD *)name.sa_data = htons(v10);
  *(_DWORD *)&name.sa_data[2] = 0;
  while ( bind(*v5, &name, 16) == -1 )
  {
    if ( WSAGetLastError() != 10048 )
    {
      WSACleanup();
      GOTO_NET_CONNECT_THEN(-1);
    }
    *(_WORD *)name.sa_data = htons(++v10);
  }
  *(_DWORD *)&byte_5D4594[3844304] = 0;
  v12 = 0;
  v11 = sub_552640(a1, &v12, 1, 3);
  GOTO_NET_CONNECT_WAIT_LOOP(args->net_connect.data, a1, v11, 60, 6);
}

void NET_CONNECT_WAIT_LOOP (sm_args_t *args)
{
  int v4; // edi

  unsigned int a1 = args->net_connect_wait_loop.id;
  char a2 = args->net_connect_wait_loop.val;
  int a3 = args->net_connect_wait_loop.retries;
  char a4 = args->net_connect_wait_loop.flags;
  int v6 = args->net_connect_wait_loop.counter;

  v4 = *(_DWORD *)&byte_5D4594[4 * a1 + 3843788];
  if ( a1 >= 0x80 )
    GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -3);
  if ( !v4 )
    GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -3);
  v6 = 0;
  if ( 20 * a3 < ++v6 )
    GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -23);
  sub_552A80(a1, a4 | 1);
  sub_552460();
  if ( *(char *)(v4 + 113) >= a2 )
    GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, 0);

  args->net_connect_wait_loop.counter = v6;
}

void NET_CONNECT_WAIT_THEN (sm_args_t *args)
{
  int *v5;

  unsigned int a1 = args->net_connect_wait_then.id;
  void *a4 = args->net_connect_wait_then.data;
  unsigned int a5 = sizeof(args->net_connect_wait_then.data);

  if (args->net_connect_wait_then.result)
    GOTO_NET_CONNECT_THEN(-23);

  v5 = *(int **)&byte_5D4594[4 * a1 + 3843788];
  if ( *(_DWORD *)&byte_5D4594[3844304] && (int)v5[5] >= 0 )
  {
    memset(&byte_5D4594[2512892], 0, 0x400u);
    byte_5D4594[2512892] = 31;
    byte_5D4594[2512893] = *(_BYTE *)(v5[12] + 1);
    byte_5D4594[2512894] = 32;
    if ( a4 )
      qmemcpy(&byte_5D4594[2512895], (const void *)a4, a5);
    sub_552640(a1, &byte_5D4594[2512892], a5 + 3, 3);
  }
  GOTO_NET_CONNECT_THEN(v5[5]);
}

void NET_CONNECT_THEN (sm_args_t *args)
{
  int v5 = args->net_connect_then.result;
  if (v5 < 0)
    GOTO_CONNECT_RESULT(v5);

  if ( !sub_40A5C0(1) )
    *(_DWORD *)&byte_5D4594[2649712] |= 0x80000000;
  sub_40ED10(31, 0);
  sub_40A340(0);
  sub_40A360(0);
  GOTO_CONNECT_WAIT_LOOP(sub_416BB0() + 10000);
}

void CONNECT_WAIT_LOOP (sm_args_t *args)
{
  if (sub_416BB0() >= args->connect_wait_loop.timeout)
    GOTO_CONNECT_WAIT_THEN(0);
  
  sub_552A80(*(unsigned int *)&byte_5D4594[815700], 1);
  sub_40EE10(*(unsigned int *)&byte_5D4594[815700], 31, 0);
  sub_40ED10(31, 0);
  sub_552460();
  if ( sub_40A370() )
    GOTO_CONNECT_WAIT_THEN(1);
}

void CONNECT_WAIT_THEN (sm_args_t *args)
{
  if (!args->connect_wait_then.result)
    GOTO_CONNECT_RESULT(-19);
  if ( sub_409AD0() != 66458 )
    GOTO_CONNECT_RESULT(-20);
  *(_DWORD *)&byte_5D4594[811372] = 2;
  if ( !sub_40A5C0(1) )
    sub_417C60();
  GOTO_CONNECT_RESULT(0);
}

void CONNECT_RESULT (sm_args_t *args)
{
  int v25;
  int v26;
  int v28;
  int result = args->connect_result.result;

  if (result)
  {
    sub_40A540(0x100000);
    g_v21 = 0;
    if ( sub_40A5C0(1) )
      sub_4D3200();
    if ( sub_40A5C0(2) )
      sub_437190();
    sub_416190();
    if ( *(_WORD *)&byte_5D4594[2650636] & 0x1000 )
      sub_413E30();
    sub_43D0A0(result);
  }
  else
  {
    g_v21 = 1;
    if ( sub_4D38D0() != 1 )
    {
      if ( !sub_40A5C0(1) )
      {
        sub_43DDF0(0);
        goto LABEL_96;
      }
      if ( sub_4D17F0() )
      {
  LABEL_96:
        if ( !sub_40A5C0(2) )
        {
          sub_43DE20(0);
          goto LABEL_104;
        }
        if ( !sub_40A5C0(0x100000) )
        {
          sub_43BEB0(&v26, &v28, &v25);
          if ( !v26 )
            sub_43BEF0(640, 480, v25);
          if ( !sub_43BF10(0) )
            return;
        }
        if ( sub_435CC0() )
        {
  LABEL_104:
          if ( *(_WORD *)&byte_5D4594[2650636] & 0x1000 )
            sub_413E30();
          if ( sub_40A5C0(0x2000) && sub_40A5C0(1) && sub_43AF40() )
            sub_43AA70();
          sub_43F1A0();
          sub_434B30(*(int *)&byte_587000[80852]);
          sub_434B60();
          sub_40A4D0(0x10000000);
          mainloop_exit = mainloop_exit_2;
          sub_43E290();
          return;
        }
      }
    }
  }

  f(0);
}

void f(int reentrant)
{
  static sm_args_t args_;
  sm_args_t *args = &args_;
  char *v23;
  int v24;
  int v25;
  int v26;
  int v28;
  printf("%s %d\n", __FUNCTION__, reentrant);
  while ( 1 )
  {
    if (!reentrant)
    {
      sub_43F140(300);
      if ( !sub_43C060() )
        return;
      if ( !sub_43BFE0() )
        return;
      if ( g_v20 )
      {
        sub_43DBA0();
        g_v20 = 0;
      }
      sub_43F1A0();
      mainloop_exit = mainloop_exit_1;
      sub_43E290();
      return;
    }
    else
    {
      reentrant = 0;
    }

    if ( !*(_DWORD *)&byte_5D4594[805872] )
    {
      sub_43DB60();
      sub_43D990();
      g_v20 = 1;
      sub_43F140(800);
      sub_415F70();
      *(_DWORD *)&byte_5D4594[2598000] = sub_40A5C0(1);
      if ( !*(_DWORD *)&byte_5D4594[260] )
        *(_DWORD *)&byte_5D4594[260] = sub_40ABF0((char *)&byte_587000[372], 7);
      *(_DWORD *)&byte_5D4594[2650664] = 0;
      *(_DWORD *)&byte_5D4594[2649708] = 0;
      if ( g_v21 )
        GOTO_CONNECT_RESULT(0);
      if ( sub_40A5C0(1) )
      {
        if ( !sub_4D1660() )
          return;
      }
      if ( !sub_4357D0(g_a1, g_a2) )
        return;
      if ( sub_40A5C0(1) && sub_40A5C0(0x400000) && (byte_5D4594[2650636] & 1) == 1 )
      {
        v23 = sub_409E10();
        sub_4D39F0(v23);
        if ( !sub_4D4320() )
        {
          sub_4D12E0(0);
          return;
        }
        sub_4D3C30();
        sub_40A540(0x400000);
      }
      GOTO_CONNECT_PREPARE();
    }
    else
    {
      sub_437190();
      sub_43BF10(1);
      sub_431390();
    }
  }
}
