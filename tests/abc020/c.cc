#include "abc020/c.cc"
#include <gtest/gtest.h>

TEST(abc020c, 1) { EXPECT_EQ(8, solve(2, 3, 10, {"S##", ".#G"})); }

TEST(abc020c, 2) { EXPECT_EQ(3, solve(3, 4, 7, {"S##G", ".##.", "..#."})); }

TEST(abc020c, 3) {
    EXPECT_EQ(199999999,
              solve(4, 4, 1000000000, {"S###", "####", "####", "###G"}));
}
