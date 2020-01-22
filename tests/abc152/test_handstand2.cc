#include "gtest/gtest.h"
#include "abc152/handstand2.h"
using namespace std;

TEST(TestHandstand2, First) {
  EXPECT_EQ(17, handstand2(25));
}

TEST(TestHandstand2, Second) {
  EXPECT_EQ(1, handstand2(1));
}

TEST(TestHandstand2, Third) {
  EXPECT_EQ(108, handstand2(100));
}

TEST(TestHandstand2, Fourth) {
  EXPECT_EQ(40812, handstand2(2020));
}

TEST(TestHandstand2, Fifth) {
  EXPECT_EQ(400000008, handstand2(200000));
}
