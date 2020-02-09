#include <gtest/gtest.h>
#include <abc110/factorization.h>

using namespace std;

TEST(TestFactorization, First) {
  EXPECT_EQ(4, factorization(2, 6));
}

TEST(TestFactorization, Second) {
  EXPECT_EQ(18, factorization(3, 12));
}

TEST(TestFactorization, Third) {
  EXPECT_EQ(957870001, factorization(100000, 1000000000));
}
