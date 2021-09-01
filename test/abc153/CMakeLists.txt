add_executable(TestCaracalVsMonster test_caracal_vs_monster.cc)
add_executable(testabc153e e.cc)

target_link_libraries(TestCaracalVsMonster CaracalVsMonster gtest_main)
target_link_libraries(testabc153e abc153e gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestCaracalVsMonster)
gtest_discover_tests(testabc153e)


