#include "abc015/c.cc"
#include <gtest/gtest.h>

TEST(abc015c, 1) {
    EXPECT_EQ("Found",
              solve(3, 4, {{1, 3, 5, 17}, {2, 4, 2, 3}, {1, 3, 2, 9}}));
}

TEST(abc015c, 2) {
    EXPECT_EQ("Nothing", solve(5, 3,
                               {{89, 62, 15},
                                {44, 36, 17},
                                {4, 24, 24},
                                {25, 98, 99},
                                {66, 33, 57}}));
}
