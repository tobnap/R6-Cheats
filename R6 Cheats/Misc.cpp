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
	WPM(0x52ae868, { 0x68, 0x0, 0x28, 0x30, 0x30, 0x28, 0x40 }, num = 0); //Spoof Spectate

	//Chams
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x110 }, num2 = 139);  //Red
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x114 }, num2 = 0);    //Green
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x118 }, num2 = 139);  //Blue
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x134 }, num2 = 0);    //Start distance
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x138 }, num2 = 0);    //Glow distance
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x13C }, num2 = 2);    //Opacity

	while (true) 
	{
		if (GetKeyState(VK_NUMPAD1) & 0x8000 && toggle==0)
		{
			WPM(0x52ae858, { 0xF8, 0x8, 0x560 }, num2 = 0.0f); //No clip on
			toggle = 1;
		}
		else if(toggle==1)
		{
			WPM(0x52ae858, { 0xF8, 0x8, 0x560 }, num2 = 0.0f); //No clip off
			toggle = 0;
		}
	}
}