#include "AIScaler.hpp"

AIScaler::AIScaler() {}

// AI-based resource allocation logic
int AIScaler::allocateResources(int currentLoad) {
    int allocatedResources = 1;

    if (currentLoad > 70) {
        allocatedResources = 4;  // High workload, scale up
    } else if (currentLoad > 40) {
        allocatedResources = 2;  // Medium workload, moderate scaling
    } else {
        allocatedResources = 1;  // Low workload, minimal resources
    }

    std::cout << "AI-Based Execution Scaling: Allocating " << allocatedResources << " cores\n";
    return allocatedResources;
}
