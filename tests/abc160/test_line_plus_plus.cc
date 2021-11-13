#include <vector>
#include "gtest/gtest.h"
#include "abc160/line_plus_plus.h"

using namespace std;

TEST(LinePlusPlus, 1) {
  vector<int> ans = {5, 4, 1, 0};
  EXPECT_EQ(ans, line_plus_plus(5, 2, 4));
}

TEST(LinePlusPlus, 2) {
  vector<int> ans = {3, 0};
  EXPECT_EQ(ans, line_plus_plus(3, 1, 3));
}

TEST(LinePlusPlus, 3) {
  vector<int> ans = {7, 8, 4, 2, 0, 0};
  EXPECT_EQ(ans, line_plus_plus(7, 3, 7));
}

TEST(LinePlusPlus, 4) {
  vector<int> ans = {10, 12, 10, 8, 4, 1, 0, 0, 0};
  EXPECT_EQ(ans, line_plus_plus(10, 4, 8));
}

