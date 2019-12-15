add_executable(TestXorSum4 test_xor_sum4.cc)
target_link_libraries(TestXorSum4 XorSum4 gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestXorSum4)
