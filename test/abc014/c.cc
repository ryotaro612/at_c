#include "abc014/c.cc"
#include <gtest/gtest.h>

TEST(abc014c, 1) { EXPECT_EQ(3, solve(4, {0, 2, 2, 5}, {2, 3, 4, 6})); }

TEST(abc014c, 2) {
    EXPECT_EQ(4, solve(4, {1000000, 1000000, 0, 1},
                       {1000000, 1000000, 1000000, 1000000}));
}
