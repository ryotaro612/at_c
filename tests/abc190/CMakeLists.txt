include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc190c c.cc)
target_link_libraries(testabc190c abc190c gtest_main)
gtest_discover_tests(testabc190c)

add_executable(testabc190d d.cc)
target_link_libraries(testabc190d abc190d gtest_main)
gtest_discover_tests(testabc190d)

add_executable(testabc190f f.cc)
target_link_libraries(testabc190f abc190f gtest_main)
gtest_discover_tests(testabc190f)