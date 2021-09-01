#include <vector>
#include "gtest/gtest.h"
#include "abc125/flipping_signs.h"

using namespace std;

TEST(TestFlippingSigns, First) {
  int n= 3;
  long long a[] = {-10, 5, -4};
  EXPECT_EQ(19, flipping_signs(n, a));
}

TEST(TestFlippingSigns, Second) {
  int n= 5;
  long long a[] = {10, -4, -8, -11, 3};
  EXPECT_EQ(30, flipping_signs(n, a));
}

TEST(TestFlippingSigns, Third) {
  int n= 11;
  long long a[] = {-1000000000, 1000000000, -1000000000, 1000000000, -1000000000, 0, 1000000000, -1000000000, 1000000000 ,-1000000000, 1000000000};
  EXPECT_EQ(10000000000, flipping_signs(n, a));
}
