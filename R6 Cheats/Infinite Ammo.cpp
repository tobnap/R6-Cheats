#include "Infinite Ammo.h"

DWORD getPID(const char* ProcessName) {
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);


	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!strcmp(processInfo.szExeFile, ProcessName))
	{
		CloseHandle(processesSnapshot);
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!strcmp(processInfo.szExeFile, ProcessName))
		{
			CloseHandle(processesSnapshot);
		}
	}
	CloseHandle(processesSnapshot);
	return processInfo.th32ProcessID;
}

MODULEENTRY32 getModule(const char* moduleName, unsigned long ProcessID)
{
	MODULEENTRY32 modEntry = { 0 };

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, ProcessID);

	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 curr = { 0 };

		curr.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &curr))
		{
			do
			{
				if (!strcmp(curr.szModule, moduleName))
				{
					modEntry = curr;
					break;
				}
			} while (Module32Next(hSnapshot, &curr));
		}
		CloseHandle(hSnapshot);
	}
	return modEntry;
}

void ammo()
{
	unsigned long long pid = getPID("RainbowSix.exe");
	MODULEENTRY32 module = getModule("RainbowSix.exe", pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	unsigned long long result;
	int ammo = 999999999;
	ReadProcessMemory(phandle, (void*)((unsigned long long)module.modBaseAddr + 0x02A141C0), &result, sizeof(result), 0);
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x98), &result, sizeof(result), 0);
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x18), &result, sizeof(result), 0);
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x2A0), &result, sizeof(result), 0);
	ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x30), &result, sizeof(result), 0);
	//ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x1F8), &result, sizeof(result), 0);
	WriteProcessMemory(phandle, (void*)((unsigned long long)result + 0x1F8), &ammo, sizeof(ammo), 0);
	//std::cout << "Your ammo value is " << result << std::endl;
}