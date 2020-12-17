# https://atcoder.jp/contests/abc060
add_executable(testabc060d d.cc)
target_link_libraries(testabc060d abc060d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc060d)