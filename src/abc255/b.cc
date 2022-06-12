#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <iomanip>
#include <ios>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ld solve(int n, int k, vector<int> &av, vector<ld> &xv, vector<ld> &yv) {
  rep(i, k) av[i]--;
  ld ub = 10000000;
  ld lb = 0;
  while (ub - lb > 0.000001) {
    ld mid = (ub + lb) / (ld)2;
    bool ok = true;
    rep(i, n) {
      ld x = xv[i];
      ld y = yv[i];
      bool temp = false;
      rep(j, k) {
        ld ax = xv[av[j]];
        ld ay = yv[av[j]];
        if ((x - ax) * (x - ax) + (y - ay) * (y - ay) <= mid * mid) {
          temp = true;
          break;
        }
      }
      if (!temp) {
        ok = false;
      }
    }
    if (ok)
      ub = mid;
    else
      lb = mid;
  }
  return ub;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> av(k);
  rep(i, k) cin >> av[i];
  vector<ld> xv(n), yv(n);
  rep(i, n) cin >> xv[i] >> yv[i];
  cout << fixed << setprecision(12) << solve(n, k, av, xv, yv) << endl;
  return 0;
}
#endif
