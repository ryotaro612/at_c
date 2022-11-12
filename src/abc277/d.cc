#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll sub(ll v, ll m, map<ll, ll> &mp, map<ll, ll> &dp) {
  if (dp.find(v) != dp.end())
    return dp[v];
  else if (mp[v]) {
    return dp[v] = v * mp[v] + sub((v + 1ll) % m, m, mp, dp);
  } else {
    return dp[v] = 0ll;
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  ll m;
  cin >> m;
  vector<ll> av(n);
  map<ll, ll> mp;
  rep(i, n) {
    cin >> av[i];
    mp[av[i]]++;
  }
  if ((int)mp.size() == m) {
    cout << 0 << endl;
    return 0;
  }

  set<ll> zeros;
  ll all = 0ll;
  ll v = 0ll;
  map<ll, ll> dp;
  rep(i, n) {
    all += av[i];
    v = max(sub(av[i], m, mp, dp), v);
  }
  cout << all - v << endl;

  return 0;
}
#endif
