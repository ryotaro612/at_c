#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "abc131/megalomania.h"

using namespace std;

TEST(TestMegalomania, First) {
  vector<int>  a {2, 1, 1, 4, 3};
  vector<int>  b {4, 9, 8, 9, 12};
  EXPECT_EQ("Yes", megalomania(a, b));
}

TEST(TestMegalomania, Second) {
  vector<int>  a {334, 334, 334};
  vector<int>  b {1000, 1000, 1000};
  EXPECT_EQ("No", megalomania(a, b));
}

TEST(TestMegalomania, Third) {
  vector<int>  a {384, 1725, 170, 4, 2, 578, 702, 143, 1420, 24, 849, 76, 85, 444, 719, 470, 1137, 455, 110, 15, 368, 104, 3, 366, 7, 610, 152, 4, 292, 334};
  vector<int>  b {8895, 9791, 1024, 11105, 6, 1815, 3352, 5141, 6980, 1602, 999, 7586, 5570, 4991, 11090, 10708, 4547, 9003, 9901, 8578, 3692, 1286, 4, 12143, 6649, 2374, 7324, 7042, 11386, 5720};
  EXPECT_EQ("Yes", megalomania(a, b));
}



