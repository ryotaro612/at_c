# https://atcoder.jp/contests/abc058
add_executable(testabc058d d.cc)
target_link_libraries(testabc058d abc058d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc058d)