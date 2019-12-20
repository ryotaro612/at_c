#include "gtest/gtest.h"
#include "abc127/integer_cards.h"

using namespace std;

TEST(TestIntegerCards, First) {
  int n = 3;
  int m = 2;
  long long a[] = {5, 1, 4};
  int b[] = {2, 1};
  long long c[] = {3, 5};
  EXPECT_EQ(14, integer_cards(n, m, a, b, c));
}

TEST(TestIntegerCards, Second) {
  int n = 10;
  int m = 3;
  long long a[] = {1, 8, 5, 7, 100, 4, 52, 33, 13, 5};
  int b[] = {3, 4, 1};
  long long c[] = {10, 30, 4};
  EXPECT_EQ(338, integer_cards(n, m, a, b, c));
}

TEST(TestIntegerCards, Third) {
  int n = 3;
  int m = 2;
  long long a[] = {100, 100, 100};
  int b[] = {3, 3};
  long long c[] = {99, 99};
  EXPECT_EQ(300, integer_cards(n, m, a, b, c));
}

TEST(TestIntegerCards, Fourth) {
  int n = 11;
  int m = 3;
  long long a[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int b[] = {3, 4, 3};
  long long c[] = {1000000000, 1000000000, 1000000000};
  EXPECT_EQ(10000000001, integer_cards(n, m, a, b, c));
}
