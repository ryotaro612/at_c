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
  cin >> n;
  vector<ll> pv(n);
  rep(i, n) cin >> pv[i];

  vector<ll> mp(n, 0);
  rep(i, n) { mp[(pv[i] - i + n) % n]++; }
  ll res = 0ll;
  rep(i, n) { res = max(res, mp[(i - 1 + n) % n] + mp[i] + mp[(i + 1) % n]); }
  cout << res << endl;
  return 0;
}
#endif
