#include "QuantumProcessor.hpp"
#include <cmath>
#include <random>

QuantumProcessor::QuantumProcessor() {}

// Apply Hadamard Gate (Creates Superposition)
void QuantumProcessor::applyHadamardGate(std::vector<std::complex<double>>& qubits) {
    std::complex<double> h_factor(1.0 / std::sqrt(2), 0);
    for (auto& q : qubits) {
        q *= h_factor;
    }
    std::cout << "Quantum: Applied Hadamard Gate (Superposition)\n";
}

// Apply CNOT Gate (Entanglement Simulation)
void QuantumProcessor::applyCNOTGate(std::vector<std::complex<double>>& qubits) {
    if (qubits.size() < 2) {
        std::cerr << "Quantum: Not enough qubits for CNOT\n";
        return;
    }
    qubits[1] = qubits[0];  // Simulating entanglement
    std::cout << "Quantum: Applied CNOT Gate (Entanglement)\n";
}

// Measure Qubit (Collapses to 0 or 1)
void QuantumProcessor::measureQubitState(const std::vector<std::complex<double>>& qubits) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.5);  // Simulating a random quantum collapse

    for (const auto& q : qubits) {
        std::cout << "Qubit collapsed to: " << (d(gen) ? "1" : "0") << "\n";
    }
}
