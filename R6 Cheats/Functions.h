//#ifndef FUNCTIONS_H    // To make sure you don't declare the function more than once by including the header multiple times.
//#define FUNCTIONS_H

#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

DWORD getPID(const char* ProcessName);
MODULEENTRY32 getModule(const char* moduleName, unsigned long ProcessID);
//uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);
uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
uintptr_t RPM(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets, int &val)
uintptr_t WPM(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets, int &val)

extern unsigned long long moduleBase;
extern HANDLE phandle;

//#endif