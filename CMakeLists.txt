cmake_minimum_required(VERSION 3.7)
project(cpp_prog)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES geometry/find_line_intersect.cpp geometry/convex_hull.cpp)
add_executable(cpp_prog ${SOURCE_FILES})