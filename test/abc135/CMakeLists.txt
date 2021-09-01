add_executable(TestDigitsParade test_digits_parade.cc)
target_link_libraries(TestDigitsParade DigitsParade gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestDigitsParade)
