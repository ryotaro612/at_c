add_executable(testarc108b b.cc)
target_link_libraries(testarc108b arc108b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc108b)