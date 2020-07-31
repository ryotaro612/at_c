#add_executable(TestFiftyFifty test_fifty_fifty.cc)
#target_link_libraries(TestFiftyFifty FiftyFifty gtest_main)

#add_executable(TestOrdinaryNumber test_ordinary_number.cc)
#target_link_libraries(TestOrdinaryNumber OrdinaryNumber gtest_main)

#add_executable(TestDivideTheProblem test_divide_the_problem.cc)
#target_link_libraries(TestDivideTheProblem DivideTheProblem gtest_main)

add_executable(TestBlueAndRedBalls test_blue_and_red_balls.cc)
target_link_libraries(TestBlueAndRedBalls BlueAndRedBalls gtest_main)

#add_executable(TestHopscotchAddict test_hopscotch_addict.cc)
#target_link_libraries(TestHopscotchAddict HopscotchAddict gtest_main)

#add_executable(TestSmallProducts test_small_products.cc)
#target_link_libraries(TestSmallProducts SmallProducts gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

#gtest_discover_tests(TestFiftyFifty)
#gtest_discover_tests(TestOrdinaryNumber)
#gtest_discover_tests(TestDivideTheProblem)
gtest_discover_tests(TestBlueAndRedBalls)
#gtest_discover_tests(TestHopscotchAddict)
#gtest_discover_tests(TestSmallProducts)
