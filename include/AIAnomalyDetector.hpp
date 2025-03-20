#pragma once
#include <vector>
#include <iostream>

class AIAnomalyDetector {
public:
    AIAnomalyDetector();
    bool detectAnomaly(const std::vector<uint8_t>& bytecode);
};
