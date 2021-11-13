#include "abc048/b.cc"
#include <gtest/gtest.h>

TEST(abc048b, 1) { EXPECT_EQ(3, solve(4, 8, 2)); }

TEST(abc048b, 2) { EXPECT_EQ(6, solve(0, 5, 1)); }

TEST(abc048b, 3) { EXPECT_EQ(0, solve(9, 9, 2)); }

TEST(abc048b, 4) {
    EXPECT_EQ(333333333333333333, solve(1, 1000000000000000000, 3));
}
