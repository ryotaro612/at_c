#include "gtest/gtest.h"
#include "abc175/abc175d.h"
typedef long long ll;
using namespace std;


TEST(abc175d, 1) {
  ll p[] = {2, 4, 5, 1, 3};
  ll c[] = {3, 4, -10, -8, 8};
  EXPECT_EQ(8, abc175d(5, 2, p, c));
}

TEST(abc175d, 2) {
  ll p[] = {2, 1};
  ll c[] = {10, -7};
  EXPECT_EQ(13, abc175d(2, 3, p, c));
}

TEST(abc175d, 3) {
  ll p[] = {3, 1, 2};
  ll c[] = {-1000, -2000, -3000};
  EXPECT_EQ(-1000, abc175d(3, 3, p, c));
}

TEST(abc175d, 4) {
  ll p[] = {9, 1, 6, 7, 8, 4, 3, 2, 10, 5};
  ll c[] = {695279662,988782657,-119067776,382975538,-151885171,-177220596,-169777795, 37619092, 389386780, 980092719};
  EXPECT_EQ(29507023469, abc175d(10, 58, p, c));
}
