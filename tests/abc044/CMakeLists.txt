# https://atcoder.jp/contests/abc044
add_executable(testabc044c c.cc)
target_link_libraries(testabc044c abc044c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc044c)