# https://atcoder.jp/contests/abc088
add_executable(testabc088d d.cc)
target_link_libraries(testabc088d abc088d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc088d)