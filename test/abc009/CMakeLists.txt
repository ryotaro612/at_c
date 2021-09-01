# https://atcoder.jp/contests/abc009
add_executable(testabc009c c.cc)
target_link_libraries(testabc009c abc009c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc009c)