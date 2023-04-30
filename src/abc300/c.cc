#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

char cm[101][101];

// #ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) {
    rep(j, w) { cin >> cm[i][j]; }
  }
  vector<int> res(min(h, w) + 1, 0);
  rep(r, h) {
    rep(c, w) {

      if (cm[r][c] == '.')
        continue;
      int d = 1;
      for (;; d++) {
        if (0 <= r - d && 0 <= c - d && cm[r - d][c - d] == '#' && c + d < w &&
            cm[r - d][c + d] == '#' && r + d < h && cm[r + d][c - d] == '#' &&
            cm[r + d][c + d] == '#') {
          ;
        } else
          break;
      }
      res[d - 1]++;
    }
  }
  rep(i, res.size()) {
    if (i)
      cout << res[i] << " \n"[i == as_int(res.size()) - 1];
  }
  return 0;
}
// #endif
