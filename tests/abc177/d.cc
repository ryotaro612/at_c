#include "gtest/gtest.h"
#include "abc177/d.h"
typedef long long ll;
using namespace std;

TEST(abc177d, 1) {
  int n = 5;
  int m = 3;
  vector<int> a ={1, 3, 5};
  vector<int> b ={2, 4, 1};
  EXPECT_EQ(3, d(n, m, a, b));
}

TEST(abc177d, 2) {
  int n = 4;
  int m = 10;
  vector<int> a ={1, 2, 1, 2, 1, 1, 1, 2, 2, 3};
  vector<int> b ={2, 1, 2, 1, 2, 3, 4, 3, 4, 4};
  EXPECT_EQ(4, d(n, m, a, b));
}

TEST(abc177d, 3) {
  int n = 10;
  int m = 4;
  vector<int> a ={3, 4, 5, 2};
  vector<int> b ={1, 1, 9, 6};
  EXPECT_EQ(3, d(n, m, a, b));
}
