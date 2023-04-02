#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <limits>
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
  ll n, m;
  cin >> n >> m;
  ll res = numeric_limits<ll>::max();
  for (ll a = 1ll; a <= 1000000ll; a++) {
    ll b;
    if (m % a == 0) {
      b = m / a;
    } else {
      b = m / a + 1ll;
    }
    if (1 <= a && a <= n && 1 <= b && b <= n) {
      res = min(res, a * b);
    }
  }

  if (res == numeric_limits<ll>::max())
    cout << "-1";
  else
    cout << res;
  cout << endl;
  return 0;
}
#endif
