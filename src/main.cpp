#include "VM.hpp"
#include "BytecodeLoader.hpp"

int main() {
    VM vm;
    std::vector<uint8_t> bytecode = BytecodeLoader::loadBytecode("bytecode/program.bin");

    if (!bytecode.empty()) {
        vm.loadProgram(bytecode);
        vm.execute();
    }

    return 0;
}
