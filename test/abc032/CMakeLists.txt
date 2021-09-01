# https://atcoder.jp/contests/abc032
add_executable(testabc032c c.cc)
target_link_libraries(testabc032c abc032c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc032c)