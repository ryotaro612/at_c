# https://atcoder.jp/contests/abc073
add_executable(testabc073d d.cc)
target_link_libraries(testabc073d abc073d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc073d)