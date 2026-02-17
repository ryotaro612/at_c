cmake_minimum_required (VERSION 3.16.3)

project (at_c)
# https://codeforces.com/blog/entry/15547#comment-205104
set(CMAKE_CXX_FLAGS "-g3 -std=c++23 -Wextra -Wall -ftrapv")
option(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_COMPILER "g++-15")

enable_testing()
add_subdirectory(src)
