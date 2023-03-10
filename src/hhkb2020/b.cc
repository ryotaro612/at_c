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

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> sv(h);
  rep(i, h) cin >> sv[i];
  int res = 0;
  rep(i, h) {
    rep(j, w) {
      if (sv[i][j] == '.') {
        if (j < w - 1 && sv[i][j + 1] == '.')
          res++;
        if (i < h - 1 && sv[i + 1][j] == '.')
          res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
