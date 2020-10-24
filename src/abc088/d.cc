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
  while (!que.empty()) {
    dot p = que.front();
    que.pop();

    if (p.h != 0 && m[p.h - 1][p.w] == '.' && d[p.h][p.w] + 1 < d[p.h - 1][p.w]) {
      d[p.h - 1][p.w] = d[p.h][p.w] + 1;
      que.push(dot(p.h - 1, p.w));
    }
    if (p.w != w - 1 && m[p.h][p.w + 1] == '.' && d[p.h][p.w] + 1 < d[p.h][p.w + 1]) {
      d[p.h][p.w + 1] = d[p.h][p.w] + 1;
      que.push(dot(p.h, p.w + 1));
    }
    if (p.h != h - 1 && m[p.h + 1][p.w] == '.' && d[p.h][p.w] + 1 < d[p.h + 1][p.w]) {
      d[p.h + 1][p.w] = d[p.h][p.w] + 1;
      que.push(dot(p.h + 1, p.w));
    }
    if (p.w != 0 && m[p.h][p.w - 1] == '.' && d[p.h][p.w] + 1 < d[p.h][p.w - 1]) {
      d[p.h][p.w - 1] = d[p.h][p.w] + 1;
      que.push(dot(p.h, p.w - 1));
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