#include "abc005/c.cc"
#include <gtest/gtest.h>

TEST(abc005c, 1) { EXPECT_EQ("yes", solve(1, 3, {1, 2, 3}, 3, {2, 3, 4})); }

TEST(abc005c, 2) { EXPECT_EQ("no", solve(1, 3, {1, 2, 3}, 3, {2, 3, 5})); }

TEST(abc005c, 3) {
    EXPECT_EQ("no",
              solve(1, 3, {1, 2, 3}, 10, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}

TEST(abc005c, 4) { EXPECT_EQ("no", solve(1, 3, {1, 2, 3}, 3, {1, 2, 2})); }

TEST(abc005c, 5) {
    EXPECT_EQ("yes", solve(2, 5, {1, 3, 6, 10, 15}, 3, {4, 8, 16}));
}
