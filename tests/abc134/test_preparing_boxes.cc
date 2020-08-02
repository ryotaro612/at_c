#include <vector>
#include "gtest/gtest.h"
typedef long long ll;
#include "abc134/preparing_boxes.h"

TEST(PreparingBoxes, 1) {
  std::vector<ll>  a{1, 0, 0};
  std::vector<ll> ans {1};
    EXPECT_EQ(ans, preparing_boxes(a));
}

TEST(PreparingBoxes, 2) {
  std::vector<ll>  a{0, 0, 0, 0, 0};
  std::vector<ll> ans {};
  EXPECT_EQ(ans, preparing_boxes(a));
}
