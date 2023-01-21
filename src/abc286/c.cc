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

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll a, b;
  string s;
  cin >> n >> a >> b >> s;
  ll res = 1000000000000000ll;
  rep(i, n) {
    string temp(n, ' ');
    rep(j, n) { temp[j] = s[(i + j) % n]; }
    // cout << temp << endl;
    ll cand = a * (ll)i;
    for (int k = 0; k < n - 1 - k; k++) {
      // cout << k << endl;
      if (temp[k] != temp[n - 1 - k])
        cand += b;
    }
    // cout << " -> " << cand << endl;
    res = min(res, cand);
  }

  cout << res << endl;
  return 0;
}
#endif
