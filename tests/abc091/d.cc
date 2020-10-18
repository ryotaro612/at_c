#include <gtest/gtest.h>
#include "abc091/d.cc"


TEST(abc091d, 1) {
  int n = 2;
  vector<ll> a = {1, 2};
  vector<ll> b = {3, 4};
  auto res = solve(n, a, b);
  EXPECT_EQ(2, res);
}
TEST(abc091d, 2) {
  int n = 6;
  vector<ll> a = {4, 6, 0, 0, 3, 3};
  vector<ll> b = {0, 5, 6, 5, 0, 3};
  auto res = solve(n, a, b);
  EXPECT_EQ(8, res);
}
TEST(abc091d, 3) {
  int n = 5;
  vector<ll> a = {1, 2, 3, 4, 5};
  vector<ll> b = {1, 2, 3, 4, 5};
  auto res = solve(n, a, b);
  EXPECT_EQ(2, res);
}
TEST(abc091d, 4) {
  int n = 1;
  vector<ll> a = {0};
  vector<ll> b = {0};
  auto res = solve(n, a, b);
  EXPECT_EQ(0, res);
}