#include "gtest/gtest.h"
#include <vector>
#include "abc118/match_matching.h"


using namespace std;
typedef long long ll;

TEST(TestMatchMatching, First) {
  ll a[] = {3, 7, 8, 4};
  EXPECT_EQ("777773", match_matching(20, 4, a));
}

TEST(TestMatchMatching, Second) {
  ll a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ("71111111111111111111111111111111111111111111111111", match_matching(101, 9, a));
}

TEST(TestMatchMatching, Third) {
  ll a[] = {5, 4, 6};
  EXPECT_EQ("654", match_matching(15, 3, a));
}
