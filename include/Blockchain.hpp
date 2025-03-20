#pragma once
#include <vector>
#include <string>

class Blockchain {
public:
    void logExecution(const std::string& tx);
    void verifyExecution();
    
private:
    std::vector<std::string> ledger;
};
