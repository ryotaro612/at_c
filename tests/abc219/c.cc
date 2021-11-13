#include "abc219/c.cc"
#include <gtest/gtest.h>

TEST(abc219c, 1) {
    vector<string> s = {"abx", "bzz", "bzy", "caa"};
    vector<string> ans = {"bzz", "bzy", "abx", "caa"};
    EXPECT_EQ(ans, solve("bacdefghijklmnopqrstuvwxzy", 4, s));
}

TEST(abc219c, 2) {
    vector<string> s = {"a", "ab", "abc", "ac", "b"};
    vector<string> ans = {"b", "a", "ac", "ab", "abc"};
    EXPECT_EQ(ans, solve("zyxwvutsrqponmlkjihgfedcba", 5, s));
}
