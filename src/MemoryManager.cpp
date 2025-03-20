#include "MemoryManager.hpp"

MemoryManager::MemoryManager(size_t size) : memoryPool(size), currentIndex(0) {}

uint8_t* MemoryManager::allocate(size_t size) {
    if (currentIndex + size > memoryPool.size()) {
        std::cerr << "Error: Out of memory!" << std::endl;
        return nullptr;
    }
    uint8_t* ptr = &memoryPool[currentIndex];
    currentIndex += size;
    return ptr;
}

void MemoryManager::deallocate(uint8_t* ptr) {
    // No real deallocation, using a simple stack-based allocator
}

void MemoryManager::reset() {
    currentIndex = 0;
}
