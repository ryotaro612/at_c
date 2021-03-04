add_executable(testtenka1_2019_beginnerc c.cc)

target_link_libraries(testtenka1_2019_beginnerc tenka1_2019_beginnerc gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testtenka1_2019_beginnerc)