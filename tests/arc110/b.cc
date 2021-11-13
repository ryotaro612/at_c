#include "arc110/b.cc"
#include "gtest/gtest.h"

TEST(arc110b, 1) { EXPECT_EQ(9999999999ll, solve(4, "1011")); }

TEST(arc110b, 2) {
    EXPECT_EQ(9999999993ll, solve(22, "1011011011011011011011"));
}
