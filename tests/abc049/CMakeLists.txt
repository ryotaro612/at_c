
# https://atcoder.jp/contests/abc049
add_executable(testabc049c c.cc)
target_link_libraries(testabc049c abc049c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc049c)