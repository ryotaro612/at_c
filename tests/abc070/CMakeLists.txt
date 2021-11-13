# https://atcoder.jp/contests/abc070
add_executable(testabc070d d.cc)
target_link_libraries(testabc070d abc070d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc070d)