#include "BlockchainManager.hpp"
#include <sstream>
#include <openssl/sha.h>

BlockchainManager::BlockchainManager() {
    // Genesis block
    Block genesis = {0, "0", "Genesis Block", generateHash({"0", "Genesis Block"})};
    chain.push_back(genesis);
}

void BlockchainManager::addExecutionRecord(const std::string& executionData) {
    std::lock_guard<std::mutex> lock(blockchainMutex);
    
    Block newBlock;
    newBlock.index = chain.size();
    newBlock.previousHash = getLatestBlock().hash;
    newBlock.data = executionData;
    newBlock.hash = generateHash(newBlock);
    
    chain.push_back(newBlock);

    std::cout << "[Blockchain] Execution logged in block " << newBlock.index << "\n";
}

bool BlockchainManager::verifyIntegrity() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        if (chain[i].previousHash != chain[i - 1].hash) {
            return false;
        }
    }
    return true;
}

std::string BlockchainManager::generateHash(const Block& block) const {
    std::stringstream ss;
    ss << block.index << block.previousHash << block.data;
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(ss.str().c_str()), ss.str().size(), hash);
    
    std::stringstream hexStream;
    for (unsigned char byte : hash) {
        hexStream << std::hex << (int)byte;
    }
    return hexStream.str();
}

Block BlockchainManager::getLatestBlock() const {
    return chain.back();
}
