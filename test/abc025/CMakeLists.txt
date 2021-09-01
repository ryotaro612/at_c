# https://atcoder.jp/contests/abc025
add_executable(testabc025c c.cc)
add_executable(testabc025d d.cc)
target_link_libraries(testabc025c abc025c gtest_main)
target_link_libraries(testabc025d abc025d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc025c)
gtest_discover_tests(testabc025d)