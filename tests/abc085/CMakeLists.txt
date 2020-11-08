# https://atcoder.jp/contests/abc085
add_executable(testabc085d d.cc)
target_link_libraries(testabc085d abc085d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc085d)