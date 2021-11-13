# https://atcoder.jp/contests/abc066
add_executable(testabc066d d.cc)
target_link_libraries(testabc066d abc066d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc066d)