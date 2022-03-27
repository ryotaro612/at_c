#include "abc245/f.cc"
#include "gtest/gtest.h"

TEST(abc245f, 1) {
  vector<int> uv = {1, 2, 3, 4, 4};
  vector<int> vv = {2, 3, 4, 2, 5};
  EXPECT_EQ(4, solve(5, 5, uv, vv));
}

TEST(abc245f, 2) {
  vector<int> uv = {1, 2};
  vector<int> vv = {2, 1};
  EXPECT_EQ(2, solve(3, 2, uv, vv));
}
