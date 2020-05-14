cmake_minimum_required(VERSION 3.13)  # CMake version check
project(DCT2)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES src/main.cpp)
set(SOURCE_FILES src/DCT2/DCT2.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(DCT2 ${SOURCE_FILES})