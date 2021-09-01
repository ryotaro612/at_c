# https://atcoder.jp/contests/abc087
add_executable(testabc087d d.cc)
target_link_libraries(testabc087d abc087d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc087d)