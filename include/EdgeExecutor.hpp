#ifndef EDGE_EXECUTOR_HPP
#define EDGE_EXECUTOR_HPP

#include <vector>
#include <string>
#include <thread>
#include <unordered_map>

class EdgeExecutor {
public:
    EdgeExecutor();

    // Register an edge node
    void registerEdgeNode(const std::string& nodeID, const std::string& ip);

    // Distribute tasks to edge nodes
    bool distributeTask(const std::vector<uint8_t>& bytecode);

    // Receive execution results from edge nodes
    std::vector<uint8_t> fetchResults();

private:
    std::unordered_map<std::string, std::string> edgeNodes;  // Stores nodeID -> IP
};

#endif // EDGE_EXECUTOR_HPP
