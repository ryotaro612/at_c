#include<vector>
#include "gtest/gtest.h"
#include "abc157/friend_suggestions.h"

using namespace std;

TEST(FriendSuggestions, 1) {
  int a[] = {2, 1, 3, 3};
  int b[] = {1, 3, 2, 4};
  int c[] = {4};
  int d[] = {1};
  vector<int> ans = {0, 1, 0, 1};
  EXPECT_EQ(ans, friend_suggestions(4, 4, 1, a, b, c, d));
}

TEST(FriendSuggestions, 2) {
  int a[] = {1, 1, 1, 1, 3, 2, 2, 4, 5, 4};
  int b[] = {2, 3, 4, 5, 2, 4, 5, 3, 3, 5};
  int c[] = {};
  int d[] = {};
  vector<int> ans = {0, 0, 0, 0, 0};
  EXPECT_EQ(ans, friend_suggestions(5, 10, 0, a, b, c, d));
}
TEST(FriendSuggestions, 3) {
  int a[] = {10, 6, 8 , 2, 8, 7, 10, 6, 5};
  int b[] = {1, 7, 2, 5, 4, 3, 9, 4, 8};
  int c[] = {2, 7, 3};
  int d[] = {6, 5, 1};
  vector<int> ans = {1, 3, 5, 4, 3, 3, 3, 3, 1, 0};
  EXPECT_EQ(ans, friend_suggestions(10, 9, 3, a, b, c, d));
}
