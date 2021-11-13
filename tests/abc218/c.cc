#include "abc218/c.cc"
#include <gtest/gtest.h>

TEST(abc218, 1) {
    vector<string> s ={
        ".....", 
		"..#..", 
		".###.", 
		".....", 
		".....",
    },
    t = {
		".....", 
        ".....", 
		"....#", 
		"...##", 
		"....#"};
    EXPECT_EQ("Yes", solve(5, s, t));
}