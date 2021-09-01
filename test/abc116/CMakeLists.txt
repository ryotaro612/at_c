add_executable(TestVariousSushi test_various_sushi.cc)
target_link_libraries(TestVariousSushi VariousSushi gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestVariousSushi)
