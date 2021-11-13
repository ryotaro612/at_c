add_executable(testabc110c c.cc)
add_executable(TestFactorization test_factorization.cc)
target_link_libraries(TestFactorization Factorization gtest_main)
target_link_libraries(testabc110c abc110c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc110c)
gtest_discover_tests(TestFactorization)
