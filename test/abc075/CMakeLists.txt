# https://atcoder.jp/contests/abc075
add_executable(testabc075c c.cc)
add_executable(testabc075d d.cc)
target_link_libraries(testabc075c abc075c gtest_main)
target_link_libraries(testabc075d abc075d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc075c)
gtest_discover_tests(testabc075d)