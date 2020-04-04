add_executable(TestBannedK test_banned_k.cc)
target_link_libraries(TestBannedK BannedK gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestBannedK)
