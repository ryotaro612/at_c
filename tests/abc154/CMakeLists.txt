add_executable(TestDiceInLine test_dice_in_line.cc)
target_link_libraries(TestDiceInLine DiceInLine gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestDiceInLine)
