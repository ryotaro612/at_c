#include <vector>
#include "gtest/gtest.h"
#include "abc124/handstand.h"

using namespace std;

TEST(TestHandstand, First) {
  int s[] = {0, 0, 0, 1, 0};
  EXPECT_EQ(4, handstand(5,1, s));
}

TEST(TestHandstand, Second) {
  int s[] = {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1};
  EXPECT_EQ(8, handstand(14, 2, s));
}

TEST(TestHandstand, Third) {
  int s[] = {1};
  EXPECT_EQ(1, handstand(1, 1, s));
}

