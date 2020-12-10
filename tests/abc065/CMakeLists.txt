# https://atcoder.jp/contests/abc065
add_executable(testabc065d d.cc)
target_link_libraries(testabc065d abc065d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc065d)