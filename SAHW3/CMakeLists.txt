cmake_minimum_required(VERSION 3.5)
project(SAHW3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp m_dist.cpp m_dist.h Myrvold_Ruskey.cpp Myrvold_Ruskey.h SlideTile15.h SlideTile15.cpp BFS.cpp BFS.h)
add_executable(SAHW3 ${SOURCE_FILES})