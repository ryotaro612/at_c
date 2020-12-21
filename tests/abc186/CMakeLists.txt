add_executable(testabc186d d.cc)
target_link_libraries(testabc186d abc186d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc186d)