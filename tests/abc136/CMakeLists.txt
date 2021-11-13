add_executable(TestGatheringChildren test_gathering_children.cc)
target_link_libraries(TestGatheringChildren GatheringChildren gtest_main)


include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestGatheringChildren)
