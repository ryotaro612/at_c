add_executable(TestPreparingBoxes test_preparing_boxes.cc)
target_link_libraries(TestPreparingBoxes PreparingBoxes gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestPreparingBoxes)
