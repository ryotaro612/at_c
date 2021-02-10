# https://atcoder.jp/contests/abc030
add_executable(testabc030d d.cc)
target_link_libraries(testabc030d abc030d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc030d)