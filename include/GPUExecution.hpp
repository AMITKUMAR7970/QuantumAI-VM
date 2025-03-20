#ifndef GPU_EXECUTION_HPP
#define GPU_EXECUTION_HPP

#include <vector>
#include <cuda_runtime.h>

class GPUExecution {
public:
    GPUExecution();
    ~GPUExecution();
    
    void executeOnGPU(std::vector<uint8_t>& bytecode);
    void optimizeGPUExecution(std::vector<uint8_t>& bytecode);
    
private:
    void allocateMemoryOnGPU(std::vector<uint8_t>& bytecode);
    void copyToGPU(std::vector<uint8_t>& bytecode);
    void copyFromGPU(std::vector<uint8_t>& bytecode);
};

#endif // GPU_EXECUTION_HPP
