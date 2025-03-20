#ifndef EDGE_NODE_MANAGER_H
#define EDGE_NODE_MANAGER_H

#include <vector>
#include <string>

class EdgeNodeManager {
public:
    EdgeNodeManager();
    bool hasAvailableNodes();
    void distributeTask(const std::vector<uint8_t>& bytecode);

private:
    std::vector<std::string> edgeNodes;  // Stores available edge node IPs
};

#endif // EDGE_NODE_MANAGER_H

