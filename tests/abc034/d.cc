#include "abc034/d.cc"
#include <gtest/gtest.h>

TEST(abc034d, 1) {
    EXPECT_NEAR(25.000000000, solve(3, 2, {100, 300, 200}, {15, 20, 30}),
                0.001);
}