#include "Functions.h"
#include <iostream>

void infiniteAmmo()
{
	int val = 999999999;
	uintptr_t ammoAddr = FindDMAAddy(phandle, moduleBase + 0x05F7A630, { 0x0, 0x28, 0x0, 0xC8, 0xCC });
	WriteProcessMemory(phandle, (BYTE*)ammoAddr, &val, sizeof(val), 0);
}