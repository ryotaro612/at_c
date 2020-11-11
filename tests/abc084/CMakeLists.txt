# https://atcoder.jp/contests/abc084
add_executable(testabc084d d.cc)
target_link_libraries(testabc084d abc084d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc084d)