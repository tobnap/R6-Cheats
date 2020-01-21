#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

DWORD GetPID(const char* ProcessName);
MODULEENTRY32 GetModule(const char* moduleName, unsigned long ProcessID);

#endif // FUNCTIONS_H