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
  int n;
  ll w;
  cin >> n >> w;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  unordered_set<ll> res;
  rep(i, n) {
    if (av[i] <= w)
      res.insert(av[i]);
  }
  rep(i, n - 1) {
    for (int j = i + 1; j < n; j++) {
      ll sum = av[i] + av[j];
      if (sum <= w)
        res.insert(sum);
    }
  }
  rep(i, n - 2) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        ll sum = av[i] + av[j] + av[k];
        if (sum <= w)
          res.insert(sum);
      }
    }
  }
  cout << res.size() << endl;

  return 0;
}
#endif
