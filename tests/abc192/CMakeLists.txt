add_executable(testabc192c c.cc)
add_executable(testabc192d d.cc)
target_link_libraries(testabc192c abc192c gtest_main)
target_link_libraries(testabc192d abc192d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc192c)
gtest_discover_tests(testabc192d)