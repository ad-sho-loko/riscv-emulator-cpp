cmake_minimum_required(VERSION 3.17)
project(riscv_emulator)

set(CMAKE_CXX_STANDARD 17)

# Include directories for this project
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories("${INCLUDE_DIR}")

# Emulator
# add_executable(riscv_emulator src/main.cpp src/memory.cpp)

# Test
add_library(riscv_emulator src/main.cpp src/memory.cpp)

add_subdirectory(third_party/googletest)
add_executable(test_all test/test_memory.cpp)
target_link_libraries(test_all gtest_main pthread riscv_emulator)
target_include_directories(test_all PUBLIC include third_party/gtest/googletest/include)
