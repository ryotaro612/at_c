add_executable(testabc005c c.cc)
add_executable(testabc005d d.cc)
target_link_libraries(testabc005c abc005c gtest_main)
target_link_libraries(testabc005d abc005d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc005c)
gtest_discover_tests(testabc005d)