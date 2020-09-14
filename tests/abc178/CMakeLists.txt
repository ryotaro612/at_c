add_executable(testabc178d d.cc)
target_link_libraries(testabc178d abc178d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc178d)
