include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc222c c.cc)
target_link_libraries(testabc222c abc222c gtest_main)
gtest_discover_tests(testabc222c)

add_executable(testabc222d d.cc)
target_link_libraries(testabc222d abc222d gtest_main)
gtest_discover_tests(testabc222d)