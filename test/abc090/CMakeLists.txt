# https://atcoder.jp/contests/abc090
add_executable(testabc090d d.cc)
target_link_libraries(testabc090d abc090d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc090d)