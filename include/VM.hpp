#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include "AIOptimizer.hpp"
#include "SelfHealingAI.hpp"
#include "PredictiveExecutionAI.hpp"
#include "QuantumProcessor.hpp"
#include "BlockchainSecurity.hpp"
#include "GPUExecutor.hpp"
#include "AIScaler.hpp"
#include "EdgeComputing.hpp"  
#include "CloudExecution.hpp"  
#include "AutonomousOptimizer.hpp"
#include "AIAnomalyDetector.hpp"  

class VM {
public:
    VM();
    void loadBytecode(const std::vector<uint8_t>& bytecode);
    void execute();

private:
    std::vector<uint8_t> bytecode;
    std::unordered_map<std::string, int> registers;
    AIOptimizer optimizer;
    SelfHealingAI selfHealer;
    PredictiveExecutionAI predictor;
    QuantumProcessor quantumProcessor;
    BlockchainSecurity blockchainSecurity;
    GPUExecutor gpuExecutor;
    AIScaler aiScaler;
    EdgeComputing edgeExecutor;  
    CloudExecution cloudExecutor;  
    AutonomousOptimizer autoOptimizer;
    AIAnomalyDetector anomalyDetector;  

    void executeInstruction(uint8_t opcode);
};
