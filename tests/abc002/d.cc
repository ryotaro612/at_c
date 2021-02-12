#include "abc002/d.cc"
#include <gtest/gtest.h>

TEST(abc002d, 1) { EXPECT_EQ(3, solve(5, 3, {1, 2, 1}, {2, 3, 3})); }

TEST(abc002d, 2) { EXPECT_EQ(2, solve(5, 3, {1, 2, 3}, {2, 3, 4})); }

TEST(abc002d, 3) {
    EXPECT_EQ(4, solve(7, 9, {1, 1, 2, 4, 4, 4, 5, 5, 6},
                       {2, 3, 3, 5, 6, 7, 6, 7, 7}));
}

TEST(abc002d, 4) { EXPECT_EQ(1, solve(12, 0, {}, {})); }
