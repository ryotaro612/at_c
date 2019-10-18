#include "gtest/gtest.h"
#include "abc137/summer_vacation.h"


TEST(TestSummerVacation, First) {
  int a[] = {4, 4, 2};
  int b[] = {3, 1, 2};
  EXPECT_EQ(5, summer_vacation(3, 4, a, b));
}

TEST(TestSummerVacation, Second) {
  int a[] = {1, 1, 1, 2, 2};
  int b[] = {2, 3, 4, 1, 3};
  EXPECT_EQ(10, summer_vacation(5, 3, a, b));
}

TEST(TestSummerVacation, Third) {
  int a[] = {2};
  int b[] = {1};
  EXPECT_EQ(0, summer_vacation(1, 1, a, b));
}
