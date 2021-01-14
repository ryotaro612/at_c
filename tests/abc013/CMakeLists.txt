# https://atcoder.jp/contests/abc013
add_executable(testabc013c c.cc)
target_link_libraries(testabc013c abc013c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc013c)