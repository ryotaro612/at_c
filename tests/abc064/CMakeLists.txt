# https://atcoder.jp/contests/abc064
add_executable(testabc064d d.cc)
target_link_libraries(testabc064d abc064d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc064d)