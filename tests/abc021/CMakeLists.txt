# https://atcoder.jp/contests/abc021
add_executable(testabc021c c.cc)
target_link_libraries(testabc021c abc021c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc021c)