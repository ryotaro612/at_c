#include "arc113/a.cc"
#include "gtest/gtest.h"

TEST(arc113a, 1) { EXPECT_EQ(4, solve(2)); }

TEST(arc113a, 2) { EXPECT_EQ(53, solve(10)); }

TEST(arc113a, 3) { EXPECT_EQ(1937281, solve(31415)); }