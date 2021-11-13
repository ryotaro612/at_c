#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc100/d.cc"

TEST(abc100d, 1) {
  vector<ll> x = {3, 1, 2, 3, 9};
  vector<ll> y = {1, 5, 6, 5, 7};
  vector<ll> z = {4, 9, 5, 8, 9};
  EXPECT_EQ(56, d(5, 3, x, y, z));
}

TEST(abc100d, 2) {
  vector<ll> x = {1, -4, 7, -10, 13};
  vector<ll> y = {-2, 5, -8, 11, -14};
  vector<ll> z = {3, -6, -9, -12, 15};
  EXPECT_EQ(54, d(5, 3, x, y, z));
}

TEST(abc100d, 3) {
  vector<ll> x = {10, 23, -94, -26, -69, -26, -72, 21, 40, -62};
  vector<ll> y = {-80, 8, 28, -2, 72, -86, -50, 65, -94, 18};
  vector<ll> z = {21, 38, 11, 18, 79, -54, 59, -32, 87, 82};
  EXPECT_EQ(638, d(10, 5, x, y, z));
}

TEST(abc100d, 4) {
  vector<ll> x = {2000000000, 7000000000, 6000000000};
  vector<ll> y = {-9000000000, -5000000000, -1000000000};
  vector<ll> z = {4000000000, 3000000000, 8000000000};

  EXPECT_EQ(30000000000, d(3, 2, x, y, z));
}
