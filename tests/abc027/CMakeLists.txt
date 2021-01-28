# https://atcoder.jp/contests/abc027
add_executable(testabc027c c.cc)
target_link_libraries(testabc027c abc027c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc027c)