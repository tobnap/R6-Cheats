#include "Memory.h"
#include "Offsets.h"
#include <iostream>

/*
int numy;

uintptr_t outlineComp = RPM(ADDRESS_GAMEMANAGER, { 0x320, 0x968 }, numy);

void setOutline(bool update, bool visible)
{
	uintptr_t objectArray;
	uint32_t objectArraySize;
	objectArray = RPM(outlineComp, { 0x328 }, numy);
	RPM(outlineComp, { 0x330 }, objectArraySize);
	objectArraySize = 39392;
	std::cout << "objectArraySize: " << objectArraySize << "\n";
	for (unsigned long offset = 0x0; offset < objectArraySize * 0x90; offset += 0x90)
	{
		WPM(objectArray, { offset, 0x0 }, visible);
		WPM(objectArray, { offset, 0x2 }, update);
	}
}
*/

bool toggled = true;

void noClip(int button)
{
	//No Clip
	if (GetAsyncKeyState(button) & 0x8000 && toggled)
	{
		WPM(0x52ae858, { 0xF8, 0x8, 0x560 }, 0.0f); //No clip on
		toggled = !toggled;
		std::cout << "no clip on\n";
		Sleep(300);
	}
	if (GetAsyncKeyState(button) & 0x8000 && !toggled)
	{
		WPM(0x52ae858, { 0xF8, 0x8, 0x560 }, 0.0001788139343f); //No clip off
		toggled = !toggled;
		std::cout << "no clip off\n";
		Sleep(300);
	}
}

void infiniteAmmo(int ammo)
{
	WPM(ADDRESS_GAMEMANAGER, { OFFSET_GAMEMANAGER_ENTITYLIST, 0x0, 0x78, 0xC8, 0x1B0, 0x4C }, ammo); //Infinite ammo
}

void damageMultiplier(int multiply)
{
	WPM(ADDRESS_GAMEMANAGER, { 0x24E0, 0x138, 0x0, 0x40 }, multiply); //Damage Multiplier
}

void weaponFov(float fov)
{
	WPM(ADDRESS_FOVMANAGER, { 0x28, 0x0, 0x3C }, fov); //Weapon FOV
}

void playerFov(float fov)
{
	WPM(ADDRESS_FOVMANAGER, { 0x28, 0x0, 0x38 }, fov); //Player FOV
}