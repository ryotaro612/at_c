#include "gtest/gtest.h"
#include "abc115/christmas.h"
using namespace std;

TEST(TestChristmas, First) {
  EXPECT_EQ(4, christmas(2, 7));
}

TEST(TestChristmas, Second) {
  EXPECT_EQ(0, christmas(1, 1));
}

TEST(TestChristmas, Third) {
  EXPECT_EQ(2160549382716056, christmas(50, 4321098765432109));
}
