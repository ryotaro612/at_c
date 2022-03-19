#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll mygcd(ll a, ll b) {
  ll aa = max(a, b);
  ll bb = min(a, b);
  if (bb == 0ll)
    return aa;
  return mygcd(bb, aa % bb);
}

ll solve(ll l, ll r) {
  ll res;
  for (ll i = r; l < i; i--) {
    if (mygcd(l, i) == 1ll) {
      res = i - l;
      break;
    }
  }
  for (ll i = r; l + 1ll < i; i--) {
    if (mygcd(l + 1ll, i) == 1ll) {
      res = max(res, i - (l + 1ll));
      break;
    }
  }
  for (ll i = l; i < r; i++) {
    if (mygcd(i, r) == 1ll) {
      res = max(res, r - i);
      break;
    }
  }
  for (ll i = l; i < r - 1ll; i++) {
    if (mygcd(i, r - 1ll) == 1ll) {
      res = max(res, (r - 1ll) - i);
      break;
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll l, r;
  cin >> l >> r;
  cout << solve(l, r) << endl;
  return 0;
}
#endif
