add_executable(TestBouquet test_bouquet.cc)
target_link_libraries(TestBouquet Bouquet gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestBouquet)
