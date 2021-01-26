#include "abc034/c.cc"
#include <gtest/gtest.h>

TEST(abc034c, 1) { EXPECT_EQ(10, solve(4, 3)); }

TEST(abc034c, 2) { EXPECT_EQ(210368064, solve(123, 456)); }