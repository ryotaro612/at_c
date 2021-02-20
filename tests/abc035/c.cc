#include "abc035/c.cc"
#include <gtest/gtest.h>

TEST(abc035c, 1) {
    EXPECT_EQ("01010", solve(5, 4, {1, 2, 3, 1}, {4, 5, 3, 5}));
}

TEST(abc035c, 2) {
    EXPECT_EQ("10110000011110000000", solve(20, 8, {1, 4, 8, 3, 5, 19, 2, 4},
                                            {8, 13, 8, 18, 20, 20, 7, 9}));
}
