# https://atcoder.jp/contests/abc086
add_executable(testabc086d d.cc)
target_link_libraries(testabc086d abc086d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc086d)