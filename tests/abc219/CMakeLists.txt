include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc219c c.cc)
target_link_libraries(testabc219c abc219c gtest_main)
gtest_discover_tests(testabc219c)

add_executable(testabc219d d.cc)
target_link_libraries(testabc219d abc219d gtest_main)
gtest_discover_tests(testabc219d)

# add_executable(testabc219e e.cc)
# target_link_libraries(testabc219e abc219e gtest_main)
# gtest_discover_tests(testabc219e)