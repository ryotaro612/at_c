#include "gtest/gtest.h"
#include "abc171/c.cc"

TEST(abc171c, 1) {
  EXPECT_EQ("b", c(2));
}

TEST(abc171c, 2) {
  EXPECT_EQ("aa", c(27));
}

TEST(abc171c, 3) {
  EXPECT_EQ("jjddja", c(123456789));
}

TEST(abc171c, 4) {
  EXPECT_EQ("zzzz", c(475254));
}


