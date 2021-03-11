#include "panasonic2020/d.cc"
#include "gtest/gtest.h"

TEST(panasonic2020d, 1) {
    vector<string> ans = {"a"};
    EXPECT_EQ(ans, solve(1));
}

TEST(panasonic2020d, 2) {
    vector<string> ans = {"aa", "ab"};
    EXPECT_EQ(ans, solve(2));
}