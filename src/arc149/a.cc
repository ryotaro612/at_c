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
  int n;
  ll m;
  cin >> n >> m;
  pair<int, int> res = {-1, -1};

  for (int i = 1; i <= 9; i++) {
    ll acc = 0ll;
    rep(j, n) {
      // n = 1
      acc *= 10ll;
      acc += i;
      if (acc % m == 0) {
        // cout << "doge " << i << " -> " << j << endl;
        res = max(res, {j + 1, i});
      }
      acc %= m;
    }
  }
  if (res.first == -1 && res.second == -1)
    cout << -1;
  else
    rep(i, res.first) cout << res.second;
  cout << endl;

  return 0;
}
#endif
