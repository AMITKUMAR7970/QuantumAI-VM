#include "ExecutionEngine.hpp"
#include <iostream>

ExecutionEngine::ExecutionEngine() : threadPool(std::thread::hardware_concurrency()) {}

void ExecutionEngine::executeBytecode(const std::vector<uint8_t>& bytecode) {
    std::lock_guard<std::mutex> lock(queueMutex);
    executionQueue.push(bytecode);
    parallelExecute(executionQueue.front());
    executionQueue.pop();
}

void ExecutionEngine::parallelExecute(std::vector<uint8_t>& bytecode) {
    boost::asio::post(threadPool, [bytecode]() {
        std::cout << "Executing bytecode on separate thread..." << std::endl;
        for (auto instruction : bytecode) {
            std::cout << "Executing instruction: " << (int)instruction << std::endl;
        }
    });
}
