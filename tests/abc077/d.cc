#include "abc077/d.cc"
#include <gtest/gtest.h>

TEST(abc077d, 1) { EXPECT_EQ(3, solve(6)); }
TEST(abc077d, 2) { EXPECT_EQ(5, solve(41)); }
TEST(abc077d, 3) { EXPECT_EQ(36, solve(79992)); }
