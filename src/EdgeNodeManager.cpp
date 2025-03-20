#include "EdgeNodeManager.h"
#include <iostream>

EdgeNodeManager::EdgeNodeManager() {
    // Simulating some available edge nodes
    edgeNodes.push_back("192.168.1.101");
    edgeNodes.push_back("192.168.1.102");
}

bool EdgeNodeManager::hasAvailableNodes() {
    return !edgeNodes.empty();
}

void EdgeNodeManager::distributeTask(const std::vector<uint8_t>& bytecode) {
    if (edgeNodes.empty()) {
        std::cerr << "No available edge nodes!\n";
        return;
    }

    // Simulate sending bytecode to an edge node
    std::string node = edgeNodes.front();
    std::cout << "Sending bytecode to edge node: " << node << "\n";

    // (Here, an actual network transmission method would be implemented)
}
