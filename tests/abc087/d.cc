#include "abc087/d.cc"
#include <gtest/gtest.h>

TEST(abc087d, 1) {
  vector<ll> l = {1, 2, 1};
  vector<ll> r = {2, 3, 3};
  vector<ll> d = {1, 1, 2};

  EXPECT_EQ("Yes", solve(3, 3, l, r, d));
}

TEST(abc087d, 2) {
  vector<ll> l = {1, 2, 1};
  vector<ll> r = {2, 3, 3};
  vector<ll> d = {1, 1, 5};

  EXPECT_EQ("No", solve(3, 3, l, r, d));
}

TEST(abc087d, 3) {
  vector<ll> l = {2, 2, 3};
  vector<ll> r = {1, 3, 4};
  vector<ll> d = {1, 5, 2};

  EXPECT_EQ("Yes", solve(4, 3, l, r, d));
}

TEST(abc087d, 4) {
  vector<ll> l = {8, 7, 9};
  vector<ll> r = {7, 9, 8};
  vector<ll> d = {100, 100, 100};

  EXPECT_EQ("No", solve(10, 3, l, r, d));
}

TEST(abc087d, 5) {
  vector<ll> l = {};
  vector<ll> r = {};
  vector<ll> d = {};

  EXPECT_EQ("Yes", solve(100, 0, l, r, d));
}