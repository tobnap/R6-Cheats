#include "Functions.h"

unsigned long long pid = GetPID("RainbowSix.exe");
MODULEENTRY32 module = GetModule("RainbowSix.exe", pid);
unsigned long long moduleBase = ((unsigned long long)module.modBaseAddr);
HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
    return addr;
}

template <typename T>
T WPM(uintptr_t ptr, std::vector<unsigned int> offsets, T &val)
{
	uintptr_t addr = moduleBase + ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		ReadProcessMemory(phandle, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	WriteProcessMemory(phandle, (BYTE*)addr, &val, sizeof(val), 0);
	return addr;
}

template <typename T>
T RPM(uintptr_t ptr, std::vector<unsigned int> offsets, T& val)
{
	uintptr_t addr = moduleBase + ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		ReadProcessMemory(phandle, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	ReadProcessMemory(phandle, (BYTE*)addr, &val, sizeof(val), 0);
	return addr;
}

/*
uintptr_t RPM(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets, int &val)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
	ReadProcessMemory(hProc, (BYTE*)addr, &val, sizeof(val), 0);
    return addr;
}

uintptr_t WPM(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets, int &val)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
	WriteProcessMemory(hProc, (BYTE*)addr, &val, sizeof(val), 0);
    return addr;
}
*/