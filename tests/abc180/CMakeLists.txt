add_executable(testabc180d d.cc)
target_link_libraries(testabc180d abc180d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc180d)