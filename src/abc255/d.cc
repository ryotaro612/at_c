#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<ll> solve(ll n, ll q, vector<ll> &av, vector<ll> &xv) {
  vector<ll> prefix_sum(n, 0ll), suffix_sum(n, 0ll);
  sort(av.begin(), av.end());
  for (ll i = 1ll; i < n; i++) {
    prefix_sum[i] = (av[i] - av[i - 1]) * i + prefix_sum[i - 1];
  }
  for (ll i = n - 2ll; i >= 0ll; i--) {
    suffix_sum[i] = (av[i + 1] - av[i]) * (n - 1ll - i) + suffix_sum[i + 1];
  }
  vector<ll> res;
  rep(i, q) {
    // cout << "i: " << i << endl;
    ll x = xv[i];
    auto iter = lower_bound(av.begin(), av.end(), x);
    if (iter == av.end()) {
      res.push_back(prefix_sum[n - 1] + (x - av[n - 1]) * n);
    } else {
      ll i = distance(av.begin(), iter);
      if (av[i] == x) {
        res.push_back(prefix_sum[i] + suffix_sum[i]);
        continue;
      }
      ll temp = 0;
      if (i > 0) {
        temp = prefix_sum[i - 1] + i * (x - av[i - 1]);
      }
      ll temp2 = suffix_sum[i] + (av[i] - x) * (n - 1ll - i + 1ll);
      // cout << i << " " << temp << " " << temp2 << endl;
      res.push_back(temp + temp2);
    }
  }
  // cout << "prefix" << endl;
  // for (auto e : prefix_sum)
  //   cout << e << endl;
  // cout << "suffix" << endl;
  // for (auto e : suffix_sum)
  //   cout << e << endl;
  // cout << "----" << endl;
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<ll> xv(q);
  rep(i, q) cin >> xv[i];
  vector<ll> res = solve(n, q, av, xv);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
