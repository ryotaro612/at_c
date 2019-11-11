#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "abc130/enough_array.h"

using namespace std;

TEST(TestEnoughArray, First) {
  int a[] = {6, 1, 2, 7};
  EXPECT_EQ(2, enough_array(a, 4, 10));
}

TEST(TestEnoughArray, Second) {
  int a[] = {3, 3, 3};
  EXPECT_EQ(3, enough_array(a, 3, 5));
}


TEST(TestEnoughArray, Third) {
  int a[] = {103, 35322, 232, 342, 21099, 90000, 18843, 9010, 35221, 19352};
  EXPECT_EQ(36, enough_array(a, 10, 53462));
}
