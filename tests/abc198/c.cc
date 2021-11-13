#include "abc198/c.cc"
#include "gtest/gtest.h"

TEST(abc198c, 1) { EXPECT_EQ(3, solve(5ll, 15ll, 0ll)); }

TEST(abc198c, 2) { EXPECT_EQ(3, solve(5ll, 11ll, 0ll)); }

TEST(abc198c, 3) { EXPECT_EQ(2, solve(3ll, 4ll, 4ll)); }