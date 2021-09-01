add_executable(TestAbc166d test_abc166d.cc)
target_link_libraries(TestAbc166d IHateFactorization gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc166d)
