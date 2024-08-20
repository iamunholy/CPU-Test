#ifndef PERFORMANCE_UTILS_H
#define PERFORMANCE_UTILS_H

#include <string>

enum class PerformanceLevel {
    HIGH,
    MEDIUM,
    LOW
};

std::string performanceLevelToString(PerformanceLevel level);

#endif
