add_executable(testabc182d d.cc)
add_executable(testabc182e e.cc)

target_link_libraries(testabc182d abc182d gtest_main)
target_link_libraries(testabc182e abc182e gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc182d)
gtest_discover_tests(testabc182e)