#include "abc050/d.cc"
#include <gtest/gtest.h>

TEST(abc050d, 1) { EXPECT_EQ(5, solve(3)); }

TEST(abc050d, 2) { EXPECT_EQ(52277, solve(1422)); }

TEST(abc050d, 3) { EXPECT_EQ(787014179, solve(1000000000000000000LL)); }