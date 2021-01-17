#include "abc105/c.cc"
#include <gtest/gtest.h>

TEST(abc105c, 1) { EXPECT_EQ("1011", solve(-9)); }

TEST(abc105c, 2) { EXPECT_EQ("11000101011001101110100010101", solve(123456789)); }

TEST(abc105c, 3) { EXPECT_EQ("0", solve(0)); }

//TEST(abc105c, 4) { EXPECT_EQ("0", solve(7)); }