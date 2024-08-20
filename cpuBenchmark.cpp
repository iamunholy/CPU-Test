#include <iostream>
#include <intrin.h>
#include <windows.h>
#include <cmath>
#include <chrono>
void benchmarkCPU() {
    auto start = std::chrono::high_resolution_clock::now();

    volatile double sum = 0;
    for (int i = 0; i < 100000000; ++i) {
        sum += sin(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "CPU Benchmark (sin calculations): " << elapsed.count() << " seconds" << std::endl;
}
