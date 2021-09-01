#include "tenka1_2019_beginner/c.cc"
#include "gtest/gtest.h"

TEST(tenka1_2019_beginnerc, 1) { EXPECT_EQ(1, solve(3, "#.#")); }

TEST(tenka1_2019_beginnerc, 2) { EXPECT_EQ(2, solve(5, "#.##.")); }

TEST(tenka1_2019_beginnerc, 3) { EXPECT_EQ(0, solve(9, ".........")); }