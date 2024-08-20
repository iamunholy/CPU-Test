#include <iostream>
#include <iomanip>  // for std::setw
#include "performanceUtils.h"

PerformanceLevel classifyCPU(double clockSpeed, int cores) {
    if (clockSpeed >= 3.5 && cores >= 8) {
        return PerformanceLevel::HIGH;
    } else if (clockSpeed >= 2.5 && cores >= 4) {
        return PerformanceLevel::MEDIUM;
    } else {
        return PerformanceLevel::LOW;
    }
}

PerformanceLevel classifyMemory(double totalRAM) {
    if (totalRAM >= 16) {
        return PerformanceLevel::HIGH;
    } else if (totalRAM >= 8) {
        return PerformanceLevel::MEDIUM;
    } else {
        return PerformanceLevel::LOW;
    }
}

PerformanceLevel classifyGPU(double gpuMemory) {
    if (gpuMemory >= 8.0) {
        return PerformanceLevel::HIGH;
    } else if (gpuMemory >= 4.0) {
        return PerformanceLevel::MEDIUM;
    } else {
        return PerformanceLevel::LOW;
    }
}

PerformanceLevel classifyIO(double ioSpeedMBps) {
    if (ioSpeedMBps >= 500) {
        return PerformanceLevel::HIGH;
    } else if (ioSpeedMBps >= 200) {
        return PerformanceLevel::MEDIUM;
    } else {
        return PerformanceLevel::LOW;
    }
}


void printPerformanceTable(double clockSpeed, int cores, double totalRAM, double ioSpeedMBps) {
    PerformanceLevel cpuPerformance = classifyCPU(clockSpeed, cores);
    PerformanceLevel memoryPerformance = classifyMemory(totalRAM);
    PerformanceLevel ioPerformance = classifyIO(ioSpeedMBps);
    
    std::cout << std::setw(15) << "Component"
              << std::setw(20) << "Specification"
              << std::setw(20) << "Performance" << std::endl;
    std::cout << std::setw(15) << "CPU"
              << std::setw(11) << clockSpeed << " GHz, " << cores << " cores"
              << std::setw(10) << (cpuPerformance == PerformanceLevel::HIGH ? "High" :
                                   cpuPerformance == PerformanceLevel::MEDIUM ? "Medium" : "Low")
              << std::endl;

    std::cout << std::setw(15) << "Memory"
              << std::setw(15) << totalRAM << " GiB"
              << std::setw(15) << (memoryPerformance == PerformanceLevel::HIGH ? "High" :
                                   memoryPerformance == PerformanceLevel::MEDIUM ? "Medium" : "Low")
              << std::endl;

    std::cout << std::setw(15) << "I/O" 
              << std::setw(15) << ioSpeedMBps << " MB/s" 
              << std::setw(14) << (ioPerformance == PerformanceLevel::HIGH ? "High" :
                                   ioPerformance == PerformanceLevel::MEDIUM ? "Medium" : "Low")
              << std::endl;
    
}
