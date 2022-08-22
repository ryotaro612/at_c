#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  rep(i, h) {
    rep(j, w) { cin >> grid[i][j]; }
  }
  vector<vector<bool>> passed(h, vector<bool>(w, false));
  int r = 0, c = 0;
  while (!passed[r][c]) {
    passed[r][c] = true;
    bool stop = true;
    if (grid[r][c] == 'U') {
      if (r > 0) {
        r -= 1;
        stop = false;
      }
    } else if (grid[r][c] == 'D') {
      if (r < h - 1) {
        r += 1;
        stop = false;
      }
    } else if (grid[r][c] == 'L') {
      if (c > 0) {
        c -= 1;
        stop = false;
      }
    } else {
      if (c < w - 1) {
        c += 1;
        stop = false;
      }
    }
    if (stop) {
      cout << r + 1 << " " << c + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
#endif
