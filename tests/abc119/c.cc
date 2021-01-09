#include "abc119/c.cc"
#include "gtest/gtest.h"

TEST(abc119c, 1) { EXPECT_EQ(23, solve(5, 100, 90, 80, {98, 40, 30, 21, 80})); }

TEST(abc119c, 2) {
    EXPECT_EQ(0, solve(8, 100, 90, 80, {100, 100, 90, 90, 90, 80, 80, 80}));
}

TEST(abc119c, 3) {
    EXPECT_EQ(243, solve(8, 1000, 800, 100,
                         {300, 333, 400, 444, 500, 555, 600, 666}));
}
