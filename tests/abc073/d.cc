#include "abc073/d.cc"
#include <gtest/gtest.h>

TEST(abc073d, 1) {
    EXPECT_EQ(2, solve(3, 3, 3, {1, 2, 3}, {1, 2, 3}, {2, 3, 1}, {1, 1, 4}));
}

TEST(abc073d, 2) {
    EXPECT_EQ(4, solve(3, 3, 2, {1, 3}, {2, 1, 1}, {3, 3, 2}, {2, 6, 2}));
}

TEST(abc073d, 3) {
    EXPECT_EQ(3, solve(4, 6, 3, {2, 3, 4}, {1, 2, 4, 1, 4, 3},
                       {2, 3, 3, 4, 2, 1}, {4, 3, 1, 1, 2, 6}));
}