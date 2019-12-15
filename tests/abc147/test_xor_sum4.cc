#include "gtest/gtest.h"
#include "abc147/xor_sum4.h"

using namespace std;

TEST(TestXorSum4, First) {
  int n = 3;
  long a[] ={1, 2, 3};
  EXPECT_EQ(6, xor_sum4(n, a));
}

TEST(TestXorSum4, Second) {
  int n = 10;
  long a[] ={3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  EXPECT_EQ(237, xor_sum4(n, a));
}

TEST(TestXorSum4, Third) {
  int n = 10;
  long a[] = {3, 14, 159, 2653, 58979, 323846, 2643383, 27950288, 419716939, 9375105820};
  EXPECT_EQ(103715602, xor_sum4(n, a));
}
