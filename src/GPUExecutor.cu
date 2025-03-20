#include "GPUExecutor.hpp"
#include <cuda_runtime.h>

__global__ void vectorMultiply(float* d_data, int size) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < size) {
        d_data[idx] *= 2.0f;  // Example: Double each value
    }
}

GPUExecutor::GPUExecutor() {}

// Execute GPU-based computations
void GPUExecutor::executeOnGPU(std::vector<float>& data) {
    float* d_data;
    size_t size = data.size() * sizeof(float);

    cudaMalloc(&d_data, size);
    cudaMemcpy(d_data, data.data(), size, cudaMemcpyHostToDevice);

    int blockSize = 256;
    int numBlocks = (data.size() + blockSize - 1) / blockSize;
    vectorMultiply<<<numBlocks, blockSize>>>(d_data, data.size());

    cudaMemcpy(data.data(), d_data, size, cudaMemcpyDeviceToHost);
    cudaFree(d_data);

    std::cout << "GPU Execution: Data processed successfully.\n";
}
