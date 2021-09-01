#include "arc115/a.cc"
#include "gtest/gtest.h"

TEST(arc115a, 1) { EXPECT_EQ(2, solve(3, 2, {"00", "01", "10"})); }

TEST(arc115a, 2) {
    EXPECT_EQ(10, solve(7, 5,
                        {"10101", "00001", "00110", "11110", "00100", "11111",
                         "10000"}));
}
