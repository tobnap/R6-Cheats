#include "Infinite Ammo.h"

void ammo()
{
	unsigned long long pid = getPID("RainbowSix.exe");
	MODULEENTRY32 module = getModule("RainbowSix.exe", pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	unsigned long long result;
	int ammo = 999999999;
	ReadProcessMemory(phandle, (void*)((unsigned long long)module.modBaseAddr + 0x02A141C0), &result, sizeof(result), 0);
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x98), &result, sizeof(result), 0);
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x18), &result, sizeof(result), 0);
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x2A0), &result, sizeof(result), 0);
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x30), &result, sizeof(result), 0);
	//ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x1F8), &result, sizeof(result), 0);
	WriteProcessMemory(phandle, (void*)((unsigned long long)result + 0x1F8), &ammo, sizeof(ammo), 0);
	//std::cout << "Your ammo value is " << result << std::endl;
}