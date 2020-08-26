#include "gtest/gtest.h"
#include "abc176/d.h"
typedef long long ll;
using namespace std;

TEST(abc176d, 1) {
  vector<vector<char>> s = {
    {'.', '.', '#', '.'}, 
    {'.', '.', '#', '.'}, 
    {'.', '#', '.', '.'}, 
    {'.', '#', '.', '.'}, 
  };
  EXPECT_EQ(1, d(4, 4, 1, 1, 4, 4, s));
}

TEST(abc176d, 2) {
  vector<vector<char>> s = {
    {'.', '#', '#', '.'}, 
    {'#', '#', '#', '#'}, 
    {'#', '#', '#', '#'}, 
    {'.', '#', '#', '.'}, 
  };
  EXPECT_EQ(-1, d(4, 4, 1, 4, 4, 1, s));
}

TEST(abc176d, 3) {
  vector<vector<char>> s = {
    {'.', '.', '.', '.'}, 
    {'.', '.', '.', '.'}, 
    {'.', '.', '.', '.'}, 
    {'.', '.', '.', '.'}, 
  };
  EXPECT_EQ(0, d(4, 4, 2, 2, 3, 3, s));
}

TEST(abc176d, 4) {
  vector<vector<char>> s = {
    {'#', '.', '#', '#', '#'}, 
    {'#', '#', '#', '#', '.'}, 
    {'#', '.', '.', '#', '#'}, 
    {'#', '.', '.', '#', '#'}, 
  };
  EXPECT_EQ(2, d(4, 5, 1, 2, 2, 5, s));
}

