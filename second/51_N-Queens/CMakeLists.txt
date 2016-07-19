cmake_minimum_required(VERSION 3.3)
project(51_N_Queens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(51_N_Queens ${SOURCE_FILES})