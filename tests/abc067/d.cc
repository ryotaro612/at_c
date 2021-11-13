#include "abc067/d.cc"
#include <gtest/gtest.h>

TEST(abc067d, 1) {
    EXPECT_EQ("Fennec", solve(7, {3, 1, 3, 7, 5, 1}, {6, 2, 1, 4, 7, 4}));
}

TEST(abc067d, 2) {
    EXPECT_EQ("Snuke", solve(4, {1, 4, 2}, {4, 2, 3}));
}
