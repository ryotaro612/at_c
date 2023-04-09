#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

void warshall_floyd(vector<vector<int>> &d) {
  int n = d.size();
  rep(k, n) {
    rep(i, n) {
      rep(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<int>> d(n, vector<int>(n, 1 << 29));
  vector<vector<bool>> av(n, vector<bool>(n, false));
  rep(i, n) {
    rep(j, n) {
      int flag;
      cin >> flag;
      if (flag) {
        av[i][j] = true;
        d[i][j] = 1;
      }
      if (i == j)
        d[i][j] = 0;
    }
  }

  warshall_floyd(d);
  // rep(i, n) {
  //   rep(j, n) { cout << d[i][j] << " "; }
  //   cout << endl;
  // }

  int q;
  cin >> q;
  rep(i, q) {
    ll s, t;
    cin >> s >> t;
    s--;
    t--;
    if (s % n == t % n) {
      if (av[s % n][t % n])
        cout << 1 << endl;
      else {
        int res = 1 << 29;
        rep(j, n) {
          if (j != s % n)
            res = min(res, d[s % n][j] + d[j][s % n]);
        }
        if (res < (1 << 16))
          cout << res << endl;
        else
          cout << -1 << endl;
      }
    } else {
      if (d[s % n][t % n] < (1 << 16)) {
        cout << d[s % n][t % n] << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
#endif
