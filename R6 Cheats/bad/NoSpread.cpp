#include "Functions.h"
#include <iostream>

void noSpread()
{
	int val = 0;
	uintptr_t spreadAddr = FindDMAAddy(phandle, moduleBase + 0x05F7A630, { 0x0, 0x28, 0x0, 0xC8, 0x208, 0x50 });
	WriteProcessMemory(phandle, (BYTE*)spreadAddr, &val, sizeof(val), 0);
}