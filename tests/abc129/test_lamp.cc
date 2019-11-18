#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "abc129/lamp.h"

using namespace std;

TEST(TestLamp, First) {
  vector<vector<char>> area;
  vector<char> row;
  row = {'#', '.', '.', '#', '.', '.'};
  area.push_back(row);
  row = {'.', '.', '.', '.', '.', '#'};
  area.push_back(row);
  row = {'.', '.', '.', '.', '#', '.'};
  area.push_back(row);
  row = {'#', '.', '#', '.', '.', '.'};
  area.push_back(row);

  EXPECT_EQ(8, lamp(area));
}

TEST(TestLamp, Second) {
  vector<vector<char>> area;
  vector<char> row;
  row = {'.', '.', '#', '.', '.', '.', '#', '.'};
  area.push_back(row);
  row = {'.', '.', '.', '.', '#', '.', '.', '.'};
  area.push_back(row);
  row = {'#', '#', '.', '.', '.', '.', '.', '.'};
  area.push_back(row);
  row = {'.', '.', '#', '#', '#', '.', '.', '#'};
  area.push_back(row);
  row = {'.', '.', '.', '#', '.', '.', '#', '.'};
  area.push_back(row);
  row = {'#', '#', '.', '.', '.', '.', '#', '.'};
  area.push_back(row);
  row = {'#', '.', '.', '.', '#', '.', '.', '.'};
  area.push_back(row);
  row = {'#', '#', '#', '.', '#', '.', '.', '#'};
  area.push_back(row);
  EXPECT_EQ(13, lamp(area));  
}
