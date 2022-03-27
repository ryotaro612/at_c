#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string solve(int n, ll k, vector<ll> &av, vector<ll> &bv) {
  vector<vector<bool>> reach(n, vector<bool>(2, false));
  reach[0][0] = reach[0][1] = true;
  for (int i = 1; i < n; i++) {
    if (reach[i - 1][0]) {
      if (abs(av[i - 1] - av[i]) <= k)
        reach[i][0] = true;
      if (abs(av[i - 1] - bv[i]) <= k)
        reach[i][1] = true;
    }
    if (reach[i - 1][1]) {
      if (abs(bv[i - 1] - av[i]) <= k)
        reach[i][0] = true;
      if (abs(bv[i - 1] - bv[i]) <= k)
        reach[i][1] = true;
    }
  }

  if (reach[n - 1][0] || reach[n - 1][1])
    return "Yes";
  else
    return "No";
}
//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  ll k;
  cin >> k;
  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  cout << solve(n, k, av, bv) << endl;
  return 0;
}
//#endif
