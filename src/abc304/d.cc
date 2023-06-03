#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll w, h;
  int n, a, b;
  cin >> w >> h >> n;
  vector<ll> pv(n), qv(n);
  rep(i, n) cin >> pv[i] >> qv[i];
  cin >> a;
  vector<ll> av(a + 2, 0);
  rep(i, a) cin >> av[i + 1];
  av[a + 1] = w;
  cin >> b;
  vector<ll> bv(b + 2, 0);
  rep(i, b) cin >> bv[i + 1];
  bv[b + 1] = h;
  map<pair<ll, ll>, int> berries;
  rep(i, n) {
    ll p = pv[i], q = qv[i];
    auto iter1 = *lower_bound(begin(av), end(av), p);
    auto iter2 = *lower_bound(begin(bv), end(bv), q);
    berries[{iter1, iter2}]++;
  }
  int m = 1 << 30, M = 0;
  for (auto [_, v] : berries) {
    m = min(m, v);
    M = max(M, v);
  }
  if (int(berries.size()) < (a + 1ll) * (b + 1ll)) {
    m = 0;
  }
  cout << m << " " << M << endl;
  return 0;
}
#endif
