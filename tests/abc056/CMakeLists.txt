# https://atcoder.jp/contests/abc056
add_executable(testabc056d d.cc)
target_link_libraries(testabc056d abc056d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc056d)