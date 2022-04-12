#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll count(vector<bool> &notv) {
  int n = static_cast<int>(notv.size());
  ll res = 0ll, acc = 0ll;

  rep(i, n) {
    if (notv[i]) {
      acc++;
    } else {
      res += acc * (acc + 1ll) / 2ll;
      acc = 0ll;
    }
  }
  res += acc * (acc + 1ll) / 2ll;
  return res;
}

ll solve(int n, int x, int y, vector<int> &av) {

  vector<bool> inxy(n, true), notx(n, true), noty(n, true), notxy(n, true);
  rep(i, n) {
    if (!(y <= av[i] && av[i] <= x)) {
      inxy[i] = notx[i] = noty[i] = notxy[i] = false;
    }
    if (x == av[i]) {
      notx[i] = notxy[i] = false;
    }
    if (y == av[i]) {
      noty[i] = notxy[i] = false;
    }
  }
  return count(inxy) - count(notx) - count(noty) + count(notxy);
}

#ifdef ONLINE_JUDGE
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, x, y, av) << endl;
  return 0;
}
#endif
