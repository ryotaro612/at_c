#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "abc099/d.cc"

TEST(abc099d, 1) {
  vector<vector<int>> dd = {
    {0, 1, 1}, 
    {1, 0, 1},
    {1, 4, 0}
  };
  int c = 3;
  for(int i=0;i<c;i++) {
    for(int j=0;j<c;j++) {
      d[i][j] = dd[i][j];
    }
  }
  int n = 2;
  vector<vector<int>> cmm = {{1, 2}, {3, 3}};
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cm[i][j] = cmm[i][j];
    }
  }
  EXPECT_EQ(3, solve(n, c));
}

TEST(abc099d, 2) {
  vector<vector<int>> dd = {
    {0, 12, 71},
    {81, 0, 53},
    {14, 92, 0}
  };
  int c = 3;
  for(int i=0;i<c;i++) {
    for(int j=0;j<c;j++) {
      d[i][j] = dd[i][j];
    }
  }
  int n = 4;
  vector<vector<int>> cmm = {
    {1, 1, 2, 1},
    {2, 1, 1, 2},
    {2, 2, 1, 3},
    {1, 1, 2, 2}
  };
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cm[i][j] = cmm[i][j];
    }
  }
  EXPECT_EQ(428, solve(n, c));
}


