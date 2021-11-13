#include "sumitrust2019/d.cc"
#include "gtest/gtest.h"

TEST(sumitrust2019d, 1) { EXPECT_EQ(3ll, solve(4, "0224")); }

TEST(sumitrust2019d, 2) { EXPECT_EQ(17ll, solve(6, "123123")); }

TEST(sumitrust2019d, 3) { EXPECT_EQ(329ll, solve(19, "3141592653589793238")); }