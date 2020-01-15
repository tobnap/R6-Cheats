#include "Functions.h"
#include <iostream>

void weaponFOV()
{
	int val = 1.2;
	uintptr_t weaponFOVAddr = FindDMAAddy(phandle, moduleBase + 0x05F7A630, { 0x0, 0x28, 0x0, 0xC8, 0x208, 0x50 });
	WriteProcessMemory(phandle, (BYTE*)weaponFOVAddr, &val, sizeof(val), 0);
}