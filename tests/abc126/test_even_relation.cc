#include <vector>
#include "gtest/gtest.h"
#include "abc126/even_relation.h"

using namespace std;

TEST(TestEvenRelation, First) {
  int n = 3;
  int u[] = {1, 2};
  int v[] = {2, 3};
  long long w[] = {2, 1};
  vector<int> ans = {0, 0, 1};
  EXPECT_EQ(ans, even_relation(n, u, v, w));
}

TEST(TestEvenRelation, Second) {
  int n = 5;
  int u[] = {2, 2, 1, 3};
  int v[] = {5, 3, 3, 4};
  long long w[] = {2, 10, 8, 2};
  vector<int> ans = {0, 0, 0, 0, 0};
  EXPECT_EQ(ans, even_relation(n, u, v, w));
}
