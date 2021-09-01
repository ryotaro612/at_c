add_executable(TestEvenRelation test_even_relation.cc)
target_link_libraries(TestEvenRelation EvenRelation gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestEvenRelation)
