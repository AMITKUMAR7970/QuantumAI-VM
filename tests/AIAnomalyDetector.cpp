#include "AIAnomalyDetector.hpp"
#include <cmath>

AIAnomalyDetector::AIAnomalyDetector() {}

bool AIAnomalyDetector::detectAnomaly(const std::vector<uint8_t>& bytecode) {
    if (bytecode.empty()) return false;

    double sum = 0.0, mean, variance = 0.0, stddev;
    for (uint8_t opcode : bytecode) {
        sum += opcode;
    }
    
    mean = sum / bytecode.size();

    for (uint8_t opcode : bytecode) {
        variance += pow(opcode - mean, 2);
    }

    stddev = sqrt(variance / bytecode.size());

    std::cout << "📊 AI-Based Anomaly Detection: Mean = " << mean << ", StdDev = " << stddev << "\n";

    if (stddev > 30.0) {  
        std::cout << "⚠️ Anomaly Detected in Execution! Possible malicious or corrupted bytecode.\n";
        return true;
    }

    return false;
}
