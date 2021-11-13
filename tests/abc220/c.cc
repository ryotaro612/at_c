#include<gtest/gtest.h>
#include "abc220/c.cc"

TEST(abc220c, 1) {
	vector<ll> a = {3, 5, 2};
	EXPECT_EQ(8, solve(3, a, 26));
}

TEST(abc220c, 2) {
	vector<ll> a = {12, 34, 56, 78};
	EXPECT_EQ(23, solve(4, a, 1000));
}

TEST(abc220c, 3) {
	vector<ll> a = {3, 2};
	EXPECT_EQ(1, solve((int) a.size(), a, 1));
}

TEST(abc220c, 4) {
	vector<ll> a = {3, 2};
	EXPECT_EQ(3, solve((int) a.size(), a, 5));
}

TEST(abc220c, 5) {
	vector<ll> a = {3, 2};
	EXPECT_EQ(2, solve((int) a.size(), a, 4));
}
TEST(abc220c, 6) {
	vector<ll> a = {3, 2};
	EXPECT_EQ(3, solve((int) a.size(), a, 6));
}