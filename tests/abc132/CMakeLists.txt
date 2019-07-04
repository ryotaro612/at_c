add_executable(TestFiftyFifty test_fifty_fifty.cc)
target_link_libraries(TestFiftyFifty FiftyFifty gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestFiftyFifty)