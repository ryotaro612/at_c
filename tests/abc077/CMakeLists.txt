# https://atcoder.jp/contests/abc077
add_executable(testabc077c c.cc)
add_executable(testabc077d d.cc)
target_link_libraries(testabc077c abc077c gtest_main)
target_link_libraries(testabc077d abc077d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc077c)
gtest_discover_tests(testabc077d)