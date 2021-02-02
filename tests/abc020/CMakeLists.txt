# https://atcoder.jp/contests/abc020
add_executable(testabc020c c.cc)
add_executable(testabc020d d.cc)
target_link_libraries(testabc020c abc020c gtest_main)
target_link_libraries(testabc020d abc020d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc020c)
gtest_discover_tests(testabc020d)