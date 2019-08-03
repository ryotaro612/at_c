#include<string>
#include "gtest/gtest.h"
#include "abc132/ordinary_number.h"


TEST(TestOrdinaryNumber, First) {
    std::string arg = "1 3 5 4 2";
    EXPECT_EQ(2, ordinary_number(5, arg));
}