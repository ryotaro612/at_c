#include "abc189/d.cc"
#include "gtest/gtest.h"

TEST(abc189d, 1) { EXPECT_EQ(5, solve(2, {"AND", "OR"})); }

TEST(abc189d, 2) { EXPECT_EQ(63, solve(5, {"OR", "OR", "OR", "OR", "OR"})); }

TEST(abc189d, 3) { EXPECT_EQ(3, solve(1, {"OR"})); }

TEST(abc189d, 4) { EXPECT_EQ(1, solve(1, {"AND"})); }

TEST(abc189d, 5) { EXPECT_EQ(5, solve(2, {"AND", "OR"})); }
