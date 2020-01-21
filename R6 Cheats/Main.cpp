#include "Main.h"
#include "Memory.h"
#include "Offsets.h"

int main() {
	while (true)
	{
		int isInGame;
		RPM(ADDRESS_ROUNDMANAGER, { 0x2E8 }, isInGame); //Is in game
		//std::cout << "in game: " << isInGame << "\n";
		if (isInGame == 1)
		{
			spoofSpectate(true);
		}
		else if (isInGame == 2)
		{
			//aimbot();
			esp(true);
			noFlash(true);
			glow(true);
			noClip(VK_NUMPAD1);
			infiniteAmmo(999999999);
			damageMultiplier(50);
			weaponFov(1.2);
			playerFov(2);
		}
		else if (isInGame == 3)
		{
			//aimbot();
			spoofSpectate(false);
			esp(true);
			noFlash(true);
			glow(true);
			noClip(VK_NUMPAD1);
			infiniteAmmo(true);
			damageMultiplier(50);
			weaponFov(1.2);
			playerFov(2);
		}
		else if (isInGame == 4)
		{
			esp(false);
		}
		else if (isInGame == 5)
		{

		}
		else
		{
			std::cout << "Please launch RainbowSix.exe" << "\n";
			std::cout << "If you are getting this message with the game open please update the offsets" << "\n";
			system("pause");
		}
	}
}