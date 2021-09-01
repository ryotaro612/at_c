#include "gtest/gtest.h"
#include "abc112/partition.h"

using namespace std;

TEST(TestPartition, First) {
  EXPECT_EQ(2, partition(3, 14));
}

TEST(TestPartition, Second) {
  EXPECT_EQ(3, partition(10, 123));
}

TEST(TestPartition, Third) {
  EXPECT_EQ(10000, partition(100000, 1000000000));
}
