#include "abc188/e.cc"
#include "gtest/gtest.h"

TEST(abc188e, 1) {
    EXPECT_EQ(3ll, solve(4, 3, {2, 3, 1, 5}, {2, 1, 1}, {4, 2, 3}));
}

TEST(abc188e, 2) {
    EXPECT_EQ(10ll, solve(5, 5, {13, 8, 3, 15, 18}, {2, 1, 4, 2, 1},
                          {4, 2, 5, 3, 3}));
}

TEST(abc188e, 3) { EXPECT_EQ(-99ll, solve(3, 1, {1, 100, 1}, {2}, {3})); }