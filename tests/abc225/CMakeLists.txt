include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc225c c.cc)
target_link_libraries(testabc225c abc225c gtest_main)
gtest_discover_tests(testabc225c)

add_executable(testabc225d d.cc)
target_link_libraries(testabc225d abc225d gtest_main)
gtest_discover_tests(testabc225d)