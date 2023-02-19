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

ll solve(ll n, ll d, ll k) {
  d %= n;

  ll r = lcm(n, d) / d;
  if (r == 0) {
    return k - 1ll;
  }

  return ((k - 1) / r + (k - 1) % r * d) % n;
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) {
    ll n, d, k;
    cin >> n >> d >> k;
    cout << solve(n, d, k) << endl;
  }
  return 0;
}
#endif
