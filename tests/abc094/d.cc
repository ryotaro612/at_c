#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc094/d.cc"

TEST(abc094d, 1) {
  auto res = solve(5, {6, 9, 4, 2, 11});
  EXPECT_EQ(11, res.first);
  EXPECT_EQ(6, res.second);
}

TEST(abc094d, 2) {
  auto res = solve(2, {100, 0});
  EXPECT_EQ(100, res.first);
  EXPECT_EQ(0, res.second);
}

