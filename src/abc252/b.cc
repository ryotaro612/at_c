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
  int n, k;
  cin >> n >> k;
  vector<int> av(n), bv(k);
  rep(i, n) cin >> av[i];
  rep(i, k) cin >> bv[i];

  int mx = -1;
  rep(i, n) mx = max(mx, av[i]);
  set<int> cands;
  rep(i, n) {
    if (av[i] == mx)
      cands.insert(i);
  }
  rep(i, k) {
    if (cands.find(--bv[i]) != cands.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
#endif
