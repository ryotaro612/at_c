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
  int r, c;
  cin >> r >> c;
  vector<string> m(r);
  vector<string> res(r);
  rep(i, r) {
    cin >> m[i];
    res[i] = string(m[i]);
  }

  rep(i, r) {
    rep(j, c) {
      if ('0' <= m[i][j] && m[i][j] <= '9') {
        int d = m[i][j] - '0';
        res[i][j] = '.';
        rep(a, r) {
          rep(b, c) {
            if (abs(i - a) + abs(b - j) <= d) {
              res[a][b] = '.';
            }
          }
        }
      }
    }
  }
  rep(i, r) { cout << res[i] << endl; }
  return 0;
}
#endif
