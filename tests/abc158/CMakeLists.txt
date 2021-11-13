add_executable(TestStringFormation test_string_formation.cc)
target_link_libraries(TestStringFormation StringFormation gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestStringFormation)
