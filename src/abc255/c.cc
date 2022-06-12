#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

__int128 abs128(__int128 a) {
  if (a < 0)
    return -a;
  return a;
}
__int128 min128(__int128 a, __int128 b) {
  if (a < b)
    return a;
  else
    return b;
}

__int128 calc(__int128 a, __int128 n, __int128 d) {
  return a + (n - (__int128)1) * d;
}

ll solve(ll x, ll a, ll d, ll n) {
  if (d == 0)
    return abs(x - a);
  __int128 aa = a, nn = n, dd = d, xx = x;
  __int128 aa_last = calc(aa, nn, dd);
  if (dd > 0) {
    if (xx <= aa)
      return abs128(aa - xx);
    if (aa_last <= xx)
      return abs128(xx - aa_last);
  } else { // dd < 0
    if (xx <= aa_last)
      return abs128(aa_last - xx);
    if (aa <= xx)
      return abs128(xx - aa);
  }
  // __int128 result = min128(abs128(xx - aa), abs128(aa_last));
  if ((__int128)0 < dd) {
    __int128 ub = n + 1ll;
    __int128 lb = 0ll;
    while (ub - lb > (__int128)1) {
      __int128 mid = (ub + lb) / (__int128)2;
      if (xx < calc(aa, mid, dd))
        ub = mid;
      else
        lb = mid;
    }
    __int128 result = abs128(xx - calc(aa, ub, dd));
    if (1 < ub) {
      result = min128(result, abs128(xx - calc(aa, ub - (__int128)1, dd)));
    }
    return result;
  } else {
    __int128 ub = n + 1ll;
    __int128 lb = 0ll;
    while (ub - lb > (__int128)1) {
      __int128 mid = (ub + lb) / (__int128)2;
      if (xx < calc(aa, mid, dd))
        lb = mid;
      else
        ub = mid;
    }
    __int128 result = abs128(xx - calc(aa, lb, dd));
    if (lb < nn) {
      result = min128(result, abs128(xx - calc(aa, lb + (__int128)1, dd)));
    }
    return result;
  }
}

//#ifdef ONLINE_JUDGE
int main() {
  ll x, a, d, n;
  cin >> x >> a >> d >> n;
  cout << solve(x, a, d, n) << endl;
  return 0;
}
//#endif
