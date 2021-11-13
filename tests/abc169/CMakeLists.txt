add_executable(TestDivGame test_div_game.cc)
target_link_libraries(TestDivGame DivGame gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestDivGame)
