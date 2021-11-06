#include "abl/d.cc"
#include <gtest/gtest.h>

TEST(abld, 1) {
    vector<int> a = {
		1, 5, 4, 3, 8, 6, 9, 7, 2, 4};
    EXPECT_EQ(7, solve(10, 3, a));
}
