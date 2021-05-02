add_executable(TestAbc140d test_abc140d.cc)
target_link_libraries(TestAbc140d Abc140d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc140d)
