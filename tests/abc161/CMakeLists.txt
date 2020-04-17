add_executable(TestLunlunNumber test_lunlun_number.cc)
target_link_libraries(TestLunlunNumber LunlunNumber gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestLunlunNumber)
