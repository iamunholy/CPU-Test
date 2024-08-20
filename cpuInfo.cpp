#include <iostream>
#include <intrin.h>
#include <windows.h>

void printCPUInfo() {
    int cpuInfo[4] = {0};
    __cpuid(cpuInfo, 0);
    char vendor[13];
    memcpy(vendor, &cpuInfo[1], 4);
    memcpy(vendor + 4, &cpuInfo[3], 4);
    memcpy(vendor + 8, &cpuInfo[2], 4);
    vendor[12] = '\0';

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    std::string architecture;
    switch (sysInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
            architecture = "x64 (AMD or Intel)";
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            architecture = "x86 (Intel)";
            break;
        case PROCESSOR_ARCHITECTURE_ARM:
            architecture = "ARM";
            break;
        case PROCESSOR_ARCHITECTURE_ARM64:
            architecture = "ARM64";
            break;
        default:
            architecture = "Unknown Architecture";
            break;
    }

    std::cout << "CPU architecture: " << vendor << " - " << architecture << std::endl;
    std::cout << "CPU logical cores: " << sysInfo.dwNumberOfProcessors << std::endl;
    std::cout << "CPU physical cores: " << sysInfo.dwNumberOfProcessors / 2 << std::endl;
}


