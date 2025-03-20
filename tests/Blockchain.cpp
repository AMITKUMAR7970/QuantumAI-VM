#include "Blockchain.hpp"
#include <iostream>

void Blockchain::logExecution(const std::string& tx) {
    ledger.push_back(tx);
    std::cout << "Execution Logged: " << tx << std::endl;
}

void Blockchain::verifyExecution() {
    for (const auto& tx : ledger) {
        std::cout << "Verified Execution: " << tx << std::endl;
    }
}
