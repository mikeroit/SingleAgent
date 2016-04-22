cmake_minimum_required(VERSION 3.5)
project(SAHW3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SlideTileDB.h SlideTileDB.cpp STP.h STP.cpp Myrvold_Ruskey.cpp Myrvold_Ruskey.h)
add_executable(SAHW3 ${SOURCE_FILES})