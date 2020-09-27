# https://atcoder.jp/contests/abc096
add_executable(testabc096d d.cc)
target_link_libraries(testabc096d abc096d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc096d)
