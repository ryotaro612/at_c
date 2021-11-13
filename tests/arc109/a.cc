#include "arc109/a.cc"
#include "gtest/gtest.h"

TEST(arc109a, 1) { EXPECT_EQ(1, solve(2, 1, 1, 5)); }

TEST(arc109a, 2) { EXPECT_EQ(101, solve(1, 2, 100, 1)); }

TEST(arc109a, 3) { EXPECT_EQ(199, solve(1, 100, 1, 100)); }