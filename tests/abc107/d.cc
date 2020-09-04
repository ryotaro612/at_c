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

