cmake_minimum_required(VERSION 3.3)
project(RPC_Tobby_and_Query)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(RPC_Tobby_and_Query ${SOURCE_FILES})