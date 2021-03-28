#include "abc197/c.cc"
#include "gtest/gtest.h"

TEST(abc197c, 1) { EXPECT_EQ(2ll, solve(3, {1, 5, 7})); }

TEST(abc197c, 2) { EXPECT_EQ(0ll, solve(3, {10, 10, 10})); }

TEST(abc197c, 3) { EXPECT_EQ(0ll, solve(4, {1, 3, 3, 1})); }