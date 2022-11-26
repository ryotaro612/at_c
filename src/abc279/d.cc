#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <debug/helper_functions.h>
#include <iomanip>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {

  ld a, b;
  cin >> a >> b;
  ld x = cbrt(a / (2.0 * b));
  x = x * x;
  ll t = x - 1.0;
  t = max((ll)0, t);
  ld res = a;
  // cout << x << endl;
  for (ll i = -10; i < 20; i++) {
    ld x = max((ll)0, t + i);
    ld temp = x * b;
    temp += a / sqrt(1 + x);
    res = min(res, temp);
    // cout << x << "->" << res << endl;
  }
  cout << fixed << setprecision(12) << res << endl;
  return 0;
}
#endif
