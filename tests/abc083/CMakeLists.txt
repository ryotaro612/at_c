# https://atcoder.jp/contests/abc083
add_executable(testabc083d d.cc)
target_link_libraries(testabc083d abc083d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc083d)