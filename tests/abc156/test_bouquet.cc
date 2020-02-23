#include "gtest/gtest.h"
#include "abc156/bouquet.h"

TEST(Bouquet, 1) {
  EXPECT_EQ(7, bouquet(4, 1, 3));
}

TEST(Bouquet, 2) {
  EXPECT_EQ(34076506, bouquet(1000000000, 141421, 173205));
}
