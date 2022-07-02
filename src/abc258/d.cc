#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(ll n, ll x, vector<ll> &av, vector<ll> &bv) {
  ll res = numeric_limits<ll>::max();
  ll min_play = numeric_limits<ll>::max();
  ll cost = 0ll;
  rep(i, min(n, x)) {
    ll temp = cost + av[i] + bv[i];
    min_play = min(bv[i], min_play);
    res = min(res, (x - (ll)i - 1) * min_play + temp);
    cost += av[i] + bv[i];
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll x;
  cin >> n >> x;

  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i] >> bv[i];

  cout << solve(n, x, av, bv) << endl;
  return 0;
}
#endif
