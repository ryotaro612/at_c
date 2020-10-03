# https://atcoder.jp/contests/abc094
add_executable(testabc094d d.cc)
target_link_libraries(testabc094d abc094d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc094d)
