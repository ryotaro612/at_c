# https://atcoder.jp/contests/abc092
add_executable(testabc092c c.cc)
target_link_libraries(testabc092c abc092c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc092c)