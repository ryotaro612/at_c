# https://atcoder.jp/contests/abc093
add_executable(testabc093d d.cc)
target_link_libraries(testabc093d abc093d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc093d)