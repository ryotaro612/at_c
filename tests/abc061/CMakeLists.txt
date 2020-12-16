# https://atcoder.jp/contests/abc061
add_executable(testabc061d d.cc)
target_link_libraries(testabc061d abc061d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc061d)