add_executable(TestKi test_ki.cc)
target_link_libraries(TestKi Ki gtest_main)


include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestKi)
