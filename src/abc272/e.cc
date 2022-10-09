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
  ll n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];

  vector<set<int>> cands(m + 1);
  // 候補になるのは[0,N]まで
  for (ll i = 1; i <= n; i++) {
    ll a = av[i - 1];

    for (ll j = max(1ll, -a / i); a + j * i <= n && j <= m; j++) {
      if (0 <= a + i * j) {
        cands[j].insert(a + i * j);
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    vector<bool> temp(n + 1, true);
    for (auto e : cands[i]) {
      temp[e] = false;
    }
    rep(j, n + 1) {
      if (temp[j]) {
        cout << j << endl;
        break;
      }
    }
  }
  return 0;
}
#endif
