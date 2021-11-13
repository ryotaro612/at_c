include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc220c c.cc)
target_link_libraries(testabc220c abc220c gtest_main)
gtest_discover_tests(testabc220c)

add_executable(testabc220e e.cc)
target_link_libraries(testabc220e abc220e gtest_main)
gtest_discover_tests(testabc220e)

add_executable(testabc220f f.cc)
target_link_libraries(testabc220f abc220f gtest_main)
gtest_discover_tests(testabc220f)