#include "abc176/f.cc"
#include "gtest/gtest.h"
typedef long long ll;
using namespace std;

TEST(abc176f, 1) { EXPECT_EQ(2, solve(2, {1, 2, 1, 2, 2, 1})); }

TEST(abc176f, 2) { EXPECT_EQ(1, solve(3, {1, 1, 2, 2, 3, 3, 3, 2, 1})); }

TEST(abc176f, 3) { EXPECT_EQ(3, solve(3, {1, 1, 2, 2, 2, 3, 3, 3, 1})); }