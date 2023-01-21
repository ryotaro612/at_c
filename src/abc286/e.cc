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

ll solve(int u, int v, vector<vector<ll>> &d, vector<vector<ll>> &souvenir,
         vector<ll> &av) {
  if (souvenir[u][v] > 0)
    return souvenir[u][v];
  if (u == v)
    return souvenir[u][v] = souvenir[v][u] = av[u];
  int n = d.size();
  ll mx = 0;
  rep(i, n) {
    if (i != u && d[u][v] == d[u][i] + d[i][v]) {
      mx = max(mx, solve(i, v, d, souvenir, av));
    }
  }
  return souvenir[u][v] = mx + av[u];
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  vector<string> sv(n);
  int q;

  rep(i, n) cin >> av[i];
  rep(i, n) cin >> sv[i];
  const ll inf = 100000000000000ll;
  vector<vector<ll>> d(n, vector<ll>(n, inf));
  rep(i, n) {
    rep(j, n) {
      if (i == j)
        d[i][j] = 0;
      else if (sv[i][j] == 'Y')
        d[i][j] = 1;
    }
  }
  rep(k, n) {
    rep(i, n) {
      rep(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
  cin >> q;
  vector<vector<ll>> souvenir(n, vector<ll>(n, -1));
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    if (d[--u][--v] >= inf)
      cout << "Impossible" << endl;
    else {
      cout << d[u][v] << " " << solve(u, v, d, souvenir, av) << endl;
    }
  }
  return 0;
}
#endif
