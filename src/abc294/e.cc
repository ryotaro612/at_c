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
  ll l, n1, n2;
  cin >> l >> n1 >> n2;
  vector<ll> v1(n1), lv1(n1), v2(n2), lv2(n2);
  rep(i, n1) cin >> v1[i] >> lv1[i];
  rep(i, n2) cin >> v2[i] >> lv2[i];

  ll res = 0ll, a = 0, b = 0, j = 0;

  for (int i = 0; i < n1;) {
    ll progress = min(lv1[i] - j, lv2[a] - b);
    if (v1[i] == v2[a])
      res += progress;
    j += progress;
    b += progress;
    if (j == lv1[i]) {
      i++;
      j = 0ll;
    }
    if (b == lv2[a]) {
      a++;
      b = 0;
    }
  }
  cout << res << endl;
  return 0;
}
#endif
