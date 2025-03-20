#!/bin/bash

# This script is used to build the Virtual Machine (VM) project

echo "Starting the build process..."

# Check if CMake is installed
if ! command -v cmake &> /dev/null
then
    echo "CMake could not be found. Please install CMake."
    exit 1
fi

# Create a build directory if it doesn't exist
if [ ! -d "build" ]; then
  echo "Creating build directory..."
  mkdir build
fi

# Change into the build directory
cd build

# Run cmake to configure the project
echo "Running CMake..."
cmake ..

# Build the project using make
echo "Building the project..."
make

echo "Build complete. The VM executable is located in the 'build' directory."
