add_executable(testabc196c c.cc)
add_executable(testabc196d d.cc)
target_link_libraries(testabc196c abc196c gtest_main)
target_link_libraries(testabc196d abc196d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc196c)
gtest_discover_tests(testabc196d)