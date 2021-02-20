# https://atcoder.jp/contests/abc030
add_executable(testabc030c c.cc)
add_executable(testabc030d d.cc)
target_link_libraries(testabc030c abc030c gtest_main)
target_link_libraries(testabc030d abc030d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc030c)
gtest_discover_tests(testabc030d)