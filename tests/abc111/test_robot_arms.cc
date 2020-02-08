#include "gtest/gtest.h"
#include <vector>
#include "abc111/robot_arms.h"

using namespace std;
/*
TEST(TestRobotArms, First) {
  vector<long long> x = {-1, 0, 2};
  vector<long long> y = {0, 3, -1};
  Answer ans = robot_arms(3, x, y);

  vector<long long> d = {1, 2};
  vector<vector<char>> w = {{'R', 'L'}, {'U', 'U'}, {'D', 'D'}};
  Answer expected = Answer(2, d, w);
  EXPECT_EQ(expected, ans);
}
*/
TEST(TestRobotArms, Second) {
  vector<long long> x = {0, 1, 2, 3, 4};
  vector<long long> y = {0, 0, 0, 0, 0};
  Answer ans = robot_arms(5, x, y);
  Answer expected = Answer();
  EXPECT_EQ(expected, ans);
}
/*
TEST(TestRobotArms, Third) {
  vector<long long> x = {1, 1};
  vector<long long> y = {1, 1};
  Answer ans = robot_arms(2, x, y);

  vector<long long> d = {1, 1};
  vector<vector<char>> w = {{'R', 'U'}, {'U', 'R'}};
  Answer expected = Answer(2, d, w);
  EXPECT_EQ(expected, ans);
}

TEST(TestRobotArms, Fourth) {
  vector<long long> x = {-7, 7, -3};
  vector<long long> y = {-3, 3, -7};
  Answer ans = robot_arms(3, x, y);

  vector<long long> d = {3, 1, 4, 1, 5};
  vector<vector<char>> w = {
    {'L', 'R', 'D', 'U', 'L'}, 
    {'R', 'D', 'U', 'L', 'R'}, 
    {'D', 'U', 'L', 'R', 'D'}, 
  };
  Answer expected = Answer(5, d, w);
  EXPECT_EQ(expected, ans);
}
*/
