#include "arc107/a.cc"
#include "gtest/gtest.h"

TEST(arc107a, 1) { EXPECT_EQ(18ll, solve(1, 2, 3)); }

TEST(arc107a, 2) {
    EXPECT_EQ(951633476ll, solve(1000000000, 987654321, 123456789));
}
