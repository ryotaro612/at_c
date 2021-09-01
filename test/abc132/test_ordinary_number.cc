#include<string>
#include "gtest/gtest.h"
#include "abc132/ordinary_number.h"

TEST(TestOrdinaryNumber, First) {
    std::string arg = "1 3 5 4 2";
    EXPECT_EQ(2, ordinary_number(5, arg));
}
TEST(TestOrdinaryNumber, Second) {
    std::string arg = "9 6 3 2 5 8 7 4 1";
    EXPECT_EQ(5, ordinary_number(9, arg));
}