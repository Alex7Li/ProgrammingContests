cmake_minimum_required(VERSION 3.15)
project(ICPCTraining)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wuninitialized")

add_executable(csb CodersStrikeBack.cpp)

