add_executable(testabc198b b.cc)
add_executable(testabc198c c.cc)
add_executable(testabc198d d.cc)

target_link_libraries(testabc198b abc198b gtest_main)
target_link_libraries(testabc198c abc198c gtest_main)
target_link_libraries(testabc198d abc198d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc198b)
gtest_discover_tests(testabc198c)
gtest_discover_tests(testabc198d)