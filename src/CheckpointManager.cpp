#include "CheckpointManager.hpp"
#include <fstream>
#include <iostream>

void CheckpointManager::saveCheckpoint(const std::vector<uint8_t>& memory, const std::string& filePath) {
    std::ofstream outFile(filePath, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error: Unable to create checkpoint file." << std::endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(memory.data()), memory.size());
    outFile.close();
    std::cout << "Checkpoint saved to " << filePath << std::endl;
}

std::vector<uint8_t> CheckpointManager::restoreCheckpoint(const std::string& filePath) {
    std::ifstream inFile(filePath, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error: Unable to load checkpoint file." << std::endl;
        return {};
    }

    std::vector<uint8_t> memory((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();
    std::cout << "Checkpoint restored from " << filePath << std::endl;
    return memory;
}

