#include "abc013/c.cc"
#include <gtest/gtest.h>

TEST(abc013c, 1) { EXPECT_EQ(160, solve(4, 5, 100, 4, 60, 1, 4)); }

TEST(abc013c, 2) { EXPECT_EQ(20000, solve(10, 1, 5000, 2, 2000, 1, 300)); }

TEST(abc013c, 3) { EXPECT_EQ(650, solve(9, 23, 170, 8, 120, 5, 12)); }

TEST(abc013c, 4) {
    EXPECT_EQ(2818162, solve(653, 314159, 6728, 123456, 5141, 41928, 222222));
}
