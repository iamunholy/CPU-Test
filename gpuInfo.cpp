#include <iostream>
#include <intrin.h>
#include <windows.h>

void printGPUInfo() {
    DISPLAY_DEVICE displayDevice;
    displayDevice.cb = sizeof(displayDevice);

    if (EnumDisplayDevices(NULL, 0, &displayDevice, 0)) {
        std::wcout << "GPU Name: " << displayDevice.DeviceString << std::endl;
    }
}
