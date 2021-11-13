#include "abc059/d.cc"
#include <gtest/gtest.h>

TEST(abc059d, 1) { 
    EXPECT_EQ("Brown", solve(2, 1)); 
}

TEST(abc059d, 2) { 
    EXPECT_EQ("Alice", solve(5, 0)); 
}

TEST(abc059d, 3) { 
    EXPECT_EQ("Brown", solve(0, 0)); 
}

TEST(abc059d, 4) { 
    EXPECT_EQ("Alice", solve(4, 8)); 
}