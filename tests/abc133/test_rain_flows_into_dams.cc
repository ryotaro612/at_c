#include "gtest/gtest.h"
#include<vector>
#include "abc133/rain_flows_into_dams.h"
typedef long long ll;

using namespace std;

TEST(TestRainFlowsIntoDams, First) {
  vector<ll> rain = {2, 2, 4};
  vector<ll> ans {4, 0, 4};
  EXPECT_EQ(ans, rain_flows_into_dams(rain));
}

TEST(TestRainFlowsIntoDams, Second) {
  vector<ll> rain = {3, 8, 7, 5, 5};
  vector<ll> ans {2, 4, 12, 2, 8};
  EXPECT_EQ(ans, rain_flows_into_dams(rain));
}

TEST(TestRainFlowsIntoDams, Third) {
  vector<ll> rain = {1000000000, 1000000000, 0};
  vector<ll> ans {0, 2000000000, 0};
  EXPECT_EQ(ans, rain_flows_into_dams(rain));
}
