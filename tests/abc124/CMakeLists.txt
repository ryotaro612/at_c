add_executable(TestHandstand test_handstand.cc)
target_link_libraries(TestHandstand Handstand gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestHandstand)
