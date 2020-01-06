#include "Functions.h"

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