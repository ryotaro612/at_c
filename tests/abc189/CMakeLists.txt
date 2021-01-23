add_executable(testabc189b b.cc)
add_executable(testabc189c c.cc)
add_executable(testabc189d d.cc)
target_link_libraries(testabc189b abc189b gtest_main)
target_link_libraries(testabc189c abc189c gtest_main)
target_link_libraries(testabc189d abc189d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc189b)
gtest_discover_tests(testabc189c)
gtest_discover_tests(testabc189d)