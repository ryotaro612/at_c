add_executable(testabc187d d.cc)
target_link_libraries(testabc187d abc187d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc187d)