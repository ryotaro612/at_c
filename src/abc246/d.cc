#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll solve(const ll x) {
  __int128 xx = x;
  ll res = numeric_limits<ll>::max();
  for (ll a = 0ll; a <= 1000000ll; a++) {

    __int128 lb = -1ll, ub = 1000001ll;
    while (ub - lb > 1ll) {
      __int128 mid = (lb + ub) / 2ll;
      __int128 temp = a * a * a + a * a * mid + a * mid * mid + mid * mid * mid;

      if (xx <= temp) {
        if (temp < res)
          res = temp;
        ub = mid;
      } else {
        lb = mid;
      }
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll x;
  cin >> x;
  cout << solve(x) << endl;
  return 0;
}
#endif
