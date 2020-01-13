#include "gtest/gtest.h"
#include "abc150/semi_common_multiple.h"

using namespace std;

TEST(TestSemiCommonMultiple, First) {
  long long a [] = {6, 10};
  EXPECT_EQ(2, semi_common_multiple(2, 50, a));
}

TEST(TestSemiCommonMultiple, Second) {
  long long a [] = {14, 22, 40};
  EXPECT_EQ(0, semi_common_multiple(3, 100, a));
}

TEST(TestSemiCommonMultiple, Third) {
  long long a [] = {6, 6, 2, 6, 2};
  EXPECT_EQ(166666667, semi_common_multiple(5, 1000000000, a));
}
