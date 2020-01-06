#ifndef FUNCTIONS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define FUNCTIONS_H

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

DWORD getPID(const char* ProcessName);
MODULEENTRY32 getModule(const char* moduleName, unsigned long ProcessID);

#endif