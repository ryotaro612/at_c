include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testarc123a a.cc)
target_link_libraries(testarc123a arc123a gtest_main)
gtest_discover_tests(testarc123a)

add_executable(testarc123b b.cc)
target_link_libraries(testarc123b arc123b gtest_main)
gtest_discover_tests(testarc123b)