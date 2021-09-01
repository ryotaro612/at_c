#include "gtest/gtest.h"
#include <cmath>
#include "abc154/dice_in_line.h"

TEST(DiceInLine, First) {
  vector<long double> p = {1, 2, 2, 4, 5};
  long double actual = dice_in_line(5, 3, p);
  EXPECT_GE(0.000001, abs(actual - 7.000000000000));
}

TEST(DiceInLine, Second) {
  vector<long double> p = {6, 6, 6, 6};
  long double actual = dice_in_line(4, 1, p);
  EXPECT_GE(0.000001, abs(actual - 3.500000000000));
}

TEST(DiceInLine, Third) {
  vector<long double> p = {17, 13, 13, 12, 15, 20, 10, 13, 17, 11};
  long double actual = dice_in_line(10, 4, p);
  EXPECT_GE(0.000001, abs(actual - 32.000000000000));
}
