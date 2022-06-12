#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(int n, int m, vector<ll> &sv, vector<ll> &xv) {
  unordered_map<ll, ll> odd, even;
  vector<ll> av(n, 0);
  even[0] = 1;
  for (int i = 1; i < n; i++) {
    av[i] = sv[i - 1] - av[i - 1];
    if (i % 2 == 0)
      even[av[i]] += 1;
    else
      odd[av[i]] += 1;
  }
  map<ll, ll> count;
  rep(i, n) {

    rep(j, m) {
      // av[i]をxv[j]にあわせる
      if (i % 2 == 0) {
        count[av[i] - xv[j]] += 1;
      } else { // i % 2 == 1
        count[xv[j] - av[i]] += 1;
      }
    }
  }
  ll res = 0ll;
  for (auto [_, v] : count)
    res = max(res, v);

  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> sv(n - 1);
  rep(i, n - 1) cin >> sv[i];
  vector<ll> xv(m);
  rep(i, m) cin >> xv[i];
  cout << solve(n, m, sv, xv) << endl;

  return 0;
}
#endif
