#include "abc023/c.cc"
#include <gtest/gtest.h>

TEST(abc023c, 1) {
    EXPECT_EQ(5, solve(3, 5, 3, 5, {1, 2, 2, 3, 3}, {2, 1, 5, 2, 5}));
}

TEST(abc023c, 2) {
    EXPECT_EQ(0, solve(7, 3, 1, 4, {3, 3, 4, 4}, {2, 3, 2, 3}));
}

TEST(abc023c, 3) {
    EXPECT_EQ(20, solve(5, 5, 2, 5, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}));
}