# https://atcoder.jp/contests/abc048
add_executable(testabc048b b.cc)
add_executable(testabc048c c.cc)
target_link_libraries(testabc048b abc048b gtest_main)
target_link_libraries(testabc048c abc048c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc048b)
gtest_discover_tests(testabc048c)
