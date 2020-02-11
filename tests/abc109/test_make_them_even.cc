#include <gtest/gtest.h>
#include "abc109/make_them_even.h"
using namespace std;

TEST(TestMakeThemEvent, First) {
  vector<vector<int>> a = {{1, 2, 3}, {0, 1, 1}};
  Answer answer = make_them_even(2, 3, a);
  EXPECT_EQ(3, answer.n);
}
