# https://atcoder.jp/contests/abc104
add_executable(testabc104c c.cc)
target_link_libraries(testabc104c abc104c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc104c)
