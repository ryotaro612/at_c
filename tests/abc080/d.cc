#include "abc080/d.cc"
#include <gtest/gtest.h>

TEST(abc080d, 1) {
    EXPECT_EQ(2, solve(3, 2, {1, 7, 8}, {7, 8, 12}, {2, 1, 1}));
}

TEST(abc080d, 2) { EXPECT_EQ(3, solve(3, 4, {1, 3, 1}, {3, 4, 4}, {2, 4, 3})); }

TEST(abc080d, 3) {
    EXPECT_EQ(2, solve(9, 4, {56, 33, 89, 32, 67, 49, 31, 70, 11},
                       {60, 37, 90, 43, 68, 51, 32, 71, 12},
                       {4, 2, 3, 1, 3, 3, 3, 1, 3}));
}
