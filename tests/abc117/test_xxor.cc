#include "gtest/gtest.h"
#include "abc117/xxor.h"
using namespace std;

TEST(TestXxor, First) {
  long long a[] = {1, 6, 3};
  EXPECT_EQ(14, xxor(3, 7, a));
}

TEST(TestXxor, Second) {
  long long a[] = {7, 4, 0, 3};
  EXPECT_EQ(46, xxor(4, 9, a));
}

TEST(TestXxor, Third) {
  long long a[] = {1000000000000};
  EXPECT_EQ(1000000000000, xxor(1, 0, a));
}

