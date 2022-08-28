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
  const ll a = 998244353ll;
  cin >> n;
  ll res = a;
  if (n < a && n % a == 0) {
    res = 0;
  } else if (0 <= n && n < a) {
    res = n;
  } else if (a <= n) {
    res = n % a;
  } else {
    res = n + (abs(n) / a + 1ll) * a;
  }
  if ((n - res) % a == 0ll && 0 <= res && res < a)
    cout << res << endl;
  else {
    assert(false);
  }
  return 0;
}
#endif
