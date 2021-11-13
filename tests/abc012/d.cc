#include "abc012/d.cc"
#include <gtest/gtest.h>

TEST(abc012d, 1) { EXPECT_EQ(10ll, solve(3, 2, {1, 2}, {2, 3}, {10, 10})); }

TEST(abc012d, 2) {
    EXPECT_EQ(26ll, solve(5, 5, {1, 2, 3, 4, 5}, {2, 3, 4, 5, 1},
                          {12, 14, 7, 9, 18}));
}

TEST(abc012d, 3) {
    EXPECT_EQ(1ll, solve(4, 6, {1, 2, 3, 4, 1, 4}, {2, 3, 4, 1, 3, 2},
                         {1, 1, 1, 1, 1, 1}));
}
