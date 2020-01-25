add_executable(TestXxor test_xxor.cc)
target_link_libraries(TestXxor Xxor gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestXxor)
