#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc102/d.h"
typedef long long ll;

using namespace std;

TEST(abc102d, 1) {
  vector<ll> a = {3, 2, 4, 1, 2};
  EXPECT_EQ(2, d(5, a));
}

TEST(abc102d, 2) {
  vector<ll> a = {10, 71, 84, 33, 6, 47, 23, 25, 52, 64};
  EXPECT_EQ(36, d(10, a));
}

TEST(abc102d, 3) {
  vector<ll> a = {1,2,3,1000000000,4,5,6};
  EXPECT_EQ(999999994, d(7, a));
}
