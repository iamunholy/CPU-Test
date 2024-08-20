#include <iostream>
#include <fstream>
#include <chrono>

std::pair<double, double> benchmarkIO() {
    const size_t fileSize = 100 * 1024 * 1024; // 100 MB
    char* buffer = new char[fileSize];

    // Write Benchmark
    auto startWrite = std::chrono::high_resolution_clock::now();
    std::ofstream outFile("testfile.bin", std::ios::binary);
    outFile.write(buffer, fileSize);
    outFile.close();
    auto endWrite = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> writeDuration = endWrite - startWrite;
    double writeSpeedMBps = (fileSize / (1024.0 * 1024.0)) / writeDuration.count();

    // Read Benchmark
    auto startRead = std::chrono::high_resolution_clock::now();
    std::ifstream inFile("testfile.bin", std::ios::binary);
    inFile.read(buffer, fileSize);
    inFile.close();
    auto endRead = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> readDuration = endRead - startRead;
    double readSpeedMBps = (fileSize / (1024.0 * 1024.0)) / readDuration.count();

    std::cout << "I/O Benchmark - Write Speed: " << writeSpeedMBps << " MB/s" << std::endl;
    std::cout << "I/O Benchmark - Read Speed: " << readSpeedMBps << " MB/s" << std::endl;

    delete[] buffer;

    return {writeSpeedMBps, readSpeedMBps};
}
