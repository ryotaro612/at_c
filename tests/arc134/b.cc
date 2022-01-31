#include "arc134/b.cc"
#include <gtest/gtest.h>

TEST(arc134b, 1) {
  string s = "dcab";
  EXPECT_EQ("acdb", solve(s.size(), s));
}

TEST(arc134b, 2) {
  string s = "ab";
  EXPECT_EQ("ab", solve(s.size(), s));
}

TEST(arc134b, 3) {
  string s = "cabaaabbbabcbaba";
  EXPECT_EQ("aaaaaaabbbbcbbbc", solve(s.size(), s));
}

TEST(arc134b, 4) {
  string s = "snwfpfwipeusiwkzo";
  EXPECT_EQ("effwpnwipsusiwkzo", solve(s.size(), s));
}
