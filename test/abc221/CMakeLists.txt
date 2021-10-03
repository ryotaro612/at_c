include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc221c c.cc)
target_link_libraries(testabc221c abc221c gtest_main)
gtest_discover_tests(testabc221c)

add_executable(testabc221d d.cc)
target_link_libraries(testabc221d abc221d gtest_main)
gtest_discover_tests(testabc221d)