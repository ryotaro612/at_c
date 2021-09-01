# https://atcoder.jp/contests/abc098
add_executable(testabc098d d.cc)
target_link_libraries(testabc098d abc098d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc098d)
