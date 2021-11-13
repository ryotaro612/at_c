include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc146c c.cc)
target_link_libraries(testabc146c abc146c gtest_main)
gtest_discover_tests(testabc146c)

add_executable(TestColoringEdgesOnTree test_coloring_edges_on_tree.cc)
target_link_libraries(TestColoringEdgesOnTree ColoringEdgesOnTree gtest_main)
gtest_discover_tests(TestColoringEdgesOnTree)

add_executable(testabc146f f.cc)
target_link_libraries(testabc146f abc146f gtest_main)
gtest_discover_tests(testabc146f)