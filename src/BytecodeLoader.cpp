#include "BytecodeLoader.hpp"
#include <fstream>
#include <iostream>

std::vector<uint8_t> BytecodeLoader::loadBytecode(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return {};
    }

    return std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
}
