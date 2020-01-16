#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

DWORD GetPID(const char* ProcessName);
MODULEENTRY32 GetModule(const char* moduleName, unsigned long ProcessID);

//uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
//uintptr_t RPM(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets, int &val);
//uintptr_t WPM(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets, int &val);
//template <typename T> T WPM(uintptr_t ptr, std::vector<unsigned int> offsets, T &val);
//template <typename T> T RPM(uintptr_t ptr, std::vector<unsigned int> offsets, T &val);