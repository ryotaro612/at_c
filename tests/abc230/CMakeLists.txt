include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc230e e.cc)
target_link_libraries(testabc230e abc230e gtest_main)
gtest_discover_tests(testabc230e)