#include "abc057/d.cc"
#include <gtest/gtest.h>

TEST(abc057d, 1) {
    auto res = solve(5, 2, 2, {1, 2, 3, 4, 5});
    EXPECT_NEAR(4.500000, res.first, 0.000001);
    EXPECT_EQ(1, res.second);
}

TEST(abc057d, 2) {
    auto res = solve(4, 2, 3, {10, 20, 10, 10});
    EXPECT_NEAR(15.000000, res.first, 0.000001);
    EXPECT_EQ(3, res.second);
}

TEST(abc057d, 3) {
    auto res = solve(5, 1, 5,
                     {1000000000000000, 999999999999999, 999999999999998,
                      999999999999997, 999999999999996});
    EXPECT_NEAR(1000000000000000.000000, res.first, 0.000001);
    EXPECT_EQ(1, res.second);
}

TEST(abc057d, 4) {
    auto res =
        solve(50, 1, 50, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    EXPECT_NEAR(1.000000, res.first, 0.000001);
    EXPECT_EQ(1125899906842623, res.second);
}
