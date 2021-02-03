#include "abc018/c.cc"
#include <gtest/gtest.h>

TEST(abc018c, 1) {
    EXPECT_EQ(3, solve(4, 5, 2, {"xoooo", "oooox", "ooooo", "oxxoo"}));
}

TEST(abc018c, 2) {
    EXPECT_EQ(0, solve(4, 5, 2, {"ooooo", "oxoox", "oooox", "oxxoo"}));
}

TEST(abc018c, 3) {
    EXPECT_EQ(4, solve(8, 6, 3,
                       {"oooooo", "oooooo", "oooooo", "oooooo", "oxoooo",
                        "oooooo", "oooooo", "oooooo"}));
}
