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

ll sub(ll t, vector<ll> &av, vector<ll> &pv) {

  int i = lower_bound(begin(av), end(av), t) - begin(av);
  // cout << i << " ##" << endl;
  if (i % 2) {
    return pv[i];
  } else {
    return pv[i] - (av[i] - t);
  }
}

// #ifdef ONLINE_JUDGE
int main() {
  int n, q;
  cin >> n;
  vector<ll> av(n), prefix(n, 0);
  rep(i, n) { cin >> av[i]; }
  rep(i, n) {
    if (i % 2) {
      prefix[i] = prefix[i - 1];
    } else if (i) {
      prefix[i] = prefix[i - 1] + av[i] - av[i - 1];
    }
  }
  cin >> q;
  rep(_, q) {
    // cout << "doge" << endl;
    ll l, r;
    cin >> l >> r;
    cout << sub(r, av, prefix) - sub(l, av, prefix) << endl;
  }
  return 0;
}
// #endif
