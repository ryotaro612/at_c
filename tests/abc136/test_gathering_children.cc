#include <vector>
#include "gtest/gtest.h"
#include "abc136/gathering_children.h"

using namespace std;

TEST(TestGatheringChildren, First) {
  vector<char> input = {'R', 'R', 'L', 'R', 'L'};
  vector<int> ans = {0, 1, 2, 1, 1};
  EXPECT_EQ(ans, gathering_children(input));
}

TEST(TestGatheringChildren, Second) {
  vector<char> input = {'R', 'R', 'L', 'L', 'L', 'L', 'R', 'L', 'R', 'R', 'L', 'L'};
  vector<int> ans = {0, 3, 3, 0, 0, 0, 1, 1, 0, 2, 2, 0};
  EXPECT_EQ(ans, gathering_children(input));
}

TEST(TestGatheringChildren, Third) {
  vector<char> input = {'R', 'R', 'R', 'L', 'L', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L'};
  vector<int> ans = {0, 0, 3, 2, 0, 2, 1, 0, 0, 0, 4, 4, 0, 0, 0, 0};
  EXPECT_EQ(ans, gathering_children(input));
}
