#include "gtest/gtest.h"
#include "abc122/we_like_agc.h"

TEST(TestWeLikeAGC, First) {
  EXPECT_EQ(61, we_like_agc(3));
}

TEST(TestWeLikeAGC, Second) {
  EXPECT_EQ(230, we_like_agc(4));
}
/*
TEST(TestWeLikeAGC, Second) {
  EXPECT_EQ(230, we_like_agc(5));
}
*/
TEST(TestWeLikeAGC, Third) {
  EXPECT_EQ(388130742, we_like_agc(100));
}
