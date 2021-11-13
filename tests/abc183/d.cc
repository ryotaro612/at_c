#include "abc183/d.cc"
#include "gtest/gtest.h"

TEST(abc183d, 1) {
    EXPECT_EQ("No", solve(4, 10, {1, 2, 3, 2}, {3, 4, 10, 4}, {5, 4, 6, 1}));
}

TEST(abc183d, 2) {
    EXPECT_EQ("Yes", solve(4, 10, {1, 2, 3, 2}, {3, 4, 10, 3}, {5, 4, 6, 1}));
}

TEST(abc183d, 3) {
    EXPECT_EQ("Yes", solve(6, 1000000000, {0, 2, 20, 200, 2000, 20000},
                           {200000, 20, 200, 2000, 20000, 200000},
                           {999999999, 1, 1, 1, 1, 1}));
}