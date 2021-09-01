add_executable(testabc190c c.cc)
add_executable(testabc190d d.cc)
target_link_libraries(testabc190c abc190c gtest_main)
target_link_libraries(testabc190d abc190d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc190c)
gtest_discover_tests(testabc190d)