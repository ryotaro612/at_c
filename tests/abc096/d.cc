#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc096/d.cc"

//solve(int n)
//
TEST(abc096d, 1) {
  vector<int> a = {11, 31, 41, 61, 71};
  EXPECT_EQ(a, solve(5));
}
