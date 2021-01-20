# https://atcoder.jp/contests/abc074
add_executable(testabc074c c.cc)
add_executable(testabc074d d.cc)
target_link_libraries(testabc074c abc074c gtest_main)
target_link_libraries(testabc074d abc074d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc074c)
gtest_discover_tests(testabc074d)