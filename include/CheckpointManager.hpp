#ifndef CHECKPOINT_MANAGER_HPP
#define CHECKPOINT_MANAGER_HPP

#include <vector>
#include <string>

class CheckpointManager {
public:
    static void saveCheckpoint(const std::vector<uint8_t>& memory, const std::string& filePath);
    static std::vector<uint8_t> restoreCheckpoint(const std::string& filePath);
};

#endif // CHECKPOINT_MANAGER_HPP
