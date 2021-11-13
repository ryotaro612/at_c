add_executable(testabc195c c.cc)
add_executable(testabc195d d.cc)
target_link_libraries(testabc195c abc195c gtest_main)
target_link_libraries(testabc195d abc195d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc195c)
gtest_discover_tests(testabc195d)