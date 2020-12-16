#include "abc061/d.cc"
#include <gtest/gtest.h>

TEST(abc061d, 1) {

    EXPECT_EQ(7, solve(3, 3, {1, 2, 1}, {2, 3, 3}, {4, 3, 5}).first);
}

TEST(abc061d, 2) {
    EXPECT_EQ("inf", solve(2, 2, {1, 2}, {2, 1}, {1, 1}).second);
}

TEST(abc061d, 3) {
    EXPECT_EQ(-5000000000, solve(6, 5, {1, 2, 3, 4, 5}, {2, 3, 4, 5, 6},
                                   {-1000000000, -1000000000, -1000000000,
                                    -1000000000, -1000000000})
                                 .first);
}
