#include "Memory.h"
#include "Offsets.h"
#include <iostream>

void spoofSpectate(bool toggle) 
{
	if (toggle) 
	{
		WPM(ADDRESS_SPECTATEMANAGER, { OFFSET_SPOOF_SPECTATE_ENABLE }, 1); //Spoof Spectate On
	}
	else
	{
		WPM(ADDRESS_SPECTATEMANAGER, { OFFSET_SPOOF_SPECTATE_ENABLE }, 0); //Spoof Spectate Off
	}
}

void esp(bool toggle)
{
	short max_entities = 0;
	short turn_on = 1;

	RPM(ADDRESS_GAMEMANAGER, { OFFSET_GAMEMANAGER_ENTITYCOUNT }, max_entities);
	//std::cout << "max entities: " << max_entities << "\n";

	for (unsigned int idx = 0; idx < max_entities; idx++)
	{
		for (unsigned int i = 0x12; i < 0x14; i++) //28
		{
			int test;
			RPM(ADDRESS_GAMEMANAGER, { OFFSET_GAMEMANAGER_ENTITYLIST, idx * OFFSET_GAMEMANAGER_ENTITY, OFFSET_ENTITY_ENTITYINFO, OFFSET_ENTITYINFO_MAINCOMPONENT, i * OFFSET_MAINCOMPONENT_CHILDCOMPONENT }, test);
			if (test == 0)
			{
				WPM(ADDRESS_GAMEMANAGER, { OFFSET_GAMEMANAGER_ENTITYLIST, idx * OFFSET_GAMEMANAGER_ENTITY, OFFSET_ENTITY_ENTITYINFO, OFFSET_ENTITYINFO_MAINCOMPONENT, i * OFFSET_MAINCOMPONENT_CHILDCOMPONENT, OFFSET_ESPCHAIN_WRITE2 }, turn_on);
			}
		}

	}
}

void noFlash(bool toggle)
{
	WPM(ADDRESS_GAMERENDERER, { OFFSET_GAMERENDERER_DEREF, OFFSET_GAMERENDERER_ENGINELINK, 0x28, 0x30, 0x30, 0x28, 0x40 }, 0); //No flash
}

void glow(bool toggle)
{
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x110 }, 139.0f);  //Red
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x114 }, 0.0f);    //Green
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x118 }, 139.0f);  //Blue
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x134 }, 0.0f);    //Start distance
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x138 }, 0.0f);    //Glow distance
	WPM(ADDRESS_GLOWMANAGER, { 0xb8, 0x13C }, 4.0f);    //Opacity
}