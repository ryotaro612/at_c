#include "abc075/c.cc"
#include <gtest/gtest.h>

TEST(abc075c, 1) {
    EXPECT_EQ(4, solve(7, 7, {1, 2, 3, 4, 4, 5, 6}, {3, 7, 4, 5, 6, 6, 7}));
}

TEST(abc075c, 2) { EXPECT_EQ(0, solve(3, 3, {1, 1, 2}, {2, 3, 3})); }

TEST(abc075c, 3) {
    EXPECT_EQ(5, solve(6, 5, {1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}));
}
