#include <gtest/gtest.h>
#include<string>
#include "abc104/we_love_abc.h"

using namespace std;


TEST(WeLoveABC, 1) {
  EXPECT_EQ(8, we_love_abc("A??C"));
}

TEST(WeLoveABC, 2) {
  EXPECT_EQ(3, we_love_abc("ABCBC"));
}

TEST(WeLoveABC, 3) {
  EXPECT_EQ(979596887, we_love_abc("????C?????B??????A???????"));
}
TEST(WeLoveABC, 4) {
  EXPECT_EQ(1, we_love_abc("?BC"));
}
TEST(WeLoveABC, 5) {
  EXPECT_EQ(0, we_love_abc("CBC"));
}
TEST(WeLoveABC, 6) {
  EXPECT_EQ(1, we_love_abc("BABC"));
}
