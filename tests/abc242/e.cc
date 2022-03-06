#include "abc242/e.cc"
#include "gtest/gtest.h"

TEST(abc242e, 1) {
  string s = "ABCZAZ";
  ll res = solve_item(s.size(), s);
  EXPECT_EQ(29ll, res);
}

TEST(abc242e, 5) {
  string s = "KVOHEEMSOZZASHENDIGOJRTJVMVSDWW";
  ll res = solve_item(s.size(), s);
  EXPECT_EQ(231364016ll, res);
}
