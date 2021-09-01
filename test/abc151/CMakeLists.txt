add_executable(TestMazeMaster test_maze_master.cc)
target_link_libraries(TestMazeMaster MazeMaster gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestMazeMaster)
