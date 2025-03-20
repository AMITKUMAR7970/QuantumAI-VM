#ifndef CLOUD_MANAGER_H
#define CLOUD_MANAGER_H

#include <vector>
#include <string>

class CloudManager {
public:
    CloudManager();
    bool isCloudAvailable();
    void sendTaskToCloud(const std::vector<uint8_t>& bytecode);

private:
    std::vector<std::string> cloudProviders; // AWS, Azure, GCP
};

#endif // CLOUD_MANAGER_H
