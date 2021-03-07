add_executable(testabc194c c.cc)
add_executable(testabc194d d.cc)
target_link_libraries(testabc194c abc194c gtest_main)
target_link_libraries(testabc194d abc194d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc194c)
gtest_discover_tests(testabc194d)