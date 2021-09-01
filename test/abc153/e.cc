#include "abc153/e.cc"
#include "gtest/gtest.h"

TEST(abc153e, 1) { EXPECT_EQ(4ll, solve(9, 3, {8, 4, 2}, {3, 2, 1})); }

TEST(abc153e, 2) {
    EXPECT_EQ(100ll, solve(100, 6, {1, 2, 3, 4, 5, 6}, {1, 3, 9, 27, 81, 243}));
}

TEST(abc153e, 3) {
    EXPECT_EQ(
        139815ll,
        solve(9999, 10, {540, 691, 700, 510, 415, 551, 587, 619, 588, 176},
              {7550, 9680, 9790, 7150, 5818, 7712, 8227, 8671, 8228, 2461}));
}
