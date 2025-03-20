#pragma once
#include <vector>
#include <complex>
#include <iostream>

class QuantumProcessor {
public:
    QuantumProcessor();
    void applyHadamardGate(std::vector<std::complex<double>>& qubits);
    void applyCNOTGate(std::vector<std::complex<double>>& qubits);
    void measureQubitState(const std::vector<std::complex<double>>& qubits);
};
