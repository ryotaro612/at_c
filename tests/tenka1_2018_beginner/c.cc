#include "tenka1_2018_beginner/c.cc"
#include "gtest/gtest.h"

TEST(tenka1_2018_beginnerc, 1) { EXPECT_EQ(21ll, solve(5, {6, 8, 1, 2, 3})); }

TEST(tenka1_2018_beginnerc, 2) {
    EXPECT_EQ(25ll, solve(6, {3, 1, 4, 1, 5, 9}));
}

TEST(tenka1_2018_beginnerc, 3) { EXPECT_EQ(8ll, solve(3, {5, 5, 1})); }
