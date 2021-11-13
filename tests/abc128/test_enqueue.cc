#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "abc128/enqueue.h"

using namespace std;

TEST(Enqueue, 1) {
  long long v[] = {-10, 8, 2, 1, 2, 6};
  EXPECT_EQ(14, enqueue(6, 4, v));
}

TEST(Enqueue, 2) {
  long long v[] = {-6, -100, 50, -2, -5, -3};
  EXPECT_EQ(44, enqueue(6, 4, v));
}

TEST(Enqueue, 3) {
  long long v[] = {-6, -100, 50, -2, -5, -3};
  EXPECT_EQ(0, enqueue(6, 3, v));
}

TEST(Enqueue, 4) {
  long long v[] = {-10};
  EXPECT_EQ(0, enqueue(1, 1, v));
}

TEST(Enqueue, 5) {
  long long v[] = {10, 10};
  EXPECT_EQ(20, enqueue(2, 5, v));
}


TEST(Enqueue, 6) {
  long long v[] = {10, -10};
  EXPECT_EQ(10, enqueue(2, 5, v));
}


TEST(Enqueue, 7) {
  long long v[] = {-10, 10, -10};
  EXPECT_EQ(0, enqueue(3, 2, v));
}
