#include <gtest/gtest.h>
#include "abc107/candles.h"
using namespace std;

TEST(TestCandles, First) {
  vector<long long> x = {-30, -10, 10, 20, 50};
  EXPECT_EQ(40, candles(5, 3, x));
}

TEST(TestCandles, Second) {
  vector<long long> x = {10, 20, 30};
  EXPECT_EQ(20, candles(3, 2, x));
}

TEST(TestCandles, Third) {
  vector<long long> x = {0};
  EXPECT_EQ(0, candles(1, 1, x));
}

TEST(TestCandles, Fourth) {
  vector<long long> x = {-9, -7,-4, -3, 1, 2, 3, 4};
  EXPECT_EQ(10, candles(8, 5, x));
}
