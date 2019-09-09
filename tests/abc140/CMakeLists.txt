add_executable(TestMaximalValue test_maximal_value.cc)
target_link_libraries(TestMaximalValue MaximalValue gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestMaximalValue)