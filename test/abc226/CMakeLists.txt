include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc226d d.cc)
target_link_libraries(testabc226d abc226d gtest_main)
gtest_discover_tests(testabc226d)