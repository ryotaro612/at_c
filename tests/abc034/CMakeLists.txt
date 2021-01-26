# https://atcoder.jp/contests/abc034
add_executable(testabc034c c.cc)
target_link_libraries(testabc034c abc034c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc034c)