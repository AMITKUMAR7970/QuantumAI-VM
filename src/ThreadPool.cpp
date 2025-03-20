#include "ThreadPool.hpp"

ThreadPool::ThreadPool(size_t numThreads) 
    : workGuard(boost::asio::make_work_guard(ioService)) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back([this] { ioService.run(); });
    }
}

ThreadPool::~ThreadPool() {
    ioService.stop();
    for (auto& worker : workers) {
        if (worker.joinable()) worker.join();
    }
}

template <typename F>
void ThreadPool::enqueue(F task) {
    ioService.post(task);
}
