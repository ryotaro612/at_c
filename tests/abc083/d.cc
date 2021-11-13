#include "abc083/d.cc"
#include <gtest/gtest.h>

TEST(abc083d, 1) {
    EXPECT_EQ(2, solve("010"));
}

TEST(abc083d, 2) {
    EXPECT_EQ(8, solve("100000000"));
}

TEST(abc083d, 3) {
    EXPECT_EQ(4, solve("00001111"));
}