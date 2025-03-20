#pragma once
#include <vector>

class SelfHealingAI {
public:
    SelfHealingAI();
    bool detectError(const std::vector<uint8_t>& bytecode);
    void recoverExecution(std::vector<uint8_t>& bytecode);
};
