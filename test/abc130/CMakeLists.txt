add_executable(TestEnoughArray test_enough_array.cc)
target_link_libraries(TestEnoughArray EnoughArray gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestEnoughArray)
