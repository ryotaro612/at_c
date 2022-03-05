#include "abc242/b.cc"
#include <gtest/gtest.h>

TEST(abc242b, 1) {
  string s = "aba";
  EXPECT_EQ("aab", solve(s));
}

TEST(abc242b, 2) {
  string s = "zzzz";
  EXPECT_EQ("zzzz", solve(s));
}
