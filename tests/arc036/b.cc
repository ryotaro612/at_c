#include "arc036/b.cc"
#include "gtest/gtest.h"

TEST(arc036b, 1) { EXPECT_EQ(4, solve(6, {4, 5, 1, 6, 9, 7})); }

TEST(arc036b, 2) { EXPECT_EQ(7, solve(7, {90, 70, 50, 30, 20, 10, 5})); }
