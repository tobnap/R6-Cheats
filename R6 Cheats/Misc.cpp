#include "Functions.h"
#include "Offsets.h"
#include <iostream>

void misc()
{
	int num;
	float num2;
	int toggle = 0;

	WPM(0x05F7A630, { 0x0, 0x28, 0x0, 0xC8, 0xCC }, num = 999999999); //Infinite ammo
	WPM(0x52ae868, { 0x68, 0x0, 0x28, 0x30, 0x30, 0x28, 0x40 }, num = 0); //No flash
	while (true) 
	{
		if (GetKeyState(VK_NUMPAD1) & 0x8000)
		{
			WPM(0x52ae858, { 0xF8, 0x8, 0x560 }, num2 = 0.0f); //No clip on
		}
		else 
		{
			WPM(0x52ae858, { 0xF8, 0x8, 0x560 }, num2 = 0.0f); //No clip off
		}
	}
}