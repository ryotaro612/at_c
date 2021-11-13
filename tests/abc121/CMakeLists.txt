add_executable(TestXORWorld test_xor_world.cc)
target_link_libraries(TestXORWorld XORWorld gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestXORWorld)
