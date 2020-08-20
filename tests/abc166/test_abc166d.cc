#include "gtest/gtest.h"
#include "abc166/abc166.h"

using namespace std;

TEST(Abc166d, 1) {
  auto ans = i_hate_factorization(33);
  EXPECT_EQ(1, ans.first);
  EXPECT_EQ(-2, ans.second);
}

TEST(Abc166d, 2) {
  auto ans = i_hate_factorization(1);
  EXPECT_EQ(0, ans.first);
  EXPECT_EQ(-1, ans.second);
}
