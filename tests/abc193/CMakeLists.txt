add_executable(testabc193c c.cc)
add_executable(testabc193d d.cc)
target_link_libraries(testabc193c abc193c gtest_main)
target_link_libraries(testabc193d abc193d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc193c)
gtest_discover_tests(testabc193d)