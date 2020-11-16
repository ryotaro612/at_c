# https://atcoder.jp/contests/abc082
add_executable(testabc082d d.cc)
target_link_libraries(testabc082d abc082d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc082d)