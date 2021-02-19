#include "abc019/c.cc"
#include <gtest/gtest.h>

TEST(abc019c, 1) {
    EXPECT_EQ(2, solve(3, {1, 2, 3}));
}

TEST(abc019c, 2) {
    EXPECT_EQ(1, solve(4, {2, 4, 8, 16}));
}

TEST(abc019c, 3) {
    EXPECT_EQ(4, solve(4, {2, 3, 5, 7}));
}