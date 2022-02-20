#include "abc239/e.cc"
#include <gtest/gtest.h>
typedef long long ll;

TEST(abc239e, 1) {
  vector<ll> xv = {1, 2, 3, 4, 5};
  vector<int> av = {1, 2, 2, 3};
  vector<int> bv = {4, 1, 5, 2};
  vector<int> vv = {1, 2};
  vector<int> kv = {2, 1};
  vector<ll> res = solve(5, 2, xv, av, bv, vv, kv);
  vector<ll> ans = {4, 5};
  EXPECT_EQ(ans, res);
}

TEST(abc239e, 2) {
  vector<ll> xv = {10, 10, 10, 9, 8, 8};
  vector<int> av = {1, 2, 2, 3, 6};
  vector<int> bv = {4, 1, 5, 2, 4};
  vector<int> vv = {1, 2};
  vector<int> kv = {4, 2};
  vector<ll> res = solve(6, 2, xv, av, bv, vv, kv);
  vector<ll> ans = {9, 10};
  EXPECT_EQ(ans, res);
}

TEST(abc239e, 3) {

  vector<ll> xv = {1, 10, 100, 1000};
  vector<int> av = {1, 2, 3};
  vector<int> bv = {2, 3, 4};
  vector<int> vv = {1, 2, 3, 4};
  vector<int> kv = {4, 3, 2, 1};
  vector<ll> res = solve(4, 4, xv, av, bv, vv, kv);
  vector<ll> ans = {1, 10, 100, 1000};
  EXPECT_EQ(ans, res);
}
