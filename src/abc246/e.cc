#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int enc(int i, int j, int n) { return i * n + j; }

int solve(int n, vector<string> &board, int ax, int ay, int bx, int by) {
  const int inf = 3000000;
  vector<vector<int>> d(n, vector<int>(n, inf));
  queue<pair<int, pair<int, int>>> que;
  que.push({0, {ax - 1, ay - 1}});
  d[ax - 1][ay - 1] = 0;

  while (!que.empty()) {
    int cost = que.front().first;
    int i = que.front().second.first;
    int j = que.front().second.second;
    que.pop();
    if (d[i][j] < cost)
      continue;
    for (int l = 1; i + l < n && j + l < n && board[i + l][j + l] == '.'; l++) {
      int n_i = i + l, n_j = j + l;
      if (cost + 1 < d[n_i][n_j]) {
        d[n_i][n_j] = cost + 1;
        que.push({d[n_i][n_j], {n_i, n_j}});
      } else if (d[n_i][n_j] < cost + 1) {
        break;
      }
    }
    for (int l = 1; i + l < n && 0 <= j - l && board[i + l][j - l] == '.';
         l++) {
      int n_i = i + l, n_j = j - l;
      if (cost + 1 < d[n_i][n_j]) {
        d[n_i][n_j] = cost + 1;
        que.push({d[n_i][n_j], {n_i, n_j}});
      } else if (d[n_i][n_j] < cost + 1) {
        break;
      }
    }
    for (int l = 1; 0 <= i - l && j + l < n && board[i - l][j + l] == '.';
         l++) {
      int n_i = i - l, n_j = j + l;
      if (cost + 1 < d[n_i][n_j]) {
        d[n_i][n_j] = cost + 1;
        que.push({d[n_i][n_j], {n_i, n_j}});
      } else if (d[n_i][n_j] < cost + 1) {
        break;
      }
    }
    for (int l = 1; 0 <= i - l && 0 <= j - l && board[i - l][j - l] == '.';
         l++) {
      int n_i = i - l, n_j = j - l;
      if (cost + 1 < d[n_i][n_j]) {
        d[n_i][n_j] = cost + 1;
        que.push({d[n_i][n_j], {n_i, n_j}});
      } else if (d[n_i][n_j] < cost + 1) {
        break;
      }
    }
  }
  int res = d[bx - 1][by - 1];
  if (res == inf)
    return -1;
  else
    return res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int n, ax, ay, bx, by;
  cin >> n >> ax >> ay >> bx >> by;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];
  cout << solve(n, sv, ax, ay, bx, by) << endl;

  return 0;
}
//#endif
