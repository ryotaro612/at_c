add_executable(testabc128b b.cc)
add_executable(testabc128c c.cc)
add_executable(TestEnqueue test_enqueue.cc)

target_link_libraries(testabc128b abc128b gtest_main)
target_link_libraries(testabc128c abc128c gtest_main)
target_link_libraries(TestEnqueue Enqueue gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc128b)
gtest_discover_tests(testabc128c)
gtest_discover_tests(TestEnqueue)
