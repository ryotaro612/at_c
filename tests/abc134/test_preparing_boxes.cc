#include <vector>
#include "gtest/gtest.h"
#include "abc134/preparing_boxes.h"

TEST(TestPreparingBoxes, First) {
  std::vector<int>  a{1, 0, 0};
  std::vector<int> ans {1};
    EXPECT_EQ(ans, preparing_boxes(a));
}

TEST(TestPreparingBoxes, Second) {
  std::vector<int>  a{0, 0, 0, 0, 0};
  std::vector<int> ans {};
  EXPECT_EQ(ans, preparing_boxes(a));
}
