#include "gtest/gtest.h"
#include <vector>
#include "abc119/lazy_faith.h"

using namespace std;

TEST(TestLazyFaith, First) {
  vector<long long> ans = {350, 1400, 301, 399};
  long long s[] = {100, 600};
  long long t[] = {400, 900, 1000};
  long long x[] = {150, 2000, 899, 799};
  EXPECT_EQ(ans, lazy_faith(2, 3, 4, s, t, x));
}

TEST(TestLazyFaith, Second) {
  vector<long long> ans = {10000000000, 10000000000, 14999999998};
  long long s[] = {1};
  long long t[] = {10000000000};
  long long x[] = {2, 9999999999, 5000000000};
  EXPECT_EQ(ans, lazy_faith(1, 1, 3, s, t, x));
}
