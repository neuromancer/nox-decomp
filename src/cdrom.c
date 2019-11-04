#include "proto.h"

#if 1
BOOL __cdecl sub_423CC0(int a1)
{
	return 0;
}

BOOL sub_423C60()
{
	return 0;
}

unsigned __int8 sub_423EC0()
{
	return 0;
}
#else
//----- (00423CC0) --------------------------------------------------------
BOOL __cdecl sub_423CC0(int a1)
{
	BOOL result; // eax

	if (*(_DWORD *)&byte_5D4594[588112] && a1 == 1)
		result = *(_DWORD *)&byte_5D4594[588096] == 530;
	else
		result = 0;
	return result;
}

//----- (00423BB0) --------------------------------------------------------
int sub_423BB0()
{
	int result; // eax
	DWORD_PTR dwParam2[5]; // [esp+0h] [ebp-14h]

	result = *(_DWORD *)&byte_5D4594[588112];
	if (!*(_DWORD *)&byte_5D4594[588112])
	{
		dwParam2[0] = 0;
		dwParam2[4] = 0;
		dwParam2[2] = 516;
		dwParam2[3] = 0;
		dwParam2[1] = 0;
		if (mciSendCommandA(0, 0x803u, 0x3102u, (DWORD_PTR)dwParam2))
		{
			result = *(_DWORD *)&byte_5D4594[588112];
		}
		else
		{
			result = 1;
			*(_DWORD *)&byte_5D4594[588108] = dwParam2[1];
			*(_DWORD *)&byte_5D4594[588112] = 1;
		}
	}
	return result;
}

//----- (00423C20) --------------------------------------------------------
MCIERROR __thiscall sub_423C20(void *this)
{
	MCIERROR result; // eax
	DWORD_PTR dwParam2; // [esp+0h] [ebp-4h]

	dwParam2 = (DWORD_PTR)this;
	result = *(_DWORD *)&byte_5D4594[588112];
	if (*(_DWORD *)&byte_5D4594[588112])
	{
		dwParam2 = 0;
		result = mciSendCommandA(*(MCIDEVICEID *)&byte_5D4594[588108], 0x804u, 2u, (DWORD_PTR)&dwParam2);
		*(_DWORD *)&byte_5D4594[588112] = 0;
	}
	return result;
}

//----- (00423C60) --------------------------------------------------------
BOOL sub_423C60()
{
	if (!*(_DWORD *)&byte_5D4594[588112])
		return 0;
	*(_DWORD *)&byte_5D4594[588092] = sub_401FD0();
	*(_DWORD *)&byte_5D4594[588100] = 4;
	*(_DWORD *)&byte_5D4594[588104] = 0;
	*(_DWORD *)&byte_5D4594[588096] = 0;
	return mciSendCommandA(*(MCIDEVICEID *)&byte_5D4594[588108], 0x814u, 0x101u, (DWORD_PTR)&byte_5D4594[588092]) == 0;
}

//----- (00423CF0) --------------------------------------------------------
int sub_423CF0()
{
	char *v0; // ebp
	int result; // eax
	_DWORD *v2; // ecx
	unsigned __int8 *v3; // edx
	int v4; // [esp+10h] [ebp-1A0h]
	int v5; // [esp+14h] [ebp-19Ch]
	int v6; // [esp+18h] [ebp-198h]
	BYTE SectorsPerCluster[144]; // [esp+1Ch] [ebp-194h]
	char Buffer[260]; // [esp+ACh] [ebp-104h]

	byte_5D4594[588116] = 0;
	if (!GetLogicalDriveStringsA(0x104u, Buffer))
		return 0;
	v0 = Buffer;
	if (!strlen(Buffer))
		return 0;
	while (GetDriveTypeA(v0) != 5
		|| !sub_423ED0(v0, (DWORD)SectorsPerCluster)
		|| _strnicmp((const char *)&byte_587000[64664], (const char *)&SectorsPerCluster[4], 3u))
	{
		v0 += strlen(v0) + 1;
		if (!strlen(v0))
			return 0;
	}
	v5 = 0;
	v6 = 0;
	v4 = 0;
	if (_strcmpi((const char *)&SectorsPerCluster[72], (const char *)&byte_587000[64668])
		|| *(_DWORD *)&SectorsPerCluster[136] > 0u)
	{
		return 0;
	}
	if (SetVolumeLabelA(v0, (LPCSTR)&byte_587000[64676]))
	{
		SetVolumeLabelA(v0, (LPCSTR)&SectorsPerCluster[4]);
		return 0;
	}
	strcpy(Buffer, v0);
	*(_WORD *)&Buffer[strlen(Buffer)] = *(_WORD *)&byte_587000[64684];
	sub_423F80(Buffer, (int)&v6, (int)&v5, (int)&v4);
	v2 = *(_DWORD **)&byte_587000[64660];
	result = 2;
	if (*(_DWORD *)&byte_587000[64660])
	{
		v3 = &byte_587000[64660];
		do
		{
			if ((unsigned int)v4 >= *v2 && (unsigned int)v6 >= v2[1] && (unsigned int)v5 >= v2[2])
				break;
			v2 = (_DWORD *)*((_DWORD *)v3 - 1);
			v3 -= 4;
			--result;
		} while (v2);
	}
	if (result == 1)
	{
		if (SectorsPerCluster[7] == 50)
			goto LABEL_23;
		return 0;
	}
	if (result != 2)
		return 0;
	if (SectorsPerCluster[7] != 49)
		return 0;
LABEL_23:
	byte_5D4594[588116] = *v0;
	return result;
}
// 423CF0: using guessed type CHAR Buffer[260];

//----- (00423EC0) --------------------------------------------------------
unsigned __int8 sub_423EC0()
{
	return byte_5D4594[588116];
}

//----- (00423ED0) --------------------------------------------------------
BOOL __cdecl sub_423ED0(LPCSTR lpRootPathName, DWORD SectorsPerCluster)
{
	DWORD v2; // esi
	const CHAR *v3; // edi
	BOOL result; // eax
	DWORD v5; // eax
	bool v6; // zf
	DWORD NumberOfFreeClusters; // [esp+8h] [ebp-10h]
	DWORD TotalNumberOfClusters; // [esp+Ch] [ebp-Ch]
	DWORD FileSystemFlags; // [esp+10h] [ebp-8h]
	DWORD MaximumComponentLength; // [esp+14h] [ebp-4h]

	v2 = SectorsPerCluster;
	memset((void *)SectorsPerCluster, 0, 0x90u);
	v3 = lpRootPathName;
	*(_DWORD *)v2 = GetDriveTypeA(lpRootPathName);
	result = GetDiskFreeSpaceA(
		v3,
		&SectorsPerCluster,
		(LPDWORD)&lpRootPathName,
		&NumberOfFreeClusters,
		&TotalNumberOfClusters);
	if (result)
	{
		v5 = (_DWORD)lpRootPathName * SectorsPerCluster;
		v6 = NumberOfFreeClusters == 0;
		*(_DWORD *)(v2 + 136) = NumberOfFreeClusters * (_DWORD)lpRootPathName * SectorsPerCluster;
		if (v6)
		{
			*(_DWORD *)(v2 + 140) = TotalNumberOfClusters * v5;
			result = GetVolumeInformationA(
				v3,
				(LPSTR)(v2 + 4),
				0x40u,
				(LPDWORD)(v2 + 68),
				&MaximumComponentLength,
				&FileSystemFlags,
				(LPSTR)(v2 + 72),
				0x40u);
		}
		else
		{
			result = 0;
		}
	}
	return result;
}
#endif