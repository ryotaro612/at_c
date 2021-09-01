#include "abc071/d.cc"
#include <gtest/gtest.h>

TEST(abc071d, 1) { EXPECT_EQ(6, solve(3, "aab", "ccb")); }

TEST(abc071d, 2) { EXPECT_EQ(3, solve(1, "Z", "Z")); }

TEST(abc071d, 3) {
    EXPECT_EQ(958681902,
              solve(52, "RvvttdWIyyPPQFFZZssffEEkkaSSDKqcibbeYrhAljCCGGJppHHn",
                    "RLLwwdWIxxNNQUUXXVVMMooBBaggDKqcimmeYrhAljOOTTJuuzzn"));
}

TEST(abc071d, 4) { EXPECT_EQ(6, solve(3, "abb", "acc")); }
TEST(abc071d, 5) { EXPECT_EQ(6, solve(4, "abbf", "accf")); }