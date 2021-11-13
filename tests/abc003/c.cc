#include "abc003/c.cc"
#include <gtest/gtest.h>

TEST(abc003c, 1) {
    auto res = solve(2, 2, {1000, 1500});
    EXPECT_NEAR(1000.000000, res, 0.00001);
}

TEST(abc003c, 2) {
    auto res = solve(2, 1, {1000, 1500});
    EXPECT_NEAR(750, res, 0.00001);
}

TEST(abc003c, 3) {
    auto res = solve(10, 5, {2604,2281,3204,2264,2200,2650,2229,2461,2439,2211});
    EXPECT_NEAR(2820.031250000, res, 0.00001);
}
