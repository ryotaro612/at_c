#include "abc179/e.cc"
#include "gtest/gtest.h"

TEST(abc179e, 1) { EXPECT_EQ(1369, solve(6, 2, 1001)); }

TEST(abc179e, 2) { EXPECT_EQ(6, solve(1000, 2, 16)); }

TEST(abc179e, 3) {
    EXPECT_EQ(492443256176507ll, solve(10000000000ll, 10ll, 99959ll));
}
