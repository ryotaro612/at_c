#include <gtest/gtest.h>
#include "abc235/d.cc"
/*
TEST(abc235d, 1) {
    int res = solve(3, 72);
    EXPECT_EQ(4, res);
}

TEST(abc235d, 2) {
    int res = solve(2, 5);
    EXPECT_EQ(-1, res);
}

TEST(abc235d, 3) {
    int res = solve(2, 611);
    EXPECT_EQ(12, res);
}
TEST(abc235d, 4) {
    int res = solve(2, 767090);
    EXPECT_EQ(111, res);
}
*/

TEST(abc235d, 1) {
    int res = solve2(3, 72);
    EXPECT_EQ(4, res);
}
TEST(abc235d, 2) {
    int res = solve2(2, 5);
    EXPECT_EQ(-1, res);
}

TEST(abc235d, 3) {
    int res = solve2(2, 611);
    EXPECT_EQ(12, res);
}
TEST(abc235d, 4) {
    int res = solve2(2, 767090);
    EXPECT_EQ(111, res);
}