# Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(VirtualMachine VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the required Boost libraries
find_package(Boost REQUIRED)

# Specify CUDA for GPU execution
find_package(CUDA REQUIRED)

# Specify the location of the source files
set(SOURCE_FILES
    src/main.cpp
    src/VM.cpp
    src/BytecodeInterpreter.cpp
    src/ExecutionEngine.cpp
    src/AIOptimizer.cpp
    # Add other source files here
)

# Specify the location of the header files
set(HEADER_FILES
    include/VM.hpp
    include/BytecodeInterpreter.hpp
    include/ExecutionEngine.hpp
    include/AIOptimizer.hpp
    # Add other header files here
)

# Add executable for the project
add_executable(VirtualMachine ${SOURCE_FILES} ${HEADER_FILES})

# Link against Boost and CUDA
target_link_libraries(VirtualMachine Boost::Boost CUDA::CUDA)

# Include directories for header files
target_include_directories(VirtualMachine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
        ${CUDA_INCLUDE_DIRS}
)

# Add flags for CUDA
if(CUDA_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -G -g")
    target_compile_options(VirtualMachine PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-D__CUDA_NO_BROKEN_WARNINGS__>)
endif()

# Google Test integration (if you are using Google Test for unit testing)
enable_testing()
find_package(GTest REQUIRED)

# Add unit tests
add_executable(tests
    test/test_vm.cpp
    test/test_bytecode_interpreter.cpp
    # Add other test files here
)

# Link test executable with Google Test and the VirtualMachine executable
target_link_libraries(tests GTest::GTest GTest::Main VirtualMachine)

# Add a custom target for running tests
add_test(NAME VMTests COMMAND tests)

# Set output directories for the build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Optional: Set compiler flags for optimization
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
endif()

# Optionally, you can set CUDA-specific flags if needed
if(CUDA_FOUND)
    target_compile_options(VirtualMachine PRIVATE -O3)
    target_link_options(VirtualMachine PRIVATE ${CUDA_LIBRARIES})
endif()

