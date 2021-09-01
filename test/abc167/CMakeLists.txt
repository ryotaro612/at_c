add_executable(TestTeleporter test_teleporter.cc)
target_link_libraries(TestTeleporter Teleporter gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestTeleporter)
