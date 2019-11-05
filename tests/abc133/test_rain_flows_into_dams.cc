#include "gtest/gtest.h"
#include<vector>
#include "abc133/rain_flows_into_dams.h"

using namespace std;

TEST(TestRainFlowsIntoDams, First) {
  vector<int> rain = {2, 2, 4};
  vector<int> ans {4, 0, 4};
  EXPECT_EQ(ans, rain_flows_into_dams(rain));
}

TEST(TestRainFlowsIntoDams, Second) {
  vector<int> rain = {3, 8, 7, 5, 5};
  vector<int> ans {2, 4, 12, 2, 8};
  EXPECT_EQ(ans, rain_flows_into_dams(rain));
}

TEST(TestRainFlowsIntoDams, Third) {
  vector<int> rain = {1000000000, 1000000000, 0};
  vector<int> ans {0, 2000000000, 0};
  EXPECT_EQ(ans, rain_flows_into_dams(rain));
}
