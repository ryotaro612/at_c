#include "gtest/gtest.h"
#include "abc142/disjoint_set_of_common_divisors.h"


TEST(TestDisjointSetOfCommonDivisors, First) {
  EXPECT_EQ(3, disjoint_set_of_common_divisors(12, 18));
}


TEST(TestDisjointSetOfCommonDivisors, Second) {
  EXPECT_EQ(4, disjoint_set_of_common_divisors(420, 660));
}

TEST(TestDisjointSetOfCommonDivisors, Third) {
  EXPECT_EQ(1, disjoint_set_of_common_divisors(1, 2019));
}
