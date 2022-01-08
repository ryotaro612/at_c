#include <gtest/gtest.h>
#include "abc234/f.cc"

TEST(abc234f, 1) {
  string s = "aab";
  EXPECT_EQ(8ll, solve(s));
}

TEST(abc234f, 2) {
  string s = "aaa";
  EXPECT_EQ(3ll, solve(s));
}

TEST(abc234f, 3) {
  string s = "abcdefghijklmnopqrstuvwxyz";
  EXPECT_EQ(149621752ll, solve(s));
}

TEST(abc234f, 4) {
  string s = "a";
  EXPECT_EQ(1ll, solve(s));
}
