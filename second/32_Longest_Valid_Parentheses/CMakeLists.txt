cmake_minimum_required(VERSION 3.5)
project(32_Longest_Valid_Parentheses)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(32_Longest_Valid_Parentheses ${SOURCE_FILES})