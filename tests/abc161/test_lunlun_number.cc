#include "gtest/gtest.h"
#include "abc161/lunlun_number.h"

using namespace std;

TEST(LunlunNumber, 1) {
  EXPECT_EQ(23, lunlun_number(15));
}

TEST(LunlunNumber, 2) {
  EXPECT_EQ(1, lunlun_number(1));
}

TEST(LunlunNumber, 3) {
  EXPECT_EQ(21, lunlun_number(13));
}

TEST(LunlunNumber, 4) {
  EXPECT_EQ(3234566667, lunlun_number(100000));
}
