cmake_minimum_required(VERSION 3.13)  # CMake version check
project(DCT2)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES src/transforms/DCT.cpp src/main.cpp)
# Add executable target with source files listed in SOURCE_FILES variable

find_library(FFTW3_LIB fftw3)
if(NOT FFTW3_LIB)
    set( FFTW3_DIR fftw-3.3.8)
    add_subdirectory(${FFTW3_DIR})
endif()

add_executable(DCT2 ${SOURCE_FILES})
target_link_libraries(DCT2 fftw3)