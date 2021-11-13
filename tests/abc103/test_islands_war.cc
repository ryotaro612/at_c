#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "abc103/islands_war.h"

using namespace std;

TEST(IslandsWar, 1) {
  vector<int> a = {1, 2};
  vector<int> b = {4, 5};
  EXPECT_EQ(1, islands_war(5, a, b));
}

TEST(IslandsWar, 2) {
  vector<int> a = {1, 2, 3, 4, 7};
  vector<int> b = {8, 7, 5, 6, 9};
  EXPECT_EQ(2, islands_war(9, a, b));
}

TEST(IslandsWar, 3) {
  vector<int> a = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
  vector<int> b = {2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
  EXPECT_EQ(4, islands_war(5, a, b));
}
