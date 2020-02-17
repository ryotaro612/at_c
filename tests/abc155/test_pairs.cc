#include "gtest/gtest.h"
#include <vector>
#include "abc155/pairs.h"

using namespace std;

TEST(Pairs, First) {
  vector<long long> a = {3, 3, -4, -2};
  EXPECT_EQ(-6, pairs(4, 3, a));
}

TEST(Pairs, Second) {
  vector<long long> a = {5, 4, 3, 2, -1, 0, 0, 0, 0, 0};
  EXPECT_EQ(6, pairs(10, 40, a));
}

TEST(Pairs, Third) {
  vector<long long> a = {-170202098, -268409015, 537203564, 983211703, 21608710, -443999067, -937727165, -97596546, -372334013, 398994917, -972141167, 798607104, -949068442, -959948616, 37909651, 0, 886627544, -20098238, 0, -948955241, 0, -214720580, 277222296, -18897162, 834475626, 0, -425610555, 110117526, 663621752, 0};
  EXPECT_EQ(448283280358331064, pairs(30, 413, a));
}
