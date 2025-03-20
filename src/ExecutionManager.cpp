#include "ExecutionManager.hpp"
#include <iostream>
#include <random>
#include <thread>
#include <algorithm>
#include <numeric>

ExecutionManager::ExecutionManager() {
    availableThreads = std::thread::hardware_concurrency();  // Get available CPU cores
}

int ExecutionManager::determineOptimalThreads(const std::vector<uint8_t>& bytecode) {
    int complexity = std::accumulate(bytecode.begin(), bytecode.end(), 0);
    int optimalThreads = std::min(availableThreads, complexity / 100); // Scale based on complexity
    return std::max(optimalThreads, 1);  // Ensure at least one thread is used
}

void ExecutionManager::distributeExecution(const std::vector<uint8_t>& bytecode) {
    int threadCount = determineOptimalThreads(bytecode);
    
    std::cout << "⚡ AI: Executing with " << threadCount << " threads for optimal performance!" << std::endl;

    // Simulated multi-threaded execution
    std::vector<std::thread> workers;
    int chunkSize = bytecode.size() / threadCount;
    
    for (int i = 0; i < threadCount; ++i) {
        workers.emplace_back([=]() {
            std::cout << "Thread " << i << " executing chunk..." << std::endl;
        });
    }

    for (auto& worker : workers) {
        worker.join();
    }
}
