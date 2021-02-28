#include "abc193/c.cc"
#include "gtest/gtest.h"

TEST(abc193c, 1) { EXPECT_EQ(6ll, solve(8ll)); }

TEST(abc193c, 2) { EXPECT_EQ(99634ll, solve(100000ll)); }