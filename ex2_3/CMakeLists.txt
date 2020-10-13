cmake_minimum_required(VERSION 3.17)
project(ex1_4)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ../ex2_1
        ../ex1_2
)

add_executable(ex2_3 main.cpp ../ex2_1/pvector.h ../ex1_2/fraction.h ../ex1_2/fraction.cpp)