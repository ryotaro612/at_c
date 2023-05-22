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
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  ll d;
  cin >> d;
  vector<ll> av(n), bv(m);
  rep(i, n) cin >> av[i];
  rep(i, m) cin >> bv[i];
  sort(bv.begin(), bv.end());

  ll res = -1ll;
  for (auto a : av) {
    auto iter = upper_bound(bv.begin(), bv.end(), a + d);
    int l = distance(bv.begin(), iter);
    for (int i = l - 1; i >= 0 && a - d <= bv[i]; i--) {
      if (abs(bv[i] - a) <= d) {
        res = max(res, bv[i] + a);
        break;
      }
    }
  }

  cout << res << endl;
  return 0;
}
#endif
