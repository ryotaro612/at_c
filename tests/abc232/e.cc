#include "abc232/e.cc"
#include <gtest/gtest.h>

 TEST(abc232e, 1) { EXPECT_EQ(2, solve(2, 2, 2, 1, 2, 2, 1)); }

TEST(abc232e, 2) {
    EXPECT_EQ(24922282ll,
              solve(1000000000ll, 1000000000ll, 1000000ll, 1000000000ll,
                    1000000000ll, 1000000000ll, 1000000000ll));
}

TEST(abc232e, 3) { EXPECT_EQ(9, solve(3, 3, 3, 1, 3, 3, 3)); }
