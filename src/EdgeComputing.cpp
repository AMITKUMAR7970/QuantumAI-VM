#include "EdgeComputing.hpp"

EdgeComputing::EdgeComputing() {}

void EdgeComputing::distributeWorkload(const std::vector<uint8_t>& bytecode) {
    std::cout << "🌍 Edge Computing: Distributing workload across edge nodes...\n";

    size_t chunkSize = bytecode.size() / 2;  
    std::vector<uint8_t> chunk1(bytecode.begin(), bytecode.begin() + chunkSize);
    std::vector<uint8_t> chunk2(bytecode.begin() + chunkSize, bytecode.end());

    std::thread node1(&EdgeComputing::executeOnEdgeNode, this, chunk1);
    std::thread node2(&EdgeComputing::executeOnEdgeNode, this, chunk2);

    node1.join();
    node2.join();
}

void EdgeComputing::executeOnEdgeNode(const std::vector<uint8_t>& chunk) {
    std::cout << "⚡ Executing " << chunk.size() << " instructions on Edge Node...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  
    std::cout << "✅ Edge Node Execution Complete!\n";
}
