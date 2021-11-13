#include "abc191/d.cc"
#include "gtest/gtest.h"

TEST(abc191d, 1) { EXPECT_EQ(3, solve(0.2, 0.8, 1.1)); }

TEST(abc191d, 2) { EXPECT_EQ(5, solve(100, 100, 1)); }

TEST(abc191d, 3) {
    EXPECT_EQ(31415920098, solve(42782.4720, 31949.0192, 99999.99));
}