include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(TestLunlunNumber test_lunlun_number.cc)
target_link_libraries(TestLunlunNumber LunlunNumber gtest_main)
gtest_discover_tests(TestLunlunNumber)

add_executable(testabc161f f.cc)
target_link_libraries(testabc161f abc161f gtest_main)
gtest_discover_tests(testabc161f)
