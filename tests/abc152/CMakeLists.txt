add_executable(TestHandstand2 test_handstand2.cc)
target_link_libraries(TestHandstand2 Handstand2 gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestHandstand2)
