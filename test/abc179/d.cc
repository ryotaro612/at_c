#include "gtest/gtest.h"
#include "abc179/d.cc"
typedef long long ll;
using namespace std;

TEST(abc179d, 1) {
  vector<ll> l = {1, 3};
  vector<ll> r = {1, 4};
  EXPECT_EQ(4, solve(5, 2, l, r));
}

TEST(abc179d, 2) {
  vector<ll> l = {3, 5};
  vector<ll> r = {3, 5};
  EXPECT_EQ(0, solve(5, 2, l, r));
}

TEST(abc179d, 3) {
  vector<ll> l = {1};
  vector<ll> r = {2};
  EXPECT_EQ(5, solve(5, 1, l, r));
}

TEST(abc179d, 4) {
  vector<ll> l = {5, 1, 10};
  vector<ll> r = {8, 3, 15};
  EXPECT_EQ(221823067, solve(60, 3, l, r));
}
