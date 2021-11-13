#include "abc032/c.cc"
#include <gtest/gtest.h>

TEST(abc032c, 1) { EXPECT_EQ(4, solve(7, 6, {4, 3, 1, 1, 2, 10, 2})); }

TEST(abc032c, 2) { EXPECT_EQ(6, solve(6, 10, {10, 10, 10, 10, 0, 10})); }

TEST(abc032c, 3) { EXPECT_EQ(0, solve(6, 9, {10, 10, 10, 10, 10, 10})); }

TEST(abc032c, 4) { EXPECT_EQ(0, solve(4, 0, {1, 2, 3, 4})); }
