#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(int n, vector<ll> &xv, vector<ll> &yv, vector<ll> &pv) {
  const ll inf = 1ll << 60;

  ll lb = -1ll, ub = 10000000000ll;
  while (ub - lb > 1ll) {
    ll mid = (ub + lb) / 2ll;
    vector<vector<ll>> d(n, vector<ll>(n, inf));
    rep(i, n) {
      rep(j, n) {
        if (pv[i] * mid >= abs(xv[i] - xv[j]) + abs(yv[i] - yv[j]))
          d[i][j] = 1ll;
      }
    }
    rep(k, n) {
      rep(i, n) {
        rep(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
      }
    }
    bool ok = false;
    rep(i, n) {
      ok = true;
      rep(j, n) {
        if (d[i][j] == inf) {
          ok = false;
        }
      }
      if (ok)
        break;
    }
    if (ok)
      ub = mid;
    else
      lb = mid;
  }
  return ub;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> xv(n), yv(n), pv(n);
  rep(i, n) { cin >> xv[i] >> yv[i] >> pv[i]; }

  cout << solve(n, xv, yv, pv) << endl;
  return 0;
}
#endif
