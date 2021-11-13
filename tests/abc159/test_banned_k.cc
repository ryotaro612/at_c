#include <vector>
#include "gtest/gtest.h"
#include "abc159/banned_k.h"

using namespace std;

TEST(BannedK, 1) {
  vector<int> a = {1, 1, 2, 1, 2};
  vector<long long> ans = {2, 2, 3, 2, 3};
  EXPECT_EQ(ans, banned_k(a));
}

TEST(BannedK, 2) {
  vector<int> a = {1, 2, 3, 4};
  vector<long long> ans = {0, 0, 0, 0};
  EXPECT_EQ(ans, banned_k(a));
}

TEST(BannedK, 3) {
  vector<int> a = {3, 3, 3, 3, 3};
  vector<long long> ans = {6, 6, 6, 6, 6};
  EXPECT_EQ(ans, banned_k(a));
}

TEST(BannedK, 4) {
  vector<int> a = {1, 2, 1, 4, 2, 1, 4, 1};
  vector<long long> ans = {5, 7, 5, 7, 7, 5, 7, 5};
  EXPECT_EQ(ans, banned_k(a));
}
