cmake_minimum_required(VERSION 3.3)
project(HW1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Grid.h Grid.cpp _RAL.h N_array.cpp N_array.h)
add_executable(HW1 ${SOURCE_FILES})