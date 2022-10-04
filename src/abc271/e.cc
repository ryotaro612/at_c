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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, ll>>> g(n);
  vector<int> av(m), bv(m);
  vector<ll> cv(m);
  rep(i, m) {
    cin >> av[i] >> bv[i] >> cv[i];
    g[--av[i]].push_back({--bv[i], cv[i]});
  }
  vector<int> ev(k);
  rep(i, k) {
    cin >> ev[i];
    ev[i]--;
  }
  const ll inf = 10000000000000000ll;
  vector<ll> d(n, inf);
  d[0] = 0ll;

  for (auto e : ev) {
    if (d[av[e]] < inf) {
      if (d[av[e]] + cv[e] < d[bv[e]]) {
        d[bv[e]] = d[av[e]] + cv[e];
      } else {
      }
    } else {
    }
  }

  if (d[n - 1] == inf)
    cout << -1;
  else
    cout << d[n - 1];
  cout << endl;
  return 0;
}
#endif
