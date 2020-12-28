# https://atcoder.jp/contests/abc050
add_executable(testabc050d d.cc)
target_link_libraries(testabc050d abc050d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc050d)