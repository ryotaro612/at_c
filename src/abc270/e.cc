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
  ll n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];

  ll ub = k + 1ll, lb = 0ll;
  while (ub - lb > 1ll) {
    ll mid = (ub + lb) / 2ll;
    ll count = 0ll;
    for (auto e : av) {
      count += min(e, mid);
    }
    if (k < count)
      ub = mid;
    else
      lb = mid;
  }

  rep(i, n) {
    ll e = min(av[i], lb);
    av[i] -= e;
    k -= e;
  }
  // cout << lb << endl;
  // rep(i, n) cout << av[i] << " ";
  // cout << endl;
  // cout << k << endl;

  int i = 0;
  while (k) {
    if (av[i]) {
      av[i]--;
      k--;
    }
    i++;
    i %= n;
  }

  rep(i, n) {
    cout << av[i];
    if (i == n - 1)
      cout << endl;
    else
      cout << " ";
  }

  return 0;
}
#endif
