cmake_minimum_required(VERSION 3.10.2)
project(standard_library)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp catch.hpp Container/Permutation_Arrays.cpp)
