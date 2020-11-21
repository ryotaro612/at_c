# https://atcoder.jp/contests/abc080
add_executable(testabc080d d.cc)
target_link_libraries(testabc080d abc080d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc080d)