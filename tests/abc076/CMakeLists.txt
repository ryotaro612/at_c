# https://atcoder.jp/contests/abc076
add_executable(testabc076c c.cc)
add_executable(testabc076d d.cc)
target_link_libraries(testabc076c abc076c gtest_main)
target_link_libraries(testabc076d abc076d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc076c)
gtest_discover_tests(testabc076d)