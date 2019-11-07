add_executable(TestMegalomania test_magalomania.cc)
target_link_libraries(TestMegalomania Megalomania gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestMegalomania)
