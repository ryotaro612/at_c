#include "abc044/c.cc"
#include <gtest/gtest.h>

TEST(abc044c, 1) { EXPECT_EQ(5, solve(4, 8, {7, 9, 8, 9})); }

TEST(abc044c, 2) { EXPECT_EQ(0, solve(3, 8, {6, 6, 9})); }

TEST(abc044c, 3) { EXPECT_EQ(19, solve(8, 5, {3, 6, 2, 8, 7, 6, 5, 9})); }

TEST(abc044c, 4) {
    EXPECT_EQ(8589934591,
              solve(33, 3, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}));
}
