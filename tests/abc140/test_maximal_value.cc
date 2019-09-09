#include "gtest/gtest.h"
#include "abc140/maximal_value.h"

TEST(TestMaximalValue, First) {
    int ary[] = {2, 5};
    EXPECT_EQ(9, solve_maximal_value(3, ary));
}

TEST(TestMaximalValue, Second) {
    int ary[] = {3};
    EXPECT_EQ(6, solve_maximal_value(2, ary));
}

TEST(TestMaximalValue, Third) {
    int ary[] = {0, 153, 10, 10, 23};
    EXPECT_EQ(53, solve_maximal_value(6, ary));
}