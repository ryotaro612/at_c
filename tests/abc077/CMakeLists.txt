# https://atcoder.jp/contests/abc077
add_executable(testabc077d d.cc)
target_link_libraries(testabc077d abc077d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc077d)