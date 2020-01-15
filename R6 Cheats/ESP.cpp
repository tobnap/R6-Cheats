#include "Functions.h"
#include <iostream>

void esp()
{
	int val = 1;
	uintptr_t espAddr = FindDMAAddy(phandle, moduleBase + 0x040BAD00, { 0x0, 0x190, 0x350, 0x20, 0x530 });
	WriteProcessMemory(phandle, (BYTE*)espAddr, &val, sizeof(val), 0);
}