#include "abc190/d.cc"
#include "gtest/gtest.h"

TEST(abc190d, 1) { EXPECT_EQ(4, solve(12)); }

TEST(abc190d, 2) { EXPECT_EQ(2, solve(1)); }

TEST(abc190d, 3) { EXPECT_EQ(1920, solve(963761198400)); }
