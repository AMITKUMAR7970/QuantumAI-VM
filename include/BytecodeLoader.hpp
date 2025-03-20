#ifndef BYTECODE_LOADER_HPP
#define BYTECODE_LOADER_HPP

#include <vector>
#include <string>

class BytecodeLoader {
public:
    static std::vector<uint8_t> loadBytecode(const std::string& filename);
};

#endif // BYTECODE_LOADER_HPP
