#include "abc001/c.cc"
#include <gtest/gtest.h>

TEST(abc001c, 1) {
    pair<string, int> res = solve(2750, 628);
    EXPECT_EQ("W", res.first);
    EXPECT_EQ(5, res.second);
}

TEST(abc001c, 2) {
    pair<string, int> res = solve(161, 8);
    EXPECT_EQ("C", res.first);
    EXPECT_EQ(0, res.second);
}

TEST(abc001c, 3) {
    pair<string, int> res = solve(3263, 15);
    EXPECT_EQ("NNW", res.first);
    EXPECT_EQ(1, res.second);
}

TEST(abc001c, 4) {
    pair<string, int> res = solve(1462, 1959);
    EXPECT_EQ("SE", res.first);
    EXPECT_EQ(12, res.second);
}

TEST(abc001c, 5) {
    pair<string, int> res = solve(1687, 1029);
    EXPECT_EQ("SSE", res.first);
    EXPECT_EQ(8, res.second);
}

TEST(abc001c, 6) {
    pair<string, int> res = solve(2587, 644);
    EXPECT_EQ("WSW", res.first);
    EXPECT_EQ(5, res.second);
}

TEST(abc001c, 7) {
    pair<string, int> res = solve(113, 201);
    EXPECT_EQ("NNE", res.first);
    EXPECT_EQ(3, res.second);
}

TEST(abc001c, 8) {
    pair<string, int> res = solve(2048, 16);
    EXPECT_EQ("SSW", res.first);
    EXPECT_EQ(1, res.second);
}