# https://atcoder.jp/contests/abc057
add_executable(testabc057c c.cc)
add_executable(testabc057d d.cc)
target_link_libraries(testabc057c abc057c gtest_main)
target_link_libraries(testabc057d abc057d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc057c)
gtest_discover_tests(testabc057d)