add_executable(TestMakeThemEven test_make_them_even.cc)
target_link_libraries(TestMakeThemEven MakeThemEven gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestMakeThemEven)
