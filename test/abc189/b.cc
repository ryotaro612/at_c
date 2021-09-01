#include "abc189/b.cc"
#include "gtest/gtest.h"

TEST(abc189b, 1) { EXPECT_EQ(2, solve(2, 15, {200, 350}, {5, 3})); }

TEST(abc189b, 2) { EXPECT_EQ(2, solve(2, 10, {200, 350}, {5, 3})); }

TEST(abc189b, 3) {
    EXPECT_EQ(-1, solve(3, 1000000, {1000, 1000, 1000}, {100, 100, 100}));
}
