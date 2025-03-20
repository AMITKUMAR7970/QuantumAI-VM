#ifndef VM_H
#define VM_H

#include <iostream>
#include <vector>
#include "EdgeNodeManager.h"
#include "CloudManager.h"

class VM {
public:
    VM();
    void executeBytecode(const std::vector<uint8_t>& bytecode);
    void distributeExecution(const std::vector<uint8_t>& bytecode);
    void offloadToCloud(const std::vector<uint8_t>& bytecode);

private:
    EdgeNodeManager edgeManager;
    CloudManager cloudManager;
};

#endif // VM_H
