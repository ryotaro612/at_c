# https://atcoder.jp/contests/abc35
add_executable(testabc035b b.cc)
add_executable(testabc035c c.cc)
add_executable(testabc035d d.cc)
target_link_libraries(testabc035b abc035b gtest_main)
target_link_libraries(testabc035c abc035c gtest_main)
target_link_libraries(testabc035d abc035d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc035b)
gtest_discover_tests(testabc035c)
gtest_discover_tests(testabc035d)