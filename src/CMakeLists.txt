cmake_minimum_required(VERSION 3.17)
project(ISP_DZ1)

set(CMAKE_CXX_STANDARD 20)

add_executable(executable main.cpp equations.cpp equations.h tests.cpp tests.h)

target_compile_options(executable PRIVATE -Wall -Wextra -Wfloat-equal)