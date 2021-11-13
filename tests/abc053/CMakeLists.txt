# https://atcoder.jp/contests/abc053
add_executable(testabc053d d.cc)
target_link_libraries(testabc053d abc053d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc053d)