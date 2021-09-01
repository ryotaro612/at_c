#include "abc125/c.cc"
#include "gtest/gtest.h"

TEST(abc125c, 1) { 
    EXPECT_EQ(2ll, solve(3, {7, 6, 8})); 
}

TEST(abc125c, 2) { 
    EXPECT_EQ(6ll, solve(3, {12, 15, 18})); 
}

TEST(abc125c, 3) { 
    EXPECT_EQ(1000000000ll, solve(2, {1000000000ll, 1000000000ll})); 
}





