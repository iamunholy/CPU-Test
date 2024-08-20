#include <iostream>
#include <intrin.h>
#include <windows.h>

void printMemoryInfo() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);

    std::cout << "Total System Memory (RAM): " << statex.ullTotalPhys / (1024 * 1024 * 1024) << " GB" << std::endl;
    std::cout << "Available Memory (RAM): " << statex.ullAvailPhys / (1024 * 1024 * 1024) << " GB" << std::endl;
}
