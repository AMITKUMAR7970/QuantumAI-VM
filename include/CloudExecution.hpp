#pragma once
#include <vector>
#include <string>
#include <iostream>

class CloudExecution {
public:
    CloudExecution();
    void offloadToCloud(const std::vector<uint8_t>& bytecode, const std::string& cloudProvider);
};
