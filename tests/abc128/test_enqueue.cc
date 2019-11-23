#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "abc128/enqueue.h"

using namespace std;

TEST(TestEnqueue, First) {
  long long v[] = {-10, 8, 2, 1, 2, 6};
  EXPECT_EQ(14, enqueue(6, 4, v));
}

TEST(TestEnqueue, Second) {
  long long v[] = {-6, -100, 50, -2, -5, -3};
  EXPECT_EQ(44, enqueue(6, 4, v));
}

TEST(TestEnqueue, Third) {
  long long v[] = {-6, -100, 50, -2, -5, -3};
  EXPECT_EQ(0, enqueue(6, 3, v));
}
