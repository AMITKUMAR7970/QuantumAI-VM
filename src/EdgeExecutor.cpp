#include "EdgeExecutor.hpp"
#include <iostream>
#include <chrono>
#include <thread>

EdgeExecutor::EdgeExecutor() {}



EdgeExecutor::EdgeExecutor(int numNodes) : numNodes(numNodes), stopExecution(false) {
    for (int i = 0; i < numNodes; ++i) {
        executionNodes.emplace_back(&EdgeExecutor::executeTask, this);
    }
}

EdgeExecutor::~EdgeExecutor() {
    stopExecution = true;
    for (auto& node : executionNodes) {
        if (node.joinable()) {
            node.join();
        }
    }
}

void EdgeExecutor::distributeExecution(const std::vector<uint8_t>& bytecode) {
    std::lock_guard<std::mutex> lock(queueMutex);
    taskQueue.push(bytecode);
}

void EdgeExecutor::executeTask() {
    while (!stopExecution) {
        std::vector<uint8_t> task;
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            if (!taskQueue.empty()) {
                task = taskQueue.front();
                taskQueue.pop();
            }
        }
        
        if (!task.empty()) {
            std::cout << "[EdgeExecutor] Executing bytecode chunk on edge node...\n";
            // Simulated execution
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}


void EdgeExecutor::registerEdgeNode(const std::string& nodeID, const std::string& ip) {
    edgeNodes[nodeID] = ip;
    std::cout << "[EdgeExecutor] Registered Edge Node: " << nodeID << " at " << ip << std::endl;
}

bool EdgeExecutor::distributeTask(const std::vector<uint8_t>& bytecode) {
    if (edgeNodes.empty()) {
        std::cerr << "[EdgeExecutor] No available edge nodes!" << std::endl;
        return false;
    }

    // Simulating task distribution
    std::cout << "[EdgeExecutor] Distributing task to edge nodes...\n";
    for (const auto& [nodeID, ip] : edgeNodes) {
        std::cout << "[EdgeExecutor] Sending bytecode to " << nodeID << " at " << ip << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Simulate network latency
    }

    return true;
}

std::vector<uint8_t> EdgeExecutor::fetchResults() {
    std::cout << "[EdgeExecutor] Fetching execution results from edge nodes...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));  // Simulate processing time

    std::vector<uint8_t> results = {0x01, 0x02, 0x03};  // Simulated result data
    std::cout << "[EdgeExecutor] Received results successfully.\n";
    return results;
}
