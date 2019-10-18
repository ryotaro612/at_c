add_executable(TestSummerVacation test_summer_vacation.cc)
target_link_libraries(TestSummerVacation SummerVacation gtest_main)


include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestSummerVacation)
