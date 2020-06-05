#include "gtest/gtest.h"
#include <vector>
#include "abc167/teleporter.h"

using namespace std;

TEST(Teleporter, 1) {
  vector<long long> a = {2, 1, 3, 0};
  EXPECT_EQ(4, teleporter(4, 5, a));
}

TEST(Teleporter, 2) {
  vector<long long> a = {5, 4, 1, 4, 2, 1};
  EXPECT_EQ(2, teleporter(6, 727202214173249351, a));
}
