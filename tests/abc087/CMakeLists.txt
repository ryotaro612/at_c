# https://atcoder.jp/contests/abc087
include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc087c c.cc)
target_link_libraries(testabc087c abc087c gtest_main)
gtest_discover_tests(testabc087c)

add_executable(testabc087d d.cc)
target_link_libraries(testabc087d abc087d gtest_main)
gtest_discover_tests(testabc087d)