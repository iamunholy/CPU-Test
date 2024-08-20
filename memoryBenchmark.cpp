#include <iostream>
#include <intrin.h>
#include <windows.h>
#include <cmath>
#include <chrono>

void benchmarkMemory() {
    const int SIZE = 10000000;
    int* arr = new int[SIZE];
    
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Memory Benchmark: " << elapsed.count() << " seconds" << std::endl;

    delete[] arr;
}
