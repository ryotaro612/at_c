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

ll pow(ll x, ll n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1)
      ret *= x; // n の最下位bitが 1 ならば x^(2^i) をかける
    x *= x;
    n >>= 1; // n を1bit 左にずらす
  }
  return ret;
}

//#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  // ll res = 0;
  // for (int i = 1; i < as_int(s.size()); i++) {
  //   res += pow(26ll, i);
  // }

  ll res = 0, add = 26;
  for (int i = 1; i <= s.size() - 1; i++) {
    res += add;
    add *= 26;
  }
  ll num = 0ll;
  rep(i, s.size()) {
    ll d = s[i] - 'A';
    num += d * pow(26, s.size() - 1 - i);
  }

  cout << 1ll + res + num << endl;
  return 0;
}
//#endif
