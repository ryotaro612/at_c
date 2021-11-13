#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc097/d.cc"

TEST(abc097d, 1) {
  EXPECT_EQ(2, solve(5, 2, {5, 3, 1, 4, 2}, {1, 5}, {3, 4}));
}

TEST(abc097d, 2) {
  EXPECT_EQ(3, solve(3, 2, {3, 2, 1}, {1, 2}, {2, 3}));
}

TEST(abc097d, 3) {
  EXPECT_EQ(
      8, 
      solve(
	10, 
	8, 
	{5, 3, 6, 8, 7, 10, 9, 1, 2, 4},
	{3, 4, 5, 2, 6, 3, 8, 7}, 
	{1, 1, 9, 5, 5, 5, 9, 9}));
}

TEST(abc097d, 4) {
  EXPECT_EQ(
      5, 
      solve(
	5, 
	1, 
	{1, 2, 3, 4, 5},
	{1}, 
	{5}));
}
