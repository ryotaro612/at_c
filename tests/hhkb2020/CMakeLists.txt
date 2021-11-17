

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testhhkb2020e e.cc)
target_link_libraries(testhhkb2020e hhkb2020e gtest_main)
gtest_discover_tests(testhhkb2020e)