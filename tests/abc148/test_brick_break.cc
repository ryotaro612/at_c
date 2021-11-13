#include "gtest/gtest.h"
#include "abc148/brick_break.h"

using namespace std;

TEST(TestBrickBreak, First) {
  int  n = 3;
  int a[] = {2, 1, 2};
  EXPECT_EQ(1, brick_break(n, a));
}

TEST(TestBrickBreak, Second) {
  int  n = 3;
  int a[] = {2, 2, 2};
  EXPECT_EQ(-1, brick_break(n, a));
}

TEST(TestBrickBreak, Third) {
  int n = 10;
  int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  EXPECT_EQ(7, brick_break(n, a));
}

TEST(TestBrickBreak, Fourth) {
  int n = 1;
  int a[] = {1};
  EXPECT_EQ(0, brick_break(n, a));
}
