# https://atcoder.jp/contests/abc028
add_executable(testabc028d d.cc)
target_link_libraries(testabc028d abc028d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc028d)