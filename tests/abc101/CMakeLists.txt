# https://atcoder.jp/contests/abc101
add_executable(testabc101d d.cc)
target_link_libraries(testabc101d abc101d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc101d)
