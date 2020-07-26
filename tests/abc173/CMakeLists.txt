add_executable(TestChatInACircle test_chat_in_a_circle.cc)
target_link_libraries(TestChatInACircle ChatInACircle gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestChatInACircle)
