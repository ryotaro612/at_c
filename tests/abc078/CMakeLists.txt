# https://atcoder.jp/contests/abc078
add_executable(testabc078d d.cc)
target_link_libraries(testabc078d abc078d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc078d)