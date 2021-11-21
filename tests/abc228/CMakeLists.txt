include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc228c c.cc)
target_link_libraries(testabc228c abc228c gtest_main)
gtest_discover_tests(testabc228c)

add_executable(testabc228d d.cc)
target_link_libraries(testabc228d abc228d gtest_main)
gtest_discover_tests(testabc228d)