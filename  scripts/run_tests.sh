#!/bin/bash

# This script is used to run the unit tests for the Virtual Machine (VM) project

echo "Running unit tests..."

# Check if Google Test is available
if [ ! -f "build/test/vm_tests" ]; then
    echo "Unit test binary not found. Please build the project first."
    exit 1
fi

# Run the unit tests
./build/test/vm_tests

# Capture the result of the test run
result=$?

# Check if tests passed or failed
if [ $result -eq 0 ]; then
    echo "All tests passed!"
else
    echo "Some tests failed. Please check the output for more details."
    exit 1
fi
