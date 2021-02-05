add_executable(testabc001d d.cc)
target_link_libraries(testabc001d abc001d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc001d)