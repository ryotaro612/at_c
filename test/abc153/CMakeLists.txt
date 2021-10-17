include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(TestCaracalVsMonster test_caracal_vs_monster.cc)
target_link_libraries(TestCaracalVsMonster CaracalVsMonster gtest_main)
gtest_discover_tests(TestCaracalVsMonster)

add_executable(testabc153e e.cc)
target_link_libraries(testabc153e abc153e gtest_main)
gtest_discover_tests(testabc153e)

add_executable(testabc153f f.cc)
target_link_libraries(testabc153f abc153f gtest_main)
gtest_discover_tests(testabc153f)