add_executable(TestCaracalVsMonster test_caracal_vs_monster.cc)
target_link_libraries(TestCaracalVsMonster CaracalVsMonster gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestCaracalVsMonster)
