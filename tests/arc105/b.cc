#include "arc105/b.cc"
#include "gtest/gtest.h"

TEST(arc105b, 1) { EXPECT_EQ(2, solve(3, {2, 6, 6})); }

TEST(arc105b, 2) {
    EXPECT_EQ(42, solve(15, {546, 3192, 1932, 630, 2100, 4116, 3906, 3234, 1302,
                             1806, 3528, 3780, 252, 1008, 588}));
}
