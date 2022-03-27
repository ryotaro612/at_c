#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> solve(int n, int m, vector<ll> av, vector<ll> cv) {
  vector<int> bv(m + 1);
  for (int i = m; 0 <= i; i--) {
    bv[i] = cv[n + i] / av[n];

    rep(j, n + 1) { cv[i + j] -= av[j] * bv[i]; }
  }
  return bv;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> av(n + 1), cv(n + m + 1);
  rep(i, n + 1) cin >> av[i];
  rep(i, n + m + 1) cin >> cv[i];
  vector<int> res = solve(n, m, av, cv);
  rep(i, m + 1) {
    cout << res[i];
    if (i == m)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
#endif
