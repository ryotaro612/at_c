#include "gtest/gtest.h"
#include "abc144/water_bottle.h"

using namespace std;

TEST(TestWaterBottle, First) {

  EXPECT_NEAR(45.0000000000, water_bottle(2.0, 2.0, 4.0), 0.01);
}

TEST(TestWaterBottle, Second) {  
  EXPECT_NEAR(89.7834636934, water_bottle(12.0, 21.0, 10.0), 0.01);
}

TEST(TestWaterBottle, Third) {
  EXPECT_NEAR(4.2363947991, water_bottle(3.0, 1.0, 8.0), 0.01);
}
