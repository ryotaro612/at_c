#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct dot {
  int h, w;
  dot(int hh, int ww) : h(hh), w(ww) {}
};

int solve(int h, int w, vector<string> m) {
  int num_white = 0;
  for (auto i : m) {
    for (auto j : i) {
      if (j == '.') {
        num_white++;
      }
    }
  }
  const int mx = 100000;
  vector<vector<int>> d(h, vector<int>(w, mx));
  queue<dot> que;
  que.push(dot(0, 0));
  d[0][0] = 1;
  int dh[4] = {-1, 0, 1, 0};
  int dw[4] = {0, 1, 0, -1};
  while (!que.empty()) {
    dot p = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nh = p.h + dh[i], nw = p.w + dw[i];
      int current_dist = d[p.h][p.w];
      if (nh < 0 || nh >= h || nw < 0 || nw >= w || m[nh][nw] == '#' || current_dist + 1 >= d[nh][nw]) {
        continue;
      }
      d[nh][nw] = current_dist + 1;
      que.push(dot(nh, nw));
    }
  }
  if (d[h - 1][w - 1] == mx) {
    return -1;
  }
  return num_white - d[h - 1][w - 1];
}
/*
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> m(h);
  for (int i = 0; i < h; i++) {
    cin >> m[i];
  }
  cout << solve(h, w, m);
}
*/