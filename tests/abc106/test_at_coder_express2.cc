#include <gtest/gtest.h>
#include "abc106/at_coder_express2.h"

using namespace std;

TEST(AtCoderExpress2, 1) {
  vector<pair<int, int>> lr = {
    make_pair(1, 1),
    make_pair(1, 2),
    make_pair(2, 2),
  };
  vector<pair<int, int>> pq = {
    make_pair(1, 2),
  };

  vector<long long> ans = {3};
  EXPECT_EQ(ans, at_coder_express2(2, 3, 1, lr, pq));
}

TEST(AtCoderExpress2, 2) {
  vector<pair<int, int>> lr = {
    make_pair(1, 5),
    make_pair(2, 8),
    make_pair(7, 10),
  };
  vector<pair<int, int>> pq = {
    make_pair(1, 7),
    make_pair(3, 10),
  };
  vector<long long> ans = {1, 1};
  EXPECT_EQ(ans, at_coder_express2(10, 3, 2, lr, pq));
}

TEST(AtCoderExpress2, 3) {
  vector<pair<int, int>> lr = {
    make_pair(1, 6),
    make_pair(2, 9),
    make_pair(4, 5),
    make_pair(4, 7),
    make_pair(4, 7),
    make_pair(5, 8),
    make_pair(6, 6),
    make_pair(6, 7),
    make_pair(7, 9),
    make_pair(10, 10)
  };
  vector<pair<int, int>> pq = {
    make_pair(1,8),
    make_pair(1,9),
    make_pair(1,10),
    make_pair(2,8),
    make_pair(2,9),
    make_pair(2,10),
    make_pair(3,8),
    make_pair(3,9),
    make_pair(3,10),
    make_pair(1,10),
  };
  vector<long long> ans = {7, 9, 10, 6, 8, 9, 6, 7, 8, 10};
  EXPECT_EQ(ans, at_coder_express2(10, 10, 10, lr, pq));
}
