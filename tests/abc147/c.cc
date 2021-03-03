#include "abc147/c.cc"
#include "gtest/gtest.h"

using namespace std;

TEST(abc147c, 1) {
    EXPECT_EQ(2, solve(3, {1, 1, 1}, {{2}, {1}, {2}}, {{1}, {1}, {0}}));
}

TEST(abc147c, 2) {
    EXPECT_EQ(0, solve(3, {2, 2, 2}, {{2, 3}, {3, 1}, {1, 2}},
                       {{1, 0}, {1, 0}, {1, 0}}));
}

TEST(abc147c, 3) { EXPECT_EQ(1, solve(2, {1, 1}, {{2}, {1}}, {{0}, {0}})); }