add_executable(testabc186c c.cc)
add_executable(testabc186d d.cc)

target_link_libraries(testabc186c abc186c gtest_main)
target_link_libraries(testabc186d abc186d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc186c)
gtest_discover_tests(testabc186d)