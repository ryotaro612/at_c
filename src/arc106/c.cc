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

//#ifdef ONLINE_JUDGE
int main() {
  ll n, m;
  cin >> n >> m;
  if (m == 0) {
    for (ll i = 0ll; i < n; i++) {
      cout << 2ll + i * 2ll << " " << 2ll + i * 2ll + 1ll << endl;
    }
    return 0;
  }
  if (m < 0 || n - m < 2) {
    cout << -1 << endl;
    return 0;
  } else {
    cout << 1 << " " << 2ll * (m + 1) + 2ll << endl;
    rep(i, m + 1) { cout << 2 + i * 2 << " " << 2 + i * 2 + 1 << endl; }
    rep(i, n - (m + 2)) {
      int offset = 2 + 2 * (m + 1) + 1;
      cout << offset + 2 * i << " " << offset + 2 * i + 1 << endl;
    }
  }
  return 0;
}
//#endif
