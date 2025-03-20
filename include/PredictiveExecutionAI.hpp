#pragma once
#include <vector>

class PredictiveExecutionAI {
public:
    PredictiveExecutionAI();
    std::vector<uint8_t> predictNextInstructions(const std::vector<uint8_t>& bytecode);
};
