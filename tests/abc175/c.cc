#include "gtest/gtest.h"
#include "abc175/c.h"
typedef long long ll;
using namespace std;

TEST(abc175c, 1) {
  EXPECT_EQ(2, c(6, 2, 4));
}

TEST(abc175c, 2) {
  EXPECT_EQ(1, c(7, 4, 3));
}

TEST(abc175c, 3) {
  EXPECT_EQ(8, c(10, 1, 2));
}

TEST(abc175c, 4) {
  EXPECT_EQ(1000000000000000, c(1000000000000000, 1000000000000000, 1000000000000000));
}
