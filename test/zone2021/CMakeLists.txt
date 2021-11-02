include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testzone2021c c.cc)
target_link_libraries(testzone2021c zone2021c gtest_main)
gtest_discover_tests(testzone2021c)