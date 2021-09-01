#include "abc194/d.cc"
#include "gtest/gtest.h"

TEST(abc194d, 1) { EXPECT_NEAR(2.0000000000, solve(2ll), 0.000001); }
TEST(abc194d, 2) { EXPECT_NEAR(4.5000000000, solve(3ll), 0.000001); }