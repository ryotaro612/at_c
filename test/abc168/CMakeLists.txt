add_executable(TestAbc168d d.cc)
target_link_libraries(TestAbc168d Abc168d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc168d)
