#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

class EdgeComputing {
public:
    EdgeComputing();
    void distributeWorkload(const std::vector<uint8_t>& bytecode);

private:
    void executeOnEdgeNode(const std::vector<uint8_t>& chunk);
};
