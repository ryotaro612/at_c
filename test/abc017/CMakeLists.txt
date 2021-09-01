# https://atcoder.jp/contests/abc017
add_executable(testabc017c c.cc)
target_link_libraries(testabc017c abc017c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc017c)