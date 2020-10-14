#include <gtest/gtest.h>
#include "abc091/d.cc"

TEST(abc091d_sub, 1) {
 EXPECT_EQ(2, boundary_eq(1, {1, 2, 4, 5}, 4, 1<<2));
 EXPECT_EQ(1, boundary_eq(1, {1, 4, 4, 5}, 4, 1<<2));
 EXPECT_EQ(4, boundary_eq(1, {1, 1, 1, 1}, 4, 1<<2));
 EXPECT_EQ(0, boundary_eq(4, {4, 4, 4, 4}, 4, 1<<2));
 EXPECT_EQ(0, boundary(3, {4, 5, 6, 7}, 4, 1<<3));
 EXPECT_EQ(3, boundary(3, {3, 4, 4, 4}, 4, 1<<3));
 EXPECT_EQ(-1, boundary(7, {2, 3, 4, 5}, 4, 1<<3));
}

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