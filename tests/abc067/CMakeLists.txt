# https://atcoder.jp/contests/abc067
add_executable(testabc067d d.cc)
target_link_libraries(testabc067d abc067d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc067d)