#include "abc089/d.cc"

#include <gtest/gtest.h>

TEST(abc089d, 1) {
  vector<vector<int>> a = {{1, 4, 3}, {2, 5, 7}, {8, 9, 6}};
  vector<int> l = {4};
  vector<int> r = {8};
  vector<ll> ans = {5};
  EXPECT_EQ(ans, solve(3, 3, 2, a, 1, l, r));
}

TEST(abc089d, 2) {
  vector<vector<int>> a = {{3, 7}, {1, 4}, {5, 2}, {6, 8}};
  vector<int> l = {2, 2};
  vector<int> r = {2, 2};
  vector<ll> ans = {0, 0};
  EXPECT_EQ(ans, solve(4, 2, 3, a, 2, l, r));
}

TEST(abc089d, 3) {
  vector<vector<int>> a =
      {{13, 25, 7, 15, 17},
       {16, 22, 20, 2, 9},
       {14, 11, 12, 1, 19},
       {10, 6, 23, 8, 18},
       {3, 21, 5, 24, 4}};
  vector<int> l = {13, 2, 13};
  vector<int> r = {13, 10, 13};
  vector<ll> ans = {0, 5, 0};
  EXPECT_EQ(ans, solve(5, 5, 4, a, 3, l, r));
}