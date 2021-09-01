#include "gtest/gtest.h"
#include "abc173/chat_in_a_circle.h"
using namespace std;


TEST(ChatInACircle, 1) {
  long long n = 4;
  long long a[] = {2, 2, 1, 3};
  long long ans = 7;
  EXPECT_EQ(ans, chat_in_a_circle(n, a));
}

TEST(ChatInACircle, 2) {
  long long n = 7;
  long long a[] = {1, 1, 1, 1, 1,1 , 1 };
  long long ans = 6;
  EXPECT_EQ(ans, chat_in_a_circle(n, a));
}



