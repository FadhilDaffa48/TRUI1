#include "TimeConverter.h"
#include <iostream>

Time::Time() {
    multipliers["ns"]   = 1e-9;
    multipliers["ms"]   = 1e-3;
    multipliers["s"]    = 1.0;
    multipliers["min"]  = 60.0;
    multipliers["hour"] = 3600.0;
}

double Time::toBase(double value, std::string unit) {
    if (multipliers.count(unit)) {
        return value * multipliers[unit];
    }
    std::cerr << "Error: Unit not found\n";
    return 0.0;
}

double Time::fromBase(double baseValue, std::string targetUnit) {
    if (multipliers.count(targetUnit)) {
        return baseValue / multipliers[targetUnit];
    }
    std::cerr << "Error: Unit not found\n";
    return 0.0;
}
