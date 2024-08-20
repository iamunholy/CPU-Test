#include "performanceUtils.h"

std::string performanceLevelToString(PerformanceLevel level) {
    switch(level) {
        case PerformanceLevel::HIGH: return "High";
        case PerformanceLevel::MEDIUM: return "Medium";
        case PerformanceLevel::LOW: return "Low";
        default: return "Unknown";
    }
}
