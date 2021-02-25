#include "abc057/c.cc"
#include <gtest/gtest.h>

TEST(abc057c, 1) { EXPECT_EQ(3, solve(10000ll)); }

TEST(abc057c, 2) { EXPECT_EQ(7, solve(1000003ll)); }

TEST(abc057c, 3) { EXPECT_EQ(6, solve(9876543210ll)); }