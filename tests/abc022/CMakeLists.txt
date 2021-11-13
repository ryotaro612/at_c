# https://atcoder.jp/contests/abc022
add_executable(testabc022c c.cc)
target_link_libraries(testabc022c abc022c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc022c)