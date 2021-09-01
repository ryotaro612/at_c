#include "gtest/gtest.h"
#include "abc113/number_of_amidakuji.h"

using namespace std;

TEST(TestNumberOfAmidakuji, First) {
  EXPECT_EQ(1, number_of_amidakuji(1, 3, 2));
}

TEST(TestNumberOfAmidakuji, Second) {
  EXPECT_EQ(2, number_of_amidakuji(1, 3, 1));
}

TEST(TestNumberOfAmidakuji, Third) {
  EXPECT_EQ(1, number_of_amidakuji(2, 3, 3));
}

TEST(TestNumberOfAmidakuji, Fourth) {
  EXPECT_EQ(5, number_of_amidakuji(2, 3, 1));
}

TEST(TestNumberOfAmidakuji, Fifth) {
  EXPECT_EQ(1, number_of_amidakuji(7, 1, 1));
}

TEST(TestNumberOfAmidakuji, Sixth) {
  EXPECT_EQ(437760187, number_of_amidakuji(15, 8, 5));
}
