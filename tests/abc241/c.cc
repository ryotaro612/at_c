#include "abc241/c.cc"
#include <gtest/gtest.h>

TEST(abc241c, 1) {
  vector<string> sv = {"......", //
                       ".#....", //
                       "..#...", //
                       "......", //
                       "....#.", //
                       "......"};
  EXPECT_EQ("No", solve(sv.size(), sv));
}

TEST(abc241c, 2) {
  vector<string> sv = {"......", //
                       ".#....", //
                       "..#...", //
                       "...#..", //
                       "....#.", //
                       "......"};
  EXPECT_EQ("Yes", solve(sv.size(), sv));
}
