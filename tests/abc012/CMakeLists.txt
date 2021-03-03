add_executable(testabc012d d.cc)

target_link_libraries(testabc012d abc012d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc012d)