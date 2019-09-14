cmake_minimum_required(VERSION 3.0.0)
project(MatMul VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_FLAGS "-fopenmp")

add_executable(MatMul main.cpp MatMul.hpp MatMul.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
