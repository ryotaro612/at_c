#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(int n, ll l, ll r, vector<ll> &av) {
  vector<ll> acc(n + 1, 0ll);
  rep(i, n) { acc[i + 1] += av[i] - l + acc[i]; }
  vector<ll> l_best(n + 1, 0);
  ll running_best = 0ll;
  for (int i = 0; i < n + 1; i++) {
    if (acc[i] < running_best) {
      l_best[i] = l_best[i - 1];
    } else {
      running_best = acc[i];
      l_best[i] = i;
    }
  }
  vector<ll> prefix_sum(n + 1, 0);
  rep(i, n) { prefix_sum[i + 1] += av[i] + prefix_sum[i]; }
  ll res = l * l_best[n] + (prefix_sum[n] - prefix_sum[l_best[n]]);

  for (int i = n - 1; i >= 0; i--) {
    ll cand =
        l * l_best[i] + r * (n - i) + (prefix_sum[i] - prefix_sum[l_best[i]]);
    res = min(res, cand);
  }

  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll l, r;
  cin >> n >> l >> r;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, l, r, av);

  return 0;
}
#endif
