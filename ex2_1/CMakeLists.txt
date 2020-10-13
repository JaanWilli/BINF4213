cmake_minimum_required(VERSION 3.17)
project(ex2_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ../ex1_2
)

add_executable(ex2_1 ../ex1_2/fraction.cpp main.cpp)