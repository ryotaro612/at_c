add_executable(testabc181d d.cc)
add_executable(testabc181e e.cc)

target_link_libraries(testabc181d abc181d gtest_main)
target_link_libraries(testabc181e abc181e gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc181d)
gtest_discover_tests(testabc181e)