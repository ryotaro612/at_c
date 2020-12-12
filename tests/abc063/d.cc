#include "abc063/d.cc"
#include <gtest/gtest.h>

TEST(abc063d, 1) { EXPECT_EQ(2, solve(4, 5, 3, {8, 7, 4, 2})); }

TEST(abc063d, 2) { EXPECT_EQ(4, solve(2, 10, 4, {20, 20})); }

TEST(abc063d, 3) {
    EXPECT_EQ(800000000, solve(5, 2, 1,
                               {900000000, 900000000, 1000000000, 1000000000,
                                1000000000}));
}
