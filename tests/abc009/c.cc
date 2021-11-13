#include "abc009/c.cc"
#include <gtest/gtest.h>

TEST(abc009c, 1) {
    EXPECT_EQ("abc", solve(3, 2, "abc"));
}

TEST(abc009c, 2) { EXPECT_EQ("actoder", solve(7, 2, "atcoder")); }

TEST(abc009c, 3) { EXPECT_EQ("acdeort", solve(7, 7, "atcoder")); }

TEST(abc009c, 4) { EXPECT_EQ("dehloworll", solve(10, 3, "helloworld")); }

TEST(abc009c, 5) { EXPECT_EQ("ba", solve(2, 0, "ba")); }

TEST(abc009c, 6) { EXPECT_EQ("ba", solve(2, 1, "ba")); }

TEST(abc009c, 7) { EXPECT_EQ("ab", solve(2, 2, "ba")); }

TEST(abc009c, 8) { EXPECT_EQ("abaabb", solve(6, 2, "bbaaba")); }