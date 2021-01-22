# https://atcoder.jp/contests/abc054
add_executable(testabc054c c.cc)
target_link_libraries(testabc054c abc054c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc054c)