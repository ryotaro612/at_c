# https://atcoder.jp/contests/abc100
add_executable(testabc100d d.cc)
target_link_libraries(testabc100d abc100d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc100d)
