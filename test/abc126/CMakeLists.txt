include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(TestEvenRelation test_even_relation.cc)
target_link_libraries(TestEvenRelation EvenRelation gtest_main)
gtest_discover_tests(TestEvenRelation)

add_executable(testabc126e e.cc)
target_link_libraries(testabc126e abc126e gtest_main)
gtest_discover_tests(testabc126e)