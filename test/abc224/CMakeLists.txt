include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc224d d.cc)
target_link_libraries(testabc224d abc224d gtest_main)
gtest_discover_tests(testabc224d)