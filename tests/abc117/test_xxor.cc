#include<fstream>
#include "gtest/gtest.h"
#include "abc117/xxor.h"
using namespace std;

TEST(TestXxor, 1) {
  long long a[] = {1, 6, 3};
  EXPECT_EQ(14, xxor(3, 7, a));
}

TEST(TestXxor, 2) {
  long long a[] = {7, 4, 0, 3};
  EXPECT_EQ(46, xxor(4, 9, a));
}

TEST(TestXxor, 3) {
  long long a[] = {1000000000000};
  EXPECT_EQ(1000000000000, xxor(1, 0, a));
}

TEST(TestXxor, 4) {
  long long a[] = {25};
  EXPECT_EQ(31, xxor(1, 15, a));
}

TEST(TestXxor, 5) {
  long long a[] = {25, 6};
  EXPECT_EQ(31, xxor(2, 15, a));
}

TEST(TestXxor, 6) {
  long long a[] = {25};
  EXPECT_EQ(31, xxor(1, 6, a));
}
