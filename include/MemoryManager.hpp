#ifndef MEMORY_MANAGER_HPP
#define MEMORY_MANAGER_HPP

#include <vector>
#include <iostream>

class MemoryManager {
public:
    MemoryManager(size_t size);
    uint8_t* allocate(size_t size);
    void deallocate(uint8_t* ptr);
    void reset();

private:
    std::vector<uint8_t> memoryPool;
    size_t currentIndex;
};

#endif // MEMORY_MANAGER_HPP
