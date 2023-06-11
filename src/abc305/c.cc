#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> sm(h);
  int min_h = 6000, max_h = -1, min_w = 6000, max_w = -1;
  rep(i, h) {
    cin >> sm[i];
    rep(j, w) {
      if (sm[i][j] == '#') {
        min_h = min(min_h, i);
        max_h = max(max_h, i);
        min_w = min(min_w, j);
        max_w = max(max_w, j);
      }
    }
  }
  rep(i, h) {
    rep(j, w) {
      if (sm[i][j] == '.' && min_h <= i && i <= max_h && min_w <= j &&
          j <= max_w) {
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
  }

  return 0;
}
#endif
