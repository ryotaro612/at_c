#include "abc196/c.cc"
#include "gtest/gtest.h"

TEST(abc196c, 1) { EXPECT_EQ(3, solve(33ll)); }

TEST(abc196c, 2) { EXPECT_EQ(13, solve(1333ll)); }

TEST(abc196c, 3) { EXPECT_EQ(999, solve(10000000ll)); }
