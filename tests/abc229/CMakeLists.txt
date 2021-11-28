include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc229d d.cc)
target_link_libraries(testabc229d abc229d gtest_main)
gtest_discover_tests(testabc229d)

add_executable(testabc229e e.cc)
target_link_libraries(testabc229e abc229e gtest_main)
gtest_discover_tests(testabc229e)