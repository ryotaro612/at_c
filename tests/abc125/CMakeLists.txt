add_executable(TestFlippingSigns test_flipping_signs.cc)
target_link_libraries(TestFlippingSigns FlippingSigns gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestFlippingSigns)
