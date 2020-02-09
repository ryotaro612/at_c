add_executable(TestFactorization test_factorization.cc)
target_link_libraries(TestFactorization Factorization gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestFactorization)
