cmake_minimum_required(VERSION 3.7)
project(cpp_prog)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES arrays/binary_search/median_of_two_sorted_array.cpp)
add_executable(cpp_prog ${SOURCE_FILES})