#include "gtest/gtest.h"
#include <vector>
#include "abc120/decayed_bridges.h"

using namespace std;

TEST(TestDecayedBridges, First) {
  long long a[] = {1, 3, 1, 2, 1};
  long long b[] = {2, 4, 3, 3, 4};
  vector<long long> ans = {0, 0, 4, 5, 6};
  EXPECT_EQ(ans, decayed_bridges(4, 5, a, b));
}

TEST(TestDecayedBridges, Second) {
  long long a[] = {2, 1, 5, 3, 4};
  long long b[] = {3, 2, 6, 4, 5};
  vector<long long> ans = {8, 9, 12, 14, 15};
  EXPECT_EQ(ans, decayed_bridges(6, 5, a, b));
}

TEST(TestDecayedBridges, Third) {
  long long  a[] = {1};
  long long b[] = {2};
  vector<long long> ans = {1};
  EXPECT_EQ(ans, decayed_bridges(2, 1, a, b));
}
