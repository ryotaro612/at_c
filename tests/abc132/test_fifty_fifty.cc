#include <string>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "abc132/fifty_fifty.h"

TEST(TestFiftyFifty, First) {
    /* 
    char s[] = {'A', 'C', 'D', 'B', 'C','B'};
    EXPECT_EQ(ans, solve_best_cow_line(6,s));
    */
    std::string arg = "ASSA";
    EXPECT_EQ("Yes", solve_fifty_fifty(arg));
}


