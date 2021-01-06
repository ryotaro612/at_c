#include "abc187/d.cc"
#include "gtest/gtest.h"

TEST(abc187d, 1) { EXPECT_EQ(1, solve(4, {2, 2, 5, 1}, {1, 2, 1, 3})); }

TEST(abc187d, 2) { EXPECT_EQ(3, solve(5, {2, 2, 2, 2, 2}, {1, 1, 1, 1, 1})); }

TEST(abc187d, 3) { EXPECT_EQ(1, solve(1, {273}, {691})); }