#ifndef CLOUD_OFFLOADER_HPP
#define CLOUD_OFFLOADER_HPP

#include <vector>
#include <cstdint>
#include <string>

class CloudOffloader {
public:
    CloudOffloader();

    // AI-driven decision for offloading
    bool shouldOffload(const std::vector<uint8_t>& bytecode);

    // Upload bytecode to cloud for execution
    std::string uploadToCloud(const std::vector<uint8_t>& bytecode);

    // Execute bytecode remotely and fetch results
    std::vector<uint8_t> executeOnCloud(const std::string& cloudJobId);

    // AI-based anomaly detection in cloud execution
    bool detectCloudAnomalies(const std::vector<uint8_t>& executionResults);

private:
    std::string generateJobId();
};

#endif // CLOUD_OFFLOADER_HPP
