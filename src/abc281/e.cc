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
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> av(n), bv(m);
  rep(i, n) cin >> av[i];
  multiset<ll> primary, secondary;
  rep(i, m) { bv[i] = av[i]; }
  sort(bv.begin(), bv.end());
  ll res = 0ll;
  rep(i, m) {
    if (i < k) {
      primary.insert(bv[i]);
      res += bv[i];
    } else {
      secondary.insert(bv[i]);
    }
  }
  rep(i, n - m + 1) {
    // for (auto e : primary) {
    //   cout << e << " ";
    // }
    // cout << endl;
    // for (auto e : secondary) {
    //   cout << e << " ";
    // }
    // // cout << endl << " == " << endl;
    cout << res;
    if (i < n - m)
      cout << " ";
    else {
      cout << endl;
      break;
    }
    auto iter = primary.find(av[i]);
    if (iter == primary.end()) {
      iter = secondary.find(av[i]);
      assert(iter != secondary.end());
      secondary.erase(iter);
    } else {
      primary.erase(iter);
      res -= av[i];
    }
    secondary.insert(av[i + m]);
    while (true) {
      if ((int)primary.size() == k &&
          (secondary.size() == 0 || *primary.rbegin() <= *secondary.begin()))
        break;
      if (static_cast<int>(primary.size()) < k) {
        ll v = *secondary.begin();
        primary.insert(v);
        res += v;
        secondary.erase(secondary.begin());
      } else {
        ll p = *primary.rbegin();
        res -= p;
        primary.erase(primary.find(p));
        secondary.insert(p);
        p = *secondary.begin();
        secondary.erase(secondary.find(p));
        res += p;
        primary.insert(p);
      }
    }
  }
  return 0;
}
#endif
