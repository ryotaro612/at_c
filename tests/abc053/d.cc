#include "abc053/d.cc"
#include <gtest/gtest.h>

TEST(abc053d, 1){EXPECT_EQ(3, solve(5, {1, 2, 1, 3, 7}));}

TEST(abc053d, 2) {
    EXPECT_EQ(7, solve(15, {1, 3, 5, 2, 1, 3, 2, 8, 8, 6, 2, 6, 11, 1, 1}));
}
