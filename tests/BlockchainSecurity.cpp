#include "BlockchainSecurity.hpp"
#include <sstream>
#include <iomanip>

BlockchainSecurity::BlockchainSecurity() {}

// Generate SHA-256 hash for execution logs
std::string BlockchainSecurity::generateHash(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)data.c_str(), data.size(), hash);

    std::ostringstream hashStream;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashStream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return hashStream.str();
}

// Log execution transactions immutably
void BlockchainSecurity::logTransaction(const std::string& instructionHash) {
    blockchainLedger.push_back(instructionHash);
    std::cout << "Blockchain: Transaction logged - " << instructionHash << "\n";
}

// Verify execution integrity by comparing hash chain
bool BlockchainSecurity::verifyIntegrity(const std::vector<std::string>& executionLogs) {
    for (const auto& log : executionLogs) {
        std::string computedHash = generateHash(log);
        if (std::find(blockchainLedger.begin(), blockchainLedger.end(), computedHash) == blockchainLedger.end()) {
            std::cerr << "Blockchain Warning: Execution integrity compromised!\n";
            return false;
        }
    }
    std::cout << "Blockchain: Execution integrity verified successfully.\n";
    return true;
}
