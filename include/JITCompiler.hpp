#ifndef JIT_COMPILER_HPP
#define JIT_COMPILER_HPP

#include <vector>
#include <unordered_map>
#include <functional>

class JITCompiler {
public:
    JITCompiler();
    void compile(const std::vector<uint8_t>& bytecode);
    void execute();

private:
    std::vector<std::function<void()>> compiledInstructions;
    std::unordered_map<uint8_t, std::function<void()>> instructionSet;
};

#endif // JIT_COMPILER_HPP
