add_executable(TestRobotArms test_robot_arms.cc)
target_link_libraries(TestRobotArms RobotArms gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestRobotArms)
