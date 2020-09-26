#include "gtest/gtest.h"
#include "abc107/d.cc"
using namespace std;

TEST(abc107d, 1) {
 auto ans = d(3, vector<ll> {10, 30, 20});
 EXPECT_EQ(30, ans);
}

TEST(abc107d, 2) {
 auto ans = d(1, vector<ll> {10});
 EXPECT_EQ(10, ans);
}

TEST(abc107d, 3) {
 auto ans = d(10, vector<ll> {5, 9, 5, 9, 8, 9, 3, 5, 4, 3});
 EXPECT_EQ(8, ans);
}

TEST(abc107d, 4) {
 auto ans = d(4, vector<ll> {1, 2, 3, 4});
 EXPECT_EQ(3, ans);
}

TEST(abc107d, 5) {
  vector<ll> a(100000);
  for(ll i =0;i<100000;i++) {
    a[i] = 100000 - i;
  }
  auto ans = d(100000, a);
  EXPECT_EQ(50001, ans);
}

TEST(abc107d, 6) {
  vector<ll> a(100000);
  for(ll i =1;i<=100000;i++) {
    a[i-1] = i;
  }
  auto ans = d(100000, a);
  EXPECT_EQ(50001, ans);
}
