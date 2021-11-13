#include "gtest/gtest.h"
#include "abc162/rgb_triplets.h"


using namespace std;

TEST(RGBTriplets, 1) {
  EXPECT_EQ(1, rgb_triplets(4, "RRGB"));
}

TEST(RGBTriplets, 2) {
  EXPECT_EQ(1800, rgb_triplets(
			    39,
			    "RBRBGRBGGBBRRGBBRRRBGGBRBGBRBGBRBBBGBBB"));
}
