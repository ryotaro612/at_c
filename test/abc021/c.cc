#include "abc021/c.cc"
#include <gtest/gtest.h>

TEST(abc021c, 1) {
    EXPECT_EQ(4, solve(7, 1, 7, 8, {1, 1, 4, 4, 4, 4, 7, 7},
                       {2, 3, 2, 3, 5, 6, 5, 6}));
}

TEST(abc021c, 2) {
    EXPECT_EQ(2, solve(7, 1, 7, 9, {1, 1, 4, 4, 4, 4, 7, 7, 4},
                       {2, 3, 2, 3, 5, 6, 5, 6, 7}));
}
