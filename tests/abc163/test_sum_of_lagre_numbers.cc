#include "gtest/gtest.h"
#include "abc163/sum_of_large_numbers.h"


using namespace std;

TEST(SumOfLargeNumbers, 1) {
  EXPECT_EQ(10, sum_of_large_numbers(3, 2));
}

TEST(SumOfLargeNumbers, 2) {
  EXPECT_EQ(1, sum_of_large_numbers(200000, 200001));
}

TEST(SumOfLargeNumbers, 3) {
  EXPECT_EQ(220280457, sum_of_large_numbers(141421, 35623));
}
