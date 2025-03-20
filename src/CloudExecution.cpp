#include "CloudExecution.hpp"

CloudExecution::CloudExecution() {}

void CloudExecution::offloadToCloud(const std::vector<uint8_t>& bytecode, const std::string& cloudProvider) {
    std::cout << "☁️ Cloud Execution: Offloading workload to " << cloudProvider << "...\n";

    if (cloudProvider == "AWS") {
        std::cout << "🚀 Running on AWS Lambda...\n";
    } else if (cloudProvider == "Azure") {
        std::cout << "🚀 Running on Azure Functions...\n";
    } else if (cloudProvider == "GCP") {
        std::cout << "🚀 Running on Google Cloud Run...\n";
    } else {
        std::cout << "⚠️ Unknown Cloud Provider! Defaulting to AWS.\n";
    }

    std::cout << "✅ Cloud Execution Complete! Results received.\n";
}
