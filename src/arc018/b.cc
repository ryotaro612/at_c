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
  cin >> n;
  vector<ll> xv(n), yv(n);
  rep(i, n) cin >> xv[i] >> yv[i];
  int res = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        ll area = abs((xv[i] - xv[k]) * (yv[j] - yv[k]) -
                      (xv[j] - xv[k]) * (yv[i] - yv[k]));
        if (area && area % 2 == 0)
          res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
