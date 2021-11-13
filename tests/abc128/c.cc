#include "abc128/c.cc"
#include "gtest/gtest.h"

TEST(abc128c, 1) { EXPECT_EQ(1, solve(2, 2, {2, 1}, {{1, 2}, {2}}, {0, 1})); }

TEST(abc128c, 2) {
    EXPECT_EQ(0, solve(2, 3, {2, 1, 1}, {{1, 2}, {1}, {2}}, {0, 0, 1}));
}

TEST(abc128c, 3) {
    EXPECT_EQ(8, solve(5, 2, {3, 2}, {{1, 2, 5}, {2, 3}}, {1, 0}));
}