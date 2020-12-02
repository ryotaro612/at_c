# https://atcoder.jp/contests/abc071
add_executable(testabc071d d.cc)
target_link_libraries(testabc071d abc071d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc071d)