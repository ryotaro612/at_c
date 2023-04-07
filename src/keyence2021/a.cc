#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
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
  int n;
  cin >> n;
  vector<ll> av(n), bv(n), cv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  ll ma = 0ll, mb = 0ll;
  rep(i, n) {
    cv[i] = max(av[i] * bv[i], ma * bv[i]);
    ma = max(av[i], ma);
    if (i)
      cv[i] = max(cv[i - 1], cv[i]);
  }
  rep(i, n) cout << cv[i] << endl;
  return 0;
}
#endif
