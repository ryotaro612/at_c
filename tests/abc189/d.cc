#include "abc189/d.cc"
#include "gtest/gtest.h"

TEST(abc189d, 1) { EXPECT_EQ(5, solve(2, {"AND", "OR"})); }

TEST(abc189d, 2) { EXPECT_EQ(63, solve(5, {"OR", "OR", "OR", "OR", "OR"})); }
