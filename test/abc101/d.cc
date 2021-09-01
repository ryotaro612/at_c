#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc101/d.cc"
typedef long long ll;

using namespace std;

TEST(abc101d, 1) {
  vector<ll> ans = {1, 2, 3, 4, 5, 6, 7, 8, 9, 19}; 
  EXPECT_EQ(ans, d(10));
}

TEST(abc101d, 2) {
  vector<ll> ans = {1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 29, 39, 49, 59, 69, 79, 89, 99, 199}; 
  EXPECT_EQ(ans, d(19));
}
