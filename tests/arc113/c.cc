#include "arc113/c.cc"
#include "gtest/gtest.h"

TEST(arc113c, 1) { EXPECT_EQ(3, solve("accept")); }

TEST(arc113c, 2) { EXPECT_EQ(0, solve("atcoder")); }

TEST(arc113c, 3) { EXPECT_EQ(16, solve("anerroroccurred")); }
