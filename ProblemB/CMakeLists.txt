cmake_minimum_required(VERSION 3.3)
project(ProblemB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(ProblemB ${SOURCE_FILES})