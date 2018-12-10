cmake_minimum_required(VERSION 3.7)
project(cpp_prog)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES greedy/activity_selection.cpp)
add_executable(cpp_prog ${SOURCE_FILES})