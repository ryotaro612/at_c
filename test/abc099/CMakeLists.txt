# https://atcoder.jp/contests/abc099
add_executable(testabc099d d.cc)
target_link_libraries(testabc099d abc099d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc099d)
