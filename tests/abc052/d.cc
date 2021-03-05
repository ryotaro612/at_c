#include "abc052/d.cc"
#include <gtest/gtest.h>

TEST(abc052d, 1) { EXPECT_EQ(11ll, solve(4, 2, 5, {1, 2, 5, 7})); }

TEST(abc052d, 2) {
    EXPECT_EQ(84ll, solve(7, 1, 100, {40, 43, 45, 105, 108, 115, 124}));
}

TEST(abc052d, 3) {
    EXPECT_EQ(12ll, solve(7, 1, 2, {24, 35, 40, 68, 72, 99, 103}));
}
