#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// #ifdef ONLINE_JUDGE
int main() {
  int n, res = 0;
  cin >> n;
  vector<pair<ll, int>> apv(n);
  map<ll, set<int>> vi;
  rep(i, n) {
    ll a;
    cin >> a;
    apv[i] = {a, i};
    vi[a].insert(i);
  }
  sort(apv.begin(), apv.end());
  for (int i = n - 1; i >= 0; i--) {
    auto [v, j] = apv[i];
    if (vi[v].count(j) == 0)
      continue;

    vi[v].erase(j);
    ll p = 1ll;
    while ((p << 1ll) <= v * 2ll) {
      p <<= 1ll;
    }
    // cout << v << " " << p << endl;
    if (vi[p - v].size()) {
      vi[p - v].erase(vi[p - v].begin());
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
// #endif
