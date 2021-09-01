add_executable(testcaddi2018bd d.cc)

target_link_libraries(testcaddi2018bd caddi2018bd gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testcaddi2018bd)