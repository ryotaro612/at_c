#include "gtest/gtest.h"
#include <vector>
#include "abc138/ki.h"


using namespace std;

TEST(abc138d, 1){
  vector<int> ans {100, 110, 111, 110};
  int a[] = {1, 2, 2};
  int b[] = {2, 3, 4};
  int p[] = {2, 1, 3};
  int x[] = {10, 100, 1};
  EXPECT_EQ(ans, ki(4, 3, a, b, p, x));
}

TEST(abc138d, 2){
  vector<int> ans {20, 20, 20, 20, 20, 20};
  int a[] = {1, 1, 2, 3, 2};
  int b[] = {2, 3, 4, 6, 5};
  int p[] = {1, 1};
  int x[] = {10, 10};
  EXPECT_EQ(ans, ki(6, 2, a, b, p, x));
}
