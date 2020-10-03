#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc094/d.cc"

TEST(abc094d, 1) {
  EXPECT_EQ(make_pair(11, 6), solve(5, {6, 9, 4, 2, 11}));
}

TEST(abc094d, 2) {
  EXPECT_EQ(make_pair(100, 0), solve(2, {100, 0}));
}

