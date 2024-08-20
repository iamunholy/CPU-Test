#include <dxgi.h>
#include <d3d11.h>
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#include <iostream>
#include <intrin.h>
#include <windows.h>
std::string getGPUInfo() {
    IDXGIFactory* pFactory = nullptr;
    HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory);

    if (FAILED(hr)) {
        return "Failed to create DXGIFactory.";
    }

    IDXGIAdapter* pAdapter = nullptr;
    pFactory->EnumAdapters(0, &pAdapter);

    DXGI_ADAPTER_DESC adapterDesc;
    pAdapter->GetDesc(&adapterDesc);

    std::wstring ws(adapterDesc.Description);
    std::string gpuName(ws.begin(), ws.end());

    pAdapter->Release();
    pFactory->Release();

    return gpuName;
}

double getGPUMemory() {
    IDXGIFactory* pFactory = nullptr;
    HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory);

    if (FAILED(hr)) {
        return 0;
    }

    IDXGIAdapter* pAdapter = nullptr;
    pFactory->EnumAdapters(0, &pAdapter);

    DXGI_ADAPTER_DESC adapterDesc;
    pAdapter->GetDesc(&adapterDesc);

    double gpuMemoryGB = adapterDesc.DedicatedVideoMemory / (1024.0 * 1024.0 * 1024.0);

    pAdapter->Release();
    pFactory->Release();

    return gpuMemoryGB;
}

