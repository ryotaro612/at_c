#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "abc145/knight.h"

using namespace std;

TEST(TestKnight, First) {
  EXPECT_EQ(2, knight(3, 3));
}

TEST(TestKnight, Second) {
  EXPECT_EQ(0, knight(2, 2));
}

TEST(TestKnight, Third) {
  EXPECT_EQ(151840682, knight(999999, 999999));
}
