#include "gtest/gtest.h"
#include "abc165/c.cc"

TEST(abc165c, 1) {
  vector<vector<ll>> qa(3);
  qa[0] = {1, 3, 3, 100};
  qa[1] = {1, 2, 2, 10};
  qa[2] = {2, 3, 2, 10};
  EXPECT_EQ(110, solve(3, 4, 3, qa));
}