#include "abc238/c.cc"
#include <gtest/gtest.h>

TEST(abc238c, 1) { EXPECT_EQ(73ll, solve(16)); }

TEST(abc238c, 2) { EXPECT_EQ(13870ll, solve(238ll)); }

TEST(abc238c, 3) { EXPECT_EQ(762062362ll, solve(999999999999999999ll)); }
