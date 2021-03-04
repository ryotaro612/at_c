
add_executable(testtenka1_2018_beginnerc c.cc)

target_link_libraries(testtenka1_2018_beginnerc tenka1_2018_beginnerc gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testtenka1_2018_beginnerc)