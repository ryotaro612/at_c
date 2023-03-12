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

ll solve(vector<ll> xv) {
  if (!(xv[0] % 2 == xv[1] % 2 && xv[1] % 2 == xv[2] % 2))
    return -1;
  if ((xv[0] + xv[1] + xv[2]) % 3)
    return -1;
  if (xv[0] == xv[1]) {
    if (xv[1] == xv[2])
      return 0;
    assert((xv[2] - xv[1]) % 6 == 0);
    return (xv[2] - xv[1]) / 6ll * 2ll;
  }
  if (xv[1] == xv[2]) {
    assert((xv[1] - xv[0]) % 6ll == 0);
    return (xv[1] - xv[0]) / 6ll * 2ll;
  }
  ll m = (xv[1] - xv[0]) / 2ll, n = (xv[2] - xv[1]) / 2ll;
  if (m <= n) {
    return m + solve({0, 0, 2ll * (n - m)});
  } else {
    return n + solve({0, 2ll * (m - n), 2ll * (m - n)});
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) {
    vector<ll> xv(3);
    cin >> xv[0] >> xv[1] >> xv[2];
    sort(xv.begin(), xv.end());
    cout << solve(xv) << endl;
  }
  return 0;
}
#endif
