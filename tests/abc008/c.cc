#include "abc008/c.cc"
#include <gtest/gtest.h>

TEST(abc008c, 1) { EXPECT_NEAR(2.166666666667, solve(3, {2, 4, 8}), 0.00001); }

TEST(abc008c, 2) {
    EXPECT_NEAR(2.000000000000, solve(4, {5, 5, 5, 5}), 0.00001);
}

TEST(abc008c, 3) {
    EXPECT_NEAR(3.100000000000, solve(5, {2, 3, 2, 6, 12}), 0.00001);
}