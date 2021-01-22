#include "abc054/c.cc"
#include <gtest/gtest.h>

TEST(abc054c, 1) { EXPECT_EQ(2, solve(3, 3, {1, 1, 2}, {2, 3, 3})); }

TEST(abc054c, 2) {
    EXPECT_EQ(1, solve(7, 7, {1, 2, 3, 4, 4, 5, 6}, {3, 7, 4, 5, 6, 6, 7}));
}