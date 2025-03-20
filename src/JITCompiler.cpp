#include "JITCompiler.hpp"
#include <iostream>

JITCompiler::JITCompiler() {
    instructionSet[0x01] = []() { std::cout << "Executing ADD\n"; };
    instructionSet[0x02] = []() { std::cout << "Executing SUB\n"; };
    instructionSet[0x03] = []() { std::cout << "Executing MUL\n"; };
    instructionSet[0x04] = []() { std::cout << "Executing DIV\n"; };
}

void JITCompiler::compile(const std::vector<uint8_t>& bytecode) {
    for (auto byte : bytecode) {
        if (instructionSet.find(byte) != instructionSet.end()) {
            compiledInstructions.push_back(instructionSet[byte]);
        }
    }
}

void JITCompiler::execute() {
    for (auto& instr : compiledInstructions) {
        instr();
    }
}
