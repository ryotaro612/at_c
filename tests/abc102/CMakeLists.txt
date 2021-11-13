# https://atcoder.jp/contests/abc102
add_executable(TestAbc102d d.cc)
target_link_libraries(TestAbc102d Abc102d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc102d)
