#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll n;
  cin >> n;
  if (n < 1000ll) {
    cout << n << endl;
    return 0;
  }
  for (int i = 4; i <= 10; i++) {
    ll temp = 1ll;
    rep(j, i) temp *= 10ll;
    if (n < temp) {
      ll a = 1ll;
      rep(k, i - 3) a *= 10ll;
      n /= a;
      cout << n * a << endl;
      return 0;
    }
  }

  return 0;
}
#endif
