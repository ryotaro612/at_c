#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int solve(int i, map<ll, ll> &parents, vector<ll> &res) {
  if (res[i] >= 0)
    return res[i];
  return res[i] = 1 + solve(parents[i], parents, res);
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  map<ll, ll> parents;
  rep(i, n) { parents[(i + 1) * 2ll] = parents[(i + 1) * 2ll + 1ll] = av[i]; }
  vector<ll> res(2 * n + 2, -1);
  res[1] = 0ll;
  for (int i = 1; i <= 2 * n + 1; i++) {
    solve(i, parents, res);
    cout << res[i] << endl;
  }

  return 0;
}
#endif
