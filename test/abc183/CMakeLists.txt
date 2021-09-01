add_executable(testabc183d d.cc)
target_link_libraries(testabc183d abc183d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc183d)