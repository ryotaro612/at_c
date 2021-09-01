# https://atcoder.jp/contests/abc034
add_executable(testabc034c c.cc)
add_executable(testabc034d d.cc)
target_link_libraries(testabc034c abc034c gtest_main)
target_link_libraries(testabc034d abc034d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc034c)
gtest_discover_tests(testabc034d)