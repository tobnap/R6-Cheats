#include "Functions.h"

DWORD GetPID(const char* ProcessName) {
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

MODULEENTRY32 GetModule(const char* moduleName, unsigned long ProcessID)
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

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
    return addr;
}

uintptr_t RPM(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets, int &val)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
	int val = ReadProcessMemory(hProc, (BYTE*)addr, &val, sizeof(val), 0);
    return 0;
}

uintptr_t WPM(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets, int &val)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
	int val = WriteProcessMemory(hProc, (BYTE*)addr, &val, sizeof(val), 0);
    return 0;
}

unsigned long long pid = GetPID("RainbowSix.exe");
MODULEENTRY32 module = GetModule("RainbowSix.exe", pid);
unsigned long long moduleBase = ((unsigned long long)module.modBaseAddr);
HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);