#include "cpuBenchmark.cpp"
#include "cpuinfo.cpp"
#include "gpuInfo.cpp"
#include "memoryBenchmark.cpp"
#include "ramInfo.cpp"
#include "performanceTable.cpp"
#include "gpuBenchmark.cpp"
#include "ioBenchmark.cpp"
int main() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    printCPUInfo();

    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);

    double clockSpeed = 3.7; // Example value; you'd normally get this from your benchmarking
    int cores = sysInfo.dwNumberOfProcessors;
    double totalRAM = statex.ullTotalPhys / (1024.0 * 1024.0 * 1024.0);

    // Get GPU Information
    std::string gpuName = getGPUInfo();
    double gpuMemory = getGPUMemory();

    std::cout << "GPU: " << gpuName << std::endl;
    std::cout << "GPU Memory: " << gpuMemory << " GiB" << std::endl;

    auto [writeSpeedMBps, readSpeedMBps] = benchmarkIO();
    double ioSpeedMBps = (writeSpeedMBps + readSpeedMBps) / 2.0; // Averaging read and write speeds
    // Classify Performance
    printPerformanceTable(clockSpeed, cores, totalRAM, ioSpeedMBps);

    PerformanceLevel gpuPerformance = classifyGPU(gpuMemory);
    std::cout << std::setw(15) << "GPU"
              << std::setw(15) << gpuMemory << " GiB"
              << std::setw(14) << (gpuPerformance == PerformanceLevel::HIGH ? "High" :
                                   gpuPerformance == PerformanceLevel::MEDIUM ? "Medium" : "Low")
              << std::endl;
        
    std::cout << "Press Enter to close...";
    std::cin.get();
    return 0;
}


