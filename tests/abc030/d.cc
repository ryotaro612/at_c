#include "abc030/d.cc"
#include <gtest/gtest.h>

TEST(abc030d, 1) { EXPECT_EQ(3, solve(6, 4, "5", {2, 3, 1, 2, 6, 5})); }

TEST(abc030d, 2) {
    EXPECT_EQ(1, solve(4, 1, "100000000000000000000", {2, 3, 4, 1}));
}

TEST(abc030d, 3) { EXPECT_EQ(2, solve(8, 1, "1", {2, 3, 4, 5, 3, 2, 4, 5})); }