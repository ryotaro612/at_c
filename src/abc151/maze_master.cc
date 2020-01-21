#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maze_master(int h, int w, vector<vector<char>> s) {
  int inf = 100000;
  int all_nums = h * w;
  int dp[all_nums][all_nums];
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      for(int k=0;k<all_nums;k++) {
	dp[i*w + j][k] = inf;
      }
      if(s[i][j] == '#') {
	continue;
      }
      dp[i*w + j][i*w + j] = 0;
      if(i != 0 && s[i-1][j] == '.') {
	dp[i*w + j][(i-1)*w + j] = 1;
      }
      if(i != h-1 && s[i+1][j] == '.') {
	dp[i*w + j][(i+1)*w + j] = 1;
      }
      if(j != 0 && s[i][j-1] == '.') {
	dp[i*w + j][i*w + (j-1)] = 1;
      }
      if(j != w-1 && s[i][j+1] == '.') {
	dp[i*w + j][i*w + (j+1)] = 1;
      }
    }
  }

  for(int k=0;k<all_nums;k++) {
    for(int i=0;i<all_nums;i++) {
      for(int j=0;j<all_nums;j++) {
	dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
      }
    }
  }
  int ans = 0;
  for(int i=0;i<all_nums;i++) {
    for(int j=0;j<all_nums;j++) {
      if(dp[i][j] >= inf) {
	continue;
      }
      ans = max(dp[i][j], ans);
    }
  }
  return ans;
}
/*
int main() {
  int h;
  int w;
  vector<vector<char>> s;
  cin >> h;
  cin >> w;
  for(int i=0;i<h;i++) {
    vector<char> ss;
    string row;
    cin >> row;
    for(int j=0;j<w;j++) {
      ss.push_back(row[j]);
    }
    s.push_back(ss);
  }
  cout << maze_master(h, w, s);
}
*/
