include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc216f f.cc)
target_link_libraries(testabc216f abc216f gtest_main)
gtest_discover_tests(testabc216f)