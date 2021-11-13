#include "abc177/e.cc"
#include "gtest/gtest.h"

TEST(abc177e, 1) { EXPECT_EQ("pairwise", solve(3, {3, 4, 5})); }

TEST(abc177e, 2) { EXPECT_EQ("setwise", solve(3, {6, 10, 15})); }

TEST(abc177e, 3) { EXPECT_EQ("not", solve(3, {6, 10, 16})); }