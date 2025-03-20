#ifndef CLOUD_EXECUTOR_HPP
#define CLOUD_EXECUTOR_HPP

#include <vector>
#include <string>
#include <unordered_map>

class CloudExecutor {
public:
    CloudExecutor();

    // Register a cloud instance
    void registerCloudInstance(const std::string& instanceID, const std::string& endpoint);

    // Offload task execution to the cloud
    bool offloadTask(const std::vector<uint8_t>& bytecode);

    // Fetch results from the cloud
    std::vector<uint8_t> fetchResults();

private:
    std::unordered_map<std::string, std::string> cloudInstances;  // Stores instanceID -> API Endpoint
};

#endif // CLOUD_EXECUTOR_HPP
