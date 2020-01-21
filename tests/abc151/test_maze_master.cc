#include "gtest/gtest.h"
#include <vector>
#include "abc151/maze_master.h"

using namespace std;

TEST(TestMazeMaster, First) {
  vector<vector<char>> s = {
    {'.', '.', '.'},
    {'.', '.', '.'},
    {'.', '.', '.'}};
  EXPECT_EQ(4, maze_master(3, 3, s));
}

TEST(TestMazeMaster, Second) {
  vector<vector<char>> s = {
    {'.', '.', '.', '#', '.'},
    {'.', '#', '.', '#', '.'},
    {'.', '#', '.', '.', '.'}};
  EXPECT_EQ(10, maze_master(3, 5, s));
}
