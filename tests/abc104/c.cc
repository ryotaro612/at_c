#include "abc104/c.cc"
#include <gtest/gtest.h>

TEST(abc104c, 1) { EXPECT_EQ(3, solve(2, 700, {3, 5}, {500, 800})); }

TEST(abc104c, 2) { EXPECT_EQ(7, solve(2, 2000, {3, 5}, {500, 800})); }

TEST(abc104c, 3) { EXPECT_EQ(2, solve(2, 400, {3, 5}, {500, 800})); }

TEST(abc104c, 4) {
    EXPECT_EQ(66, solve(5, 25000, {20, 40, 50, 30, 1},
                        {1000, 1000, 1000, 1000, 1000}));
}
