# https://atcoder.jp/contests/abc050
add_executable(testabc050c c.cc)
add_executable(testabc050d d.cc)
target_link_libraries(testabc050c abc050c gtest_main)
target_link_libraries(testabc050d abc050d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc050c)
gtest_discover_tests(testabc050d)