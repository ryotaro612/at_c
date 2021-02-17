#include "abc054/b.cc"
#include <gtest/gtest.h>

TEST(abc054b, 1) {
    EXPECT_EQ("Yes", solve(3, 2, {"#.#", ".#.", "#.#"}, {"#.", ".#"}));
}

TEST(abc054b, 2) {
    EXPECT_EQ("No", solve(4, 1, {"....", "....", "....", "...."}, {"#"}));
}
