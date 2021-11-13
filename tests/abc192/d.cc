#include "abc192/d.cc"
#include "gtest/gtest.h"

TEST(abc192d, 1) { EXPECT_EQ(2, solve("22", 10ll)); }

TEST(abc192d, 2) { EXPECT_EQ(3, solve("999", 1500ll)); }

TEST(abc192d, 3) {
    EXPECT_EQ(
        1, solve("100000000000000000000000000000000000000000000000000000000000",
                 1000000000000000000ll));
}
