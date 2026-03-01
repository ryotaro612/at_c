cmake_minimum_required (VERSION 3.16.3)

project (at_c)
# https://codeforces.com/blog/entry/15547#comment-205104
set(CMAKE_CXX_FLAGS "--std=c++23 -O2 -Wall -Wextra -Wshadow -Wfloat-equal -fsanitize=address,undefined -fdiagnostics-color -ftrapv -fstack-protector-all -fno-omit-frame-pointer")
option(CMAKE_EXPORT_COMPILE_COMMANDS 1)
#set(CMAKE_CXX_COMPILER "g++-15")
set(CMAKE_CXX_COMPILER "g++")

enable_testing()
add_subdirectory(src)
