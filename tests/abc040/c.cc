#include "abc040/c.cc"
#include <gtest/gtest.h>

TEST(abc040c, 1) { EXPECT_EQ(40, solve(4, {100, 150, 130, 120})); }

TEST(abc040c, 2) { EXPECT_EQ(40, solve(4, {100, 125, 80, 110})); }

TEST(abc040c, 3) {
    EXPECT_EQ(310, solve(9, {314, 159, 265, 358, 979, 323, 846, 264, 338}));
}
