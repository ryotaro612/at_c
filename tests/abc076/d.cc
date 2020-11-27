#include "abc076/d.cc"
#include <gtest/gtest.h>

TEST(abc076d, 1) {
    EXPECT_NEAR(2100.000000000000000, solve(1, {100}, {30}), 0.001);
}

TEST(abc076d, 2) {
    EXPECT_NEAR(2632.000000000000000, solve(2, {60, 50}, {34, 38}), 0.001);
}

TEST(abc076d, 3) {
    EXPECT_NEAR(76.000000000000000, solve(3, {12, 14, 2}, {6, 2, 7}), 0.001);
}

TEST(abc076d, 4) {
    EXPECT_NEAR(20.250000000000000000, solve(1, {9}, {10}), 0.001);
}