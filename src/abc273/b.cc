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
  ll x, k;
  cin >> x >> k;
  rep(i, k) {
    ll temp = x;
    rep(j, i) { temp /= 10ll; }
    if (4 < temp % 10) {
      temp /= 10ll;
      temp += 1ll;
      temp *= 10ll;
    } else {
      temp /= 10ll;
      temp *= 10ll;
    }
    rep(j, i) { temp *= 10ll; }
    x = temp;
  }
  cout << x << endl;
  return 0;
}
#endif
