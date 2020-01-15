#include "Functions.h"
#include <iostream>

void noRecoil()
{
	int val = 0;
	uintptr_t recoilAddr = FindDMAAddy(phandle, moduleBase + 0x05F7A630, { 0x0, 0x28, 0x0, 0xC8, 0x208, 0x50 });
	WriteProcessMemory(phandle, (BYTE*)recoilAddr, &val, sizeof(val), 0);
}