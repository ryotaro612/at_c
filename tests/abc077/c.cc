#include "abc077/c.cc"
#include <gtest/gtest.h>

TEST(abc077c, 1) { EXPECT_EQ(3, solve(2, {1, 5}, {2, 4}, {3, 6})); }

TEST(abc077c, 2) { EXPECT_EQ(27, solve(3, {1, 1, 1}, {2, 2, 2}, {3, 3, 3})); }

TEST(abc077c, 3) {
    EXPECT_EQ(87, solve(6, {3, 14, 159, 2, 6, 53}, {58, 9, 79, 323, 84, 6},
                        {2643, 383, 2, 79, 50, 288}));
}
