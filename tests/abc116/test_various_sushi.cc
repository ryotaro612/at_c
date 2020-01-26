#include "gtest/gtest.h"
#include "abc116/various_sushi.h"
using namespace std;

TEST(TestVariousSushi, First) {
  int t[] = {1, 1, 2, 2, 3};
  long long d[] = {9, 7, 6, 5, 1};
  EXPECT_EQ(26, various_sushi(5, 3, t, d));
}

TEST(TestVariousSushi, Second) {
  int t[] = {1, 2, 3, 4, 4, 4, 4};
  long long d[] = {1, 1, 1, 6, 5, 5, 5};
  EXPECT_EQ(25, various_sushi(7, 4, t, d));
}

TEST(TestVariousSushi, Third) {
  int t[] = {5, 2, 3, 6, 6, 4};
  long long d[] = {1000000000, 990000000, 980000000, 970000000, 960000000, 950000000};
  EXPECT_EQ(4900000016, various_sushi(6, 5, t, d));
}
