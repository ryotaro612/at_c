#include "sumitrust2019/e.cc"
#include "gtest/gtest.h"

TEST(sumitrust2019e, 1) { EXPECT_EQ(3ll, solve(6, {0, 1, 2, 3, 4, 5})); }

TEST(sumitrust2019e, 2) { EXPECT_EQ(6ll, solve(3, {0, 0, 0})); }

TEST(sumitrust2019e, 3) {
    EXPECT_EQ(115295190ll,
              solve(54, {0,  0,  1,  0,  1,  2,  1,  2,  3,  2,  3,  3,  4,  4,
                         5,  4,  6,  5,  7,  8,  5,  6,  6,  7,  7,  8,  8,  9,
                         9,  10, 10, 11, 9,  12, 10, 13, 14, 11, 11, 12, 12, 13,
                         13, 14, 14, 15, 15, 15, 16, 16, 16, 17, 17, 17}));
}
