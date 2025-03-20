#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <boost/asio.hpp>
#include <vector>
#include <thread>

class ThreadPool {
public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();

    template <typename F>
    void enqueue(F task);

private:
    boost::asio::io_service ioService;
    boost::asio::executor_work_guard<boost::asio::io_service::work> workGuard;
    std::vector<std::thread> workers;
};

#endif // THREAD_POOL_HPP
