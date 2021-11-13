#include "abc039/d.cc"
#include <gtest/gtest.h>

TEST(abc039d, 1) {
    vector<string> ans = {"#...", "....", "....", "...#"};
    EXPECT_EQ(ans, solve(4, 4, {"##..", "##..", "..##", "..##"}));
}

TEST(abc039d, 2) {
    vector<string> ans = {"##..", "....", "...#", "...#"};
    EXPECT_EQ(ans, solve(4, 4, {"###.", "####", "..##", "..##"}));
}

TEST(abc039d, 3) {
    vector<string> ans = {};
    EXPECT_EQ(ans, solve(4, 4, {"###.", "##.#", "..##", "..##"}));
}
