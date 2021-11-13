add_executable(TestWeLikeAGC test_we_like_agc.cc)
target_link_libraries(TestWeLikeAGC WeLikeAGC gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestWeLikeAGC)
