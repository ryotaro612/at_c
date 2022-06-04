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
  ll n;
  cin >> n;
  ll res = 0ll;

  for (ll i = 1ll; i <= n; i++) {
    ll k = i;
    for (ll d = 2ll; d * d <= k; d++) {
      while (k % (d * d) == 0ll)
        k /= d * d;
    }
    for (ll d = 1ll; k * d * d <= n; d++)
      res++;
  }
  cout << res << endl;
  return 0;
}
#endif
