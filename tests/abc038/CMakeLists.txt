# https://atcoder.jp/contests/abc038
add_executable(testabc038c c.cc)
target_link_libraries(testabc038c abc038c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc038c)