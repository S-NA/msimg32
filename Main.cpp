#include <Windows.h>

#pragma pack(1)

FARPROC p[5] = { 0 };

BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID pvReserved)
{
	static HINSTANCE hDLL;
	if (reason == DLL_PROCESS_ATTACH)
	{
		// DisableThreadLibraryCalls(hInst);
		hDLL = LoadLibrary(L".\\msimg32.dll");
		if (!hDLL) return false;
		p[0] = GetProcAddress(hDLL, "vSetDdrawflag");
		p[1] = GetProcAddress(hDLL, "AlphaBlend");
		p[2] = GetProcAddress(hDLL, "DllInitialize");
		p[3] = GetProcAddress(hDLL, "GradientFill");
		p[4] = GetProcAddress(hDLL, "TransparentBlt");
	}
	if (reason == DLL_PROCESS_DETACH)
		FreeLibrary(hDLL);
	return TRUE;
}

// vSetDdrawflag
extern "C" __declspec(naked) void __stdcall __E__0__()
{
	__asm
	{
		jmp p[0 * 4];
	}
}

// AlphaBlend
extern "C" __declspec(naked) void __stdcall __E__1__()
{
	__asm
	{
		jmp p[1 * 4];
	}
}

// DllInitialize
extern "C" __declspec(naked) void __stdcall __E__2__()
{
	__asm
	{
		jmp p[2 * 4];
	}
}

// GradientFill
extern "C" __declspec(naked) void __stdcall __E__3__()
{
	__asm
	{
		jmp p[3 * 4];
	}
}

// TransparentBlt
extern "C" __declspec(naked) void __stdcall __E__4__()
{
	__asm
	{
		jmp p[4 * 4];
	}
}