#include "gtest/gtest.h"
#include "abc172/sum_of_divisors.h"
using namespace std;


TEST(SumOfDivisors, 1) {
  long long n = 4;
  long long ans = 23;
  EXPECT_EQ(ans, sum_of_divisors(n));
}

TEST(SumOfDivisors, 2) {
  long long n = 100;
  long long ans = 26879;
  EXPECT_EQ(ans, sum_of_divisors(n));
}

TEST(SumOfDivisors, 3) {
  long long n = 10000000;
  long long ans = 838627288460105;
  EXPECT_EQ(ans, sum_of_divisors(n));
}
