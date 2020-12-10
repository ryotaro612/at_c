#include "abc065/d.cc"
#include <gtest/gtest.h>

TEST(abc065d, 1) { EXPECT_EQ(3, solve(3, {1, 3, 7}, {5, 9, 8})); }

TEST(abc065d, 2) {
    EXPECT_EQ(8, solve(6, {8, 4, 12, 18, 13, 7}, {3, 9, 19, 1, 5, 6}));
}
