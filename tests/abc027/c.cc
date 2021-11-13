#include "abc027/c.cc"
#include <gtest/gtest.h>

TEST(abc027c, 1) { EXPECT_EQ("Aoki", solve(1)); }

TEST(abc027c, 2) { EXPECT_EQ("Takahashi", solve(5)); }

TEST(abc027c, 3) { EXPECT_EQ("Aoki", solve(7)); }

TEST(abc027c, 4) { EXPECT_EQ("Takahashi", solve(10)); }

TEST(abc027c, 5) { EXPECT_EQ("Aoki", solve(123456789123456789)); }