#include "gtest/gtest.h"
#include "bits/stdc++.h"
#include "abc168/d.h"
using namespace std;

TEST(abc168d, 1) {
  vector<vector<int>> edge = {{1}, {3, 2}, {1, 3}, {1, 2}};
  vector<int> ans = {1, 2, 2};
  EXPECT_EQ(ans, abc168d(4, edge));
}
