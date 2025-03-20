#ifndef EXECUTION_ENGINE_HPP
#define EXECUTION_ENGINE_HPP

#include <vector>
#include <boost/asio.hpp>
#include <mutex>
#include <queue>
#include <thread>
#include "Bytecode.hpp"

class ExecutionEngine {
public:
    ExecutionEngine();
    void executeBytecode(const std::vector<uint8_t>& bytecode);
    void parallelExecute(std::vector<uint8_t>& bytecode);

private:
    boost::asio::thread_pool threadPool;
    std::mutex queueMutex;
    std::queue<std::vector<uint8_t>> executionQueue;
};

#endif // EXECUTION_ENGINE_HPP
