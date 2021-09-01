#include "abc062/c.cc"
#include <gtest/gtest.h>

TEST(abc062c, 1) { EXPECT_EQ(0, solve(3, 5)); }

TEST(abc062c, 2) { EXPECT_EQ(2, solve(4, 5)); }

TEST(abc062c, 3) { EXPECT_EQ(4, solve(5, 5)); }

TEST(abc062c, 4) { EXPECT_EQ(1, solve(100000, 2)); }

TEST(abc062c, 5) { EXPECT_EQ(50000, solve(100000, 100000)); }
