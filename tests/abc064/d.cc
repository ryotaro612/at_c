#include "abc064/d.cc"
#include <gtest/gtest.h>

TEST(abc064d, 1) { EXPECT_EQ("(())", solve(3, "())")); }

TEST(abc064d, 2) { EXPECT_EQ("(((()))())", solve(6, ")))())")); }

TEST(abc064d, 3) { EXPECT_EQ("(((())))(((())))", solve(8, "))))((((")); }