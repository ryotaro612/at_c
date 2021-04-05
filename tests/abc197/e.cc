#include "abc197/e.cc"
#include "gtest/gtest.h"

TEST(abc197e, 1) {
    EXPECT_EQ(12ll, solve(5, {2, 3, 1, 4, 5}, {2, 1, 3, 2, 3}));
}

TEST(abc197e, 2) {
    EXPECT_EQ(38ll, solve(9, {5, -4, 4, 6, -5, -3, 2, 3, 1},
                          {5, 4, 3, 3, 5, 2, 2, 3, 4}));
}
