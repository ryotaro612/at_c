#include "gtest/gtest.h"
#include "abc174/abc174d.h"
typedef long long ll;
using namespace std;


TEST(abc174d, 1) {
  string s = "WWRR";
  ll ans = 2;
  EXPECT_EQ(ans, abc174d(s));
}

TEST(abc174d, 2) {
  string s = "RR";
  ll ans = 0;
  EXPECT_EQ(ans, abc174d(s));
}

TEST(abc174d, 3){
  string s = "WRWWRWRR";
  ll ans = 3;
  EXPECT_EQ(ans, abc174d(s));
}
