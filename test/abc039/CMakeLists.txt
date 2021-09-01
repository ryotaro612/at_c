add_executable(testabc039d d.cc)
target_link_libraries(testabc039d abc039d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc039d)