#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <openssl/sha.h>

class BlockchainSecurity {
public:
    BlockchainSecurity();
    void logTransaction(const std::string& instructionHash);
    bool verifyIntegrity(const std::vector<std::string>& executionLogs);
    
private:
    std::vector<std::string> blockchainLedger;
    std::string generateHash(const std::string& data);
};
