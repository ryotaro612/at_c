#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

string solve(ll n, ll m, ll t, vector<ll> &av, vector<ll> &xv, vector<ll> &yv) {
  map<ll, ll> bonus;
  rep(i, m) { bonus[--xv[i]] = yv[i]; }

  rep(i, n - 1) {
    if (bonus.find(i) != bonus.end()) {
      t += bonus[i];
    }
    if (av[i] < t) {
      t -= av[i];
    } else {
      return "No";
    }
    // cout << i << " " << t << endl;
  }
  return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, m, t;
  cin >> n >> m >> t;
  vector<ll> av(n - 1);
  rep(i, n - 1) cin >> av[i];
  vector<ll> xv(m), yv(m);
  rep(i, m) { cin >> xv[i] >> yv[i]; }
  cout << solve(n, m, t, av, xv, yv) << endl;
  return 0;
}
#endif
