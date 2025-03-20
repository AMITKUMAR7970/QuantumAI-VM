#include "AutoCodeOptimizer.hpp"
#include <iostream>
#include <algorithm>

AutoCodeOptimizer::AutoCodeOptimizer() {}

void AutoCodeOptimizer::optimizeBytecode(std::vector<uint8_t>& bytecode) {
    uint8_t frequentInstr = findMostFrequentInstruction();

    // Example: Move frequently executed instructions to the start for better caching
    std::stable_partition(bytecode.begin(), bytecode.end(), 
        [frequentInstr](uint8_t instr) { return instr == frequentInstr; });

    std::cout << "AI Optimization: Bytecode reordered for efficiency." << std::endl;
}

void AutoCodeOptimizer::analyzeExecutionPatterns(const std::vector<uint8_t>& executionData) {
    for (auto byte : executionData) {
        instructionUsage[byte]++;
    }
}

uint8_t AutoCodeOptimizer::findMostFrequentInstruction() {
    uint8_t mostFrequent = 0;
    int maxCount = 0;

    for (const auto& [instr, count] : instructionUsage) {
        if (count > maxCount) {
            mostFrequent = instr;
            maxCount = count;
        }
    }

    return mostFrequent;
}
