#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc098/d.cc"

TEST(abc098d, 1) {
  vector<ll> a = {2, 5, 4, 6};
  EXPECT_EQ(5, solve(4, a));
}

TEST(abc098d, 2) {
  vector<ll> a = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_EQ(45, solve(9, a));
}

TEST(abc098d, 3) {
vector<ll> a = {885, 8, 1, 128, 83, 32, 256, 206, 639, 16, 4, 128, 689, 32, 8, 64, 885, 969, 1};
  EXPECT_EQ(37, solve(19, a));
}
