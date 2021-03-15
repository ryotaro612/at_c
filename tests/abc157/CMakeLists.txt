add_executable(testabc157c c.cc)
add_executable(TestFriendSuggestions test_friend_suggestions.cc)

target_link_libraries(testabc157c abc157c gtest_main)
target_link_libraries(TestFriendSuggestions FriendSuggestions gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc157c)
gtest_discover_tests(TestFriendSuggestions)
