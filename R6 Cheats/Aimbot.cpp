#include "Functions.h"
#include "Memory.h"
#include "Offsets.h"
#include "Vectors.h"
#include <iostream>

int test;
Vector3 test2;
float test3;

DWORD_PTR GetEntity(int i) {
	return RPM(ADDRESS_GAMEMANAGER, { OFFSET_GAMEMANAGER_ENTITYLIST, (unsigned int)i * OFFSET_GAMEMANAGER_ENTITY, 0x20 }, test);
}

Vector3 GetViewTranslation() {
	//View translation comes straight from the camera
	return RPM(ADDRESS_GAMERENDERER, { OFFSET_GAMERENDERER_DEREF, OFFSET_GAMERENDERER_ENGINELINK, OFFSET_ENGINELINK_ENGINE, OFFSET_ENGINE_CAMERA, OFFSET_CAMERA_VIEWTRANSLATION }, test2);
}

Vector3 GetViewRight() {
	//View right comes directly from the camera
	return RPM(ADDRESS_GAMERENDERER, { OFFSET_GAMERENDERER_DEREF, OFFSET_GAMERENDERER_ENGINELINK, OFFSET_ENGINELINK_ENGINE, OFFSET_ENGINE_CAMERA, OFFSET_CAMERA_VIEWRIGHT }, test2);
}

Vector3 GetViewUp() {
	//View up comes directly from the camera
	return RPM(ADDRESS_GAMERENDERER, { OFFSET_GAMERENDERER_DEREF, OFFSET_GAMERENDERER_ENGINELINK, OFFSET_ENGINELINK_ENGINE, OFFSET_ENGINE_CAMERA, OFFSET_CAMERA_VIEWUP }, test2);
}

Vector3 GetViewForward() {
	//View forward comes directly from the camera
	return RPM(ADDRESS_GAMERENDERER, { OFFSET_GAMERENDERER_DEREF, OFFSET_GAMERENDERER_ENGINELINK, OFFSET_ENGINELINK_ENGINE, OFFSET_ENGINE_CAMERA, OFFSET_CAMERA_VIEWFORWARD }, test2);
}

float GetFOVX() {
	//FOV comes directly from the camera
	return RPM(ADDRESS_GAMERENDERER, { OFFSET_GAMERENDERER_DEREF, OFFSET_GAMERENDERER_ENGINELINK, OFFSET_ENGINELINK_ENGINE, OFFSET_ENGINE_CAMERA, OFFSET_CAMERA_VIEWFOVX }, test3);
}

float GetFOVY() {
	//FOV comes directly from the camera
	return RPM(ADDRESS_GAMERENDERER, { OFFSET_GAMERENDERER_DEREF, OFFSET_GAMERENDERER_ENGINELINK, OFFSET_ENGINELINK_ENGINE, OFFSET_ENGINE_CAMERA, OFFSET_CAMERA_VIEWFOVY }, test3);
}

int displayWidth = GetSystemMetrics(SM_CXSCREEN);
int displayHeight = GetSystemMetrics(SM_CYSCREEN);

Vector3 WorldToScreen(Vector3 position) {
	Vector3 temp = position - GetViewTranslation();

	float x = temp.Dot(GetViewRight());
	float y = temp.Dot(GetViewUp());
	float z = temp.Dot(GetViewForward() * -1);

	return Vector3((displayWidth / 2) * (1 + x / GetFOVX() / z), (displayHeight / 2) * (1 - y / GetFOVY() / z), z);
}

void aimbot()
{
	for (int i = 1/*0 is local player in situations and lw htunt, set to 0 if playing mp*/; i < 9; i++) {
		int fff;

		RPM(GetEntity(i), { OFFSET_ENTITY_HEAD }, fff);
		std::cout << "fff: " << test << "\n";
	}
	//int pp;

	//RPM(ADDRESS_GAMEMANAGER, { OFFSET_GAMEMANAGER_ENTITYLIST + 2 * OFFSET_GAMEMANAGER_ENTITY + 0x20 + OFFSET_ENTITY_ENTITYINFO + OFFSET_ENTITYINFO_MAINCOMPONENT + OFFSET_MAINCOMPONENT_CHILDCOMPONENT + OFFSET_CHILDCOMPONENT_HEALTH_FLOAT }, pp);
	//RPM(ADDRESS_GAMEMANAGER, { OFFSET_GAMEMANAGER_ENTITYLIST + OFFSET_GAMEMANAGER_ENTITY + 0x20 + OFFSET_ENTITY_HEAD }, pp);
	//std::cout << "Pos: " << pp << "\n";
}