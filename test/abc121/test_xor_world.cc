#include "gtest/gtest.h"
#include "abc121/xor_world.h"

TEST(TestXORWorld, First) {
  EXPECT_EQ(5, xor_world(2, 4));
}

TEST(TestXORWorld, Second) {
  EXPECT_EQ(435, xor_world(123, 456));
}

TEST(TestXORWorld, Third) {
  EXPECT_EQ(123456789012, xor_world(123456789012, 123456789012));
}
