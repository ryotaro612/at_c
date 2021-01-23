# https://atcoder.jp/contests/abc046
add_executable(testabc046c c.cc)
target_link_libraries(testabc046c abc046c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc046c)