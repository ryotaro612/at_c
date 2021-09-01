add_executable(testabc111c c.cc)
add_executable(TestRobotArms test_robot_arms.cc)

target_link_libraries(testabc111c abc111c gtest_main)
target_link_libraries(TestRobotArms RobotArms gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc111c)
gtest_discover_tests(TestRobotArms)
