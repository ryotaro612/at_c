add_executable(testabc179d d.cc)
target_link_libraries(testabc179d abc179d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc179d)
