#include "abc060/d.cc"
#include <gtest/gtest.h>

TEST(abc060d, 1) { EXPECT_EQ(11, solve(4, 6, {2, 3, 4, 3}, {1, 4, 10, 4})); }

TEST(abc060d, 2) { EXPECT_EQ(13, solve(4, 6, {2, 3, 4, 3}, {1, 7, 10, 6})); }

TEST(abc060d, 3) {
    EXPECT_EQ(400, solve(4, 10, {1, 1, 1, 1}, {100, 100, 100, 100}));
}

TEST(abc060d, 4) {
    EXPECT_EQ(0, solve(4, 1, {10, 10, 10, 10}, {100, 100, 100, 100}));
}