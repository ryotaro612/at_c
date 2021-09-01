# https://atcoder.jp/contests/abc023
add_executable(testabc023c c.cc)
target_link_libraries(testabc023c abc023c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc023c)