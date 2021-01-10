#include "abc025/c.cc"
#include <gtest/gtest.h>

TEST(abc025c, 1) {
    EXPECT_EQ(make_pair(15, 80),
              solve({{0, 15, 0}, {0, 0, 25}}, {{20, 10}, {0, 0}, {25, 0}}));
}

TEST(abc025c, 2) {
    EXPECT_EQ(make_pair(72, 107), solve({{18, 22, 15}, {11, 16, 17}},
                                        {{4, 25}, {22, 15}, {10, 4}}));
}
