#include "gtest/gtest.h"
#include <vector>
#include "abc171/replacing.h"
using namespace std;


TEST(Replacing, 1) {
  int n = 4;
  int a[] = {1,2,3,4};
  int q = 3;
  int b[] = {1, 3, 2};
  int c[] = {2, 4, 4};
  vector<long long> ans = {11, 12, 16};
  EXPECT_EQ(ans, replacing(n, a, q, b, c));
}

TEST(Replacing, 2) {
  int n = 4;
  int a[] = {1,1, 1, 1};
  int q = 3;
  int b[] = {1, 2, 3};
  int c[] = {2, 1, 5};
  vector<long long> ans = {8, 4, 4};
  EXPECT_EQ(ans, replacing(n, a, q, b, c));
}

TEST(Replacing, 3) {
  int n = 2;
  int a[] = {1, 2};
  int q = 3;
  int b[] = {1, 2, 100};
  int c[] = {100, 100, 1000};
  vector<long long> ans = {102, 200, 2000};
  EXPECT_EQ(ans, replacing(n, a, q, b, c));
}
