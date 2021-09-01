# https://atcoder.jp/contests/abc096
add_executable(testabc095d d.cc)
target_link_libraries(testabc095d abc095d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc095d)
