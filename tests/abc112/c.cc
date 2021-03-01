#include "abc112/c.cc"
#include "gtest/gtest.h"

TEST(abc112c, 1) {
    chokudai res = solve(4, {2, 2, 1, 3}, {3, 1, 2, 2}, {5, 5, 5, 5});
    EXPECT_EQ(2, res.x);
    EXPECT_EQ(2, res.y);
    EXPECT_EQ(6, res.h);
}

TEST(abc112c, 2) {
    chokudai res = solve(2, {0, 1}, {0, 1}, {100, 98});
    EXPECT_EQ(0, res.x);
    EXPECT_EQ(0, res.y);
    EXPECT_EQ(100, res.h);
}

TEST(abc112c, 3) {
    chokudai res = solve(3, {99, 100, 99}, {1, 1, 0}, {191, 192, 192});
    EXPECT_EQ(100, res.x);
    EXPECT_EQ(0, res.y);
    EXPECT_EQ(193, res.h);
}
