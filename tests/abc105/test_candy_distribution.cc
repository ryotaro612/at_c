#include <gtest/gtest.h>
#include<vector>
#include "abc105/candy_distribution.h"

using namespace std;

TEST(CandyDistribution, 1) {
  vector<long long> a = {4, 1, 5};
  EXPECT_EQ(3, candy_distribution(3, 2, a));
}

TEST(CandyDistribution, 2) {
  vector<long long> a = {29, 7, 5, 7, 9, 51, 7, 13, 8, 55, 42, 9, 81};
  EXPECT_EQ(6, candy_distribution(13, 17, a));
}

TEST(CandyDistribution, 3) {
  vector<long long> a = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
  EXPECT_EQ(25, candy_distribution(10, 400000000, a));
}
