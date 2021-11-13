#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "abc129/lamp.h"

using namespace std;

TEST(Lamp, 1) {
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

TEST(Lamp, 2) {
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
