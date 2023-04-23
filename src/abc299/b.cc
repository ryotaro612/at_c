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
  ll n, t;
  cin >> n >> t;
  vector<ll> cv(n), rv(n);
  rep(i, n) cin >> cv[i];
  rep(i, n) cin >> rv[i];
  bool found = false;
  rep(i, n) {
    if (cv[i] == t)
      found = true;
  }
  if (!found)
    t = cv[0];
  // cout << found << endl;
  int res;
  ll v = -1ll;
  rep(i, n) {
    if (cv[i] == t && rv[i] > v) {
      v = rv[i];
      res = i;
    }
  }
  cout << res + 1 << endl;
  return 0;
}
#endif
