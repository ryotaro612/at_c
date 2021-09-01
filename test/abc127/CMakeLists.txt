add_executable(TestIntegerCards test_integer_cards.cc)
target_link_libraries(TestIntegerCards IntegerCards gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestIntegerCards)
