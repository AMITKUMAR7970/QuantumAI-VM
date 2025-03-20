#ifndef BLOCKCHAIN_MANAGER_HPP
#define BLOCKCHAIN_MANAGER_HPP

#include <vector>
#include <string>
#include <mutex>
#include <iostream>

struct Block {
    int index;
    std::string previousHash;
    std::string data;
    std::string hash;
};

class BlockchainManager {
public:
    BlockchainManager();

    // Add a new execution log to the blockchain
    void addExecutionRecord(const std::string& executionData);

    // Verify execution integrity
    bool verifyIntegrity() const;

private:
    std::vector<Block> chain;
    std::mutex blockchainMutex;

    // Generate hash for a block
    std::string generateHash(const Block& block) const;

    // Get the latest block in the chain
    Block getLatestBlock() const;
};

#endif // BLOCKCHAIN_MANAGER_HPP
