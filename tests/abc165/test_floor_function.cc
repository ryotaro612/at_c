#include "gtest/gtest.h"
#include "abc165/floor_function.h"

using namespace std;

TEST(FloorFunction, 1) {
  EXPECT_EQ(2, floor_function(5, 7, 4));
}

TEST(FloorFunction, 2) {
  EXPECT_EQ(9, floor_function(11, 10, 9));
}
