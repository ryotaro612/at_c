#include "abc161/f.cc"
#include "gtest/gtest.h"

TEST(f, 1) { EXPECT_EQ(3ll, solve(6ll)); }

TEST(f, 2) { EXPECT_EQ(13ll, solve(3141ll)); }

TEST(f, 3) { EXPECT_EQ(9ll, solve(314159265358ll)); }
