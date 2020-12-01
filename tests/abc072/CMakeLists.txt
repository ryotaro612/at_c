# https://atcoder.jp/contests/abc072
add_executable(testabc072d d.cc)
target_link_libraries(testabc072d abc072d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc072d)