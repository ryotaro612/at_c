# https://atcoder.jp/contests/abc048
add_executable(testabc048b b.cc)
target_link_libraries(testabc048b abc048b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc048b)