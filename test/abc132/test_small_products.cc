#include<string>
#include "gtest/gtest.h"
#include "abc132/small_products.h"

TEST(TestSmallProducts, First) {
    EXPECT_EQ(5, solve_small_products(3, 2));
}

TEST(TestSmallProducts, Second) {
    EXPECT_EQ(147, solve_small_products(10, 3));
}
/*
TEST(TestSmallProducts, Third) {
    EXPECT_EQ(457397712, solve_small_products(314159265, 35));
}
*/