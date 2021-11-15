#include<gtest/gtest.h>
#include "abc227/d.cc"

TEST(abc227d,1) {
	vector<ll> a =  {2, 3, 4};
	EXPECT_EQ(2, solve(3, 3, a));
}

TEST(abc227d,2) {
	vector<ll> a =  {1, 1, 3, 4};
	EXPECT_EQ(4, solve(4, 2, a));
}

TEST(abc227d,3) {
	vector<ll> a =  {1, 1, 3, 4};
	EXPECT_EQ(2, solve(4, 3, a));
}