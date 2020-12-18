# https://atcoder.jp/contests/abc059
add_executable(testabc059d d.cc)
target_link_libraries(testabc059d abc059d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc059d)